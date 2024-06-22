#include <Adafruit_NeoMatrix.h>
#define PIXEL_PIN 6

// configure the 32 x 8 matrix
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(32, 8, PIXEL_PIN, NEO_MATRIX_TOP + NEO_MATRIX_RIGHT + NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE, NEO_RGB + NEO_KHZ800);

void setup() {
  matrix.begin();
  matrix.setBrightness(100);  // 0 to 255
  matrix.show();              // Initialize all pixels to 'off'
}

void loop() {
  for (int i = 0; i < 256 + 4; i++) {
    matrix.setPixelColor(i, 10, 10, 0);
    matrix.setPixelColor(i - 4, 0, 0, 10);
    matrix.show();
    delay(50);
  }
}