#ifndef NEWTONGREGORY_H_INCLUDED
#define NEWTONGREGORY_H_INCLUDED

struct delta;

void D(double *x, double *y, int n, struct delta *O, double *DN);

double P(double *x, double *y, double *DN, int n, double valor);

#endif // NEWTONGREGORY_H_INCLUDED
