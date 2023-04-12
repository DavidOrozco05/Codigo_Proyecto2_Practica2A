#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/spi1.h"

#include "nuestrospi.h"

#define TAMANO_REGISTRO 16
char primerbyte = 0;
char segundobyte = 0;

void inicie_SPI(spi* spi){
    spi -> valor = 0;
    spi -> ganancia = 0;
    spi -> canal = 0;
    spi -> impedancia = 0;
    spi -> valor_enviando = 0;
    spi -> estado_registro = TAMANO_REGISTRO;
    spi -> caso = 0;
    spi -> tamano_registro = TAMANO_REGISTRO;
    DAC_CS_SetHigh();
    LDAC_SetHigh();
}

void selec_channel(spi* spi,char canalspi){
    spi -> canal = canalspi;
}
void selec_gain(spi* spi, char gananciaspi){
    spi -> ganancia = gananciaspi;
}
void selec_imp(spi* spi, char impedanciaspi){
    spi -> impedancia = impedanciaspi;
}

void actualize_valor(spi* spi, unsigned int valorspi ){
    spi -> valor = valorspi;
    
}
/*void inicie_envio_SPI(spi* spi){
    spi -> valor_enviando = 1;
}*/
void envioSPI(spi* spi){
    spi -> spi_data[0] = ((spi -> canal << 7) & (0x80)) | ((spi -> ganancia << 5) & (0x20)) | ((spi -> impedancia << 4) & (0x10)) | ((spi -> valor >> 8) & (0x0F));
    spi -> spi_data[1] = ((spi -> valor) & 0xFF);
    
    DAC_CS_SetLow();
    SPI1_WriteByte(spi ->spi_data[0]);
    SPI1_WriteByte(spi ->spi_data[1]);
   // __delay_us(16);
    /*DAC_CS_SetHigh();
    LDAC_SetLow();
    __delay_us(1);
    LDAC_SetLow();
    LDAC_SetHigh();*/
}

/*char sigo_enviando_SPI(spi* spi){
    return spi -> valor_enviando;
}*/
