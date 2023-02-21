#ifndef BME280_h

    #define BME280_h

        extern float BME280_temperature;
        extern float BME280_pressure;
        extern float BME280_altitude;
        extern float BME280_humidity;

        void setupBME280();
        void readBME280();
        void printReadBME280();
        
#endif