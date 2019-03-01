/*
 * switch.h
 *
 * Created: 22-02-2019 2.23.41 PM
 *  Author: arunkumar
 */ 


#ifndef __SWITCH_H__
#define __SWITCH_H__

#define  switch_status		(1u<<PB0)

void switch_init(void);
void switch_on(void);

#endif /* SWITCH_H__ */