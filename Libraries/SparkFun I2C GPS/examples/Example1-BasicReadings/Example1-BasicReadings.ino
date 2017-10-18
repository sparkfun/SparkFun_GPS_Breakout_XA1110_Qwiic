/*
  Reading the raw NMEA sentences from the Qwiic GPS module over I2C
  By: Nathan Seidle
  SparkFun Electronics
  Date: April 12th, 2017
  License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

  This grabs the incoming NMEA sentences like GNGGA and GNRMC over I2C and outputs them to the serial
  monitor at 115200bps.

  We've included the library with this example so that you can get started immediately. For the other
  examples you'll need to install the SparkFun I2C GPS Arduino library from the Library manager.

  Hardware Connections:
  Attach a Qwiic shield to your RedBoard or Uno.
  Plug the Qwiic sensor into any port.
  Serial.print it out at 115200 baud to serial monitor.
*/

#include "SparkFun_I2C_GPS_Arduino_Library.h" //Use Library Manager or download here: https://github.com/sparkfun/SparkFun_I2C_GPS_Arduino_Library
I2CGPS myI2CGPS; //Hook object to the library

void setup()
{
  Serial.begin(115200);
  Serial.println("GTOP Read Example");

  if (myI2CGPS.begin() == false)
  {
    Serial.println("Module failed to respond. Please check wiring.");
    while (1); //Freeze!
  }
  Serial.println("GPS module found!");
}

void loop()
{
  while (myI2CGPS.available()) //available() returns the number of new bytes available from the GPS module
  {
    byte incoming = myI2CGPS.read(); //Read the latest byte from Qwiic GPS

    if(incoming == '$') Serial.println(); //Break the sentences onto new lines
    Serial.write(incoming); //Print this character
  }
}


