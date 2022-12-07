

#include "stm32f4xx.h"
#include "ADC.h"
#include "gpio.h"

void ADC_init(ADCConfigType* config_parameters){
	config_parameters->resolution = twelve_bit;
	config_parameters->convrsion_mode = single; //single ,continuous
	config_parameters->ref_voltage=10;


}

void ADC_start_conv(unsigned char ChannelNum){

	RCC->APB2ENR |=(1u<<8);
	if (ChannelNum>=0 &&ChannelNum<=7){
		GPIO_Init_analoge( GPIOA, ChannelNum);
		RCC->AHB1ENR |=(1u<<0);
	}
	else if(ChannelNum==8 || ChannelNum==9){
		RCC->AHB1ENR |=(1u<<1);
		GPIO_Init_analoge( GPIOB, ChannelNum-8);
	}
	else if(ChannelNum>=10 &&ChannelNum<=14){
		RCC->AHB1ENR |=(1u<<2);
		GPIO_Init_analoge( GPIOC, ChannelNum-10);
	}
	// Enable the ADC
		ADC1->CR2 |= (1u<<0); //ADON
		ADC->CCR &=~(1u<<16); //PRESCALER
		ADC->CCR &=~(1u<<17); //PRESCLAER
		ADC1->CR2 &=~(1u<<11); //alignment
		// set the order of chanels using SQR register
		ADC1->SQR3 &=~ADC_SQR3_SQ1;
		ADC1->SQR3 |= ChannelNum;

		switch(config_parameters.convrsion_mode){
		case 1:
			ADC1->CR2 |= (1u<<1); //single
		break;
		case 0:
			ADC1->CR2 &=~ (1u<<1); //continuous
		break;
		}

		switch(config_parameters.resolution){
		case 12:
			ADC1->CR1  &=~(1u<<24); //RES
		 	ADC1->CR1 &=~(1u<<25); //RES
		break;
		case 10:
			ADC1->CR1  |=(1u<<24); //RES
		 	ADC1->CR1 &=~(1u<<25); //RES
		break;
		case 8:
			ADC1->CR1  &=~(1u<<24); //RES
		 	ADC1->CR1 |=(1u<<25); //RES
		break;
		case 6:
			ADC1->CR1 |=(1u<<24); //RES
		 	ADC1->CR1 |=(1u<<25); //RES
		break;
		}

		if(USE_POLLING==0){
			ADC1->CR1 |=(1u<<5); // enebale interrupt
			NVIC->ISER[0]|=(1u<<18);
		}

		ADC1->CR2 |= (1u<<30); //set swstart bit
}

unsigned char ADC_ReadData(unsigned short int* DataPtr){
		if(ADC1->SR &(1u<<1)){
			*DataPtr = (int)((ADC1->DR/(1.5f * 4095.0f)) * 5 * 150);
			return 0;
		}
		else
			return 1;
}







