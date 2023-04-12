/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F46K42
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/adcc.h"
#include "mcc_generated_files/spi1.h"
#include "nuestrostimers.h"
#include "cola.h"
#include "nuestrospi.h"
#include "nuestrausart.h"
//volatile char ADC_tabla[2] = {ADC1,ADC2};
int ADC1 = 0;
int ADC2 = 0;
char conv1 = 0;
char conv2 = 0;
char f_send1 = 0;
char f_send2 = 0;
int data;


void main(void)
{
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptDisable();

    TMR2_Initialize();
    ADCC_Initialize();
    SPI1_Initialize();
    UART1_Initialize();
    INTERRUPT_Initialize();
    Tm_Periodico time_out;
    Tm_Inicie_periodico(&time_out,1010);
    eCola cola,colarx;
    inicie_cola(&cola);
    inicie_cola(&colarx);
    spi spi;
    inicie_SPI(&spi);
    selec_channel(&spi,0x00);
    selec_gain(&spi,0x01);
    selec_imp(&spi,0x01);
    usart disp;
    iniciar_struct_usart(&disp);
    SPI1CON0bits.EN = 1;
    while (1)
    {
        if(TMR2_HasOverflowOccured()){
            Tm_Procese_tiempo(&time_out);
        }
        if(Tm_Hubo_periodico(&time_out)){
            Tm_Baje_periodico(&time_out);
            ADCC_StartConversion(primerADC);
            conv1 = 1;
            envioSPI(&spi);
        }
        
        if(ADCC_IsConversionDone() && conv1){            
            ADC1 = ADCC_GetConversionResult();    
            f_send1=1;
            cola_add(&cola,(char)((ADC1 & 0x0F00) >> 8));
            cola_add(&cola,(char)(ADC1 & 0x00FF));
            cola_add(&cola,(char)(0x2C));
            //cola_add(&cola,(char)('F');
            //selec_channel(&spi,0x00);
            //actualize_valor(&spi,ADC1);
            //envioSPI(&spi);
            conv1 = 0; 
            ADCC_StartConversion(segundoADC);
            conv2=1;
            
        }
        
        if(f_send1 && SPI1STATUSbits.TXBE){
            f_send1=0;
            DAC_CS_SetHigh();
            LDAC_SetLow();
            //__delay_us(1);
            LDAC_SetLow();
            LDAC_SetHigh();
            f_send2=1;     
            selec_channel(&spi,0x00);
            actualize_valor(&spi,ADC1);
            envioSPI(&spi);
            
        }
        
        if(ADCC_IsConversionDone() && conv2){
            ADC2 = ADCC_GetConversionResult();
            cola_add(&cola,(char)((ADC2 & 0x0F00) >> 8));
            cola_add(&cola,(char)(ADC2 & 0x00FF));
            cola_add(&cola,(char)(0x13));
            cola_add(&cola,(char)(0x10));
            //selec_channel(&spi,0x01);
            //actualize_valor(&spi,ADC2);
            //envioSPI(&spi);
            conv2=0;
            
        }
        if(f_send2 && SPI1STATUSbits.TXBE){
            //f_send1=0;
            f_send2=0; 
            DAC_CS_SetHigh();
            LDAC_SetLow();
            //__delay_us(1);
            LDAC_SetLow();
            LDAC_SetHigh();
            f_send1=1;
            selec_channel(&spi,0x01);
            actualize_valor(&spi,ADC2);
            envioSPI(&spi); 
                  
        }
        
        if(UART1_is_tx_ready() && (!cola_vacia(&cola))){
            enviar_Eusart(cola_get(&cola));
        }
        
        if(UART1_is_rx_ready()){
            recibir_periodo_Eusart(&disp, data);
        }
        if(dato_recibido_completo(&disp)){
            Tm_Inicie_periodico(&time_out,1 + actualizar_recibido_Eusart(&disp));
        }
            
    }
}

/**
 End of File
*/