/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "gpio.h"
#include "LCD.h"
#include "ADC.h"
			
unsigned short int tempreture =0;
int main(void)
{

	LCD_Init();
	GPIO_Init(GPIOA,7,1,0);// debugging
	ADC_init(&config_parameters);
	ADC_start_conv(5);


	while(1)
	{

		if(USE_POLLING == 1){
			if(ADC1->SR &(1u<<1)){
				LCD_ClearScreen();
				for(int i=0 ; i<200000;i++){}
				ADC_ReadData(&tempreture);
				GPIO_Write(GPIOA,7,1);// debugging
				LCD_IntToStr(tempreture);
				for(int i=0 ; i<200000;i++){}
				GPIO_Write(GPIOA,7,0);// debugging
				}
			}

	}
}



void ADC_IRQHandler(void){
		LCD_ClearScreen();
		ADC_ReadData(&tempreture);
		for(int i=0 ; i<200000;i++){}
		GPIO_Write(GPIOA,7,1);// debugging
		LCD_IntToStr(tempreture);

		for(int i=0 ; i<200000;i++){}
		GPIO_Write(GPIOA,7,0);// debugging
		ADC1->CR2 |= (1u<<30);

}
