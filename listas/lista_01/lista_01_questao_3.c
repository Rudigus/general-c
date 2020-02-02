#include <stdio.h>

// URI Online Judge - Problema 1182 - Column in Array - Nível 3
// Aluno: Rodrigo Matos Aguiar - Rudigus

// Tamanho da matriz quadrada
int t = 12;

// Calcula a soma de todos os 144 elementos da matriz
float sum(float matrix[t][t], int column)
{
	float sum = 0;
	for(int i = 0; i < t; i++)
	{
		sum += matrix[i][column];
		printf("matrix[%d][%d] = %f\n", i, column, matrix[i][column]);
	}
	return sum;
}

// Calcula a média entre todos os 144 elementos da matriz
float average(float matrix[t][t], int column)
{
	float average = 0;
	for(int i = 0; i < t; i++)
	{
		average += matrix[i][column];
	}
	average /= t;
	return average;
}

// Calcula a soma ou a média de elementos de uma coluna de uma matriz e mostra esse resultado, com uma casa decimal.
int main()
{
	float matrix[t][t];
	int c;
	scanf("%d", &c);
	char operation;
	scanf(" %c", &operation);
	for(int i = 0; i < t*t; i++)
	{
		scanf("%f", &matrix[i/t][i%t]);
	}
	printf("%.1f\n", (operation == 'S') ? sum(matrix, c) : average(matrix, c));
}
