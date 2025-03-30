#include <stdio.h>
#include <stdlib.h>

#define NR 100   
#define NC 1000  

void llenar_matriz(double **matriz) {
    for (int i = 0; i < NR; i++) {
        for (int j = 0; j < NC; j++) {
            matriz[i][j] = rand() % 100;
        }
    }
}
void escribir_matriz_a_binario(double **matriz, const char *nombre_archivo) {
    
    FILE *archivo = fopen(nombre_archivo, "wb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo");
        return;
    }
    for (int i = 0; i < NR; i++) {
        fwrite(matriz[i], sizeof(double), NC, archivo); 
    }
    fclose(archivo);
}

int main() {
      double **matriz = (double **)malloc(NR * sizeof(double *));
    if (matriz == NULL) {
        printf("Error al asignar memoria para la matriz");
        return 1;
    }
    
    for (int i = 0; i < NR; i++) {
        matriz[i] = (double *)malloc(NC * sizeof(double));
        if (matriz[i] == NULL) {
            printf("Error al asignar memoria para un renglón de la matriz");
            return 1;
        }
    }


    llenar_matriz(matriz);
    escribir_matriz_a_binario(matriz, "matriz.bin");
    for (int i = 0; i < NR; i++) {
        free(matriz[i]);
    }
    free(matriz);

    printf("Matriz escrita correctamente en el archivo binario 'matriz.bin'\n");

    return 0;
}
