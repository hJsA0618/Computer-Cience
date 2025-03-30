#include <stdio.h>
#include <math.h>
#include <windows.h>

void gotoxy(int x, int y);
void clearScreen(void);
void dibujarCirculo(float r);

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void clearScreen(void) {
    // Limpia la consola
    system("cls"); // Limpia la consola
    gotoxy(0, 0);   // Mueve el cursor a la esquina superior izquierda
}

void dibujarCirculo(float r) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int ancho = csbi.srWindow.Right - csbi.srWindow.Left + 1; 
    int alto = csbi.srWindow.Bottom - csbi.srWindow.Top + 1; 

    int x_centro = ancho / 2;
    int y_centro = alto / 2;

    for (int i = 0; i < 360; i++) {
        float angulo = i * (M_PI / 180);
        
        int x = round(r * cos(angulo));
        int y = round(r * sin(angulo));
        
        // Ajustar la posición para centrar mejor el círculo
        gotoxy(x_centro + x, y_centro - y); 
        printf("*"); 
    }
}

int main(void) {
    float radio;
    clearScreen(); 
    printf("Introduce el radio del círculo (mayor que 0): ");
    scanf("%f", &radio);
    
    if (radio <= 0) {
        printf("El radio debe ser mayor que 0.\n");
        return 1; 
    }
    
    dibujarCirculo(radio); 
    printf("\nPresiona cualquier tecla para continuar...");
    getchar(); // Limpiar el buffer
    getchar(); // Esperar la entrada del usuario

    return 0;
}
