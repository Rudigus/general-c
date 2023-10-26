#include <stdio.h>
#include <locale.h>

#include "bateriaTestes.h"

#define TAM 5 // Quantidade de pontos máxima a ser utilizada

struct delta {
  double delta1;
  double delta2;
  double delta3;
  double delta4;
};

double h;

// Declaração das funções
void D(double *x, double *y, int n, struct delta *O, double *DN, double valor);

double P(double *x, double *y, double *DN, int n, double valor);

void print(double *x, double *y, double *DN, double result, int n);

int fatorial(int numero);

void printTabela(struct delta *O, int n, double *y);

int testeQuadratica(double xEscolhido);

void executarBateriaTestes();

int main() {
  int n;
  double valor, result;
  double x[TAM];
  double y[TAM];
  double DN[TAM];
  struct delta O[TAM];

  setlocale(LC_ALL,"Portuguese");

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

  h = x[1] - x[0];
  D(x, y, n, O, DN, valor);       // Calcula os coeficientes de Newton
  result = P(x, y, DN, n, valor); // Calcula o polinômio de Newton no ponto
  print(x, y, DN, result, n);
  printTabela(O, n, y);

  executarBateriaTestes();
  return 0;
}

// Função que calcula os coeficientes de Gregory-Newton
void D(double *x, double *y, int n, struct delta *O, double *DN, double valor) {
  if (n >= 3) {

    DN[0] = y[0];
    for (int i = 0; i < n; i++) {
      O[i].delta1 = (y[i + 1] - y[i]);
    }
    DN[1] = O[0].delta1;

    for (int i = 0; i < n; i++) {
      O[i].delta2 = (O[i + 1].delta1 - O[i].delta1);
    }
    DN[2] = O[0].delta2;
  }

  if (n >= 4) {
    for (int i = 0; i < n; i++) {
      O[i].delta3 = (O[i + 1].delta2 - O[i].delta2);
    }
    DN[3] = O[0].delta3;
  }

  if (n >= 5) {
    for (int i = 0; i < n; i++) {
      O[i].delta4 = (O[i + 1].delta3 - O[i].delta3);
    }
    DN[4] = O[0].delta4;
  }
}

// Função que calcula o polinômio de Gregory-Newton
double P(double *x, double *y, double *DN, int n, double valor) {
  double u = (valor - x[0]) / h;
  double result = 0, prod = 1, sum = 0;

  for (int j = 0; j < n - 1; j++) {
    prod = prod * (u - j);
    sum = sum + ((DN[j + 1] / fatorial(j + 1)) * prod);
  }

  result = DN[0] + sum;

  return result;
}

// Função que imprime os resultados na tela
void print(double *x, double *y, double *DN, double result, int n) {
  printf(
      "      ************************|RESULTADOS|************************\n\n");
  printf("Os pontos utilizados foram:\n");

  for (int i = 0; i < n; i++) {
    printf("X%d = %lf\n", i, x[i]);
    printf("Y%d = %lf\n\n", i, y[i]);
  }
  printf("Os coeficientes de Newton são:\n");

  for (int i = 0; i < n; i++) {
    printf("D%d = %lf\n\n", i, DN[i]);
  }
  printf("\n");
  printf("O valor de Y no ponto desejado: %lf\n", result);
}

// Calcula o fatorial de um número
int fatorial(int numero) {
  int result = numero;
  for (int i = 1; i < numero; i++) {
    result = result * (numero - 1);
    numero = numero - 1;
  }

  return result;
}

void printTabela(struct delta *O, int n, double *y) {
  printf("\n\n      ************************|TABELA DE "
         "DIFERENÇAS|************************\n\n");

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
