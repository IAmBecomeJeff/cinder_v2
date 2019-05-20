void strobe_mode(LEDStruct& leds, bool mc) {
	if (mc) {
		fill_solid(leds.strip, NUM_LEDS, CRGB(0, 0, 0));
		combo_handling();
	}

	switch (leds.led_mode) { // keep combo_modes array updated to include led_mode values that use a combo LEDStruct (combo[A,B,C,D]_leds)
		case 0:
			fill_solid(leds.strip, NUM_LEDS, CRGB(0, 0, 0));
			break;

		case 1:
			if (mc) { leds.this_delay = 15; leds.target_palette = RainbowColors_p; leds.all_freq = 4; leds.this_bright = 255; leds.start_index = 0; leds.this_inc = 16; leds.this_cutoff = 200; leds.this_rot = 10; leds.this_speed = 3; }
			one_sin_pal(leds);
			break;

		case 2:
			if (mc) { leds.this_delay = 15;  leds.target_palette = RainbowColors_p; leds.all_freq = 8; leds.this_bright = 255; leds.start_index = 0; leds.this_inc = 24; leds.this_cutoff = 100; leds.this_rot = 1; leds.this_speed = 6; }
			one_sin_pal(leds);
			break;

		case 3:
			if (mc) { leds.this_delay = 20; leds.target_palette = green_gp; leds.this_inc = 1; leds.this_fade = 2; leds.this_diff = 32; leds.this_bright = 255; }
			confetti(leds);
			break;

		case 4:
			if (mc) { leds.this_delay = 20; leds.target_palette = Skydye11_gp; leds.this_inc = 1; leds.this_fade = 2; leds.this_diff = 32; leds.this_bright = 255; }
			confetti_ring(leds);
			break;

		case 5:
			if (mc) { leds.this_delay = 10; leds.this_speed = 12; leds.that_speed = 6; leds.this_rot = 1; leds.that_rot = 10; leds.all_freq = 3; leds.this_cutoff = 200; leds.that_cutoff = 128;  leds.this_sat = 255;leds.that_sat = 255; }
			two_sin(leds);
			break;
		
		case 6:
			if (mc) { leds.this_delay = 15; leds.this_speed = 12; leds.that_speed = 6; leds.this_rot = 1; leds.that_rot = 10; leds.all_freq = 3; leds.this_cutoff = 200; leds.that_cutoff = 100; leds.this_sat = 255;leds.that_sat = 255; }
			two_sin_ring(leds);
			break;

		case 7:
			if (mc) { leds.this_delay = 15; leds.target_palette = stratosphere_sunset_gp;  leds.this_speed = 12; leds.that_speed = 6; leds.this_rot = 1; leds.that_rot = 10; leds.all_freq = 3; leds.this_cutoff = 200; leds.that_cutoff = 100; leds.this_sat = 255;leds.that_sat = 255; }
			two_sin_pal_ring(leds);
			break;

		case 8:
			if (mc) { leds.this_delay = 15; leds.target_palette = blueice_gp; }
			plasma(leds);
			break;

		case 9:
			if (mc) { leds.this_delay = 10; leds.target_palette = GMT_cool_gp; leds.this_fade = 180; leds.this_bright = 255; leds.ripple_fade = 128; leds.ripple_step = -1; }
			ripple(leds);
			break;

		case 10:
			if (mc) { leds.this_delay = 10; leds.target_palette = parrot_gp; leds.this_fade = 180; leds.this_bright = 255; leds.ripple_fade = 128; leds.ripple_step = -1; }
			ripple_through_pal(leds);
			break;

		case 11:
			if (mc) { leds.this_delay = 15; leds.target_palette = bhw3_61_gp; }
			colorwave(leds);
			break;

		case 12:
			if (mc) { leds.this_delay = 12; leds.this_rot = 32; leds.this_diff = 6; leds.this_index = 0; }
			rainbow_march(leds);
			break;

		case 13:
			if (mc) { leds.this_delay = 12; leds.this_rot = 3; leds.this_diff = 16; leds.this_index = 0; }
			rainbow_march_ring(leds);
			break;

		case 14:
			if (mc) { leds.this_delay = 20; leds.target_palette = ofaurora_gp; leds.this_inc = 4; leds.this_speed = 2; leds.all_freq = 4; leds.this_phase = 0; leds.start_index = 0; leds.this_rot = 3; }
			spiral_sin(leds);
			break;

		case 15:
			if (mc) { leds.this_delay = 15; leds.target_palette = water1_gp; leds.spiral_num = 2; leds.this_inc = 7; leds.this_speed = 0; leds.all_freq = 2; leds.this_phase = 0; leds.start_index = 0; leds.this_rot = 0; leds.bg_clr = 0; leds.bg_bri = 0; }
			one_sin_spiral(leds);
			break;

		case 16:
			if (mc) { leds.this_delay = 10; leds.target_palette = sunlitwave_gp; leds.this_fade = 200; leds.numdots_ring = 3; leds.this_beat = 10; leds.this_bright = 255; leds.this_diff = 6; leds.juggle_index_reset = 0; }
			juggle_ring(leds);
			break;

		case 17:
			if (mc) { leds.this_delay = 10; leds.target_palette = Complementary_01a_gp; leds.this_fade = 100; leds.numdots_ring = 5; leds.this_beat = 64; leds.this_bright = 255; leds.this_diff = 0; leds.juggle_index_reset = 1; }
			juggle_ring_onedir(leds);
			break;

		case 18:
			if (mc) { leds.this_delay = 10; leds.target_palette = scoutie_gp; leds.this_fade = 200; leds.numdots = 3; leds.ringBeat[0] = 5; leds.ringBeat[1] = 10; leds.ringBeat[2] = 3; leds.ringBeat[3] = 1; leds.this_bright = 255; leds.this_diff = 6; leds.juggle_index_reset = 0; }
			juggle_columns_all(leds);
			break;

		case 19:
			if (mc) { leds.this_delay = 10; leds.target_palette = cequal_gp; leds.this_fade = 164; leds.numdots = 4; leds.ringBeat[0] = 5; leds.ringBeat[1] = 1; leds.ringBeat[2] = 3; leds.ringBeat[3] = 1; leds.this_bright = 255; leds.this_diff = 6; leds.juggle_index_reset = 0; }
			juggle_columns_onedir_all(leds);
			break;

		case 20:
			if (mc) { leds.this_delay = 12; leds.this_fade = 32; leds.this_sat = 255; leds.this_bright = 255; leds.gHue = 0; }
			sinelon_rainbow(leds);
			break;

		case 21:
			if (mc) { leds.this_delay = 10; leds.sparking = 60; leds.cooling = 30; }
			fire(leds);
			break;

		case 22:
			if (mc) { leds.this_delay = 10; leds.target_palette = blade_runner_2049_gp; leds.sparking = 60; leds.cooling = 30; }
			fire_pal(leds);
			break;

		case 23:
			if (mc) { leds.this_delay = 10; leds.sparking = 50; leds.cooling = 100; }
			fire_mirror(leds);
			break;

		case 24:
			if (mc) { leds.this_delay = 10; leds.target_palette = purple_flower_gp; leds.sparking = 100; leds.cooling = 70; }
			fire_mirror_pal(leds);
			break;

		case 25:
			if (mc) { leds.this_delay = 10; leds.sparking_columns[0] = 50; leds.sparking_columns[1] = 60; leds.sparking_columns[2] = 20; leds.sparking_columns[3] = 80; leds.cooling_columns[0] = 50; leds.cooling_columns[1] = 40; leds.cooling_columns[2] = 30; leds.cooling_columns[3] = 60; }
			fire_columns(leds);
			break;

		case 26:
			if (mc) { leds.this_delay = 10; leds.target_palette = slope_gp; leds.sparking_columns[0] = 50; leds.sparking_columns[1] = 60; leds.sparking_columns[2] = 20; leds.sparking_columns[3] = 80; leds.cooling_columns[0] = 50; leds.cooling_columns[1] = 40; leds.cooling_columns[2] = 30; leds.cooling_columns[3] = 60; }
			fire_columns_pal(leds);
			break;

		case 27:
			if (mc) { leds.this_delay = 10; leds.sparking_columns[0] = 50; leds.sparking_columns[1] = 60; leds.sparking_columns[2] = 20; leds.sparking_columns[3] = 80; leds.cooling_columns[0] = 50; leds.cooling_columns[1] = 40; leds.cooling_columns[2] = 30; leds.cooling_columns[3] = 60;	}
			fire_mirror_columns(leds);
			break;

		case 28:
			if (mc) { leds.this_delay = 10; leds.target_palette = Fire_1_gp; leds.sparking_columns[0] = 50; leds.sparking_columns[1] = 60; leds.sparking_columns[2] = 20; leds.sparking_columns[3] = 80; leds.cooling_columns[0] = 50; leds.cooling_columns[1] = 40; leds.cooling_columns[2] = 30; leds.cooling_columns[3] = 60; }
			fire_mirror_columns_pal(leds);
			break;

		case 29:
			if (mc) { leds.this_delay = 10; leds.target_palette = ofaurora_gp; leds.sparking = 60; leds.cooling = 50; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots_ring = 4; leds.this_beat = 10; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_fire(leds);
			break;

		case 30:
			if (mc) { leds.this_delay = 10; leds.target_palette = ofaurora_gp; leds.sparking = 60; leds.cooling = 50; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots_ring = 4; leds.this_beat = 10; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_onedir_fire(leds);
			break;

		case 31:
			if (mc) { leds.this_delay = 10; leds.target_palette = ofaurora_gp; leds.sparking = 60; leds.cooling = 50; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots = 3; leds.ringBeat[0] = 1; leds.ringBeat[1] = 4; leds.ringBeat[2] = 3; leds.ringBeat[3] = 4; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_columns_fire(leds);
			break;

		case 32:
			if (mc) { leds.this_delay = 10; leds.target_palette = ofaurora_gp; leds.sparking = 60; leds.cooling = 50; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots = 3; leds.ringBeat[0] = 1; leds.ringBeat[1] = 4; leds.ringBeat[2] = 3; leds.ringBeat[3] = 4; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_columns_onedir_fire(leds);
			break;

		case 33:
			if (mc) { leds.this_delay = 10; leds.target_palette = ofaurora_gp; leds.sparking = 60; leds.cooling = 50; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots_ring = 4; leds.this_beat = 10; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_fire_pal(leds);
			break;

		case 34:
			if (mc) { leds.this_delay = 10; leds.target_palette = ofaurora_gp; leds.sparking = 60; leds.cooling = 50; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots_ring = 4; leds.this_beat = 10; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_onedir_fire_pal(leds);
			break;

		case 35:
			if (mc) { leds.this_delay = 10; leds.target_palette = ofaurora_gp; leds.sparking = 60; leds.cooling = 50; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots = 3; leds.ringBeat[0] = 1; leds.ringBeat[1] = 4; leds.ringBeat[2] = 3; leds.ringBeat[3] = 4; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_columns_fire_pal(leds);
			break;

		case 36:
			if (mc) { leds.this_delay = 10; leds.target_palette = ofaurora_gp; leds.sparking = 60; leds.cooling = 50; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots = 3; leds.ringBeat[0] = 1; leds.ringBeat[1] = 4; leds.ringBeat[2] = 3; leds.ringBeat[3] = 4; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_columns_onedir_fire_pal(leds);
			break;

		case 37:
			if (mc) { leds.this_delay = 10; leds.target_palette = ofaurora_gp; leds.sparking = 60; leds.cooling = 50; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots_ring = 4; leds.this_beat = 10; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_fire_mirror(leds);
			break;

		case 38:
			if (mc) { leds.this_delay = 10; leds.target_palette = ofaurora_gp; leds.sparking = 60; leds.cooling = 50; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots_ring = 4; leds.this_beat = 10; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_onedir_fire_mirror(leds);
			break;

		case 39:
			if (mc) { leds.this_delay = 10; leds.target_palette = ofaurora_gp; leds.sparking = 60; leds.cooling = 50; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots = 3; leds.ringBeat[0] = 1; leds.ringBeat[1] = 4; leds.ringBeat[2] = 3; leds.ringBeat[3] = 4; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_columns_fire_mirror(leds);
			break;

		case 40:
			if (mc) { leds.this_delay = 10; leds.target_palette = ofaurora_gp; leds.sparking = 60; leds.cooling = 50; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots = 3; leds.ringBeat[0] = 1; leds.ringBeat[1] = 4; leds.ringBeat[2] = 3; leds.ringBeat[3] = 4; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_columns_onedir_fire_mirror(leds);
			break;

		case 41:
			if (mc) { leds.this_delay = 10; leds.target_palette = ofaurora_gp; leds.sparking = 60; leds.cooling = 50; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots_ring = 4; leds.this_beat = 10; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_fire_mirror_pal(leds);
			break;

		case 42:
			if (mc) { leds.this_delay = 10; leds.target_palette = ofaurora_gp; leds.sparking = 60; leds.cooling = 50; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots_ring = 4; leds.this_beat = 10; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_onedir_fire_mirror_pal(leds);
			break;

		case 43:
			if (mc) { leds.this_delay = 10; leds.target_palette = ofaurora_gp; leds.sparking = 60; leds.cooling = 50; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots = 3; leds.ringBeat[0] = 1; leds.ringBeat[1] = 4; leds.ringBeat[2] = 3; leds.ringBeat[3] = 4; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_columns_fire_mirror_pal(leds);
			break;

		case 44:
			if (mc) { leds.this_delay = 10; leds.target_palette = ofaurora_gp; leds.sparking = 60; leds.cooling = 50; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots = 3; leds.ringBeat[0] = 1; leds.ringBeat[1] = 4; leds.ringBeat[2] = 3; leds.ringBeat[3] = 4; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_columns_onedir_fire_mirror_pal(leds);
			break;

		case 45:
			if (mc) { leds.this_delay = 10; leds.target_palette = ofaurora_gp;leds.sparking_columns[0] = 50; leds.sparking_columns[1] = 60; leds.sparking_columns[2] = 20; leds.sparking_columns[3] = 80;  leds.cooling_columns[0] = 50; leds.cooling_columns[1] = 45; leds.cooling_columns[2] = 32; leds.cooling_columns[3] = 30; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots_ring = 4; leds.this_beat = 10; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_fire_columns(leds);
			break;

		case 46:
			if (mc) { leds.this_delay = 10; leds.target_palette = ofaurora_gp;leds.sparking_columns[0] = 50; leds.sparking_columns[1] = 60; leds.sparking_columns[2] = 20; leds.sparking_columns[3] = 80;  leds.cooling_columns[0] = 50; leds.cooling_columns[1] = 45; leds.cooling_columns[2] = 32; leds.cooling_columns[3] = 30; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots_ring = 4; leds.this_beat = 10; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_onedir_fire_columns(leds);
			break;

		case 47:
			if (mc) { leds.this_delay = 10;  leds.target_palette = ofaurora_gp; leds.sparking_columns[0] = 50; leds.sparking_columns[1] = 60; leds.sparking_columns[2] = 20; leds.sparking_columns[3] = 80;  leds.cooling_columns[0] = 50; leds.cooling_columns[1] = 40; leds.cooling_columns[2] = 30; leds.cooling_columns[3] = 60; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots = 3; leds.ringBeat[0] = 1; leds.ringBeat[1] = 4; leds.ringBeat[2] = 3; leds.ringBeat[3] = 4; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_columns_fire_columns(leds);
			break;

		case 48:
			if (mc) { leds.this_delay = 10;  leds.target_palette = ofaurora_gp; leds.sparking_columns[0] = 50; leds.sparking_columns[1] = 60; leds.sparking_columns[2] = 20; leds.sparking_columns[3] = 80;  leds.cooling_columns[0] = 50; leds.cooling_columns[1] = 40; leds.cooling_columns[2] = 30; leds.cooling_columns[3] = 60; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots = 3; leds.ringBeat[0] = 1; leds.ringBeat[1] = 4; leds.ringBeat[2] = 3; leds.ringBeat[3] = 4; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_columns_onedir_fire_columns(leds);
			break;

		case 49:
			if (mc) { leds.this_delay = 10; leds.target_palette = ofaurora_gp;leds.sparking_columns[0] = 50; leds.sparking_columns[1] = 60; leds.sparking_columns[2] = 20; leds.sparking_columns[3] = 80;  leds.cooling_columns[0] = 50; leds.cooling_columns[1] = 45; leds.cooling_columns[2] = 32; leds.cooling_columns[3] = 30; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots_ring = 4; leds.this_beat = 10; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_fire_columns_pal(leds);
			break;

		case 50:
			if (mc) { leds.this_delay = 10; leds.target_palette = ofaurora_gp;leds.sparking_columns[0] = 50; leds.sparking_columns[1] = 60; leds.sparking_columns[2] = 20; leds.sparking_columns[3] = 80;  leds.cooling_columns[0] = 50; leds.cooling_columns[1] = 45; leds.cooling_columns[2] = 32; leds.cooling_columns[3] = 30; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots_ring = 4; leds.this_beat = 10; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_onedir_fire_columns_pal(leds);
			break;

		case 51:
			if (mc) { leds.this_delay = 10;  leds.target_palette = ofaurora_gp; leds.sparking_columns[0] = 50; leds.sparking_columns[1] = 60; leds.sparking_columns[2] = 20; leds.sparking_columns[3] = 80;  leds.cooling_columns[0] = 50; leds.cooling_columns[1] = 40; leds.cooling_columns[2] = 30; leds.cooling_columns[3] = 60; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots = 3; leds.ringBeat[0] = 1; leds.ringBeat[1] = 4; leds.ringBeat[2] = 3; leds.ringBeat[3] = 4; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_columns_fire_columns_pal(leds);
			break;

		case 52:
			if (mc) { leds.this_delay = 10;  leds.target_palette = ofaurora_gp; leds.sparking_columns[0] = 50; leds.sparking_columns[1] = 60; leds.sparking_columns[2] = 20; leds.sparking_columns[3] = 80;  leds.cooling_columns[0] = 50; leds.cooling_columns[1] = 40; leds.cooling_columns[2] = 30; leds.cooling_columns[3] = 60; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots = 3; leds.ringBeat[0] = 1; leds.ringBeat[1] = 4; leds.ringBeat[2] = 3; leds.ringBeat[3] = 4; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_columns_onedir_fire_columns_pal(leds);
			break;

		case 53:
			if (mc) { leds.this_delay = 10; leds.target_palette = ofaurora_gp;leds.sparking_columns[0] = 50; leds.sparking_columns[1] = 60; leds.sparking_columns[2] = 20; leds.sparking_columns[3] = 80;  leds.cooling_columns[0] = 50; leds.cooling_columns[1] = 45; leds.cooling_columns[2] = 32; leds.cooling_columns[3] = 30; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots_ring = 4; leds.this_beat = 10; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_fire_mirror_columns(leds);
			break;

		case 54:
			if (mc) { leds.this_delay = 10; leds.target_palette = ofaurora_gp;leds.sparking_columns[0] = 50; leds.sparking_columns[1] = 60; leds.sparking_columns[2] = 20; leds.sparking_columns[3] = 80;  leds.cooling_columns[0] = 50; leds.cooling_columns[1] = 45; leds.cooling_columns[2] = 32; leds.cooling_columns[3] = 30; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots_ring = 4; leds.this_beat = 10; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_onedir_fire_mirror_columns(leds);
			break;

		case 55:
			if (mc) { leds.this_delay = 10; leds.target_palette = ofaurora_gp; leds.sparking_columns[0] = 50; leds.sparking_columns[1] = 60; leds.sparking_columns[2] = 20; leds.sparking_columns[3] = 80;  leds.cooling_columns[0] = 50; leds.cooling_columns[1] = 40; leds.cooling_columns[2] = 30; leds.cooling_columns[3] = 60; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots = 3; leds.ringBeat[0] = 1; leds.ringBeat[1] = 4; leds.ringBeat[2] = 3; leds.ringBeat[3] = 4; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_columns_fire_mirror_columns(leds);
			break;

		case 56:
			if (mc) { leds.this_delay = 10;  leds.target_palette = ofaurora_gp; leds.sparking_columns[0] = 50; leds.sparking_columns[1] = 60; leds.sparking_columns[2] = 20; leds.sparking_columns[3] = 80;  leds.cooling_columns[0] = 50; leds.cooling_columns[1] = 40; leds.cooling_columns[2] = 30; leds.cooling_columns[3] = 60; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots = 3; leds.ringBeat[0] = 1; leds.ringBeat[1] = 4; leds.ringBeat[2] = 3; leds.ringBeat[3] = 4; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_columns_onedir_fire_mirror_columns(leds);
			break;

		case 57:
			if (mc) { leds.this_delay = 10; leds.target_palette = ofaurora_gp;leds.sparking_columns[0] = 50; leds.sparking_columns[1] = 60; leds.sparking_columns[2] = 20; leds.sparking_columns[3] = 80;  leds.cooling_columns[0] = 50; leds.cooling_columns[1] = 45; leds.cooling_columns[2] = 32; leds.cooling_columns[3] = 30; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots_ring = 4; leds.this_beat = 10; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_fire_mirror_columns_pal(leds);
			break;

		case 58:
			if (mc) { leds.this_delay = 10; leds.target_palette = ofaurora_gp;leds.sparking_columns[0] = 50; leds.sparking_columns[1] = 60; leds.sparking_columns[2] = 20; leds.sparking_columns[3] = 80;  leds.cooling_columns[0] = 50; leds.cooling_columns[1] = 45; leds.cooling_columns[2] = 32; leds.cooling_columns[3] = 30; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots_ring = 4; leds.this_beat = 10; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_onedir_fire_mirror_columns_pal(leds);
			break;

		case 59:
			if (mc) { leds.this_delay = 10;  leds.this_delay = 10; leds.target_palette = ofaurora_gp; leds.sparking_columns[0] = 50; leds.sparking_columns[1] = 60; leds.sparking_columns[2] = 20; leds.sparking_columns[3] = 80;  leds.cooling_columns[0] = 50; leds.cooling_columns[1] = 40; leds.cooling_columns[2] = 30; leds.cooling_columns[3] = 60; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots = 3; leds.ringBeat[0] = 1; leds.ringBeat[1] = 4; leds.ringBeat[2] = 3; leds.ringBeat[3] = 4; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_columns_fire_mirror_columns_pal(leds);
			break;

		case 60:
			if (mc) { leds.this_delay = 10;  leds.this_delay = 10; leds.target_palette = ofaurora_gp; leds.sparking_columns[0] = 50; leds.sparking_columns[1] = 60; leds.sparking_columns[2] = 20; leds.sparking_columns[3] = 80;  leds.cooling_columns[0] = 50; leds.cooling_columns[1] = 40; leds.cooling_columns[2] = 30; leds.cooling_columns[3] = 60; leds.juggle_index_reset = 0; leds.this_fade = 64; leds.numdots = 3; leds.ringBeat[0] = 1; leds.ringBeat[1] = 4; leds.ringBeat[2] = 3; leds.ringBeat[3] = 4; leds.this_bright = 255; leds.this_diff = 4; }
			juggle_columns_onedir_fire_mirror_columns_pal(leds);
			break;

	}
}
