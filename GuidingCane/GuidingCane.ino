#include <JsonListener.h>
#include <JsonStreamingParser.h>

#include <Adafruit_ATParser.h>
#include <Adafruit_BLE.h>
#include <Adafruit_BLEBattery.h>
#include <Adafruit_BLEEddystone.h>
#include <Adafruit_BLEGatt.h>
#include <Adafruit_BLEMIDI.h>
#include <Adafruit_BluefruitLE_SPI.h>
#include <Adafruit_BluefruitLE_UART.h>

//#include <GoogleMapsApi.h>
//#include <GoogleMapsDirectionsApi.h> //not sure if this is actually imported

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
 */

//init where pins are
int motorPin = 3; //or any other PWM pin

int BLUEFRUIT_UART_MODE_PIN = 12;
String BLUEFRUIT_HWSERIAL_NAME = "replace"; //TODO find serial name of module

//direction - 0 is forward, 1 is right, 2 is left, 3 is stopped
int dir = 0;

void setup()
{
  pinMode(motorPin, OUTPUT);
  //Adafruit_BluefruitLE_UART ble(BLUEFRUIT_HWSERIAL_NAME, BLUEFRUIT_UART_MODE_PIN);
  //TODO - setup google maps communication
  Serial.begin(9600);
}

void loop() 
{
  /*
   * TODO - communicate with maps to indicate a turn/direction 
   * INCLUDING delay and warning (warnDir()) before a turn
   * NOTE: warning will not trigger for stopping
   */
   dir = readMap();
   Serial.print(dir);
   if (dir == 1){
    turnRight();
   }else if (dir == 2){
    turnLeft();
   }else if (dir == 3){
    stopping();
   }
   dir = 0;
}

/*
 * Method to read google maps and communicate with the phone
 * to find direction instructions. Also uses warnDir() before left and right turns
 * TODO - Google maps integration, bluetooth communication, throw warning pings
 * 
 * @return random temporary integer from 1-3 to simulate a direction
 *         and test the vibration system
 */
long readMap(){
  long rand = random(1,4); //getting random long
  if (rand == 1 || rand == 2){
    warnDir(); //sends warning ping
    delay(3000); //waits for 3 seconds
  }
  return rand;
}

/*
 * Method for making a small vibration pattern 
 * to indicate a turn coming up
 */
void warnDir(){
  digitalWrite(motorPin, HIGH); //vibrate
  delay(300);
  digitalWrite(motorPin, LOW); //stop vibrating
  delay(300);
  digitalWrite(motorPin, HIGH);
  delay(100);
  digitalWrite(motorPin, LOW);
  delay(100);
  digitalWrite(motorPin, HIGH);
  delay(100);
  digitalWrite(motorPin, LOW);
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
