
#include "Can.h"
#include "CanIf_Cbk.h"
#include <string.h>

#include "debug.h"
#include "PduR.h"

const CanIf_ConfigType CanIf_Config;

void Can_Init( const Can_ConfigType *Config ){

}
void Can_DeInit(void){

}

void Can_InitController( uint8 controller, const Can_ControllerConfigType *config){

}
Can_ReturnType Can_SetControllerMode( uint8 Controller, Can_StateTransitionType transition ){
    return CAN_OK;
}
void Can_DisableControllerInterrupts( uint8 controller ){

}
void Can_EnableControllerInterrupts( uint8 controller ){

}

Can_ReturnType Can_Write( Can_Arc_HTHType hth, Can_PduType *pduInfo ){
    return CAN_OK;
}

void Can_Cbk_CheckWakeup( uint8 controller ){

}
void Can_MainFunction_Write( void ){

}
void Can_MainFunction_Read( void ){

}
void Can_MainFunction_BusOff( void ){

}
void Can_MainFunction_Error( void ){

}
void Can_MainFunction_Wakeup( void ){

}

void Can_Arc_GetStatistics( uint8 controller, Can_Arc_StatisticsType * stat){

}
