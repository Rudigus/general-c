#include <stdio.h>
#include <locale.h>

#include "newtonGregory.h"

void executarBateriaTestes();
int testeQuadratica(double xEscolhido);
int testeCubica(double xEscolhido);

void main() {
  executarBateriaTestes();
}

void executarBateriaTestes() {
  int numSucessos = 0;
  int numFalhas = 0;
  int numTestes = 3;
  double valoresTeste[] = {2.5, 5, 13.5};

  setlocale(LC_ALL,"Portuguese");

  for (int i = 0; i < numTestes; i++) {
    numSucessos += testeQuadratica(valoresTeste[i]);
    numSucessos += testeCubica(valoresTeste[i]);
  }
  numFalhas = numTestes * 2 - numSucessos;

  printf("\n\nResultado da bateria de testes:\n");
  printf("\nTestes com sucesso: %d", numSucessos);
  printf("\nTestes com falha: %d", numFalhas);
}

// Retorna 1 se o teste teve sucesso
// 0 se o teste falhar
int testeQuadratica(double xEscolhido) {
  // Estruturas auxiliares
  double DN[NG_TAM];
  double O[NG_TAM][NG_TAM];
  // Entrada
  double n = 4;
  double x[4] = {1, 2, 3, 4};
  double y[4] = {1, 4, 9, 16};

  D(x, y, n, O, DN);
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
  double DN[NG_TAM];
  double O[NG_TAM][NG_TAM];
  // Entrada
  double n = 4;
  double x[4] = {1, 2, 3, 4};
  double y[4] = {1, 8, 27, 64};

  D(x, y, n, O, DN);
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
