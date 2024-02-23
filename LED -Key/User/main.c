#include "stm32f10x.h"                  // Device header
#include "Delay.h"
#include "LED.h"
#include "Key.h"

int main(void)
{	
	int Key_Sta=0;
	LED_Init(RCC_APB2Periph_GPIOA,0x000e);//对led口初始化
	Key_Init(RCC_APB2Periph_GPIOB,0x08ff);//对按键初始化
	
	LED_Ctrl(0,GPIOA,GPIO_Pin_1);//led全灭
	LED_Ctrl(0,GPIOA,GPIO_Pin_2);	

	while(1)
	{ 	
		Key_Sta = Key_Judge();
		if(Key_Sta ==1) 	//按键按下
		{
			LED_Ctrl(1,GPIOA,GPIO_Pin_1);
			LED_Ctrl(0,GPIOA,GPIO_Pin_2);
			Key_Sta =0;
		}
		if(Key_Sta ==2)
		{
			LED_Ctrl(1,GPIOA,GPIO_Pin_2);
			LED_Ctrl(0,GPIOA,GPIO_Pin_1);
			Key_Sta =0;
		}
	}
}
