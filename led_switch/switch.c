/*
 * switch.c
 *
 * Created: 22-02-2019 3.23.56 PM
 *  Author: arunkumar
 */ 

#define F_CPU 16000000UL

#include <avr/io.h>
#include "switch.h"

void switch_init()
{
	DDRB &= ~switch_status;  /* Initialization of Switch */
}

void switch_on()
{
	PORTB |= switch_status; /* Make PORTB of PIN0 as HIGH */
}