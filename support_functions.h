#ifndef SUPPORT_FUNCTIONS_H
#define SUPPORT_FUNCTIONS_H


//		Transitioning works as follows:
//
//		updates
//		  ||
//		  \/			
//		new_leds -> actual_leds -> old_leds
//		
//		Begin transition sends updates -> new_leds
//
//		repeat


// *************** Combo Mode Functions ***************

// Check if we're in a combo and update new_leds.combo value if so
void combo_check() {	
	for (int i = 0; i < combo_modes_size; i++) {
		if (new_leds.led_mode == combo_modes[i]) {
			new_leds.combo = 1;
		}
		else { new_leds.combo = 0; }
	}
	combo_num = new_leds.combo + old_leds.combo;
}

// Wipe new variables and copy relevant info, only called during mode-change
void combo_handling() { 
	if (combo_num == 1) { // only new_leds is using a combo mode
		comboA_leds = new_leds;
		comboB_leds = new_leds;
		//copy_led_struct(comboA_leds, new_leds);
		//copy_led_struct(comboB_leds, new_leds);
	}
	if (combo_num == 2) {
		comboC_leds = new_leds;
		comboD_leds = new_leds;
		//copy_led_struct(comboC_leds, new_leds);
		//copy_led_struct(comboD_leds, new_leds);
	}
}

// *************** Rotary Knob Functions ***************

// Increase or decrease LEDStruct's delay based on boolean direction
void delay_change(LEDStruct& leds, bool delay_direction) {
	if (delay_direction) { leds.this_delay++; }
	else { leds.this_delay--; }
	constrain(leds.this_delay, 5, 1000);
}


// Find index of current (target) palette
void updatePaletteIndex(LEDStruct& leds) {
	for (int i = 0; i < palette_count; i++) {
		if (leds.target_palette == palette_array[i]) {
			leds.palette_index = i;
			break;
		}
	}
}


// Increase or decrease LEDSstruct's palette based on boolean direction
void palette_change(LEDStruct& leds, bool direction) {
	updatePaletteIndex(leds);
	if (direction) { leds.palette_index++; }
	else {
		if (leds.palette_index == 0) { leds.palette_index = palette_count - 1; }
		else { leds.palette_index--; }
	}
	if (leds.palette_index > palette_count - 1) { leds.palette_index = 0; }
	leds.target_palette = palette_array[leds.palette_index];
}


// *************** TRANSITION FUNCTIONS ***************
void transition1() {
	//if (transition_wait) {
	blending_ratio += 1;
	//}
	for (int i = 0; i < NUM_LEDS; i++) {
		actual_leds.strip[i] = blend(old_leds.strip[i], new_leds.strip[i], blending_ratio);
	}
	if (blending_ratio >= 255) {
		actual_leds = new_leds; // copy_led_struct(actual_leds, new_leds);
		transitioning = 0;
		blending_ratio = 0;
		fill_solid(old_leds.strip, NUM_LEDS, CRGB(0, 0, 0));
		fill_solid(new_leds.strip, NUM_LEDS, CRGB(0, 0, 0));
	}
	//transition_wait = !transition_wait;
}

void transition2() { // White line drops down
	for (int r = 0; r < 4; r++) {
		for (int i = 0; i < line; i++) {
			actual_leds.strip[ringArray[i][r]] = old_leds.strip[ringArray[i][r]];
		}
		if (line < 143) {
			for (int i = 143; i > line; i--) {
				actual_leds.strip[ringArray[i][r]] = new_leds.strip[ringArray[i][r]];
			}
		}
		for (int i = 1; i < 4; i++) {
			if (line - i >= 0) {
				actual_leds.strip[ringArray[line - i][r]] = nblend(lineColor, old_leds.strip[ringArray[line - i][r]], 32 * i);
			}
			if (line + i <= 143) {
				actual_leds.strip[ringArray[line + i][r]] = nblend(lineColor, new_leds.strip[ringArray[line + i][r]], 32 * i);
			}
		}
		actual_leds.strip[ringArray[line][r]] = lineColor;
	}
	line--;
	if (line == 0) {
		actual_leds = new_leds;
		transitioning = 0;
		fill_solid(old_leds.strip, NUM_LEDS, CRGB(0, 0, 0));
		fill_solid(new_leds.strip, NUM_LEDS, CRGB(0, 0, 0));
		line = 143;
	}
}


void transition3() { // White lines from middle
	for (int r = 0; r < 4; r++){
		for (int i = 0; i < STRIP_LENGTH; i++) {
			if (i < downline ||  i > upline) {
				actual_leds.strip[ringArray[i][r]] = old_leds.strip[ringArray[i][r]];
			}
			if (i > downline && i < upline) {
				actual_leds.strip[ringArray[i][r]] = new_leds.strip[ringArray[i][r]];
			}
		}
		actual_leds.strip[downline] = lineColor;
		actual_leds.strip[upline] = lineColor;
		for (int i = 1; i < 4; i++) {
			if (downline - i >= 0) {
				actual_leds.strip[ringArray[downline - i][r]] = nblend(lineColor, old_leds.strip[ringArray[downline - i][r]], 32 * i);
			}
			actual_leds.strip[ringArray[upline - i][r]] = nblend(lineColor, new_leds.strip[ringArray[upline - i][r]], 32 * i);
			if (upline + i <= 143) {
				actual_leds.strip[ringArray[upline + i][r]] = nblend(lineColor, old_leds.strip[ringArray[upline + i][r]], 32 * i);
			}
			actual_leds.strip[ringArray[downline + i][r]] = nblend(lineColor, new_leds.strip[ringArray[downline + i][r]], 32 * i);
		}
	}
	downline--;
	upline++;
	if (downline == 0) {
		actual_leds = new_leds;
		transitioning = 0;
		fill_solid(old_leds.strip, NUM_LEDS, CRGB(0, 0, 0));
		fill_solid(new_leds.strip, NUM_LEDS, CRGB(0, 0, 0));
		downline = 71;
		upline = 72;
	}
}


