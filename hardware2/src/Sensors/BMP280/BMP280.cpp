#include <Wire.h>
#include <SPI.h>
#include <Adafruit_BMP280.h>
#include "BMP280.h"

Adafruit_BMP280 bmp; // I2C

// Define Variables:
float BMP280_temperature = 0;
float BMP280_pressure = 0;
float BMP280_altitude = 0;


void setupBMP280() {
  unsigned status;
  status = bmp.begin(0x76);
  // if (!status) {
  //   while (1) delay(100);
  // }

 /* Default settings from datasheet. */
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL,     /* Operating Mode. */
                  Adafruit_BMP280::SAMPLING_X2,     /* Temp. oversampling */
                  Adafruit_BMP280::SAMPLING_X16,    /* Pressure oversampling */
                  Adafruit_BMP280::FILTER_X16,      /* Filtering. */
                  Adafruit_BMP280::STANDBY_MS_500); /* Standby time. */
}




void readBMP280() {
    BMP280_temperature = bmp.readTemperature();
    BMP280_pressure = bmp.readPressure();
    BMP280_altitude = bmp.readAltitude(1013);
    delay(100);
}


void printReadBMP280() {
    Serial.print("BMP280_temperature (°C): ");
    Serial.print(BMP280_temperature);

    Serial.print(" - BMP280_pressure (Pa): ");
    Serial.print(BMP280_pressure);

    Serial.print(" - BMP280_altitude (m): ");
    Serial.print(BMP280_altitude);

    Serial.println();

    delay(1000);
}