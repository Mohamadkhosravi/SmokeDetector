#include "A_VAL_DEFINE.h"


unsigned char R_EE_DATA;
unsigned char R_EE_ADDR;

//System variable
unsigned char R_LONG_DELAY;
byte_type R_SYS_FG;
byte_type R_BOARD_FG;
byte_type R_SYS_MODE_FG;

//BUZR 
#if _BUZZ
unsigned char R_BUZZ_ALARM_DELAY;
unsigned char R_BUZZ_ALARM_CNT;
byte_type R_BUZZ_ALARM_FG;
#endif

//key
#if _KEY
byte_type R_KEY_ISCHANGE;
byte_type R_KEY1_STATE;
unsigned char R_DEBOUNCE_CNT[2];
unsigned char R_KEY_DEBOUNCE;
#endif

//LED
unsigned char R_LED_ALARM_DELAY;
unsigned char R_NOR_DELAY;
byte_type R_LED_ALARM_FG;

//HUsh delay
unsigned int R16_HUSH_DELAY;

//Battery
unsigned char R_BAT_ADC;
unsigned char R_BAT_CK_SPACE;

//smoke detector workshop debug
#if	_SOFTDEBUG
unsigned char R_SFUART_RXDAT[12];
unsigned char R_SFUART_RXCNT;
unsigned char R_UART_RUNCNT;
unsigned char R_SFCHECK_SUM;
#endif

//BD DATA SAVE IN EEPROM OR NOT
bit F_BD_DATA_DONT_SAVE;