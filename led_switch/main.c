/*
 * key_led.c
 *
 * Created: 22-02-2019 1.54.47 PM
 * Author : arunkumar
 */ 
#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "led.h"
#include "switch.h"


int main(void)
{
	led_init();
	switch_init();
	switch_on();
    while (1) 
    {
		if (!(switch_status & STATUS_LED)) /* If Switch is pressed */
		{
			led_status_on();
		}
		else
		{
			led_status_off();
    }
}
}

