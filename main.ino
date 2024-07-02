
/* 
This is the main code for the IO loading sign
This code runs on a 8 x 32 LED matrix and has 5 chapters:
- Chapter 1: A Ghent University Blue ember searches for a place to hatch
- Chapter 2: A Ghent University Yellow ember searches for a place to hatch
- Chapter 3: Envelopped in each others wombs, the blue ember hatches and sprouts an "O"
- Chapter 4: A second blue ember hatches and spouts an 'i'
- Chapter 5: The story crumbles down
*/

// Libraries
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>

// Pins & Settings
#define PIN 6
#define MATRIX_WIDTH 32
#define MATRIX_HEIGHT 8
const int last_row = MATRIX_WIDTH - 1;

// Configuration of the LED matrix
Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(
  MATRIX_WIDTH, MATRIX_HEIGHT, PIN,
  NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
  NEO_GRB + NEO_KHZ800);

// Initialize the LED matrix
void setup() {
  matrix.begin();
  matrix.setBrightness(40);
  matrix.fillScreen(0);
}

// Main program
void loop() {
  // clear the screen
  matrix.fillScreen(0);

  // Colors (RGB)
  uint16_t Blue = matrix.Color(0, 0, 255);
  uint16_t Yellow = matrix.Color(255, 255, 0);
  uint16_t Off = matrix.Color(0, 0, 0);

  // Chapter 1: A Ghent University Blue ember searches for a place to hatch (the search)
  for (int steps = 0; steps < MATRIX_WIDTH - 5; steps++) {
    int noise = random(0, 2);
    matrix.drawPixel(last_row - steps, MATRIX_HEIGHT / 2 - 1 + noise, Blue);
    matrix.show();
    matrix.drawPixel(last_row - steps, MATRIX_HEIGHT / 2 - 1 + noise, Off);
    delay(100);
  }

  // Chapter 1: A Ghent University Blue ember searches for a place to hatch (the settle)


  // Chapter 1: A Ghent University Blue ember searches for a place to hatch (the explosion)
  for (int radius = 0; radius < MATRIX_WIDTH; radius++) {
    matrix.fillCircle(5, MATRIX_HEIGHT / 2 - 1, radius, Blue);
    matrix.show();
    delay(30);
  }

  // Chapter 2: A Ghent University Yellow ember searches for a place to hatch (the search)
  for (int steps = 0; steps < MATRIX_WIDTH - 5; steps++) {
    int noise = random(0, 2);
    matrix.drawPixel(0 + steps, MATRIX_HEIGHT / 2 - 1 + noise, Yellow);
    matrix.show();
    matrix.drawPixel(0 + steps, MATRIX_HEIGHT / 2 - 1 + noise, Blue);
    delay(100);
  }

  // Chapter 2: A Ghent University Yellow ember searches for a place to hatch (the settle)


  // Chapter 2: A Ghent University Yellow ember searches for a place to hatch (the explosion)
  for (int radius = 0; radius < MATRIX_WIDTH; radius++) {
    matrix.fillCircle(MATRIX_WIDTH - 5, MATRIX_HEIGHT / 2 - 1, radius, Yellow);
    matrix.show();
    delay(30);
  }

  // Chapter 3: Envelopped in each others wombs, the blue ember hatches and sprouts an "O" (the search)
  for (int steps = 0; steps < 12; steps++) {
    int noise = random(0, 2);
    matrix.drawPixel(last_row - steps, MATRIX_HEIGHT / 2 - 1 + noise, Blue);
    matrix.show();
    matrix.drawPixel(last_row - steps, MATRIX_HEIGHT / 2 - 1 + noise, Yellow);
    delay(100);
  }

  // Chapter 3: Envelopped in each others wombs, the blue ember hatches and sprouts an "O" (the sprout)
  // outer layers
  matrix.fillRect(last_row - 11, MATRIX_HEIGHT / 2 - 1, 2, 2, Blue);  // fillRect -> top-left+width+height+color
  matrix.show();
  delay(100);
  matrix.fillRect(last_row - 11, MATRIX_HEIGHT / 2 - 2, 2, 4, Blue);
  matrix.fillRect(last_row - 12, MATRIX_HEIGHT / 2 - 1, 4, 2, Blue);
  matrix.show();
  delay(100);
  matrix.fillRect(last_row - 11, MATRIX_HEIGHT / 2 - 3, 2, 6, Blue);
  matrix.show();
  delay(100);
  matrix.fillRect(last_row - 12, MATRIX_HEIGHT / 2 - 4, 4, 8, Blue);
  matrix.fillRect(last_row - 14, MATRIX_HEIGHT / 2 - 2, 8, 4, Blue);
  matrix.fillRect(last_row - 13, MATRIX_HEIGHT / 2 - 3, 6, 6, Blue);
  matrix.fillRect(last_row - 11, MATRIX_HEIGHT / 2 - 1, 2, 2, Yellow);
  matrix.show();
  delay(100);
  // punch the hole
  matrix.fillRect(last_row - 11, MATRIX_HEIGHT / 2 - 2, 2, 4, Yellow);
  matrix.fillRect(last_row - 12, MATRIX_HEIGHT / 2 - 1, 4, 2, Yellow);
  matrix.show();
  delay(100);

  // Chapter 4: A second blue ember hatches and spouts an 'i' (the search)
  for (int steps = 0; steps < 9; steps++) {
    int noise = random(0, 1);
    matrix.drawPixel(steps + 2 + noise, steps, matrix.Color(0, 0, 255));
    matrix.show();
    matrix.drawPixel(steps + 2 + noise, steps, matrix.Color(255, 255, 0));
    delay(200);
  }

  // Chapter 4: A second blue ember hatches and spouts an 'i' (the sprout)
  matrix.drawLine(10, 7, 16, 7, Blue);  // drawLine > x0, y0, x1, y1, color
  matrix.show();
  delay(200);
  matrix.drawLine(11, 6, 12, 6, Blue);
  matrix.drawLine(13, 6, 15, 6, Blue);
  matrix.show();
  delay(200);
  matrix.drawLine(12, 5, 14, 5, Blue);
  matrix.show();
  delay(200);
  matrix.drawPixel(13, 4, Blue);
  matrix.show();
  delay(200);

  matrix.drawPixel(13, 3, Blue);
  matrix.show();
  delay(200);

  matrix.drawPixel(13, 2, Blue);
  matrix.drawPixel(13, 3, Yellow);
  matrix.show();
  delay(200);

  matrix.drawPixel(13, 1, Blue);
  matrix.drawPixel(13, 2, Blue);
  matrix.show();
  delay(200);

  matrix.drawPixel(13, 1, Yellow);
  matrix.drawRect(12, 0, 3, 3, Blue);
  matrix.show();
  delay(200);

  // Chapter 5 - crumbling down


  delay(10000);
}