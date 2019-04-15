#ifndef RINGS_H
#define RINGS_H

void ringCHSV(LEDStruct& leds, uint8_t pos, uint8_t hue, uint8_t sat, uint8_t bri) {
	for (byte j = 0; j < 4; j++) {
		leds.strip[ringArray[pos][j]] = CHSV(hue, sat, bri);
	}
}

void ringCHSVAdd(LEDStruct& leds, uint8_t pos, uint8_t hue, uint8_t sat, uint8_t bri) {
	for (byte j = 0; j < 4; j++) {
		leds.strip[ringArray[pos][j]] += CHSV(hue, sat, bri);
	}
}

void ringCRGB(LEDStruct& leds, uint8_t pos, uint8_t r, uint8_t g, uint8_t b) {
	for (byte j = 0; j < 4; j++) {
		leds.strip[ringArray[pos][j]] = CRGB(r, g, b);
	}
}

void ringCRGBAdd(LEDStruct& leds, uint8_t pos, uint8_t r, uint8_t g, uint8_t b) {
	for (byte j = 0; j < 4; j++) {
		leds.strip[ringArray[pos][j]] += CRGB(r, g, b);
	}
}

void ringPalette(LEDStruct& leds, uint8_t pos, CRGBPalette16 pal, uint8_t index, uint8_t bri, TBlendType blending) {
	for (byte j = 0; j < 4; j++) {
		leds.strip[ringArray[pos][j]] = ColorFromPalette(pal, index, bri, blending);
	}
}

void ringPaletteAdd(LEDStruct& leds, uint8_t pos, CRGBPalette16 pal, uint8_t index, uint8_t bri, TBlendType blending) {
	for (byte j = 0; j < 4; j++) {
		leds.strip[ringArray[pos][j]] += ColorFromPalette(pal, index, bri, blending);
	}
}

void ring_nblend(LEDStruct& leds, uint8_t pix, CRGB new_color, fract8 blend_amount) {
	for (byte j = 0; j < 4; j++) {
		nblend(leds.strip[ringArray[pix][j]], new_color, blend_amount);
	}
}

void ring_fill_palette(LEDStruct& leds, uint8_t startIndex, uint8_t incIndex, CRGBPalette16 pal, uint8_t bri, TBlendType blending) {
	uint8_t colorIndex = startIndex;
	for (uint8_t i = 0; i < STRIP_LENGTH; i++) {
		ringPalette(leds, i, pal, colorIndex, bri, blending);
		colorIndex += incIndex;
	}
}

void ring_fill_rainbow(LEDStruct& leds, uint8_t initialhue, uint8_t deltahue) {
	byte hsv_hue;
	hsv_hue = initialhue;
	for (int i = 0; i < STRIP_LENGTH; i++) {
		ringCHSV(leds, i, hsv_hue, 255, 255);
		hsv_hue += deltahue;
	}
}


#endif