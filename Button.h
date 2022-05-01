/*
 * Button.h
 *
 *  Created on: Apr 3, 2022
 *      Author: BN_Desouky
 */

#ifndef BUTTON_H_
#define BUTTON_H_


#ifndef __SW_H__
#define __SW_H__

#define PB_RELEASED_TIME_MAX_MS    (5000)
#define PB_PRESSED_TIME_MAX_MS     (5000)

typedef enum
{
    SW_INCREMENT,
    SW_RESET
}tSW;

typedef enum
{
    SW_RELEASED,
    SW_PRE_PRESSED,
    SW_PRESSED,
    SW_PRE_RELEASED
}tSW_State;

void SW_Init(void);
tSW_State SW_GetState(tSW sw);
void SW_Update(void);

#endif // __SW_H__


#endif /* BUTTON_H_ */
