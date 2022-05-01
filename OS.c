/*
 * OS.c
 *
 *  Created on: Apr 3, 2022
 *      Author: BN_Desouky
 */

#include "Main.h"
#include "OS.h"
#include "Button.h"
#include "Sepeha_Controller.h"
#include "SSegment.h"

extern tByte flag;

void OS_Init(void)
{
	/* Add your code here! */
	TMR_SET_PRESCALER_256;
	TMR_DISABLE_CLOCK;
	/* End of your code!*/
}
void OS_Start(void)
{
	/* Add your code here! */
	TMR_CLEAR_FLAG;
	TMR_UPDATE_REGISTER(TMR_TICK_MS);
	TMR_ENABLE_INTERRUPT;
	GLOBAL_INTERRUPT_ENABLE;
	TMR_ENABLE_CLOCK;
	/* End of your code!*/
}
tByte TMR_CheckOverFlow(void)
{
	/* Add your code here! */
	return TMR_GET_FLAG;
	/* End of your code!*/
}
void TMR_Stop(void)
{
	/* Add your code here! */
	TMR_DISABLE_CLOCK;
	/* End of your code!*/
}

void TMR_Update(void) __interrupt 0
{
	/* Add your code here! */
    //RC7 = 1 ^ RC7;
	/* Call Tasks */
	//flag = 1;

    /* Reload timer */
	TMR_CLEAR_FLAG;
	TMR_UPDATE_REGISTER(TMR_TICK_MS);

    RC7 = 1 ^ RC7;
    SW_Update();
    SEPEHA_Update();
    SSD_Update();

	/* End of your code!*/

}

