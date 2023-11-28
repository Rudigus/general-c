/*  Implementação de uma biblioteca do método Newton Gregory para interpolação de polinômios,
    em que é possível calcular os coeficientes de um polinômio interpolador e
    calcular o valor de Y para um certo X utilizando um polinômio interpolador
*/

// Quantidade de pontos máxima a ser utilizada
#define NG_TAM 16

double fatorial(int numero);

/*  Função que calcula os coeficientes de Gregory-Newton
    Recebe os valores das coordenadas (x, y) dos pontos conhecidos, calcula os coeficientes de Newton-Gregory
    e armazena os dados no vetor coeficientesPolinomio
*/
void calculaCoeficientesPolinomio(double *x, double *y, int numeroPontos, 
                                  double tabelaDiferencas[NG_TAM][NG_TAM], double *coeficientesPolinomio) {
  int i, j;
  coeficientesPolinomio[0] = y[0];
  for (i = 0; i < numeroPontos - 1; i++) {
    tabelaDiferencas[i][0] = y[i + 1] - y[i];
  }
  for (i = 1; i < numeroPontos; i++) {
    for (j = 0; j < numeroPontos - i; j++) {
      tabelaDiferencas[j][i] = tabelaDiferencas[j + 1][i - 1] - tabelaDiferencas[j][i - 1];
    }
    coeficientesPolinomio[i] = tabelaDiferencas[0][i - 1];
  }
}

/*  Função que calcula o polinômio de Gregory-Newton
    Recebe os valores das coordenadas dos n pontos conhecidos (x, y), o valor da abcissa do ponto a ser determinado
    e calcula o valor da função para o x dado, isto é, calcula o somatório, o produtório e o fatorial de n, definindo P(x)
*/
double calculaImagemPolinomio(double *x, double *y, double *coeficientesPolinomio, int numeroPontos, double abcissaInteresse) {
  double h = x[2] - x[1];
  double u = (abcissaInteresse - x[0]) / h;
  double imagem = 0, prod = 1, sum = 0;

  for (int j = 0; j < numeroPontos - 1; j++) {
    // Produtório
    prod = prod * (u - j);
    // Somatório e fatorial (chamada da função fatorial)
    sum = sum + ((coeficientesPolinomio[j + 1] / fatorial(j + 1)) * prod);
  }
  // soma do termo inicial (delta^0) + somatório acumulado das parcelas de grau 1 ao grau n
  imagem = coeficientesPolinomio[0] + sum;

  return imagem;
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
