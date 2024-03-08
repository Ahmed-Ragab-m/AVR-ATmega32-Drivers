

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_
#include "STD_TYPES.h"

#define ADMUX_REG     (*(volatile u8*)0X27)     // ADC Multiplexer selection register
#define MUX0      0
#define MUX1      1
#define MUX2      2
#define MUX3      3
#define MUX4      4
#define ADLAR     5
#define REFS0     6
#define REFS1     7

#define ADCSRA_REG   (*(volatile u8*)0X26)      // ADC CONTROL AND STATUS REGISTER
#define ADPS0   0
#define ADPS1   1
#define ADPS2   2
#define ADIE    3
#define ADIF    4
#define ADATE   5
#define ADSC    6
#define ADEN    7

#define ADCH   (*(volatile u8*)0X25)
#define ADCL   (*(volatile u8*)0X24)
#define ADC    (*(volatile u16*)0X24)



#endif /* ADC_PRIVATE_H_ */