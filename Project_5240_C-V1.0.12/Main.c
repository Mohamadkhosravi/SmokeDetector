//=============================================================================================================
//*File Name	: MAIN.c
//*Code Version	: V1.0
//*MCU			: BA45F5240
//*Company		: Anchip Electronic Technology (Dongguan) Co., Ltd.
//=============================================================================================================

#include "BA45F5240.h"
#include "A_USE_MACRO.h"
#include "ADC.h"
#include "RCC.h"
#include "AFE.h"
#include "GPIO.h"
#include "TM.h"
#include "A_USE_LIB.h"

#if _SPI_DRIVER
	#include "SPI.h"
#elif _IIC_DRIVER
	#include "IIC.h"
#elif _UART_DRIVER
	#include "UART.h"
#endif

#include "A_USE_LIB.h"
#include "A_BOARD.h"
#include "A_KEY_DRV.h"
#include "A_VAL_DEFINE.h"
#include "A_SYS_FUNCTION.h"
#include "A_SOFTDEBUG_DRV.h"
#include "UserFunction.h"
#include "UserISR.h"
#include "PLT.h"





void main()
{
	if(_to==0 || _pdf==0)
	{
		S_RAM_Init(0);			//Clear RAM0
		S_RAM_Init(1);			//Clear RAM1
		S_GPIO_Init();			//IO Init
		S_RCC_Init();			//System Clock Init
		S_OPA_Init();			//OPA Init
		S_PTM_Init();			//PTM Init
		S_STM_Init();			//STM Init
		S_SM_INIT();			//SMOKE Init
		S_BOARD_INI();
		#if _KEY
			S_KEY_Init();		//Key Init
		#endif
		#if _SPI_DRIVER
			S_SPI_Init();
		#elif _IIC_DRIVER
			S_IIC_Init();
		#elif _UART_DRIVER
			S_UART_Init();
		#endif
		#if _SOFTDEBUG
			S_SFUART_Init();	//Soft Debug Init
		#endif
		//USER CODE START
		S_USER_INIT();
		//USER CODE END
		S_Timebase_Init();		//Timebase Init
		
		_LED_R_ON;
		#if _BUZZ
			_pton=1;
		#endif
		S_SYS_DELAY(30);
		#if _T_REF
			R_T_ADC = T_AD;
		#endif
		
		#if _BUZZ
			_pton=0;
		#endif
		_LED_R_OFF;
		
	}


	while(1)
	{
		#if _KEY
			S_KEY_UPDATE();						//key scan
			S_KEY_PROCESS();					//key process
		#endif
		GCC_CLRWDT();
	/*	ntemp=T_AD;
		read_temprature();*/
		
		
		
		/*	if((F_LED_ALARM == 1)){
	
			   
	         	while(1)
				{
				 _LED_R_ON;	
				 GCC_CLRWDT();
				  plt=PLT0Recive();
			  	S_SFUART_SEND(0x46);
				S_SFUART_SEND(plt+0x30);
				 if(plt==0){ _LED_R_OFF;	break;}
				}
			}*/
		   /* if(!PLT0Recive())
			{ 
		    	while(1){
					_LED_R_OFF;
					S_SFUART_SEND(0x46);
					S_SFUART_SEND(0x0a);
					S_SFUART_SEND(PLT0Recive()+0x30);
					GCC_CLRWDT();
					F_LED_ALARM =0;
			    	F_TIMER=0;
				}
				
			}	*/
		
			/*	S_SFUART_SEND(0x0a);
				S_SFUART_SEND(0x45);
				S_SFUART_SEND(PLT0Recive()+0x30);
				S_SFUART_SEND(0x0a);*/
		
		if(F_SYS_SLOW)
		{
			GCC_CLRWDT();
		}
		else if(F_TIMER)
		{
			F_TIMER=0;
			S_SysTimeTask();
			S_LED_DRV();							//led driver
			#if _BUZZ
				S_BUZZ_DRV();						//led driver
			#endif
		/*	#if _SOFTDEBUG
				if(R_UART_RUNCNT!=0)
				{
					R_UART_RUNCNT--;
				}
			#endif*/
			//USER CODE START
			S_USER_8MS_WORK_PERIOD();
			//USER CODE END
		}
		if( F_ONESEC!=0 || F_SYS_SLOW!=0 )
		{
			F_ONESEC=0;
			S_HUSH_COUNT();
			S_READ_SMOKE_DATA();					//READ SMOKE AD
			S_SM_BD_ZERO();							//SMOKE BD
			S_SM_BD_ALARM();
			#if _CHECK_IR_ERR
				S_SM_IR_ERR_CHECK();				//SMOKE ERROR CHECK
			#endif
			S_SM_ALARM_CHECK();						//SMOKE ALARM CHECK
			S_BAT_CHECK();							//LOW BATTERY CHECK
			S_MODE_JUDG();							//MCU mode processing
			//USER CODE START
			S_USER_1S_WORK_PERIOD();
			//USER CODE END
		/*	
			#if _DEBUG
				S_DEBUG_Output();
			#endif
			#if _SOFTDEBUG
				S_SFUART_DEAL(R_SFUART_RXDAT);
				S_SOFTDEBUG_Output();				//smoke detector workshop debug data output
			#endif*/
			
			F_SYS_SLOW = 0;
			#if _KEY
			if(!R_KEY_ISCHANGE.byte)
			{
			#endif
				F_SYS_WMODE=0;
				
				if(F_TEST)				F_SYS_WMODE = 1;
				if(F_SM_BD)				F_SYS_WMODE = 1;
				if(!F_SM_BD_OK)			F_SYS_WMODE = 1;
				if(F_LED_ALARM)			F_SYS_WMODE = 1;
				if(F_SM_ALARM)			F_SYS_WMODE = 1;
				if(F_SM_PRE_ALARM)		F_SYS_WMODE = 1;
				if(F_HUSH)				F_SYS_WMODE = 1;
				
				#if _BUZZ
					if(F_BUZZ_ALARM)	F_SYS_WMODE = 1;
				#endif
				
				#if _SOFTDEBUG
					if(R_UART_RUNCNT)	F_SYS_WMODE = 1;
				#endif
				
				#if _NO_SLEEP
					F_SYS_WMODE=1;
				#endif
				//USER CODE START
				if(F_NO_SLEEP)			F_SYS_WMODE = 1;
				//USER CODE END
				if(!F_SYS_WMODE)
				{
					F_SYS_SLOW = 1;
					R_LONG_DELAY = C_LONG_DELAY;
					_fhiden = 0;
					_fsiden = 0;
					_halt();
				}
				else
				{
					_fhiden = 1;
					_fsiden = 1;
					_halt();
				}
			#if _KEY
			}
			#endif
		}
	}
}


//===========================================================
//*@brief	: 8ms tb1 is used to control the program cycle.
//===========================================================
DEFINE_ISR(TB1_ISR,0x34)
{
	F_TIMER=1;
}


//===========================================================
//*@brief	: smoke detector workshop debugging processing function,INT1 used.
//===========================================================
#if _SOFTDEBUG
DEFINE_ISR(INT1_ISR,0x0C)
{
	_int1e=0;
	R_UART_RUNCNT=15;
	S_SFUART_RXINT();
	_int1f=0;
	_int1e=1;
}
#endif




