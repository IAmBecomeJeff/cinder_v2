#ifndef CIRCNOISE_H
#define CIRCNOISE_H

//	circnoise_1()
//	circnoise_1_ring()
//	circnoise_2()
//	circnoise_2_ring()
//	circnoise_3()
//	circnoise_3_ring()
//	circnosie_4()
//	circnoise_4_ring()
//
//	Variables to set:
//		leds.circ_scale
//		leds.current_palette
//		leds.current_blending
//	
//	Experiment with changes in real_x,y,z and shift_x,y

void circnoise_1(LEDStruct& leds) {
	for (uint16_t i = 0; i < NUM_LEDS ; i++) {
		uint16_t shift_x = beatsin8(17);							// the x position of the noise field swings @ 17 bpm
		uint16_t shift_y = millis() / 100;							// the y position becomes slowly incremented
		uint32_t real_x = (xd[i] + shift_x) * leds.circ_scale;      // calculate the coordinates within the noise field
		uint32_t real_y = (yd[i] + shift_y) * leds.circ_scale;      // based on the precalculated positions
		uint8_t noise = inoise16(real_x, real_y, 4223) >> 8;        // get the noise data and scale it down
		uint8_t index = noise * 3;									// map led color based on noise data
		uint8_t bri = noise;
		leds.strip[i] = ColorFromPalette(leds.current_palette, index, bri, leds.current_blending);
	}
}

void circnoise_1_ring(LEDStruct& leds) {
	for (uint8_t i = 0; i < STRIP_LENGTH; i++) {
		uint16_t shift_x = beatsin8(17);							// the x position of the noise field swings @ 17 bpm
		uint16_t shift_y = millis() / 100;							// the y position becomes slowly incremented
		uint32_t real_x = (xd[i] + shift_x) * leds.circ_scale;      // calculate the coordinates within the noise field
		uint32_t real_y = (yd[i] + shift_y) * leds.circ_scale;      // based on the precalculated positions
		uint8_t noise = inoise16(real_x, real_y, 4223) >> 8;        // get the noise data and scale it down
		uint8_t index = noise * 3;									// map led color based on noise data
		uint8_t bri = noise;
		ringPalette(leds, i, leds.current_palette, index, bri, leds.current_blending);
	}
}

void circnoise_2(LEDStruct& leds) {
	for (uint16_t i = 0; i < NUM_LEDS; i++) {
		uint16_t shift_x = millis() / 10;							// the x position of the noise field swings @ 17 bpm
		uint16_t shift_y = 0;						// the y position becomes slowly incremented
		uint32_t real_x = (xd[i] + shift_x) * leds.circ_scale;      // calculate the coordinates within the noise field
		uint32_t real_y = (yd[i] + shift_y) * leds.circ_scale;      // based on the precalculated positions
		uint8_t noise = inoise16(real_x, real_y, 4223) >> 8;        // get the noise data and scale it down
		uint8_t index = noise * 3;									// map led color based on noise data
		uint8_t bri = noise;
		leds.strip[i] = ColorFromPalette(leds.current_palette, index, bri, leds.current_blending);
	}
}

void circnoise_2_ring(LEDStruct& leds) {
	for (uint8_t i = 0; i < STRIP_LENGTH; i++) {
		uint16_t shift_x = millis() / 10;							// x as a function of time
		uint16_t shift_y = 0;
		uint32_t real_x = (xd[i] + shift_x) * leds.circ_scale;      // calculate the coordinates within the noise field
		uint32_t real_y = (yd[i] + shift_y) * leds.circ_scale;      // based on the precalculated positions
		uint8_t noise = inoise16(real_x, real_y, 4223) >> 8;        // get the noise data and scale it down
		uint8_t index = noise * 3;									// map led color based on noise data
		uint8_t bri = noise;
		ringPalette(leds, i, leds.current_palette, index, bri, leds.current_blending);				
																	// With that value, look up the 8 bit colour palette value and assign it to the current LED.
	}
}

