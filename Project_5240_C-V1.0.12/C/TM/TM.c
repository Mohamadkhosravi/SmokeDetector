#include "A_USE_MACRO.h"
#include "TM.h"


//===========================================================
//*@brief		: PTM Init
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_PTM_Init()
{
#if _BUZZ
	S_BUZZ_Init();
#else
	_ptmc0=0b00000000;
	_ptmc1=0b00000000;
	_ptmrpl=0x00;
	_ptmrph=0x00;
	_ptmal=0X00;
	_ptmah=0X00;
	
	_ptmae=0;
	_ptmpe=0;
#endif

}


//===========================================================
//*@brief		: BUZZ Init
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_BUZZ_Init(void)
{
	#if _HIRCC_8M
		#if (C16_BUZZ_SET_WIDTH<2000)
			_ptmc0=0b00100000;
		#else
			_ptmc0=0b00000000;
		#endif
	#else
		_ptmc0=0b00000000;
	#endif
	_ptmc1=0b10101000;
	_ptmrpl=(unsigned char)C16_BUZZ_WIDTH;
	_ptmrph=C16_BUZZ_WIDTH>>8;
	_ptmal=(unsigned char)C16_BUZZ_DUTY;
	_ptmah=C16_BUZZ_DUTY>>8;
}


//===========================================================
//*@brief		: STM Init
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_STM_Init()
{
	_stmc0=0b00010000; 
	_stmc1=0b11000000;
	_stmal=0x00;
	_stmah=0x02;
	
	_stmae=0;
	_stmaf=0;
	
	_stmpe=0;
	_stmpf=0;
}


//===========================================================
//*@brief		: BUZZ Driver
//*@param[in]	: None
//*@retval		: None
//===========================================================
#if _BUZZ
void S_BUZZ_DRV(void)
{
	if(F_BUZZ_ALARM == 1)
	{
		if(F_BUZZ_ALARM_INI == 0)
		{
			R_BUZZ_ALARM_CNT = C_BUZZ_ALARM_CNT;
			R_LONG_DELAY = C_LONG_SP_DELAY;
			F_BUZZ_ALARM_INI = 1;
			
			F_BUZZ_ALARM_HL = 1;
			R_BUZZ_ALARM_DELAY = C_BUZZ_ALARM_DELAY_H;
			if(F_TEST == 1 || F_HUSH == 0)
			{
				_pton=1;
			}
		}
		else
		{
			--R_BUZZ_ALARM_DELAY;
			if(R_BUZZ_ALARM_DELAY == 0)
			{
				if(F_BUZZ_ALARM_HL == 0)
				{
					F_BUZZ_ALARM_HL = 1;
					R_BUZZ_ALARM_DELAY = C_BUZZ_ALARM_DELAY_H;
					
					if(F_TEST == 1 || F_HUSH == 0)
					{
						_pton=1;
					}
				}
				else
				{
					F_BUZZ_ALARM_HL = 0;
					R_BUZZ_ALARM_DELAY = C_BUZZ_ALARM_DELAY_L;
					_pton=0;
					--R_BUZZ_ALARM_CNT;
					if(R_BUZZ_ALARM_CNT == 0)
					{
						R_BUZZ_ALARM_CNT = C_BUZZ_ALARM_CNT;
						R_BUZZ_ALARM_DELAY = C_BUZZ_ALARM_DELAY_LONG;
						
						if(F_BUZZ_ALARM_STOP == 1)
						{
							R_BUZZ_ALARM_FG.byte = 0;
						}
					}
				}
			}
		}
	}
}
#endif




