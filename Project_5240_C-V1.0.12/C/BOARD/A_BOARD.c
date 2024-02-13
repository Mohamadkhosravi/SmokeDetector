#include "A_BOARD.h"



//===========================================================
//*@brief		: Clear RAM
//*@param[in]	: RAM_BANK 0/1
//*@retval		: None
//===========================================================
void S_RAM_Init(unsigned char RAM_BANK)
{
	_mp1h = RAM_BANK;
	_mp1l = C_RAM_ADDR_START;
	_acc  = C_RAM_ADDR_END-C_RAM_ADDR_START+1;
	while(_acc!=0)
	{
		_iar1=0;
		++_mp1l;
		_acc--;
	}
}


//===========================================================
//*@brief		: LED Driver
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_LED_DRV(void)
{
	static int cunter=0;
	static int flag=0;
	if(F_LED_ALARM == 1)
	{
		if(F_LED_ALARM_INI == 1)
		{
			--R_LED_ALARM_DELAY;
			if(R_LED_ALARM_DELAY == 0)
			{
				if(F_LED_HL == 0)
				{
					
			    
						F_LED_ALARM_INI = 1;
						F_LED_HL = 1;
						
					
						R_LED_ALARM_DELAY = C_LED_ALARM_DELAY_H;
					
						
						 
						  		_LED_R_ON;
					
				}
				else
				{
					F_LED_HL = 0;
					_LED_R_OFF;
					R_LED_ALARM_DELAY = C_LED_ALARM_DELAY_L;
				}
			}
		}
		else
		{
		flag=0;
			F_LED_ALARM_INI = 1;
			F_LED_HL = 1;
			_LED_R_ON;
			R_LED_ALARM_DELAY = C_LED_ALARM_DELAY_H;
		
		}
	}
}


//===========================================================
//*@brief		: SMOKE Init
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_SM_INIT(void)
{
	#if _V_CONVER
		F_V_CONVER = 1;
	#endif
	
	#if _UL_BAT_L
		F_UL_BAT_L = 1;
	#endif
	
	R_SM_BD_ZERO_MIN = C_SM_BD_ZERO_MIN;
	R_SM_BD_ZERO_MAX = C_SM_BD_ZERO_MAX;
	R_VDD_CK_SPACE_C = C_VDD_CK_SPACE;
	S_SM_INI();								//Smoke Init
}


//===========================================================
//*@brief		: Board Init
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_BOARD_INI(void)
{
	unsigned char i;
	if(_ADJUST)
	{
		i=200;
		while(i)
		{
			if(BD) break;
			--i;
		}
		if(i==0)
		{
			F_BD_DATA_DONT_SAVE=0;
			S_SM_BD_AIR();
		}
	}
	R_LONG_DELAY   = C_LONG_DELAY;
	R_SM_BD_KQ_SET = C_SM_BD_JS_ALARM;
	S_CLR_OUTPUT();
	#if _DEBUG
	#if _KEY
		if(P_KEY==0)
	#endif
			F_RS_OUT=1;
	#endif
}


//===========================================================
//*@brief		: HUSH Delay
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_HUSH_COUNT(void)
{
	if(F_HUSH==1)
	{
		R16_HUSH_DELAY++;
		if(R16_HUSH_DELAY >= C16_HUSH_DELAY)
		{
			F_HUSH = 0;
			R16_HUSH_DELAY = 0;
		}
	}
}


//===========================================================
//*@brief		: Low Voltage Detection/Internal Resistance Detection
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_BAT_CHECK(void)
{
#if _UL_BAT_L
	unsigned int R_VDD_TMP;
	unsigned int R_VDD_RL_TMP;
#endif
	if(F_SYS_SLOW)
	{
		R_BAT_CK_SPACE=R_BAT_CK_SPACE+8;
	}
	else
	{
		R_BAT_CK_SPACE++;
	}
	
	if(R_BAT_CK_SPACE>=C_BAT_CK_SPACE)
	{
		R_BAT_CK_SPACE = 0;
		R_BAT_ADC = (R_VDD_ADC[1]) << 4 | (R_VDD_ADC[0] >> 4);
		
		R_BAT_CK_SPACE = 0;
		if(R_BAT_ADC >= C_BAT_LOW)
		{
			F_BAT_L = 1;
		}
		else
		{
			#if _UL_BAT_L
			R_VDD_TMP = (unsigned int)R_VDD_ADC[1] << 8 | R_VDD_ADC[0];
			R_VDD_RL_TMP = (unsigned int)R_VDD_RL_ADC[1] << 8 | R_VDD_RL_ADC[0];
			if(R_VDD_RL_TMP > R_VDD_TMP)
			{
				if( (R_VDD_RL_TMP - R_VDD_TMP) > C16_BAT_R_CK )
				{
					F_BAT_L = 1;
				}
				else
				{
					F_BAT_L = 0;
				}
			}
			#else
				F_BAT_L = 0;
			#endif
		}
	}
}


//===========================================================
//*@brief		: SMOKE Voltage Compensation
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_V_CONVER(void)
{
	R_CACL_A_H = 0;
	R_CACL_A_L = R_CACL_A_L;
	R_CACL_B_L = C_SM_COV_VAL;
	
	S_SUR_MUL_16_8_CALC();
	
	R_CACL_A_H = R_CACL_A_H;
	R_CACL_A_L = R_CACL_A_L;
	R_CACL_B_H = 0;
	R_CACL_B_L = R_SM_TMP[0];
	
	S_SBR_DIV_16_CALC();
}


//===========================================================
//*@brief		: SMOKE Temperature Compensation
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_SM_T_REF(void)
{
	#if	_T_REF
		unsigned char i;
		
		if(R_T_ADC>=C_T_AD_ERR_L)
		{
			if(R_T_ADC<C_T_AD_DATA_L1)
			{
				i=C_T_ADD_L2;
			}
			else if(R_T_ADC<C_T_AD_DATA_L2)
			{
				i=C_T_ADD_L1;
			}
			else if((R_T_ADC>C_T_AD_DATA_L3)&&(R_T_ADC<C_T_AD_DATA_L4))
			{
				i=C_T_SUB_L1;
			}
			else if((R_T_ADC>C_T_AD_DATA_L4)&&(R_T_ADC<C_T_AD_ERR_H))
			{
				i=C_T_SUB_L2;
			}
			else
			{
				return;
			}
			
			if(R_T_ADC<C_T_AD_DATA_L2)
			{
				R_SM_ALARM = R_SM_ALARM + i;
				if(_c)
				{
					R_SM_ALARM = 255;
				}
			}
			else if(R_T_ADC>C_T_AD_DATA_L3 || R_T_ADC<C_T_AD_ERR_H)
			{
				R_SM_ALARM = R_SM_ALARM - i;
			}
			if(R_SM_ALARM<=C_SM_ALARM_DATA_L) 
			{
				R_SM_ALARM=C_SM_ALARM_DATA_L;
			}
		}
#endif
}


//===========================================================
//*@brief		: Write EEPROM
//*@param[in]	: WR_EE_addr£¬WR_EE_data
//*@retval		: None
//===========================================================
void S_WR_EE(unsigned char WR_EE_addr,unsigned char WR_EE_data)
{
	_emi=0;
	_eea=WR_EE_addr;
	_eed=WR_EE_data;
	_mp1l=0x40;
	_mp1h=0x01;
	_iar1=_iar1|0b00001000;
	_iar1=_iar1|0b00000100;
	while(_iar1&0b00000100);
	_iar1=0x00;
	_mp1h=0x00;
	_emi=1;
}
