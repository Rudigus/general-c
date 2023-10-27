#define TAM 5 // Quantidade de pontos m�xima a ser utilizada

struct delta {
  double delta1;
  double delta2;
  double delta3;
  double delta4;
};

// Fun��o que calcula os coeficientes de Gregory-Newton
void D(double *x, double *y, int n, struct delta *O, double *DN) {
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

// Fun��o que calcula o polin�mio de Gregory-Newton
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

// Calcula o fatorial de um n�mero
int fatorial(int numero) {
  int result = numero;
  for (int i = 1; i < numero; i++) {
    result = result * (numero - 1);
    numero = numero - 1;
  }

  return result;
}