/*********************************************************************************************************
 * @file    A_KEY_DRV.h
*********************************************************************************************************/
#ifndef A_KEY_DRV_H__
#define A_KEY_DRV_H__

#include "BA45F5240.h"
#include "A_USE_MACRO.h"
#include "A_VAL_DEFINE.h"
#include "A_USE_LIB.h"

#if _KEY
#define C_KEY1_SDELAY		5

void S_KEY_Init(void);
void S_KEY_UPDATE(void);
void S_KEY_PROCESS(void);
#endif

#endif

