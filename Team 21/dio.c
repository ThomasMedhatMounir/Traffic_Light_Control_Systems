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

 void NS_G();
void NS_Y();
void NS_R();
void PNS_G();
void PNS_R();
void PEW_G();
void PEW_R();
void EW_G();
void EW_Y();
void EW_R();
void PED_HANDLER();
//void PEW_HANDLER();
//void PED_TIMER();
void DIO_write_pin(uint32 port,uint8 pin,uint8 value){
    if (value == 1){
    switch (port){
case PORT_A:

  set_bit(GPIO_PORTA_DATA_R,pin);
  break;
  case PORT_B:

  set_bit(GPIO_PORTB_DATA_R,pin);
  break;
  case PORT_C:

  set_bit(GPIO_PORTC_DATA_R,pin);
  break;
  case PORT_D:

  set_bit(GPIO_PORTD_DATA_R,pin);
  break;
  case PORT_E:

  set_bit(GPIO_PORTE_DATA_R,pin);
  break;
  case PORT_F:

  set_bit(GPIO_PORTF_DATA_R,pin);
  break;
    }
    }
    else {
    switch (port){
case PORT_A:

  clear_bit(GPIO_PORTA_DATA_R,pin);
  break;
  case PORT_B:

  clear_bit(GPIO_PORTB_DATA_R,pin);
  break;
  case PORT_C:

  clear_bit(GPIO_PORTC_DATA_R,pin);
  break;
  case PORT_D:

  clear_bit(GPIO_PORTD_DATA_R,pin);
  break;
  case PORT_E:

  clear_bit(GPIO_PORTE_DATA_R,pin);
  break;
  case PORT_F:

  clear_bit(GPIO_PORTF_DATA_R,pin);
  break;
    }
    }
}

void DIO_write_port(uint32 port,uint8 value){
switch (port){
    case PORT_A:
 GPIO_PORTA_DATA_R=value;
 break;
 case PORT_B:
 GPIO_PORTB_DATA_R=value;
 break;
 case PORT_C:
 GPIO_PORTC_DATA_R=value;
 break;
 case PORT_D:
 GPIO_PORTD_DATA_R=value;
 break;
 case PORT_E:
 GPIO_PORTE_DATA_R=value;
 break;
 case PORT_F:
 GPIO_PORTF_DATA_R=value;
 break;
}
}

