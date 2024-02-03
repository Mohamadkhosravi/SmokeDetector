#ifndef A_VAL_DEFINE_H__
#define A_VAL_DEFINE_H__
#include "A_USE_MACRO.h"
volatile typedef struct {
	unsigned char bit0 : 1;
	unsigned char bit1 : 1;
	unsigned char bit2 : 1;
	unsigned char bit3 : 1;
	unsigned char bit4 : 1;
	unsigned char bit5 : 1;
	unsigned char bit6 : 1;
	unsigned char bit7 : 1;
}bit_type;						//Structure definition
typedef union {
	bit_type			bits;
	unsigned char		byte;
}byte_type;


extern unsigned char R_EE_DATA;
extern unsigned char R_EE_ADDR;


//system
extern byte_type R_SYS_FG;
#define		F_TIMER			R_SYS_FG.bits.bit0		//8.192 period
#define		F_SYS_SLOW		R_SYS_FG.bits.bit1		//halt flag
#define		F_ONESEC		R_SYS_FG.bits.bit2		//1 s flag
#define		F_SYS_WMODE		R_SYS_FG.bits.bit3		//1 s cycle
extern unsigned char R_LONG_DELAY;

extern byte_type R_BOARD_FG;
#define		F_RS_OUT		R_BOARD_FG.bits.bit2	//DEBUG OUTPUT ENABLE BIT
#define		F_TEST_CLR		R_BOARD_FG.bits.bit3	//RELEASE KEY BIT
#define		F_BAT_L			R_BOARD_FG.bits.bit4	//LOW BATTERY
#define		F_TEST			R_BOARD_FG.bits.bit5	//TEST MODE
#define		F_HUSH			R_BOARD_FG.bits.bit6	//HUSH MODE

extern byte_type R_SYS_MODE_FG;
#define		F_ALARM_MODE_INI	R_SYS_MODE_FG.bits.bit0
#define		F_NOR_MODE_INI		R_SYS_MODE_FG.bits.bit1
#define		F_NOR_CNT_MODE		R_SYS_MODE_FG.bits.bit2
//buzz
#if _BUZZ
extern unsigned char R_BUZZ_ALARM_DELAY;
extern unsigned char R_BUZZ_ALARM_CNT;
extern byte_type R_BUZZ_ALARM_FG;
#define		F_BUZZ_ALARM		R_BUZZ_ALARM_FG.bits.bit0
#define		F_BUZZ_ALARM_INI	R_BUZZ_ALARM_FG.bits.bit1
#define		F_BUZZ_ALARM_HL		R_BUZZ_ALARM_FG.bits.bit2
#define		F_BUZZ_ALARM_STOP	R_BUZZ_ALARM_FG.bits.bit3
#endif

#if _KEY
extern byte_type R_KEY_ISCHANGE;
#define		F_KEY_ISCHANGE_1	R_KEY_ISCHANGE.bits.bit0
#define		F_KEY_ISCHANGE_2	R_KEY_ISCHANGE.bits.bit1

extern byte_type R_KEY1_STATE;
#define		F_KEY1_SPRESS	R_KEY1_STATE.bits.bit0
#define		F_KEY1_RESET	R_KEY1_STATE.bits.bit1
#define		F_KEY1_LONGPR	R_KEY1_STATE.bits.bit2
#define		F_KEY1_LAST		R_KEY1_STATE.bits.bit3

#define		F_KEY2_SPRESS	R_KEY1_STATE.bits.bit4
#define		F_KEY2_RESET	R_KEY1_STATE.bits.bit5
#define		F_KEY2_LONGPR	R_KEY1_STATE.bits.bit6
#define		F_KEY2_LAST		R_KEY1_STATE.bits.bit7

extern unsigned char R_DEBOUNCE_CNT[2];
extern unsigned char R_KEY_DEBOUNCE;
#endif

//LED
extern unsigned char R_LED_ALARM_DELAY;
extern byte_type R_LED_ALARM_FG;
#define		F_LED_ALARM			R_LED_ALARM_FG.bits.bit0
#define		F_LED_HL			R_LED_ALARM_FG.bits.bit1
#define		F_LED_ALARM_INI		R_LED_ALARM_FG.bits.bit2
extern unsigned char R_NOR_DELAY;

//HUsh delay
extern unsigned int R16_HUSH_DELAY;

//Battery
extern unsigned char R_BAT_ADC;
extern unsigned char R_BAT_CK_SPACE;

//smoke detector workshop debug
#if _SOFTDEBUG
extern unsigned char R_SFUART_RXDAT[12];
extern unsigned char R_SFUART_RXCNT;
extern unsigned char R_UART_RUNCNT;
extern unsigned char R_SFCHECK_SUM;
#endif

//BD DATA SAVE IN EEPROM OR NOT
extern bit F_BD_DATA_DONT_SAVE;

#endif

