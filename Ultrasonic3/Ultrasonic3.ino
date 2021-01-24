#define CM 1      //Centimeter

#define TP1 4      //Trig_pin
#define EP1 5      //Echo_pin

#define TP2 6      //Trig_pin
#define EP2 7      //Echo_pin

#define TP3 8      //Trig_pin
#define EP3 9      //Echo_pin

void setup() {
  pinMode(TP1, OUTPUT);      // set TP output for trigger
  pinMode(EP1, INPUT);       // set EP input for echo

  pinMode(TP2, OUTPUT);      // set TP output for trigger
  pinMode(EP2, INPUT);       // set EP input for echo
  
  pinMode(TP3, OUTPUT);      // set TP output for trigger
  pinMode(EP3, INPUT);       // set EP input for echo
  
  Serial.begin(9600);      // init serial 9600
}

void loop() {
  long microseconds1 = TP1_init();
  long distance_cm1 = distanceCalc(microseconds1);
  if (distance_cm1 <= 330) {
    Serial.print("Distance_CM 1 = ");
    Serial.println(distance_cm1);
  }

  long microseconds2 = TP2_init();
  long distance_cm2 = distanceCalc(microseconds2);
  if (distance_cm2 <= 330) {
    Serial.print("Distance_CM 2 = ");
    Serial.println(distance_cm2);
  }

  long microseconds3 = TP3_init();
  long distance_cm3 = distanceCalc(microseconds3);
  if (distance_cm3 <= 330) {
    Serial.print("Distance_CM 3 = ");
    Serial.println(distance_cm3);
  }

  delay(300);
}

long distanceCalc(long time) {
  long distance;
  distance = time / 29 / 2  ;    // Distance_CM  = ((Duration of high level)*(Sonic :340m/s))/2
  return distance;
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

long TP2_init() {
  digitalWrite(TP2, LOW);
  delayMicroseconds(2);
  digitalWrite(TP2, HIGH);                 // pull the Trig pin to high level for more than 10us impulse
  delayMicroseconds(10);
  digitalWrite(TP2, LOW);
  long microseconds = pulseIn(EP2, HIGH);  // waits for the pin to go HIGH, and returns the length of the pulse in microseconds
  return microseconds;                    // return microseconds
}

long TP3_init() {
  digitalWrite(TP3, LOW);
  delayMicroseconds(2);
  digitalWrite(TP3, HIGH);                 // pull the Trig pin to high level for more than 10us impulse
  delayMicroseconds(10);
  digitalWrite(TP3, LOW);
  long microseconds = pulseIn(EP3, HIGH);  // waits for the pin to go HIGH, and returns the length of the pulse in microseconds
  return microseconds;                    // return microseconds
}
