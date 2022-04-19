//=====[#include guards - begin]===============================================

#ifndef _SMART_SCALE_SYSTEM_H_
#define _SMART_SCALE_SYSTEM_H_

//=====[Libraries]=============================================================

//=====[Declaration of public defines]=======================================

#define SYSTEM_TIME_INCREMENT_MS   10

//=====[Declaration of public data types]======================================

enum class States {Weighing, Tare, DataUpload, ScaleCalibration};
extern States current_state;

//=====[Declarations (prototypes) of public functions]=========================

void smartScaleSystemInit();
void smartScaleSystemUpdate();
void changeState(States new_state);

//=====[#include guards - end]=================================================

#endif // _SMART_SCALE_SYSTEM_H_