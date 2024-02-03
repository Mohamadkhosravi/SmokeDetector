#include "ADC.h"


//===========================================================
//*@brief		: ADC Init
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_ADC_Init()
{
	_sadc0=0b00000111;
	_sadc1=0b01101011;
	_ade = 0;
}


//===========================================================
//*@brief		: Read ADC
//*@param[in]	: ADC channel:AN0、AN1、AN2、AN3、VBGREF、OPA0O、OPA1O、LINEV
//*@retval		: AD Value
//===========================================================
unsigned int S_READ_ADC(unsigned char CH)
{
	unsigned int temp;
	
	switch(CH)
	{
		case 0:
			_RD_ADC_SET_AN0
			break;
		case 1:
			_RD_ADC_SET_AN1
			break;
		case 2:
			_RD_ADC_SET_AN2
			break;
		case 3:
			_RD_ADC_SET_AN3
			break;
		case 4:
			_RD_ADC_SET_VBGREF
			break;
		case 5:
			_RD_ADC_SET_OPA0O
			break;
		case 6:
			_RD_ADC_SET_OPA1O
			break;
		case 7:
			_RD_ADC_SET_LINEV
			break;
		default:
			break;
	}
	
	_adcen=1;
	GCC_DELAY(12);
	_start=0;
	_start=1;
	_start=0;
	while(_adbz);
	_adcen=0;
	temp=_sadoh;
	if(_adrfs!=0)
	{
		temp=(temp<<8)|_sadol;
	}
	
	return temp;
}



