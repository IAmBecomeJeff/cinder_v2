#ifndef TWO_SIN_H
#define TWO_SIN_H

// two_sin()
// two_sin_ring()
// two_sin_pal_ring()
//
//	Variables:
//		leds.this_dir
//		leds.this_speed
//		leds.that_speed
//		leds.this_rot
//		leds.that_rot
//		leds.all_freq
//		leds.this_cutoff
//		leds.this_sat
//		leds.target_palette

void two_sin(LEDStruct& leds) {
	if (leds.this_dir) { leds.this_phase -= leds.this_speed; leds.that_phase -= leds.that_speed; }
	else { leds.this_phase += leds.this_speed; leds.that_phase += leds.that_speed; }
	leds.this_hue += leds.this_rot;
	leds.that_hue += leds.that_rot;
	for (int k = 0; k < NUM_LEDS - 1; k++) {
		int this_bright = qsuba(cubicwave8((k*leds.all_freq) + leds.this_phase), leds.this_cutoff);
		int that_bright = qsuba(cubicwave8((k*leds.all_freq) + 128 + leds.that_phase), leds.this_cutoff);
		leds.strip[k] = CHSV(leds.this_hue, leds.this_sat, this_bright);
		leds.strip[k] += CHSV(leds.that_hue, leds.that_sat, that_bright);
	}
}

void two_sin_ring(LEDStruct& leds) {
	if (leds.this_dir) { leds.this_phase -= leds.this_speed; leds.that_phase -= leds.that_speed; }
	else { leds.this_phase += leds.this_speed; leds.that_phase += leds.that_speed; }
	leds.this_hue += leds.this_rot;
	leds.that_hue += leds.that_rot;
	for (int k = 0; k < NUM_LEDS - 1; k++) {
		int this_bright = qsuba(cubicwave8((k*leds.all_freq) + leds.this_phase), leds.this_cutoff);
		int that_bright = qsuba(cubicwave8((k*leds.all_freq) + 128 + leds.that_phase), leds.this_cutoff);
		ringCHSV(leds, k, leds.this_hue, leds.this_sat, this_bright);
		ringCHSVAdd(leds, k, leds.that_hue, leds.that_sat, that_bright);
	}
}

void two_sin_pal_ring(LEDStruct& leds) {
	if (leds.this_dir) { leds.this_phase -= leds.this_speed; leds.that_phase -= leds.that_speed; }
	else { leds.this_phase += leds.this_speed; leds.that_phase += leds.that_speed; }
	leds.this_hue += leds.this_rot;
	leds.that_hue += leds.that_rot; // that_hue will be palette pos
	for (int k = 0; k < NUM_LEDS - 1; k++) {
		int this_bright = qsuba(cubicwave8((k*leds.all_freq) + leds.this_phase), leds.this_cutoff);
		int that_bright = qsuba(cubicwave8((k*leds.all_freq) + 128 + leds.that_phase), leds.this_cutoff);
		ringCHSV(leds, k, leds.this_hue, leds.this_sat, this_bright);
		ringPaletteAdd(leds, k, leds.current_palette, leds.that_hue, that_bright, leds.current_blending);
	}
}


#endif
