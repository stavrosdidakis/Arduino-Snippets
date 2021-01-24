// These constants won't change. They're used to give names to the pins used:
const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to

const int analogOutPin6 = 6; // Analog output pin that the LED is attached to
const int analogOutPin9 = 9; // Analog output pin that the LED is attached to
const int analogOutPin10 = 10; // Analog output pin that the LED is attached to
const int analogOutPin11 = 11; // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  // change the analog out value:

  if (sensorValue < 255){
    outputValue = map(sensorValue, 0, 255, 0, 255);
    Serial.print("Out 6 = ");
    Serial.println(outputValue);
    analogWrite(analogOutPin6, outputValue);
    
  } else if (sensorValue > 255 && sensorValue < 512){
    outputValue = map(sensorValue, 255, 512, 0, 255);
    Serial.print("Out 9 = ");
    Serial.println(outputValue);
    analogWrite(analogOutPin9, outputValue);
  } else if (sensorValue > 512 && sensorValue < 768){
    outputValue = map(sensorValue, 512, 768, 0, 255);
    Serial.print("Out 10 = ");
    Serial.println(outputValue);
    analogWrite(analogOutPin10, outputValue);
  } else if (sensorValue > 768){
    outputValue = map(sensorValue, 512, 768, 0, 255);
    Serial.print("Out 11 = ");
    Serial.println(outputValue);
    analogWrite(analogOutPin11, outputValue);
  }
 
  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  delay(2);
}