void circnoise_3(LEDStruct& leds) {
	for (uint16_t i = 0; i < NUM_LEDS; i++) {
		uint16_t shift_x = 0;							// the x position of the noise field swings @ 17 bpm
		uint16_t shift_y = 0;							// the y position becomes slowly incremented
		uint32_t real_x = (xd[i] + shift_x) * leds.circ_scale;      // calculate the coordinates within the noise field
		uint32_t real_y = (yd[i] + shift_y) * leds.circ_scale;      // based on the precalculated positions
		uint32_t real_z = millis() * 20;							 // increment z linear
		uint8_t noise = inoise16(real_x, real_y, real_z) >> 8;        // get the noise data and scale it down
		uint8_t index = noise * 3;									// map led color based on noise data
		uint8_t bri = noise;
		leds.strip[i] = ColorFromPalette(leds.current_palette, index, bri, leds.current_blending);
	}
}

void circnoise_3_ring(LEDStruct& leds) {
	for (uint16_t i = 0; i < STRIP_LENGTH; i++) {
		uint16_t shift_x = 0;										 // no movement along x and y
		uint16_t shift_y = 0;
		uint32_t real_x = (xd[i] + shift_x) * leds.circ_scale;       // calculate the coordinates within the noise field
		uint32_t real_y = (yd[i] + shift_y) * leds.circ_scale;       // based on the precalculated positions
		uint32_t real_z = millis() * 20;							 // increment z linear
		uint8_t noise = inoise16(real_x, real_y, real_z) >> 8;       // get the noise data and scale it down
		uint8_t index = noise * 3;									 // map led color based on noise data
		uint8_t bri = noise;
		ringPalette(leds, i, leds.current_palette, index, bri, leds.current_blending);
		// With that value, look up the 8 bit colour palette value and assign it to the current LED.
	}
}

void circnoise_4(LEDStruct& leds) {
	for (uint16_t i = 0; i < NUM_LEDS; i++) {
		uint16_t shift_x = beatsin8(15);							// the x position of the noise field swings @ 17 bpm
		uint16_t shift_y = beatsin8(17);							// the y position becomes slowly incremented
		uint32_t real_z = millis() / 11;												// z is also a function of time
		uint32_t real_x = (cos8(i) + beatsin8(5, 0, 32) + shift_x) * leds.circ_scale;      // calculate the coordinates within the noise field
		uint32_t real_y = (sin8(i) + beatsin8(3, 0, 32) + shift_y) * leds.circ_scale;      // based on the precalculated positions
		uint8_t noise = inoise16(real_x, real_y, real_z) >> 8;        // get the noise data and scale it down
		uint8_t index = noise * 3;									// map led color based on noise data
		uint8_t bri = noise;
		leds.strip[i] = ColorFromPalette(leds.current_palette, index, bri, leds.current_blending);
	}
}

void circnoise_4_ring(LEDStruct& leds) {
	for (uint16_t i = 0; i < STRIP_LENGTH; i++) {
		uint16_t shift_x = beatsin8(15);												// x as a function of time
		uint16_t shift_y = beatsin8(17);												// y as a function of time
		uint32_t real_z = millis() / 11;												// z is also a function of time
		uint32_t real_x = (cos8(i) + beatsin8(5, 0, 32) + shift_x) * leds.circ_scale;   // calculate the coordinates within the noise field
		uint32_t real_y = (sin8(i) + beatsin8(3, 0, 32) + shift_y) * leds.circ_scale;   // based on the precalculated positions
		uint8_t noise = inoise16(real_x, real_y, real_z) >> 8;							// get the noise data and scale it down
		uint8_t index = noise * 3;														// map led color based on noise data
		uint8_t bri = noise;
		ringPalette(leds, i, leds.current_palette, index, bri, leds.current_blending);
		// With that value, look up the 8 bit colour palette value and assign it to the current LED.
	}
}






#endif