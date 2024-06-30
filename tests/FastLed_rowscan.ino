// Description: This test lights up each LED in the matrix in sequence, row by row, with a yellow color. The LEDs are lit up for 30ms each. The brightness of the LEDs is set to 50% of the maximum brightness. The LEDs are connected to pin 6 of the Arduino. The number of LEDs in the matrix is 256. The LEDs are controlled using the FastLED library.

#include "FastLED.h"

// matrix attributes
#define NUM_LEDS 256
#define DATA_PIN 6
#define BRIGHTNESS 50  // value from 0 to 255
CRGB leds[NUM_LEDS];   // sets up the block of memory used for storing and manipulating the led data

void setup() {
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
  for (int dot = 0; dot < NUM_LEDS; dot++) {
    leds[dot] = CRGB::Yellow;
    FastLED.show();
    // clear this led for the next time around the loop
    leds[dot] = CRGB::Black;
    delay(30);
  }
}
