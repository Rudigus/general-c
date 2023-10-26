#include <stdio.h>
#include "main.h"

#define TAM 5

struct delta {
  double delta1;
  double delta2;
  double delta3;
  double delta4;
};

double h;

void executarBateriaTestes() {
  int numSucessos = 0;
  int numFalhas = 0;
  int numTestes = 3;
  double valoresTeste[] = {2.5, 5, 13.5};

  for (int i = 0; i < numTestes; i++) {
    numSucessos += testeQuadratica(valoresTeste[i]);
    numSucessos += testeCubica(valoresTeste[i]);
  }
  numFalhas = numTestes * 2 - numSucessos;

  printf("\nResultado da bateria de testes:\n\n");
  printf("Fun��o quadr�tica:\n");
  printf("\nTestes com sucesso: %d", numSucessos);
  printf("\nTestes com falha: %d", numFalhas);
}

// Retorna 1 se o teste teve sucesso
// 0 se o teste falhar
int testeQuadratica(double xEscolhido) {
  // Estruturas auxiliares
  double DN[TAM];
  struct delta O[TAM];
  // Entrada
  double n = 4;
  double x[4] = {1, 2, 3, 4};
  double y[4] = {1, 4, 9, 16};

  h = x[1] - x[0];
  D(x, y, n, O, DN, xEscolhido);
  double resultado = P(x, y, DN, n, xEscolhido);

  double yEsperado = xEscolhido * xEscolhido;
  if (resultado == yEsperado) {
    printf("\nSucesso, valor: %lf", resultado);
    return 1;
  } else {
      printf("\nFalha, valor retornado: %lf, valor esperado: %lf", resultado, yEsperado);
    return 0;
  }
}

int testeCubica(double xEscolhido) {
  // Estruturas auxiliares
  double DN[TAM];
  struct delta O[TAM];
  // Entrada
  double n = 4;
  double x[4] = {1, 2, 3, 4};
  double y[4] = {1, 8, 27, 64};

  h = x[1] - x[0];
  D(x, y, n, O, DN, xEscolhido);
  double resultado = P(x, y, DN, n, xEscolhido);

  double yEsperado = xEscolhido * xEscolhido * xEscolhido;
  if (resultado == yEsperado) {
    printf("\nSucesso, valor: %lf", resultado);
    return 1;
  } else {
      printf("\nFalha, valor retornado: %lf, valor esperado: %lf", resultado, yEsperado);
    return 0;
  }
}
