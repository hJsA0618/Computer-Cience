#include <stdio.h>
#include <stdlib.h>
#include "agentes.h"

int main(void) {
    agente *as = (agente *)malloc(N_AGENTES * sizeof(agente));

    for (int i = 0; i < N_AGENTES; i++) {
        as[i].nombre = 'A' + (char)i;
        as[i].fila = rand() % FILAS;
        as[i].columna = rand() % COLUMNAS;
    }

    while (1) {
        asignaFuncionesAleatoriamente(as);
        limpiarPantalla();
        dibujarPantalla(as);
        for (int i = 0; i < N_AGENTES; i++) {
            as[i].una_funcion(as[i].nombre, as[i].fila, as[i].columna);
            as[i].fila = rand() % FILAS;
            as[i].columna = rand() % COLUMNAS;
        }
        
        printf("Presiona ENTER para continuar...\n");
        getchar();
    }

    liberarMemoria(as);
    return 0;
}
