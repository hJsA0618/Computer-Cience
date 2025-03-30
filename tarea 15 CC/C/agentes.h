#ifndef AGENTES_H
#define AGENTES_H

#define N_AGENTES 5
#define FILAS 10
#define COLUMNAS 10

typedef struct AGENTE {
    char nombre;
    void (*una_funcion)(char, int, int);
    int fila;
    int columna;
} agente;

void f_comiendo(char n, int a, int b);
void f_buscando(char n, int a, int b);
void f_durmiendo(char n, int a, int b);
void asignaFuncionesAleatoriamente(agente *as);
void dibujarPantalla(agente *as);
void limpiarPantalla();
void liberarMemoria(agente *as);

#endif