void transition4() { // Fade old_leds to random color, and return back to new_leds
	if (get_new_color) {
		transition_color = CHSV(random8(), 255, 255);
		get_new_color = 0;
	}
	if (color_direction) {
		amount_of_color++;
		for (uint16_t i = 0; i < NUM_LEDS; i++) {
			actual_leds.strip[i] = nblend(old_leds.strip[i], transition_color, amount_of_color);
		}
		if (amount_of_color == 255) { color_direction = 0; }
	}
	else {
		amount_of_color--;
		for (uint16_t i = 0; i < NUM_LEDS; i++) {
			actual_leds.strip[i] = nblend(new_leds.strip[i], transition_color, amount_of_color);
		}
		if (amount_of_color == 0) {
			color_direction = 1;
			transitioning = 0;
			get_new_color = 1;
			actual_leds = new_leds;
			fill_solid(old_leds.strip, NUM_LEDS, CRGB(0, 0, 0));
			fill_solid(new_leds.strip, NUM_LEDS, CRGB(0, 0, 0));
		}
	}
}



// *************** Initialization function for setup() ***************
void array_init() {
	// Init ring array
	for (uint8_t i = 0; i < STRIP_LENGTH; i++) {
		ringArray[i][0] = i;
		ringArray[i][1] = 287 - i;
		ringArray[i][2] = 288 + i;
		ringArray[i][3] = 575 - i;
	}

	// Set up circnoise variables
	for (long i = 0; i < NUM_LEDS; i++) {
		uint8_t angle = (i * 256) / NUM_LEDS;
		xd[i] = cos8(angle);
		yd[i] = sin8(angle);
	}

	// Init Spiral Arrays
	for (uint8_t i = 0; i < STRIP_LENGTH; i += 4 * w) {
		for (uint8_t j = 0; j < w; j++) {
			spiralArray[0][i + j] = i + j;
			spiralArray[0][i + j + w] = 287 - w - i - j;
			spiralArray[0][i + j + 2 * w] = 288 + 2 * w + i + j;
			spiralArray[0][i + j + 3 * w] = 575 - 3 * w - i - j;
			spiralArray[1][i + j] = 287 - i - j;
			spiralArray[1][i + j + w] = 288 + w + i + j;
			spiralArray[1][i + j + 2 * w] = 575 - 2 * w - i - j;
			spiralArray[1][i + j + 3 * w] = 3 * w + i + j;
			spiralArray[2][i + j] = 288 + i + j;
			spiralArray[2][i + j + w] = 575 - w - i - j;
			spiralArray[2][i + j + 2 * w] = 2 * w + i + j;
			spiralArray[2][i + j + 3 * w] = 287 - 3 * w - i - j;
			spiralArray[3][i + j] = 575 - i - j;
			spiralArray[3][i + j + w] = w + i + j;
			spiralArray[3][i + j + 2 * w] = 287 - 2 * w - i - j;
			spiralArray[3][i + j + 3 * w] = 288 + 3 * w + i + j;
		}
	}

	for (int i = 0; i < STRIP_LENGTH; i += 4 * w) {
		for (int j = 0; j < w; j++) {
			spiralArrayRev[0][i + j] = i + j;
			spiralArrayRev[0][i + j + w] = 575 - w - i - j;
			spiralArrayRev[0][i + j + 2 * w] = 288 + 2 * w + i + j;
			spiralArrayRev[0][i + j + 3 * w] = 287 - 3 * w - i - j;

			spiralArrayRev[1][i + j] = 287 - i - j;
			spiralArrayRev[1][i + j + w] = w + i + j;
			spiralArrayRev[1][i + j + 2 * w] = 575 - 2 * w - i - j;
			spiralArrayRev[1][i + j + 3 * w] = 288 + 3 * w + i + j;

			spiralArrayRev[2][i + j] = 288 + i + j;
			spiralArrayRev[2][i + j + w] = 287 - w - i - j;
			spiralArrayRev[2][i + j + 2 * w] = 2 * w + i + j;
			spiralArrayRev[2][i + j + 3 * w] = 575 - 3 * w - i - j;

			spiralArrayRev[3][i + j] = 575 - i - j;
			spiralArrayRev[3][i + j + w] = 288 + w + i + j;
			spiralArrayRev[3][i + j + 2 * w] = 287 - 2 * w - i - j;
			spiralArrayRev[3][i + j + 3 * w] = 3 * w + i + j;
		}
	}
}



#endif