/*
 * uart.c
 *
 * Created: 04.07.2026 00:40:33
 *  Author: rakel
 */ 

#include "Driver_UARTatm8.h"
#include <stdint.h>

void uart_Init()
{
	// 1) –ежим работы UART/USART  бит UMSEL в регистре UCSRC 0 - UART 1 - USART (0 по умолчанию)
	// 2) —корость 9600 boud       скорость регулируетс€ числом в регистре UBRL(таблица значений в даташите в разделе USART)U2X = 0 (по умолчанию)
	// 3) Ѕит четности             бит четности включаетс€ в регистре UCSRC битами UPM1, UPM0 (по умолчанию они оба в 0 это значит Ѕ»“ четности отключен)
	// 4)  оличество датабит       выставл€етс€ битами UCSZ2 : 0 в регистре UCSRB->UCSZ2, в регистре UCSRC->UCSZ1:0(по умолчанию стоит 8 бит)
	// 5)  оличество стопбитов    количество стоп битов включаетс€ битом USBS в регистре UCSRC (0 - 1 бит, 1 - 2 бита) по умолчанию стоит значение 0(1бит)
	// 6) –азрешить прием/передачу  выставл€етс€ битами RXEN, TXEN в регистре UCSRB
	
	/* 1) */   // Ќичего не пишем режим UART включен по умолчанию
	/* 2) */    /*UCSRA |= (1 << U2X);*/UBRRL = 51;
	/* 3) */   // Ќичего не пишем бит четности отключен по умолчанию
	/* 4) */   // Ќичего не пишем по умолчанию установлено 8 датабит
	/* 5) */   // Ќичего не ставим по умолчанию стоит один бит (значение 0)
	/* 6) */   UCSRB |= (1 << RXEN) | (1 << TXEN);
}

void uart_SendChar(char simbol)
{
	while(!(UCSRA & (1 << UDRE)));
	UDR = simbol;
	_delay_ms(2);
}

uint8_t uart_SendCharHex(uint8_t value)
{
	switch(value)
	{
		case 0: return (value + '0'); break;
		case 1: return (value + '0'); break;
		case 2: return (value + '0'); break;
		case 3: return (value + '0'); break;
		case 4: return (value + '0'); break;
		case 5: return (value + '0'); break;
		case 6: return (value + '0'); break;
		case 7: return (value + '0'); break;
		case 8: return (value + '0'); break;
		case 9: return (value + '0'); break;
		case 10: return (value + 55);break;
		case 11: return (value + 55);break;
		case 12: return (value + 55);break;
		case 13: return (value + 55);break;
		case 14: return (value + 55);break;
		case 15: return (value + 55);break;
		default: return 63;          break;
	}
	
}

void uart_SendHex8(uint8_t value)
{
	uint8_t Htetr = (value & 0xF0) >> 4;
	uint8_t Ltetr = (value & 0x0F);
	
	while(!(UCSRA & (1 << UDRE)));
	UDR = uart_SendCharHex(Htetr);
	_delay_ms(2);                   // эта задержка уберетс€ после того как поставитс€ внешний кварц
	while(!(UCSRA & (1 << UDRE)));
	UDR = uart_SendCharHex(Ltetr);
	_delay_ms(2);                   // эта задержка уберетс€ после того как поставитс€ внешний кварц
	
}

void uart_SendHex32(uint32_t value)
{
	uart_SendHex8((uint8_t)(value >> 24));
	_delay_ms(2);
	uart_SendHex8((uint8_t)(value >> 16));
	_delay_ms(2);
	uart_SendHex8((uint8_t)(value >> 8));
	_delay_ms(2);
	uart_SendHex8((uint8_t)value);
	_delay_ms(2);
}

void uart_SendString(char *str)
{
	uint8_t i= 0;
	while(str[i])
	{
		while(!(UCSRA & (1 << UDRE)));
		UDR = str[i];
		i++;
	}
}
 