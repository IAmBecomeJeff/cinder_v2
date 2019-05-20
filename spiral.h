#ifndef SPIRAL_H
#define SPIRAL_H

//	spiral_sin()
//	one_sin_spiral()
//
//	Variables:
//		leds.this_inc
//		leds.this_speed
//		leds.all_freq
//		leds.this_phase (starting)
//		leds.start_index (starting)
//		leds.target_palette
//		leds.current_blending
//		leds.this_rot
//
//		leds.spiral_num [0-3]
//		leds.bg_clr
//		leds.bg_bri


void spiral_sin(LEDStruct& leds) {
	fill_solid(leds.strip, NUM_LEDS, CRGB(0, 0, 0));
	leds.start_index += leds.this_inc;
	leds.this_index = leds.start_index;
	leds.this_phase += leds.this_speed;
	for (uint8_t k = 0; k < STRIP_LENGTH; k++) {
		for (int r = 0; r < 4; r++) {
			uint8_t spiral_bri = qsuba(scale8(cubicwave8((k * leds.all_freq) + r * 64 + leds.this_phase), 120), 85);
			leds.strip[ringArray[k][r]] = ColorFromPalette(leds.current_palette, leds.this_index + k * leds.this_inc, spiral_bri, leds.current_blending);
		}
		leds.this_index += leds.this_rot;
	}
}


void one_sin_spiral(LEDStruct& leds) {
	leds.start_index += leds.this_inc;
	leds.this_index = leds.start_index;
	if (leds.this_dir) { leds.this_phase += leds.this_speed; }
	else { leds.this_phase -= leds.this_speed; }
	for (int k = 0; k < STRIP_LENGTH; k++) {
		uint8_t this_bright = qsubd(cubicwave8((k * leds.all_freq) + leds.this_phase), leds.this_cutoff);
		leds.strip[spiralArray[leds.spiral_num][k]] = CHSV(leds.bg_clr, 255, leds.bg_bri);
		leds.strip[spiralArray[leds.spiral_num][k]] += ColorFromPalette(leds.current_palette, leds.this_index + k * leds.this_inc, this_bright, leds.current_blending);
		leds.this_index += leds.this_rot;
	}
}




#endif