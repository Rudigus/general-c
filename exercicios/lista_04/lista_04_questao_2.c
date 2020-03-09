#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// Lista 04 - Questão 2
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

int desempilha(pilha** base)
{
	if(pilhaVazia(base))
	{
		return 1;
	}
	pilha* p = (pilha*) malloc(sizeof(pilha));
	p = (*base)->proximo;
	(*base)->proximo = p->proximo;
	free(p);
	return 0;
}

void liberarPilha(pilha** base)
{
	while(!desempilha(base));
	(*base)->proximo = NULL;
	return;
}

int main()
{
	char caractere;
	pilha *base = (pilha*) malloc(sizeof(pilha));
	base->proximo = NULL;
	while((caractere = getchar()) != EOF)
	{
		if(caractere == '(')
		{
			empilha(&base);
		}
		else if(caractere == ')')
		{
			// desempilha um elemento da pilha e, caso a pilha esteja vazia, o corpo do if é executado.
			if(desempilha(&base))
			{
				printf("incorrect\n");
				char c;
				// retira o resto do input buffer que não será mais necessário
				while((c = getchar()) != '\n' && c != EOF);
				liberarPilha(&base);
			}
		}
		else if(caractere == '\n')
		{
			if(pilhaVazia(&base))
			{
				printf("correct\n");
			}
			else
			{
				printf("incorrect\n");
				liberarPilha(&base);
			}
		}
	}
	free(base);
}
