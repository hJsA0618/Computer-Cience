#include <stdio.h>
#include <string.h>

void leer_archivo(const char *fileName) {
    FILE *file = fopen(fileName, "r"); 
    if (file == NULL) {
        perror("Error al abrir el archivo");
        return;
    }

    char line[256]; 
    int num_vertices = 0, num_caras = 0, caras_triangulo = 0;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';

        if (strncmp(line, "element vertex", 14) == 0) {
            sscanf(line, "element vertex %d", &num_vertices);
        }

        if (strncmp(line, "element face", 12) == 0) {
            sscanf(line, "element face %d", &num_caras);
        }

        if (strncmp(line, "end_header", 10) == 0) {
            break;
        }
    }

    int vertices_por_cara;
    for (int i = 0; i < num_caras; i++) {
        if (fgets(line, sizeof(line), file)) {
            sscanf(line, "%d", &vertices_por_cara);

            if (vertices_por_cara == 3) {
                caras_triangulo++;
            }
        }
    }

    printf("Archivo: %s\n", fileName);
    printf("Número de vértices: %d\n", num_vertices);
    printf("Número de caras: %d\n", num_caras);
    printf("Número de triángulos: %d\n", caras_triangulo);
    printf(">---------\n--------->");

    fclose(file);
}

int main(void) {
    const char *archivo_1 = "Cyl_1p0diam_60_uni_ondul_3cic_1p4ampX_1p4ampY.ply.txt";
    const char *archivo_2 = "cube_ball.ply.txt";

    leer_archivo(archivo_1);
    leer_archivo(archivo_2);

    return 0;
}
