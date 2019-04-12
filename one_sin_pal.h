void one_sin_pal(LEDClass leds) {
	leds.start_index += leds.this_inc;
	leds.this_index = leds.start_index;
	if (leds.this_dir) {
		leds.this_phase += leds.this_speed;
	}
	else {
		leds.this_phase -= leds.this_speed;
	}
	for (int k = 0; k < NUM_LEDS; k++) {
		leds.this_bright = qsubd(cubicwave8((k*leds.all_freq) + leds.this_phase), leds.this_cutoff);
		leds.strip[k] += ColorFromPalette(leds.current_palette, leds.this_index + k * leds.this_inc, leds.this_bright, leds.current_blending);
		leds.this_index += leds.this_rot;
	}
} // one_sin()