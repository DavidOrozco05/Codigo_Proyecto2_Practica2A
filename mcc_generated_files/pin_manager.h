/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F46K42
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set LDAC aliases
#define LDAC_TRIS                 TRISBbits.TRISB4
#define LDAC_LAT                  LATBbits.LATB4
#define LDAC_PORT                 PORTBbits.RB4
#define LDAC_WPU                  WPUBbits.WPUB4
#define LDAC_OD                   ODCONBbits.ODCB4
#define LDAC_ANS                  ANSELBbits.ANSELB4
#define LDAC_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define LDAC_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define LDAC_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define LDAC_GetValue()           PORTBbits.RB4
#define LDAC_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define LDAC_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define LDAC_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define LDAC_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define LDAC_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define LDAC_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define LDAC_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define LDAC_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSELC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetAnalogMode()         do { ANSELCbits.ANSELC5 = 1; } while(0)
#define RC5_SetDigitalMode()        do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RX aliases
#define RX_TRIS                 TRISCbits.TRISC7
#define RX_LAT                  LATCbits.LATC7
#define RX_PORT                 PORTCbits.RC7
#define RX_WPU                  WPUCbits.WPUC7
#define RX_OD                   ODCONCbits.ODCC7
#define RX_ANS                  ANSELCbits.ANSELC7
#define RX_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RX_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RX_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RX_GetValue()           PORTCbits.RC7
#define RX_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RX_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RX_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define RX_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define RX_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define RX_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define RX_SetAnalogMode()      do { ANSELCbits.ANSELC7 = 1; } while(0)
#define RX_SetDigitalMode()     do { ANSELCbits.ANSELC7 = 0; } while(0)

// get/set primerADC aliases
#define primerADC_TRIS                 TRISDbits.TRISD0
#define primerADC_LAT                  LATDbits.LATD0
#define primerADC_PORT                 PORTDbits.RD0
#define primerADC_WPU                  WPUDbits.WPUD0
#define primerADC_OD                   ODCONDbits.ODCD0
#define primerADC_ANS                  ANSELDbits.ANSELD0
#define primerADC_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define primerADC_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define primerADC_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define primerADC_GetValue()           PORTDbits.RD0
#define primerADC_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define primerADC_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define primerADC_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define primerADC_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define primerADC_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define primerADC_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define primerADC_SetAnalogMode()      do { ANSELDbits.ANSELD0 = 1; } while(0)
#define primerADC_SetDigitalMode()     do { ANSELDbits.ANSELD0 = 0; } while(0)

// get/set segundoADC aliases
#define segundoADC_TRIS                 TRISDbits.TRISD3
#define segundoADC_LAT                  LATDbits.LATD3
#define segundoADC_PORT                 PORTDbits.RD3
#define segundoADC_WPU                  WPUDbits.WPUD3
#define segundoADC_OD                   ODCONDbits.ODCD3
#define segundoADC_ANS                  ANSELDbits.ANSELD3
#define segundoADC_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define segundoADC_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define segundoADC_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define segundoADC_GetValue()           PORTDbits.RD3
#define segundoADC_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define segundoADC_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define segundoADC_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define segundoADC_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define segundoADC_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define segundoADC_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define segundoADC_SetAnalogMode()      do { ANSELDbits.ANSELD3 = 1; } while(0)
#define segundoADC_SetDigitalMode()     do { ANSELDbits.ANSELD3 = 0; } while(0)

// get/set salida aliases
#define salida_TRIS                 TRISDbits.TRISD4
#define salida_LAT                  LATDbits.LATD4
#define salida_PORT                 PORTDbits.RD4
#define salida_WPU                  WPUDbits.WPUD4
#define salida_OD                   ODCONDbits.ODCD4
#define salida_ANS                  ANSELDbits.ANSELD4
#define salida_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define salida_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define salida_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define salida_GetValue()           PORTDbits.RD4
#define salida_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define salida_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define salida_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define salida_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define salida_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define salida_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define salida_SetAnalogMode()      do { ANSELDbits.ANSELD4 = 1; } while(0)
#define salida_SetDigitalMode()     do { ANSELDbits.ANSELD4 = 0; } while(0)

