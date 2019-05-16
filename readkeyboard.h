void readkeyboard() {
	while (Serial.available() > 0) {

		in_byte = Serial.read();

		// Don't print carriage return
		if (in_byte != 10) {
			Serial.print("# ");
			Serial.print(char(in_byte));
			Serial.print(" ");
		}

		switch (in_byte) {

			// Command: a {hue} - set entire strip to {hue} (0-255)
		//case 97:
		//	//led_mode = 0;
		//	this_arg = Serial.parseInt();
		//	this_arg = constrain(this_arg, 0, 255);
		//	Serial.println(this_arg);
		//	fill_solid(actual_leds, NUM_LEDS, CHSV(this_arg, 255, 255));
		//	break;

			// Command: b {brightness} - set entire strip to {brightness} (0-255)
		case 98:
			max_bright = Serial.parseInt();
			max_bright = constrain(max_bright, 0, 255);
			Serial.print("Max brightness: ");
			Serial.println(max_bright);
			LEDS.setBrightness(max_bright);
			break;

			// Command: c - clear strip
		case 99:
			Serial.println("Clearing strip ");
			led_mode = 0;
			strobe_mode(led_mode, 1, 0);
			break;

			// Command: d {delay} - set the delay amount to {delay} (0-255)
		case 100:
			this_arg = Serial.parseInt();
			actual_leds.this_delay = constrain(this_arg, 0, 255);
			Serial.print("Delay: ");
			Serial.println(actual_leds.this_delay);
			break;

			// Command: e {0/1} - increment or decrement the mode without transitions
		case 101:
			this_arg = Serial.parseInt();
			if (this_arg) {
				actual_leds.led_mode = (actual_leds.led_mode + 1) % (max_mode + 1);
				if (actual_leds.led_mode == 0) actual_leds.led_mode = 1;
			}
			else {
				//demo_run = 0;
				actual_leds.led_mode = (actual_leds.led_mode - 1);
				if (actual_leds.led_mode == 0) actual_leds.led_mode = max_mode;
			}
			Serial.print("New mode number: ");
			Serial.println(actual_leds.led_mode);
			combo_check();
			strobe_mode(actual_leds, 1);
			break;

			// Command: f {palette_number} - set the current palette
		case 102:
			this_arg = Serial.parseInt();
			actual_leds.palette_index = this_arg % palette_count;
			actual_leds.target_palette = palette_array[actual_leds.palette_index];
			Serial.print("Palette: ");
			Serial.println(actual_leds.palette_index);
			break;

			// Command: g - toggle glitter
		case 103:
			glitter = !glitter;
			Serial.println("Glittering... ");
			break;

			// Command: h {hue} - set hue variable to {hue} (0-255)
		case 104:
			this_arg = Serial.parseInt();
			actual_leds.this_hue = constrain(this_arg, 0, 255);
			Serial.print("Hue: ");
			Serial.println(this_hue);
			break;

			// Command: i {hue} - set similar palette with selected hue {hue} (0-255)
		//case 105:
		//	//palette_change = 0;
		//	this_arg = Serial.parseInt();
		//	actual_leds.this_hue = constrain(this_arg, 0, 255);
		//	Serial.println(this_hue);
		//	SetupMySimilar4Palette();
		//	break;

			// Command: m {mode} - select mode {mode} (0-255)
		case 109:
			old_leds = actual_leds;
			new_leds.led_mode = Serial.parseInt();
			new_leds.led_mode = constrain(led_mode, 1, max_mode);
			Serial.print("New mode: ");
			Serial.println(new_leds.led_mode);
			transitioning = random8(1, max_transitions + 1);
			combo_check();
			strobe_mode(new_leds.led_mode, 1); // strobe the updated mode, mc = 1, old = 0 (so cur_leds)		
			break;

			// Command: n - toggle direction
		//case 110:
		//	Serial.println(" ");
		//	this_dir = !this_dir;
		//	break;

			// Command: p {0/1/2} - set demo mode (fixed/sequential/shuffle)
		//case 112:
		//	demo_run = Serial.parseInt();
		//	demo_run = constrain(demo_run, 0, 2);
		//	Serial.println(demo_run);
		//	break;

			// Command: s {saturation} - set saturation to {saturation} (0-255)
		case 115:
			this_arg = Serial.parseInt();
			actual_leds.this_sat = constrain(this_arg, 0, 255);
			Serial.print("Saturation: ");
			Serial.println(actual_leds.this_sat);
			break;

			// Command: t {0/1/2/3} - set palette mode (fixed/4similar/random4/random16)
		//case 116:
		//	this_arg = Serial.parseInt();
		//	palette_change = constrain(this_arg, 0, 3);
		//	Serial.println(palette_change);
		//	break;

			// Command: w - write current mode to EEPROM
		//case 119:
		//	EEPROM.write(STARTMODE, led_mode);
		//	Serial.print("Writing keyboard: ");
		//	Serial.println(led_mode);
		//	break;
		}
	}
}