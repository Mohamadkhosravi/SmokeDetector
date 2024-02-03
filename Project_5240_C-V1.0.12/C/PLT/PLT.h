#ifndef _PLT_H
#define _PLT_H

#define S0_S1_ON_S2_OFF  ((_pltc0ofm)&(_pltc0rsp))&0x0;
#define S0_S1_OFF_S2_ON
enum{
 Disable,
 Enable
};



//*******************************
#define PLTS2_Switch_Selection 	_plts2 
enum {
 Connect_to_PLTDAC2O,
 Connect_to_PLRX
};
//**********************************
#define PLTS1_Switch_Selection 	_plts1 
enum
{
 Connect_to_PLIS,
 Connect_to_LINEV 
};
//********************************
#define PLTS0_Switch_Selection 	_plts0
enum
{
 Connect_to_GND,
 Connect_to_OPAMP_output
};
//********************************
//Enable Or Disable 
#define PLT_DAC2_Control	_pltdac2en
#define PLT_DAC1_Control	_pltdac1en
#define PLT_DAC0_Control	_pltdac0en 

/********************************
D5~D0: PLT DAC0 output control code
PLTDAC0O= ( DAC VDD/26)× PLTDA0L[5:0]*/
#define PLT_DAC0_VALUE	_pltda0l
#define PLT_DAC1_VALUE	_pltda1l
#define PLT_DAC2_VALUE	_pltda2l
//**************************
#define PLT_DAC0_Output 

//********************************
//Enable Or Disable 
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
#define PLT_Comparator_0_Debounced_Output 	_pltc0o
#define PLT_Comparator_1_Debounced_Output	_pltc1o
#define PLT_Comparator_2_Debounced_Output	_pltc2o
//*************************
#define PLT_Comparator_0_Debounce_Time_Value(time) _pltc0c=(time&2)<<2//_pltc0deb1|_pltc0deb0
#define PLT_Comparator_1_Debounce_Time_Value(time) _pltc1c=(time&2)<<2//_pltc1deb1|_pltc1deb0
#define PLT_Comparator_2_Debounce_Time_Value(time) _pltc2c=(time&2)<<2//_pltc2deb1|_pltc2deb0
 enum{
	 No_debounce,
	_31to32_tSYS,
	_63to64_tSYS,
	_126to127_tSYS
 };

//***********************************************
#define PLT_Comparator_0_Current_Control_Value(value)   _pltc0c=value&2 //_pltc0is1|_pltc0is0
#define PLT_Comparator_1_Current_Control_Value(value)	_pltc1c=value&2  //_pltc0is1|_pltc0is0
#define PLT_Comparator_2_Current_Control_Value(value)	_pltc2c=value&2  //_pltc0is1|_pltc0is0
//*************************************************
#define PLT_Comparator0_Or_Comparator1_Output_selection  _pltcxosw
enum
{
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
//*****************************
#define PLT_Comparator_0_Output_Value _pltc0out
#define PLT_Comparator_1_Output_Value _pltc1out
#define PLT_Comparator_2_Output_Value _pltc2out

//****************************************	
// PLT Comparator Hysteresis voltage (pltc1hys1|pltc1hys0|_pltc0hys1|pltc0hys0) max value 2
#define PLT_Comparator_0_Hysteresis_voltage(voltage)  _pltchyc=voltage&2  
#define PLT_Comparator_1_Hysteresis_voltage(voltage)  _pltchyc=(voltage&2)<<2
//***************************************
//Enable Or Disable 
#define PLT_OPAMP_0_CONTROL _pltc0en

//***************************************
#define PLT_OPA_Output_Status  _pltao
#define PLT_OP0_Output_Status  _pltc0o
#define PLT_OP1_Output_Status  _pltc1o
/*
PLTAO: PLT OPA output status (positive logic)
When PLTAOFM bit is set to 1, PLTAO is defined as PLT OPAMP output status,
please refer to Offset calibration procedure. When PLTAOFM bit is cleared to 0, this
bit will be fixed at a low level.
*/
//**************************************
#define PLT_OPA_Gain_Bandwidth_Control	_pltabw
enum{
 _600kHz,
 _2MHz
};
//***************************************
#define PLT_Voltage_Calibration_Mode_Selection	_pltaofm
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
//_pltaof5|_pltaof4||_pltaof3||_pltaof2||_pltaof1||_pltaof0
#define PLT_Input_Offset_Voltage_Calibration_Value(value) _pltavos=value&5

//*******************

char PLT0Receive(void);

#endif