#include <Adafruit_NeoPixel.h>
#define PIN 2	 // input pin Neopixel is attached to
#define NUMPIXELS      4 // number of neopixels in strip
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int delayval = 100; // timing delay in milliseconds
int redColor = 0;
int greenColor = 0;
int blueColor = 0;

#define CM 1      //Centimeter
#define TP1 4      //Trig_pin
#define EP1 5      //Echo_pin

void setup() {
  pinMode(TP1, OUTPUT);      // set TP output for trigger
  pinMode(EP1, INPUT);       // set EP input for echo

  // Initialize the NeoPixel library.
  pixels.begin();
}

void loop() {
  long microseconds1 = TP1_init();
  long distance_cm1 = distanceCalc(microseconds1);
  
  //setColor();
  for (int i=0; i < NUMPIXELS; i++) {
    if (distance_cm1 < 336) {
      //Serial.print("Distance_CM 1 = ");
      //Serial.println(distance_cm1);
      pixels.setPixelColor(i, pixels.Color(255,0,255));
      // This sends the updated pixel color to the hardware.
      // Delay for a period of time (in milliseconds).
      //delay(delayval);
    } else{
      pixels.setPixelColor(i, pixels.Color(0,0,0));
    }
    pixels.show();
  }
 delay(100);
}

long TP1_init() {
  digitalWrite(TP1, LOW);
  delayMicroseconds(2);
  digitalWrite(TP1, HIGH);                 // pull the Trig pin to high level for more than 10us impulse
  delayMicroseconds(10);
  digitalWrite(TP1, LOW);
  long microseconds = pulseIn(EP1, HIGH);  // waits for the pin to go HIGH, and returns the length of the pulse in microseconds
  return microseconds;                    // return microseconds
}

long distanceCalc(long time) {
  long distance;
  distance = time / 29 / 2  ;    // Distance_CM  = ((Duration of high level)*(Sonic :340m/s))/2
  return distance;
}