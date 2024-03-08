#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GIE_Interface.h"

void GIE_voidEnable(void)
{
	SET_BIT(SREG_REG,SREG_I);
}

void GIE_voidDisable(void)
{
	CLEAR_BIT(SREG_REG,SREG_I);
}
