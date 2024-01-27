
#include "A_KEY_DRV.h"


#if _KEY
//===========================================================
//*@brief		: Key Init
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_KEY_Init(void)
{

}


//===========================================================
//*@brief		: Key Scan
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_KEY_UPDATE(void)
{
	if(P_KEY == 0)
	{
		F_KEY_ISCHANGE_1 = 1;
		
		if(F_KEY1_LAST == 1)
		{
			++R_DEBOUNCE_CNT[0];
			if(R_DEBOUNCE_CNT[0]>=C_KEY1_SDELAY)
			{
				F_KEY1_LAST = 0;
				F_KEY1_SPRESS =1;
			}
		}
	}
	else
	{
		
		R_DEBOUNCE_CNT[0] = 0;
		F_KEY_ISCHANGE_1 = 0;
		if(F_KEY1_LAST == 0)
		{
			F_KEY1_LAST = 1;
			F_KEY1_RESET= 1;
		}
	}
#if _SMJUST	
	if(BD == 0)
	{
		F_KEY_ISCHANGE_2 = 1;
		
		if(F_KEY2_LAST == 1)
		{
			++R_DEBOUNCE_CNT[1];
			if(R_DEBOUNCE_CNT[1]>=C_KEY1_SDELAY)
			{
				F_KEY2_LAST = 0;
				F_KEY2_SPRESS =1;
			}
		}
	}
	else
	{
		R_DEBOUNCE_CNT[1] = 0;
		F_KEY_ISCHANGE_2 = 0;
		if(F_KEY2_LAST == 0)
		{
			F_KEY2_LAST = 1;
			F_KEY2_RESET= 1;
		}
	}
#endif
}


//===========================================================
//*@brief		: Key Driver
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_KEY_PROCESS(void)
{
	if(F_KEY1_SPRESS == 1)
	{	
		if(F_SM_ALARM==1 || F_HUSH==1)
		{
			F_HUSH=1;
		}
		else
		{
			F_TEST = 1;
			F_TEST_CLR = 0;
		}
		F_KEY1_SPRESS = 0;
	}
	if(F_KEY1_RESET == 1)
	{
		F_KEY1_RESET = 0;
		F_TEST_CLR = 1;
		F_TEST = 0;
	}
#if _SMJUST
	if(F_KEY2_SPRESS == 1)
	{
		S_SM_BD_SM();
		F_KEY2_SPRESS = 0;
	}
#endif
}

#endif










