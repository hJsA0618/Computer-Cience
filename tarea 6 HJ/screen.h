#ifndef SCREEN_H
#define SCREEN_H

#include <stdio.h>

#define SCREEN_NC 80
#define SCREEN_NR 24

#define N_COLORS 8
#define I_NRM  0
#define I_RED  1
#define I_GRN  2
#define I_YEL  3
#define I_BLU  4
#define I_MAG  5
#define I_CYN  6
#define I_WHT  7

void gotoxy(int x, int y);
void clearScreen(void);
void setColor(int idxColor);

#endif /* SCREEN_H */
