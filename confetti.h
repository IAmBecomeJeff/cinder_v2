// confetti.h

#ifndef CONFETTI_h
#define CONFETTI_h

//	confetti()
//	confetti_ring()
//
//	Variables:
//		leds.this_fade
//		leds.target_palette
//		leds.this_bright
//		leds.this_diff
//		leds.current_blending
//		leds.this_inc

void confetti(LEDStruct& leds) {                             
	fadeToBlackBy(leds.strip, NUM_LEDS, leds.this_fade);
	uint16_t pos = random16(NUM_LEDS);             
	leds.strip[pos] = ColorFromPalette(leds.current_palette, leds.this_index + random8(leds.this_diff) / 4, leds.this_bright, leds.current_blending);
	leds.this_index += leds.this_inc;
} 


void confetti_ring(LEDStruct& leds) {
	fadeToBlackBy(leds.strip, NUM_LEDS, leds.this_fade);
	uint8_t pos = random8(STRIP_LENGTH);
	ringPalette(leds, pos, leds.current_palette, leds.this_index + random8(leds.this_diff) / 4, leds.this_bright, leds.current_blending);
	leds.this_index += leds.this_inc;
}

#endif

