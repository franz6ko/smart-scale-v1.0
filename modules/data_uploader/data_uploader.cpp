//=====[Libraries]=============================================================

#include "mbed.h"

#include "data_uploader.h"

#include <string> 

//=====[Declaration of private defines]======================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

Serial uartEsp01(PA_15, PB_7, "ESP01", 115200); // TX_PIN | RX_PIN | NAME | BAUDRATE

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void sendData(int number, int weight){
    uartEsp01.printf("N%04dW%04d\r\n", number, weight);
}

//=====[Implementations of private functions]==================================