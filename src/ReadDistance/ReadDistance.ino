#include <ComponentObject.h>
#include <RangeSensor.h>
#include <SparkFun_VL53L1X.h>
#include <vl53l1x_class.h>
#include <vl53l1_error_codes.h>
#include <Wire.h>
#include "SparkFun_VL53L1X.h"

//Optional interrupt and shutdown pins.
#define SHUTDOWN_PIN 2
#define INTERRUPT_PIN 3

SFEVL53L1X distanceSensor1;
SFEVL53L1X distanceSensor2;

//Uncomment the following line to use the optional shutdown and interrupt pins.
//SFEVL53L1X distanceSensor(Wire, SHUTDOWN_PIN, INTERRUPT_PIN);

void setup(void)
{
  Wire.begin();

  Serial.begin(9600);
 // Serial.println("VL53L1X Qwiic Test");

  if (distanceSensor1.begin() == false)
  {
   // Serial.println("Sensor online!");
  }
}

void loop(void)
{
  distanceSensor1.startRanging(); //Write configuration bytes to initiate measurement
  int distance = distanceSensor1.getDistance(); //Get the result of the measurement from the sensor
  distanceSensor1.stopRanging();


  Serial.print("S1");
  Serial.print(distance);
  Serial.print("E");

}

