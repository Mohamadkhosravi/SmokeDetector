#include "A_SOFTDEBUG_DRV.h"



#if _SOFTDEBUG
//===========================================================
//*@brief		: S_SFUART_Init
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_SFUART_Init(void)
{
	//TX -PA4
	PC_SFUART_TX=0;
	P_SFUART_TX=1;
	//RX -PA1
	P_SFUART_RX=1;
	PC_SFUART_RX=1;
	PU_SFUART_RX=1;
	_pac5=1;
	_papu5=0;
	
	//PA1 as INT1 IO
	_pas02=0;
	_pas03=0;
	//Falling edge trig
	_int1s1=1;
	_int1s0=0;
	//ISR EN
	_int1e=1;
}


//===========================================================
//*@brief		: S_SFUART_SEND(9600BPS)
//*@param[in]	: R_SFUART_DATA
//*@retval		: None
//===========================================================
void S_SFUART_SEND(unsigned char R_SFUART_DATA)
{
	asm("include BA45F5240.inc");
	asm("LOCAL	R_SFUART_TCNT		DB		?");
	asm("LOCAL	R_SFUART_TDAT		DB		?");
	asm("MOV	R_SFUART_TDAT,A");
	asm("ADDM	A,_R_SFCHECK_SUM");
	asm("CLR	EMI");
	asm("MOV	A,8");
	asm("MOV	R_SFUART_TCNT,A");
	P_SFUART_TX=0;
	#if _HIRCC_8M
		asm("JMP	$+1");
		asm("MOV	A,67");
	#elif _HIRCC_4M
		asm("MOV	A,33");
	#else
		asm("JMP	$+1");
		asm("MOV	A,15");
	#endif
	asm("SDZ	ACC");
	asm("JMP	$-1");
	
asm("L_SFUART_SEND_LOOP:");
	asm("SNZ	R_SFUART_TDAT.0");
	asm("JMP	L_SFUART_SEND_D0");
	asm("JMP	L_SFUART_SEND_D1");
asm("L_SFUART_SEND_D0:");
	asm("NOP");
	P_SFUART_TX=0;
	asm("JMP	L_SFUART_SEND_NEXT");
asm("L_SFUART_SEND_D1:");
	P_SFUART_TX=1;
	asm("JMP	L_SFUART_SEND_NEXT");
asm("L_SFUART_SEND_NEXT:");
	
	#if _HIRCC_8M
		asm("JMP	$+1");
		asm("MOV	A,65");
	#elif _HIRCC_4M
		asm("MOV	A,31");
	#else
		asm("JMP	$+1");
		asm("MOV	A,13");
	#endif
	asm("SDZ	ACC");
	asm("JMP	$-1");
	
	asm("RRC	R_SFUART_TDAT");
	asm("SDZ	R_SFUART_TCNT");
	asm("JMP	L_SFUART_SEND_LOOP");
	
	asm("MOV	A,2");
	asm("SDZ	ACC");
	asm("JMP	$-1");
	P_SFUART_TX=1;
	#if _HIRCC_8M
		asm("JMP	$+1");
		asm("MOV	A,69");
	#elif _HIRCC_4M
		asm("MOV	A,34");
	#else
		asm("JMP	$+1");
		asm("MOV	A,17");
	#endif
	asm("SDZ	ACC");
	asm("JMP	$-1");
	
	asm("SET	EMI");
}	


