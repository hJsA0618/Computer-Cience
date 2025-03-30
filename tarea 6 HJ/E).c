#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h> // Necesario para SetConsoleCursorPosition

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Función para dibujar una línea horizontal
void drawHorizontalLine(int row, int colStart, int colEnd) {
    gotoxy(colStart, row);
    for (int col = colStart; col <= colEnd; col++) {
        printf("-"); // Imprimir el carácter '-'
    }
}

// Función para dibujar una línea vertical
void drawVerticalLine(int col, int rowStart, int rowEnd) {
    for (int row = rowStart; row <= rowEnd; row++) {
        gotoxy(col, row);
        printf("|"); // Imprimir el carácter '|'
    }
}

int main() {
    // Limpiar la pantalla al inicio
    system("cls");

    // Dibujar la línea horizontal en la fila 1
    drawHorizontalLine(1, 0, 50); // Línea horizontal en la fila 1, de columna 0 a 50

    // Dibujar la línea vertical
    drawVerticalLine(50, 2, 6); // Línea vertical en la columna 50, de fila 2 a 6

    // Dibujar otra línea horizontal en la fila 7
    drawHorizontalLine(7, 0, 50); // Línea horizontal en la fila 7

    // Dibujar la línea vertical a partir de la fila 8
    drawVerticalLine(50, 8, 11); // Línea vertical en la columna 50, de fila 8 a 11

    return 0;
}
