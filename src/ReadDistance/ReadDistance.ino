#include <ComponentObject.h>
#include <RangeSensor.h>
#include <SparkFun_VL53L1X.h>
#include <vl53l1x_class.h>
#include <vl53l1_error_codes.h>
#include <Wire.h>
#include "SparkFun_VL53L1X.h"

//Optional interrupt and shutdown pins.
#define SHUTDOWN_PIN_ONE 8
#define INTERRUPT_PIN_ONE 9
#define SHUTDOWN_PIN_TWO 10
#define INTERRUPT_PIN_TWO 11
#define TOF_ADDRESS_ONE 82
#define TOF_ADDRESS_TWO 83

SFEVL53L1X distanceSensor1(Wire, SHUTDOWN_PIN_ONE, INTERRUPT_PIN_ONE);
SFEVL53L1X distanceSensor2(Wire, SHUTDOWN_PIN_TWO, INTERRUPT_PIN_TWO);


void setup(void)
{
  Wire.begin();

  Serial.begin(9600);
  //Turn off Sensor 1 so we can reprogram address on #2 
  distanceSensor1.sensorOff();
  
  distanceSensor2.sensorOn();
  distanceSensor2.init();
  distanceSensor2.setI2CAddress(TOF_ADDRESS_TWO);
  distanceSensor2.stopRanging();

  distanceSensor1.sensorOn();
  distanceSensor1.init();

  if(distanceSensor1.checkBootState()) Serial.println("Sensor one booted.");
  if(distanceSensor2.checkBootState()) Serial.println("Sensor two booted.");
  Serial.print("Sensor 1 address = ");
  Serial.println(distanceSensor1.getI2CAddress());
  Serial.print("Sensor 2 address = ");
  Serial.println(distanceSensor2.getI2CAddress());

  distanceSensor1.startRanging();
  distanceSensor2.startRanging();

  while(!distanceSensor1.checkForDataReady()) distanceSensor1.checkForDataReady();
  Serial.print("Distance1: ");
  Serial.println(distanceSensor1.getDistance());
  delay(10);
  while(!distanceSensor2.checkForDataReady()) distanceSensor2.checkForDataReady();
  Serial.print("Distance2: ");
  Serial.println(distanceSensor2.getDistance());
  
  }

void loop(void)
{
  /*
  Serial.print("S1:");
  
  distanceSensor1.startRanging();
  Serial.print(distanceSensor1.getDistance()); //Get the result of the measurement from the sensor
  distanceSensor1.stopRanging();

  Serial.println(",");
  Serial.print("S2:");

  
 // distanceSensor2.startRanging();
 Serial.print(distanceSensor2.getDistance()); //Get the result of the measurement from the sensor
 // distanceSensor2.stopRanging();
  Serial.println(".");
*/
}

