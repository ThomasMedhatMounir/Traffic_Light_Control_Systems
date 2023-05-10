#ifndef DIO_H_INCLUDED
#define DIO_H_INCLUDED
#include "types.h"

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3
#define PORT_E 4
#define PORT_F 5
void DIO_write_port(uint32 port,uint8 value);
void DIO_write_pin(uint32 port,uint8 pin,uint8 value);
void DIO_init_portf();
uint8 DIO_read_pin(uint32 port,uint8 pin);
uint32 DIO_read_port(uint32 port);
void DIO_init_portd();
void DIO_init_porte();
void DIO_init_portc();
//void gpioa_init();
//void gpiob_init();
//void NORMAL_TRAFFIC();
void timer0A_delayMs(uint32 ttime);
void timer1A_delayMs(uint32 ttime);
void NS_GO();
void NS_READY();
void NS_STOP();
void EW_GO();
void EW_READY();
void EW_STOP();
/*void NS_G();
void NS_Y();
void NS_R();
void PNS_G();
void PNS_R();
void PEW_G();
void PEW_R();
void EW_G();
void EW_Y();
void EW_R();
*/

#endif // DIO_H_INCLUDED
