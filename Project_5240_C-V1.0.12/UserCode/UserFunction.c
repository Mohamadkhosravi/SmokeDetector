#include "BA45F5240.h"
#include "A_USE_MACRO.h"
#include "UserFunction.h"
#include "A_VAL_DEFINE.h"

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





//===========================================================
//*@brief		: User 1s work period function
//*@param[in]	: None
//*@retval		: None
//*@note		: If in sleep/standby mode, it runs once every work cycle. If in fast mode, run once every 1s.
//===========================================================
void S_USER_1S_WORK_PERIOD()
{
	//USER 1s CODE START
	
	
	
	//USER 1s CODE END
	return;
}