uint8 DIO_read_pin(uint32 port,uint8 pin){
  uint8 state=0;

  switch (port){
case PORT_A:

  state =  get_bit(GPIO_PORTA_DATA_R,pin);
  break;
  case PORT_B:

  state = get_bit(GPIO_PORTB_DATA_R,pin);
  break;
  case PORT_C:

  state = get_bit(GPIO_PORTC_DATA_R,pin);
  break;
  case PORT_D:

 state = get_bit(GPIO_PORTD_DATA_R,pin);
  break;
  case PORT_E:

 state = get_bit(GPIO_PORTE_DATA_R,pin);
  break;
  case PORT_F:

 state = get_bit(GPIO_PORTF_DATA_R,pin);
  break;
    }

  return (state);
}
uint32 DIO_read_port(uint32 port){
uint32 state =0;
  switch (port){
    case PORT_A:
   if ((get_bit(GPIO_PORTA_DATA_R,0))==0){
   state = 0x02;
   }
   else if((get_bit(GPIO_PORTA_DATA_R,4))==0){
     state = 0x04;
   }
   else if(((get_bit(GPIO_PORTA_DATA_R,0))&&(get_bit(GPIO_PORTA_DATA_R,0)))==1){
    state = 0x08; 
   }
   else 
     state =1;

break;
 case PORT_B:
   if ((get_bit(GPIO_PORTB_DATA_R,0))==0){
   state = 0x02;
   }
   else if((get_bit(GPIO_PORTB_DATA_R,4))==0){
     state = 0x04;
   }
   else if(((get_bit(GPIO_PORTB_DATA_R,0))&&(get_bit(GPIO_PORTB_DATA_R,0)))==1){
    state = 0x08; 
   }
   else 
     state =1;

break;
case PORT_C:
   for (uint16 k=4;k<=7;k++){
     
     state|=get_bit(GPIO_PORTC_DATA_R,k);}
break;
 case PORT_D:
   if ((get_bit(GPIO_PORTD_DATA_R,0))==0){
   state = 0x02;
   }
   else if((get_bit(GPIO_PORTD_DATA_R,4))==0){
     state = 0x04;
   }
   else if(((get_bit(GPIO_PORTD_DATA_R,0))&&(get_bit(GPIO_PORTD_DATA_R,0)))==1){
    state = 0x08; 
   }
   else 
     state =1;

break;
 case PORT_E:
   for (uint16 l=1;l<=4;l++){
     
     state|=get_bit(GPIO_PORTE_DATA_R,l);}
 break;

 case PORT_F:
   if ((get_bit(GPIO_PORTF_DATA_R,0))==0){
   state = 0x02;
   }
   else if((get_bit(GPIO_PORTF_DATA_R,4))==0){
     state = 0x04;
   }
   else if(((get_bit(GPIO_PORTF_DATA_R,0))&&(get_bit(GPIO_PORTF_DATA_R,0)))==1){
    state = 0x08; 
   }
   else {
     state =1;
   }
break;
  
}
return state;
}
/*
-------------------------------------------------------------------------
*/
void gpioa_init(){
   SYSCTL_RCGCGPIO_R |= 0x1;//port a clock gating
 while((SYSCTL_PRGPIO_R&0x1) == 0){}; //waiting for port to be ready for access
 GPIO_PORTA_LOCK_R = 0x4C4F434B;// unlocking port a
 GPIO_PORTA_CR_R = 0xFC;
 GPIO_PORTA_DIR_R = 0xFC;//pin 2,3,4,5,6,7 outputs
 GPIO_PORTA_DEN_R = 0xFC;//enabling pins

}
void gpiob_init(){ // same as port a
   SYSCTL_RCGCGPIO_R |= 0x2;
 while((SYSCTL_PRGPIO_R&0x2) == 0){};
 GPIO_PORTB_LOCK_R = 0x4C4F434B;
 GPIO_PORTB_CR_R = 0x0F;
 GPIO_PORTB_DIR_R = 0x0F;// 0,1,2,3 OUTPUT
 GPIO_PORTB_DEN_R = 0x0F;

}
void gpiof_init(){
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)){}

  HWREG(GPIO_PORTF_BASE+GPIO_O_LOCK) = GPIO_LOCK_KEY; // unlocking port f
  HWREG(GPIO_PORTF_BASE+GPIO_O_CR) = GPIO_PIN_0 | GPIO_PIN_4;// comit pins 0 and 4
  GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0); // pins 0 and 4 are inputs
  GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU); 
  GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);

  GPIOIntDisable(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0); //disabling previous interrupt
  GPIOIntClear(GPIO_PORTF_BASE,GPIO_PIN_4||GPIO_PIN_0);// clearing previous interrrupts
  GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0, GPIO_FALLING_EDGE);//setting interrupts to be triggered with falling edge
  GPIOIntRegister(GPIO_PORTF_BASE,PED_HANDLER);//setting which interrupt function to be triggered
  
   GPIOIntEnable(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0);//enabling interrupt
}
void timer0A_delayMs(uint32 ttime) // delay function in milliseconds
{
    uint32 i;
    TimerDisable(TIMER0_BASE, TIMER_BOTH);//disabling timer 0
   TimerConfigure(TIMER0_BASE,TIMER_CFG_PERIODIC_UP); //configuring timer 0 to be periodic and counting up
 
    TimerLoadSet(TIMER0_BASE, TIMER_BOTH, 15999); // 15999 = 1 ms
  
  TIMER0_ICR_R=0x01;
 
 TimerEnable(TIMER0_BASE, TIMER_BOTH);
    for(i = 0; i < ttime; i++) { 
      while ((TIMER0->RIS & 0x1) == 0) ;    
    TIMER0_ICR_R=0x01;
    }
}
void timer1A_delayMs(uint32 ttime)
{
  
    uint32 i;
    TimerDisable(TIMER1_BASE, TIMER_BOTH);
   TimerConfigure(TIMER1_BASE,TIMER_CFG_PERIODIC_UP);
 
    TimerLoadSet(TIMER1_BASE, TIMER_BOTH, 15999);
  
  TIMER1_ICR_R=0x01;
 
 TimerEnable(TIMER1_BASE, TIMER_BOTH);
    for(i = 0; i < ttime; i++) { while ((TIMER1->RIS & 0x1) == 0) ;      
    TIMER1_ICR_R=0x01;
    }
}
// traffic lights status functions
/*NS = NORTH SOUTH
PNS = PEDESTRIAN NORTH SOUTH
EW = EAST WEST
PEW = PEDESTRIAN EAST WEST
GO
READY
STOP
G=GREEN
Y=YELLOW
R=RED
*/
void NS_GO(){ //north-south go
  NS_G();
  PNS_G();
  EW_R();
  PEW_R();
}
void NS_READY(){
  NS_Y();
  PNS_G();
  EW_R();
  PEW_R();
}
void NS_STOP(){
  NS_R();
  PNS_R();
  EW_Y();
  PEW_R();
}
void EW_GO(){
  NS_R();
  PNS_R();
  EW_G();
  PEW_G();
}
void EW_READY(){
  NS_R();
  PNS_R();
  EW_Y();
  PEW_G();
}
void EW_STOP(){
  NS_Y();
  PNS_R();
  EW_R();
  PEW_R();
}
//traffic lights LED operation
void NS_G(){ // north south green
  DIO_write_pin(PORT_A,2,1);
   DIO_write_pin(PORT_A,3,0);
    DIO_write_pin(PORT_A,4,0);
}
void PNS_G(){
   DIO_write_pin(PORT_B,0,1);
    DIO_write_pin(PORT_B,1,0);
}
void EW_G(){
   DIO_write_pin(PORT_A,5,1);
   DIO_write_pin(PORT_A,6,0);
    DIO_write_pin(PORT_A,7,0);
}
void PEW_G(){
   DIO_write_pin(PORT_B,2,1);
    DIO_write_pin(PORT_B,3,0);
}
void NS_Y(){ // north south yellow
   DIO_write_pin(PORT_A,2,0);
   DIO_write_pin(PORT_A,3,1);
    DIO_write_pin(PORT_A,4,0);
}

