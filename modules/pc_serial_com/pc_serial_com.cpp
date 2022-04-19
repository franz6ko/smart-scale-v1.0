//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "pc_serial_com.h"
#include "smart_scale_system.h"

//=====[Declaration of private defines]======================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

Serial uartUsb(USBTX, USBRX);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

//=====[Declarations (prototypes) of private functions]========================

//=====[Implementations of public functions]===================================

void pcSerialComInit()
{
    uartUsb.printf( "Smart Scale v1.0:\r\n" );
}

void pcSerialComUpdate()
{
    if(uartUsb.readable()) {
        char receivedChar = uartUsb.getc();
        if(receivedChar == '\r'){
            uartUsb.printf("Next state \r\n");
        }
    }
}

//=====[Implementations of private functions]==================================