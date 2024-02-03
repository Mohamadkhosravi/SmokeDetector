#include "A_SYS_FUNCTION.h"


//===========================================================
//*@brief		: 1s Timing
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_SysTimeTask(void)
{
	
	R_LONG_DELAY--;
	if(R_LONG_DELAY == 0)
	{
		R_LONG_DELAY = C_LONG_DELAY;				//122 *8.192  = 1s
		F_ONESEC = 1;
	}
}


//===========================================================
//*@brief		: Baud rate£º38400£¨Software UART£¬TX:PA0£©
//*@param[in]	: R_RS_DATA
//*@retval		: None
//===========================================================
#if _DEBUG
void S_RS232_SEND(unsigned char R_RS_DATA)
{
	asm("include BA45F5240.inc");
	asm("LOCAL	R_RS_CNT		DB		?");
	asm("LOCAL	R_RS_DATA		DB		?");
	
	asm("CLR	EMI");
	asm("MOV	R_RS_DATA,A");
	
	asm("MOV	A,8");
	asm("MOV	R_RS_CNT,A");
	P_RS_TX=0;
	#if _HIRCC_8M
		asm("MOV	A,16");
	#elif _HIRCC_4M
		asm("NOP");
		asm("MOV	A,7");
	#else
		asm("MOV	A,3");
	#endif
	asm("SDZ	ACC");
	asm("JMP	$-1");
	
asm("L_RS_SEND_LOOP:");
	asm("SZ		R_RS_DATA.0");
	asm("JMP	L_RS_SEND_1");
asm("L_RS_SEND_0:");
	asm("NOP");
	P_RS_TX=0;
	asm("JMP	L_RS_SEND_NEXT");
asm("L_RS_SEND_1:");
	P_RS_TX=1;
	asm("JMP	L_RS_SEND_NEXT");
asm("L_RS_SEND_NEXT:");
	#if _HIRCC_8M
		asm("MOV	A,14");
	#elif _HIRCC_4M
		asm("NOP");
		asm("MOV	A,5");
	#else
		asm("MOV	A,1");
	#endif
	asm("SDZ	ACC");
	asm("JMP	$-1");
	
	asm("RRC	R_RS_DATA");
	asm("SDZ	R_RS_CNT");
	asm("JMP	L_RS_SEND_LOOP");
	
	asm("JMP	$+1");
	asm("JMP	$+1");
	P_RS_TX=1;
	#if _HIRCC_8M
		asm("MOV	A,17");
	#elif _HIRCC_4M
		asm("NOP");
		asm("MOV	A,8");
	#else
		asm("MOV	A,4");
	#endif
	asm("SDZ	ACC");
	asm("JMP	$-1");
	
	asm("SET	EMI");
	
}
#endif


//===========================================================
//*@brief		: Flag Clear
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_CLR_OUTPUT(void)
{
	#if	_BUZZ
	R_BUZZ_ALARM_FG.byte = 0;
	F_BUZZ_ALARM = 0;
	_pton = 0;
	#endif
	R_LED_ALARM_FG.byte = 0;
	R_SYS_MODE_FG.byte = 0;
	LED_R=0;

}


//===========================================================
//*@brief		: Delay 5ms * R_DELAY_CNT
//*@param[in]	: R_DELAY_CNT
//*@retval		: None
//===========================================================
void S_SYS_DELAY(unsigned char R_DELAY_CNT)
{
	unsigned char i;
	for(i=0;i<R_DELAY_CNT;i++)
	{
		#if		_HIRCC_8M
			GCC_DELAY(10000);
		#elif	_HIRCC_4M
			GCC_DELAY(5000);
		#else
			GCC_DELAY(2500);
		#endif
	}
}


