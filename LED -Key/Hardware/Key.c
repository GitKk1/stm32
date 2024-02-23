#include "stm32f10x.h"                  // Device header
#include "Delay.h"


/**
  * @brief  初始化与按键连接的gpio
  * @param  GPIO：gpio连接的总线
  *			Pin：需要初始化的引脚
  * @retval None
  */
void Key_Init(uint32_t GPIO,uint16_t Pin)
{
	RCC_APB2PeriphClockCmd(GPIO,ENABLE);//使能时钟
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;//上拉输入模式
	GPIO_InitStructure.GPIO_Pin = Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	
	GPIO_Init (GPIOB,&GPIO_InitStructure);   
}

/**
  * @brief  初始化与按键连接的GPIO
  * @param  None
  * @retval 按键判定值
  */
uint8_t Key_Judge()
{
	uint8_t Judge_Num=0;
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)==0)
	{
		Delay_ms(20);
		while((GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_11)==0));
		Delay_ms(20);
		Judge_Num=1;
	}
	else if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0)
	{
		Delay_ms(20);
		while((GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_1)==0));
		Delay_ms(20);
		Judge_Num=2;
	}
	
	return Judge_Num ;
}
