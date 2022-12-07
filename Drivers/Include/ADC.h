/*
 * ADC.h
 *
 *  Created on: Jun 5, 2022
 *      Author: 10
 */

#ifndef INCLUDE_ADC_H_
#define INCLUDE_ADC_H_

#define USE_POLLING 0

typedef struct{
	enum {twelve_bit=12, ten_bit=10, eight_bit=8, six_bit = 6 } resolution;
	enum { single, continuous } convrsion_mode;
	char ref_voltage;

}ADCConfigType;

ADCConfigType config_parameters;

void ADC_init(ADCConfigType* config_parameters);

void ADC_start_conv(unsigned char ChannelNum);

void ADC_get_conversion_state(unsigned char* ConversionStatePtr);

unsigned char ADC_ReadData(unsigned short int* DataPtr);

#endif /* INCLUDE_ADC_H_ */
