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
___pa equ [20]
___pac equ [21]
___papu equ [22]
___pawu equ [23]
___pas0 equ [76]
___pas1 equ [77]
___pb equ [24]
___pbc equ [25]
___pbpu equ [26]
___pbs0 equ [78]
___pbs1 equ [79]
___ifs0 equ [80]
public _S_GPIO_Init
#pragma debug scope 2 1
#line 11 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\GPIO\GPIO.c"
_S_GPIO_Init .section 'code'
_S_GPIO_Init proc
#line 12 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\GPIO\GPIO.c"
	clr [20]
#line 13 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\GPIO\GPIO.c"
	mov a,17
	mov [21],a
#line 14 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\GPIO\GPIO.c"
	mov a,1
	mov [22],a
#line 15 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\GPIO\GPIO.c"
	mov a,1
	mov [23],a
#line 16 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\GPIO\GPIO.c"
	clr [76]
#line 17 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\GPIO\GPIO.c"
	mov a,146
	mov [77],a
#line 19 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\GPIO\GPIO.c"
	clr [24]
#line 20 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\GPIO\GPIO.c"
	mov a,4
	mov [25],a
#line 21 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\GPIO\GPIO.c"
	mov a,4
	mov [26],a
#line 22 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\GPIO\GPIO.c"
	mov a,64
	mov [78],a
#line 23 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\GPIO\GPIO.c"
	clr [79]
#line 25 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\GPIO\GPIO.c"
	clr [80]
	ret
