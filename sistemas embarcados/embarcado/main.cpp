/*  Programa para calcular o valor de Y para um X fornecido sem informar a função, apenas fornecendo um conjunto
    de pontos conhecidos. Utiliza o método de Newton Gregory para calcular um polinômio interpolador que
    possibilita o cálculo do valor de Y
*/

#include <mbed.h>
#include <stdlib.h>

#include "newton_gregory.h"

#define BUFFER_SIZE 50

// Declaração das funções

int lerSerialInt();
double lerSerialDouble();
void pularLinhaSerial();

int numeroPontos;
double abcissaInteresse, imagemEncontrada;
double x[NG_TAM];
double y[NG_TAM];
double coeficientesPolinomio[NG_TAM];
double tabelaDiferencas[NG_TAM][NG_TAM];

// Configurações da porta serial
Serial pc(USBTX, USBRX, 9600);
char buffer[BUFFER_SIZE];

int main() {
    while (1) {
        numeroPontos = lerSerialInt();
        abcissaInteresse = lerSerialDouble();
        pularLinhaSerial();
        for (int i = 0; i < numeroPontos; i++) {
            x[i] = lerSerialDouble();
        }
        pularLinhaSerial();
        for (int i = 0; i < numeroPontos; i++) {
            y[i] = lerSerialDouble();
        }
        //pularLinhaSerial();
        // Calcula os coeficientes de Newton
        calculaCoeficientesPolinomio(x, y, numeroPontos, tabelaDiferencas, coeficientesPolinomio);
        // Calcula o polinômio de Newton no ponto
        imagemEncontrada = calculaImagemPolinomio(x, y, coeficientesPolinomio, numeroPontos, abcissaInteresse);
        pc.printf("RESULTADO: %lf", imagemEncontrada);
    }
}

// Faz a leitura de um int pela interface serial e o retorna
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

// Faz a leitura de um double pela interface serial e o retorna
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

// Faz a leitura do serial até encontrar um caractere de nova linha (\n)
void pularLinhaSerial() {
    char c;
    do {
        c = pc.getc();
    } while (c != '\n');
}