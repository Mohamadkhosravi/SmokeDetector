#include "BA45F5240.h"
#include "A_USE_MACRO.h"
#include "UserFunction.h"
#include "A_VAL_DEFINE.h"
#include "PLT.h"
#include "A_BOARD.h"
#include "A_SYS_FUNCTION.h"
#include "A_SOFTDEBUG_DRV.h"

bit F_NO_SLEEP;	//If you don¡¯t want the MCU to go to sleep/standby mode, set this bit.


//===========================================================
//*@brief		: User init function
//*@param[in]	: None
//*@retval		: None
//*@note		: Run once at power on
//===========================================================
void S_USER_INIT()
{
	//USER INIT CODE START
	
	
	
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



char read_temprature(char temp_ADC  ){
	
static int r=0;	
static const unsigned char temprature1_250table[120]=
{
61,64,66,69,71,74,77,79,82,85,88,
91,93,96,99,102,105,108,111,114,117,119,
122,125,128,131,134,137,139,142,145,147,150,
153,155,158,160,163,165,167,170,172,174,176,
179,181,183,185,187,189,190,192,194,196,197,
199,201,202,204,205,207,208,209,211,212,213,
214,216,217,218,219,220,221,222,223,224,225,
226,226,227,228,229,230,230,231,232,232,233,
234,234,235,235,236,237,237,238,238,239,239,
239,240,240,241,241,242,242,242,243,243,243
};
		_pa2=1;
//	temp_ADC=ntemp; 

	for(r=0 ; r<115;r++)
	{
	
		if(temprature1_250table[r] > temp_ADC ){break;}
	}
	R_T_ADC=r;
	S_SFUART_SEND(0x0a);	
	S_SFUART_SEND(0x42);
	S_SFUART_SEND(0x42);
	S_SFUART_SEND(0x42);
	S_SFUART_SEND(0x42);
	S_SFUART_SEND(r);
	S_SFUART_SEND(0x42);
	S_SFUART_SEND(0x42);
	S_SFUART_SEND(0x42);
	S_SFUART_SEND(0x42);
	S_SFUART_SEND(0x42);
	S_SFUART_SEND(0x0a);

	if(r>55){ _pa2=0; return 1;}
	else {_pa2=0; return 0;}
	

//	temp_ADC=0;
//	if(r>55) {
//		F_LED_ALARM=1;
////	F_HUSH=1;
////	F_SM_ALARM=1;
//	}

	
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
	static char plt=0;
	static char temperature=0;
	static unsigned int counterPLT=0;
	int i=0;
	/*void read_temprature(void);*/
	
	

#define	NTC_ON_OFF		_pa2
temperature=read_temprature(T_AD);

	   /*  ntemp=T_AD;*/
	
	S_SFUART_SEND(0x0a);
	S_SFUART_SEND(0x0a);
	S_SFUART_SEND(0x0a);
	S_SFUART_SEND(0x0a);
	S_SFUART_SEND(0x0a);
	S_SFUART_SEND(0x0a);
	S_SFUART_SEND(0x43);
	S_SFUART_SEND(0x43);
	S_SFUART_SEND(0x43);
	S_SFUART_SEND(0x43);
	S_SFUART_SEND(0x43);
	S_SFUART_SEND(0x43);
	S_SFUART_SEND(0x43);	
	S_SFUART_SEND(temperature);
	S_SFUART_SEND(0x43);
	S_SFUART_SEND(0x43);
	S_SFUART_SEND(0x43);
	S_SFUART_SEND(0x43);
	S_SFUART_SEND(0x43);
	S_SFUART_SEND(0x43);
	S_SFUART_SEND(0x43);
	S_SFUART_SEND(0x0a);
	S_SFUART_SEND(0x0a);
	S_SFUART_SEND(0x0a);
	S_SFUART_SEND(0x0a);
	S_SFUART_SEND(0x0a);
	S_SFUART_SEND(0x0a);
	S_SFUART_SEND(0x0a);

		if((F_LED_ALARM == 1)||(temperature)){
	
			   
	         	while(1)
				{
				S_SFUART_SEND(0x0a);	
				S_SFUART_SEND(0x43);
				S_SFUART_SEND(0x43);
				S_SFUART_SEND(0x43);
				S_SFUART_SEND(0x43);
				S_SFUART_SEND(0x43);
				S_SFUART_SEND(0x43);
				S_SFUART_SEND(0x43);
				S_SFUART_SEND(0x0a);
	
					
				 _LED_R_ON;	
				 GCC_CLRWDT();
				 if(PLT0Recive()==0) {plt=1; break;}
				}
							
		}
    	if(PLT0Recive()==0)
		{ 	
		  plt=1;			
		}
	
		
        if(plt)
		{
		  
		  		while(1){

			    S_SFUART_SEND(0x0a);	
				S_SFUART_SEND(0x42);
				S_SFUART_SEND(0x42);
				S_SFUART_SEND(0x42);
				S_SFUART_SEND(0x42);
				S_SFUART_SEND(0x42);
				S_SFUART_SEND(0x42);
				S_SFUART_SEND(0x42);
				S_SFUART_SEND(0x0a);

				_LED_R_OFF;
				S_SFUART_SEND(0x0a);
				S_SFUART_SEND(PLT0Recive()+0x30);
			//	S_SFUART_SEND(counterPLT+0x30);
			//	S_SFUART_SEND(0x0a);
				GCC_CLRWDT();
				if(PLT0Recive())
				{
			 	counterPLT++;	
				}
				else{
				if(counterPLT>0)counterPLT--;	
				}	
		        
				
			  	if(counterPLT>20){
			  		plt=0;
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
					S_SFUART_SEND(0x0a);	
					S_SFUART_SEND(0x41);
					S_SFUART_SEND(0x41);
					S_SFUART_SEND(0x41);
					S_SFUART_SEND(0x41);
					S_SFUART_SEND(0x41);
					S_SFUART_SEND(0x41);
					S_SFUART_SEND(0x41);
					S_SFUART_SEND(0x0a);
					break;
				}
			   
				
		  
	      }
	      
	      
	      }
	
	
			
	
		
			/*	S_READ_SMOKE_DATA();					//READ SMOKE AD
				S_SM_BD_ZERO();							//SMOKE BD
				S_SM_BD_ALARM();
			    S_SM_ALARM_CHECK();	*/
		/*	if((F_LED_ALARM == 1)
			{*/
			
		/*	};*/
			
			
			
	
	//USER 1s CODE END
	return ;
}


		