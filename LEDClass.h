#ifndef LEDCLASS_H
#define LEDCLASS_H

class LEDClass {
  public:
  	struct CRGB strip;
  	uint8_t start_index;
  	uint8_t this_inc;
  	uint8_t this_index;
  	uint8_t this_dir;
  	int this_phase;
  	uint8_t this_speed;
  	uint8_t this_bright;
  	uint8_t this_rot;
  	uint8_t all_freq;
  	uint8_t this_delay;
  	uint8_t this_cutoff;
  	CRGBPalette16 current_palette;
  	CRGBPalette16 target_palette;
  	TBlendType current_blending;
  	uint8_t = led_mode;
}

#endif
