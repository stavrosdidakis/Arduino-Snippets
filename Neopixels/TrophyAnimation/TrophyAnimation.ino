///////////////////////////////////// Adafruit Neopixel Settings
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define LED_PIN   D2
#define LED_COUNT 32
Adafruit_NeoPixel leds(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
uint32_t col;
/////////////////////////////////////

int wait = 5;

void setup() {
  leds.begin();    // initialize pixel strip
  leds.show();     // Initialize all pixels to 'off'

  col = leds.Color(255, 0, 255);
  for(int i=0; i< leds.numPixels() ; i++) { 
    leds.setPixelColor(i, col); 
  }
  leds.show();
}

void loop() {
  leds.clear();
  for (int brightness = 255; brightness >= 0; brightness--) {
    for(int i=0; i<leds.numPixels(); i++) { 
      leds.setBrightness(brightness);    // set the brightness
      leds.setPixelColor(i, col); 
    }
    leds.show(); // refresh the strip
    delay(wait);                           
  }
  for (int brightness = 0; brightness <= 255; brightness++) {
    for(int i=0; i< leds.numPixels() ; i++) { 
      leds.setBrightness(brightness);    // set the brightness
      leds.setPixelColor(i, col); 
    }
    leds.show(); // refresh the strip
    delay(wait);
  }
  
  delay(wait*100);
}
