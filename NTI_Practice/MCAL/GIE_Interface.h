
#ifndef GIE_INTERFACE_H_
#define GIE_INTERFACE_H_



#define SREG_REG   *((volatile u8*)0x5F)
#define SREG_I		7

void GIE_voidEnable(void);
void GIE_voidDisable(void);




#endif /* GIE_INTERFACE_H_ */