//===========================================================
//*@brief		: Mode Processing
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_MODE_JUDG(void)
{
	unsigned char	R_MODE_FG = 0;

	if(F_TEST == 1 || F_SM_ALARM == 1)	R_MODE_FG = 1;	//TEST OR ALARM MODE
	if(F_SM_BD_OK == 0)					R_MODE_FG = 2;	//BD ERROR MODE
	if(F_SM_BD == 1)					R_MODE_FG = 3;	//BD MODE
	if(F_SM_ERR == 1)					R_MODE_FG = 4;	//SMOKE ERROR MODE
	
	switch(R_MODE_FG)
	{
		case 4:
			S_CLR_OUTPUT();
			R_NOR_DELAY++;
			if(R_NOR_DELAY >= C_NOR_DELAY)
			{
				R_NOR_DELAY = 0;
				_LED_R_ON;
				#if _BUZZ
					_pton=1;
				#endif
				S_SYS_DELAY(15);
				#if _BUZZ
					_pton=0;
				#endif
				_LED_R_OFF;	
				S_SYS_DELAY(15);
				_LED_R_ON;
				#if _BUZZ
					_pton=1;
				#endif
				S_SYS_DELAY(15);
			}	
			break;
		case 3:
			S_CLR_OUTPUT();
			_LED_R_ON;
			break;
		case 2:
			S_CLR_OUTPUT();
			_LED_R_ON;
			break;
		case 1:
			#if	_BUZZ
				F_BUZZ_ALARM_STOP = 0;
				F_BUZZ_ALARM = 1;
			#endif
			if(F_ALARM_MODE_INI == 0)
			{
				S_CLR_OUTPUT();	
				F_ALARM_MODE_INI = 1;
				#if	_BUZZ
					F_BUZZ_ALARM = 1;
				#endif
				
				F_LED_ALARM = 1;
			}
			break;
		default:
			#if	_BUZZ
			F_BUZZ_ALARM_STOP = 1;
			if(F_BUZZ_ALARM == 0)
			{
			#endif
				if(F_NOR_MODE_INI == 0)
				{
					S_CLR_OUTPUT();
					F_NOR_MODE_INI = 1;
				}
				R_NOR_DELAY++;
				if(R_NOR_DELAY >= C_NOR_DELAY)
				{
					F_NOR_CNT_MODE = 1;
					R_NOR_DELAY = 0;
					_LED_R_ON;
					if(F_BAT_L == 1)		//LOW BATTERY MODE
					{
						#if _BUZZ
							_pton=1;
							S_SYS_DELAY(15);
						#endif
					}
				}
			#if	_BUZZ
			}
			#endif
			
			break;
	}			
	if(F_NOR_CNT_MODE == 1 || F_SM_BD == 1 ||  F_SM_ERR == 1 )
	{
		GCC_DELAY(10000);
		F_NOR_CNT_MODE = 0;
		#if	_T_REF
			if(LED_R) {
			//ntemp=T_AD;
			//read_temprature();
			//R_T_ADC=T_AD;
				 }
		#endif
		
		#if _BUZZ
			_pton=0;
		#endif
		_LED_R_OFF;
	}	
}


//===========================================================
//*@brief		: DEBUG Output
//*@param[in]	: None
//*@retval		: None
//===========================================================
#if _DEBUG
void S_DEBUG_Output(void)
{
	if(F_RS_OUT)
	{
		S_RS232_SEND(0xAA);							//0  Fixed code
		S_RS232_SEND(35);							//1  Length of the data
		S_RS232_SEND(R_SM_ZERO_DATA);				//2  SMOKE ZERO data
		S_RS232_SEND(R_SM_IR_DATA);					//3  SMOKE IR data
		S_RS232_SEND(R_SM_DATA);					//4  IR data - ZERO data
		S_RS232_SEND(R_SM_BD_ZERO);					//5  Calibration value
		S_RS232_SEND(R_SM_BD_ALARM);				//6  Calibrate the alarm threshold
		S_RS232_SEND(R_VDD_ADC[1]);					//7  
		S_RS232_SEND(R_VDD_ADC[0]);					//8  
		S_RS232_SEND(R_SYS_FG.byte);				//9  System operation mark
		S_RS232_SEND(R_SM_FG.byte);					//10 Smoke signal
		S_RS232_SEND(R_BOARD_FG.byte);				//11
		S_RS232_SEND(R_BAT_ADC);					//12 Battery AD
		S_RS232_SEND(R_T_ADC);						//13 Temperature AD
		S_RS232_SEND(R_SM_ALARM);					//14 
		S_RS232_SEND(R_SM_LIB_STATE.byte);			//15 
		S_RS232_SEND(R_VDD_RL_ADC[1]);				//16 
		S_RS232_SEND(R_VDD_RL_ADC[0]);				//17 
		S_RS232_SEND(R_BAT_CK_SPACE);				//18 
		S_RS232_SEND(R16_HUSH_DELAY);				//19 
		S_RS232_SEND(R16_HUSH_DELAY >> 8);			//20 
		
		S_RS232_SEND(_ptmrph);						//21 
		S_RS232_SEND(_ptmrpl);						//22 
		S_RS232_SEND(_ptmah);						//23 
		S_RS232_SEND(_ptmal);						//24 
		S_RS232_SEND(_ptmc1);						//25 
		S_RS232_SEND(_sda0vos);						//26 
		S_RS232_SEND(_sda1vos);						//27 
		S_RS232_SEND(_sdsw);						//28 
		S_RS232_SEND(_sdpgac0);						//29 
		S_RS232_SEND(_sdpgac1);						//30 
		S_RS232_SEND(C_BAT_LOW);					//31 
		
		S_RS232_SEND((C16_SOFT_VERSION>>8)&0xFF);	//32 Soft version
		S_RS232_SEND(C16_SOFT_VERSION&0xFF);		//33 Soft version
		S_RS232_SEND(0x55);							//34 Fixed code
	}
}
#endif