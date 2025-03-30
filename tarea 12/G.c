#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void fx(float x, float *result) {
    *result = x * x;  // f(x) = x^2
}

void dfx(float x, float *result) {
    *result = 2 * x;  
}

void derivadaAproximada(float *vector_x, int n, float h, float **derivada_aprox) {
    
    *derivada_aprox = (float*) malloc(n * sizeof(float));

    for (int i = 0; i < n; i++) {
        float fx_plus_h, fx_minus_h;
        fx(vector_x[i] + h, &fx_plus_h);   // f(x+h)
        fx(vector_x[i] - h, &fx_minus_h);  // f(x-h)
        
        (*derivada_aprox)[i] = (fx_plus_h - fx_minus_h) / (2 * h);
    }
}

void calcularEAM(float *derivada_aprox, float *vector_x, int n, float *EAM) {
    float suma_error = 0.0;
    for (int i = 0; i < n; i++) {
        float derivada_analitica;
        dfx(vector_x[i], &derivada_analitica);  
        
        float error = fabs(derivada_analitica - derivada_aprox[i]);  
        suma_error += error;
    }
    *EAM = suma_error / n;  
}

int main() {
    float a = 0.0, b = 2.0, h = 0.1;

    int n = (int)((b - a) / h) + 1;

    float *vector_x = (float*) malloc(n * sizeof(float));

    for (int i = 0; i < n; i++) {
        vector_x[i] = a + i * h;
    }

    float *derivada_aprox = NULL;
    derivadaAproximada(vector_x, n, h, &derivada_aprox);

    float EAM = 0.0;
    calcularEAM(derivada_aprox, vector_x, n, &EAM);
    
    printf("Intervalo: [%.2f, %.2f] con paso h = %.2f\n", a, b, h);
    printf("Error Absoluto Medio (EAM): %.10f\n", EAM);


    free(vector_x);
    free(derivada_aprox);

    return 0;
}
