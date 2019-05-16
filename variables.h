#define FASTLED_INTERNAL

#define DATA_PIN 7
#define CLOCK_PIN 14

#define switchA 3
#define switchB 4

#define COLOR_ORDER BGR
#define LED_TYPE APA102

#define NUM_LEDS 576
#define STRIP_LENGTH 144

// Brightness variables. 
uint8_t max_bright = 255;
uint8_t wave_brightness = 255;
uint8_t overall_bright = max_bright;

#define qsubd(x, b) ((x>b)?wave_brightness:0)
#define qsuba(x, b) ((x>b)?x-b:0)

bool glitter;

// Indexing arrays
uint8_t ringArray[144][4];
uint8_t spiralArray[4][144];		  
uint8_t spiralArrayRev[4][144];
uint8_t xd[NUM_LEDS];
uint8_t yd[NUM_LEDS];
uint8_t w = 3; // spiral array width


// Transition and mode variables
uint8_t old_mode = 0;
uint8_t max_mode = 3;
uint8_t transitioning = 0;
bool transition_wait = 0;
uint8_t blending_ratio = 0;
uint8_t combo_modes[3] = { 10, 11, 12 }; // led_modes that use a combo LEDStruct
uint8_t combo_modes_size = sizeof(combo_modes) / sizeof(uint8_t);
uint8_t combo_num = 0;
uint8_t line = 143;
uint8_t downline = 71;
uint8_t upline = 72;
CRGB lineColor(CRGB::White);
CHSV transition_color(CHSV(0, 255, 255));
uint8_t amount_of_color = 0;
bool color_direction = 1;
bool get_new_color = 1;
max_transitions = 4;



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


// Serial variables (remove after testing)
byte in_byte;
int this_arg;
#define SERIAL_BAUDRATE 57600
#define SERIAL_TIMEOUT 500