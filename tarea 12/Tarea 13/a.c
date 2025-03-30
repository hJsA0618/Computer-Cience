#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_RENGLONES 24
#define MAX_COLUMNAS 80

void leerEscenario2D(const char* nombreArchivo, char*** mundo2D) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo");
        exit(1);
    }

    *mundo2D = (char**)malloc(MAX_RENGLONES * sizeof(char*));
    for (int i = 0; i < MAX_RENGLONES; i++) {
        (*mundo2D)[i] = (char*)malloc(MAX_COLUMNAS * sizeof(char));
        for (int j = 0; j < MAX_COLUMNAS; j++) {
            (*mundo2D)[i][j] = ' ';
        }
    }

    int renglones = 0;
    while (renglones < MAX_RENGLONES) {
        for (int columna = 0; columna < MAX_COLUMNAS; columna++) {
            int c = getc(archivo);
            if (c == EOF || c == '\n') {
                break;
            }
            (*mundo2D)[renglones][columna] = (char)c;
        }
        renglones++;
        if (getc(archivo) == EOF) break;
    }

    fclose(archivo);
}

void imprimirEscenario2D(char** mundo2D) {
    for (int i = 0; i < MAX_RENGLONES; i++) {
        for (int j = 0; j < MAX_COLUMNAS; j++) {
            putchar(mundo2D[i][j]);
        }
        putchar('\n');
    }
}

void simularCaidaDeGota(char** mundo2D) {
    int x = 0;
    int y = rand() % MAX_COLUMNAS;
    while (mundo2D[x][y] != ' ' || mundo2D[x + 1][y] == '#') {
        y = rand() % MAX_COLUMNAS;
    }

    mundo2D[x][y] = '&';  

    int direccion = 1;
    int haSalido = 0;

    while (x < MAX_RENGLONES - 1 && !haSalido) {
        if (mundo2D[x + 1][y] == ' ') {
            mundo2D[x][y] = ' ';
            x++;
            mundo2D[x][y] = '&';
        }
        else if (mundo2D[x + 1][y] == '#') {
            if (direccion == 1 && y < MAX_COLUMNAS - 1 && mundo2D[x][y + 1] == ' ') {
                mundo2D[x][y] = ' ';
                y++;
                mundo2D[x][y] = '&';
            }
            else if (direccion == -1 && y > 0 && mundo2D[x][y - 1] == ' ') {
                mundo2D[x][y] = ' ';
                y--;
                mundo2D[x][y] = '&';
            }
            else {
                direccion *= -1;
            }
        }

        system("cls");  
        imprimirEscenario2D(mundo2D);

        if (x == MAX_RENGLONES - 1 && mundo2D[x][y] == '&') {
            haSalido = 1;
        }

        printf("\nPresiona Enter para continuar...\n");
        getchar();
    }

    if (haSalido) {
        printf("\nLa gota ha salido del laberinto en la posicion (%d, %d).\n", x, y);
    } else {
        printf("\nLa gota no puede caer más, ha llegado al final del mapa.\n");
    }
}

int main() {
    srand((unsigned int)time(NULL));

    char** mundo2D = NULL;

    leerEscenario2D("escenario.txt", &mundo2D);

    printf("Escenario 2D Inicial:\n");
    imprimirEscenario2D(mundo2D);

    simularCaidaDeGota(mundo2D);

    for (int i = 0; i < MAX_RENGLONES; i++) {
        free(mundo2D[i]);
    }
    free(mundo2D);

    return 0;
}