_S_GPIO_Init endp
#line 25 "c:\users\tech\desktop\smokedetector\project_5240_c-v1.0.12\C\GPIO\GPIO.c"
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
#pragma debug struct_begin 44 "__pac_bits"
#pragma debug field 21 8 0 1 "__pac0" ;0,1
#pragma debug field 21 8 0 1 "__pac1" ;1,1
#pragma debug field 21 8 0 1 "__pac2" ;2,1
#pragma debug field 21 8 0 1 "__pac3" ;3,1
#pragma debug field 21 8 0 1 "__pac4" ;4,1
#pragma debug field 21 8 0 1 "__pac5" ;5,1
#pragma debug field 21 8 0 1 "__pac6" ;6,1
#pragma debug field 21 8 0 1 "__pac7" ;7,1
#pragma debug struct_end
#pragma debug union_begin 45 ""
#pragma debug field 2 44 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 45 1 ___pac "__pac" 1
#pragma debug struct_begin 46 "__papu_bits"
#pragma debug field 21 8 0 1 "__papu0" ;0,1
#pragma debug field 21 8 0 1 "__papu1" ;1,1
#pragma debug field 21 8 0 1 "__papu2" ;2,1
#pragma debug field 21 8 0 1 "__papu3" ;3,1
#pragma debug field 21 8 0 1 "__papu4" ;4,1
#pragma debug field 21 8 0 1 "__papu5" ;5,1
#pragma debug field 21 8 0 1 "__papu6" ;6,1
#pragma debug field 21 8 0 1 "__papu7" ;7,1
#pragma debug struct_end
#pragma debug union_begin 47 ""
#pragma debug field 2 46 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 47 1 ___papu "__papu" 1
#pragma debug struct_begin 48 "__pawu_bits"
#pragma debug field 21 8 0 1 "__pawu0" ;0,1
#pragma debug field 21 8 0 1 "__pawu1" ;1,1
#pragma debug field 21 8 0 1 "__pawu2" ;2,1
#pragma debug field 21 8 0 1 "__pawu3" ;3,1
#pragma debug field 21 8 0 1 "__pawu4" ;4,1
#pragma debug field 21 8 0 1 "__pawu5" ;5,1
#pragma debug field 21 8 0 1 "__pawu6" ;6,1
#pragma debug field 21 8 0 1 "__pawu7" ;7,1
#pragma debug struct_end
#pragma debug union_begin 49 ""
#pragma debug field 2 48 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 49 1 ___pawu "__pawu" 1
#pragma debug struct_begin 50 "__pb_bits"
#pragma debug field 21 8 0 1 "__pb0" ;0,1
#pragma debug field 21 8 0 1 "__pb1" ;1,1
#pragma debug field 21 8 0 1 "__pb2" ;2,1
#pragma debug field 21 8 0 1 "__pb3" ;3,1
#pragma debug field 21 8 0 1 "__pb4" ;4,1
#pragma debug field 21 8 0 3 ;5,3
#pragma debug struct_end
#pragma debug union_begin 51 ""
#pragma debug field 2 50 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 51 1 ___pb "__pb" 1
#pragma debug struct_begin 52 "__pbc_bits"
#pragma debug field 21 8 0 1 "__pbc0" ;0,1
#pragma debug field 21 8 0 1 "__pbc1" ;1,1
#pragma debug field 21 8 0 1 "__pbc2" ;2,1
#pragma debug field 21 8 0 1 "__pbc3" ;3,1
#pragma debug field 21 8 0 1 "__pbc4" ;4,1
#pragma debug field 21 8 0 3 ;5,3
#pragma debug struct_end
#pragma debug union_begin 53 ""
#pragma debug field 2 52 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 53 1 ___pbc "__pbc" 1
#pragma debug struct_begin 54 "__pbpu_bits"
#pragma debug field 21 8 0 1 "__pbpu0" ;0,1
#pragma debug field 21 8 0 1 "__pbpu1" ;1,1
#pragma debug field 21 8 0 1 "__pbpu2" ;2,1
#pragma debug field 21 8 0 1 "__pbpu3" ;3,1
#pragma debug field 21 8 0 1 "__pbpu4" ;4,1
#pragma debug field 21 8 0 3 ;5,3
#pragma debug struct_end
#pragma debug union_begin 55 ""
#pragma debug field 2 54 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 55 1 ___pbpu "__pbpu" 1
#pragma debug struct_begin 56 "__pas0_bits"
#pragma debug field 21 8 0 1 "__pas00" ;0,1
#pragma debug field 21 8 0 1 "__pas01" ;1,1
#pragma debug field 21 8 0 1 "__pas02" ;2,1
#pragma debug field 21 8 0 1 "__pas03" ;3,1
#pragma debug field 21 8 0 1 "__pas04" ;4,1
#pragma debug field 21 8 0 1 "__pas05" ;5,1
#pragma debug field 21 8 0 1 "__pas06" ;6,1
#pragma debug field 21 8 0 1 "__pas07" ;7,1
#pragma debug struct_end
#pragma debug union_begin 57 ""
#pragma debug field 2 56 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 57 1 ___pas0 "__pas0" 1
#pragma debug struct_begin 58 "__pas1_bits"
#pragma debug field 21 8 0 1 "__pas10" ;0,1
#pragma debug field 21 8 0 1 "__pas11" ;1,1
#pragma debug field 21 8 0 1 "__pas12" ;2,1
#pragma debug field 21 8 0 1 "__pas13" ;3,1
#pragma debug field 21 8 0 1 "__pas14" ;4,1
#pragma debug field 21 8 0 1 "__pas15" ;5,1
#pragma debug field 21 8 0 1 "__pas16" ;6,1
#pragma debug field 21 8 0 1 "__pas17" ;7,1
#pragma debug struct_end
#pragma debug union_begin 59 ""
#pragma debug field 2 58 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 59 1 ___pas1 "__pas1" 1
#pragma debug struct_begin 60 "__pbs0_bits"
#pragma debug field 21 8 0 1 "__pbs00" ;0,1
#pragma debug field 21 8 0 1 "__pbs01" ;1,1
#pragma debug field 21 8 0 1 "__pbs02" ;2,1
#pragma debug field 21 8 0 1 "__pbs03" ;3,1
#pragma debug field 21 8 0 1 "__pbs04" ;4,1
#pragma debug field 21 8 0 1 "__pbs05" ;5,1
#pragma debug field 21 8 0 1 "__pbs06" ;6,1
#pragma debug field 21 8 0 1 "__pbs07" ;7,1
#pragma debug struct_end
#pragma debug union_begin 61 ""
#pragma debug field 2 60 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 61 1 ___pbs0 "__pbs0" 1
#pragma debug struct_begin 62 "__pbs1_bits"
#pragma debug field 21 8 0 1 "__pbs10" ;0,1
#pragma debug field 21 8 0 1 "__pbs11" ;1,1
#pragma debug field 21 8 0 6 ;2,6
#pragma debug struct_end
#pragma debug union_begin 63 ""
#pragma debug field 2 62 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 63 1 ___pbs1 "__pbs1" 1
#pragma debug struct_begin 64 "__ifs0_bits"
#pragma debug field 21 8 0 1 "__ifs00" ;0,1
#pragma debug field 21 8 0 1 "__ifs01" ;1,1
#pragma debug field 21 8 0 1 "__ifs02" ;2,1
#pragma debug field 21 8 0 1 "__ifs03" ;3,1
#pragma debug field 21 8 0 1 "__ifs04" ;4,1
#pragma debug field 21 8 0 1 "__ifs05" ;5,1
#pragma debug field 21 8 0 1 "__ifs06" ;6,1
#pragma debug field 21 8 0 1 "__ifs07" ;7,1
#pragma debug struct_end
#pragma debug union_begin 65 ""
#pragma debug field 2 64 "bits"
#pragma debug field 0 8 "byte"
#pragma debug union_end
#pragma debug variable 65 1 ___ifs0 "__ifs0" 1

; 
; Generated by holtek-gcc v3.19, Tue Mar 05 11:15:15 2024
; Rebuild 718
; end of file
