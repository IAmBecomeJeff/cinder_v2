#ifndef PLASMA_H
#define PLASMA_H

//	plasma()
//
//	Variables:
//		leds.current_palette
//		leds.current_blending
//		Manually edit plasma_phases?


void plasma(LEDStruct& leds) {
	leds.plasma_phase1 = beatsin8(5, -64, 64);
	leds.plasma_phase2 = beatsin8(7, -64, 64);
	for (uint8_t k = 0; k < STRIP_LENGTH; k++) {
		leds.plasma_index = cubicwave8((k * 23) + leds.plasma_phase1) / 2 + cos8((k * 15) + leds.plasma_phase2) / 2;
		leds.plasma_bright = qsuba(leds.plasma_index, beatsin8(7, 0, 96));
		ringPalette(leds, k, leds.current_palette, leds.plasma_index, leds.plasma_bright, leds.current_blending);
	}
}

#endif