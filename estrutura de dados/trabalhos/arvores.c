#include <stdio.h>
#include <stdlib.h>

const int maxNos = 52;

typedef struct no
{
    char chave;
    struct no *esq, *dir;
} no;

no* criaNo(char chave)
{
    no* novoNo = (no*) malloc(sizeof(no));
    novoNo->chave = chave;
    novoNo->esq = NULL;
    novoNo->dir = NULL;
    return novoNo;
}

int procurarIndiceNo(char *chaves, int inicio, int fim, char chave)
{
    int i;
    for(i = inicio; i <= fim; i++)
    {
        if(chaves[i] == chave)
        {
            return i;
        }
    }
    return -1;
}

int indexPreOrdem = 0;

// xYz, Yxz -> Yzx | ABCDEF, CBAEDF -> CBEFDA
no* montaArvore(char *preOrdem, char *emOrdem, int inicioEmOrdem, int fimEmOrdem)
{
    if(inicioEmOrdem > fimEmOrdem)
    {
        return NULL;
    }
    no* raiz = criaNo(preOrdem[indexPreOrdem++]);
    if(inicioEmOrdem == fimEmOrdem)
    {
        return raiz;
    }
    int indexEmOrdem = procurarIndiceNo(emOrdem, inicioEmOrdem, fimEmOrdem, raiz->chave);
    raiz->esq = montaArvore(preOrdem, emOrdem, inicioEmOrdem, indexEmOrdem - 1);
    raiz->dir = montaArvore(preOrdem, emOrdem, indexEmOrdem + 1, fimEmOrdem);
    return raiz;
}

void printarPosOrdem(no *raiz)
{
    if(raiz == NULL)
    {
        return;
    }
    printarPosOrdem(raiz->esq);
    printarPosOrdem(raiz->dir);
    printf("%c", raiz->chave);
}

int main()
{
    int numeroCasos;
    scanf("%d", &numeroCasos);
    int i;
    for(i = 0; i < numeroCasos; i++)
    {
        int numeroNos;
        scanf("%d", &numeroNos);
        char preOrdem[maxNos], emOrdem[maxNos];
        scanf(" %s %s", preOrdem, emOrdem);
        indexPreOrdem = 0;
        no* raiz = montaArvore(preOrdem, emOrdem, 0, numeroNos - 1);
        printarPosOrdem(raiz);
        printf("\n");
    }
}
