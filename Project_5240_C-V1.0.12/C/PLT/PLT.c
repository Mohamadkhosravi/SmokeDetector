
#include "PLT.h"

#include "BA45F5240.h"
#include "A_USE_MACRO.h"
#include "ADC.h"
#include "RCC.h"
#include "AFE.h"
#include "GPIO.h"
#include "TM.h"
	
unsigned int value =0;

char PLT0InputOffsetCalibration(void){
int repeat=0;		
 S0_S2_ON_S1_OFF;
 PLT0_Input_Offset_Voltage_Calibration_Value(0);
 value=0;
 
 for(repeat=0;repeat<3;repeat++){
 	
  PLT0_Input_Offset_Voltage_Calibration_Value(value);
   if( PLT_Comparator_0_Output_Value){
   	VC0OS1=PLT0_Input_Offset_Voltage_Calibration_Value;	
   	repeat=0
   	break;
  }
  
 }
repeat=0;
value=0b11111;
for(repeat=0;repeat<5;repeat++){

  PLT0_Input_Offset_Voltage_Calibration_Value(value);
  if( PLT_Comparator_0_Output_Value)
  {
  	
   	VC0OS2=PLT0_Input_Offset_Voltage_Calibration_Value;	
   	repeat=0
   	break;
  }
  value--;
 }

};


char PLT0Recive(void){
		
	PLT_DAC0_Control=Enable;
	PLT_DAC0_VALUE=28;
	S0_S1_ON_S2_OFF;
	PLT_Comparator_0_Hysteresis_voltage(1); 
	PLT_Comparator_0_Current_Control_Value(1);
	PLT_OPAMP_0_CONTROL=Enable;

return PLT_OP0_Output_Status;

};
char PLT1Recive(void){
		
	PLT_DAC1_Control=Enable;
	PLT_DAC1_VALUE=28;
	S3_S4_ON_S5_OFF;
	PLT_Comparator_1_Hysteresis_voltage(1); 
	PLT_Comparator_1_Current_Control_Value(1);
	PLT_OPAMP_1_CONTROL=Enable;

return PLT_OP1_Output_Status;

};