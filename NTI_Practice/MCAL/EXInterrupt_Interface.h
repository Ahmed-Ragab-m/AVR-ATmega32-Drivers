

#ifndef EXINTERRUPT_INTERFACE_H_
#define EXINTERRUPT_INTERFACE_H_

typedef enum
{
	EXTI_INT0 = 0,
	EXTI_INT1,
	EXTI_INT2
}EXTI_source;

typedef enum
{
	RISING_EDGE =0 ,
	FALLING_EDGE,
	LOW_LEVEL  ,
	LOGIC_CHANGE

}EXTI_senseControl;


void EXTI_voidEnable (EXTI_source InterruptSource,EXTI_senseControl SenseControl);

void EXTI_voidDisable (EXTI_source InterruptSource);

void EXTI_voidSetCall_BackINT0(void(*localPtrFunc)(void));

void EXTI_voidSetCall_BackINT1(void(*localPtrFunc)(void));

void EXTI_voidSetCall_BackINT2(void(*localPtrFunc)(void));


#endif /* EXINTERRUPT_INTERFACE_H_ */