; Generated by holtek-gcc v3.19, Tue Mar 05 11:15:16 2024
; 
; Configuration:
;       with long instruction
;       Single ROM, Multi-RAM
;       bits_per_rom_unit:16
;       with mp1
;       with tbhp, address(0x9)
;          Use tabrd-const
;       
; SFR address of long-instruction arch:
;    mp0 = -1,1,0
;    mp1 = 4,3,2
;    mp2 = 14,13,12
;    tbp = 9,7,8
;    acc = 5
;    pcl = 6
;    status = 10
;    bp = 11
;    intc = 72
;       
;       
; use 'tabrdc' instead of 'tabrd'
;       

#pragma translator "holtek-gcc 4.6.4" "3.19" "build 20130711"
; Rebuild 718

ir equ [2]
mp equ [3]
sbp equ [4]
acc equ [5]
bp equ [11]
tblp equ [7]
tbhp equ [9]
status equ [10]
c equ [10].0
ac equ [10].1
z equ [10].2
ov equ [10].3
cz equ [10].6
sc equ [10].7
intc equ [72]

extern ra:byte
extern rb:byte
extern rc:byte
extern rd:byte
extern re:byte
extern rf:byte
extern rg:byte
extern rh:byte
extern _Crom2Prom:near
extern _Crom2PromNext:near

RAMBANK 0 @BITDATASEC, @BITDATASEC1
@HCCINIT	.section 'data'
@HCCINIT0	.section 'data'
@BITDATASEC	 .section 'data'
@BITDATASEC1	 .section 'data'

#pragma debug scope 1 1
	extern __DELAY3:near
	extern __DELAYX3:near
	extern __DELAYX6:near
	extern __DELAYY5:near
	extern __DELAYY3:near
	extern _builtin_holtek_delay_2:byte
#line 4 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\VAL_DEFINE\A_VAL_DEFINE.c"
public _R_EE_DATA
@HCCINIT0_R_EE_DATA .section 'data'
_R_EE_DATA	db 0
#pragma debug variable 8 1 _R_EE_DATA "R_EE_DATA"

@HCCINIT .section 'data'
#line 5 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\VAL_DEFINE\A_VAL_DEFINE.c"
public _R_EE_ADDR
@HCCINIT0_R_EE_ADDR .section 'data'
_R_EE_ADDR	db 0
#pragma debug variable 8 1 _R_EE_ADDR "R_EE_ADDR"

@HCCINIT .section 'data'
#line 8 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\VAL_DEFINE\A_VAL_DEFINE.c"
public _R_LONG_DELAY
@HCCINIT0_R_LONG_DELAY .section 'data'
_R_LONG_DELAY	db 0
#pragma debug variable 8 1 _R_LONG_DELAY "R_LONG_DELAY"

@HCCINIT .section 'data'
#line 9 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\VAL_DEFINE\A_VAL_DEFINE.c"
public _R_SYS_FG
@HCCINIT0_R_SYS_FG .section 'data'
_R_SYS_FG	db 0
#pragma debug struct_begin 42 "bit_type"
#pragma debug field 21 8 0 1 "bit0" ;0,1
#pragma debug field 21 8 0 1 "bit1" ;1,1
#pragma debug field 21 8 0 1 "bit2" ;2,1
#pragma debug field 21 8 0 1 "bit3" ;3,1
#pragma debug field 21 8 0 1 "bit4" ;4,1
#pragma debug field 21 8 0 1 "bit5" ;5,1
#pragma debug field 21 8 0 1 "bit6" ;6,1
#pragma debug field 21 8 0 1 "bit7" ;7,1
#pragma debug struct_end
#pragma debug union_begin 43 ""
#pragma debug field 2 42 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 43 1 _R_SYS_FG "R_SYS_FG"

