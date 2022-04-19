//=====[Libraries]=============================================================

#include "arm_book_lib.h"

#include "smart_scale_system.h"

#include "load_cell.h"
#include "user_interface.h"
#include "pc_serial_com.h"

//=====[Declaration of private defines]======================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

InterruptIn tareButton(BUTTON1);
Ticker timer;
DigitalOut myled(LED1);

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

States current_state = States::Weighing;

//=====[Declarations (prototypes) of private functions]========================

static void tareButtonCallback();

static void led_switch(void);

//=====[Implementations of public functions]===================================

void smartScaleSystemInit()
{
    pcSerialComInit();
    loadCellInit();
    userInterfaceInit();
    tareButton.fall(&tareButtonCallback);
    timer.attach(&led_switch, 1);
}

void smartScaleSystemUpdate()
{
    pcSerialComUpdate();
    if(current_state == States::Weighing || current_state == States::ScaleCalibration) loadCellUpdate();
    userInterfaceUpdate();
}

//=====[Implementations of private functions]==================================

void changeState(States new_state)
{
    current_state = new_state;
    
    userInterfaceScreen(new_state);
    switch(new_state){
        case States::DataUpload:
            resetNumber();
            break;
    }
}

void tareButtonCallback()
{
    if(current_state ==  States::Weighing){
        current_state = States::Tare;
        loadCellTare();
        current_state = States::Weighing;
    }
}

void led_switch() {
    if(current_state == States::Weighing) myled = !myled;
    else myled = false;       
}