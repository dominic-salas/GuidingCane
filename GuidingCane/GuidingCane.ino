#include <Adafruit_ATParser.h>
#include <Adafruit_BLE.h>
#include <Adafruit_BLEBattery.h>
#include <Adafruit_BLEEddystone.h>
#include <Adafruit_BLEGatt.h>
#include <Adafruit_BLEMIDI.h>
#include <Adafruit_BluefruitLE_SPI.h>
#include <Adafruit_BluefruitLE_UART.h>

#include <JsonListener.h>
#include <JsonStreamingParser.h>

#include <GoogleMapsApi.h>
#include <GoogleMapsDirectionsApi.h> //not sure if this is actually imported

/*
 * Code for vibration motor for the guiding cane project.
 * Vibrating motor pulses to communicate with user:
 * TODO: warnings before turns
 * 1 pulse = turn right
 * 2 pulses = turn left
 * 3 pulses = stop
 * Possible: instructions for distances, 
 */

//init where pins are
int motorPin = 3;
int BLUEFRUIT_UART_MODE_PIN = 12;
String BLUEFRUIT_HWSERIAL_NAME = "replace this with serial name of module"; //TODO find serial name of module

//direction - 0 is forward, 1 is right, 2 is left, 3 is stopped
int dir = 0;

void setup()
{
  pinMode(motorPin, OUTPUT);
  Adafruit_BluefruitLE_UART ble(BLUEFRUIT_HWSERIAL_NAME, BLUEFRUIT_UART_MODE_PIN);
}

void loop() 
{
  if (dir == 1){
    turnRight();
  }else if (dir == 2){
    turnLeft();
  }else if (dir == 3){
    stopping();
  }
}

/*
 * Turning right, pulses motor once
 */
void turnRight(){
  digitalWrite(motorPin, HIGH); //vibrate
  delay(500);  // on .5 seconds
  digitalWrite(motorPin, LOW);  //stop vibrating
  right = false;
}

/*
 * Turning left, pulses motor twice
 */
void turnLeft(){
  digitalWrite(motorPin, HIGH); //vibrate
  delay(500);  // on .5 seconds
  digitalWrite(motorPin, LOW);  //stop vibrating
  left = false;
}

/*
 * Stopping, pulses motor three times
 * Possible: call turnRight or turnLeft to 
 * indicate what direction destination is
 */
void stopping(){
  digitalWrite(motorPin, HIGH); //vibrate
  delay(500);  // on .5 seconds
  digitalWrite(motorPin, LOW);  //stop vibrating
  stop = false;
}
