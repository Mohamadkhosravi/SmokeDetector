#ifndef A_USE_MACRO_H__
#define A_USE_MACRO_H__
#include "BA45F5240.h"

//Please do not change the macro definition

#define		_HIRCC_8M		0			//System frequency 8M enable
#define		_HIRCC_4M		0			//System frequency 4M enable
#define		_HIRCC_2M		1			//System frequency 2M enable
#define		_BUZZ			1			//buzz enable							1-ON  0-OFF
#define		_KEY			1			//KEY  enable							1-ON  0-OFF
#define		_ADJUST			1			//Air SMOKE BD							1-ON  0-OFF
#define		_CHECK_IR_ERR	1			//check IR ERR							1-ON  0-OFF
#define		_T_REF			1			//Temperature compensation				1-ON  0-OFF
#define		_SMJUST			0			//BD with smoke							1-ON  0-OFF
#define		_V_CONVER		1			//voltage compensation					1-ON  0-OFF
#define		_UL_BAT_L		1			//Internal resistance detection			1-ON  0-OFF
#define		_DEBUG			0			//Debug serial port						1-ON  0-OFF
#define		_SOFTDEBUG		1			//smoke detector workshop debug driver	1-ON  0-OFF
#define		_NO_SLEEP		1

//ISR ENABLE/DISABLE
#define		_TB0_ISR_EN		1			//TimeBase	ISR		1-ON	0-OFF
#define		_SPI_ISR_EN		0			//SPI		ISR		1-ON	0-OFF
#define		_IIC_ISR_EN		0			//IIC		ISR		1-ON	0-OFF
#define		_UART_ISR_EN	0			//UART		ISR		1-ON	0-OFF
#define		_STM_P_ISR_EN	0			//STM P		ISR		1-ON	0-OFF
#define		_STM_A_ISR_EN	0			//STM A		ISR		1-ON	0-OFF

//USIM DRIVER ENABLE/DISABLE
#define		_SPI_DRIVER		0			//SPI	DRIVER		1-ON	0-OFF
#define		_IIC_DRIVER		0			//IIC	DRIVER		1-ON	0-OFF
#define		_UART_DRIVER	0			//UART	DRIVER		1-ON	0-OFF


#define C16_BUZZ_SET_WIDTH		3200
#define C16_BUZZ_SET_DUTY		50

//define BUZZ frequency
#if		_HIRCC_8M
	#if		(C16_BUZZ_SET_WIDTH<2000)
		#define Fsys			8000000/16
	#else
		#define Fsys			8000000/4
	#endif
#elif	_HIRCC_4M
	#define Fsys				4000000/4
#else
	#define Fsys				2000000/4
#endif
#define C16_BUZZ_WIDTH			(Fsys/C16_BUZZ_SET_WIDTH)
#define C16_BUZZ_DUTY			((C16_BUZZ_WIDTH*C16_BUZZ_SET_DUTY)/100)

//IO define
#define	P_KEY		_pa0
#define	PA1		_pa1
#define	PA2		_pa2
#define	LED_R		_pa3
#define	PA4		_pa4
#define	BUZZ		_pa6
#define	T_AD		S_READ_ADC(AN1)
#define	PB1		_pb1
#define	BD		_pb2
#define	PB3		_pb3

#define C_INTERRESIST_DELAY		1		//Delay of internal resistance detection
#define C_VDD_CK_SPACE			10		//internal resistance check period
#define C16_BAT_R_CK			100		//Internal resistance test threshold
//BAT check
#define C_BAT_LOW				113		//Low voltage threshold
#define C_BAT_CK_SPACE			40
#define C_BAT_LOW_CNT			3
//SMOKE 
#define C_SM_BD_ZERO_MAX		200		//Air calibration maximum
#define C_SM_BD_ZERO_MIN		2		//Air calibration minimum


#define C16_HUSH_DELAY			90		//Hush delay
#define C_NOR_DELAY				5		//LED flash period

#define C_SM_COV_VAL			102		//Voltage compensation threshold


#if _T_REF
	//Temperature fault threshold
	#define C_T_AD_ERR_L 		2
	#define C_T_AD_ERR_H 		254
	//Compensate threshold for temperature AD(8bit)
	#define C_T_AD_DATA_L1		66		//Low temperature level 2   : AD<L1
	#define C_T_AD_DATA_L2		86		//Low temperature level 1   : L1<AD<L2
	#define C_T_AD_DATA_L3		106		//The normal temperature AD : L2<AD<L3
	#define C_T_AD_DATA_L4		130		//High temperature level 1  : L3<AD<L4. And AD>L4 is High temperature level 2
	
	#define C_T_ADD_L2			0		//The compensation of low temperature level 2
	#define C_T_ADD_L1			0		//The compensation of low temperature level 1
	#define C_T_SUB_L1			0		//The compensation of high temperature level 1
	#define C_T_SUB_L2			0		//The compensation of high temperature level 2
	
	#define C_SM_ALARM_DATA_L	10
#endif

//software version
#define C16_SOFT_VERSION		0x100C
#endif

