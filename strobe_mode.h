void strobe_mode(LEDStruct& leds, bool mc) {
	if (mc) {
		fill_solid(leds.strip, NUM_LEDS, CRGB(0, 0, 0));
		combo_handling();
	}

	switch (leds.led_mode) { // keep combo_modes array updated to include led_mode values that use a combo LEDStruct (combo[A,B,C,D]_leds)
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