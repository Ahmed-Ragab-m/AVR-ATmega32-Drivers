#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_Interface.h"
#include "ADC_Interface.h"
#include "SPI_Interface.h"
#include "LCD_Interface.h"
#include "KEYPAD_Interface.h"

#define F_CPU 16000000
#include "util/delay.h"

//#include <avr/io.h>


int main(void)
{
	DIO_voidSetAllPinsDirections();
    LCD_voidInit();
    LCD_voidWriteString("SPI_MASTER");
	DIO_voidSetPinValue(PINB4,LOW);
	SPI_voidInitMaster();
	u8 dataRecive,dataSend=3;
	
	
	DIO_voidSetPinValue(PINC1,LOW);
	
    while (1) 
    {
		SPI_voidTransieve(dataSend,&dataRecive);
		LCD_voidSetCursor(1,0);
		LCD_voidWriteNumber(dataRecive);
		if(dataRecive==5)
		{
			DIO_voidSetPinValue(PINC1,HIGH);
		}
		else
		{
			DIO_voidSetPinValue(PINC1,LOW);
		}
		
    }
}

