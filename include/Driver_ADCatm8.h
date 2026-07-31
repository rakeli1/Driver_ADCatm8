/*
 * Driver_ADCatm8.h
 *
 * Created: 27.07.2026 23:35:04
 *  Author: rakel
 */ 



#ifndef DRIVER_ADCATM8_H_
#define DRIVER_ADCATM8_H_
#include <stdint.h>
#include <avr/io.h>


typedef enum
{
	ADC_SINGLE_CONVERSION       = (1 << ADSC),
	ADC_FREE_RUNNING_CONVERSION = (1 << ADFR)
	
}__attribute__((packed)) ADC_Mode;

typedef enum
{
	ADC_REF_AREF = 0x00,                            // используется опорное напряжение которое я подключу к пину AREF
	ADC_REF_VCC  = (1 << REFS0),                    // используется опорное напряжение питания микроконтроллера (в этом режиме установить конденсатор 0.1,мкФ м-у GND и пином AREF)
	ADC_REF_INTERNAL = (1 << REFS1) | (1 << REFS0)  // используется опорное напряжение внутренннее встроеное в микроконтроллер 2.56В 
	                                                // (в этом режиме установить конденсатор 0.1мкФ м-у GND и пином AREF)
	
}__attribute__((packed)) ADC_Reference;

typedef enum
{
	ADC_PRESCALER_2   = (1 << ADPS0),
	ADC_PRESCALER_4   = (1 << ADPS1),
	ADC_PRESCALER_8   = (1 << ADPS1) | (1 << ADPS0),
	ADC_PRESCALER_16  = (1 << ADPS2),
	ADC_PRESCALER_32  = (1 << ADPS2) | (1 << ADPS0),
	ADC_PRECALER_64   = (1 << ADPS2) | (1 << ADPS1),
	ADC_PRESCALER_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0)
	
}__attribute__((packed)) ADC_Prescaler;

typedef enum
{
	/**Для ATmega8 в корпусе DIP28 Каналов - 6; для других МК возможно два дополнительных*/
	ADC_CHANNEL_0 = 0,
	ADC_CHANNEL_1 = 1,
	ADC_CHANNEL_2 = 2,
	ADC_CHANNEL_3 = 3,
	ADC_CHANNEL_4 = 4,
	ADC_CHANNEL_5 = 5
	
	
}__attribute__((packed)) ADC_Channel;

typedef enum 
{
	ADC_ALIGN_RIGHT = 0x00,
	ADC_ALIGN_LEFT  = (1 << ADLAR)
	
}__attribute__((packed)) ADC_Align;

typedef struct 
{
	/**Conversion mode*/
	ADC_Mode conversionMode;
	
	/**Voltage reference*/
	ADC_Reference reference;
	
	/**ADC clock prescaler*/
	ADC_Prescaler prescaler;
	
	/**Registers ADCL and ADCH align*/
	ADC_Align resultAlign;
	 
}ADC_Config;


void adc_Init(ADC_Config *config);
uint16_t adc_Read(ADC_Channel channel);
	 

#endif /* DRIVER_ADCATM8_H_ */