//===========================================================
//*@brief		: S_SFUART_RXINT(9600BPS)
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_SFUART_RXINT(void)
{
	unsigned char R_SFUART_RDAT;
	asm("LOCAL	R_SFUART_RCNT	DB		?");
	asm("P_SFUART_RX			EQU		PA1");
	
	asm("MOV	A,8");
	asm("MOV	R_SFUART_RCNT,A");
	#if _HIRCC_8M
		asm("MOV	A,27");
	#elif _HIRCC_4M
		asm("JMP	$+1");
		asm("MOV	A,9");
	#else
		asm("MOV	A,1");
	#endif
	asm("SDZ	ACC");
	asm("JMP	$-1");
		
	asm volatile ("CLR	%0" : "=m"(R_SFUART_RDAT): "m"(R_SFUART_RDAT));
asm("L_SFUART_RXINT_BLOOP:");
	#if _HIRCC_8M
		asm("NOP");
		asm("MOV	A,65");
	#elif _HIRCC_4M
		asm("JMP	$+1");
		asm("MOV	A,30");
	#else
		asm("NOP");
		asm("MOV	A,13");
	#endif
	asm("SDZ	ACC");
	asm("JMP	$-1");
	
	asm("CLR	C");
	asm volatile ("RRC	%0" : "=m"(R_SFUART_RDAT): "m"(R_SFUART_RDAT));
	asm("SZ		P_SFUART_RX");
	asm("JMP	L_SFUART_RXINT_D1");
	asm("JMP	L_SFUART_RXINT_D0");
asm("L_SFUART_RXINT_D1:");
	asm("NOP");
	asm volatile ("SET	%0.7" : "=m"(R_SFUART_RDAT): "m"(R_SFUART_RDAT));
	asm("JMP	L_SFUART_RXINT_N0");
asm("L_SFUART_RXINT_D0:");
	asm volatile ("CLR	%0.7" : "=m"(R_SFUART_RDAT): "m"(R_SFUART_RDAT));
	asm("JMP	L_SFUART_RXINT_N0");
asm("L_SFUART_RXINT_N0:");
	asm("SDZ	R_SFUART_RCNT");
	asm("JMP	L_SFUART_RXINT_BLOOP");
	
	R_SFUART_RXDAT[R_SFUART_RXCNT]=R_SFUART_RDAT;
	R_SFUART_RXCNT++;
	
	#if _HIRCC_8M
		GCC_DELAY(104);
	#elif _HIRCC_4M
		GCC_DELAY(52);
	#else
		GCC_DELAY(26);
	#endif
}


//===========================================================
//*@brief		: Software data processing
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_SFUART_DEAL(unsigned char *p)
{
	unsigned char i;
	unsigned char R_CHECK_DATA;
	R_CHECK_DATA=0;
	if(p[0]!=0xAA)
	{
		R_SFUART_RXCNT=0;
		return;
	}
	if(R_SFUART_RXCNT < sizeof(R_SFUART_RXDAT))
	{
		return;
	}
	for(i=0;i<11;i++)
	{
		R_CHECK_DATA+=p[i];
	}
	if(p[11]!=R_CHECK_DATA)
	{
		R_SFUART_RXCNT=0;
		return;
	}
	_sdpgac0		= p[2];
	_sdpgac1		= p[3]+(p[4]<<6);
	R_ISINK0_VALUE	= p[5];
	R_ISINK1_VALUE	= p[6];
	R_OPA_DELAY		= p[7];
	R_ISINK0_DELAY	= p[8];
	R_ISINK1_DELAY	= p[9];
	R_SM_BD_KQ_SET	= p[10];
	S_CLR_OUTPUT();
	F_SM_ALARM=0;
	
	F_BD_DATA_DONT_SAVE=1;
	S_SM_BD_AIR();
	for(i=0;i<12;i++)
	{
		p[i]=0;
	}
	R_SFUART_RXCNT=0;
}


//===========================================================
//*@brief		: Software debug data output
//*@param[in]	: None
//*@retval		: None
//===========================================================
void S_SOFTDEBUG_Output(void)
{
	R_SFCHECK_SUM=0;
	if(R_UART_RUNCNT==0)
	{
		S_SFUART_SEND(0XAA);					//0
		S_SFUART_SEND(17);						//1
		S_SFUART_SEND(_sdpgac0);				//2
		S_SFUART_SEND(_sdpgac1&(0X3F));			//3
		S_SFUART_SEND(_sdpgac1>>6);				//4
		S_SFUART_SEND(_isgdata0);				//5
		S_SFUART_SEND(_isgdata1);				//6
		S_SFUART_SEND(R_OPA_DELAY);				//7
		S_SFUART_SEND(R_ISINK0_DELAY);			//8
		S_SFUART_SEND(R_ISINK1_DELAY);			//9
		S_SFUART_SEND(R_SM_BD_ALARM);			//10
		S_SFUART_SEND(R_SYS_FG.byte);			//11
		S_SFUART_SEND(R_SM_FG.byte);			//12
		S_SFUART_SEND(R_BAT_ADC);				//13
		S_SFUART_SEND(R_T_ADC);					//14
		S_SFUART_SEND(R_SM_BD_ZERO);			//15
		S_SFUART_SEND(R_SM_ZERO_DATA);			//16
		S_SFUART_SEND(R_SM_IR_DATA);			//17
		S_SFUART_SEND(R_SM_DATA);				//18
		S_SFUART_SEND(R_SFCHECK_SUM);			//19
	}
}

#endif


