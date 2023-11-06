#include <stdio.h>
#include <locale.h>

#include "newton_gregory.h"

// Declaração das funções

void print(double *x, double *y, double *DN, double result, int n);

void printTabela(double O[NG_TAM][NG_TAM], int n, double *y);

int main() {
  int n;
  double valor, result;
  double x[NG_TAM];
  double y[NG_TAM];
  double DN[NG_TAM];
  double O[NG_TAM][NG_TAM];

  setlocale(LC_ALL, "Portuguese");

  printf("Quantos pontos você vai utilizar?\n");
  fflush(stdout);
  scanf("%d", &n);

  printf("Para qual valor de x você quer o polinômio?\n");
  fflush(stdout);
  scanf("%lf", &valor);

  printf("Digite os valores das abscissas:\n");
  fflush(stdout);
  for (int i = 0; i < n; i++) {
    scanf("%lf", &x[i]);
  }

  printf("Digite os valores das ordenadas:\n");
  fflush(stdout);
  for (int i = 0; i < n; i++) {
    scanf("%lf", &y[i]);
  }
  // Calcula os coeficientes de Newton
  D(x, y, n, O, DN);
  // Calcula o polinômio de Newton no ponto
  result = P(x, y, DN, n, valor);
  print(x, y, DN, result, n);
  //printTabela(O, n, y);

  return 0;
}

// Função que imprime os resultados na tela
void print(double *x, double *y, double *DN, double result, int n) {
  printf(
      "      ************************|RESULTADOS|************************\n\n");
  printf("Os pontos utilizados foram:\n");

  for (int i = 0; i < n; i++) {
    printf("X%d = %lf, Y%d = %lf\n\n", i, x[i], i, y[i]);
  }
  printf("Os coeficientes de Newton são:\n");

  for (int i = 0; i < n; i++) {
    printf("D%d = %lf\n\n", i, DN[i]);
  }
  printf("\n");
  printf("O valor de Y no ponto desejado: %lf\n", result);
}

void printTabela(double O[NG_TAM][NG_TAM], int n, double *y) {
  printf("\n\n      ************************|TABELA DE "
         "DIFERENÇAS|************************\n\n");

  for (int i = 0; i < n; i++) {
    printf("%lf    ", y[i]);
    for (int j = 0; j < n - i - 1; j++) {
      printf("%lf    ", O[i][j]);
    }
    printf("\n");
  }
}
