#include <stdio.h>

// URI Online Judge - Problema 1176 - Fibonacci Array - Nível 4

// Função que recebe como parâmetro um número N e retorna o N-ésimo termo da sequência de Fibonacci.
unsigned long fibonacci(int numFornecido)
{
	unsigned long n1 = 0, n2 = 1, aux = 0;
	for(int i = 0; i < numFornecido; i++)
	{
		aux = n2;
		n2 = n2 + n1;
		n1 = aux;
	}
	return n1;
}

// Lê um número X como entrada e executa X testes. Cada teste consiste em printar o resultado da função Fibonacci de acordo com a entrada fornecida.
int main()
{
	int numeroTestes;
	scanf("%d", &numeroTestes);
	for(int i = 0; i < numeroTestes; i++)
	{
		int numFornecido;
		scanf("%d", &numFornecido);
		printf("Fib(%d) = %lu\n", numFornecido, fibonacci(numFornecido));
	}
}
