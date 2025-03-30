#include <stdio.h>

typedef struct {
    unsigned long long int id;
    char letra;
} RegistroIdentidad;

typedef struct {
    float temperatura;
    char unidad;
} Clima;

typedef struct {
    char modelo[50];
    int caballosDeFuerza;
    char version[50];
} Porsche;

int main() {
    RegistroIdentidad identidad = {123456789012345ULL, 'z'};
    Clima clima = {36.5, 'C'};
    Porsche porsche = {"Porsche 911 GT3 RS", 1099, "Versión 1.0"};

    RegistroIdentidad *ptrIdentidad = &identidad;
    Clima *ptrClima = &clima;
    Porsche *ptrPorsche = &porsche;

    printf("Dirección de RegistroIdentidad: %p, ptrIdentidad: %p\n", (void*)&identidad, (void*)ptrIdentidad);
    printf("Dirección de Clima: %p, ptrClima: %p\n", (void*)&clima, (void*)ptrClima);
    printf("Dirección de Porsche: %p, ptrPorsche: %p\n", (void*)&porsche, (void*)ptrPorsche);

    printf("\nAvanzando punteros:\n");

    ptrIdentidad++;
    ptrClima++;
    ptrPorsche++;

    printf("Después de ptr++:\n");
    printf("ptrIdentidad: %p (debería avanzar %zu bytes)\n", (void*)ptrIdentidad, sizeof(RegistroIdentidad));
    printf("ptrClima: %p (debería avanzar %zu bytes)\n", (void*)ptrClima, sizeof(Clima));
    printf("ptrPorsche: %p (debería avanzar %zu bytes)\n", (void*)ptrPorsche, sizeof(Porsche));

    return 0;
}
