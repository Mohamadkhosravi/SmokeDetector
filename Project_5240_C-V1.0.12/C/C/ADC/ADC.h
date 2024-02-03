#ifndef ADC_H__
#define ADC_H__
#include "BA45F5240.h"

//The macro definition cannot be changed
#define AN0			0x00
#define AN1			0X01
#define AN2			0X02
#define AN3			0X03
#define VBGREF		0X04
#define OPA0O		0X05
#define OPA1O		0X06
#define LINEV		0X07


#define _RD_ADC_SET_AN0		{ _sadc1 = 0b00000011; _sadc0 = 0b00000000; }

#define	_RD_ADC_SET_AN1     { _sadc1 = 0b00001001;_sadc0 = 0b00000001; }

#define _RD_ADC_SET_AN2		{ _sadc1 = 0b00000011; _sadc0 = 0b00000010; }

#define _RD_ADC_SET_AN3		{ _sadc1 = 0b00000011; _sadc0 = 0b00000011; }

#define _RD_ADC_SET_VBGREF	{ _sadc1 = 0b00101011; _sadc0 = 0b00010111; }

#define _RD_ADC_SET_OPA0O	{ _sadc1 = 0b01000011; _sadc0 = 0b00000111; }

#define _RD_ADC_SET_OPA1O	{ _sadc1 = 0b01101011; _sadc0 = 0b00000111; }

#define _RD_ADC_SET_LINEV	{ _sadc1 = 0b10000011; _sadc0 = 0b00000111; }

//The function name is defined by the user tag
#define		ADC_ON		{_adcen=1;}
#define		ADC_OFF		{_adcen=0;}

void S_ADC_Init();
unsigned int S_READ_ADC(unsigned char CH);






#endif
