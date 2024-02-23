#include "stm32f10x.h"                  // Device header


/**
  * @brief  初始化与LED连接的gpio
  * @param  GPIO：GPIO连接的总线
  *			Pin：需要初始化的引脚
  * @retval None
  */
void LED_Init(uint32_t GPIO,uint16_t Pin)//led初始化
{ 
	RCC_APB2PeriphClockCmd(GPIO,ENABLE);//使能时钟
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Pin = Pin;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init (GPIOA,&GPIO_InitStructure);   
}

/**
  * @brief  改变LED的状态
  * @param  Sta：1或0，1为点亮led，0为熄灭
  *			GPIOx：GPIO组
*			Pin：哪个引脚上的LED
  * @retval None
  */
void LED_Ctrl(uint8_t Sta,GPIO_TypeDef* GPIOx,uint16_t Pin)
{
	if(Sta==1)
	{
		GPIO_ResetBits(GPIOx,Pin);
	}
	else 
	{
		GPIO_SetBits(GPIOx,Pin);
	}

}
