#ifndef USERISR_H__
#define USERISR_H__



//External reference declaration
#if _TB0_ISR_EN
	void S_TB0_ISR();
#endif
#if _IIC_ISR_EN
	void S_IIC_ISR();
#endif
#if _SPI_ISR_EN
	void S_SPI_ISR();
#endif
#if _UART_ISR_EN
	void S_UART_ISR();
#endif
#if _STM_P_ISR_EN
	void S_STM_P_ISR();
#endif
#if _STM_A_ISR_EN
	void S_STM_A_ISR();
#endif


#endif