#include <Wire.h>
#include <SPI.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include "BME280.h"

Adafruit_BME280 bme; // I2C

// Define Variables:
float BME280_temperature = 0;
float BME280_pressure = 0;
float BME280_altitude = 0;
float BME280_humidity = 0;


void setupBME280() {
    unsigned status;
    status = bme.begin(0x77);
    // if (!status) {
    //     while (1) delay(100);
    // }
}


void readBME280() { 
    BME280_temperature = bme.readTemperature();
    BME280_pressure = bme.readPressure() / 100.0F;
    BME280_altitude = bme.readAltitude(1013);
    BME280_humidity = bme.readHumidity();
    delay(100);
}


void printReadBME280() {
    Serial.print("BME280_temperature (°C): ");
    Serial.print(BME280_temperature);

    Serial.print(" - BME280_pressure (hPa): ");
    Serial.print(BME280_pressure);


    Serial.print(" - BME280_altitude (m): ");
    Serial.print(BME280_altitude);

    Serial.print(" - BME280_humidity (%) = ");
    Serial.print(BME280_humidity);

    Serial.println();
}