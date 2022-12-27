#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN D2 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 32
Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int ledDelay = 100;
int ledDelayMin = 30;
int ledDelayMax = 300;

void setup() {
  Serial.begin(9600);
  strip.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();
}

void loop() {
  ledDelay = random(ledDelayMin, ledDelayMax);
  colorChase(strip.Color(126, 0, 0), ledDelay);  //0  RED

  ledDelay = random(ledDelayMin, ledDelayMax);
  colorChase(strip.Color(126, 126, 0), ledDelay); //1  ORANGE

  ledDelay = random(ledDelayMin, ledDelayMax);
  colorChase(strip.Color(0, 126, 126), ledDelay); //2  YELLOW

  ledDelay = random(ledDelayMin, ledDelayMax);
  colorChase(strip.Color(63, 90, 0), ledDelay); //3  CHARTREUSE GREEN

  ledDelay = random(ledDelayMin, ledDelayMax);
  colorChase(strip.Color(0, 126, 0), ledDelay); //4  ELECTRIC GREEN

  ledDelay = random(ledDelayMin, ledDelayMax);
  colorChase(strip.Color(0, 126, 63), ledDelay); //5  SPRING GREEN

  ledDelay = random(ledDelayMin, ledDelayMax);
  colorChase(strip.Color(0, 126, 126), ledDelay); //6  CYAN

  ledDelay = random(ledDelayMin, ledDelayMax);
  colorChase(strip.Color(0, 63, 126), ledDelay); //7  AZURE

  ledDelay = random(ledDelayMin, ledDelayMax);
  colorChase(strip.Color(0, 0, 126), ledDelay); //8  BLUE
  
  ledDelay = random(ledDelayMin, ledDelayMax);
  colorChase(strip.Color(63, 0, 126), ledDelay); //9  VIOLET

  ledDelay = random(ledDelayMin, ledDelayMax);
  colorChase(strip.Color(126, 0, 126), ledDelay); //10 MAGENTA

  ledDelay = random(ledDelayMin, ledDelayMax);
  colorChase(strip.Color(126, 0, 63), ledDelay); //11 ROSE

  ledDelay = random(ledDelayMin, ledDelayMax);
  colorChase(strip.Color(126, 126, 126), ledDelay); //12 WHITE
}

// Chase one dot down the full strip.  Good for testing purposes.
void colorChase(uint32_t c, uint8_t wait) {
  int i;
  
  // Start by turning all pixels off:
  for(i=0; i<strip.numPixels(); i++) strip.setPixelColor(i, 0);

  // Then display one pixel at a time:
  for(i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c); // Set new pixel 'on'
    strip.show();              // Refresh LED states
    strip.setPixelColor(i, 0); // Erase pixel, but don't refresh!
    delay(wait);
  }

  strip.show(); // Refresh to turn off last pixel
}
