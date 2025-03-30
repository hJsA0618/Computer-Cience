#include <stdio.h>
#include <stdlib.h>

#define N 100
#define M 50
void imprimeVectorFloat(float miVec[], int n);
int contarMenoresQue(float miVec[], int n, float limite);

void imprimeVectorFloat(float miVec[], int n) {
    printf("\n--------------");
    for (int i = 0; i < n; i++) {
        printf("\npos=%d,\tvalor=%f", i, miVec[i]);
    }
    printf("\n--------------");
}

int hayUnRepetido(unsigned int vec[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (vec[i] == vec[j]) {
                return 1;  // TRUE
            }
        }
    }
    return 0;  // FALSE
}

int main(void) {
    unsigned int vec[N];
    for (int i = 0; i < N; i++) {
        vec[i] = (unsigned int)(rand() % (M + 1));
    }

    imprimeVectorFloat(vec, N);
    
    if (hayUnRepetido(vec, N)) {
        printf("Hay numeros repetidos en el vector.\n");
    } else {
        printf("No hay numeros repetidos en el vector.\n");
    }

    return 0;
}