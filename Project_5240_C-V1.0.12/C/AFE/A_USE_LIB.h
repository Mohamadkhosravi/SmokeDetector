#ifndef A_USE_LIB_H__
#define A_USE_LIB_H__
#include "A_VAL_DEFINE.h"
//External declaration of variables in the library
extern unsigned char R_ISINK0_VALUE;
extern unsigned char R_ISINK1_VALUE;
extern unsigned char R_ISINK0_DELAY;
extern unsigned char R_ISINK1_DELAY;
extern unsigned char R_OPA_DELAY;
extern unsigned char R_INTERRESIST_DELAY;
extern unsigned char R_VDD_CK_SPACE_C;
extern unsigned char R_SM_BD_ZERO_MIN;
extern unsigned char R_SM_BD_ZERO_MAX;
extern unsigned char R_SM_BD_KQ_SET;
extern unsigned char R_SM_ZERO_DATA;			//zero AD
extern unsigned char R_SM_IR_DATA;				//IR AD
extern unsigned char R_SM_DATA;					//R_SM_IR_DATA-R_SM_ZERO_DATA
extern unsigned char R_T_ADC;					//Temperature AD
extern unsigned char R_BAT_CK_SPACE;
extern unsigned char R_VDD_ADC[2];
extern unsigned char R_SM_TMP[2];
extern unsigned char R_SM_ALARM;
extern unsigned char R_SM_BD_ZERO;
extern unsigned char R_VDD_RL_ADC[2];
extern unsigned char R_SM_BD_ALARM;				//Alarm threshold
extern unsigned char R_CACL_A_H;
extern unsigned char R_CACL_A_L;
extern unsigned char R_CACL_B_H;
extern unsigned char R_CACL_B_L;
extern unsigned char R_TMP0;
extern unsigned char R_TMP1;
extern unsigned char R_TMP2;
extern unsigned char R_TMP3;

extern byte_type R_SM_FG;
#define		F_SM_ERR		R_SM_FG.bits.bit0	//ERROR MODE
#define		F_SM_ALARM		R_SM_FG.bits.bit1	//ALARM MODE
#define		F_SM_PRE_ALARM	R_SM_FG.bits.bit2	
#define		F_SM_BD			R_SM_FG.bits.bit3	//BD MODE
#define		F_SM_BD_OK		R_SM_FG.bits.bit4	//BD FINISH BIT

extern byte_type R_SM_LIB_STATE;
#define		F_V_CONVER		R_SM_LIB_STATE.bits.bit0
#define		F_UL_BAT_L		R_SM_LIB_STATE.bits.bit1

//===========================================================
//*@brief		: Read SMOKE AD
//*@param[in]	: None
//*@retval		: None
//*@note		: £¨Global variable£©
//					R_SM_ZERO_DATA(zero AD)
//					R_SM_IR_DATA(IR AD )
//					R_SM_DATA(R_SM_IR_DATA - R_SM_ZERO_DATA)
//===========================================================
extern void S_READ_SMOKE_DATA(void);

//===========================================================
//*@brief		: SMOKE Init
//*@param[in]	: None
//*@retval		: None
//===========================================================
extern void S_SM_INI(void);

//===========================================================
//*@brief		: Calibrate in air
//*@param[in]	: None
//*@retval		: None
//===========================================================
extern void S_SM_BD_AIR(void);

//===========================================================
//*@brief		: Calibrate in smoke
//*@param[in]	: None
//*@retval		: None
//===========================================================
extern void S_SM_BD_SM(void);

//===========================================================
//*@brief		: Calibrate the zero value of the smoke sensor
//*@param[in]	: None
//*@retval		: None
//===========================================================
extern void S_SM_BD_ZERO(void);

//===========================================================
//*@brief		: Calibrate the alarm value of the smoke sensor
//*@param[in]	: None
//*@retval		: None
//===========================================================
extern void S_SM_BD_ALARM(void);

//===========================================================
//*@brief		: Infrared tube fault detect
//*@param[in]	: None
//*@retval		: (Global variable) F_SM_ERR£º1:Fault  0:Normal
//===========================================================
extern void S_SM_IR_ERR_CHECK(void);

//===========================================================
//*@brief		: Smoke alarm detect
//*@param[in]	: None
//*@retval		: (Global variable) F_SM_ALARM£º1:Alarm  0:Normal
//===========================================================
extern void S_SM_ALARM_CHECK(void);

//===========================================================
//*@brief		: Software calculation function
//*@param[in]	: None
//*@retval		: None
//===========================================================
extern void S_SUR_MUL_16_8_CALC(void);
extern void S_SBR_DIV_16_CALC(void);

#endif