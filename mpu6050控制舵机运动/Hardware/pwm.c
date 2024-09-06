#include "stm32f10x.h"                  // Device header

void PWM1_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);			//开启TIM2的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_1;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);	

	TIM_InternalClockConfig(TIM2);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitstructure;
	TIM_TimeBaseInitstructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitstructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitstructure.TIM_Period=20000-1;
	TIM_TimeBaseInitstructure.TIM_Prescaler=72-1;
	TIM_TimeBaseInitstructure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM2, &TIM_TimeBaseInitstructure);

	TIM_OCInitTypeDef TIM_OCInitStructure;							//定义结构体变量
	TIM_OCStructInit(&TIM_OCInitStructure);
	
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse=0;
	TIM_OC2Init(TIM2, &TIM_OCInitStructure); 
	
	TIM_Cmd(TIM2, ENABLE);

}

void PWM2_Init(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);			//开启TIM2的时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_Init(GPIOA, &GPIO_InitStructure);	

	TIM_InternalClockConfig(TIM3);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitstructure;
	TIM_TimeBaseInitstructure.TIM_ClockDivision=TIM_CKD_DIV1;
	TIM_TimeBaseInitstructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIM_TimeBaseInitstructure.TIM_Period=20000-1;
	TIM_TimeBaseInitstructure.TIM_Prescaler=72-1;
	TIM_TimeBaseInitstructure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitstructure);

	TIM_OCInitTypeDef TIM_OCInitStructure;							//定义结构体变量
	TIM_OCStructInit(&TIM_OCInitStructure);
	
	TIM_OCInitStructure.TIM_OCMode=TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OCPolarity=TIM_OCPolarity_High;
	TIM_OCInitStructure.TIM_OutputState=TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse=0;
	TIM_OC1Init(TIM3, &TIM_OCInitStructure); 
	
	TIM_Cmd(TIM3, ENABLE);
	
}


void PWM_SetCompare2(uint16_t Compare)         //pin1
{
	TIM_SetCompare2(TIM2,Compare);
}

void PWM_SetCompare1(uint16_t Compare)        //pin6
{
	TIM_SetCompare1(TIM3,Compare);
}
