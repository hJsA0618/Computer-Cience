#include <stdio.h>
#include <stdlib.h>


#define N 100
#define PLAUSIBLE_MAX 40
#define PLAUSIBLE_MIN -10

void imprimeVectorFloat(float miVec[], int n);

void imprimeVectorFloat(float miVec[], int n){

	printf("\n--------------");
	for(int i=0;i<n;i++){
		printf("\npos=%d,\tvalor=%.2f",i,miVec[i]);
	}
	printf("\n--------------");
}

int main(void){
	float vec[N];

	for(int i=0;i<N;i++){
		vec[i]=PLAUSIBLE_MIN + ((float)rand() / RAND_MAX) * ((float)PLAUSIBLE_MAX - (float)PLAUSIBLE_MIN);
    }
    imprimeVectorFloat(vec, N);


	printf("\n");

	return 0;
}