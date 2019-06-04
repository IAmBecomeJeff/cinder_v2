#ifndef RAINBOW_WAVES_H
#define RAINBOW_WAVES_H

void rainbow_wave(LEDStruct& leds) {
	leds[0].b = beatsin8(100);
	leds[0].g = beatsin8(75);
	leds[0].r = beatsin8(66);
	memmove(leds.strip + 1, leds.strip, (NUM_LEDS - 1) * 3);
}

void rainbow_wave_moving_dot(LEDStruct& leds) {
	if (leds.lead_led > 30) {
		for (int i = 0; i < leds.num_sparks; i++) {
			leds.strip[leds.lead_led - random8(5)] = CRGB::White;
		}
	}
	leds.strip[leds.lead_led].b = beatsin8(100, 50, 255);
	leds.strip[leds.lead_led].g = beatsin8(78, 0, 255);
	leds.strip[leds.lead_led].r = beatsin8(66, 0, 160);
	fadeToBlackBy(leds.strip, NUM_LEDS, spark_fade);
	if (leds.lead_led++ >= NUM_LEDS) { leds.lead_led = 0; }
}



#endif
