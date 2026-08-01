/*
 * Driver_ADCatm8.c
 *
 * Created: 27.07.2026 21:39:49
 * Author : rakel
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <stdint.h>
#include "Driver_ADCatm8.h"


ADC_Config config = {
	.conversionMode = ADC_SINGLE_CONVERSION,
	.reference      = ADC_REF_VCC,
	.prescaler      = ADC_PRECALER_64,
	.resultAlign    = ADC_ALIGN_RIGHT
};


int main(void)
{
	adc_Init(&config);
    
    while (1) 
    {
        adc_Read(ADC_CHANNEL_5);
		
    }
}

