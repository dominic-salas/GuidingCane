/*
 * Code for vibration motor for the guiding cane project.
 * Vibrating motor pulses to communicate with user:
 * 
 * A small vibration warning happens before each turn
 *
 * 1 pulse = turn right
 * 2 pulses = turn left
 * 3 pulses = stop
 * 
 * The user uses buttons to give signals:
 * 
 * btn1 = turn left
 * btn2 = turn right
 * btn1 and btn2 pressed simultaneously = stop
 */

//init where pins are
const int motorPin = 3; //or any other PWM pin
const int btn1 = 2; //button for left
const int btn2 = 4; //button for right

//direction - 0 is forward, 1 is right, 2 is left, 3 is stopped
int left = 0;
int right = 0;
int dir = 0;

void setup()
{
  pinMode(motorPin, OUTPUT);
  pinMode(btn1, INPUT);
  pinMode(btn1, INPUT);
}

void loop() 
{
  // read the state of the pushbutton value:
  left = digitalRead(btn1);
  right = digitalRead(btn2);
  //while loop to make pressing both buttons easier
  int counter = 0;
  while (left == 1 || right == 1){
    left = digitalRead(btn1);
    right = digitalRead(btn2);
    counter += 1;
    if (counter >= 100){ //at least 100 loops to trigger other button
      if (left == 1 && right == 1){
        dir = 3;
        left = 0;
        right = 0;
      }
      else{
        if (right == 1){
          dir = 1;
        }else if (left == 1){
          dir = 2;
        }
      }
    }
  }
  
  if (dir == 1){
    turnRight();
  }else if (dir == 2){
    turnLeft();
  }else if (dir == 3){
    stopping();
  }
  dir = 0;
  left = 0;
  right = 0;
}

/*
 * Turning right, pulses motor once
 */
void turnRight(){
  digitalWrite(motorPin, HIGH); //vibrate
  delay(500);  // on .5 seconds
  digitalWrite(motorPin, LOW);  //stop vibrating
  delay(2000  );
}

/*
 * Turning left, pulses motor twice
 */
void turnLeft(){
  digitalWrite(motorPin, HIGH); //vibrate
  delay(500);  // on .5 seconds
  digitalWrite(motorPin, LOW);  //stop vibrating
  delay(500);
  digitalWrite(motorPin, HIGH); //vibrate
  delay(500);  // on .5 seconds
  digitalWrite(motorPin, LOW);  //stop vibrating
  delay(2000);
}

/*
 * Stopping, pulses motor three times
 */
void stopping(){
  digitalWrite(motorPin, HIGH); //vibrate
  delay(500);  // on .5 seconds
  digitalWrite(motorPin, LOW);  //stop vibrating
  delay(500);
  digitalWrite(motorPin, HIGH); //vibrate
  delay(500);  // on .5 seconds
  digitalWrite(motorPin, LOW);  //stop vibrating
  delay(500);
  digitalWrite(motorPin, HIGH); //vibrate
  delay(500);  // on .5 seconds
  digitalWrite(motorPin, LOW);  //stop vibrating
  delay(2000);
}
