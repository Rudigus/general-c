#include <stdio.h>

// URI Online Judge - Problema 1435 - Square Matrix I - Nível 4
// Aluno: Rodrigo Matos Aguiar - Rudigus

// Retorna o elemento que deve ser printado em uma linha e uma coluna específicas.
int getActualElement(int i, int j, int n)
{
	// Distâncias em ordem - esquerda, cima, direita, baixo.
	int actualElement = 1, distance[4];
	distance[0] = j;
	distance[1] = i;
	distance[2] = (n - 1) - j;
	distance[3] = (n - 1) - i;
	// Menor distância é inicializada com a distância da esquerda, porém passará a guardar a menor das 4 distâncias.
	int smallestDistance = distance[0];
	for(int i = 1; i < 4; i++)
	{
		if(distance[i] < smallestDistance)
		{
			smallestDistance = distance[i];
		}
	}
	// A menor distância irá indicar, com precisão, o incremento necessário ao actualElement
	// de forma que seu valor seja proporcional à profundidade em que ele se encontra.
	actualElement += smallestDistance;
	return actualElement;
}

// Printa a matriz quadrada associada ao inteiro n fornecido.
void printSquareMatrix(int n)
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int actualElement = getActualElement(i, j, n);
			(j == 0) ? printf("%3d", actualElement) : printf("%4d", actualElement);
		}
		// Nova linha após cada coluna
		printf("\n");
	}
	// Nova linha após o fim da matriz.
	printf("\n");
}

// Recebe inteiros como inputs e printa as matrizes quadradas associadas a esses inputs. Para após receber 0 como input.
int main()
{
	int n;
	do
	{
		scanf("%d", &n);
		// Caso n seja 0, a função printSquareMatrix() não será chamada. Isso evitará que uma nova linha seja acrescentada desnecessariamente.
		if(n != 0)
		{
			printSquareMatrix(n);
		}
	}
	while(n != 0);
}

