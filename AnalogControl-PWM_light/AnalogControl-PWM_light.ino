int led = 9;           

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read: 
  Serial.println(sensorValue);
  
  analogWrite(led, sensorValue/4 ); 
  //0-255 is the range for PWM
  //For this reason, we divide sensorValue by 4, 
  //as its original range is 0-1024
  
  delay(1);        // delay in between reads for stability
}
