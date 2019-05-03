// Functions:

//				juggle_fire()
//				juggle_onedir_fire()
//				juggle_columns_fire()
//				juggle_columns_onedir_fire()

//				juggle_fire_pal()
//				juggle_onedir_fire_pal()
//				juggle_columns_fire_pal()
//				juggle_columns_onedir_fire_pal()

//				juggle_fire_mirror()
//				juggle_onedir_fire_mirror()
//				juggle_columns_fire_mirror()
//				juggle_columns_onedir_fire_mirror()

//				juggle_fire_mirror_pal()
//				juggle_onedir_fire_mirror_pal()
//				juggle_columns_fire_mirror_pal()
//				juggle_columns_onedir_fire_mirror_pal()

//				juggle_fire_columns()
//				juggle_onedir_fire_columns()
//				juggle_columns_fire_columns()
//				juggle_columns_onedir_fire_columns()

//				juggle_fire_columns_pal()
//				juggle_onedir_fire_columns_pal()
//				juggle_columns_fire_columns_pal()
//				juggle_columns_onedir_fire_columns_pal()

//				juggle_fire_mirror_columns()
//				juggle_onedir_fire_mirror_columns()
//				juggle_columns_fire_mirror_columns()
//				juggle_columns_onedir_fire_mirror_columns()

//				juggle_fire_mirror_columns_pal()
//				juggle_onedir_fire_mirror_columns_pal()
//				juggle_columns_fire_mirror_columns_pal()
//				juggle_columns_onedir_fire_mirror_columns_pal()

// Variables:
//	ComboA / ComboC:
//				this_index		(auto set to 0, maybe change?)
//				this_fade 
//				numdots_ring
//				this_beat
//				current_palette
//				this_bright
//				current_blending
//				this_diff
//				ringBeat[]		(only used in columns modes)
//				gHue			(auto set; only used in sinelon modes)
//	ComboB / ComboD:
//				cooling
//				sparking
//				current_palete			(only used in pal modes)
//				this_bright				(only used in pal modes)
//				current_blending		(only used in pal modes)
//				cooling_columns[]		(only used in columns modes)
//				sparking_columns[]		(only used in columns modes)

// Currently, combo structs get the palette that new_leds is set with, and does not change.  If (new_leds.combo), updates should go to juggle combo struct pal.  Probably disable fire_pal modes.


