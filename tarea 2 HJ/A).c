/*en este codigo esta todo los codigos  transcritos para facil lectura

<-----------------DIAPOSITIVA 12----------------->
#include <stdio.h>

int main(void)
{
    printf("Hola clase! \n");
    getchar();
    return 0;
}
<-----------------DIAPOSITIVA 15----------------->
#include <stdio.h>

int main(void){
    int edad;
    printf("\n introduce tu edad: ");
    scanf("%d", &edad);
    printf("tu edad es %d \n", edad);
    getchar();
    return 0;

}
<-----------------DIAPOSITIVA 16----------------->
#include <stdio.h>

int main(void)
{
    int a;

    a=0;
    a=a+5;
    if (a==5)
        printf("\n a valia 0 antes \n");

    getchar()
    return 0;
}
<-----------------DIAPOSITIVA 18----------------->
#include <stdio.h>

int main(void)
{
    float  cels, farh;
    farh=95.0 ;
    cels= 5.0*(farh-32.0)/9.0 ;
    printf(">>>%f F son %f C\n", farh,cels);
    getchar()
    return 0;

}
<-----------------DIAPOSITIVA 19----------------->
#include <stdio.h>

int main(void)
{
    int age;
    printf("please your age");
    scanf("%d, ", &age);
    if (age<100){
        printf("you are pretty young!\n");
    }
    else if (age==100){
        printf("you are old\n");
    }
    else {
        printf("you are really old\n");
    }
    getchar()
    return 0;
}
/*