#include <stdio.h>
#include <conio.h>   // Para poder usar gotoxy()
#include <windows.h> // Para poder usar Sleep()

#define WIDTH 70
#define HEIGHT 25

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void clearScreen() {
    system("cls");
}

void drawPacman(int x, int y, int phase) {
    gotoxy(x, y);
    if (phase == 0) {
        printf("<( ' u ' )>");
    } else if (phase == 1) {
        printf("<( ' ^^ ' )>");
    } else if (phase == 2) {
        printf("<( ' {} ' )>");
    }
}

int main() {
    int x = WIDTH / 2;
    int y = HEIGHT / 2;
    int phase = 0;
    int direction = 1;

    while (1) {
        clearScreen();
        drawPacman(x, y, phase);
        phase = (phase + 1) % 3;

        Sleep(200); // Pausa para ver el movimiento

        // Cambia la dirección de Pac-Man cuando llegue al borde
        if (x >= WIDTH - 1 || x <= 1) {
            direction = -direction;
        }
        x += direction;
    }

    return 0;
}
