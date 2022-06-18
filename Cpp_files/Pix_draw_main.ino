#define NUM_LEDS 81
#define LED_PIN 13
#define LIMIT 1000
#define POT_PIN 4
#define BUT_PIN 6

#include "FastLED.h"

struct CRGB leds[NUM_LEDS];

unsigned short int LED_COUNT = NUM_LEDS;

byte rec_counter = 0;
bool switcher = 1;
boolean pc = 0 ;
boolean is_c = 0;
boolean z_count = 0;
boolean led_show = 0;

unsigned short int gif_delay = 0.001   * 1000;
String alph_l = "0123456789abcdef";
byte alph_n[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
byte buffer_[NUM_LEDS][4];
//byte buffer_[][4] ={{0, 0, 0, 0}, {1, 0, 0, 0}, {2, 0, 0, 0}, {3, 0, 0, 0}, {4, 0, 0, 0}, {5, 0, 0, 0}, {6, 0, 0, 0}, {7, 0, 0, 0}, {8, 0, 0, 0}, {9, 0, 0, 0}, {10, 0, 0, 0}, {11, 0, 0, 0}, {12, 0, 0, 0}, {13, 0, 0, 0}, {14, 0, 0, 0}, {15, 0, 0, 0}, {16, 0, 0, 0}, {17, 0, 0, 0}, {18, 0, 0, 0}, {19, 0, 0, 0}, {20, 0, 0, 0}, {21, 0, 0, 0}, {22, 0, 0, 0}, {23, 0, 0, 0}, {24, 0, 0, 0}, {25, 0, 0, 0}, {26, 0, 0, 0}, {27, 0, 0, 0}, {28, 0, 0, 0}, {29, 0, 0, 0}, {30, 0, 0, 0}, {31, 0, 0, 0}, {32, 0, 0, 0}, {33, 0, 0, 0}, {34, 0, 0, 0}, {35, 0, 0, 0}, {36, 0, 0, 0}, {37, 0, 0, 0}, {38, 0, 0, 0}, {39, 0, 0, 0}, {40, 0, 0, 0}, {41, 0, 0, 0}, {42, 0, 0, 0}, {43, 0, 0, 0}, {44, 0, 0, 0}, {45, 0, 0, 0}, {46, 0, 0, 0}, {47, 0, 0, 0}, {48, 0, 0, 0}, {49, 0, 0, 0}, {50, 0, 0, 0}, {51, 0, 0, 0}, {52, 0, 0, 0}, {53, 0, 0, 0}, {54, 0, 0, 0}, {55, 0, 0, 0}, {56, 0, 0, 0}, {57, 0, 0, 0}, {58, 0, 0, 0}, {59, 0, 0, 0}, {60, 0, 0, 0}, {61, 0, 0, 0}, {62, 0, 0, 0}, {63, 0, 0, 0}, {64, 0, 0, 0}, {65, 0, 0, 0}, {66, 0, 0, 0}, {67, 0, 0, 0}, {68, 0, 0, 0}, {69, 0, 0, 0}, {70, 0, 0, 0}, {71, 0, 0, 0}, {72, 0, 0, 0}, {73, 0, 0, 0}, {74, 0, 0, 0}, {75, 0, 0, 0}, {76, 0, 0, 0}, {77, 0, 0, 0}, {78, 0, 0, 0}, {79, 0, 0, 0}, {80, 0, 0, 0}};
byte err_b[NUM_LEDS][4];
//byte err_b[][4] = {{0, 0, 0, 0}, {1, 0, 0, 0}, {2, 0, 0, 0}, {3, 0, 0, 0}, {4, 0, 0, 0}, {5, 0, 0, 0}, {6, 0, 0, 0}, {7, 0, 0, 0}, {8, 0, 0, 0}, {9, 0, 0, 0}, {10, 0, 0, 0}, {11, 0, 0, 0}, {12, 0, 0, 0}, {13, 0, 0, 0}, {14, 0, 0, 0}, {15, 0, 0, 0}, {16, 0, 0, 0}, {17, 0, 0, 0}, {18, 0, 0, 0}, {19, 0, 0, 0}, {20, 0, 0, 0}, {21, 0, 0, 0}, {22, 0, 0, 0}, {23, 0, 0, 0}, {24, 0, 0, 0}, {25, 0, 0, 0}, {26, 0, 0, 0}, {27, 0, 0, 0}, {28, 0, 0, 0}, {29, 0, 0, 0}, {30, 0, 0, 0}, {31, 0, 0, 0}, {32, 0, 0, 0}, {33, 0, 0, 0}, {34, 0, 0, 0}, {35, 0, 0, 0}, {36, 0, 0, 0}, {37, 0, 0, 0}, {38, 0, 0, 0}, {39, 0, 0, 0}, {40, 0, 0, 0}, {41, 0, 0, 0}, {42, 0, 0, 0}, {43, 0, 0, 0}, {44, 0, 0, 0}, {45, 0, 0, 0}, {46, 0, 0, 0}, {47, 0, 0, 0}, {48, 0, 0, 0}, {49, 0, 0, 0}, {50, 0, 0, 0}, {51, 0, 0, 0}, {52, 0, 0, 0}, {53, 0, 0, 0}, {54, 0, 0, 0}, {55, 0, 0, 0}, {56, 0, 0, 0}, {57, 0, 0, 0}, {58, 0, 0, 0}, {59, 0, 0, 0}, {60, 0, 0, 0}, {61, 0, 0, 0}, {62, 0, 0, 0}, {63, 0, 0, 0}, {64, 0, 0, 0}, {65, 0, 0, 0}, {66, 0, 0, 0}, {67, 0, 0, 0}, {68, 0, 0, 0}, {69, 0, 0, 0}, {70, 0, 0, 0}, {71, 0, 0, 0}, {72, 0, 0, 0}, {73, 0, 0, 0}, {74, 0, 0, 0}, {75, 0, 0, 0}, {76, 0, 0, 0}, {77, 0, 0, 0}, {78, 0, 0, 0}, {79, 0, 0, 0}, {80, 0, 0, 0}};
byte brightness = 50;
unsigned short int error_delay = 150;

byte pix_num;
byte cR = 0;
byte cG = 0;
byte cB = 0;


void setup() {
  Serial.begin(115200);
  Serial.setTimeout(1000);

  LEDS.addLeds<WS2811, LED_PIN, GRB>(leds, NUM_LEDS);  // настройки для нашей ленты (ленты на WS2811, WS2812, WS2812B)
  if (LIMIT > 0) FastLED.setMaxPowerInVoltsAndMilliamps(5, LIMIT);
  one_color_all(0, 0, 0);
  LEDS.setBrightness(brightness);
  pinMode(POT_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUT_PIN, INPUT_PULLUP);
  strip_setup();
  one_color_all(0, 0, 0);
  LEDS.show();

  for (int index = 0; index < NUM_LEDS; index++ ) {
    :: buffer_[index][0] = index;
    :: err_b[index][0] = index;
    for (int inner_index = 1; inner_index < 4; inner_index++ ) {
      :: buffer_[index][inner_index] = 0;
      :: err_b[index][inner_index] = 0;
    }
  }
}



void draw(String recieved) {
  unsigned int prev_index = 0;

  for ( unsigned int read_counter = recieved.indexOf('P'); read_counter < recieved.length(); read_counter = recieved.indexOf('P', read_counter + 1)) {

    String working = recieved.substring(prev_index, read_counter);
    prev_index = read_counter;
    unsigned int S_index = working.indexOf('S');

    if (working.substring(0, 1) == "P" or working.substring(0, 1) == "Z") {
      pix_num = working.substring(1, working.indexOf('S')).toInt();
    }
    else {
      pix_num = working.substring(0, working.indexOf('S')).toInt();
    }

    if (working.substring(S_index + 1, working.length()).length() == 3) {
      :: buffer_[pix_num][1] = alph_n[alph_l.indexOf(working[S_index + 1])] * 16;
      :: buffer_[pix_num][2] = alph_n[alph_l.indexOf(working[S_index + 2])] * 16;
      :: buffer_[pix_num][3] = alph_n[alph_l.indexOf(working[S_index + 3])] * 16;

    }

    else if (working.substring(S_index + 1, working.length()).length() == 6) {
      :: buffer_[pix_num][1] = alph_n[alph_l.indexOf(working[S_index + 1])] * 16 + alph_n[alph_l.indexOf(working[S_index + 2])];
      :: buffer_[pix_num][2] = alph_n[alph_l.indexOf(working[S_index + 3])] * 16 + alph_n[alph_l.indexOf(working[S_index + 4])];
      :: buffer_[pix_num][3] = alph_n[alph_l.indexOf(working[S_index + 5])] * 16 + alph_n[alph_l.indexOf(working[S_index + 6])];
    }

    else {
      one_color_all(255, 0, 0);
      delay(250);
      one_color_all(0, 0, 0);
    }
  }
}

void loop() {
  if (switcher) {
    switcher = 0;
    Serial.println("R");
  }
  if (Serial.available() > 0) {
    String recieved = Serial.readString();
    if (recieved[0] == '1') {
      if (recieved[1] == 'Z') {

        unsigned int prev_index = 0;
        for ( unsigned int read_counter = recieved.indexOf('P'); read_counter < recieved.length(); read_counter = recieved.indexOf('P', read_counter + 1)) {
          String working;
          String * working_choose = &working;
          if (prev_index == 0) {
            * working_choose = recieved.substring(1, read_counter);
          }
          else {
            * working_choose = recieved.substring(prev_index, read_counter);
          }

          prev_index = read_counter;
          unsigned int S_index = working.indexOf('S');

          if (working.substring(0, 1) == "P" or working.substring(0, 1) == "Z") {
            pix_num = working.substring(1, working.indexOf('S')).toInt();
          }
          else {
            pix_num = working.substring(0, working.indexOf('S')).toInt();
          }

          if (working.substring(S_index + 1).length() == 3) {
            :: buffer_[pix_num][1] = alph_n[alph_l.indexOf(working[S_index + 1])] * 16;
            :: buffer_[pix_num][2] = alph_n[alph_l.indexOf(working[S_index + 2])] * 16;
            :: buffer_[pix_num][3] = alph_n[alph_l.indexOf(working[S_index + 3])] * 16;

          }

          else if (working.substring(S_index + 1).length() == 6) {
            :: buffer_[pix_num][1] = alph_n[alph_l.indexOf(working[S_index + 1])] * 16 + alph_n[alph_l.indexOf(working[S_index + 2])];
            :: buffer_[pix_num][2] = alph_n[alph_l.indexOf(working[S_index + 3])] * 16 + alph_n[alph_l.indexOf(working[S_index + 4])];
            :: buffer_[pix_num][3] = alph_n[alph_l.indexOf(working[S_index + 5])] * 16 + alph_n[alph_l.indexOf(working[S_index + 6])];
          }

          else {
            Serial.println("Fix it, really");
          }
        }

        for (unsigned int pixel_value = 0; pixel_value < sizeof(:: buffer_) / sizeof(:: buffer_[0]); pixel_value++) {

          leds[pixel_value] = CRGB(:: buffer_[pixel_value][1], :: buffer_[pixel_value][2], :: buffer_[pixel_value][3]);

          :: err_b[pixel_value][1] = :: buffer_[pixel_value][1];
          :: err_b[pixel_value][2] = :: buffer_[pixel_value][2];
          :: err_b[pixel_value][3] = :: buffer_[pixel_value][3];

          :: buffer_[pixel_value][1] = 0;
          :: buffer_[pixel_value][2] = 0;
          :: buffer_[pixel_value][3] = 0;
        }
        LEDS.show();
        Serial.println("g");
        delay(gif_delay);
      }
    }
    else if (recieved[0] == 'Z') {
      if (not z_count) {
        led_show = 0;
        z_count = 1;
      }
      else {
        led_show = 1;
        z_count = 0;
      }

      unsigned int prev_index = 0;

      for ( unsigned int read_counter = recieved.indexOf('P'); read_counter < recieved.length(); read_counter = recieved.indexOf('P', read_counter + 1)) {

        String working = recieved.substring(prev_index, read_counter);
        prev_index = read_counter;
        unsigned int S_index = working.indexOf('S');

        if (working.substring(0, 1) == "P" or working.substring(0, 1) == "Z") {
          pix_num = working.substring(1, working.indexOf('S')).toInt();
        }
        else {
          pix_num = working.substring(0, working.indexOf('S')).toInt();
        }
        if (working.substring(S_index + 1, working.length()).length() == 3) {
          :: buffer_[pix_num][1] = alph_n[alph_l.indexOf(working[S_index + 1])] * 16;
          :: buffer_[pix_num][2] = alph_n[alph_l.indexOf(working[S_index + 2])] * 16;
          :: buffer_[pix_num][3] = alph_n[alph_l.indexOf(working[S_index + 3])] * 16;

        }

        else if (working.substring(S_index + 1, working.length()).length() == 6) {
          :: buffer_[pix_num][1] = alph_n[alph_l.indexOf(working[S_index + 1])] * 16 + alph_n[alph_l.indexOf(working[S_index + 2])];
          :: buffer_[pix_num][2] = alph_n[alph_l.indexOf(working[S_index + 3])] * 16 + alph_n[alph_l.indexOf(working[S_index + 4])];
          :: buffer_[pix_num][3] = alph_n[alph_l.indexOf(working[S_index + 5])] * 16 + alph_n[alph_l.indexOf(working[S_index + 6])];
        }

        else {
          Serial.println("Fix it 2");
        }
      }

      if (led_show) {
        for (unsigned int pixel_value = 0; pixel_value < sizeof(:: buffer_) / sizeof(:: buffer_[0]); pixel_value++) {

          leds[pixel_value] = CRGB(:: buffer_[pixel_value][1], :: buffer_[pixel_value][2], :: buffer_[pixel_value][3]);

          :: err_b[pixel_value][1] = :: buffer_[pixel_value][1];
          :: err_b[pixel_value][2] = :: buffer_[pixel_value][2];
          :: err_b[pixel_value][3] = :: buffer_[pixel_value][3];

          :: buffer_[pixel_value][1] = 0;
          :: buffer_[pixel_value][2] = 0;
          :: buffer_[pixel_value][3] = 0;
        }

        LEDS.show();

      }

      Serial.println("g");
      delay(gif_delay);

    }



    else if (recieved[0] == 'b') {
      LEDS.setBrightness(recieved.substring(1).toInt());
      LEDS.show();
      Serial.println("g");
    }

    else if (recieved[0] == 'c') {
      one_color_all(0, 0, 0);
      LEDS.show();
      Serial.println("g");
    }

    else {
      one_color_all(255, 0, 0);
      LEDS.show();
      Serial.println("ERROR");
      delay(error_delay);

      for (byte pixels = 0; pixels < NUM_LEDS; pixels++) {
        leds[pixels] = CRGB(:: err_b[pixels][1], :: err_b[pixels][2], :: err_b[pixels][3]);
      }
      LEDS.show();
      delay(gif_delay);
    }
  }
}
