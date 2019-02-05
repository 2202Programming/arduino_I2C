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


SFEVL53L1X distanceSensor1(Wire, SHUTDOWN_PIN_ONE, INTERRUPT_PIN_ONE);
SFEVL53L1X distanceSensor2(Wire, SHUTDOWN_PIN_TWO, INTERRUPT_PIN_TWO);


void setup(void)
{
  Wire.begin();

  Serial.begin(115200);

}

void loop(void)
{
  Serial.print("S1");
  distanceSensor1.sensorOn();
  distanceSensor1.init();
  distanceSensor1.setDistanceModeLong();
  distanceSensor1.setIntermeasurementPeriod(100);

  Serial.print(distanceSensor1.getDistance()); //Get the result of the measurement from the sensor
  distanceSensor1.sensorOff();
 
  Serial.print("ES2");


  distanceSensor2.sensorOn();
  distanceSensor2.init();
  distanceSensor2.setDistanceModeLong();
  distanceSensor2.setIntermeasurementPeriod(100);
  Serial.print(distanceSensor2.getDistance()); //Get the result of the measurement from the sensor
  distanceSensor2.sensorOff();

  Serial.print("E");

}

