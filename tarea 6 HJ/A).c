#include <stdio.h>
#include <stdlib.h>


#define N 100

void imprimeVectorFloat(float miVec[], int n);

void imprimeVectorFloat(float miVec[], int n){

	printf("\n--------------");
	for(int i=0;i<n;i++){
		printf("\npos=%d,\tvalor=%f",i,miVec[i]);
	}
	printf("\n--------------");
}


int main(void){

	float vec[N];

	// llenar con multiplos de 10
	for(int i=0;i<N;i++)
		vec[i] = (i+1)*10.0;
	
	// mandar a imprimir a pantalla
	imprimeVectorFloat(vec, N);

	// llenar con numeros aleatorios 
	// la funcion rand() genera enteros entre 0 y RAND_MAX
	// y esta en <stdlib.h>
	for(int i=0;i<N;i++)
		vec[i] = rand();
	imprimeVectorFloat(vec, N);

	// llenar con numeros aleatorios entre 0 y 1 
	for(int i=0;i<N;i++)
		vec[i] = (float)rand()/RAND_MAX;
	imprimeVectorFloat(vec, N);

	// llenar con numeros aleatorios entre -1.0 y 1.0 
	for(int i=0;i<N;i++)
		vec[i] = ((float)rand()/RAND_MAX)*2.0 - 1.0;
	imprimeVectorFloat(vec, N);


	printf("\n");

	return 0;
}