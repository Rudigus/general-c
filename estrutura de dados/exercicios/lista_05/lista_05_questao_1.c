#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct fila
{
    int chave;
    struct fila *proximo;
} fila;

fila* inicializarFila()
{
    fila *fim = (fila*) malloc(sizeof(fila));
    fim->chave = 1;
    fim->proximo = NULL;
    return fim;
}

void enfila(fila** fim, int chave)
{
    fila *f = inicializarFila();
    f->chave = chave;
    f->proximo = *fim;
    *fim = f;
}

void desenfila(fila** fim)
{
    fila *f = *fim;
    while(f->proximo->proximo != NULL)
    {
        f = f->proximo;
    }
    fila *temp = f->proximo;
    f->proximo = NULL;
    free(temp);
}

fila* acharInicio(fila* fim)
{
    fila *inicio = fim;
    while(inicio->proximo != NULL)
    {
        inicio = inicio->proximo;
    }
    return inicio;
}

//int calcularNumeroCartas(fila *fim)
//{
//    int i = 1;
//    fila *f = fim;
//    while(f->proximo != NULL)
//    {
//        i++;
//        f = f->proximo;
//    }
//    return i;
//}

int main()
{
    while(true) {
        int numeroCartas;
        scanf("%d", &numeroCartas);
        if(numeroCartas == 0)
        {
            break;
        }
        printf("Discarded cards:");
        fila *fim = inicializarFila();
        for(int i = 0; i < numeroCartas - 1; i++)
        {
            enfila(&fim, i + 2);
        }
        while(numeroCartas >= 2)
        {
            int chave = (acharInicio(fim))->chave;
            printf(" %d", chave);
            desenfila(&fim);
            numeroCartas--;
            if(numeroCartas >= 2)
            {
                printf(",");
                chave = (acharInicio(fim))->chave;
                desenfila(&fim);
                enfila(&fim, chave);
            }
        }
        printf("\nRemaining card: %d\n", fim->chave);
    }
}
