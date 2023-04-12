#if !defined(PROCESEUSART_H)
#define PROCESEUSART_H
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include "mcc_generated_files/mcc.h"

struct usart{
    char valor;
    int numero1;
    int numero2;
    int numero3;
    int caso;
    bool recibir_dato_completo;
    bool esperar_datos_eusart;
};

typedef struct usart usart;

void iniciar_struct_usart(usart *disp);
void iniciar_Eusart(usart *disp);
int actualizar_recibido_Eusart(usart *disp);
void recibir_periodo_Eusart(usart *disp, char dato);
void enviar_Eusart(usart *disp);
char recibir_Eusart(usart *disp);
void parar_Eusart(usart *disp);
bool continuar_envio_Eusart(usart *disp);
bool dato_recibido_completo(usart *disp);

#endif