#ifndef BITWISE_OPERATION_H_INCLUDED
#define BITWISE_OPERATION_H_INCLUDED



#define set_bit(reg,bit) ((reg)|=(1<<(bit)))
#define clear_bit(reg,bit) ((reg)&=(~(1<<(bit))))
#define get_bit(reg,bit) ((reg)&(1<<(bit)))
#define toggle_bit(reg,bit) ((reg) ^= (1<<(bit)))

#endif // BITWISE_OPERATION_H_INCLUDED
