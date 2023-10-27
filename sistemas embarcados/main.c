#include <stdio.h>
#include <locale.h>

#include "newtonGregory.h"

#define TAM 5 // Quantidade de pontos m�xima a ser utilizada

struct delta {
  double delta1;
  double delta2;
  double delta3;
  double delta4;
};

// Declara��o das fun��es

//void print(double *x, double *y, double *DN, double result, int n);

//void printTabela(struct delta *O, int n, double *y);

int main() {
  int n;
  double valor, result;
  double x[TAM];
  double y[TAM];
  double DN[TAM];
  struct delta O[TAM];

  setlocale(LC_ALL, "Portuguese");

  printf("Quantos pontos você vai utilizar?\n");
  scanf("%d", &n);

  printf("Para qual valor de x você quer o polinômio?\n");
  scanf("%lf", &valor);

  printf("Digite os valores das abscissas:\n");
  for (int i = 0; i < n; i++) {
    scanf("%lf", &x[i]);
  }

  printf("Digite os valores das ordenadas:\n");
  for (int i = 0; i < n; i++) {
    scanf("%lf", &y[i]);
  }

  D(x, y, n, O, DN);       // Calcula os coeficientes de Newton
  result = P(x, y, DN, n, valor); // Calcula o polin�mio de Newton no ponto
  printf("\nResultado: %lf", result);
  //print(x, y, DN, result, n);
  //printTabela(O, n, y);

  return 0;
}
/*
// Fun��o que imprime os resultados na tela
void print(double *x, double *y, double *DN, double result, int n) {
  printf(
      "      ************************|RESULTADOS|************************\n\n");
  printf("Os pontos utilizados foram:\n");

  for (int i = 0; i < n; i++) {
    printf("X%d = %lf\n", i, x[i]);
    printf("Y%d = %lf\n\n", i, y[i]);
  }
  printf("Os coeficientes de Newton s�o:\n");

  for (int i = 0; i < n; i++) {
    printf("D%d = %lf\n\n", i, DN[i]);
  }
  printf("\n");
  printf("O valor de Y no ponto desejado: %lf\n", result);
}

void printTabela(struct delta *O, int n, double *y) {
  printf("\n\n      ************************|TABELA DE "
         "DIFEREN�AS|************************\n\n");

  for (int i = 0; i < n; i++) {
    printf("%lf    ", y[i]);
    if ((n >= 2) && (i < n - 1))
      printf("%lf    ", O[i].delta1);
    if (n == 2)
      printf("\n");

    if ((n >= 3) && (i < n - 2))
      printf("%lf    ", O[i].delta2);
    if (i < n - 2)
      printf("    ");
    if (n == 3)
      printf("\n");

    if ((n >= 4) && (i < n - 3))
      printf("%lf    ", O[i].delta3);
    if (i < n - 3)
      printf("    ");
    if (n == 4)
      printf("\n");

    if ((n >= 5) && (i < n - 4))
      printf("%lf    ", O[i].delta4);
    if (i < n - 4)
      printf("    ");
    if (n == 5)
      printf("\n");
  }
}
*/