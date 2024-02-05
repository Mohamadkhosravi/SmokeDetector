#ifndef A_SYS_FUNCTION_H__
#define A_SYS_FUNCTION_H__
#include "BA45F5240.h"
#include "A_VAL_DEFINE.h"
#include "A_USE_LIB.h"
#include "A_USE_MACRO.h"
#include "ADC.h"
#include "A_BOARD.h"
//RS232 define
#define P_RS_TX		_pa0		//RS232 debug output IO
#define PC_RS_TX	_pac0
#define PU_RS_TX	_papu0

//1s
#define C_LONG_DELAY	122

char S_SysTimeTask(int time);
#if _DEBUG
	void S_RS232_SEND(unsigned char R_RS_DATA);
	void S_DEBUG_Output(void);
#endif
void S_CLR_OUTPUT(void);
void S_SYS_DELAY(unsigned char R_DELAY_CNT);
void S_MODE_JUDG(void);

#endif
