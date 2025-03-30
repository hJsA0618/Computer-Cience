#include <stdio.h>

int main()
{
int a;
char b; 
float c;
double d; 
long e; 
unsigned int i; 
a = 4 * 6;
a = a + 5;
printf("el tamaño que ocupa el entero es de %d\n", sizeof(a));
printf("el tamaño que ocupa el char es de %d\n", sizeof(b));
printf("el tamaño que ocupa el float es de %d\n", sizeof(c));
printf("el tamaño que ocupa el double es de %d\n", sizeof(d));
printf("el tamaño que ocupa el long es de %d\n", sizeof(e));
printf("el tamaño que ocupa el unsigned int es de %d\n", sizeof(i));
getchar();
return 0;

//sizeof(a):
/*
Tipo de dato: int
Resultado: 4 bytes
Explicación: En la mayoría de las plataformas modernas, un int ocupa 4 bytes. 
Esto es común en muchas arquitecturas y compiladores.
sizeof(b):

Tipo de dato: char
Resultado: 1 byte
Explicación: Un char siempre ocupa 1 byte por definición del estándar C.
es el tipo de dato más básico y se utiliza para representar caracteres. 
sizeof(c):

Tipo de dato: float
Resultado: 4 bytes
Explicación: En la mayoría de las arquitecturas, un float ocupa 4 bytes. 
Esto es típico en muchas plataformas y compiladores.
ste formato proporciona una representación de números decimales
con una precisión adecuada para muchas aplicaciones sin usar demasiada memoria
sizeof(d):

Tipo de dato: double
Resultado: 8 bytes
Explicación: Un double generalmente ocupa 8 bytes en muchas plataformas modernas.
Esto permite una mayor precisión y un rango más amplio de valores en comparación con float.
sizeof(e):

Tipo de dato: long
Resultado: 4 bytes
Explicación: En algunas plataformas, como muchas plataformas de 32 bits, un long es de 4 bytes. 
Sin embargo, en plataformas de 64 bits, un long puede ser de 8 bytes. 
sizeof(i):

Tipo de dato: unsigned int
Resultado: 4 bytes
Explicación: Un unsigned int típicamente ocupa 4 bytes, similar a un int.
es un entero sin signo que, en la mayoría de las plataformas, ocupa el mismo tamaño que un int, 
es decir, 4 bytes. 
La única diferencia es que unsigned int no puede representar valores negativos
*/
}