//	Cinder v2.0
//	Created by Jeff Karle
//	jeffrey.karle@gmail.com
//
//	Cobbled together from other scripts on github from Andrew Tuline, Mark Kriegsman, Caleb Ditchfield, and probably others.


#include "FastLED.h"
#include "Bounce2.h"	// Debouncing the KY-040 rotary switch
#include "variables.h"
#include "gradient_palettes.h" 
#include "LEDStruct.h"
#include "rings.h"
#include "support_functions.h" 


#include "one_sin_pal.h"
#include "confetti.h"
#include "two_sin.h"
#include "juggle.h"
#include "fire.h" 
#include "juggle_fire.h" 
#include "colorwave.h"
#include "circnoise.h"
#include "rainbow_march.h"
#include "ripple.h"
#include "plasma.h"
#include "spiral.h"
#include "rainbow_waves.h"

#include "strobe_mode.h"
#include "readkeyboard.h"
#include "rotary_functions.h"


void setup() {
	// Serial SETUP, REMOVE
	Serial.begin(SERIAL_BAUDRATE);
	Serial.setTimeout(SERIAL_TIMEOUT);

	// Delay
	delay(2000);

	// LEDS setup
	LEDS.setBrightness(overall_bright);
	LEDS.addLeds<LED_TYPE, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(actual_leds.strip, NUM_LEDS);
	FastLED.setMaxPowerInVoltsAndMilliamps(5, 5000);	// TODO update this for live values

	// Random Variables
	random16_set_seed(4832);
	random16_add_entropy(analogRead(2));

	// Static (mostly) variables for specific LEDStructs
	new_leds.isNew = 1;
	comboB_leds.target_palette = fire_gp;
	comboD_leds.target_palette = fire_gp;
	actual_leds.target_palette = RainbowColors_p;

	// Fill LEDs with initial values
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

	// Initialize Ring/Column and Spiral Arrays, as well as circnoise variables
	array_init();			// support_functions.h

}

void loop() {

	// Get keyboard input
	readkeyboard();			// support_functions.h

	// Check rotary dial
	checkDial();			// rotary_functions.h

	// Check switchA for direction
	checkDirection();		// support_functions.h

	// Palette blending
	EVERY_N_MILLISECONDS(50) {	
		uint8_t maxChanges = 24;
		if (transitioning > 0) {	// If transitioning, update new and old palettes
			nblendPaletteTowardPalette(new_leds.current_palette, new_leds.target_palette, maxChanges);
			nblendPaletteTowardPalette(old_leds.current_palette, old_leds.target_palette, maxChanges);
		}
		else {					// If not transitioning, update actual leds palette, which it gained from new_leds at the end of transitioning
			nblendPaletteTowardPalette(actual_leds.current_palette, actual_leds.target_palette, maxChanges);
		}
	}
	
	// Transition every N seconds if switch B active
	EVERY_N_SECONDS(20) {
		if (digitalRead(switchB)) {
			old_leds = actual_leds;				// copy the currently running leds into old_leds
			new_leds.led_mode = random8(1, max_mode + 1);
			if (!transition_lock) {
				transitioning = (transitioning + 1) % max_transitions + 1;
				//transitioning = random8(1, max_transitions + 1);
			}
			combo_check();						// support_functions.h
			strobe_mode(new_leds, 1);			// fill new_leds with the next animation
		};
	}
	
	// old_leds timer	-	only runs when transitioning
	EVERY_N_MILLIS_I(old_timer, old_leds.this_delay) {	
		if (transitioning > 0) {
			old_timer.setPeriod(old_leds.this_delay);
			strobe_mode(old_leds, 0);
		}
	}

	// new_leds timer	-	only runs when transitioning
	EVERY_N_MILLIS_I(new_timer, new_leds.this_delay) {	
		if (transitioning > 0) {
			new_timer.setPeriod(new_leds.this_delay);
			strobe_mode(new_leds, 0);
		}
	}

	// actual_leds timer   -   only runs when not transitioning.  then actual_leds is set by transition function
	EVERY_N_MILLIS_I(actual_timer, actual_leds.this_delay) {	
		actual_timer.setPeriod(actual_leds.this_delay);
		if (!transitioning) {
			strobe_mode(actual_leds, 0);
		}
	}
	
	// Transition functions		- support_functions.h
	EVERY_N_MILLIS(5){
		switch (transitioning){
			case 0:
				break;

			case 1:
				transition1();
				break;
			
			case 2:
				transition2();
				break;

			case 3:
				transition3();
				break;

			case 4:
				transition4();
				break;	
		}
	}

	// glitter
	if (glitter) addglitter(10);		// support_functions.h

	// Show LEDs
	FastLED.show();

} // loop()