@HCCINIT .section 'data'
#line 10 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\VAL_DEFINE\A_VAL_DEFINE.c"
public _R_BOARD_FG
@HCCINIT0_R_BOARD_FG .section 'data'
_R_BOARD_FG	db 0
#pragma debug variable 43 1 _R_BOARD_FG "R_BOARD_FG"

@HCCINIT .section 'data'
#line 11 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\VAL_DEFINE\A_VAL_DEFINE.c"
public _R_SYS_MODE_FG
@HCCINIT0_R_SYS_MODE_FG .section 'data'
_R_SYS_MODE_FG	db 0
#pragma debug variable 43 1 _R_SYS_MODE_FG "R_SYS_MODE_FG"

@HCCINIT .section 'data'
#line 15 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\VAL_DEFINE\A_VAL_DEFINE.c"
public _R_BUZZ_ALARM_DELAY
@HCCINIT0_R_BUZZ_ALARM_DELAY .section 'data'
_R_BUZZ_ALARM_DELAY	db 0
#pragma debug variable 8 1 _R_BUZZ_ALARM_DELAY "R_BUZZ_ALARM_DELAY"

@HCCINIT .section 'data'
#line 16 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\VAL_DEFINE\A_VAL_DEFINE.c"
public _R_BUZZ_ALARM_CNT
@HCCINIT0_R_BUZZ_ALARM_CNT .section 'data'
_R_BUZZ_ALARM_CNT	db 0
#pragma debug variable 8 1 _R_BUZZ_ALARM_CNT "R_BUZZ_ALARM_CNT"

@HCCINIT .section 'data'
#line 17 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\VAL_DEFINE\A_VAL_DEFINE.c"
public _R_BUZZ_ALARM_FG
@HCCINIT0_R_BUZZ_ALARM_FG .section 'data'
_R_BUZZ_ALARM_FG	db 0
#pragma debug variable 43 1 _R_BUZZ_ALARM_FG "R_BUZZ_ALARM_FG"

@HCCINIT .section 'data'
#line 22 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\VAL_DEFINE\A_VAL_DEFINE.c"
public _R_KEY_ISCHANGE
@HCCINIT0_R_KEY_ISCHANGE .section 'data'
_R_KEY_ISCHANGE	db 0
#pragma debug variable 43 1 _R_KEY_ISCHANGE "R_KEY_ISCHANGE"

@HCCINIT .section 'data'
#line 23 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\VAL_DEFINE\A_VAL_DEFINE.c"
public _R_KEY1_STATE
@HCCINIT0_R_KEY1_STATE .section 'data'
_R_KEY1_STATE	db 0
#pragma debug variable 43 1 _R_KEY1_STATE "R_KEY1_STATE"

@HCCINIT .section 'data'
#line 24 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\VAL_DEFINE\A_VAL_DEFINE.c"
public _R_DEBOUNCE_CNT
@HCCINIT0_R_DEBOUNCE_CNT .section 'data'
_R_DEBOUNCE_CNT	db 2 dup(0)
#pragma debug array 44 8 2 1
#pragma debug variable 44 1 _R_DEBOUNCE_CNT "R_DEBOUNCE_CNT"

@HCCINIT .section 'data'
#line 25 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\VAL_DEFINE\A_VAL_DEFINE.c"
public _R_KEY_DEBOUNCE
@HCCINIT0_R_KEY_DEBOUNCE .section 'data'
_R_KEY_DEBOUNCE	db 0
#pragma debug variable 8 1 _R_KEY_DEBOUNCE "R_KEY_DEBOUNCE"

@HCCINIT .section 'data'
#line 29 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\VAL_DEFINE\A_VAL_DEFINE.c"
public _R_LED_ALARM_DELAY
@HCCINIT0_R_LED_ALARM_DELAY .section 'data'
_R_LED_ALARM_DELAY	db 0
#pragma debug variable 8 1 _R_LED_ALARM_DELAY "R_LED_ALARM_DELAY"

