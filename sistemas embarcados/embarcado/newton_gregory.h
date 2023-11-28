/*  Interface de uma biblioteca do método Newton Gregory para interpolação de polinômios,
    em que é possível calcular os coeficientes de um polinômio interpolador e
    calcular o valor de Y para um certo X utilizando um polinômio interpolador
*/

#ifndef NEWTONGREGORY_H_INCLUDED
#define NEWTONGREGORY_H_INCLUDED

// Quantidade de pontos máxima a ser utilizada
#define NG_TAM 16

// Calcula os coeficientes do polinômio de Newton Gregory e os armazena em coeficientesPolinomio
void calculaCoeficientesPolinomio(double *x, double *y, int numeroPontos, 
                                  double tabelaDiferencas[NG_TAM][NG_TAM], double *coeficientesPolinomio);

// Calcula e retorna a imagem do polinômio de Newton Gregory para uma abcissa específica
double calculaImagemPolinomio(double *x, double *y, double *coeficientesPolinomio, int numeroPontos, double abcissaInteresse);

#endif // NEWTONGREGORY_H_INCLUDED
