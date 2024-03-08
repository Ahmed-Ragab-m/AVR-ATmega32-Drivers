#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "EXInterupt_Private.h"
#include "EXInterrupt_Interface.h"

void EXTI_voidEnable (EXTI_source InterruptSource,EXTI_senseControl SenseControl)
{
	switch(InterruptSource)
	{
		case EXTI_INT0 :
		switch(SenseControl)
		{
			case RISING_EDGE :
			SET_BIT(MCUCR_REG,MCUCR_ISC00);
			SET_BIT(MCUCR_REG,MCUCR_ISC01);
			break;
			case FALLING_EDGE:
			CLEAR_BIT(MCUCR_REG,MCUCR_ISC00);
			SET_BIT(MCUCR_REG,MCUCR_ISC01);
			break;
			
			case LOW_LEVEL:
			CLEAR_BIT(MCUCR_REG,MCUCR_ISC00);
			CLEAR_BIT(MCUCR_REG,MCUCR_ISC01);
			break;
			
			case LOGIC_CHANGE :
			SET_BIT(MCUCR_REG,MCUCR_ISC00);
			CLEAR_BIT(MCUCR_REG,MCUCR_ISC01);
			break;
		}
		SET_BIT(GICR_REG,GICR_INT0);
		break;
		
		case EXTI_INT1 :
		switch(SenseControl)
		{
			case RISING_EDGE :
			SET_BIT(MCUCR_REG,MCUCR_ISC10);
			SET_BIT(MCUCR_REG,MCUCR_ISC11);
			break;
			case FALLING_EDGE:
			CLEAR_BIT(MCUCR_REG,MCUCR_ISC10);
			SET_BIT(MCUCR_REG,MCUCR_ISC11);
			break;
			
			case LOW_LEVEL:
			CLEAR_BIT(MCUCR_REG,MCUCR_ISC10);
			CLEAR_BIT(MCUCR_REG,MCUCR_ISC11);
			break;
			
			case LOGIC_CHANGE :
			SET_BIT(MCUCR_REG,MCUCR_ISC10);
			CLEAR_BIT(MCUCR_REG,MCUCR_ISC11);
			break;
		}
		SET_BIT(GICR_REG,GICR_INT1);
		break;
		
		
		case EXTI_INT2 :
		switch(SenseControl)
		{
			case RISING_EDGE :
			SET_BIT(MCUCSR_REG,MCUCSR_ISC2);
			break;
			case FALLING_EDGE:
			CLEAR_BIT(MCUCSR_REG,MCUCSR_ISC2);
			break;
			
		}
		SET_BIT(GICR_REG,GICR_INT2);
		break;
		
	}
}

void EXTI_voidDisable (EXTI_source InterruptSource)
{
	switch(InterruptSource)
	{
		case EXTI_INT0 :
		CLEAR_BIT(GICR_REG,GICR_INT0);
		break;
		
		case EXTI_INT1 :
		CLEAR_BIT(GICR_REG,GICR_INT1);
		break;
		
		case EXTI_INT2 :
		CLEAR_BIT(GICR_REG,GICR_INT2);
		break;
		
	}

}


static void(*INT0_PtrFunc)(void)=NULL;
static void(*INT1_PtrFunc)(void)=NULL;
static void(*INT2_PtrFunc)(void)=NULL;


void EXTI_voidSetCall_BackINT0(void(*localPtrFunc)(void))
{
	if (localPtrFunc!=NULL)
	{
		INT0_PtrFunc=localPtrFunc;
	}
	else
	{
		//return error
	}
	
}
void EXTI_voidSetCall_BackINT1(void(*localPtrFunc)(void))
{
	if (localPtrFunc!=NULL)
	{
		INT1_PtrFunc=localPtrFunc;
	}
	else
	{
		//return error
	}
	
}

void EXTI_voidSetCall_BackINT2(void(*localPtrFunc)(void))
{
	if (localPtrFunc!=NULL)
	{
		INT2_PtrFunc=localPtrFunc;
	}
	else
	{
		//return error
	}
	
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void)
{
	if(INT0_PtrFunc!=NULL)
	{
		INT0_PtrFunc();
	}
	
}
void __vector_2(void) __attribute__((signal));
void __vector_2(void)
{
	if(INT1_PtrFunc!=NULL)
	{
		INT1_PtrFunc();
	}
	
}

void __vector_3(void) __attribute__((signal));
void __vector_3(void)
{
	if(INT2_PtrFunc!=NULL)
	{
		INT2_PtrFunc();
	}
	
}

