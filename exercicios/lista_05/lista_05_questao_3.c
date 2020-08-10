#include <stdio.h>
#include <stdlib.h>

#define true 1

typedef struct caixa
{
    int id;
    int tempoProcessamentoItem;
    int tempoAtendimento;
    struct caixa *proximo;
} caixa;

typedef struct cliente
{
    int numeroItens;
    struct cliente *proximo;
} cliente;

caixa* inicializarCaixa()
{
    caixa *ca = (caixa*) malloc(sizeof(caixa));
    ca->id = -1;
    ca->tempoProcessamentoItem = -1;
    ca->tempoAtendimento = 0;
    ca->proximo = NULL;
    return ca;
}

cliente* inicializarCliente()
{
    cliente *cl = (cliente*) malloc(sizeof(cliente));
    cl->numeroItens = -1;
    cl->proximo = NULL;
    return cl;
}

void enfilaCaixa(caixa **ca, int tempoProcessamentoItem, int id)
{
    caixa *temp = inicializarCaixa();
    temp->tempoProcessamentoItem = tempoProcessamentoItem;
    temp->id = id;
    temp->proximo = *ca;
    *ca = temp;
}

void enfilaCliente(cliente **cl, int numeroItens)
{
    cliente *temp = inicializarCliente();
    temp->numeroItens = numeroItens;
    temp->proximo = *cl;
    *cl = temp;
}

int desenfilaCliente(cliente **cl)
{
    if((*cl)->proximo != NULL)
    {
        cliente *aux = *cl;
        while(aux->proximo->proximo != NULL)
        {
            aux = aux->proximo;
        }
        cliente *temp = aux->proximo;
        aux->proximo = NULL;
        int numeroItens = temp->numeroItens;
        free(temp);
        return numeroItens;
    }
    else
    {
        int numeroItens = (*cl)->numeroItens;
        free(*cl);
        *cl = NULL;
        return numeroItens;
    }
}

int calcularMenorTempoAtendimento(caixa *ca, int *menorId)
{
    int menorTempoAtendimento = ca->tempoAtendimento;
    *menorId = ca->id;
    while(ca->proximo != NULL)
    {
        ca = ca->proximo;
        if(ca->tempoAtendimento <= menorTempoAtendimento)
        {
            menorTempoAtendimento = ca->tempoAtendimento;
            *menorId = ca->id;
        }
    }
    return menorTempoAtendimento;
}

int calcularMaiorTempoAtendimento(caixa *ca)
{
    int maiorTempoAtendimento = ca->tempoAtendimento;
    while(ca->proximo != NULL)
    {
        ca = ca->proximo;
        if(ca->tempoAtendimento > maiorTempoAtendimento)
        {
            maiorTempoAtendimento = ca->tempoAtendimento;
        }
    }
    return maiorTempoAtendimento;
}

void atendeCliente(caixa **ca, int numeroItens)
{
    int menorId;
    int menorTempoAtendimento = calcularMenorTempoAtendimento(*ca, &menorId);
    caixa *aux = *ca;
    while(aux != NULL)
    {
        if(aux->id == menorId)
        {
            aux->tempoAtendimento += aux->tempoProcessamentoItem * numeroItens;
            return;
        }
        aux = aux->proximo;
    }
}

//void impressora(caixa *ca)
//{
//    caixa *aux = ca;
//    while(aux != NULL)
//    {
//        printf("%d ", aux->tempoAtendimento);
//        aux = aux->proximo;
//    }
//    printf(".\n");
//}

int main()
{
    int numeroCaixas, numeroClientes;
    caixa *caixas = NULL;
    cliente *clientes = NULL;
    scanf("%d %d", &numeroCaixas, &numeroClientes);
    for(int i = 0; i < numeroCaixas; i++)
    {
        int tempoCaixa;
        scanf(" %d", &tempoCaixa);
        enfilaCaixa(&caixas, tempoCaixa, i + 1);
    }
    for(int i = 0; i < numeroClientes; i++)
    {
        int numeroItensCliente;
        scanf(" %d", &numeroItensCliente);
        enfilaCliente(&clientes, numeroItensCliente);
    }
    while(clientes != NULL)
    {
//        impressora(caixas);
        int numeroItens = desenfilaCliente(&clientes);
        atendeCliente(&caixas, numeroItens);
    }
    printf("%d\n", calcularMaiorTempoAtendimento(caixas));
}
