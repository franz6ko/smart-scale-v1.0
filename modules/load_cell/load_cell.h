//=====[#include guards - begin]===============================================

#ifndef _LOAD_CELL_H_
#define _LOAD_CELL_H_

//=====[Libraries]=============================================================

//=====[Declaration of public defines]=======================================

//=====[Declaration of public data types]======================================

//=====[Declarations (prototypes) of public functions]=========================

void loadCellInit();
void loadCellUpdate();
int loadCellGetWeight();
void loadCellTare();
void modCalibration(float n);
float getCalibration();

//=====[#include guards - end]=================================================

#endif // _LOAD_CELL_H_