/*
 * Sepeha_Controller.c
 *
 *  Created on: Apr 3, 2022
 *      Author: BN_Desouky
 */

#include "Port.h"
#include "Main.h"
#include "Button.h"
#include "OS.h"
#include "Sepeha_Controller.h"



/*SEPEHA_Update period*/
#define SEPEHA_PERIOD_MS (20)

static uint16_t counter ;

void SEPEHA_init (void)
{
	counter = 0;
}




void SEPEHA_Update (void)
{
	static tWord Sep_Counter = 0;

	/*Check the time for the controller task to run*/
	Sep_Counter += TMR_TICK_MS;

	if (Sep_Counter != SEPEHA_PERIOD_MS)
	{
		return;
	}

	Sep_Counter = 0;
	if (SW_GetState(SW_INCREMENT) == SW_PRE_PRESSED)
	{
		counter ++;
	}
	else if (SW_GetState(SW_RESET) == SW_PRE_PRESSED)
	{
		counter = 0;
	}
	else
	{
		/*DO NOTHING HERE */
	}
}



uint16_t SEPEHA_GetValue (void)
{
	uint16_t  count;
	count = counter;
	return count;
}
