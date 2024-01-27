#ifndef TM_H__
#define TM_H__
#include "BA45F5240.h"
#include "A_VAL_DEFINE.h"


#define C_BUZZ_ALARM_DELAY_H	61
#define C_BUZZ_ALARM_DELAY_L	61
#define C_BUZZ_ALARM_DELAY_LONG	183
#define C_BUZZ_ALARM_CNT		3
#define C_LONG_SP_DELAY			90

//The macro name is defined by the user tag
#define PTM_ON			{_pton=1;}
#define PTM_OFF			{_pton=0;}
#define STM_ON			{_ston=1;}
#define STM_OFF			{_ston=0;}
		
void S_PTM_Init();
void S_STM_Init();
#if _BUZZ
	void S_BUZZ_DRV(void);
	void S_BUZZ_Init(void);
#endif


#endif 