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

#define SENSOR_ADDRESS_ONE 20
//SFEVL53L1X distanceSensor1;
SFEVL53L1X distanceSensor1(Wire, SHUTDOWN_PIN_ONE, INTERRUPT_PIN_ONE);
SFEVL53L1X distanceSensor2(Wire, SHUTDOWN_PIN_TWO, INTERRUPT_PIN_TWO);


void setup(void)
{
  Wire.begin();

  Serial.begin(9600);

  Serial.println("Booting...");
  
  distanceSensor1.sensorOn();
   
  if (distanceSensor1.begin() == false)
  {
    Serial.println("Sensor 1 online!");
  }
  Serial.print("Sensor1 Address: ");
  Serial.println(distanceSensor1.getI2CAddress());

  distanceSensor1.sensorOff();


  distanceSensor2.sensorOn();
   
  if (distanceSensor2.begin() == false)
  {
    Serial.println("Sensor 2 online!");
  }
  Serial.print("Sensor2 Address: ");
  Serial.println(distanceSensor2.getI2CAddress());

  distanceSensor2.sensorOff();

  
/*
  if (distanceSensor2.begin() == false)
  {
    Serial.println("Sensor 2 online!");
  }
  Serial.println(distanceSensor2.getI2CAddress());
*/  

//  distanceSensor2.sensorOff();
//  distanceSensor1.setI2CAddress(SENSOR_ADDRESS_ONE);
//  distanceSensor2.sensorOn();
// Serial.println("Sensor 1 Address: " + distanceSensor1.getSensorID());
//  Serial.println("Sensor 2 Address: " + distanceSensor2.getI2CAddress());
 
}

void loop(void)
{
  distanceSensor1.startRanging(); //Write configuration bytes to initiate measurement
  int distance = distanceSensor1.getDistance(); //Get the result of the measurement from the sensor
  distanceSensor1.stopRanging();


  //Serial.print("S1");
  //Serial.println(distance);
  //Serial.print("E");

}

