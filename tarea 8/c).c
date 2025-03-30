#include <stdio.h>
#include <windows.h>
#include <string.h>

#define N 100

int comparar_cadenas(char c1[], char c2[]) {
    int i = 0;
    while (c1[i] != '\0' && c2[i] != '\0') {
        if (c1[i] != c2[i]) {
            return 1;
        }
        i++;
    }
    return (c1[i] == c2[i]) ? 0 : 1;
}

CHAR ObtenerCaracter(void) {
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    INPUT_RECORD irInputRecord;
    DWORD dwEventosLeidos;
    CHAR cCaracter;

    while (ReadConsoleInputA(hStdin, &irInputRecord, 1, &dwEventosLeidos)) {
        if (irInputRecord.EventType == KEY_EVENT && 
            irInputRecord.Event.KeyEvent.wVirtualKeyCode != VK_SHIFT &&
            irInputRecord.Event.KeyEvent.wVirtualKeyCode != VK_MENU &&
            irInputRecord.Event.KeyEvent.wVirtualKeyCode != VK_CONTROL) {
            
            cCaracter = irInputRecord.Event.KeyEvent.uChar.AsciiChar;
            ReadConsoleInputA(hStdin, &irInputRecord, 1, &dwEventosLeidos);
            return cCaracter;
        }
    }
    return EOF;
}

void capturar_password(char *password) {
    int indice = 0;
    char c;

    printf("Ingresa tu password: ");
    while (indice < N - 1) {
        c = ObtenerCaracter();
        
        if (c == '\r') {
            break;
        } else if (c == 8) {
            if (indice > 0) {
                indice--;
                printf("\b \b");
            }
        } else {
            password[indice++] = c;
            printf("*");
        }
    }
    password[indice] = '\0';
    printf("\n");
}

int main() {
    char password[N];
    const char *password_real = "secreto";      //     <--------------- solo prueba :)

    capturar_password(password);

    if (comparar_cadenas(password, password_real) == 0) {
        printf("Password correcto.\n");
    } else {
        printf("Password incorrecto.\n");
    }

    return 0;
}
