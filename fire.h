#ifndef FIRE_H
#define FIRE_H

// Functions:
	// fire()			
		// Moves a fire along the strip, with the rings all the same

	// fire_pal()
		// Moves a fire along the strip with a palette, with the rings all the same

	// fire_mirror()
		// Fire from middle or ends, rings all the same

	// fire_mirror_pal()
		// Fire mirrored, with palette, rings all the same

	// fire_rings()
		// Fire with each strip a different flame

	// fire_pal_rings()
		// Fire with each strip a different flame, using palettes

	// fire_mirror_rings()
		// Mirrored fire, with each strip different flame

	// fire_mirror_pal_rings()
		// Mirrored fire, with palettes, each strip different


void fire(LEDStruct& leds) {

	for (uint8_t i = 0; i < STRIP_LENGTH; i++) {
		leds.heat[i] = qsub8(leds.heat[i], random8(0, ((leds.cooling * 10) / STRIP_LENGTH) + 2));
	}

	for (int k = STRIP_LENGTH - 3; k >= 2; k--) {
		leds.heat[k] = (leds.heat[k - 1] + leds.heat[k - 2] + leds.heat[k - 2]) / 3;
	}

	if (random8() < leds.sparking) {
		int y = random8(7);
		leds.heat[y] = qadd8(leds.heat[y], random8(160, 255));
	}

	if (leds.this_dir) {
		for (int j = 0; j < STRIP_LENGTH; j++) {
			CRGB hcolor = HeatColor(leds.heat[j]);
			ringCRGB(leds, j, hcolor.r, hcolor.g, hcolor.b);
		}
	}
	else {
		for (int j = 0; j < STRIP_LENGTH; j++) {
			CRGB hcolor = HeatColor(leds.heat[j]);
			ringCRGB(leds, (STRIP_LENGTH - 1) - j, hcolor.r, hcolor.g, hcolor.b);
		}
	}
}

void fire_pal(LEDStruct& leds) {

	for (uint8_t i = 0; i < STRIP_LENGTH; i++) {
		leds.heat[i] = qsub8(leds.heat[i], random8(0, ((leds.cooling * 10) / STRIP_LENGTH) + 2));
	}

	for (int k = STRIP_LENGTH - 3; k >= 2; k--) {
		leds.heat[k] = (leds.heat[k - 1] + leds.heat[k - 2] + leds.heat[k - 2]) / 3;
	}

	if (random8() < leds.sparking) {
		int y = random8(7);
		leds.heat[y] = qadd8(leds.heat[y], random8(160, 255));
	}

	if (leds.this_dir) {
		for (int j = 0; j < STRIP_LENGTH; j++) {
			ringPalette(leds, j, leds.current_palette, scale8(leds.heat[j], 240), leds.this_bright, leds.this_blending);
		}
	}
	else {
		for (int j = 0; j < STRIP_LENGTH; j++) {
			ringPalette(leds, (STRIP_LENGTH - 1) - j, leds.current_palette, scale8(leds.heat[j], 240), leds.this_bright, leds.this_blending);
		}
	}
}


void fire_mirror(LEDStruct& leds) {
	for (int i = 0; i < STRIP_LENGTH / 2; i++) {
		leds.heat_mirror[i] = qsub8(leds.heat_mirror[i], random8(0, ((leds.cooling * 10) / (STRIP_LENGTH / 2)) + 2));
	}

	for (int k = (STRIP_LENGTH / 2) - 1; k >= 2; k--) {
		leds.heat_mirror[k] = (leds.heat_mirror[k - 1] + leds.heat_mirror[k - 2] + leds.heat_mirror[k - 2]) / 3;
	}

	if (random8() < leds.sparking) {
		int y = random8(7);
		leds.heat_mirror[y] = qadd8(leds.heat_mirror[y], random8(160, 255));
	}

	if (leds.this_dir) {
		for (int j = 0; j < STRIP_LENGTH / 2; j++) {
			CRGB hcolor = HeatColor(leds.heat_mirror[j]);
			ringCRGB(leds, j, hcolor.r, hcolor.g, hcolor.b);
			ringCRGB(leds, STRIP_LENGTH - 1 - j, hcolor.r, hcolor.g, hcolor.b);
		}
	}
	else {
		for (int j = 0; j < STRIP_LENGTH / 2; j++) {
			CRGB hcolor = HeatColor(leds.heat_mirror[j]]);
			ringCRGB(leds, (STRIP_LENGTH / 2) - 1 - j, hcolor.r, hcolor.g, hcolor.b);
			ringCRGB(leds, (STRIP_LENGTH / 2) + j, hcolor.r, hcolor.g, hcolor.b);
		}
	}
}


