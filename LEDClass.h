#ifndef LEDCLASS_H
#define LEDCLASS_H

class LEDClass {
  public:
  	struct CRGB strip[NUM_LEDS];
  	uint8_t start_index = 0;
  	uint8_t this_inc = 1;
  	uint8_t this_index = 0;
  	uint8_t this_dir = 1;
  	int this_phase = 0;
  	uint8_t this_speed = 4;
  	uint8_t this_bright = 255;
  	uint8_t this_rot = 2;
  	uint8_t all_freq = 4;
  	uint8_t this_delay = 10;
  	uint8_t this_cutoff = 128;
  	CRGBPalette16 current_palette = CRGBPalette16(CRGB::Black);
  	CRGBPalette16 target_palette;
  	TBlendType current_blending = LINEARBLEND;
  	uint8_t led_mode = 0;
};


#endif
