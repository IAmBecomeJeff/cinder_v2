struct LEDStruct {
	// ***** COMMON Variables *****
  	struct CRGB strip[NUM_LEDS];
	CRGBPalette16 current_palette = CRGBPalette16(CRGB::Black);
	CRGBPalette16 target_palette;
	TBlendType current_blending = LINEARBLEND;
	uint8_t palette_index = 0;
	uint8_t led_mode = 0;
	uint8_t this_dir = 1;
	uint8_t this_bright = 255;
	uint16_t this_delay = 10;
	uint8_t this_index = 0;
	uint8_t this_inc = 1;
  	uint8_t start_index = 0;
	uint8_t this_fade = 32;
	bool isNew = 0;
	bool combo = 0;

	// ***** SIN Variables *****
  	uint8_t this_phase = 0;
  	uint8_t this_speed = 1;
  	uint8_t this_rot = 2;
  	uint8_t all_freq = 4;
  	uint8_t this_cutoff = 128;
	uint8_t this_diff = 4;
	uint8_t bg_clr = 0;
	uint8_t bg_bri = 128;
	uint8_t bg_sat = 155;
	uint8_t that_phase = 0;
	uint8_t that_speed = 4;
	uint8_t that_hue = 16;
	uint8_t that_rot = 2;
	uint8_t this_hue = 0;
	uint8_t this_sat = 255;
	uint8_t that_sat = 128;

	// ***** JUGGLE Variables *****
	uint8_t numdots = 4;
	uint8_t numdots_ring = 3;
	uint8_t ringBeat[4] = { 3, 2, 0, 1 };
	uint8_t this_beat = 8;
	int prev_pos = 0; // sinelon_rainbow
	
	// ***** FIRE Variables *****
	uint8_t heat[STRIP_LENGTH];
	uint8_t heat_ring[STRIP_LENGTH][4];
	uint8_t heat_mirror[STRIP_LENGTH / 2];
	uint8_t heat_mirror_ring[STRIP_LENGTH / 2][4];
	uint8_t cooling = 55;
	uint8_t sparking = 100;
	uint8_t cooling_columns[4] = { 55, 30, 70, 60 };
	uint8_t sparking_columns[4] = { 100, 70, 120, 40 };

	// ***** CIRC Variables *****
	uint16_t circ_scale = 1000;
	   
	//Variables for ripple 
	uint8_t ripple_index;
	uint8_t ripple_center = 0;
	int ripple_step = -1;
	int ripple_delay = -10;
	int ripple_pause = -10;
	uint8_t ripple_fade = 255;
	uint8_t ripple_maxSteps = 16;
};

LEDStruct new_leds;
LEDStruct old_leds;
LEDStruct actual_leds;

LEDStruct comboA_leds;
LEDStruct comboB_leds;
LEDStruct comboC_leds;
LEDStruct comboD_leds;