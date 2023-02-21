#ifndef CCS811_h

    #define CCS811_h
    
        extern int CCS811_eCO2; // eCO2 = equivalent CO2
        extern int CCS811_TVOC; // TVOC = total volatile organic compounds (VOCs)

        void setupCCS811();
        void readCCS811();
        void printReadCCS811();

#endif