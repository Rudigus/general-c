#include <mbed.h>
#include <stdlib.h>

#include "newton_gregory.h"

#define BUFFER_SIZE 50

// Declaração das funções

//void print(double *x, double *y, double *DN, double result, int n);

//void printTabela(double O[NG_TAM][NG_TAM], int n, double *y);

int lerSerialInt();
double lerSerialDouble();
void pularLinhaSerial();

int n;
double valor, result;
double x[NG_TAM];
double y[NG_TAM];
double DN[NG_TAM];
double O[NG_TAM][NG_TAM];

// Configurações da porta serial
Serial pc(USBTX, USBRX, 9600);
char buffer[BUFFER_SIZE];

int main() {
    while (1) {
        n = lerSerialInt();
        valor = lerSerialDouble();
        pularLinhaSerial();
        for (int i = 0; i < n; i++) {
            x[i] = lerSerialDouble();
        }
        pularLinhaSerial();
        for (int i = 0; i < n; i++) {
            y[i] = lerSerialDouble();
        }
        //pularLinhaSerial();
        // Calcula os coeficientes de Newton
        D(x, y, n, O, DN);
        // Calcula o polinômio de Newton no ponto
        result = P(x, y, DN, n, valor);
        pc.printf("RESULTADO: %lf", result);
    }
}

int lerSerialInt() {
    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = pc.getc();
        if (buffer[i] == ' ') {
            break;
        }
    }
    int valorInteiro = atoi(buffer);
    return valorInteiro;
}

double lerSerialDouble() {
    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer[i] = pc.getc();
        if (buffer[i] == ' ') {
            break;
        }
    }
    double valorDouble = atof(buffer);
    return valorDouble;
}

void pularLinhaSerial() {
    char c;
    do {
        c = pc.getc();
    } while (c != '\n');
}

/*
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
*/