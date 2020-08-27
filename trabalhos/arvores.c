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
    // Se a raiz não for o primeiro nó do percurso em ordem da sua respectiva árvore, então ela terá uma subárvore esquerda.
    if(chaveRaiz != emOrdem[0])
    {
        char aux = emOrdem[0];
        int numeroNosEsq = 0, i = 0;
        // Calculamos o número de nós da subárvore esquerda.
        while(aux != chaveRaiz)
        {
            numeroNosEsq++;
            aux = emOrdem[++i];
        }
        char chaveRaizEsq;
        // Encontramos a chave da raiz da subárvore esquerda.
        for(int i = 0; i < numeroNos; i++)
        {
            for(int j = 0; j < numeroNosEsq; j++)
            {
                if(preOrdem[i] == emOrdem[j])
                {
                    chaveRaizEsq = preOrdem[i];
                    goto montaSubarvoreEsquerda;
                }
            }
        }
        // Montamos a subárvore esquerda.
        montaSubarvoreEsquerda:
            raiz->esq = montaArvore(chaveRaizEsq, preOrdem, emOrdem, numeroNosEsq);
    }
    // Se a raiz não for o último nó do percurso em ordem da sua respectiva árvore, então ela terá uma subárvore direita.
    if(chaveRaiz != emOrdem[numeroNos-1])
    {
        char aux = emOrdem[numeroNos-1];
        int numeroNosDir = 0, i = numeroNos - 1;
        // Calculamos o número de nós da subárvore direita.
        while(aux != chaveRaiz)
        {
            numeroNosDir++;
            aux = emOrdem[--i];
        }
        char chaveRaizDir;
        // Encontramos a chave da raiz da subárvore direita.
        for(int i = 0; i < numeroNos; i++)
        {
            for(int j = 1; j <= numeroNosDir; j++)
            {
                if(preOrdem[i] == emOrdem[numeroNos - j])
                {
                    chaveRaizDir = preOrdem[i];
                    goto montaSubarvoreDireita;
                }
            }
        }
        // Montamos a subárvore direita.
        montaSubarvoreDireita:
            raiz->dir = montaArvore(chaveRaizDir, preOrdem, emOrdem, numeroNosDir);
    }
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
