#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "ADC_Interface.h"
#include "ADC_Private.h"

void ADC_voidInit(ADC_VREF Refrence)
{
	/* VREF */
	switch(Refrence)
	{
		case AREF:     CLEAR_BIT(ADMUX_REG,REFS0);
		               CLEAR_BIT(ADMUX_REG,REFS1);
					   break;
		case AVCC:
		               SET_BIT(ADMUX_REG,REFS0);
		               CLEAR_BIT(ADMUX_REG,REFS1);
					   break;
		case INTERNAL: SET_BIT(ADMUX_REG,REFS0);
		               SET_BIT(ADMUX_REG,REFS1);
					   break;
					   
	}
	/*PRESCALLER 128*/
	ADCSRA_REG=ADCSRA_REG&0XF8;
	ADCSRA_REG|=0b00000111;
	/*INTERRUPT DISABLE*/
	CLEAR_BIT(ADCSRA_REG,ADIE);
	/*ADLAR=0*/
	CLEAR_BIT(ADMUX_REG,ADLAR);
	/*ADC ENABLE*/
	SET_BIT(ADCSRA_REG,ADEN);
}

u16 ADC_u16ReadDigitalValue(ADC_CHANNEL Channel)
{
	/* SELECT CHANNEL*/
	ADMUX_REG=ADMUX_REG&0xE0;
	ADMUX_REG=ADMUX_REG|Channel;
	/* START CONVERSION */
	SET_BIT(ADCSRA_REG,ADSC);
	/* WAIT UNTILL CONVERSION COMPLETE*/
	while(GET_BIT(ADCSRA_REG,ADSC)==1);  
	/* GET VALUE */
	return ADC;
}