@HCCINIT .section 'data'
#line 30 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\VAL_DEFINE\A_VAL_DEFINE.c"
public _R_NOR_DELAY
@HCCINIT0_R_NOR_DELAY .section 'data'
_R_NOR_DELAY	db 0
#pragma debug variable 8 1 _R_NOR_DELAY "R_NOR_DELAY"

@HCCINIT .section 'data'
#line 31 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\VAL_DEFINE\A_VAL_DEFINE.c"
public _R_LED_ALARM_FG
@HCCINIT0_R_LED_ALARM_FG .section 'data'
_R_LED_ALARM_FG	db 0
#pragma debug variable 43 1 _R_LED_ALARM_FG "R_LED_ALARM_FG"

@HCCINIT .section 'data'
#line 34 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\VAL_DEFINE\A_VAL_DEFINE.c"
public _R16_HUSH_DELAY
@HCCINIT0_R16_HUSH_DELAY .section 'data'
_R16_HUSH_DELAY	db 2 dup(0)
#pragma debug variable 12 1 _R16_HUSH_DELAY "R16_HUSH_DELAY"

@HCCINIT .section 'data'
#line 37 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\VAL_DEFINE\A_VAL_DEFINE.c"
public _R_BAT_ADC
@HCCINIT0_R_BAT_ADC .section 'data'
_R_BAT_ADC	db 0
#pragma debug variable 8 1 _R_BAT_ADC "R_BAT_ADC"

@HCCINIT .section 'data'
#line 38 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\VAL_DEFINE\A_VAL_DEFINE.c"
public _R_BAT_CK_SPACE
@HCCINIT0_R_BAT_CK_SPACE .section 'data'
_R_BAT_CK_SPACE	db 0
#pragma debug variable 8 1 _R_BAT_CK_SPACE "R_BAT_CK_SPACE"

@HCCINIT .section 'data'
#line 42 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\VAL_DEFINE\A_VAL_DEFINE.c"
public _R_SFUART_RXDAT
@HCCINIT0_R_SFUART_RXDAT .section 'data'
_R_SFUART_RXDAT	db 12 dup(0)
#pragma debug array 45 8 12 1
#pragma debug variable 45 1 _R_SFUART_RXDAT "R_SFUART_RXDAT"

@HCCINIT .section 'data'
#line 43 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\VAL_DEFINE\A_VAL_DEFINE.c"
public _R_SFUART_RXCNT
@HCCINIT0_R_SFUART_RXCNT .section 'data'
_R_SFUART_RXCNT	db 0
#pragma debug variable 8 1 _R_SFUART_RXCNT "R_SFUART_RXCNT"

@HCCINIT .section 'data'
#line 44 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\VAL_DEFINE\A_VAL_DEFINE.c"
public _R_UART_RUNCNT
@HCCINIT0_R_UART_RUNCNT .section 'data'
_R_UART_RUNCNT	db 0
#pragma debug variable 8 1 _R_UART_RUNCNT "R_UART_RUNCNT"

@HCCINIT .section 'data'
#line 45 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\VAL_DEFINE\A_VAL_DEFINE.c"
public _R_SFCHECK_SUM
@HCCINIT0_R_SFCHECK_SUM .section 'data'
_R_SFCHECK_SUM	db 0
#pragma debug variable 8 1 _R_SFCHECK_SUM "R_SFCHECK_SUM"

@HCCINIT .section 'data'
#line 49 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\VAL_DEFINE\A_VAL_DEFINE.c"
public _F_BD_DATA_DONT_SAVE
@BITDATASEC .section 'data'
_F_BD_DATA_DONT_SAVE	dbit 0
#pragma debug variable 2 1 _F_BD_DATA_DONT_SAVE "F_BD_DATA_DONT_SAVE"

@HCCINIT .section 'data'

; 
; Generated by holtek-gcc v3.19, Tue Mar 05 11:15:16 2024
; Rebuild 718
; end of file
