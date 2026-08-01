

  # Driver_ADCatm8

 A lightweight ADC driver for the ATmega8 microcontroller.

 The driver provides a simple API for configuring and reading the internal 10-bit Analog-to_Digital Converter(ADC) without direct register manipulation

 ------------------------------------------------------------------

  ## Features

 - 10-bit ADC support

 - Single Conversion Mode

 - Free Running Mode

 - Runtime channel selection

 - AVCC and Internal 2.56V reference support

 - Left and Right result alignment

 - Configurable ADC prescaler
 
 - Simple configuration structure

 - Lightweight and easy to integrate

-------------------------------------------------------------------

 ## Folder Structure

 - include/  - Header files
 - src/      - Source files
 - examples/ - Usage examples
 - docs/     - Documentation

-------------------------------------------------------------------


  ## Example

  ```c
  ADC_Config config =
  {
    .reference = ADC_REF_VCC,
    .mode = ADC_SINGLE_CONVERSION,
    .prescaler = ADC_PRESCALER_64,
    .align = ADC_ALIGN_RIGHT
  };

 int main(void)
 {

  adc_Init(&config); 

  while(1)
  {
   uint16_t adcValue = adc_Read(ADC_CHANNEL5);
  }

 }

 
 ## Ready-to-use examples can be found in the examples/directory

-----------------------------------------------------------------------

 # Configuration

 ## The driver supports:

 - ADC reference voltage selection

 - ADC prescaler configuration

 - Result alignment (Left/Right)

 - Single Conversion mode

 - FreeRunning mode

 - Runtime ADC channel selection

-------------------------------------------------------------------------

 # Tested

 - ATmega8 (8000000MHz)
 
 - Single Conversion Mode

 - Free Running Mode

 - Runtime channel switching

 - 10-bit ADC conversion verified on real hardware
 

---------------------------------------------------------------------------

 # Development Environment

 - Microcontroller: ATmega8

 - IDE:             Microchip Studio

--------------------------------------------------------------------------

 # Documentation

 Additional documentation is available in the docs/ directory

-----------------------------------------------------------------------

  # License

 This project is released under the MIT License



 

 