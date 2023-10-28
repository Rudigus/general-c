#define NG_TAM 45 // Quantidade de pontos máxima a ser utilizada

double fatorial(int numero);

// Função que calcula os coeficientes de Gregory-Newton
void D(double *x, double *y, int n, double O[NG_TAM][NG_TAM], double *DN) {
  int i, j;
  DN[0] = y[0];
  for (i = 0; i < n - 1; i++) {
    O[i][0] = y[i + 1] - y[i];
  }
  for (i = 1; i < n; i++) {
    for (j = 0; j < n - i; j++) {
      O[j][i] = O[j + 1][i - 1] - O[j][i - 1];
    }
    DN[i] = O[0][i - 1];
  }
}

// Função que calcula o polinômio de Gregory-Newton
double P(double *x, double *y, double *DN, int n, double valor) {
  double h = x[2] - x[1];
  double u = (valor - x[0]) / h;
  double result = 0, prod = 1, sum = 0;

  for (int j = 0; j < n - 1; j++) {
    prod = prod * (u - j);
    sum = sum + ((DN[j + 1] / fatorial(j + 1)) * prod);
  }

  result = DN[0] + sum;

  return result;
}

// Calcula o fatorial de um número
double fatorial(int numero) {
  double result = numero;
  for (int i = 1; i < numero; i++) {
    result = result * (numero - 1);
    numero = numero - 1;
  }

  return result;
}