#ifndef NEWTONGREGORY_H_INCLUDED
#define NEWTONGREGORY_H_INCLUDED

// Quantidade de pontos máxima a ser utilizada
#define NG_TAM 45

void D(double *x, double *y, int n, double O[NG_TAM][NG_TAM], double *DN);

double P(double *x, double *y, double *DN, int n, double valor);

#endif // NEWTONGREGORY_H_INCLUDED
