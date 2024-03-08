
#ifndef SPI_PRIVATE_H_
#define SPI_PRIVATE_H_
#include "STD_TYPES.h"

#define     SPCR_REG       (*(volatile u8*)0X2D)
#define     SPSR_REG       (*(volatile u8*)0X2E)
#define     SPDR_REG       (*(volatile u8*)0X2F)      


#define     SPR0                0             
#define     SPR1                1            
#define     CPHA                2            
#define     CPOL                3             
#define     MSTR                4            
#define     DORD                5             
#define     SPE                 6             
#define     SPIE                7             


#define     SPI2X               0      
#define     WCOL                6             
#define     SPIF                7            



#endif /* SPI_PRIVATE_H_ */