// Quantidade de pontos máxima a ser utilizada
#define NG_TAM 45

double fatorial(int numero);

// Função que calcula os coeficientes de Gregory-Newton
// Recebe os valores das coordenadas (x, y) dos pontos conhecidos, calcula os coeficientes de Newton-Gregory e armazena os dados no vetor DN
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

/*  Função que calcula o polinômio de Gregory-Newton
    Recebe os valores das coordenadas dos n pontos conhecidos (x,Y)  e o valor da absissa do ponto a ser determinado e  calcula o valor da função para o x dado,
    isto é, calcula o somatório, o produtório e o fatoria de n, definindo P(x)
*/
double P(double *x, double *y, double *DN, int n, double valor) {
  double h = x[2] - x[1];
  double u = (valor - x[0]) / h;
  double result = 0, prod = 1, sum = 0;


  for (int j = 0; j < n - 1; j++) {
    // Produtório
    prod = prod * (u - j);
    // Somatório e fatorial (chamada da função fatorial)
    sum = sum + ((DN[j + 1] / fatorial(j + 1)) * prod);
  }
  // soma do termo inicial (delta^0) + somatório acumulado das parcelas de grau 1 ao grau n
  result = DN[0] + sum;

  return result;
}

// Calcula o fatorial de um número, no caso, do número n (grau do polinômio), recebendo como parâmetro n
double fatorial(int numero) {
  double result = numero;
  // Cálculo do fatorial Ex: 5! = 5*4*3*2
  for (int i = 1; i < numero; i++) {
    result = result * (numero - 1);
    numero = numero - 1;
  }
  // retorna o valor do fatorial do número
  return result;
}
