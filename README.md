# loading
an animated loading sign

## Materials
- BTF-LIGHTNING WS2812B Panel Screen 8*32 DC5V
- Arduino Nano
- External Power

## Short reminders
- The LED panel needs 5V seperate from the Arduino (but don't forget to connect grounds)
- 8 x 32 = 256 leds

## Things I learned and want to remember
- You can use the Neopixel Libraries such as the [simple](/tests) examples in the test folder
- This includes simple ways to produce text using ``Adafruit_NeoMatrix.h``
- LED strips and matrices often use a ``ws2811`` controller
- ``FastLED`` is a library that allows faster, more efficient and more advanced animations
