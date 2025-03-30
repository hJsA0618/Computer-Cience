#include <stdio.h>
#include <stdlib.h>
#include "agentes.h"

void f_comiendo(char n, int a, int b) {
    printf("Soy %c, estoy comiendo en la posición (%d, %d)\n", n, a, b);
}

void f_buscando(char n, int a, int b) {
    printf("Soy %c, estoy buscando en la posición (%d, %d)\n", n, a, b);
}

void f_durmiendo(char n, int a, int b) {
    printf("Soy %c, estoy durmiendo en la posición (%d, %d)\n", n, a, b);
}

void asignaFuncionesAleatoriamente(agente *as) {
    for (int i = 0; i < N_AGENTES; i++) {
        int r = rand() % 3;
        switch (r) {
            case 0:
                as[i].una_funcion = f_comiendo; break;
            case 1:
                as[i].una_funcion = f_buscando; break;
            case 2:
                as[i].una_funcion = f_durmiendo; break;
        }
    }
}

void dibujarPantalla(agente *as) {
    char **pantalla = (char **)malloc(FILAS * sizeof(char *));
    for (int i = 0; i < FILAS; i++) {
        pantalla[i] = (char *)malloc(COLUMNAS * sizeof(char));
        for (int j = 0; j < COLUMNAS; j++) {
            pantalla[i][j] = '.';
        }
    }

    for (int i = 0; i < N_AGENTES; i++) {
        if (as[i].fila >= 0 && as[i].fila < FILAS && as[i].columna >= 0 && as[i].columna < COLUMNAS) {
            pantalla[as[i].fila][as[i].columna] = as[i].nombre;
        }
    }

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%c ", pantalla[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < FILAS; i++) {
        free(pantalla[i]);
    }
    free(pantalla);
}

void limpiarPantalla() {
    printf("\033[H\033[J");
}

void liberarMemoria(agente *as) {
    free(as);
}
