/*
 * Port.h
 *
 *  Created on: Apr 3, 2022
 *      Author: BN_Desouky
 */

#ifndef __PORT_H__
#define __PORT_H__

#include "Main.h"

#define LEDs                    (0)
#define BUTTON                  (1)
#define SSegment                (1)

#if LEDs
/* Leds' pins */
#define LED_1_PORT_DR           (GPIO_PORTB_DATA)
#define LED_1_PORT_CR           (GPIO_PORTB_CONTROL)
#define LED_1_PIN               (GPIO_PIN_0)

#define LED_2_PORT_DR           (GPIO_PORTB_DATA)
#define LED_2_PORT_CR           (GPIO_PORTB_CONTROL)
#define LED_2_PIN               (GPIO_PIN_1)

#define LED_3_PORT_DR           (GPIO_PORTB_DATA)
#define LED_3_PORT_CR           (GPIO_PORTB_CONTROL)
#define LED_3_PIN               (GPIO_PIN_2)

#define LED_4_PORT_DR           (GPIO_PORTB_DATA)
#define LED_4_PORT_CR           (GPIO_PORTB_CONTROL)
#define LED_4_PIN               (GPIO_PIN_3)

#endif

#if BUTTON
/* Fill missing code below */
/* Switches */
#define SW_INCREMENT_PORT_DR    (GPIO_PORTB_DATA)
#define SW_INCREMENT_PORT_CR    (GPIO_PORTB_CONTROL)
#define SW_INCREMENT_PIN        (GPIO_PIN_0)

#define SW_RESET_PORT_DR        (GPIO_PORTB_DATA)
#define SW_RESET_PORT_CR        (GPIO_PORTB_CONTROL)
#define SW_RESET_PIN            (GPIO_PIN_1)

#define SW_SET_PORT_DR          (GPIO_PORTB_DATA)
#define SW_SET_PORT_CR          (GPIO_PORTB_CONTROL)
#define SW_SET_PIN              (GPIO_PIN_2)

#endif

#if SSegment
/* SSD */
#define SSD_DATA_PORT_DR        (GPIO_PORTD_DATA)
#define SSD_DATA_PORT_CR        (GPIO_PORTD_CONTROL)

#define SSD_THOUSANDS_DR        (GPIO_PORTB_DATA)
#define SSD_THOUSANDS_CR        (GPIO_PORTB_CONTROL)
#define SSD_THOUSANDS_PIN       (GPIO_PIN_7)

#define SSD_HUNDREDS_DR         (GPIO_PORTB_DATA)
#define SSD_HUNDREDS_CR         (GPIO_PORTB_CONTROL)
#define SSD_HUNDREDS_PIN        (GPIO_PIN_6)

#define SSD_TENS_DR             (GPIO_PORTB_DATA)
#define SSD_TENS_CR             (GPIO_PORTB_CONTROL)
#define SSD_TENS_PIN            (GPIO_PIN_5)

#define SSD_UNITS_DR            (GPIO_PORTB_DATA)
#define SSD_UNITS_CR            (GPIO_PORTB_CONTROL)
#define SSD_UNITS_PIN           (GPIO_PIN_4)

#endif // SSegment

#endif // __PORT_H__
