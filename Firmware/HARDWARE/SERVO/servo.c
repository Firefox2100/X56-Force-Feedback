#include "servo.h"

void TIM4_PWM_Init(u16 arr,u16 psc)
{ 
	GPIO_InitTypeDef GPIO_InitStructure;
	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
	TIM_OCInitTypeDef TIM_OCInitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);

	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB , ENABLE); 
                                                                          
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
 
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
 
	TIM_TimeBaseStructure.TIM_Period = arr;
	TIM_TimeBaseStructure.TIM_Prescaler =psc;
	TIM_TimeBaseStructure.TIM_ClockDivision = 0;
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC1Init(TIM4, &TIM_OCInitStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OC2Init(TIM4, &TIM_OCInitStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC3Init(TIM4, &TIM_OCInitStructure);

	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OCInitStructure.TIM_Pulse = 0;
	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OC4Init(TIM4, &TIM_OCInitStructure);

	TIM_OC1PreloadConfig(TIM4, TIM_OCPreload_Enable);
	TIM_OC2PreloadConfig(TIM4, TIM_OCPreload_Enable);
	TIM_OC3PreloadConfig(TIM4, TIM_OCPreload_Enable);
	TIM_OC4PreloadConfig(TIM4, TIM_OCPreload_Enable);
	TIM_ARRPreloadConfig(TIM4, ENABLE);
 
	TIM_Cmd(TIM4, ENABLE);
}

void set_servo(u8 buffer[])
{
	u16 s1, s2, s3, s4;
	
	s1 = (buffer[0] - '0') * 100 + (buffer[1] - '0') * 10 + (buffer[2] - '0');
	s1 = (buffer[4] - '0') * 100 + (buffer[5] - '0') * 10 + (buffer[6] - '0');
	s1 = (buffer[8] - '0') * 100 + (buffer[9] - '0') * 10 + (buffer[10] - '0');
	s1 = (buffer[12] - '0') * 100 + (buffer[13] - '0') * 10 + (buffer[14] - '0');
	
	TIM_SetCompare1(TIM4, s1 / 180 * 20 + 5);
  TIM_SetCompare2(TIM4, s2 / 180 * 20 + 5);
  TIM_SetCompare3(TIM4, s3 / 180 * 20 + 5);
  TIM_SetCompare4(TIM4, s4 / 180 * 20 + 5);

	
}
