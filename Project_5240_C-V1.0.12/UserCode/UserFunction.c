#include "BA45F5240.h"
#include "A_USE_MACRO.h"
#include "UserFunction.h"
#include "A_VAL_DEFINE.h"
#include "PLT.h"
#include "A_BOARD.h"
#include "A_SYS_FUNCTION.h"
#include "A_SOFTDEBUG_DRV.h"

bit F_NO_SLEEP;	//If you don¡¯t want the MCU to go to sleep/standby mode, set this bit.

void print(unsigned int number);
//===========================================================
//*@brief		: User init function
//*@param[in]	: None
//*@retval		: None
//*@note		: Run once at power on
//===========================================================
void S_USER_INIT()
{
	//USER INIT CODE START

	
//*********************************************************


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
	static char plt0=0;
	static unsigned int counterPLT=0;
	int i=0;
	//when detect fire wait here ; if power voltage (PLT) is low power led off and reset fire state 

	if(F_LED_ALARM == 1){

     	while(1)
		{	
		 _LED_R_ON;	
		 _pb1=1;
		 GCC_CLRWDT();
		 if(PLT0Recive()==0) {plt0=1; break;}
		}	
		 _pb1=0;					
	}
/*	if((PLT0Recive()==0)&&(PLT1Recive()==0))*/
	if((PLT0Recive()==0))
	{ 	
	  plt0=1;			
	}
	
    if(plt0)
	{
	  
  		while(1)
  		{
			_LED_R_OFF;
			GCC_CLRWDT();
			/*if((PLT0Recive())&&(PLT1Recive()))*/
			if(PLT1Recive())
			{
		 	  counterPLT++;	
			}
			else
			{
			  if(counterPLT>0)counterPLT--;	
			}	
	        
		  	if(counterPLT>20){
		  		plt0=0;
		  		counterPLT=0;
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
				S_MODE_JUDG();	
				break;
			}
		   
			
	  
        }
      
      
    }			
	
	//USER 1s CODE END
	return ;
}


void print(unsigned int number){//send ascii number data over uart 
	unsigned int lastNumber = number;
	unsigned char len = 0;
	unsigned int pow = 1;
	unsigned int digit = 0;
	
	S_SFUART_SEND(0x0a);
	if (lastNumber<=0){
	S_SFUART_SEND(0+30);
	S_SFUART_SEND(0x0a);	
		return 0;}
	while (lastNumber > 0)
	{
		len++;    
		pow = pow * 10;
		lastNumber = lastNumber / 10;    
	}
	pow = pow / 10;
	lastNumber = number;
	while (1)
	{
		len--;
		digit = lastNumber / pow;
		lastNumber = lastNumber - (digit * pow);
		S_SFUART_SEND(digit + 0x30);
		pow = pow / 10;
		if (len == 0) break;   
	
	}
	
	S_SFUART_SEND(0x0a);
}	