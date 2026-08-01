/*
 * Driver_ADCatm8.c
 *
 * Created: 27.07.2026 23:35:41
 *  Author: rakel
 */ 

#define F_CPU 8000000UL
#include "Driver_ADCatm8.h"
#include <avr/io.h>
#include <util/delay.h>

static ADC_Mode currentMode; // переменная которая устанавливается в void adc_Init(ADC_Mode mode); и используется в функции uint16_t adc_Read(ADC_Channel channel);
static uint16_t adc_ReadSingleMode(ADC_Channel channel);
static uint16_t adc_ReadFreeRunningMode(ADC_Channel chanel);

_Static_assert(sizeof(ADC_Config) == 4, "Error: Structure ADC_Config must have 4 bytes"); // Проверка размера структуры ADC_Config

void adc_Init(ADC_Config *config)
{
	/*1*/ //Включаем ADC (Бит ADEN в регистре ADCSRA возводим в"1")
	
	/*2*/ //Устанавливаем режим: (Free Runing Mode->В регистре ADCSRA бит ADFR возводим в "1" )
	      //или (Single Conversion Mode->в регистре ADCSRA бит ADSC возводим в "1")
		  
    /*3*/ //Устанавливаем источник опорного напряжения (В регистре ADMUX комбинацией битов REFS0 и REFS1) 
	
	/*4*/ //Устанавливаем предделитель частоты контроллера для установки частоты дискретизации (в регистре ADSRA комбинация битов ADPS2,ADPS1,ADPS0)
	      //(для данного ADC оптимальная частота 125000Гц)
	
	/*5*/ //Устанавливаем выравнивание регистров либо по левому краю либо по правому краю
	      //(В регистре ADMUX бит ADLAR->"1"-выравнивание по правому краю; "0"- по левому
		  
    /*6*/ //ЕСЛИ установлен режим Free Running Делаем первый запуск ADC; -> ADCSRA |= (1 << ADSC); 
	
		  
    /*1*/ ADCSRA |= (1 << ADEN);        // ЭТОТ ПУНКТ ПЕРЕСМОТРЕТЬ ПО НАДОБНОСТИ!!!!
	
	/*2*/ ADCSRA |= config->conversionMode;
	  currentMode = config->conversionMode;
	
	/*3*/ ADMUX  |= config->reference;
	
	/*4*/ ADCSRA |= config->prescaler;
	
	/*5*/ ADMUX  |= config->resultAlign;
	
	/*6*/ if(config->conversionMode == ADC_FREE_RUNNING_CONVERSION)
	       {
			   ADCSRA |= (1 << ADSC);
		   }
	
}

 static uint16_t adc_ReadSingleMode(ADC_Channel channel)
{
	ADMUX = (ADMUX & 0xF0) | channel;
	
	ADCSRA |= (1 << ADSC);
	while(ADCSRA & (1 << ADSC));
	
	return ADC;
}

 static uint16_t adc_ReadFreeRunningMode(ADC_Channel channel)
{
	ADMUX = (ADMUX & 0xF0) | channel;
	
	while(!(ADCSRA & (1 << ADIF)));
	ADCSRA |= (1 << ADIF);
	
	while(!(ADCSRA & (1 << ADIF)));
	ADCSRA |= (1 << ADIF);
	
	return ADC;
}

uint16_t adc_Read(ADC_Channel channel)
{
  if(currentMode == ADC_SINGLE_CONVERSION)
  {
	  return adc_ReadSingleMode(channel);
  }else
  {
	  return adc_ReadFreeRunningMode(channel);
  }
	
}