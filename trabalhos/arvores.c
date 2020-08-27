#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    char chave;
    struct no *esq, *dir;
} no;

no* criaNo(int chave)
{
    no* novoNo = (no*) malloc(sizeof(no));
    novoNo->chave = chave;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}

no* montaArvore(int chaveRaiz, char *preOrdem, char *emOrdem, int numeroNos)
{
    no* raiz = criaNo(chaveRaiz);
    // Checa para ver se a raiz tem uma subárvore esquerda
    // Checa para ver se a raiz tem uma subárvore direita
    return raiz;
}

int main()
{
    int numeroCasos;
    scanf("%d", &numeroCasos);
    for(int i = 0; i < numeroCasos; i++)
    {
        int numeroNos;
        scanf("%d", &numeroNos);
        char preOrdem[52], emOrdem[52];
        scanf(" %s %s", preOrdem, emOrdem);
        // A pré-ordem começa pela raiz, logo o primeiro elemento do vetor pré-ordem será a chave da raiz.
        int chaveRaiz = preOrdem[0];
        no* raiz = montaArvore(chaveRaiz, preOrdem, emOrdem, numeroNos);
    }
}
