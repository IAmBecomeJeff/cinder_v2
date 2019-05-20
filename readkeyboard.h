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

			// Command: a switch blending, 0 = NOBLEND, 1 = LINEARBLEND
		case 97:
			this_arg = Serial.parseInt();
			if (this_arg) {	actual_leds.current_blending = LINEARBLEND;	}
			else { actual_leds.current_blending = NOBLEND; }
			break;

			// Command: b {brightness} - set entire strip to {brightness} (0-255)
		case 98:
			max_bright = Serial.parseInt();
			max_bright = constrain(max_bright, 0, 255);
			Serial.print("Max brightness: ");
			Serial.println(max_bright);
			LEDS.setBrightness(max_bright);
			break;

			// Command: c - clear strip
		//case 99:
		//	Serial.println("Clearing strip ");
		//	led_mode = 0;
		//	strobe_mode(led_mode, 1, 0);
		//	break;

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
			Serial.println(actual_leds.this_hue);
			break;

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

			// Command: i Change this_inc (0-255)
		case 105:
			this_arg = Serial.parseInt();
			actual_leds.this_inc = constrain(this_arg, 0, 255);
			Serial.print("this_inc: ");
			Serial.println(actual_leds.this_inc);
			break;

			// Command: j Change this_speed (0-255)
		case 106:
			this_arg = Serial.parseInt();
			actual_leds.this_speed = constrain(this_arg, 0, 255);
			Serial.print("this_speed: ");
			Serial.println(actual_leds.this_speed);
			break;

			// Command: k Change this_rot (0-255)
		case 107:
			this_arg = Serial.parseInt();
			actual_leds.this_rot = constrain(this_arg, 0, 255);
			Serial.print("this_rot: ");
			Serial.println(actual_leds.this_rot);
			break;

			// Command: l Change this_cutoff (0-255)
		case 108:
			this_arg = Serial.parseInt();
			actual_leds.this_cutoff = constrain(this_arg, 0, 255);
			Serial.print("this_cutoff: ");
			Serial.println(actual_leds.this_cutoff);
			break;

			// Command: n Change all_freq (0-255)
		case 110:
			this_arg = Serial.parseInt();
			actual_leds.all_freq = constrain(this_arg, 0, 255);
			Serial.print("all_freq: ");
			Serial.println(actual_leds.all_freq);
			break;

			// Command: o Change this_fade (0-255)
		case 111:
			this_arg = Serial.parseInt();
			actual_leds.this_fade = constrain(this_arg, 0, 255);
			Serial.print("this_fade: ");
			Serial.println(actual_leds.this_fade);
			break;

			// Command: p Change numdots_ring (0-255)
		case 112:
			this_arg = Serial.parseInt();
			actual_leds.numdots_ring = constrain(this_arg, 0, 255);
			Serial.print("numdots_ring: ");
			Serial.println(actual_leds.numdots_ring);
			break;

			// Command: q Change this_beat (0-255)
		case 113:
			this_arg = Serial.parseInt();
			actual_leds.this_beat = constrain(this_arg, 0, 255);
			Serial.print("this_beat: ");
			Serial.println(actual_leds.this_beat);
			break;

			// Command: r Change all_freq (0-255)
		case 114:
			this_arg = Serial.parseInt();
			actual_leds.this_diff = constrain(this_arg, 0, 255);
			Serial.print("this_diff: ");
			Serial.println(actual_leds.this_diff);
			break;

			// Command: s {saturation} - set saturation to {saturation} (0-255)
		case 115:
			this_arg = Serial.parseInt();
			actual_leds.this_sat = constrain(this_arg, 0, 255);
			Serial.print("Saturation: ");
			Serial.println(actual_leds.this_sat);
			break;

			// Command: t {0/1} - juggle_index_reset
		case 116:
			this_arg = Serial.parseInt();
			if (this_arg) {	actual_leds.juggle_index_reset = 1;	}
			else { actual_leds.juggle_index_reset = 0; }
			Serial.print("Juggle_index_reset: ");
			Serial.println(actual_leds.juggle_index_reset);
			break;

			// Command: u Change this_bright (0-255)
		case 117:
			this_arg = Serial.parseInt();
			actual_leds.this_bright = constrain(this_arg, 0, 255);
			Serial.print("this_bright: ");
			Serial.println(actual_leds.this_bright);
			break;

			// Command: v Change numdots (0-255)
		case 118:
			this_arg = Serial.parseInt();
			actual_leds.numdots = constrain(this_arg, 0, 255);
			Serial.print("numdots: ");
			Serial.println(actual_leds.numdots);
			break;

			// Command: w Change numdots (0-255)
		case 119:
			this_arg = Serial.parseInt();
			actual_leds.cooling = constrain(this_arg, 0, 255);
			Serial.print("cooling: ");
			Serial.println(actual_leds.cooling);
			break;

			// Command: x Change numdots (0-255)
		case 120:
			this_arg = Serial.parseInt();
			actual_leds.sparking = constrain(this_arg, 0, 255);
			Serial.print("sparking: ");
			Serial.println(actual_leds.sparking);
			break;

			// Command: y Change numdots (0-255)
		case 121:
			this_arg = Serial.parseInt();
			actual_leds.circ_scale = constrain(this_arg, 0, 255);
			Serial.print("circ_scale: ");
			Serial.println(actual_leds.circ_scale);
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