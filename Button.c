/*
 * Button.c
 *
 *  Created on: Apr 3, 2022
 *      Author: BN_Desouky
 */
#include "Main.h"
#include "Port.h"
#include "Timer.h"
#include "Button.h"

/*number of used buttons*/
#define N_SWITCHES              (2)
/* SW_Update period */
#define SW_PERIOD_MS            (20)
/* Number of samples per SW */
#define N_SAMPLES               (5)
/* SW voltage level */
#define SW_PRESSED_LEVEL        (0)
#define SW_RELEASED_LEVEL       (1)



/* SW info: samples, state */
typedef struct
{
    tByte sw_samples[N_SAMPLES];
    tSW_State sw_state;
    uint16_t pressed_time ;
    uint16_t released_time ;
}tSW_Info;

/* Switches info */
static tSW_Info SWs_Info[N_SWITCHES];

void SW_Init(void)
{
    uint8_t current_SW;
    uint8_t sample_index;
    /* Add your code here! */
    /* Initialize switches as inputs */
    GPIO_InitPortPin(SW_INCREMENT_PORT_CR, SW_INCREMENT_PIN, GPIO_IN);
    GPIO_InitPortPin(SW_RESET_PORT_CR, SW_RESET_PIN, GPIO_IN);

    /* Initialize switches info */
    for (current_SW = SW_INCREMENT; current_SW < N_SWITCHES; current_SW++)
    {
        /* Initialize switch samples */
        for (sample_index = 0; sample_index < N_SAMPLES; sample_index++)
        {
            SWs_Info[current_SW].sw_samples[sample_index] = SW_RELEASED_LEVEL;
        }
        /* Initialize sw state */
        SWs_Info[current_SW].sw_state = SW_RELEASED;

    }
    /* End of your code!*/
}


tSW_State SW_GetState(tSW sw)
{
    /* Add your code here! */
    /* return sw state */
    return SWs_Info[sw].sw_state;
    /* End of your code!*/
}


void SW_Update(void)
{
    static tWord SW_COUNTER_MS = 0;
    uint8_t current_SW = 0;
    uint8_t sample_index;
    /* Check if it is time for the SW_Update to run */
    SW_COUNTER_MS += TMR_TICK_MS;

    if (SW_COUNTER_MS != SW_PERIOD_MS){
        return;
    }

    SW_COUNTER_MS = 0;

    /* Update switches states */
    for (current_SW = SW_INCREMENT; current_SW < N_SWITCHES; current_SW++)
    {
        /* Add your code here! */
        /* Update switch samples */
        for(sample_index = 0; sample_index < N_SAMPLES-1; sample_index++)
        {
            SWs_Info[current_SW].sw_samples[sample_index] = SWs_Info[current_SW].sw_samples[sample_index+1];
        }
        switch(current_SW)
        {

        case SW_INCREMENT:
            SWs_Info[current_SW].sw_samples[sample_index] = GPIO_ReadPortPin(SW_INCREMENT_PORT_DR, SW_INCREMENT_PIN);
            break;
        case SW_RESET:
            SWs_Info[current_SW].sw_samples[sample_index] = GPIO_ReadPortPin(SW_RESET_PORT_DR, SW_RESET_PIN);
            break;
        default:
            /*should not be here*/
            break;
        }
        /* End of your code!*/

        /* Update switch state */
        /* Add your code here! */
        switch(SWs_Info[current_SW].sw_state)
        {

            case SW_RELEASED:
                if ((SWs_Info[current_SW].sw_samples[4] == SW_PRESSED_LEVEL)&&
                    (SWs_Info[current_SW].sw_samples[3] == SW_PRESSED_LEVEL)&&
                    (SWs_Info[current_SW].sw_samples[1] == SW_RELEASED_LEVEL)&&
                    (SWs_Info[current_SW].sw_samples[0] == SW_RELEASED_LEVEL))
                {
                    SWs_Info[current_SW].sw_state = SW_PRE_PRESSED;
                } else
                {
                    /* Do nothing */
                }
                break;
            case SW_PRE_PRESSED:
                /* Go to pressed state if needed  */
                if ((SWs_Info[current_SW].sw_samples[4] == SW_PRESSED_LEVEL)&&
                    (SWs_Info[current_SW].sw_samples[3] == SW_PRESSED_LEVEL)&&
                    (SWs_Info[current_SW].sw_samples[2] == SW_PRESSED_LEVEL))
                {
                    SWs_Info[current_SW].sw_state = SW_PRESSED;
                }
                else
                {
                    /* Do nothing */
                }
                break;
            case SW_PRESSED:
                /* Go to pre-released state if needed */
                if ((SWs_Info[current_SW].sw_samples[4] == SW_RELEASED_LEVEL)&&
                    (SWs_Info[current_SW].sw_samples[3] == SW_RELEASED_LEVEL)&&
                    (SWs_Info[current_SW].sw_samples[1] == SW_PRESSED_LEVEL)&&
                    (SWs_Info[current_SW].sw_samples[0] == SW_PRESSED_LEVEL))
                {
                    SWs_Info[current_SW].sw_state = SW_PRE_RELEASED;
                }
                else
                {
                    /* Do nothing */
                }
                break;
            case SW_PRE_RELEASED:
                /* Go to released state if needed */
                if ((SWs_Info[current_SW].sw_samples[4] == SW_RELEASED_LEVEL)&&
                    (SWs_Info[current_SW].sw_samples[3] == SW_RELEASED_LEVEL)&&
                    (SWs_Info[current_SW].sw_samples[2] == SW_RELEASED_LEVEL))
                {
                    SWs_Info[current_SW].sw_state = SW_RELEASED;
                } else
                {
                    /* Do nothing */
                }
                break;
            /* Should not be here */
            default:
                break;
        }
        /* End of your code!*/
    }

}
