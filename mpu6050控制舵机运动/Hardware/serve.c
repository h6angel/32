#include "stm32f10x.h"                  // Device header
#include"pwm.h"

void serve_init(void)
{

	PWM1_Init();
	PWM2_Init();
	
}


void serve_setangels1(float angle)        //pin6的舵机
{
	PWM_SetCompare1(angle/180*2000+500);
}


void serve_setangels2(float angle)                //pin1的舵机
{
	PWM_SetCompare2(angle/180*2000+500);
}
