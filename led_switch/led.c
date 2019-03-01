/*
 * led.c
 *
 * Created: 22-02-2019 2.04.56 PM
 *  Author: arunkumar
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "led.h"

void led_init()
{
	DDRB |= STATUS_LED;				/* Initialization of LED */
}

void led_status_on(void)			/* LED ON */
{
	PORTB |= STATUS_LED;		
	_delay_ms(STATUS_LED_ON_TIME);
}

void led_status_off(void)			/* LED OFF */
{
	PORTB &= ~STATUS_LED;
	_delay_ms(STATUS_LED_OFF_TIME);
}