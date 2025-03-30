#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "screen.h"

#define N_CABALLOS 6
#define X_META SCREEN_NC - 5 - 4

void dibujaCaballo(int x, int y, int color);
void borraCaballo(int x, int y);
int avanzaAleatorio(void);
void quitaCursor(void);
void delay(void);
void dibujaPantalla(void);
int carrera(int semillaAleatoria);

int main(void) {
    int semillaAleatoria = 36;
    int ganador = carrera(semillaAleatoria);
    gotoxy(1, 1);
    printf("  El ganador es el caballo %d", ganador + 1);
    delay();
    return 0;
}

void delay(void) {
    quitaCursor();
    getchar();
}

void quitaCursor(void) {
    gotoxy(X_META + 5 + 1, 1);
}

void dibujaCaballo(int x, int y, int color) {
    setColor(color);
    gotoxy(x, y);
    printf("/(~)P");
    setColor(I_NRM); // Regresa al color normal
}

void borraCaballo(int x, int y) {
    gotoxy(x, y);
    printf("     ");
}

void dibujaPantalla(void) {
    clearScreen();
    for (int y = 1; y <= SCREEN_NR; y++) {
        gotoxy(X_META + 5, y);
        printf("|");
    }
}

int avanzaAleatorio(void) {
    return rand() % 2;
}

int carrera(int semillaAleatoria) {
    srand(semillaAleatoria);
    dibujaPantalla();

    int posiciones[N_CABALLOS] = {1, 1, 1, 1, 1, 1};
    int meta = X_META;
    int ganador = -1;

    int colores[N_CABALLOS] = {I_RED, I_GRN, I_YEL, I_BLU, I_MAG, I_CYN};

    while (ganador == -1) {
        for (int i = 0; i < N_CABALLOS; i++) {
            if (avanzaAleatorio()) {
                borraCaballo(posiciones[i], i + 3);
                posiciones[i]++;
                dibujaCaballo(posiciones[i], i + 3, colores[i]);
                if (posiciones[i] >= meta) {
                    ganador = i;
                    break;
                }
            }
        }
        delay();
    }
    return ganador;
}
