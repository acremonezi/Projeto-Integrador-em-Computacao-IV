#include <Arduino.h>
#include "Sensors/CCS811/CCS811.h"
#include "Sensors/BMP280/BMP280.h"
#include "Sensors/BME280/BME280.h"
#include "Wifi/wifi.h"
#include "MQTT/mqtt.h"

void setup() {
  //Serial
    Serial.begin(9600);
    delay(100);

  // Sensors
    setupCCS811();
    setupBMP280();
    setupBME280();

  // WiFi and MQTT
    setupWifi();
    setupMQTT();
}

void loop() {
  // Sensors
    readCCS811();
    //printReadCCS811();

    readBMP280();
    //printReadBMP280();

    readBME280();
    //printReadBME280();

  // WiFi and MQTT
    //reconnectWifi();
    publishMQTT();
    delay(1000);
}