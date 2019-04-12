#define FASTLED_INTERNAL

#define DATA_PIN 7
#define CLOCK_PIN 14

#define COLOR_ORDER BGR
#define LED_TYPE APA102

#define NUM_LEDS 576

#define qsubd(x, b) ((x>b)?wave_brightness:0)
uint8_t max_bright = 255;
uint8_t the_delay = 10;
uint8_t wave_brightness = 255;
uint8_t old_mode = 1;
uint8_t max_mode = 2;
uint8_t transitioning = 0;
bool transition_wait = 0;
int blending_ratio = 0;
