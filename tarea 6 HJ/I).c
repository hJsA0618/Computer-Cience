/*i) Hacer una función que recibe un vector de tipo float y regresa por
la izquierda la varianza muestral de los datos (ver el link explicativo de
la varianza muestral que anexo). Para calcular lo anterior, hacer y usar
adentro otra función que calcula el promedio de los datos.*/

#include <stdio.h>
#include <math.h>

// Prototipos de funciones
float calcularMedia(float val[], int size);
float calcularVarianzaMuestral(float val[], int size);
void arreglovectoresusuario(void);

void arreglovectoresusuario(void) {
    int sizeA;
    printf("Numero de arreglos: ");
    scanf("%d", &sizeA);
    
    float val[sizeA];
    
    // Pedir al usuario los valores
    for (int i = 0; i < sizeA; i++) {
        printf("Ingresa el valor %d: ", i + 1);
        scanf("%f", &val[i]);
    }

    // Imprimir los valores del arreglo
    printf("Los arreglos del vector son: \n");
    for (int i = 0; i < sizeA; i++) {
        printf("%f ", val[i]);
    }
    printf("\n");
    
    // Calcular la media
    float media = calcularMedia(val, sizeA);
    printf("La media de los arreglos es: %f\n", media);
    
    // Calcular la varianza muestral
    float varianza = calcularVarianzaMuestral(val, sizeA);
    printf("La varianza muestral de los arreglos es: %f\n", varianza);
}

float calcularMedia(float val[], int size) {
    float sumatoria = 0;
    for (int i = 0; i < size; i++) {
        sumatoria += val[i];
    }
    return sumatoria / size;
}

float calcularVarianzaMuestral(float val[], int size) {
    float media = calcularMedia(val, size);
    float sumaStndar = 0;
    for (int i = 0; i < size; i++) {
        sumaStndar += (val[i] - media) * (val[i] - media);
    }
    return sumaStndar / (size - 1);  // Varianza muestral
}

int main(void) {
    arreglovectoresusuario();
    return 0;
}

