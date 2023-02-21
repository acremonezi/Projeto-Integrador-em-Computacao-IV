#include "Adafruit_CCS811.h"
#include "CCS811.h"

Adafruit_CCS811 ccs;

// Define Variables starting values:
int CCS811_eCO2 = 0;
int CCS811_TVOC = 0;


void setupCCS811() {

  if(!ccs.begin()){
    Serial.println("Failed to start sensor! Please check your wiring.");
    while(1);
  }

  // Wait for the sensor to be ready
  while(!ccs.available());
}


void readCCS811() {
  if(ccs.available()){
    if(!ccs.readData()){
      CCS811_eCO2 = ccs.geteCO2();
      CCS811_TVOC = ccs.getTVOC();
    }
    else{
      while(1);
    }
  }
}


void printReadCCS811() {
      Serial.print("CCS811_eCO2 (ppm): ");
      Serial.print(CCS811_eCO2);

      Serial.print(" - CCS811_TVOC (ppb): ");
      Serial.print(CCS811_TVOC);

      Serial.println();

      delay(1000);
  }