
#include "PLT.h"

#include "BA45F5240.h"
#include "A_USE_MACRO.h"
#include "ADC.h"
#include "RCC.h"
#include "AFE.h"
#include "GPIO.h"
#include "TM.h"
	

unsigned int VC0OS1=0;
unsigned int VC0OS2=0;
unsigned int VC1OS1=0;
unsigned int VC1OS2=0;

int PLT0InputOffsetCalibration(void){
	
	int repeat=0;	
	static unsigned int value =0;
	
	PLT0_Voltage_Calibration_Mode_Selection = Offset_Calibration_Mode;
	S0_S2_ON_S1_OFF;
	PLT0_Input_Offset_Voltage_Calibration_Value(0);
	value=1;
	 
	for(repeat=0;repeat<3;repeat++){
		
		value+=repeat;
		PLT0_Input_Offset_Voltage_Calibration_Value(value);
		VC0OS1=value;
		if( PLT_Comparator_0_Output_Value){
			repeat=0;
			break;
		}
	
	}
	repeat=0;
	value=0b11111;
	for(repeat=0;repeat<5;repeat++){
		
		value-=repeat;
		PLT0_Input_Offset_Voltage_Calibration_Value(value);
		VC0OS2=value;
		if( PLT_Comparator_0_Output_Value)
		{	
			repeat=0;
			break;
		}
	 
	}
	 value= (int)(VC0OS1+VC0OS2)/2;
	 PLT0_Input_Offset_Voltage_Calibration_Value(value);
//_pltc0of0=1;
//_pltc0of1=1;
//_pltc0of2=1;
//_pltc1of3=1;
//_pltc1of4=1;

     return (value);
};


int PLT1InputOffsetCalibration(void){
	
	int repeat=0;	
	static unsigned int value =0;
	
	PLT1_Voltage_Calibration_Mode_Selection = Offset_Calibration_Mode;
	S3_S5_ON_S4_OFF;

	PLT1_Input_Offset_Voltage_Calibration_Value(0);
	value=1;
	 
	for(repeat=0;repeat<3;repeat++){
		
		value+=repeat;
		PLT1_Input_Offset_Voltage_Calibration_Value(5);
		VC1OS1=value;
		if( PLT_Comparator_1_Output_Value){
				
			repeat=0;
			break;
	 	} 
	    
	}
	repeat=0;
	value=0b11111;
	for(repeat=0;repeat<5;repeat++){
		
		value-=repeat;
		PLT1_Input_Offset_Voltage_Calibration_Value(value);
		VC1OS2=value;
		if( PLT_Comparator_1_Output_Value)
		{
			
			repeat=0;
			break;
		}
	 
	}
	 value= (int)(VC1OS1+VC1OS2)/2;

	PLT1_Input_Offset_Voltage_Calibration_Value(value);
	
     return (value);
};


int PLT0AmplifierInputOffsetCalibration(void)
{
	int repeat=0;	
	static unsigned int value =0;
	PLT0_Voltage_Calibration_Mode_Selection = Offset_Calibration_Mode;
	S0_S2_ON_S1_OFF;
	PLT0_Input_Offset_Voltage_Calibration_Value(0);
	value=1;
	 
	for(repeat=0;repeat<2;repeat++){
		
		value+=repeat;
		PLT0_Input_Offset_Voltage_Calibration_Value(value);
		VC0OS1=value;
		if( PLT_Comparator_0_Output_Value){
			repeat=0;
			break;
		}
	
	}
	repeat=0;
	value=0b11111;
	for(repeat=0;repeat<4;repeat++){
		
		value-=repeat;
		PLT0_Input_Offset_Voltage_Calibration_Value(value);
		VC0OS2=value;
		if( PLT_Comparator_0_Output_Value)
		{	
			repeat=0;
			break;
		}
	 
	}
	 value= (int)(VC0OS1+VC0OS2)/2;
	 PLT0_Input_Offset_Voltage_Calibration_Value(value);
	
     return (value);
	
	
}


char PLT0Recive(void){
	PLT0_Voltage_Calibration_Mode_Selection	= Normal_Operation;	
	PLT_DAC0_Control=Enable;
	PLT_DAC0_VALUE=22;
	S0_S1_ON_S2_OFF;
	PLT_Comparator_0_Hysteresis_voltage(0); 
	PLT_Comparator_0_Current_Control_Value(0);
	PLT_OPAMP_0_CONTROL=Enable;

return PLT_OP0_Output_Status;

};
char PLT1Recive(void){
	PLT1_Voltage_Calibration_Mode_Selection	= Normal_Operation;		
	PLT_DAC1_Control=Enable;
	PLT_DAC1_VALUE=30;
	S3_S4_ON_S5_OFF;
	PLT_Comparator_1_Hysteresis_voltage(0); 
	PLT_Comparator_1_Current_Control_Value(0);
	PLT_OPAMP_1_CONTROL=Enable;

return PLT_OP1_Output_Status;

};