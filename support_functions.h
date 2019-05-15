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

// Increase or decrease LEDStruct's delay based on boolean direction
void delay_change(LEDStruct& leds, bool delay_direction) {
	if (delay_direction) {
		leds.this_delay++;
	}
	else {
		if (leds.this_delay == 1) { leds.this_delay = 1; }
		else { leds.this_delay--; }
	}
	constrain(leds.this_delay, 1, 1000);
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

void transition2() {
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


void transition3() {
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


//// May not need this, if structA = structB works:
//void copy_led_struct(LEDStruct& a, LEDStruct& b) {
//	a.start_index = b.start_index;
//	a.this_inc = b.this_inc;
//	a.this_index = b.this_index;
//	a.this_dir = b.this_dir;
//	a.this_phase = b.this_phase;
//	a.this_speed = b.this_speed;
//	a.this_bright = b.this_bright;
//	a.this_rot = b.this_rot;
//	a.all_freq = b.all_freq;
//	a.this_delay = b.this_delay;
//	a.this_cutoff = b.this_cutoff;
//	a.this_fade = b.this_fade;
//	a.this_diff = b.this_diff;
//	a.bg_clr = b.bg_clr;
//	a.bg_bri = b.bg_bri;
//	a.bg_sat = b.bg_sat;
//	a.that_phase = b.that_phase;
//	a.that_speed = b.that_speed;
//	a.that_hue = b.that_hue;
//	a.that_rot = b.that_rot;
//	a.this_hue = b.this_hue;
//	a.this_sat = b.this_sat;
//	a.that_sat = b.that_sat;
//	a.current_palette = b.current_palette;
//	a.current_blending = b.current_blending;
//	a.target_palette = b.target_palette;
//	a.palette_index = b.palette_index;
//	a.led_mode = b.led_mode;
//	for (int i = 0; i < NUM_LEDS; i++) {
//		a.strip[i] = b.strip[i];
//	}
//	a.led_mode = b.led_mode;
//	a.numdots = b.numdots;
//	a.numdots_ring = b.numdots_ring;
//	a.this_beat = b.this_beat;
//	for (int i = 0; i < 4; i++) {
//		a.ringBeat[i] = b.ringBeat[i];
//	}
//	for (int i = 0; i < STRIP_LENGTH; i++) {
//		a.heat[i] = b.heat[i];
//		for (int r = 0; r > 4; r++) {
//			a.heat_ring[i][r] = b.heat_ring[i][r];
//		}
//	}
//	for (int i = 0; i < STRIP_LENGTH / 2; i++) {
//		a.heat_mirror[i] = b.heat_mirror[i];
//		for (int r = 0; r < 4; r++) {
//			a.heat_mirror_ring[i][r] = b.heat_mirror_ring[i][r];
//		}
//	}
//	a.cooling = b.cooling;
//	a.sparking = a.cooling;
//	for (int r = 0; r < 4; r++) {
//		a.cooling_columns[r] = b.cooling_columns[r];
//		a.sparking_columns[r] = b.sparking_columns[r];
//	}
//	a.prev_pos = b.prev_pos;
//	a.combo = b.combo;
//}


#endif