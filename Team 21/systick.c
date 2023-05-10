#include "tm4c123gh6pm.h"
#include "bitwise_operation.h"
#include "types.h"
#include "DIO.h"
void SysTickEnable(void){
  NVIC_ST_RELOAD_R=0x7A11FF; //timer set to 500ms
 NVIC_ST_CURRENT_R =0x00;
 NVIC_ST_CTRL_R=0x05;
}
uint32 SysTickPeriodGet(void){

}