// get/set DAC_CS aliases
#define DAC_CS_TRIS                 TRISEbits.TRISE0
#define DAC_CS_LAT                  LATEbits.LATE0
#define DAC_CS_PORT                 PORTEbits.RE0
#define DAC_CS_WPU                  WPUEbits.WPUE0
#define DAC_CS_OD                   ODCONEbits.ODCE0
#define DAC_CS_ANS                  ANSELEbits.ANSELE0
#define DAC_CS_SetHigh()            do { LATEbits.LATE0 = 1; } while(0)
#define DAC_CS_SetLow()             do { LATEbits.LATE0 = 0; } while(0)
#define DAC_CS_Toggle()             do { LATEbits.LATE0 = ~LATEbits.LATE0; } while(0)
#define DAC_CS_GetValue()           PORTEbits.RE0
#define DAC_CS_SetDigitalInput()    do { TRISEbits.TRISE0 = 1; } while(0)
#define DAC_CS_SetDigitalOutput()   do { TRISEbits.TRISE0 = 0; } while(0)
#define DAC_CS_SetPullup()          do { WPUEbits.WPUE0 = 1; } while(0)
#define DAC_CS_ResetPullup()        do { WPUEbits.WPUE0 = 0; } while(0)
#define DAC_CS_SetPushPull()        do { ODCONEbits.ODCE0 = 0; } while(0)
#define DAC_CS_SetOpenDrain()       do { ODCONEbits.ODCE0 = 1; } while(0)
#define DAC_CS_SetAnalogMode()      do { ANSELEbits.ANSELE0 = 1; } while(0)
#define DAC_CS_SetDigitalMode()     do { ANSELEbits.ANSELE0 = 0; } while(0)

// get/set ADC_CS aliases
#define ADC_CS_TRIS                 TRISEbits.TRISE1
#define ADC_CS_LAT                  LATEbits.LATE1
#define ADC_CS_PORT                 PORTEbits.RE1
#define ADC_CS_WPU                  WPUEbits.WPUE1
#define ADC_CS_OD                   ODCONEbits.ODCE1
#define ADC_CS_ANS                  ANSELEbits.ANSELE1
#define ADC_CS_SetHigh()            do { LATEbits.LATE1 = 1; } while(0)
#define ADC_CS_SetLow()             do { LATEbits.LATE1 = 0; } while(0)
#define ADC_CS_Toggle()             do { LATEbits.LATE1 = ~LATEbits.LATE1; } while(0)
#define ADC_CS_GetValue()           PORTEbits.RE1
#define ADC_CS_SetDigitalInput()    do { TRISEbits.TRISE1 = 1; } while(0)
#define ADC_CS_SetDigitalOutput()   do { TRISEbits.TRISE1 = 0; } while(0)
#define ADC_CS_SetPullup()          do { WPUEbits.WPUE1 = 1; } while(0)
#define ADC_CS_ResetPullup()        do { WPUEbits.WPUE1 = 0; } while(0)
#define ADC_CS_SetPushPull()        do { ODCONEbits.ODCE1 = 0; } while(0)
#define ADC_CS_SetOpenDrain()       do { ODCONEbits.ODCE1 = 1; } while(0)
#define ADC_CS_SetAnalogMode()      do { ANSELEbits.ANSELE1 = 1; } while(0)
#define ADC_CS_SetDigitalMode()     do { ANSELEbits.ANSELE1 = 0; } while(0)

// get/set ADC_chan aliases
#define ADC_chan_TRIS                 TRISEbits.TRISE2
#define ADC_chan_LAT                  LATEbits.LATE2
#define ADC_chan_PORT                 PORTEbits.RE2
#define ADC_chan_WPU                  WPUEbits.WPUE2
#define ADC_chan_OD                   ODCONEbits.ODCE2
#define ADC_chan_ANS                  ANSELEbits.ANSELE2
#define ADC_chan_SetHigh()            do { LATEbits.LATE2 = 1; } while(0)
#define ADC_chan_SetLow()             do { LATEbits.LATE2 = 0; } while(0)
#define ADC_chan_Toggle()             do { LATEbits.LATE2 = ~LATEbits.LATE2; } while(0)
#define ADC_chan_GetValue()           PORTEbits.RE2
#define ADC_chan_SetDigitalInput()    do { TRISEbits.TRISE2 = 1; } while(0)
#define ADC_chan_SetDigitalOutput()   do { TRISEbits.TRISE2 = 0; } while(0)
#define ADC_chan_SetPullup()          do { WPUEbits.WPUE2 = 1; } while(0)
#define ADC_chan_ResetPullup()        do { WPUEbits.WPUE2 = 0; } while(0)
#define ADC_chan_SetPushPull()        do { ODCONEbits.ODCE2 = 0; } while(0)
#define ADC_chan_SetOpenDrain()       do { ODCONEbits.ODCE2 = 1; } while(0)
#define ADC_chan_SetAnalogMode()      do { ANSELEbits.ANSELE2 = 1; } while(0)
#define ADC_chan_SetDigitalMode()     do { ANSELEbits.ANSELE2 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/