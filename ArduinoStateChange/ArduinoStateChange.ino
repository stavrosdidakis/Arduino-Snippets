//This code makes sure to allow the button send only ONE value when its pressed
//Schematics as here: https://www.arduino.cc/en/Tutorial/Button
 
int tempButton1 = 0;
int button1 = 0;

void setup() {
  //Initialise Digital 2
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
  //Read from Digital 2
  button1 = digitalRead(2);

  //tempButton1 checks if there is a new incoming value
  //If there is a new value, and if this value is 1, then we print "1" on the Serial
  //After the end of the conditions, we assign the new value to temp
  if (tempButton1 != button1) {
    if (button1 == 1) Serial.println("1");
    tempButton1 = button1;
  }

  delay(100);
}
