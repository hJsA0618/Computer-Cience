#include <stdio.h>
#include <stdlib.h>

#define MAX_RENGLONES 24
#define MAX_COLUMNAS 80

void leerEscenario2D(const char* nombreArchivo, char*** mundo2D) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        perror("No se pudo abrir el archivo");
        exit(1);
    }


    *mundo2D = (char**)malloc(MAX_RENGLONES * sizeof(char*));
    for (int i = 0; i < MAX_RENGLONES; i++) {
        (*mundo2D)[i] = (char*)malloc(MAX_COLUMNAS * sizeof(char));
    }


    int renglones = 0;
    while (renglones < MAX_RENGLONES) {
        for (int columna = 0; columna < MAX_COLUMNAS; columna++) {
            int c = getc(archivo);
            if (c == EOF || c == '\n') {
                (*mundo2D)[renglones][columna] = '\0';  
                break;
            }
            (*mundo2D)[renglones][columna] = (char)c;
        }
        if (getc(archivo) == EOF) break;  
        renglones++;
    }

    
    fclose(archivo);
}

void imprimirEscenario2D(char** mundo2D) {
    for (int i = 0; i < MAX_RENGLONES; i++) {
        printf("%s\n", mundo2D[i]); 
    }
}

int main() {
    char** mundo2D = NULL;

    
    leerEscenario2D("escenario.txt", &mundo2D);

    
    printf("Escenario 2D:\n");
    imprimirEscenario2D(mundo2D);

    for (int i = 0; i < MAX_RENGLONES; i++) {
        free(mundo2D[i]);
    }
    free(mundo2D);

    return 0;
}
