// Pins
int sensorPin = 0;
int lightPin = 13; //On-board LED

void setup() {
  // Start Serial & set pin to output
  Serial.begin(9600);
  pinMode(lightPin,OUTPUT);
}

void loop() {
  // Read the sensor pin
  int sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);

  if (sensorValue>350){
    digitalWrite(lightPin,HIGH);
  }
  else {
    digitalWrite(lightPin,LOW);
  }
}