void fire_mirror_pal(LEDStruct& leds) {
	for (int i = 0; i < STRIP_LENGTH / 2; i++) {
		leds.heat_mirror[i] = qsub8(leds.heat_mirror[i], random8(0, ((leds.cooling * 10) / (STRIP_LENGTH / 2)) + 2));
	}

	for (int k = (STRIP_LENGTH / 2) - 1; k >= 2; k--) {
		leds.heat_mirror[k] = (leds.heat_mirror[k - 1] + leds.heat_mirror[k - 2] + leds.heat_mirror[k - 2]) / 3;
	}

	if (random8() < leds.sparking) {
		int y = random8(7);
		leds.heat_mirror[y] = qadd8(leds.heat_mirror[y], random8(160, 255));
	}

	if (leds.this_dir) {
		for (int j = 0; j < STRIP_LENGTH / 2; j++) {
			byte colorindex = scale8(leds.heat_mirror[j], 240);
			ringPalette(leds, j, leds.current_palette, colorindex, leds.this_bright, leds.this_blending);
			ringPalette(leds, STRIP_LENGTH - 1 - j, leds.current_palette, colorindex, leds.this_bright, leds.this_blending);
		}
	}
	else {
		for (int j = 0; j < STRIP_LENGTH / 2; j++) {
			byte colorindex = scale8(leds.heat_mirror[j], 240);
			ringPalette(leds, (STRIP_LENGTH / 2) - 1 - j, leds.current_palette, colorindex, leds.this_bright, leds.this_blending);
			ringPalette(leds, (STRIP_LENGTH / 2) + j, leds.current_palette, colorindex, leds.this_bright, leds.this_blending);
		}
	}
}


void fire_rings(LEDStruct& leds) {
	for (byte r = 0; r < 4; r++) {
		for (int i = 0; i < STRIP_LENGTH; i++) {
			leds.heat_ring[i][r] = qsub8(leds.heat_ring[i][r], random8(0, ((leds.cooling_ring[r] * 10) / STRIP_LENGTH) + 2));
		}
		for (int k = STRIP_LENGTH - 3; k > 0; k--) {
			leds.heat_ring[k][r] = (leds.heat_ring[k - 1][r] + leds.heat_ring[k - 2][r] + leds.heat_ring[k - 2][r]) / 3;
		}
		if (random8() < leds.sparking_ring[r]) {
			int y = random8(7);
			leds.heat_ring[y][r] = qadd8(leds.heat_ring[y][r], random8(160, 255));
		}
		if (leds.this_dir) {
			for (int j = 0; j < STRIP_LENGTH; j++) {
				leds.strip[ringArray[j][r]] = HeatColor(leds.heat_ring[j]);
			}
		}
		else {
			for (int j = 0; j < STRIP_LENGTH; j++) {
				leds.strip[ringArray[STRIP_LENGTH - 1 - j][r]] = HeatColor(leds.heat_ring[j][r]);
			}
		}
	}
}


void fire_rings_pal(LEDStruct& leds) {
	for (byte r = 0; r < 4; r++) {
		for (int i = 0; i < STRIP_LENGTH; i++) {
			leds.heat_ring[i][r] = qsub8(leds.heat_ring[i][r], random8(0, ((leds.cooling_ring[r] * 10) / STRIP_LENGTH) + 2));
		}
		for (int k = STRIP_LENGTH - 3; k > 0; k--) {
			leds.heat_ring[k][r] = (leds.heat_ring[k - 1][r] + leds.heat_ring[k - 2][r] + leds.heat_ring[k - 2][r]) / 3;
		}
		if (random8() < leds.sparking_ring[r]) {
			int y = random8(7);
			leds.heat_ring[y][r] = qadd8(leds.heat_ring[y][r], random8(160, 255));
		}
		if (leds.this_dir) {
			for (int j = 0; j < STRIP_LENGTH; j++) {
				leds.strip[ringArray[STRIP_LENGTH - 1 - j][r]] = ColorFromPalette(leds.current_palette, scale(leds.heat_ring[j][r], 240));;
			}
		}
		else {
			for (int j = 0; j < STRIP_LENGTH; j++) {
				leds.strip[ringArray[j][r]] = ColorFromPalette(leds.current_palette, scale(leds.heat_ring[j][r], 240));;
			}
		}
	}
}


