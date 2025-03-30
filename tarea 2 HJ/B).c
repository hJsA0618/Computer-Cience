#include <stdio.h>

int main(void)
{
    // Uso de \a (alerta/bell)
    printf("Hola clase! \a\n");

    // Uso de \b (backspace) para sobrescribir
    printf("Hola clase! \bX\n");

    // Uso de \f (form feed) - Hace el mismo efecto de la maquina de escribir de retroceder
    printf("Hola clase! \fNueva linea\n");

    // Uso de \n (newline) - salto de linea
    printf("Hola clase! \nNueva linea\n");

    // Uso de \r (carriage return) - regresa al inicio de la linea
    printf("Hola clase! \rRegresado al inicio\n");

    // Uso de \t (tabulacion) - inserta una tabulacion horizontal
    printf("Hola clase! \tCon tabulacion\n");

    // Uso de \v (vertical tab) - puede ser menos visible
    printf("Hola clase! \vNueva linea vertical\n");

    // Uso de \\ (backslash)
    printf("Hola clase! \\ barra invertida\n");

    // Uso de \' (comilla simple)
    printf("Hola clase! \'Comilla simple\'\n");

    // Uso de \" (comilla doble)
    printf("Hola clase! \"Comilla doble\"\n");

    // Uso de \000 (octal escape) - representando el caracter con codigo octal
    printf("Hola clase! \001 (octal 001)\n");

    // Uso de \xHH (hexadecimal escape) - representando el caracter con codigo hexadecimal
    printf("Hola clase! \x41 (hexadecimal 41)\n"); // 'A' en hexadecimal

    getchar();
    return 0;
}
