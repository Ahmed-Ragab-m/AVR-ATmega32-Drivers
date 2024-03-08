#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "SPI_Private.h"
#include "SPI_Interface.h"


void SPI_voidInitMaster(void)
{
	// Disable SPI interrupt
	CLEAR_BIT(SPCR_REG, SPIE);
	
	//select Data Order LSB transmitted first
	SET_BIT(SPCR_REG, DORD);
	
	// select Master Mode
	SET_BIT(SPCR_REG, MSTR);
	
	// select CLK Polarity Falling => Rising , select CLK Phase Setup => Sample
	CLEAR_BIT(SPCR_REG, CPOL);
	CLEAR_BIT(SPCR_REG, CPHA);
	
	// select CLK Rate = FCPU/64 (250 KHZ)
	
	CLEAR_BIT(SPCR_REG, SPR0);
	SET_BIT(SPCR_REG, SPR1);
	CLEAR_BIT(SPSR_REG, SPI2X);
	
	// Enable SPI
	SET_BIT(SPCR_REG, SPE);
}

void SPI_voidInitSlave(void)
{
	// Disable SPI interrupt
	CLEAR_BIT(SPCR_REG, SPIE);
	
	//select Data Order LSB transmitted first
	SET_BIT(SPCR_REG, DORD);
	
	// select Salve Mode
	CLEAR_BIT(SPCR_REG, MSTR);
	
	// select CLK Polarity Falling => Rising , select CLK Phase Setup => Sample
	CLEAR_BIT(SPCR_REG, CPOL);
	CLEAR_BIT(SPCR_REG, CPHA);
	
	// Enable SPI
	SET_BIT(SPCR_REG, SPE);
}

void SPI_voidTransieve(u8 TxData, u8* RxData)
{
	if(RxData!=NULL)
	{
		SPDR_REG = TxData;
		
		// Busy Wait for SPI Flag
		while(GET_BIT(SPSR_REG,SPIF)==0);
		
		*RxData = SPDR_REG;
	}
	else
	{
		// return Error State
	}
}

