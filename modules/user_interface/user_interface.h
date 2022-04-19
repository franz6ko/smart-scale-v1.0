//=====[#include guards - begin]===============================================

#ifndef _USER_INTERFACE_H_
#define _USER_INTERFACE_H_

//=====[Libraries]=============================================================

#include "smart_scale_system.h"
#include "display.h"
#include "load_cell.h"
#include "matrix_keypad.h"
#include "pc_serial_com.h"
#include "data_uploader.h"

//=====[Declaration of public defines]=======================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void userInterfaceInit();
void userInterfaceUpdate();
void userInterfaceScreen(States new_state);
void resetNumber();
int getNumber();

//=====[#include guards - end]=================================================

#endif // _USER_INTERFACE_H_