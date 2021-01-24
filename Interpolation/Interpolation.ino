int inValue = 0;
int oldValue = 0;
int counter = 0;
int counterTime = 0;
int percentage = 0;
float percentFloat = 0;
float interpolate = 0;

void setup(){
  Serial.begin(9600);
}

void loop(){
  int analIn = analogRead(0);
  //Function's parameters: (incoming value, delay time)
  interpolation(analIn, 1000);
}

void interpolation(int inValue, int interpolateTime){
  if (inValue != oldValue) counterTime = interpolateTime;
  if (counterTime != 0) counter++;
  percentage = map (counter, 0, interpolateTime, 0, 100);
  percentFloat = (float) percentage/100;      
  interpolate = lerp(oldValue, inValue, percentFloat);
  if (counter > counterTime) counter = counterTime;
  if (percentage == 100) oldValue = inValue;
  counterTime = 0; 
  Serial.println(interpolate);
}

float lerp(float a, float b, float x) { 
  return a + x * (b - a);
}

