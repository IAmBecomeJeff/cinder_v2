//	Cinder v2.0
//	Created by Jeff Karle
//	jeffrey.karle@gmail.com
//
//	Cobbled together from other scripts on github from Andrew Tuline, Mark Kriegsman, Caleb Ditchfield, and probably others.


#include "FastLED.h"
#include "Bounce2.h"	// Debouncing the KY-040 rotary switch
#include "variables.h"
#include "LEDStruct.h"
#include "rings.h"
#include "gradient_palettes.h" 
#include "support_functions.h" 

#include "one_sin_pal.h"
#include "confetti.h"
#include "two_sin.h"
#include "juggle.h"
#include "fire.h" 
#include "juggle_fire.h" 
#include "colorwave.h"
#include "circnosie.h"

#include "strobe_mode.h"



void setup() {
	delay(2000);
	LEDS.setBrightness(max_bright);
	LEDS.addLeds<LED_TYPE, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(actual_leds.strip, NUM_LEDS);
	set_max_power_in_volts_and_milliamps(5, 5000);	// TODO update this for live values
	random16_set_seed(4832);
	random16_add_entropy(analogRead(2));
	new_leds.isNew = 1;
	actual_leds.target_palette = RainbowColors_p;
	strobe_mode(actual_leds, 1);

	// Set up rotary encoder
	pinMode(pinA, INPUT);
	pinMode(pinB, INPUT);
	pinMode(pinSW, INPUT_PULLUP); // or pinMode(pinSW,INPUT); if I use the 10k resistor
	pinALast = digitalRead(pinA);
	debouncer.attach(pinSW);
	debouncer.interval(100);

	// Set up switches
	pinMode(switchA, INPUT_PULLUP);
	pinMode(switchB, INPUT_PULLUP);

	// Init ring array
	for (uint8_t i = 0;i < 144;i++) {
		ringArray[i][0] = i;
		ringArray[i][1] = 287 - i;
		ringArray[i][2] = 288 + i;
		ringArray[i][3] = 575 - i;
	}

	// Set up circnoise variables
	for (long i = 0; i < NUM_LEDS; i++) {
		uint8_t angle = (i * 256) / NUM_LEDS;
		xd[i] = cos8(angle);
		yd[i] = sin8(angle);
	}
}

void loop() {

	// Check rotary dial
	checkDial();

	// Check switchA for direction
	if (digitalRead(switchA)) { 
		if (transitioning == 0) {
			actual_leds.this_dir = 0;
		}
		else {
			new_leds.this_dir = 0;
			old_leds.this_dir = 0;
		}
	}
	else {
		if (transitioning == 0) {
			actual_leds.this_dir = 1;
		}
		else {
			new_leds.this_dir = 1;
			old_leds.this_dir = 1;
		}
	}

	EVERY_N_MILLISECONDS(50) {	// Palette blending
		uint8_t maxChanges = 24;
		if (transitioning > 0) {	// If transitioning, update new and old palettes
			nblendPaletteTowardPalette(new_leds.current_palette, new_leds.target_palette, maxChanges);
			nblendPaletteTowardPalette(old_leds.current_palette, old_leds.target_palette, maxChanges);
		}
		else {		// If not transitioning, update actual leds palette, which it gained from new_leds at the end of transitioning
			nblendPaletteTowardPalette(actual_leds.current_palette, actual_leds.target_palette, maxChanges);
		}
	}

	EVERY_N_SECONDS(20) {		// Transition every N seconds
		old_leds = actual_leds; //  copy_led_struct(old_leds, actual_leds);	// copy the currently running leds into old_leds
		new_leds.led_mode = random8(max_mode + 1);
		transitioning = random8(1,max_transitions+1);
		combo_check();
		strobe_mode(new_leds, 1);			// fill new_leds with the next animation
	}

	EVERY_N_MILLIS_I(old_timer, old_leds.this_delay) {	// Keep a timer for the old leds to function independently of new leds
		if (transitioning > 0) {
			old_timer.setPeriod(old_leds.this_delay);
			strobe_mode(old_leds, 0);
		}
	}

	EVERY_N_MILLIS_I(new_timer, new_leds.this_delay) {	// timer for new leds
		if (transitioning > 0) {
			new_timer.setPeriod(new_leds.this_delay);
			strobe_mode(new_leds, 0);
		}
	}

	EVERY_N_MILLIS_I(actual_timer, actual_leds.this_delay) {	// timer for actual leds in regular mode
		actual_timer.setPeriod(actual_leds.this_delay);
		if (!transitioning) {
			strobe_mode(actual_leds, 0);
		}
	}
	
	EVERY_N_MILLIS(25){
		if (transitioning == 1) {						// TODO, update with multiple transition types
			transition1();
		}
		if (transitioning == 2){
			transition2();
		}
		if (transitioning == 3) {
			transition3();
		}
	}

	show_at_max_brightness_for_power();
} // loop()


