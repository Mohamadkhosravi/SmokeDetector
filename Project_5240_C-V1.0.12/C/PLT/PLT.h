#ifndef _PLT_H
#define _PLT_H
#include "ADC.h"
#include "RCC.h"
#include "AFE.h"
#define S0_S1_ON_S2_OFF  ((_pltc0ofm)&&(_pltc0rsp))&&0x0;


enum{
	Disable,
	Enable
};


//*******************************
#define PLTS2_Switch_Selection 	_plts2 
#define  Connect_to_PLTDAC2O 0
#define  Connect_to_PLRX 1

#define PLTS1_Switch_Selection 	_plts1 
#define  Connect_to_PLIS 0
#define  Connect_to_LINEV 1

#define PLTS0_Switch_Selection 	_plts0
#define  Connect_to_GND 0
#define  Connect_to_OPAMP_output 1
//********************************
#define PLT_DAC2_Control _pltdac2en
#define PLT_DAC1_Control _pltdac1en
#define PLT_DAC0_Control _pltdac0en 

/********************************
D5~D0: PLT DAC0 output control code
PLTDAC0O= ( DAC VDD/26)× PLTDA0L[5:0]*/
#define PLT0_DAC_VALUE _pltda0l
#define PLT1_DAC_VALUE _pltda1l
#define PLT2_DAC_VALUE _pltda2l
//********************************





#define PLT_Comparator_0_Control  _pltc0en 
#define PLT_Comparator_1_Control  _pltc1en 
#define PLT_Comparator_2_Control  _pltc2en 
/*********************************
PLT Comparator 0 debounced output
The PLTC0O is de-bounced version of PLTC0OUT
If PLTC0POL=0, the PLTC0O outputs “1” only when the current and the previous N
samples of PLTC0OUT are all “1”. If PLTC0POL=1, The PLTC0O outputs “0” only
when the current and the previous N samples of PLTC0OUT are all “0”. The sampling
frequency is depend on the PLTC0DEB[1:0] bit configuration.*/
#define PLT_Comparator_0_Debounced_Output	_pltc0o
#define PLT_Comparator_1_Debounced_Output	_pltc1o
#define PLT_Comparator_2_Debounced_Output   _pltc2o
//*************************
#define PLT_Comparator_0_Debounce_Time_Value 2

 #define _pltc0deb1((PLT_Comparator_0_Debounce_Time_Value) >> 1) 
 //#define _pltc0deb0 (PLT_Comparator_0_Debounce_Time_Value & 0x01)



#define PLT_Comparator_1_Debounce_Time_Value _pltc1deb1|_pltc1deb0
#define PLT_Comparator_2_Debounce_Time_Value _pltc2deb1|_pltc2deb0
//*******************
#define PLT_Comparator_0_Current_Value _pltc0is0|_pltc0is1
#define PLT_Comparator_1_Current_Value _pltc1is0|_pltc1is1
#define PLT_Comparator_2_Current_Value _pltc2is0|_pltc2is1

//*************************************************
#define PLT_Comparator0_OrComparator1_Output_selection  _pltcxosw
enum{
	Comparator_0_Output,
	Comparator_1_Output
};
//******************************************
#define PLT_Comparator_0_Output_Polarity  _pltc0pol
#define PLT_Comparator_1_Output_Polarity  _pltc0pol
enum{
	 Non_Invert,
	 Invert
};
//****************************************	
#define PLT_Comparator_0_Hysteresis_voltage (_pltc0hys|pltc0hys1)
#define PLT_Comparator_1_Hysteresis_voltage (_pltc1hys0|_pltc1hys1)
//***************************************
#define PLT_OPAMP_CONTROL _pltaen
//***************************************
#define PLT_OPA_Output_Status  _pltao
/*
PLTAO: PLT OPA output status (positive logic)
When PLTAOFM bit is set to 1, PLTAO is defined as PLT OPAMP output status,
please refer to Offset calibration procedure. When PLTAOFM bit is cleared to 0, this
bit will be fixed at a low level.
*/
//**************************************
#define PLT_OPA_Gain_Bandwidth_Control _pltabw
enum{
	_600kHz,
	_2MHz
};
//***************************************
#define PLT_Voltage_Calibration_Mode_Selection _pltaofm
enum
{
	Normal_Operation,
	Offset_Calibration_Mode
};
//***************************************

#define PLT_Input_Offset_Voltage_Calibration_Reference_Selection _pltarsp
enum 
{
  From_ANI,
  From_API	
};
//***************************************
#define PLT_Input_Offset_Voltage_Calibration_Value (_pltaof0|_pltaof1||_pltaof2||_pltaof3||_pltaof4||_pltaof5)&&
//*******************

void PLT0Receive(void);

#endif