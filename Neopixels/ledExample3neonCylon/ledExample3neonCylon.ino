#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN D2 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 32
Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int ledDelay = 10;
int ledDelayMin = 30;
int ledDelayMax = 300;

void setup() {
  Serial.begin(9600);
  strip.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();
}

void loop() {
  void colorWipe(int r, int g, int b, int wait); {
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, strip.Color(255, 0, 0));
      //strip.setPixelColor(32-i, strip.Color(255, 0, 0));
      strip.show();
      delay(ledDelay);
      strip.setPixelColor(i - 5, strip.Color(0, 0, 0));
      //strip.setPixelColor(32-i, strip.Color(0,0,0));
      strip.show();
      delay(ledDelay);

    }
    void colorWipe(int r, int g, int b, int wait); {
      for (int i = 0; i < strip.numPixels(); i++) {
        //strip.setPixelColor(i, strip.Color(255, 0, 0));
        strip.setPixelColor(32 - i, strip.Color(255, 0, 0));
        strip.show();
        delay(ledDelay);
        //strip.setPixelColor(i, strip.Color(0,0,0));
        strip.setPixelColor(37 - i, strip.Color(0, 0, 0));
        strip.show();
        delay(ledDelay);
      }
    }

  }
}
