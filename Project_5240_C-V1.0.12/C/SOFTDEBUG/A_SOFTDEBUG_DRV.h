#ifndef A_SOFTDEBUG_DRV_H__
#define A_SOFTDEBUG_DRV_H__
#include "BA45F5240.h"
#include "A_VAL_DEFINE.h"
#include "A_USE_MACRO.h"
#include "A_USE_LIB.h"
#include "A_BOARD.h"
#include "A_SYS_FUNCTION.h"

#if	_SOFTDEBUG
	#define P_SFUART_TX		_pa4
	#define PC_SFUART_TX	_pac4
	
	#define P_SFUART_RX		_pa1
	#define PC_SFUART_RX	_pac1
	#define PU_SFUART_RX	_papu1
	
	void S_SFUART_Init(void);
	void S_SFUART_SEND(unsigned char R_SFUART_DATA);
	void S_SFUART_RXINT(void);
	void S_SFUART_DEAL(unsigned char *p);
	void S_SOFTDEBUG_Output(void);
#endif




#endif