void checkDial() {
	debouncer.update();
	if (debouncer.fell()) {	pinSWstate = 0;	}
	else { pinSWstate = 1; }

	if (!pinSWstate) {	// If pinSW was pressed, update what the dial does
		rotary_function += 1;
		if (rotary_function > 3) {	// If above max rotary modes, loop back to 0
			rotary_function = 0;
		}
		//Serial.print("Button Function: ");	// Add back if we use Serial data again
		//Serial.println(rotary_function);
	}
	
	aVal = digitalRead(pinA);   // Read pinA
	if ((aVal != pinALast)) {//&&(aVal==LOW)){      // If pinA has changed, update things.   Added the &&
		rotateCount = !rotateCount;   // If at 0, change to 1... if at 1 change to 0 and don't update.
		if (rotateCount) {    // Need to let it change twice
			switch (rotary_function) {

				case 0: // If button is in stage 0:  Increase or decrease mode based on case order
					if (transitioning == 0) {
						old_leds = actual_leds; // copy_led_struct(old_leds, actual_leds);
						if (digitalRead(pinB) != aVal) { new_leds.led_mode = old_leds.led_mode + 1; }	// Means pin A changed first, we're rotating CW
						else { new_leds.led_mode = old_leds.led_mode - 1; }								// Means pin B changed first, we're moving CCW
						if (new_leds.led_mode < 0) { new_leds.led_mode = max_mode; }
						if (new_leds.led_mode > max_mode) { new_leds.led_mode = 0; }
						transitioning = 1;
						combo_check();
						strobe_mode(new_leds, 1);
					}
					break;

				case 1: // If button is in stage 1:		Update palettes based on palette index 
					if (digitalRead(pinB) != aVal) {
						if (transitioning == 0) {
							palette_change(actual_leds, 1);
						}
						else {
							palette_change(new_leds, 1);
							palette_change(old_leds, 1);
						}
					}
					else {
						if (transitioning == 0) {
							palette_change(actual_leds, 0);
						}
						else {
							palette_change(new_leds, 0);
							palette_change(old_leds, 0);
						}
					}
					//Serial.print("Palette number: ");
					//Serial.println(palette_index);
					break;

				case 2:		// If button is in stage 2:		Adjust delay speed   TODO: consider proportionally updating new and old speeds?
					if (digitalRead(pinB) != aVal) {
						if (transitioning > 0) {
							delay_change(old_leds, 0);
							delay_change(new_leds, 0);
						}
						else {
							delay_change(actual_leds,0);
						}
					}
					else{
						if (transitioning > 0) {
							delay_change(old_leds, 1);
							delay_change(old_leds, 1);
						}
						else {
							delay_change(actual_leds, 1);
						}
					}
					//Serial.print("Delay: ");
					//Serial.println(this_delay);
					break;

				case 3:		// If button in stage 3:	Adjust brightness
					if (digitalRead(pinB) != aVal) {
						overall_bright++;
					}
					else {
						overall_bright--;
					}
					constrain(overall_bright, 0, 128);
					LEDS.setBrightness(overall_bright);
					//Serial.print("Brightness: ");
					//Serial.println(this_bright);
					break;

			}
		}
	}
	pinALast = aVal;
}
