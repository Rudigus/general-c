#include <stdio.h>

// URI Online Judge - Problema 1180 - Lowest Number and Position - Nível 2
// Aluno: Rodrigo Matos Aguiar - Rudigus

// Recebe uma array e retorna o índice do número de menor valor de toda a array.
int calcularIndiceMenorValor(int x[], int n)
{
	int imv = 0;
	for(int i = 1; i < n; i++)
	{
		if(x[i] < x[imv])
		{
			imv = i;
		}
	}
	return imv;
}

// Recebe um inteiro X informando o tamanho de uma array, recebe X inteiros que a compõem e
// informa o elemento de menor valor e seu respectivo índice.
int main()
{
	int n;
	scanf("%d", &n);
	int x[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &x[i]);
	}
	int imv = calcularIndiceMenorValor(x, n);
	printf("Menor valor: %d\n", x[imv]);
	printf("Posicao: %d\n", imv);
}

