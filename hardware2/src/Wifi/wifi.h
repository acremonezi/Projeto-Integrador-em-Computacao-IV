#ifndef wifi_h

    #define wifi_h
        #include <WiFi.h>
        
        extern WiFiClient espClient;

        extern String espClientIP;
        extern String espClientMAC;
        extern String espClientMACsimple;
        extern String espClientHostname;

        void setupWifi();
        void reconnectWifi();

#endif
