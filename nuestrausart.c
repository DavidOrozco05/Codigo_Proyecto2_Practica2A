#include "nuestrausart.h"
#include "mcc_generated_files/uart1.h"
#include "mcc_generated_files/mcc.h"
 


void iniciar_struct_usart(usart *disp){
    disp -> numero1 = 0;
    disp -> numero2 = 0;
    disp -> numero3 = 0;
    disp -> valor = 0;
    disp -> recibir_dato_completo = false;
    disp -> esperar_datos_eusart = false;
    disp -> caso = 0;
}

void recibir_periodo_Eusart(usart *disp,char dato){
    disp -> valor = U1RXB;
    UART1_Write(disp-> valor);
    switch(disp -> caso)
    {
        case 0:
            if(disp -> valor == 60){
                disp -> caso = 1;      
            }
            else
            {
                disp -> caso = 0;
            }
            break;
        case 1:
            //if(disp -> valor >48 && disp->valor<58){
            disp -> caso = 2;
            disp -> numero1 = disp -> valor;
            break;
            /*}
            else{
                disp -> caso = 0;
            }*/
        case 2: 
            //if(disp -> numero2 >48 && disp->numero2<58){
            disp -> caso = 3;
            disp -> numero2 = disp -> valor;
            break;
            /*}
            else{
                disp -> caso = 0;
            }*/
        case 3: 
            //if(disp -> numero3 >48&&disp->numero3<58){
            disp -> caso = 4;
            disp -> numero3 = disp -> valor;
            break;
            /*}
            else{
                disp -> caso = 0;
            }*/
        case 4:
            if(disp -> valor == 62){
                disp -> recibir_dato_completo = true;
                disp -> caso = 0;
            }
            else{
                disp -> caso = 0;
            }

        
    }
}

void iniciar_Eusart(usart *disp){
    disp -> esperar_datos_eusart = false;
}
void parar_Eusart(usart *disp){
    disp -> esperar_datos_eusart = true;
}
void enviar_Eusart(usart *disp){
    U1TXB = disp->valor;
}

char recibir_Eusart(usart *disp){
    
    disp -> valor = U1RXB;
    return disp -> valor;
}


bool dato_recibido_completo(usart *disp){

    return disp -> recibir_dato_completo;
}

int actualizar_recibido_Eusart(usart *disp){
    disp -> recibir_dato_completo = 0;
    return ((disp -> numero1 - 48)*100 + (disp -> numero2 - 48)*10 + (disp -> numero3 - 48));
}
