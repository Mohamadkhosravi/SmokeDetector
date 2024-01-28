
#include "GPIO.h"


//===========================================================
//*@brief		: GPIO Init
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_GPIO_Init()
{
	_pa = 0b00000000;
	_pac= 0b00000001;
	_papu=0b00000001;
	_pawu=0b00000001;
	_pas0=0b00000000;
	_pas1=0b10010000;
	
	_pb = 0b00000000;
	_pbc= 0b00000100;
	_pbpu=0b00000100;
	_pbs0=0b01000100;
	_pbs1=0b00000000;
	
	_ifs0=0b00100010;

}








