#include "dio.h"
#include "types.h"
#include "bitwise_operation.h"
#include "tm4c123gh6pm.h"

#include <stdint.h>
#include <stdbool.h>
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"
#include "driverlib/interrupt.h"
#include "inc/hw_memmap.h"
#include "inc/hw_gpio.h"
#include "inc/hw_ints.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tm4c123gh6pm.h"
#include "driverlib/timer.h"
#include <string.h>
#include <time.h>
#include "driverlib/sysctl.h"
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "tm4c123gh6pm.h"
#include "tm4c_cmsis.h"
#include "core_cm4.h"
#include "core_cmInstr.h"
#include "core_cmFunc.h"
#include "core_cmSimd.h"
 


 void gpioa_init();//initialize port a
  void gpiob_init();//init port b
  void gpiof_init();//init port f
  void NORMAL_TRAFFIC();
  int main() {
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);// enabling timers 1 and 0 peripherals
   while(!SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER0))
{
}
  SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);
   while(!SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER1))
{
}  
   gpioa_init();
   gpiob_init();
   gpiof_init();

 while(1){
   printf("hamada\n"); 
   NORMAL_TRAFFIC();
   
 }
  }
 
  

