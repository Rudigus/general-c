#include <stdio.h>
#include <stdlib.h>

// URI Online Judge
// 1076 - Desenhando Labirintos

#define BRANCO 0
#define AMARELO 1
#define VERMELHO 2

typedef struct adjacencia {
    int vertice;
    struct adjacencia *prox;
} adjacencia;

typedef struct vertice {
    adjacencia *cabeca;
} vertice;

typedef struct grafo {
    int numeroVertices;
    int numeroArestas;
    vertice *vertices;
} grafo;

grafo* inicializaGrafo(int numeroVertices, int numeroArestas) {
    grafo *g = (grafo*) malloc(sizeof(grafo));
    g->numeroVertices = numeroVertices;
    g->numeroArestas = numeroArestas;
    g->vertices = (vertice*) malloc(numeroVertices * sizeof(vertice));
    for(int i = 0; i < numeroVertices; i++) {
        g->vertices[i].cabeca = NULL;
    }
    return g;
}

adjacencia* criaAdjacencia(int vertice) {
    adjacencia *adj = (adjacencia*) malloc(sizeof(adjacencia));
    adj->vertice = vertice;
    adj->prox = NULL;
    return adj;
}

void criaAresta(grafo *g, int verticePartida, int verticeDestino) {
    adjacencia *adj = criaAdjacencia(verticeDestino);
    adj->prox = g->vertices[verticePartida].cabeca;
    g->vertices[verticePartida].cabeca = adj;
}

int visitaProfundidade(grafo *g, int verticePartida, int *cor) {
    int movimentos = 0;
    cor[verticePartida] = AMARELO;
    adjacencia *adj = g->vertices[verticePartida].cabeca;
    while(adj) {
        if(cor[adj->vertice] == BRANCO) {
            movimentos++;
            movimentos += visitaProfundidade(g, adj->vertice, cor);
            movimentos++;
        }
        adj = adj->prox;
    }
    cor[verticePartida] = VERMELHO;
    //printf("Do vértice %d são feitos %d movimentos\n", verticePartida, movimentos);
    return movimentos;
}

int calculaMovimentosCaneta(grafo *g, int verticePartida) {
    int cor[g->numeroVertices];
    for(int i = 0; i < g->numeroVertices; i++) {
        cor[i] = BRANCO;
    }
    return visitaProfundidade(g, verticePartida, cor);
}

int main() {
    int numeroCasos;
    scanf("%d", &numeroCasos);
    for(int i = 0; i < numeroCasos; i++) {
        int verticeDesejado, numeroVertices, numeroArestas;
        scanf("%d", &verticeDesejado);
        scanf("%d %d", &numeroVertices, &numeroArestas);
        grafo *labirinto = inicializaGrafo(numeroVertices, numeroArestas);
        for(int j = 0; j < numeroArestas; j++) {
            int verticePartida, verticeDestino;
            scanf("%d %d", &verticePartida, &verticeDestino);
            criaAresta(labirinto, verticePartida, verticeDestino);
            criaAresta(labirinto, verticeDestino, verticePartida);
        }
        int movimentosCaneta = calculaMovimentosCaneta(labirinto, verticeDesejado);
        printf("%d\n", movimentosCaneta);
    }
}
