#define FASTLED_INTERNAL

#define DATA_PIN 7
#define CLOCK_PIN 14

#define switchA 3
#define switchB 4

#define COLOR_ORDER BGR
#define LED_TYPE APA102

#define NUM_LEDS 576
#define STRIP_LENGTH 144

#define qsubd(x, b) ((x>b)?wave_brightness:0)
#define qsuba(x, b) ((x>b)?x-b:0)
uint8_t max_bright = 255;
//uint8_t the_delay = 10;
uint8_t wave_brightness = 255;
uint8_t old_mode = 0;
uint8_t max_mode = 3;
uint8_t transitioning = 0;
bool transition_wait = 0;
int blending_ratio = 0;
int ringArray[144][4];
uint8_t gHue = 0;
int combo_modes[3] = { 10, 11, 12 }; // led_modes that use a combo LEDStruct
int combo_modes_size = sizeof(combo_modes) / sizeof(int);
uint8_t combo_num = 0;
uint8_t overall_bright = 128;
uint8_t line = 143;
uint8_t downline = 71;
uint8_t upline = 72;
CRGB lineColor (CRGB::White);
uint8_t max_transitions = 3;
uint8_t xd[NUM_LEDS];
uint8_t yd[NUM_LEDS];


// KY-040 Rotary Module variables
int pinA = 21;
int pinB = 22;
int pinSW = 23;
int lastPinSWstate = 1;
int pinSWstate;
int pinALast;
int aVal;
int rotateCount = 0;
int rotary_function = 0;
int palette_index;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

Bounce debouncer = Bounce();
