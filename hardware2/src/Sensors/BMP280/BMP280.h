#ifndef BMP280_h

    #define BMP280_h
    
        extern float BMP280_temperature;
        extern float BMP280_pressure;
        extern float BMP280_altitude;

        void setupBMP280();
        void readBMP280();
        void printReadBMP280();

#endif