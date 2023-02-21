#include "wifi.h"

// Variables:
String espClientIP = "";
String espClientMAC = "";
String espClientMACsimple = "";
String espClientHostname = "";

// WiFi Authentication:
const char* ssid     = "Quantum_IoT";
const char* password = "Y7Q9vD8V10b!!!";

// Create an WiFiClient class to connect to the MQTT server.
WiFiClient espClient;

void setupWifi() {

    // Extract Wifi MAC Address
      espClientMAC = String(WiFi.macAddress()).c_str();
      espClientMACsimple = espClientMAC.c_str();
      espClientMACsimple.replace(":", "");

    // Connect to WiFi network:
      delay(1000);
      Serial.println();
      Serial.println();
      Serial.print("Connecting to: ");
      Serial.println(ssid);

      // Set Device Hostname
      WiFi.hostname(espClientMACsimple);

      // WiFi.mode(WIFI_STA);
      // WiFi.disconnect();
      WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(100);
        Serial.print(".");
    }
    
    // Set Device Hostname
      WiFi.hostname(espClientMACsimple);

    // Extract Wifi IP Address and Hostname
      espClientIP = WiFi.localIP().toString().c_str();
      espClientHostname = WiFi.getHostname();
    
    // Print Wifi Connection Info
      Serial.println("");
      Serial.println("WiFi connected");
      Serial.println("IP address: " + espClientIP);
      Serial.println("Hostname: " + espClientHostname);
      Serial.print("Connection Strength: ");
      Serial.println(WiFi.RSSI());
}



void reconnectWifi() {
  if (WiFi.status() != WL_CONNECTED)
  {
    WiFi.reconnect();
  }
}
