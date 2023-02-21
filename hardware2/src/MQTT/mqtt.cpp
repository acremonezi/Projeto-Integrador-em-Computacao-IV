#include "mqtt.h"                   // MQTT Code
#include <PubSubClient.h>           // MQTT Library
#include <ArduinoJson.h>            // JSON Library
#include "Wifi/wifi.h"              // WiFi Code
#include "Sensors/CCS811/CCS811.h"  // CCS811 Code
#include "Sensors/BMP280/BMP280.h"  // BMP280 Code
#include "Sensors/BME280/BME280.h"  // BME280 Code


// MQTT Settings
const char *mqtt_username = MQTT_USERNAME;
const char *mqtt_password = MQTT_PASSWD;
const char *mqtt_broker = MQTT_BROKER_SERVER;
const int mqtt_port = MQTT_SERVER_PORT;


PubSubClient client(espClient);


void setupMQTT() {

  // Connecting to a mqtt broker
  client.setServer(mqtt_broker, mqtt_port);
  //client.setCallback(callback);

  while (!client.connected()) {

      Serial.printf("The client %s is conneting to the MQTT Broker Server\n", espClientMACsimple.c_str());
      if (client.connect(espClientHostname.c_str(), mqtt_username, mqtt_password)) {

      } else {
          Serial.print("Failed with state: ");
          Serial.print(client.state());      }
  }
}


void publishMQTT() {

  // Define MQTT Topic
  String device_topic = "sensors/";
  device_topic.concat(espClientMACsimple);

  // Convert String to char
  int stringLength = device_topic.length() + 1; 
  char characterArray[stringLength];
  device_topic.toCharArray(characterArray, stringLength);

  // Define MQTT Topic to Publish
  char *topic = characterArray;


  //Convert float data to strings
  // Allocate the JSON document
  //
  // Inside the brackets, 200 is the RAM allocated to this document.
  // Don't forget to change this value to match your requirement.
  // Use https://arduinojson.org/v6/assistant to compute the capacity.
  StaticJsonDocument<1024> doc;

  // StaticJsonObject allocates memory on the stack, it can be
  // replaced by DynamicJsonDocument which allocates in the heap.
  //
  //DynamicJsonDocument doc(256);

  // Add values in the document
  doc["Hostname"] = espClientHostname;
  doc["BME280_temp"] = floor(BME280_temperature * 10.0) / 10.0;
  doc["BME280_pres"] = floor(BME280_pressure * 10.0) / 10.0;
  doc["BME280_alt"] = floor(BME280_altitude * 10.0) / 10.0;
  doc["BME280_hum"] = floor(BME280_humidity * 10.0) / 10.0;
  doc["BMP280_temp"] = floor(BMP280_temperature * 10.0) / 10.0;
  doc["BMP280_pres"] = floor(BMP280_pressure * 10.0) / 10.0;
  doc["BMP280_alt"] = floor(BMP280_altitude * 10.0) / 10.0;
  doc["CCS811_eCO2"] = CCS811_eCO2;
  doc["CCS811_TVOC"] = CCS811_TVOC;

  // Generate the minified JSON and send it to the Serial port.
  serializeJsonPretty(doc, Serial);

  // Start a new line
  Serial.println();

  char outputJson[512];
  serializeJson(doc, outputJson);
  
  //Publish the data to the topic
  client.publish(topic, outputJson);
  client.loop();
}