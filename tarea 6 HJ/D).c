#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h> // Necesario para SetConsoleCursorPosition
#include <time.h>

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void clearPreviousPosition(int x, int y) {
    gotoxy(x, y);
    printf(" ");  // Imprimir espacio para borrar el carácter anterior
}

void clearScreen() {
    system("cls"); // Borrar la consola
}

int main() {
    int prevX = 0, prevY = 0;
    int newX, newY;

    // Limpiar la pantalla al inicio
    clearScreen();

    // Inicializar el generador de números aleatorios
    srand(time(0));

    // Colocar un objeto inicial en (0, 0)
    gotoxy(prevX, prevY);
    printf("O");

    while (1) {
        // Esperar un tiempo antes de mover el objeto
        Sleep(500);  // Sleep en milisegundos

        // Generar nuevas coordenadas aleatorias
        newX = rand() % 80; // ancho de la consola [0, 79]
        newY = rand() % 24; // alto de la consola [0, 23]

        // Borrar la posición anterior
        clearPreviousPosition(prevX, prevY);

        // Colocar el objeto en la nueva posición
        gotoxy(newX, newY);
        printf("O");

        // Actualizar la posición anterior
        prevX = newX;
        prevY = newY;
    }

    return 0;
}