void EW_Y(){
  DIO_write_pin(PORT_A,5,0);
   DIO_write_pin(PORT_A,6,1);
    DIO_write_pin(PORT_A,7,0);
}


void NS_R(){ // north south red
  DIO_write_pin(PORT_A,2,0);
   DIO_write_pin(PORT_A,3,0);
    DIO_write_pin(PORT_A,4,1);
}
void PNS_R(){
   DIO_write_pin(PORT_B,0,0);
    DIO_write_pin(PORT_B,1,1);
}
void EW_R(){
  DIO_write_pin(PORT_A,5,0);
   DIO_write_pin(PORT_A,6,0);
    DIO_write_pin(PORT_A,7,1);
}

void PEW_R(){
  DIO_write_pin(PORT_B,2,0);
    DIO_write_pin(PORT_B,3,1);
}
/*
--------------------------------------------------------
*/
//Normal traffic lights operation
void NORMAL_TRAFFIC(){
 
   NS_GO();
  timer0A_delayMs(5000);
  NS_READY();

  timer0A_delayMs(2000);
  NS_STOP();

  timer0A_delayMs(1000);
   EW_GO();

  timer0A_delayMs(5000);
  EW_READY();

  timer0A_delayMs(2000);
  EW_STOP();

  timer0A_delayMs(1000);

}

void PED_HANDLER(){ // when pedestrian presses button
   __asm  ("    CPSID  I\n");
   if(DIO_read_pin(PORT_F,0)){ // if north south pedestrian needs to move
 
 printf("H\n");
  EW_Y();
  PEW_R();
  timer1A_delayMs(1000);
  NS_G();
  PNS_G();
  EW_R();
  PEW_R();
  timer1A_delayMs(2000);
  GPIOIntClear(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0); 
     __asm  ("    CPSIE  I\n");
   }
   else if (DIO_read_pin(PORT_F,4))// if east west pedestrian needs to move
   {
      printf("inthamadsha\n");


  NS_Y();
  PNS_R();
  timer1A_delayMs(1000);
  NS_R();
  PNS_R();
  EW_G();
  PEW_G();
  timer1A_delayMs(2000);
    GPIOIntClear(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0); 
   }
}
