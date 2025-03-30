#include "screen.h"

// Definir si estamos en Windows o Linux/Mac
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// Función para mover el cursor a la posición (x, y)
void gotoxy(int x, int y) {
#ifdef _WIN32
    COORD coord;
    coord.X = x - 1; // Ajustamos a 0 basado para Windows
    coord.Y = y - 1; // Ajustamos a 0 basado para Windows
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
#else
    printf("\x1B[%d;%df", y, x);
#endif
}

// Función para limpiar la pantalla
void clearScreen(void) {
    for (int r = 0; r < SCREEN_NR; r++) {
        for (int c = 0; c < SCREEN_NC; c++) {
            gotoxy(c + 1, r + 1);
            printf(" ");
        }
    }
    gotoxy(1, 1); // Regresar al principio
}

// Función para establecer el color del texto
void setColor(int idxColor) {
#ifdef _WIN32
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    switch (idxColor) {
        case I_NRM:
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
            break;
        case I_RED:
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
            break;
        case I_GRN:
            SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            break;
        case I_YEL:
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            break;
        case I_BLU:
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            break;
        case I_MAG:
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            break;
        case I_CYN:
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            break;
        case I_WHT:
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
            break;
        default:
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // Default to normal
            break;
    }
#else
    switch (idxColor) {
        case I_NRM:
            printf("\x1B[0m");
            break;
        case I_RED:
            printf("\x1B[31m");
            break;
        case I_GRN:
            printf("\x1B[32m");
            break;
        case I_YEL:
            printf("\x1B[33m");
            break;
        case I_BLU:
            printf("\x1B[34m");
            break;
        case I_MAG:
            printf("\x1B[35m");
            break;
        case I_CYN:
            printf("\x1B[36m");
            break;
        case I_WHT:
            printf("\x1B[37m");
            break;
        default:
            printf("\x1B[0m"); // Default to normal
            break;
    }
#endif
}