// *******juggle with fire()********
void juggle_fire(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_ring(comboC_leds);
		fire(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_ring(comboA_leds);
		fire(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
} //juggle_fire(leds)


void juggle_onedir_fire(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_ring_onedir(comboC_leds);
		fire(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_ring_onedir(comboA_leds);
		fire(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}//juggle_onedir_fire(leds)


void juggle_columns_fire(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_columns_all(comboC_leds);
		fire(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_columns_all(comboA_leds);
		fire(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}//juggle_columns_fire(leds)


void juggle_columns_onedir_fire(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_columns_onedir_all(comboC_leds);
		fire(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_columns_onedir_all(comboA_leds);
		fire(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}//juggle_columns_onedir_fire(leds)


// *******juggle with fire_pal()********
void juggle_fire_pal(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_ring(comboC_leds);
		fire_pal(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_ring(comboA_leds);
		fire_pal(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}//juggle_fire_pal(leds)


void juggle_onedir_fire_pal(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_ring_onedir(comboC_leds);
		fire_pal(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_ring_onedir(comboA_leds);
		fire_pal(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}//juggle_onedir_fire_pal(leds)


void juggle_columns_fire_pal(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_columns_all(comboC_leds);
		fire_pal(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_columns_all(comboA_leds);
		fire_pal(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}//juggle_columns_fire_pal(leds)


void juggle_columns_onedir_fire_pal(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_columns_onedir_all(comboC_leds);
		fire_pal(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_columns_onedir_all(comboA_leds);
		fire_pal(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}//juggle_columns_onedir_fire_pal(leds)


// *******juggle with fire_mirror()********
void juggle_fire_mirror(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_ring(comboC_leds);
		fire_mirror(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_ring(comboA_leds);
		fire_mirror(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}


void juggle_onedir_fire_mirror(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_ring_onedir(comboC_leds);
		fire_mirror(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_ring_onedir(comboA_leds);
		fire_mirror(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}


void juggle_columns_fire_mirror(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_columns_all(comboC_leds);
		fire_mirror(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_columns_all(comboA_leds);
		fire_mirror(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}


void juggle_columns_onedir_fire_mirror(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_columns_onedir_all(comboC_leds);
		fire_mirror(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_columns_onedir_all(comboA_leds);
		fire_mirror(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}


// *******juggle with fire_mirror_pal()********
void juggle_fire_mirror_pal(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_ring(comboC_leds);
		fire_mirror_pal(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_ring(comboA_leds);
		fire_mirror_pal(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}


void juggle_onedir_fire_mirror_pal(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_ring_onedir(comboC_leds);
		fire_mirror_pal(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_ring_onedir(comboA_leds);
		fire_mirror_pal(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}


void juggle_columns_fire_mirror_pal(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_columns_all(comboC_leds);
		fire_mirror_pal(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_columns_all(comboA_leds);
		fire_mirror_pal(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}


void juggle_columns_onedir_fire_mirror_pal(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_columns_onedir_all(comboC_leds);
		fire_mirror_pal(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_columns_onedir_all(comboA_leds);
		fire_mirror_pal(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}


// *******juggle with fire_columns()********
void juggle_fire_columns(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_ring(comboC_leds);
		fire_columns(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_ring(comboA_leds);
		fire_columns(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}


void juggle_onedir_fire_columns(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_ring_onedir(comboC_leds);
		fire_columns(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_ring_onedir(comboA_leds);
		fire_columns(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}


void juggle_columns_fire_columns(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_columns_all(comboC_leds);
		fire_columns(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_columns_all(comboA_leds);
		fire_columns(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}


void juggle_columns_onedir_fire_columns(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_columns_onedir_all(comboC_leds);
		fire_columns(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_columns_onedir_all(comboA_leds);
		fire_columns(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}

// *******juggle with fire_columns_pal()********
void juggle_fire_columns_pal(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_ring(comboC_leds);
		fire_columns_pal(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_ring(comboA_leds);
		fire_columns_pal(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}


void juggle_onedir_fire_columns_pal(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_ring_onedir(comboC_leds);
		fire_columns_pal(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_ring_onedir(comboA_leds);
		fire_columns_pal(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}


void juggle_columns_fire_columns_pal(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_columns_all(comboC_leds);
		fire_columns_pal(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_columns_all(comboA_leds);
		fire_columns_pal(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}


void juggle_columns_onedir_fire_columns_pal(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_columns_onedir_all(comboC_leds);
		fire_columns_pal(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_columns_onedir_all(comboA_leds);
		fire_columns_pal(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}


// *******juggle with fire_mirror_columns()********
void juggle_fire_mirror_columns(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_ring(comboC_leds);
		fire_mirror_columns(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_ring(comboA_leds);
		fire_mirror_columns(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}


void juggle_onedir_fire_mirror_columns(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_ring_onedir(comboC_leds);
		fire_mirror_columns(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_ring_onedir(comboA_leds);
		fire_mirror_columns(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}


void juggle_columns_fire_mirror_columns(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_columns_all(comboC_leds);
		fire_mirror_columns(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_columns_all(comboA_leds);
		fire_mirror_columns(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}


void juggle_columns_onedir_fire_mirror_columns(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_columns_onedir_all(comboC_leds);
		fire_mirror_columns(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_columns_onedir_all(comboA_leds);
		fire_mirror_columns(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}


// *******juggle with fire_mirror_columns_pal()********
void juggle_fire_mirror_columns_pal(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_ring(comboC_leds);
		fire_mirror_columns_pal(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_ring(comboA_leds);
		fire_mirror_columns_pal(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}


void juggle_onedir_fire_mirror_columns_pal(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_ring_onedir(comboC_leds);
		fire_mirror_columns_pal(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_ring_onedir(comboA_leds);
		fire_mirror_columns_pal(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}


void juggle_columns_fire_mirror_columns_pal(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_columns_all(comboC_leds);
		fire_mirror_columns_pal(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_columns_all(comboA_leds);
		fire_mirror_columns_pal(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}


void juggle_columns_onedir_fire_mirror_columns_pal(LEDStruct& leds) {
	if (leds.isNew && combo_num == 2) {
		juggle_columns_onedir_all(comboC_leds);
		fire_mirror_columns_pal(comboD_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboC_leds.strip[i] + comboD_leds.strip[i];
		}
	}
	else {
		juggle_columns_onedir_all(comboA_leds);
		fire_mirror_columns_pal(comboB_leds);
		for (int i = 0; i < NUM_LEDS; i++) {
			leds.strip[i] = comboA_leds.strip[i] + comboB_leds.strip[i];
		}
	}
}