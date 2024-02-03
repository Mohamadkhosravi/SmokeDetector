
#include "PLT.h"

#include "BA45F5240.h"
#include "A_USE_MACRO.h"
#include "ADC.h"
#include "RCC.h"
#include "AFE.h"
#include "GPIO.h"
#include "TM.h"
	




char PLT0Recive(void){
		
	PLT_DAC0_Control=Enable;
	PLT_DAC0_VALUE=28;
	S0_S1_ON_S2_OFF;
	PLT_Comparator_0_Hysteresis_voltage(1); 
	PLT_Comparator_0_Current_Control_Value(1);
	PLT_OPAMP_0_CONTROL=Enable;

return PLT_OP0_Output_Status;

};