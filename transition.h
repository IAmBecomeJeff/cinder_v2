#ifndef TRANSITION_H
#define TRANSITION_H

void copy_led_classes(LEDStruct& a, LEDStruct& b) {
	a.start_index = b.start_index;
	a.this_inc = b.this_inc;
	a.this_index = b.this_index;
	a.this_dir = b.this_dir;
	a.this_phase = b.this_phase;
	a.this_speed = b.this_speed;
	a.this_bright = b.this_bright;
	a.this_rot = b.this_rot;
	a.all_freq = b.all_freq;
	a.this_delay = b.this_delay;
	a.this_cutoff = b.this_cutoff;
	a.this_fade = b.this_fade;
	a.this_diff = b.this_diff;
	a.bg_clr = b.bg_clr;
	a.bg_bri = b.bg_bri;
	a.bg_sat = b.bg_sat;
	a.that_phase = that_phase;
	a.that_speed = b.that_speed;
	a.that_hue = b.that_hue;
	a.that_rot = b.that_rot;
	a.this_hue = b.this_hue;
	a.this_sat = b.this_sat;
	a.that_sat = b.that_sat;
	a.current_palette = b.current_palette;
	a.current_blending = b.current_blending;
	a.target_palette = b.target_palette;
	a.led_mode = b.led_mode;
	for (int i = 0; i < NUM_LEDS; i++) {
		a.strip[i] = b.strip[i];
	}
	a.led_mode = b.led_mode;
	a.numdots = b.numdots;
	a.numdots_ring = b.numdots_ring;
	a.this_beat = b.this_beat; // ringBeat is defined in LEDStruct
	a.heat = b.heat;
	a.heat_ring = b.heat_ring;
	a.heat_mirror = b.heat_mirror;
	a.heat_mirror_ring = b.heat_mirror_ring;
	a.cooling = b.cooling;
	a.sparking = a.cooling;
	a.cooling_ring = b.cooling_ring;
	a.sparking_ring = b.sparking_ring;
}


#endif
