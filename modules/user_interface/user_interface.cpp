//=====[Libraries]=============================================================

#include "mbed.h"
#include "arm_book_lib.h"

#include "user_interface.h"

//=====[Declaration of private defines]======================================

#define DISPLAY_REFRESH_TIME_MS 5

//=====[Declaration of private data types]=====================================

AnalogIn potenciometer(A0);

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

char number[5] = {'-','-','-','-', 0};
int index = 0;

//=====[Declarations (prototypes) of private functions]========================

static void userInterfaceDisplayInit();
static void userInterfaceDisplayUpdate();
static void userInterfaceMatrixKeypadUpdate();
void eraseLine(int line);

//=====[Implementations of public functions]===================================

void userInterfaceInit()
{
    matrixKeypadInit(SYSTEM_TIME_INCREMENT_MS);
    userInterfaceDisplayInit();
}

void userInterfaceUpdate()
{
    static int filter = 0;
    if(current_state == States::ScaleCalibration){
        if(filter >= 5){
            float p = potenciometer.read();
            modCalibration(p);
            filter = 0;
        }
        else filter++;
    }
    userInterfaceMatrixKeypadUpdate();
    userInterfaceDisplayUpdate();
}

//=====[Implementations of private functions]==================================

static void userInterfaceDisplayInit()
{
    displayInit( DISPLAY_TYPE_GLCD_ST7920, DISPLAY_CONNECTION_SPI); 
     
    displayCharPositionWrite ( 0,0 );
    displayStringWrite( "Smart Scale v1.0" );

    displayCharPositionWrite ( 0,1 );
    displayStringWrite( "Weight:" );
    
    displayCharPositionWrite ( 12,1 );
    displayStringWrite( "g" );
}

static void userInterfaceDisplayUpdate()
{
    static int accumulatedDisplayTime = 0;
    char weightString[5];
    char calibValue[4];
    
    if( accumulatedDisplayTime >= DISPLAY_REFRESH_TIME_MS )
    {
        accumulatedDisplayTime = 0;
        
        switch(current_state){
            case States::ScaleCalibration: {
                displayCharPositionWrite ( 0,3 );
                displayStringWrite("Calibration: ");
                sprintf(calibValue, "%03d", (int)getCalibration());
                displayCharPositionWrite ( 12,3 );
                displayStringWrite(calibValue);
                
                int value = loadCellGetWeight();
                if(value < 0 || value > 9999) strcpy(weightString, "----");
                else sprintf(weightString, "%04d", value);
                displayCharPositionWrite ( 9,1 );
                displayStringWrite(weightString);
                break;
                }
            case States::Weighing: {
                int value = loadCellGetWeight();
                if(value < 0 || value > 9999) strcpy(weightString, "----");
                else sprintf(weightString, "%04d", value);
                displayCharPositionWrite ( 9,1 );
                displayStringWrite(weightString);
                break;
                }
            case States::DataUpload: {
                displayCharPositionWrite ( 0,2 );
                displayStringWrite("ID:");
                displayCharPositionWrite ( 4,2 );
                displayStringWrite(number);    
                break;
                }
        }
    }
    else
    {
        accumulatedDisplayTime = accumulatedDisplayTime + SYSTEM_TIME_INCREMENT_MS;        
    } 
}

static void userInterfaceMatrixKeypadUpdate()
{
    static int numberOfHashKeyReleased = 0;
    char keyReleased = matrixKeypadUpdate();
    
    if( keyReleased != '\0' ) {
        uartUsb.printf("Key pressed: %c \r\n", keyReleased);
        switch(keyReleased){
            case 'B':
            case '*':
                resetNumber();
                index = 0;
                break;
            case 'C':
                if(current_state == States::Weighing){
                    changeState(States::ScaleCalibration);
                }
                break;
            case 'A':
                if(current_state == States::Weighing){
                    changeState(States::DataUpload);
                }
                break;
            case '#': {
                if(current_state == States::DataUpload){
                    sendData(getNumber(), loadCellGetWeight());
                    displayCharPositionWrite ( 0,3 );
                    displayStringWrite("Data uploaded!");
                    wait(2.0f);
                    changeState(States::Weighing);
                }
                if(current_state == States::ScaleCalibration){
                    changeState(States::Weighing);    
                }
                break;
                }
            default:
                if(index < 4) number[index++] = keyReleased; 
        }
    }
}

void userInterfaceScreen(States new_state)
{
    switch(new_state){
        case States::Weighing:
            eraseLine(2);
            eraseLine(3);
            break;
    }
}

void eraseLine(int line){
    displayCharPositionWrite (0, line);
    displayStringWrite("                ");    
}

void resetNumber()
{
    index = 0;
    strcpy(number, "----");
}

int getNumber()
{
    return atoi(number);  
}