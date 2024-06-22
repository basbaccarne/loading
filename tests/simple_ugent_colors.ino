#include <Adafruit_NeoMatrix.h>
#define PIXEL_PIN 6

// configure the 32 x 8 matrix
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(32, 8, PIXEL_PIN, NEO_MATRIX_TOP + NEO_MATRIX_RIGHT + NEO_MATRIX_COLUMNS + NEO_MATRIX_PROGRESSIVE, NEO_RGB + NEO_KHZ800);

// create array of colors
const row[] = [4,13,20,29,36,45,52,61,68,77,84,93,100,109,116,125,132,141,148,157,164,173,180,189,196,205,212,221,228,237,244,253];


void setup() {
  matrix.begin();
  matrix.setBrightness(100);  // 0 to 255
  matrix.show();              // Initialize all pixels to 'off'
}

void loop() {
  for (row; row < 256 + 4; row++) {
    matrix.setPixelColor(row, 10, 10, 0);
    matrix.setPixelColor(row - 4, 0, 0, 10);
    matrix.show();
    delay(50);
  }
}