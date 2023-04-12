/* 
 * File:   processpi.h
 * Author: aulasingenieria
 *
 * Created on 14 de marzo de 2023, 03:58 PM
 */

#ifndef PROCESSPI_H
#define	PROCESSPI_H

typedef struct spi{
    unsigned int valor;
    char valor_enviando;
    char canal;
    char ganancia;
    char impedancia;
    unsigned int estado_registro;
    unsigned int caso;
    unsigned int tamano_registro;
    uint8_t spi_data[2]; 

}spi;
void inicie_SPI(spi* spi);
char sigo_enviando_SPI(spi* spi);
void envioSPI(spi* spi);
void actualize_valor(spi* spi, unsigned int valorspi );
void selec_imp(spi* spi, char impedanciaspi);
void selec_gain(spi* spi, char gananciaspi);
void inicie_envio_SPI(spi* spi);
void selec_channel(spi* spi,char canalspi);

#endif	/* PROCESSPI_H */

