#ifndef RIPPLE_H
#define RIPPLE_H

//	ripple()
//
//	Variables:
//		leds.this_fade
//		leds.target_palette
//		leds.this_bright
//		leds.ripple_fade
//		leds.ripple_step = 0



void ripple(LEDStruct& leds) {
	fadeToBlackBy(leds.strip, NUM_LEDS, leds.this_fade);

	switch (leds.ripple_step) {

		case -10:
			leds.ripple_pause++;
			if (leds.ripple_pause == 0) { leds.ripple_step = -1; leds.ripple_pause = random8(20) - 20; }
			break;

		case -1:
			leds.ripple_center = random(STRIP_LENGTH);
			leds.ripple_index = random8();
			leds.ripple_step = 0;
			break;

		case 0:
			ringPalette(leds, leds.ripple_center, leds.current_palette, leds.ripple_index, leds.this_bright, leds.current_blending);
			leds.ripple_step++;
			break;

		case 16: // change this?
			leds.ripple_step = 10;
			break;

		default:
			ringPaletteAdd(leds, (leds.ripple_center + leds.ripple_step + STRIP_LENGTH) % STRIP_LENGTH, leds.current_palette, leds.ripple_index, leds.ripple_fade / leds.ripple_step * 2, leds.current_blending);
			ringPaletteAdd(leds, (leds.ripple_center - leds.ripple_step + STRIP_LENGTH) % STRIP_LENGTH, leds.current_palette, leds.ripple_index, leds.ripple_fade / leds.ripple_step * 2, leds.current_blending);
			leds.ripple_step++;
			break;
	}
}






#endif