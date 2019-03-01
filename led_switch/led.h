/*
 * led.h
 *
 * Created: 22-02-2019 1.59.24 PM
 *  Author: arunkumar
 */ 


#ifndef __LED_H__
#define __LED_H__

#define  STATUS_LED				(1u<<PB5)
#define  STATUS_LED_ON_TIME		(1000u)
#define  STATUS_LED_OFF_TIME	(1000u)


void led_init(void);
void led_status_on(void);
void led_status_off(void);

#endif /* __LED_H__ */