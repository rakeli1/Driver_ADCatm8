

   # ADC Driver API

   This document describes the public API of Driver_ADCatm8.

==================================================================

   # Initialization

   ## adc_Init()

   Initializes the ADC peripheral using the specified configuration.

   ### Prototype

   void adc_Init(const ADC_Config *config);
   ### Parameters

   | Parameter | Description                                 |
   |-----------|---------------------------------------------|
   | config    | Pointer to the ADC configuration structure. |

   ### Description

   This function configures:

   - Reference voltage
   - Conversion mode
   - Result alignment
   - ADC prescaler
   - ADC enable
   - If Free Running Mode is set, it triggers the ADC

====================================================================

   # Read ADC Value

   ## adc_Read()

   Performs an ADC conversion and returns the conversion result.

   ### Prototype

   uint16_t adc_Read(ADC_Channel channel);
   ### Parameters

   | Parameter | Description                |
   |-----------|----------------------------|
   | channel   | ADC input channel to read. |

   ### Return value

   Returns a 10-bit ADC conversion result.

   Range:

   0 ... 1023
   ### Description

   Depending on the selected ADC mode:

      1). ADC_SINGLE_CONVERSION 

  - Selects the requested channel
  - Starts a new conversion
  - Waits until conversion is complete
  - Returns the conversion result

      2). ADC_FREE_RUNNING_CONVERSION

  - Waits for a completed conversion
  - Automatically handles continuous conversions
  - Returns the latest conversion result

========================================================

   # ADC_Config

   Configuration structure passed to adc_Init().

   typedef struct
   {
    ...
   } ADC_Config;

   The structure contains:

   - ADC_Mode conversionMode
   - ADC_Reference reference
   - ADC_Prescaler prescaler
   - ADC_Align resultAlign

============================================================

   # ADC_Channel

   ADC input channel enumeration.

   Available channels:

   | Channel       | ADC Pin |
   |---------------|---------|
   | ADC_CHANNEL_0 | ADC0    |
   | ADC_CHANNEL_1 | ADC1    |
   | ADC_CHANNEL_2 | ADC2    |
   | ADC_CHANNEL_3 | ADC3    |
   | ADC_CHANNEL_4 | ADC4    |
   | ADC_CHANNEL_5 | ADC5    |
   | ADC_CHANNEL_6 | ADC6    | - This pin is not available on all ATmega8
   | ADC_CHANNEL_7 | ADC7    | - This pin is not available on all ATmega8

===================================================================

   # ADC_Reference

   Reference voltage selection.

   | Value            | Description              |
   |------------------|--------------------------|
   | ADC_REF_AREF     | External AREF            |
   | ADC_REF_VCC      | AVCC reference           |
   | ADC_REF_INTERNAL | Internal 2.56V reference |

====================================================================

   # ADC_Mode

   Conversion mode.

   | Value                       | Description                |
   |-----------------------------|----------------------------|
   | ADC_SINGLE_CONVERSION       | Single conversion mode     |
   | ADC_FREE_RUNNING_CONVERSION | Continuous conversion mode |

======================================================================

   # ADC_Align

   Result alignment.

   | Value           | Description          |
   |-----------------|----------------------|
   | ADC_ALIGN_RIGHT | Right adjusted result|
   | ADC_ALIGN_LEFT  | Left adjusted result |

=====================================================================

   # ADC_Prescaler

   ADC clock prescaler.

   Supported values:

   - ADC_PRESCALER_2
   - ADC_PRESCALER_4
   - ADC_PRESCALER_8
   - ADC_PRESCALER_16
   - ADC_PRESCALER_32
   - ADC_PRESCALER_64
   - ADC_PRESCALER_128

===================================================================================

   # Notes

   - The driver is designed for the ATmega8 microcontroller.
   - The ADC result is always returned as a 16-bit unsigned integer.
   - Runtime ADC channel selection is supported.
   - The driver supports both Single Conversion and Free Running modes.
   - The driver accesses the hardware registers directly (Bare Metal implementation).

========================================================================================

   # Example
  ````c
   ADC_Config config =
   {
     .conversionMode = ADC_SINGLE_CONVERSION,
     .reference = ADC_REF_VCC,
     .prescaler = ADC_PRESCALER_64,
     .align = ADC_ALIGN_RIGHT
   };

   int main(void)
   {

     adc_Init(&config);

     while(1)
     {

        uint16_t value = adc_Read(ADC_CHANNEL_5);

     }

   }