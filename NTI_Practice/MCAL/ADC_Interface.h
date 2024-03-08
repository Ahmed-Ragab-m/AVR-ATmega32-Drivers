/*
 * ADC_Interface.h
 *
 * Created: 3/4/2024 11:11:51 AM
 *  Author: Lenovo
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

typedef enum{     // ADC VREF
	AREF,
	AVCC,
	INTERNAL
	}ADC_VREF;
	
typedef enum{    // ADC CHANNEL
	CHANEL0,
	CHANEL1,
	CHANEL2,
	CHANEL3,
	CHANEL4,
	CHANEL5,
	CHANEL6,
	CHANEL7,
	}ADC_CHANNEL;
	


void ADC_voidInit(ADC_VREF Refrence);
u16 ADC_u16ReadDigitalValue(ADC_CHANNEL Channel);



#endif /* ADC_INTERFACE_H_ */