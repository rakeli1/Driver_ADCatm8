

     # ADC Driver Configuration

   This document describes how to configure the ADC driver before initialization.

==================================================================================

    # Configuration Structure

    The ADC driver is configured using the ADC_Config structure.

    ADC_Config config;
    The structure contains all parameters required to initialize the ADC peripheral.

==================================================================================

    # Reference Voltage

    Select the ADC reference voltage.

    | Option           | Description                                        |
    |------------------|----------------------------------------------------|
    | ADC_REF_AREF     | External reference voltage applied to the AREF pin |
    | ADC_REF_VCC      | AVCC used as reference voltage                     |
    | ADC_REF_INTERNAL | Internal 2.56V voltage reference                   |

    Example:

    config.reference = ADC_REF_VCC;
==================================================================================

    # Conversion Mode

    Select the ADC operating mode.

    | Option                      | Description                                      |
    |-----------------------------|--------------------------------------------------|
    | ADC_SINGLE_CONVERSION       | Performs one conversion for each adc_Read() call |
    | ADC_FREE_RUNNING_CONVERSION | Performs continuous conversions automatically    |

    Example:

    config.conversionMode = ADC_SINGLE_CONVERSION;
==================================================================================

    # Result Alignment

    Configure the ADC result alignment.

    | Option          | Description           |
    |-----------------|-----------------------|
    | ADC_ALIGN_RIGHT | Right-adjusted result |
    | ADC_ALIGN_LEFT  | Left-adjusted result  |

    Example:

    config.resultAlign = ADC_ALIGN_RIGHT;
==================================================================================

    # ADC Clock Prescaler

    Select the ADC clock prescaler.

    Available options:

    - ADC_PRESCALER_2
    - ADC_PRESCALER_4
    - ADC_PRESCALER_8
    - ADC_PRESCALER_16
    - ADC_PRESCALER_32
    - ADC_PRESCALER_64
    - ADC_PRESCALER_128

    Example:

    config.prescaler = ADC_PRESCALER_64;
==================================================================================

    # Complete Configuration Example

    ````c
    ADC_Config config =
    {
        
        .conversionMode      = ADC_SINGLE_CONVERSION,
        .reference           = ADC_REF_VCC,
        .prescaler           = ADC_PRESCALER_64
        .resultAlign         = ADC_ALIGN_RIGHT,
        
    };

    Example:    

    adc_Init(&config);
===================================================================================

    # Notes

    - Configure the driver before calling adc_Init().
    - The ADC must be initialized before the first call to adc_Read().
    - The selected reference voltage should match the hardware configuration.
    - For best ADC accuracy, choose an appropriate prescaler according to the MCU clock frequency.


    ## Prescaler Recommendation

    For maximum ADC accuracy, the ADC clock should typically be in the range of 50 kHz to 200 kHz.

    Choose the prescaler according to the system clock frequency.

    Example for F_CPU = 8 MHz:

    | Prescaler  | ADC Clock               |
    |-----------:|------------------------:|
    |     2      | 4 MHz                   |
    |     4      | 2 MHz                   |
    |     8      | 1 MHz                   |
    |     16     | 500  kHz                |
    |     32     | 250  kHz                |
    |     64     | 125  kHz ✔ Recommended |
    |     128    | 62.5 kHz ✔ Recommended |