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

  Serial.begin(115200);
  //Turn off Sensor 1 so we can reprogram address on #2 
  distanceSensor1.sensorOff();
  distanceSensor2.sensorOn();
  distanceSensor2.init();
  distanceSensor2.setI2CAddress(TOF_ADDRESS_TWO);
 

  distanceSensor1.sensorOn();
  distanceSensor1.init();
  
}

void loop(void)
{
  distanceSensor1.startRanging();
  int distance1 = distanceSensor1.getDistance(); //Get the result of the measurement from the sensor
  distanceSensor1.stopRanging();
  Serial.print("S1");
  Serial.print(distance1);
  Serial.print("E");


  distanceSensor2.startRanging();
  int distance2 = distanceSensor2.getDistance(); //Get the result of the measurement from the sensor
  distanceSensor2.stopRanging();

  Serial.print("S2");
  Serial.print(distance2);
  Serial.print("E");

}

