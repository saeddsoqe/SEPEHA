
#include "Main.h"
#include "Port.h"
#include "Button.h"
#include "SSegment.h"
#include "Sepeha_Controller.h"
#include "OS.h"



tWord __at(0x2007) CONFIG = _HS_OSC & _WDT_OFF & _PWRTE_ON & _BODEN_OFF & _LVP_OFF & _CPD_OFF & _WRT_OFF & _DEBUG_OFF & _CP_OFF;



void main (void)
{
	/*Initializations*/
	SW_Init();
	SEPEHA_init();
	SSD_Init();
    OS_Init();
	/*Start OS*/
	OS_Start();
	while(1)
	{
		/**/
	}
}
