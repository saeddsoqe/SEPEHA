/*
 * OS.h
 *
 *  Created on: Apr 3, 2022
 *      Author: BN_Desouky
 */

#ifndef OS_H_
#define OS_H_

#include "Main.h"

#define TMR_INTERRUPT_ENABLE	    /* 0 --> Interrupts disabled */
									/* 1 --> Interrupts enabled */

#define TMR_TICK_MS				(5) /* HCF(P1, P2, ..., PN) */

void OS_Init(void);
void OS_Start(void);
tByte TMR_CheckOverFlow(void);
void TMR_Stop(void);
void TMR_Update(void) __interrupt 0; /* ISR @  vector 0 */

#endif /* OS_H_ */
