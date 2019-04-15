#ifndef JUGGLE_H
#define JUGGLE_H

void juggle_pal_ring(LEDStruct& leds) {
	leds.this_index = 0;
	fadeToBlackBy(leds.strip, NUM_LEDS, leds.this_fade);
	for (uint8_t i = 0; i < leds.numdots_ring; i++) {
		ringPaletteAdd(leds, beatsin16(leds.this_beat + i + leds.numdots_ring, 0, STRIP_LENGTH - 1), leds.current_palette, leds.this_index, leds.this_bright, leds.current_blending);
		leds.this_index += leds.this_diff;
	}
}

void juggle_pal_ring_onedir(LEDStruct& leds) {
	leds.this_index = 0;
	fadeToBlackBy(leds.strip, NUM_LEDS, leds.this_fade);
	for (uint8_t i = 0; i < leds.numdots_ring; i++) {
		if (!leds.this_dir) {
			ringPaletteAdd(leds, beatsin16_halfdown(leds.this_beat + 2 * i + leds.numdots_ring, 0, STRIP_LENGTH - 1), leds.current_palette, leds.this_index, leds.this_bright, leds.current_blending);
		}
		else {
			ringPaletteAdd(leds, beatsin16_halfup(leds.this_beat + 2 * i + leds.numdots_ring, 0, STRIP_LENGTH - 1), leds.current_palette, leds.this_index, leds.this_bright, leds.current_blending);
		}
		leds.this_index += leds.this_diff;
	}
}

void juggle_pal_individual_ring(LEDStruct& leds, uint8_t ring) {
	leds.this_index = 0;
	fadeToBlackBy(leds.strip, NUM_LEDS, leds.this_fade);
	for (uint8_t i = 0; i < leds.numdots; i++) {
		leds.strip[ringArray[beatsin16(leds.ringBeat[ring] + i + leds.numdots, 0, STRIP_LENGTH - 1)][ring]] += ColorFromPalette(leds.current_palette, leds.this_index, leds.this_bright, leds.current_blending);
		leds.this_index += leds.this_diff;
	}
}

void juggle_pal_individual_ring_all(LEDStruct& leds) {
	juggle_pal_individual_ring(leds, 0);
	juggle_pal_individual_ring(leds, 1);
	juggle_pal_individual_ring(leds, 2);
	juggle_pal_individual_ring(leds, 3);
}

void juggle_pal_individual_ring_onedir(LEDStruct& leds, uint8_t ring) {
	leds.this_index = 0;
	fadeToBlackBy(leds.strip, NUM_LEDS, leds.this_fade);
	for (uint8_t i = 0; i < leds.numdots; i++) {
		if (leds.this_dir) {
			leds.strip[ringArray[beatsin16_halfdown(leds.ringBeat[ring] + i + leds.numdots, 0, STRIP_LENGTH - 1)][ring]] += ColorFromPalette(leds.current_palette, leds.this_index, leds.this_bright, leds.current_blending);
			leds.this_index += leds.this_diff;
		}
		else {
			leds.strip[ringArray[beatsin16_halfup(leds.ringBeat[ring] + i + leds.numdots, 0, STRIP_LENGTH - 1)][ring]] += ColorFromPalette(leds.current_palette, leds.this_index, leds.this_bright, leds.current_blending);
			leds.this_index += leds.this_diff;
		}
	}
}

void juggle_pal_individual_ring_onedir_all(LEDStruct& leds) {
	juggle_pal_individual_ring_onedir(leds, 0);
	juggle_pal_individual_ring_onedir(leds, 1);
	juggle_pal_individual_ring_onedir(leds, 2);
	juggle_pal_individual_ring_onedir(leds, 3);
}



#endif