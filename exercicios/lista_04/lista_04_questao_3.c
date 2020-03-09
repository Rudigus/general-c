#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// Lista 04 - Questão 3
// Aluno: Rodrigo Matos Aguiar - Rudigus

typedef struct pilha
{
	struct pilha *proximo;
} pilha;

int pilhaVazia(pilha** base)
{
	return (*base)->proximo == NULL;
}

void empilha(pilha** base)
{
	pilha *p = (pilha*) malloc(sizeof(pilha));
	p->proximo = *base;
	*base = p;
}

void desempilha(pilha** base, int* diamantesExtraidos)
{
	if(pilhaVazia(base))
	{
		return;
	}
	pilha* p = (pilha*) malloc(sizeof(pilha));
	p = (*base)->proximo;
	(*base)->proximo = p->proximo;
	free(p);
	*diamantesExtraidos += 1;
	return;
}

int main()
{
	int numeroCasos;
	scanf("%d", &numeroCasos);
	// getchar() vai retirar o '\n' do input buffer
	getchar();
	for(int i = 0; i < numeroCasos; i++)
	{
		int diamantesExtraidos = 0;
		pilha *base = (pilha*) malloc(sizeof(pilha));
		base->proximo = NULL;
		while(1)
		{
			char caractere;
			scanf("%c", &caractere);
			if(caractere == '<')
			{
				empilha(&base);
			}
			else if(caractere == '>')
			{
				desempilha(&base, &diamantesExtraidos);
			}
			else if(caractere == '\n')
			{
				printf("%d\n", diamantesExtraidos);
				break;
			}
		}
	}
}
