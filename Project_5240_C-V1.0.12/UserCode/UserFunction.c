#include "BA45F5240.h"
#include "A_USE_MACRO.h"
#include "UserFunction.h"
#include "A_VAL_DEFINE.h"
#include "ADC.h"
#include "PLT.h"
#include  "stdlib.h"
#include "A_SYS_FUNCTION.h"
#include "A_SOFTDEBUG_DRV.h"
#include <time.h>
bit F_NO_SLEEP;	//If you don¡¯t want the MCU to go to sleep/standby mode, set this bit.
bit resetMcu=0;

//===========================================================
//*@brief		: User init function
//*@param[in]	: None
//*@retval		: None
//*@note		: Run once at power on
//===========================================================
void S_USER_INIT()
{
	//USER INIT CODE START
	unsigned long int randomDelay=0;
	unsigned int i;
    resetMcu=1;
//*********************************************************
	_pac3=1;
    _pas07=1;
    _pas06=1;
   // S_STM_Init();
   // _ston=1;
    // S_SFUART_SEND((_stmdl)|(_stmdh<<8));
    S_SYS_DELAY(100);
    srand(S_READ_ADC(3));//read adc3 and pass to random input	
    S_SYS_DELAY(100);
//	S_SFUART_SEND(0x0a);
//	S_SFUART_SEND(rand());
   for (i=0;i<=(rand()*10)+1000;i++)
   {
	GCC_CLRWDT();
	GCC_DELAY(1500);
	GCC_CLRWDT();
	GCC_DELAY(1500);
	GCC_CLRWDT();
	GCC_DELAY(1500);
	GCC_CLRWDT();
	GCC_DELAY(1500);
	GCC_CLRWDT();
	GCC_DELAY(1500);
     // S_SFUART_SEND(i);
   }


  //  S_SFUART_SEND(rand());

	   
	_pac3=0;
    _pas07=0;
    _pas06=0; 

	//*********************************************************
	
	//USER INIT CODE END
	return;
}





//===========================================================
//*@brief		: User 8ms work period function
//*@param[in]	: None
//*@retval		: None
//*@note		: Run once every 8ms. If MCU in sleep/standby mode, it will not run.
//===========================================================
void S_USER_8MS_WORK_PERIOD()
{
	//USER 8ms CODE START
	
	
	
	//USER 8ms CODE END
	return;
}





//===========================================================
//*@brief		: User 1s work period function
//*@param[in]	: None
//*@retval		: None
//*@note		: If in sleep/standby mode, it runs once every work cycle. If in fast mode, run once every 1s.
//===========================================================
void S_USER_1S_WORK_PERIOD()
{
	//USER 1s CODE START
	   	  //	S_SFUART_SEND(0x0a);
		//	S_SFUART_SEND(F_SYS_SLOW+0x30);
			//S_SFUART_SEND(0x0a);
		
	
	if((R_LED_ALARM_DELAY)&&(F_LED_HL))
	{
		
		while(1)
		{
			F_LED_HL = 0;
			_LED_R_ON;
			R_LED_ALARM_DELAY = C_LED_ALARM_DELAY_L;
			GCC_CLRWDT();
			if(PLT0Recive()==0)break;
		
				
		}
	}
	
   // S_SFUART_SEND(0x0a);
 //   S_SFUART_SEND(PLT0Recive()+0x30);
    while(PLT0Recive()==0)
    { 
    	_LED_R_OFF;
    /*	S_SFUART_SEND(0x0a);
		S_SFUART_SEND(PLT0Recive()+0x30);*/
		GCC_CLRWDT();
       	
    }
	
	//USER 1s CODE END
	return;
}


