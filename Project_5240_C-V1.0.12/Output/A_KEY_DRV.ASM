; Generated by holtek-gcc v3.19, Tue Mar 05 11:15:15 2024
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
public _S_KEY_Init
#pragma debug scope 2 1
#line 12 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\KEY\A_KEY_DRV.c"
_S_KEY_Init .section 'code'
_S_KEY_Init proc
	ret
_S_KEY_Init endp
#line 12 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\KEY\A_KEY_DRV.c"
#pragma debug scope 1 1
___pa equ [20]
public _S_KEY_UPDATE
#pragma debug scope 3 1
#line 23 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\KEY\A_KEY_DRV.c"
_S_KEY_UPDATE .section 'code'
_S_KEY_UPDATE proc
#line 24 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\KEY\A_KEY_DRV.c"
	mov a,[20]
	mov ra,a
	mov a,1
	andm a,ra
	sz ra
	jmp _L3
#line 26 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\KEY\A_KEY_DRV.c"
	set _R_KEY_ISCHANGE[0].0
#line 28 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\KEY\A_KEY_DRV.c"
	mov a,_R_KEY1_STATE[0]
	mov ra,a
	mov a,8
	andm a,ra
	snz ra
	jmp _L2
#line 30 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\KEY\A_KEY_DRV.c"
	mov a,_R_DEBOUNCE_CNT[0]
	mov ra,a
	inc ra
	mov a,ra
	mov _R_DEBOUNCE_CNT[0],a
#line 31 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\KEY\A_KEY_DRV.c"
	mov a,_R_DEBOUNCE_CNT[0]
	mov ra,a
	mov a,4
	sub a,ra
	sz c
	jmp _L2
#line 33 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\KEY\A_KEY_DRV.c"
	clr _R_KEY1_STATE[0].3
#line 34 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\KEY\A_KEY_DRV.c"
	set _R_KEY1_STATE[0].0
	jmp _L2
_L3:
#line 41 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\KEY\A_KEY_DRV.c"
	clr _R_DEBOUNCE_CNT[0]
#line 42 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\KEY\A_KEY_DRV.c"
	clr _R_KEY_ISCHANGE[0].0
#line 43 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\KEY\A_KEY_DRV.c"
	mov a,_R_KEY1_STATE[0]
	mov ra,a
	mov a,8
	andm a,ra
	sz ra
	jmp _L2
#line 45 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\KEY\A_KEY_DRV.c"
	set _R_KEY1_STATE[0].3
#line 46 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\KEY\A_KEY_DRV.c"
	set _R_KEY1_STATE[0].1
_L2:
	ret
_S_KEY_UPDATE endp
#line 46 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\KEY\A_KEY_DRV.c"
#pragma debug scope 1 1
public _S_KEY_PROCESS
#pragma debug scope 4 1
#line 84 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\KEY\A_KEY_DRV.c"
_S_KEY_PROCESS .section 'code'
_S_KEY_PROCESS proc
#line 85 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\KEY\A_KEY_DRV.c"
	mov a,_R_KEY1_STATE[0]
	mov ra,a
	mov a,1
	andm a,ra
	snz ra
	jmp _L7
#line 87 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\KEY\A_KEY_DRV.c"
	mov a,_R_SM_FG[0]
	mov ra,a
	mov a,2
	andm a,ra
	sz ra
	jmp _L8
	mov a,_R_BOARD_FG[0]
	mov ra,a
	mov a,64
	andm a,ra
	snz ra
	jmp _L9
_L8:
#line 89 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\KEY\A_KEY_DRV.c"
	set _R_BOARD_FG[0].6
	jmp _L10
_L9:
#line 93 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\KEY\A_KEY_DRV.c"
	set _R_BOARD_FG[0].5
#line 94 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\KEY\A_KEY_DRV.c"
	clr _R_BOARD_FG[0].3
_L10:
#line 96 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\KEY\A_KEY_DRV.c"
	clr _R_KEY1_STATE[0].0
_L7:
#line 98 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\KEY\A_KEY_DRV.c"
	mov a,_R_KEY1_STATE[0]
	mov ra,a
	mov a,2
	andm a,ra
	snz ra
	jmp _L6
#line 100 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\KEY\A_KEY_DRV.c"
	clr _R_KEY1_STATE[0].1
#line 101 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\KEY\A_KEY_DRV.c"
	set _R_BOARD_FG[0].3
#line 102 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\KEY\A_KEY_DRV.c"
	clr _R_BOARD_FG[0].5
_L6:
	ret
_S_KEY_PROCESS endp
#line 102 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\KEY\A_KEY_DRV.c"
#pragma debug scope 1 1
#pragma debug struct_begin 42 "__pa_bits"
#pragma debug field 21 8 0 1 "__pa0" ;0,1
#pragma debug field 21 8 0 1 "__pa1" ;1,1
#pragma debug field 21 8 0 1 "__pa2" ;2,1
#pragma debug field 21 8 0 1 "__pa3" ;3,1
#pragma debug field 21 8 0 1 "__pa4" ;4,1
#pragma debug field 21 8 0 1 "__pa5" ;5,1
#pragma debug field 21 8 0 1 "__pa6" ;6,1
#pragma debug field 21 8 0 1 "__pa7" ;7,1
#pragma debug struct_end
#pragma debug union_begin 43 ""
#pragma debug field 2 42 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 43 1 ___pa "__pa" 1

; output external variables
extern _R_BOARD_FG:byte
extern _R_SM_FG:byte
extern _R_DEBOUNCE_CNT:byte
extern _R_KEY1_STATE:byte
extern _R_KEY_ISCHANGE:byte

; 
; Generated by holtek-gcc v3.19, Tue Mar 05 11:15:15 2024
; Rebuild 718
; end of file