void fire_mirror_rings(LEDStruct& leds) {
	for (byte r = 0; r < 4; r++) {
		for (int i = 0; i < STRIP_LENGTH / 2; i++) {
			leds.heat_mirror_ring[i][r] = qsub8(leds.heat_mirror_ring[i][r], random8(0, ((leds.cooling_ring[r] * 10) / (STRIP_LENGTH / 2)) + 2));
		}

		for (int k = (STRIP_LENGTH / 2) - 1; k >= 2; k--) {
			leds.heat_mirror_ring[k][r] = (leds.heat_mirror_ring[k - 1][r] + leds.heat_mirror_ring[k - 2][r] + leds.heat_mirror_ring[k - 2][r]) / 3;
		}

		if (random8() < leds.sparking_ring[r]) {
			int y = random8(7);
			leds.heat_mirror_ring[y][r] = qadd8(leds.heat_mirror_ring[y][r], random8(160, 255));
		}

		if (leds.this_dir) {
			for (int j = 0; j < STRIP_LENGTH / 2; j++) {
				CRGB hcolor = HeatColor(leds.heat_mirror_ring[j][r]);
				leds.strip[ringArray[j][r]] = hcolor;
				leds.strip[ringArray[STRIP_LENGTH - 1 - j][r]] = hcolor;
			}
		}
		else {
			for (int j = 0; j < STRIP_LENGTH / 2; j++) {
				CRGB hcolor = HeatColor(leds.heat_mirror_ring[j][r]);
				leds.strip[ringArray[(STRIP_LENGTH / 2) - 1 - j][r]] = hcolor;
				leds.strip[ringArray[(STRIP_LENGTH / 2) + j][r]] = hcolor;
			}
		}
	}
}


void fire_mirror_rings_pal(LEDStruct& leds) {
	for (byte r = 0; r < 4; r++) {
		for (int i = 0; i < STRIP_LENGTH / 2; i++) {
			leds.heat_mirror_ring[i][r] = qsub8(leds.heat_mirror_ring[i][r], random8(0, ((leds.cooling_ring[r] * 10) / (STRIP_LENGTH / 2)) + 2));
		}

		for (int k = (STRIP_LENGTH / 2) - 1; k >= 2; k--) {
			leds.heat_mirror_ring[k][r] = (leds.heat_mirror_ring[k - 1][r] + leds.heat_mirror_ring[k - 2][r] + leds.heat_mirror_ring[k - 2][r]) / 3;
		}

		if (random8() < leds.sparking_ring[r]) {
			int y = random8(7);
			leds.heat_mirror_ring[y][r] = qadd8(leds.heat_mirror_ring[y][r], random8(160, 255));
		}

		if (leds.this_dir) {
			for (int j = 0; j < STRIP_LENGTH / 2; j++) {
				CRGB color = ColorFromPalette(leds.current_palette, scale8(leds.heat_mirror_ring[j][r], 240));
				leds.strip[ringArray[j][r]] = color;
				leds.strip[ringArray[STRIP_LENGTH - 1 - ][r]] = color;
			}
		}
		else {
			for (int j = 0; j < STRIP_LENGTH / 2; j++) {
				CRGB color = ColorFromPalette(leds.current_palette, scale8(leds.heat_mirror_ring[j][r], 240));
				leds.strip[ringArray[(STRIP_LENGTH / 2) - 1 - j][r]] = color;
				leds.strip[ringArray[(STRIP_LENGTH / 2) + j][r]] = color;
			}
		}
	}
}



#endif