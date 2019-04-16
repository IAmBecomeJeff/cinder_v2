
#include "FastLED.h"
#include "variables.h"
#include "LEDStruct.h"
#include "rings.h"
#include "transition.h"
#include "one_sin_pal.h"
#include "confetti.h"
#include "juggle.h"
#include "fire.h"

#define qsubd(x, b) ((x>b)?wave_brightness:0)

LEDStruct new_leds;
LEDStruct old_leds;
LEDStruct actual_leds;

void setup() {
	delay(2000);
	LEDS.setBrightness(max_bright);
	LEDS.addLeds<LED_TYPE, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(actual_leds.strip, NUM_LEDS);
	set_max_power_in_volts_and_milliamps(5, 5000);
	random16_set_seed(4832);
	random16_add_entropy(analogRead(2));
	actual_leds.target_palette = RainbowColors_p;
	strobe_mode(actual_leds, 1);

	// Init ring array
	for (uint8_t i = 0;i < 144;i++) {
		ringArray[i][0] = i;
		ringArray[i][1] = 287 - i;
		ringArray[i][2] = 288 + i;
		ringArray[i][3] = 575 - i;
	}
}

void loop() {

	EVERY_N_MILLISECONDS(50) {
		uint8_t maxChanges = 24;
		if (transitioning > 0) {
			nblendPaletteTowardPalette(new_leds.current_palette, new_leds.target_palette, maxChanges);
			nblendPaletteTowardPalette(old_leds.current_palette, old_leds.target_palette, maxChanges);
		}
		else {
			nblendPaletteTowardPalette(actual_leds.current_palette, actual_leds.target_palette, maxChanges);
		}
	}

	EVERY_N_SECONDS(10) {
		copy_led_classes(old_leds, actual_leds);	// copy the currently running leds into old_leds
		new_leds.led_mode = random8(max_mode + 1);
		transitioning = 1;
		strobe_mode(new_leds, 1);			// fill new_leds with the next animation
	}

	EVERY_N_MILLIS(old_timer, old_leds.this_delay) {
		if (transitioning > 0) {
			old_timer.setPeriod(old_leds.this_delay);
			strobe_mode(old_leds, 0);
		}
	}

	EVERY_N_MILLIS(new_timer, new_leds.this_delay) {
		if (transitioning > 0) {
			new_timer.setPeriod(new_leds.this_delay);
			strobe_mode(new_leds, 0);
		}
	}

	EVERY_N_MILLIS_I(actual_timer, actual_leds.this_delay) {
		actual_timer.setPeriod(actual_leds.this_delay);
		if (!transitioning) {
			strobe_mode(actual_leds, 0);
		}
	}

	if (transitioning > 0) {						// TODO, update with multiple transition types
		if (transition_wait) {
			blending_ratio += 1;
		}
		for (int i = 0; i < NUM_LEDS; i++) {
			actual_leds.strip[i] = blend(old_leds.strip[i], new_leds.strip[i], blending_ratio);
		}
		if (blending_ratio >= 255) {
			copy_led_classes(actual_leds, new_leds);
			transitioning = 0;
			blending_ratio = 0;
			fill_solid(old_leds.strip, NUM_LEDS, CRGB(0, 0, 0));
			fill_solid(new_leds.strip, NUM_LEDS, CRGB(0, 0, 0));
		}
		transition_wait = !transition_wait;
	}

	show_at_max_brightness_for_power();
}

void strobe_mode(LEDStruct& leds, bool mc) {
	if (mc) {
		fill_solid(leds.strip, NUM_LEDS, CRGB(0, 0, 0));
	}

	switch (leds.led_mode) {
		case 0:
			if (mc) { leds.this_delay = 15; leds.target_palette = RainbowColors_p; leds.all_freq = 4; leds.this_bright = 255; leds.start_index = 0; leds.this_inc = 16; leds.this_cutoff = 200; leds.this_rot = 10; leds.this_speed = 3; }
			one_sin_pal(leds);
			break;

		case 1:
			if (mc) { leds.this_delay = 15; leds.target_palette = ForestColors_p; leds.all_freq = 16; leds.this_bright = 255; leds.start_index = 64; leds.this_inc = 2; leds.this_cutoff = 224; leds.this_rot = 0; leds.this_speed = 6; }
			one_sin_pal(leds);
			break;

		case 2:
			if (mc) { leds.this_delay = 15; leds.target_palette = LavaColors_p; leds.all_freq = 32; leds.this_bright = 255; leds.start_index = 0; leds.this_inc = 4; leds.this_cutoff = 180; leds.this_rot = 2; leds.this_speed = 4; }
			one_sin_pal(leds);
			break;

		case 3:
			if (mc) { leds.this_delay = 20; leds.target_palette = PartyColors_p; leds.this_inc = 1; leds.this_fade = 2; leds.this_diff = 32; leds.this_bright = 255; }
			confetti_pal(leds);
			break;

	}
}
