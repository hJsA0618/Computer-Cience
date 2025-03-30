/*Hacer una función que, dadas 2 cadenas de caracteres que se mandan
por parámetro (sentece y word) busque si existe la cadena word
dentro de la cadena sentence. Si existe regresa TRUE, de lo contrario
FALSE.*/

#include <stdio.h>
#include <string.h>
#define N 1024

int contains(const char *sentence, const char *word) {
    if (strstr(sentence, word) != NULL) {
        return 1; // TRUE
    } else {
        return 0; // FALSE
    }
}

int main() {
    char sentence[N];
    char word[N];

    printf("Ingresa la cadena (sentence): ");
    fgets(sentence, N, stdin);
    sentence[strcspn(sentence, "\n")] = '\0';

    printf("Ingresa la palabra (word): ");
    fgets(word, N, stdin);
    word[strcspn(word, "\n")] = '\0'; 

    if (contains(sentence, word)) {
        printf("La palabra '%s' se encuentra en la cadena.\n", word);
    } else {
        printf("La palabra '%s' NO se encuentra en la cadena.\n", word);
    }

    return 0;
}