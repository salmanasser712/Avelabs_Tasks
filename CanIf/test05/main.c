#include <stdio.h>
#include "CanIf.h"
#include "CanIf_Cbk.h"

extern const CanIf_ConfigType CanIf_Config;

int main(){
    CanControllerIdType Controller = CAN_CTRL_0;

    CanIf_Init(&CanIf_Config);
    CanIf_ControllerBusOff(Controller);
    
    return 0;
}