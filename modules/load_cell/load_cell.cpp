//=====[Libraries]=============================================================

#include "mbed.h"

#include "HX711.h"

//=====[Declaration of private defines]======================================

//#define HX711_NUMBER_OF_AVG_SAMPLES    10
#define HX711_CALIBRATION_FACTOR    410

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

HX711 scale(PA_11, PA_12);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

int hx711_reading = 0;

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void loadCellInit()
{
    scale.setScale(HX711_CALIBRATION_FACTOR);
    scale.tare();
}

void loadCellUpdate()
{
    hx711_reading = (int)scale.getGram();
}

int loadCellGetWeight()
{
    return hx711_reading;
}

void loadCellTare()
{
    scale.tare();    
}

void modCalibration(float n)
{
    scale.setScale((int)(2.0*n*(float)HX711_CALIBRATION_FACTOR));
}

float getCalibration()
{
    return scale.getScale();
}



//=====[Implementations of private functions]==================================