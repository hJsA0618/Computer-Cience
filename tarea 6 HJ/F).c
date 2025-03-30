#include<stdio.h>
#include "screen.h"
#include<math.h>

void pintaCuadro(int cini,int cfin,int rini, int rfin, int color);
void pintaCirculo(int cini,int cfin,int rini, int rfin, int color);


void pintaCuadro(int cini,int cfin,int rini, int rfin, int color){

	setColor(color);

	for(int r=rini ; r<=rfin ; r++){
		for(int c=cini ; c<=cfin ; c++){
			gotoxy(c,r);
			printf("#");
		}
	}

	setColor(I_NRM);

}



void pintaCirculo(int cini,int cfin,int rini, int rfin, int color){

	setColor(color);

	int centro_c = (cini+cfin)/2;
	int centro_r = (rini+rfin)/2;
	int radio = (cfin-cini)/2 < (rfin-rini)/2 ? (cfin-cini)/2 : (rfin-rini)/2;

	for(int r=rini ; r<=rfin ; r++){
		for(int c=cini ; c<=cfin ; c++){

			if( pow(r-centro_r,2) + pow(c-centro_c,2) <= radio*radio ){
				gotoxy(c,r);
				printf("#");
			}
		}
	}

	setColor(I_NRM);
}




int main(void){
	clearScreen();

	pintaCuadro(1, 1,2,24, I_YEL); // asta


	pintaCuadro(2, 27,5,16, I_GRN);
	pintaCuadro(28,53,4,15, I_WHT);
	pintaCuadro(54,80,3,14, I_RED);

	pintaCirculo(28+3,53-3,4+2,15-2, I_YEL ); //escudo



	gotoxy(1,24);

	return 0;

}