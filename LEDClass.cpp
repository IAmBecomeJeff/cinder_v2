#include "LEDClass.h"

LEDClass::LEDClass(void) {
	start_index = 0;
	this_inc = 4;
	this_index = 0;
	this_dir = 1;
	this_phase = 0;
	this_speed = 4;
	this_bright = 255;
	this_rot = 4;
	all_freq = 16;
	this_delay = 10;
	this_cutoff = 128;
	led_mode = 0;
	current_palette = CRGBPalette16(CRGB::Black);
	current_blending = LINEARBLEND;
}