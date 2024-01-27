#include "AFE.h"
#include "A_SET_PARAM.h"
#include "A_USE_LIB.h"


//===========================================================
//*@brief		: Adjust OPA0
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_ADJ_OPA0(void)
{
	unsigned char R_TMP0,R_TMP1;
	R_TMP0 = 0x00;
	R_TMP1 = 0x00;
	_sda0vos=0b11111111;
	GCC_DELAY(2000);
	while(_sda0o)
	{
		_sda0vos--;
		GCC_DELAY(2000);
	}
	R_TMP0=_sda0vos & 0b00111111;
	_sda0vos=0b11000000;
	GCC_DELAY(2000);
	while(!_sda0o)
	{
		_sda0vos++;
		GCC_DELAY(2000);
	}
	R_TMP1=_sda0vos & 0b00111111;
	_sda0vos=(R_TMP0+R_TMP1)/2;

}


//===========================================================
//*@brief		: Adjust OPA1
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_ADJ_OPA1(void)
{
	unsigned char R_TMP0,R_TMP1;
	R_TMP0 = 0x00;
	R_TMP1 = 0x00;
	_sda1vos = 0b11111111;
	GCC_DELAY(2000);
	while(_sda1o)
	{
		_sda1vos--;
		GCC_DELAY(2000);
	}
	R_TMP0=_sda1vos & 0b00111111;
	_sda1vos=0b11000000;
	GCC_DELAY(2000);
	while(!_sda1o)
	{
		_sda1vos++;
		GCC_DELAY(2000);
	}
	R_TMP1=_sda1vos & 0b00111111;
	_sda1vos=(R_TMP0+R_TMP1)/2;
}


//===========================================================
//*@brief		: OPA Init
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_OPA_Init()
{
	R_ISINK0_VALUE = C_TX0_POWER;
	R_ISINK1_VALUE = C_TX1_POWER;
	R_ISINK0_DELAY = C_ISINK0_DELAY;
	R_ISINK1_DELAY = C_ISINK1_DELAY;
	R_OPA_DELAY    = C_OPA_DELAY;
	R_INTERRESIST_DELAY = C_INTERRESIST_DELAY;
	_isgdata0 = R_ISINK0_VALUE;
	_isgdata1 = R_ISINK1_VALUE;
	_sdpgac0  = C_AFE_R1;
	_sdpgac1  = (C_AFE_R3<<6)+C_AFE_R2;
	_sda0c = 0b01000011;
	_sda1c = 0b01000011;
	_sdsw  = 0b01110111;
	
	S_ADJ_OPA0();
	S_ADJ_OPA1();
}


//===========================================================
//*@brief		: Open ISINK0
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_SM_ISINK0_ON()
{
	_isgdata0 = R_ISINK0_VALUE;
	_isgen=1;
	_isgs0=1;
}


//===========================================================
//*@brief		: Open ISINK1
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_SM_ISINK1_ON()
{
	_isgdata1 = R_ISINK1_VALUE;
	_isgen=1;
	_isgs1=1;
}


//===========================================================
//*@brief		: Close ISINK0
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_SM_ISINK0_OFF()
{
	_isgen=0;
	_isgs0=0;
}


//===========================================================
//*@brief		: Close ISINK1
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_SM_ISINK1_OFF()
{
	_isgen=0;
	_isgs1=0;
}


//===========================================================
//*@brief		: Open OPA
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_SM_OPA_ON(void)
{
	_sda0en = 1;
	_sda1en = 1;
	_sds0   = 1;
}


//===========================================================
//*@brief		: Close OPA
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_SM_OPA_OFF(void)
{
	_sda0en = 0;
	_sda1en = 0;
	_sds0   = 0;
}


//===========================================================
//*@brief		: Open ISINK0 Delay
//*@param[in]	: None
//*@retval		: None
//*@note		: R_ISINK0_DELAY*50us
//===========================================================
void S_SM_TX0_DELAY(void)
{
	unsigned char i;
	for(i=0;i<R_ISINK0_DELAY;i++)
	{
		#if _HIRCC_8M
			GCC_DELAY(93);
		#elif _HIRCC_4M
			GCC_DELAY(43);
		#else
			GCC_DELAY(18);
		#endif
	}
}


//===========================================================
//*@brief		: Open ISINK1 Delay
//*@param[in]	: None
//*@retval		: None
//*@note		: R_ISINK1_DELAY*50us
//===========================================================
void S_SM_TX1_DELAY(void)
{
	unsigned char i;
	for(i=0;i<R_ISINK1_DELAY;i++)
	{
		#if _HIRCC_8M
			GCC_DELAY(93);
		#elif _HIRCC_4M
			GCC_DELAY(43);
		#else
			GCC_DELAY(18);
		#endif
	}
}


//===========================================================
//*@brief		: Open OPA Delay
//*@param[in]	: None
//*@retval		: None
//*@note		: R_OPA_DELAY*100us
//===========================================================
void S_OPA_STATIME(void)
{
	unsigned char i;
	for(i=0;i<R_OPA_DELAY;i++)
	{
		#if _HIRCC_8M
		GCC_DELAY(193);
		#elif _HIRCC_4M
		GCC_DELAY(93);
		#else
		GCC_DELAY(43);
		#endif
	}
}	


//===========================================================
//*@brief		: Delay of internal resistance detection
//*@param[in]	: None
//*@retval		: None
//*@note		: R_INTERRESIST_DELAY*10us
//===========================================================
void S_BAT_CK_DELAY(void)
{
	unsigned char i;
	#if _HIRCC_8M
	for(i=0;i<R_INTERRESIST_DELAY;i++)
	{
		GCC_DELAY(13);
	}
	#elif _HIRCC_4M
	for(i=0;i<R_INTERRESIST_DELAY;i++)
	{
		GCC_DELAY(3);
	}
	#else
	i=R_INTERRESIST_DELAY;
	while(i--)
	{
		GCC_NOP();
	}
	#endif
}


