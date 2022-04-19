//=====[Libraries]=============================================================

#include "smart_scale_system.h"

//=====[Main function, the program entry point after power on or reset]========

int main()
{
    smartScaleSystemInit();
    while (true) {
        smartScaleSystemUpdate();
    }
}