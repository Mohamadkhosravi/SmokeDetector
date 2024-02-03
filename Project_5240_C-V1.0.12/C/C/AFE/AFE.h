#ifndef AFE_H__
#define AFE_H__
#include "BA45F5240.h"
#include "PLT.h"
//The macro name is defined by the user tag
#define OPA_ON		{S_SM_OPA_ON();}
#define OPA_OFF		{S_SM_OPA_OFF();}

void S_ADJ_OPA0();
void S_ADJ_OPA1();
void S_OPA_Init();
void S_SM_ISINK0_ON();
void S_SM_ISINK1_ON();
void S_SM_ISINK0_OFF();
void S_SM_ISINK1_OFF();

void S_SM_OPA_ON();
void S_SM_OPA_OFF();
void S_SM_TX0_DELAY();
void S_SM_TX1_DELAY();
void S_OPA_STATIME();
void S_BAT_CK_DELAY();
#endif
