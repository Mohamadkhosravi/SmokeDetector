#ifndef A_BOARD_H__
#define A_BOARD_H__
#include "BA45F5240.h"
#include "A_VAL_DEFINE.h"
#include "A_USE_MACRO.h"
#include "A_USE_LIB.h"
#include "A_SYS_FUNCTION.h"
#include "A_SET_PARAM.h"

#define		C_RAM_ADDR_START		0x80		// RAM starting address
#define		C_RAM_ADDR_END			0xFF		// RAM Last address
#define		C_LED_ALARM_DELAY_H		12			//ON	N*8.192MS
#define		C_LED_ALARM_DELAY_L		37			//OFF	N*8.192MS

#define		_LED_R_ON	{LED_R=1;}
#define		_LED_R_OFF	{LED_R=0;}

void S_RAM_Init(unsigned char RAM_BANK);
void S_SM_INIT(void);
void S_BOARD_INI(void);
void S_HUSH_COUNT(void);
void S_LED_DRV(void);
void S_BAT_CHECK(void);
void S_V_CONVER(void);
void S_SM_T_REF(void);
void S_WR_EE(unsigned char WR_EE_addr,unsigned char WR_EE_data);

#endif