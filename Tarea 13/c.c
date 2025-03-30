#include <stdio.h>
#include <stdlib.h>

void leer_vector_binario(const char *archivo) {
    FILE *file = fopen(archivo, "rb");
    if (file == NULL) {
        printf("Error al abrir el archivo %s\n", archivo);
        exit(1);
    }
    int tamaño;
    fread(&tamaño, sizeof(int), 1, file);
    float *vector = (float *)malloc(tamaño * sizeof(float));
    if (vector == NULL) {
        printf("Error al asignar memoria para el vector\n");
        exit(1);
    }
    fread(vector, sizeof(float), tamaño, file);
    printf("Tamaño del vector: %d\n", tamaño);
    printf("Contenido del vector:\n");
    for (int i = 0; i < tamaño; i++) {
        printf("%f\n", vector[i]);
    }
    free(vector);
    fclose(file);
}

int main() {
    leer_vector_binario("resultado.bin");

    return 0;
}