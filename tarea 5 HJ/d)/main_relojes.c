#include <stdio.h>
#include <stdlib.h>
#include "screen.h"

#define R_INI 1
#define R_FIN 21
#define C_INI 5
#define C_FIN 90
#define N_CHARS 4

int main(void) {
    clearScreen();
    
    const char chars[] = "-\\*#";  // Usar 'const char' para evitar advertencias

    int idxChar = 0;
    
    while(1){ // salir del programa con Ctrl + c
        for(int r = R_INI; r < R_FIN; r++) {
            for(int c = C_INI, color = I_NRM; c < C_FIN; c++, color++) {
                setColor(color % N_COLORS);
                gotoxy(c, r);
                printf("%c", chars[idxChar]);
            }
        }
        
        idxChar++;
        idxChar %= N_CHARS;
                
        setColor(I_NRM);
        gotoxy(1, 1); 

        getchar();
    }    

    return 0;
}
