#include <stdio.h>
#include <locale.h>

#include "newton_gregory.h"

#define EPSILON 0.00000001

FILE *abrirArquivoRelatorioTestes();
int aproximadamenteIgual(double a, double b, double maximaDiferencaRelativa);

int main() {
  int numPontos, numTestes;
  double x[NG_TAM];
  double y[NG_TAM];
  double xDado[NG_TAM];
  double yEsperado[NG_TAM];
  double yEncontrado[NG_TAM];
  double DN[NG_TAM];
  double O[NG_TAM][NG_TAM];
  int numAcertos = 0, numErros = 0;
  FILE *arquivoBateriaTestes;
  int i;

  setlocale(LC_ALL,"Portuguese");

  arquivoBateriaTestes = fopen("bateria_testes.txt", "r");

  if (arquivoBateriaTestes == NULL) {
    FILE *arquivoResultado = abrirArquivoRelatorioTestes();
    fprintf(arquivoResultado, "Não foi possível ler o arquivo da bateria de testes.\n");
    fclose(arquivoResultado);
    return 1;
  }

  FILE *arquivoRelatorio = abrirArquivoRelatorioTestes();
  fprintf(arquivoRelatorio, "Histórico de testes:\n");
  while (!feof(arquivoBateriaTestes)) {
    fscanf(arquivoBateriaTestes, "%d %d", &numPontos, &numTestes);
    for (i = 0; i < numPontos; i++) {
      fscanf(arquivoBateriaTestes, "%lf", &x[i]);
    }
    for (i = 0; i < numPontos; i++) {
      fscanf(arquivoBateriaTestes, "%lf", &y[i]);
    }
    for (i = 0; i < numTestes; i++) {
      fscanf(arquivoBateriaTestes, "%lf", &xDado[i]);
    }
    for (i = 0; i < numTestes; i++) {
      fscanf(arquivoBateriaTestes, "%lf", &yEsperado[i]);
    }
    // Encontra os coeficientes de Newton
    D(x, y, numPontos, O, DN);
    
    for (i = 0; i < numTestes; i++) {
      yEncontrado[i] = P(x, y, DN, numPontos, xDado[i]);
      if (aproximadamenteIgual(yEncontrado[i], yEsperado[i], EPSILON)) {
        numAcertos += 1;
        fprintf(arquivoRelatorio, "\nAcerto, x utilizado: %lf, y encontrado: %lf", xDado[i], yEncontrado[i]);
      } else {
        numErros += 1;
        fprintf(arquivoRelatorio, "\nErro, x utilizado: %lf, y encontrado: %.20lf, y esperado: %.20lf", xDado[i], yEncontrado[i], yEsperado[i]);
      }
    }
  }
  fclose(arquivoBateriaTestes);

  fprintf(arquivoRelatorio, "\n\nRelatório da bateria de testes:\n");
  fprintf(arquivoRelatorio, "\nNúmero de acertos: %d", numAcertos);
  fprintf(arquivoRelatorio, "\nNúmero de erros: %d", numErros);
  fclose(arquivoRelatorio);
}

FILE *abrirArquivoRelatorioTestes() {
  FILE *arquivoRelatorioTestes;
  arquivoRelatorioTestes = fopen("relatorio_testes.txt", "w");
  return arquivoRelatorioTestes;
}

double lfabs(double numero) {
  if (numero < 0) {
    return -numero;
  }
  return numero;
}

int aproximadamenteIgual(double a, double b, double maximaDiferencaRelativa) {
  double diferenca = lfabs(a - b);
  a = lfabs(a);
  b = lfabs(b);
  double maiorNumero = (b > a) ? b : a;

  if (diferenca <= maiorNumero * maximaDiferencaRelativa)
    return 1;
  return 0;
}