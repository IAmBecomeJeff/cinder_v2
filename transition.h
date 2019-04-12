#ifndef TRANSITION_H
#define TRANSITION_H

void copy_led_classes(LEDClass a, LEDClass b) {
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
	a.current_palette = b.current_palette;
	a.current_blending = b.current_blending;
	a.target_palette = b.target_palette;
	a.led_mode = b.led_mode;
	for (int i = 0; i < NUM_LEDS; i++) {
		a.strip[i] = b.strip[i];
	}
}


#endif