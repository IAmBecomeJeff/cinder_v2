#ifndef ROTARY_FUNCTIONS_H
#define

void checkDial() {
	debouncer.update();
	if (debouncer.fell()) { pinSWstate = 0; }
	else { pinSWstate = 1; }

	if (!pinSWstate) {	// If pinSW was pressed, update what the dial does
		rotary_function++;
		if (rotary_function > 3) {	// If above max rotary modes, loop back to 0
			rotary_function = 0;
		}
		Serial.print("Button Function: ");	// Add back if we use Serial data again
		Serial.println(rotary_function);
	}

	aVal = digitalRead(pinA);   // Read pinA
	if ((aVal != pinALast)) {//&&(aVal==LOW)){      // If pinA has changed, update things.   Added the &&
		rotateCount = !rotateCount;   // If at 0, change to 1... if at 1 change to 0 and don't update.
		if (rotateCount) {    // Need to let it change twice
			switch (rotary_function) {

				// If button is in stage 0:  Increase or decrease mode based on case order
				case 0: 
					if (transitioning == 0) {
						old_leds = actual_leds; // copy_led_struct(old_leds, actual_leds);
						if (digitalRead(pinB) != aVal) { new_leds.led_mode = old_leds.led_mode + 1; }	// Means pin A changed first, we're rotating CW
						else { new_leds.led_mode = old_leds.led_mode - 1; }								// Means pin B changed first, we're moving CCW
						if (new_leds.led_mode < 0) { new_leds.led_mode = max_mode; }
						if (new_leds.led_mode > max_mode) { new_leds.led_mode = 0; }
						if (!transition_lock) {
							transitioning = (transisitioning + 1) % max_transitions + 1;
							//transitioning = random8(1, max_transitions + 1);
						}
						combo_check();
						strobe_mode(new_leds, 1);
					}
					break;

				// If button is in stage 1:		Update palettes based on palette index 
				case 1: 
					if (digitalRead(pinB) != aVal) {
						if (transitioning == 0) {
							palette_change(actual_leds, 1);
						}
						else {
							palette_change(new_leds, 1);
						}
					}
					else {
						if (transitioning == 0) {
							palette_change(actual_leds, 0);
						}
						else {
							palette_change(new_leds, 0);
						}
					}
					Serial.print("Palette number: ");
					Serial.println(palette_index);
					break;

				// If button is in stage 2:		Adjust delay speed   TODO: consider proportionally updating new and old speeds?
				case 2:		
					if (digitalRead(pinB) != aVal) {
						if (transitioning > 0) {
							delay_change(new_leds, 0);
						}
						else {
							delay_change(actual_leds, 0);
						}
					}
					else {
						if (transitioning > 0) {
							delay_change(new_leds, 1);
						}
						else {
							delay_change(actual_leds, 1);
						}
					}
					Serial.print("Delay: ");
					Serial.println(actual_leds.this_delay);
					break;

				// If button in stage 3:	Adjust brightness
				case 3:		
					if (digitalRead(pinB) != aVal) {
						overall_bright++;
					}
					else {
						overall_bright--;
					}
					constrain(overall_bright, 0, max_bright);
					FastLED.setBrightness(overall_bright);
					Serial.print("Brightness: ");
					Serial.println(overall_bright);
					break;

			}
		}
	}
	pinALast = aVal;
}

#endif
