#include <stdio.h>

#define FOCO_PRENDIDO 1 << 8
#define AUTO_EN_COCHERA 1 << 7
#define ALARMA_ACTIVADA 1 << 6
#define PUERTA_CERRADA 1 << 5
#define PERRO_SUELTO 1 << 4
#define VENTANA_CERRADA 1 << 3
#define TINACO_DE_AGUA_LLENO 1 << 2
#define HAY_LUZ_ELECTRICA 1 << 1
#define REFRIGERADOR_CONECTADO 1 << 0

void imprimir_estado_casa(unsigned int estado);
void imprimir_estado_casa(unsigned int estado) 
{
    printf("FOCO: %s\n", (estado & FOCO_PRENDIDO) ? "ESTA PRENDIDO" : "ESTA APAGADO");
    printf("AUTO: %s\n", (estado & AUTO_EN_COCHERA) ? "ESTA EN LA COCHERA" : "NO ESTA EN LA COCHERA");
    printf("ALARMA: %s\n", (estado & ALARMA_ACTIVADA) ? "ESTA ACTIVADA" : "ESTA DESACTIVADA");
    printf("PUERTA: %s\n", (estado & PUERTA_CERRADA) ? "CERRADA" : "ABIERTA");
    printf("PERRO: %s\n", (estado & PERRO_SUELTO) ? "SUELTO" : "ENCERRADO");
    printf("VENTANA: %s\n", (estado & VENTANA_CERRADA) ? "CERRADA" : "ABIERTA");
    printf("TINACO DE AGUA: %s\n", (estado & TINACO_DE_AGUA_LLENO) ? "LLENO" : "VACIO");
    printf("LUZ ELECTRICA: %s\n", (estado & HAY_LUZ_ELECTRICA) ? "HAY" : "NO HAY");
    printf("REFRIGERADOR: %s\n", (estado & REFRIGERADOR_CONECTADO) ? "CONECTADO" : "DESCONECTADO");
}

void notImprimir_estado_casa(unsigned int estado);
void notImprimir_estado_casa(unsigned int estado) 
{
    printf("FOCO: %s\n", !(estado & FOCO_PRENDIDO) ? "ESTA PRENDIDO" : "ESTA APAGADO");
    printf("AUTO: %s\n", !(estado & AUTO_EN_COCHERA) ? "ESTA EN LA COCHERA" : "NO ESTA EN LA COCHERA");
    printf("ALARMA: %s\n", !(estado & ALARMA_ACTIVADA) ? "ESTA ACTIVADA" : "ESTA DESACTIVADA");
    printf("PUERTA: %s\n", !(estado & PUERTA_CERRADA) ? "CERRADA" : "ABIERTA");
    printf("PERRO: %s\n", !(estado & PERRO_SUELTO) ? "SUELTO" : "ENCERRADO");
    printf("VENTANA: %s\n", !(estado & VENTANA_CERRADA) ? "CERRADA" : "ABIERTA");
    printf("TINACO DE AGUA: %s\n", !(estado & TINACO_DE_AGUA_LLENO) ? "LLENO" : "VACIO");
    printf("LUZ ELECTRICA: %s\n", !(estado & HAY_LUZ_ELECTRICA) ? "HAY" : "NO HAY");
    printf("REFRIGERADOR: %s\n", !(estado & REFRIGERADOR_CONECTADO) ? "CONECTADO" : "DESCONECTADO");
}
int main() {
    unsigned int estado = (FOCO_PRENDIDO | AUTO_EN_COCHERA | ALARMA_ACTIVADA |
                          PUERTA_CERRADA | PERRO_SUELTO | VENTANA_CERRADA |
                          TINACO_DE_AGUA_LLENO | HAY_LUZ_ELECTRICA |
                          REFRIGERADOR_CONECTADO);
    
    printf("Estado de la casa:\n");
    imprimir_estado_casa(estado);

    printf("\nEstado contrario de la casa:\n");
    notImprimir_estado_casa(estado);
    return 0;
}