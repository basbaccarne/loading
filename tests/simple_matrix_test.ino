// This code lights up a blue pixel that moves from left to right across the 32 x 8 matrix. The pixel trail will be 4 pixels long.
#include <Adafruit_NeoMatrix.h>
#define PIXEL_PIN 6

// configure the 32 x 8 matrix
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(32, 8, PIXEL_PIN, NEO_MATRIX_TOP + NEO_MATRIX_RIGHT + NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE, NEO_GRB + NEO_KHZ800);

// color scheme
uint32_t blue = matrix.Color(0, 0, 255);

void setup() {
  matrix.begin();
  matrix.setBrightness(10);  // 0 to 255
  matrix.show();             // Initialize all pixels to 'off'
}

void loop() {
  for (int i = 0; i < 256 + 4; i++) {
    matrix.setPixelColor(i, blue);
    matrix.setPixelColor(i - 4, 0);
    matrix.show();
    delay(50);
  }
}