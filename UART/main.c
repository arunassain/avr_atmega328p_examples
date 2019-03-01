/*
 * serial.c
 *
 * Created: 28-02-2019 11.39.02 AM
 * Author : arunkumar
 */ 
#define F_CPU 16000000UL
#include <stdio.h>
#include <avr/io.h>
#include <string.h>
#include <util/delay.h>

#define USART_BAUDRATE	9600
#define BAUD_PRESCALE	(((F_CPU / (USART_BAUDRATE * 16UL))) - 1) 

void USART0Init(void)
{
	// Set baud rate
	UBRR0H = (uint8_t)(BAUD_PRESCALE>>8);
	UBRR0L = (uint8_t)BAUD_PRESCALE;
	
	// Set frame format to 8 data bits, no parity, 1 stop bit
	UCSR0C |= (1<<UCSZ01)|(1<<UCSZ00);
	
	//enable transmission and reception
	UCSR0B |= (1<<RXEN0)|(1<<TXEN0);
}

void USART_Transmit(unsigned char data )
{
	/* Wait for empty transmit buffer */
	while ( !( UCSR0A & (1<<UDRE0)) )
	;
	/* Put data into buffer, sends the data */
	UDR0 = data;
}

// write null terminated string
void serial_write_str(const char* str)
{
	int len = strlen(str);
	int i;
	for (i = 0; i < len; i++) {
		USART_Transmit(str[i]);
	}
}

//
// END: serial comms
//

int main (void)
{
	
	// initialize USART
	USART0Init();

	while (1) {

		// print 
		serial_write_str("Hello world");
	}
	return 0;
}