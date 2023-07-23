#include "stm32f4xx.h"
#include "stm32f4xx_tim.h"

void gpioConfig(){
	GPIO_InitTypeDef	GPIOInitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB,ENABLE);

	GPIOInitStructure.GPIO_Mode=GPIO_Mode_OUT;
	GPIOInitStructure.GPIO_OType=GPIO_OType_PP;
	GPIOInitStructure.GPIO_Pin=GPIO_Pin_0;
	GPIOInitStructure.GPIO_PuPd=GPIO_PuPd_NOPULL;
	GPIOInitStructure.GPIO_Speed=GPIO_Speed_100MHz;
	GPIO_Init(GPIOB,&GPIOInitStructure);
}
void timerConfig(){
	TIM_TimeBaseInitTypeDef	TIMERInitStructure;
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM6,ENABLE);

	TIMERInitStructure.TIM_ClockDivision=1;
	TIMERInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
	TIMERInitStructure.TIM_Period=3999;
	TIMERInitStructure.TIM_Prescaler=5999;
	TIMERInitStructure.TIM_RepetitionCounter=0;
	TIM_TimeBaseInit(TIM6,&TIMERInitStructure);
	TIM_Cmd(TIM6,ENABLE);
}
uint16_t counter=0;
int main(void){
  gpioConfig();
  timerConfig();

  while (1){
	  counter=TIM_GetCounter(TIM6);
	  if(counter==1999){
		  GPIO_SetBits(GPIOB,GPIO_Pin_0);
	  }
	  else if (counter==3999){
		  GPIO_ResetBits(GPIOB,GPIO_Pin_0);
	  }

  }
}
