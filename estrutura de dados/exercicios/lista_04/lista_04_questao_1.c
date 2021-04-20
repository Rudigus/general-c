#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

// Lista 04 - Questão 1
// Aluno: Rodrigo Matos Aguiar - Rudigus

typedef struct pilha
{
	int numeroVagao;
	struct pilha *proximo;
} pilha;

pilha* inicializarPilha()
{
	pilha* base = (pilha*) malloc(sizeof(pilha));
	base->numeroVagao = -1;
	base->proximo = NULL;
	return base;
}

int pilhaVazia(pilha** base)
{
	return (*base)->proximo == NULL;
}

void empilha(pilha** base, int numeroVagao)
{
	pilha *p = inicializarPilha();
	p->proximo = *base;
	(*base)->numeroVagao = numeroVagao;
	*base = p;
}

void desempilha(pilha** base)
{
	pilha* p = (pilha*) malloc(sizeof(pilha));
	p = (*base)->proximo;
	(*base)->proximo = p->proximo;
	free(p);
	return;
}

void liberarPilha(pilha** base)
{
	while(!pilhaVazia(base))
	{
		desempilha(base);
	}
	(*base)->proximo = NULL;
	return;
}

int main()
{
	while(1)
	{
		int n;
		scanf("%d", &n);
		if(n == 0)
		{
			break;
		}
		while(1)
		{
			pilha* baseRota = inicializarPilha();
			pilha* baseEstacao = inicializarPilha();
			pilha* baseVagao = inicializarPilha();
			int primeiroValor;
			scanf("%d", &primeiroValor);
			if(primeiroValor == 0)
			{
				printf("\n");
				break;
			}
			else
			{
				empilha(&baseVagao, primeiroValor);
			}
			for(int i = 1; i < n; i++)
			{
				int valorAtual;
				scanf("%d", &valorAtual);
				empilha(&baseVagao, valorAtual);
			}
			int vagaoNecessario = n;
			while(1)
			{
				if(!pilhaVazia(&baseVagao) && baseVagao->proximo->numeroVagao == vagaoNecessario)
				{
					//printf("Vagão %d foi para a rota\n", vagaoNecessario);
					empilha(&baseRota, vagaoNecessario);
					desempilha(&baseVagao);
					vagaoNecessario--;
				}
				else if(!pilhaVazia(&baseEstacao) && baseEstacao->proximo->numeroVagao == vagaoNecessario)
				{
					//printf("Vagão %d foi da estação para a rota\n", vagaoNecessario);
					empilha(&baseRota, vagaoNecessario);
					desempilha(&baseEstacao);
					vagaoNecessario--;
				}
				else if(!pilhaVazia(&baseVagao))
				{
					//printf("Vagão %d foi para a estação\n", baseVagao->proximo->numeroVagao);
					empilha(&baseEstacao, baseVagao->proximo->numeroVagao);
					desempilha(&baseVagao);
				}
				else
				{
					if(!pilhaVazia(&baseEstacao))
					{
						printf("No\n");
						break;
					}
					else
					{
						printf("Yes\n");
						break;
					}
				}
			}
			// Liberando as pilhas utilizadas
			liberarPilha(&baseRota);
			liberarPilha(&baseEstacao);
			liberarPilha(&baseVagao);
		}
	}
}
