

      # ADC Basic Test

    This example demonstrates the basic usage of the Driver_ADCatm8 library.

    The program initializes the ADC peripheral and continuously reads the analog voltage from ADC Channel 5 (PC5).

    The conversion result is transmitted over UART in hexadecimal format.

============================================================================================================

    ## Hardware

    - Microcontroller: ATmega8
    - ADC Input: ADC5 (PC5)
    - Analog Source: 10 kΩ potentiometer
    - Reference Voltage: AVCC
    - Result Alignment: Right
    - ADC Mode: Single Conversion

============================================================================================================

    ## Wiring

    The potentiometer connection diagram is available in the Connection_Diagram directory.

============================================================================================================

    ## Expected Result

    Rotating the potentiometer changes the ADC conversion result.

    Typical output:

  - 0000
  - 003A
  - 00BC
  - 01F0
  - 02D4
  - 03FF
   Where:

  - 0000 → approximately 0 V
  - 03FF → reference voltage (AVCC)

===========================================================================================================

   ## Build

   Compile the project using:

   - AVR-GCC
   - Microchip Studio

   Flash the firmware to an ATmega8 and open a serial terminal to observe the ADC values.

===========================================================================================================

   ## Notes

   This example is intended to verify the correct operation of the ADC driver on real hardware.