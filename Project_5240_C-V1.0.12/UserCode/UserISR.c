#include "BA45F5240.h"
#include "A_USE_MACRO.h"
#include "UserISR.h"




//===========================================================
//*@brief		: Timebase0 ISR
//*@param[in]	: None
//*@retval		: None
//===========================================================
#if _TB0_ISR_EN
void __attribute((interrupt(0x30))) S_TB0_ISR(void)
{
	//USER CODE START
	
	
	
	//USER CODE END
}
#endif



//===========================================================
//*@brief		: IIC ISR
//*@param[in]	: None
//*@retval		: None
//===========================================================
#if _IIC_DRIVER & _IIC_ISR_EN
void __attribute((interrupt(0x10))) S_IIC_ISR(void)
{
	//USER CODE START
	
	
	
	//USER CODE END
}
#endif



//===========================================================
//*@brief		: SPI ISR
//*@param[in]	: None
//*@retval		: None
//===========================================================
#if _SPI_DRIVER & _SPI_ISR_EN
void __attribute((interrupt(0x10))) S_SPI_ISR(void)
{
	//USER CODE START
	
	
	
	//USER CODE END
}
#endif



//===========================================================
//*@brief		: UART ISR
//*@param[in]	: None
//*@retval		: None
//===========================================================
#if _UART_DRIVER & _UART_ISR_EN
void __attribute((interrupt(0x10))) S_UART_ISR(void)
{
	//USER CODE START
	
	
	
	//USER CODE END
}
#endif



//===========================================================
//*@brief		: STM P ISR
//*@param[in]	: None
//*@retval		: None
//===========================================================
#if _STM_P_ISR_EN
void __attribute((interrupt(0x28))) S_STM_P_ISR(void)
{
	//USER CODE START
	
	
	
	//USER CODE END
}
#endif



//===========================================================
//*@brief		: STM A ISR
//*@param[in]	: None
//*@retval		: None
//===========================================================
#if _STM_A_ISR_EN
void __attribute((interrupt(0x2C))) S_STM_A_ISR(void)
{
	//USER CODE START
	
	
	
	//USER CODE END
}
#endif


