#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct box
{
char conteudo;
struct box *proximo;
} box;

box *inicio, *novo, *temp1, *temp2;

int contPassos = 1;

void printarLista()
{
	novo = inicio->proximo;
	printf("%2d - ", contPassos);
	contPassos++;
	while(novo != NULL)
	{
		printf("%c ", novo->conteudo);
		novo = novo->proximo;
	}
	printf("\n");
}

void colocarFinalLista(char caractere)
{
	novo = inicio;
	while(novo->proximo != NULL)
	{
		novo = novo->proximo;
	}
	novo->proximo = (box *) malloc(sizeof(box));
	novo = novo->proximo;
	novo->conteudo = caractere;
	novo->proximo = NULL;
	printarLista();
}

void colocarInicioLista(char caractere)
{
	novo = (box *) malloc(sizeof(box));
	novo->proximo = inicio;
	inicio->conteudo = caractere;
	inicio = novo;
	printarLista();
}

void colocarEntreCaracteres(char caractere, char caractereInicial, char caractereFinal)
{
	temp1 = inicio->proximo;
	while(temp1->conteudo != caractereInicial && temp1->conteudo != caractereFinal)
	{
		temp1 = temp1->proximo;
	}
	novo = (box *) malloc(sizeof(box));
	novo->conteudo = caractere;
	novo->proximo = temp1->proximo;
	temp1->proximo = novo;
	printarLista();
}

void removerCaractere(char caractere)
{
	temp1 = inicio;
	while(temp1->proximo->conteudo != caractere)
	{
		temp1 = temp1->proximo;
	}
	temp2 = temp1->proximo;
	temp1->proximo = temp2->proximo;
	free(temp2);
	printarLista();
}

void removerUltimoCaractere()
{
	temp1 = inicio;
	while(temp1->proximo->proximo != NULL)
	{
		temp1 = temp1->proximo;
	}
	temp2 = temp1->proximo;
	temp1->proximo = temp2->proximo;
	free(temp2);
	printarLista();
}

int main()
{
	inicio = (box *) malloc(sizeof(box));
	inicio->proximo = NULL;
	colocarFinalLista('A');
	colocarInicioLista('B');
	colocarFinalLista('C');
	colocarFinalLista('D');
	colocarEntreCaracteres('E', 'A', 'C');
	colocarFinalLista('F');
	colocarInicioLista('G');
	removerUltimoCaractere();
	removerCaractere(inicio->proximo->conteudo);
	colocarEntreCaracteres('H', 'A', 'E');
	removerCaractere('A');
	colocarEntreCaracteres('I', 'E', 'D');
	colocarFinalLista('J');
	colocarEntreCaracteres('K', 'B', 'H');
	removerCaractere('D');
	removerCaractere('K');
	removerCaractere('I');
	removerCaractere('B');
	colocarFinalLista('L');
}
