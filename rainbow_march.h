#ifndef RAINBOWMARCH_H
#define RAINBOWMARCH_H

//
//	rainbow_march()
//	rainbow_march_ring()
//
//	Variables:
//		leds.this_rot
//		leds.this_diff
//		leds.this_index = 0

void rainbow_march(LEDStruct& leds) {
	if (leds.this_dir == 0) leds.this_index += leds.this_rot; else leds.this_index -= leds.this_rot;
	fill_rainbow(leds.strip, NUM_LEDS, leds.this_index, leds.this_diff);
}

void rainbow_march_ring(LEDStruct& leds) {
	if (leds.this_dir == 0) leds.this_index += leds.this_rot; else leds.this_index -= leds.this_rot;
	ring_fill_rainbow(leds, leds.this_index, leds.this_diff);
}




#endif