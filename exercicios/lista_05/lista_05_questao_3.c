#include <stdio.h>
#include <stdlib.h>

#define true 1

typedef struct caixa
{
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

void enfilaCaixa(caixa **ca, int tempoProcessamentoItem)
{
    caixa *temp = inicializarCaixa();
    temp->tempoProcessamentoItem = tempoProcessamentoItem;
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
    cliente *aux = *cl;
    if(aux->proximo != NULL)
    {
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
        int numeroItens = aux->numeroItens;
        printf("%d", numeroItens);
        //free(aux);
        aux = NULL;
        return numeroItens;
    }
}

int calcularMenorTempoAtendimento(caixa *ca)
{
    int menorTempoAtendimento = ca->tempoAtendimento;
    while(ca->proximo != NULL)
    {
        ca = ca->proximo;
        if(ca->tempoAtendimento < menorTempoAtendimento)
        {
            menorTempoAtendimento = ca->tempoAtendimento;
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
    int menorTempoAtendimento = calcularMenorTempoAtendimento(*ca);
    caixa *aux = *ca;
    while(true)
    {
        if(aux->tempoAtendimento == menorTempoAtendimento)
        {
            aux->tempoAtendimento += aux->tempoProcessamentoItem * numeroItens;
            return;
        }
        aux = aux->proximo;
    }
}

int main()
{
    int numeroCaixas, numeroClientes;
    caixa *caixas;
    cliente *clientes;
    scanf("%d %d", &numeroCaixas, &numeroClientes);
    for(int i = 0; i < numeroCaixas; i++)
    {
        int tempoCaixa;
        scanf(" %d", &tempoCaixa);
        enfilaCaixa(&caixas, tempoCaixa);
    }
    for(int i = 0; i < numeroClientes; i++)
    {
        int numeroItensCliente;
        scanf(" %d", &numeroItensCliente);
        enfilaCliente(&clientes, numeroItensCliente);
    }
    while(clientes != NULL)
    {
        int numeroItens = desenfilaCliente(&clientes);
        atendeCliente(&caixas, numeroItens);
    }
    printf("%d", calcularMaiorTempoAtendimento(caixas));
}
