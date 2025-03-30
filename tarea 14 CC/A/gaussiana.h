#ifndef GAUSSIANA_H
#define GAUSSIANA_H

void eliminacionGaussiana(double **A, double *b, int n);
void sustitucionHaciaAtras(double **A, double *b, double *x, int n);
void leerDatos(const char *archivoA, const char *archivoB, double **A, double *b, int n);
void escribirSolucion(const char *archivo, double *x, int n);
void crearMemoria(double ***A, double **b, double **x, int n);
void liberarMemoria(double **A, double *b, double *x, int n);

#endif

