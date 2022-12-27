//Trigger Counter

boolean trigger = false;
int counter = 0;

void setup() {  
}

void loop() {
  
  //Action to set trigger to true, i.e. press a button
      //..........
      //..........
      //..........

  //When the trigger variable is set to true, 
  //the following code activates
  if (trigger){
    
    //When the trigger is true, the counter starts
    counter++;
    
    //When the counter is below 5000 (a few secs)
    //run the following code
    if (counter < 5000){
      
      //The buzzer executes for the duration of 5000
      tone(buzzer, 1000); // Send 1KHz sound signal...
      delay(1000);        // ...for 1 sec
      noTone(buzzer);     // Stop sound...
      delay(1000);        // ...for 1sec
   
    } else {

      //When the counter passes 5000, we reset counter
      //and trigger
      counter = 0;
      trigger = false;
    }
  }
}
