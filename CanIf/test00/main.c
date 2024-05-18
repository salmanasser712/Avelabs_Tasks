#include <stdio.h>
#include "CanIf.h"

int main(){
    printf("Compiled successfully!!\n");
    uint8  Controller = 0, ConfigurationIndex = 0;
    CanIf_InitController( Controller, ConfigurationIndex);
    return 0;
}