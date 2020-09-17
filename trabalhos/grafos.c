#include <stdio.h>
#include <stdlib.h>

// URI Online Judge
// 1076 - Desenhando Labirintos

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
    grafo *temp = (grafo*) malloc(sizeof(grafo));
    temp->numeroVertices = numeroVertices;
    temp->numeroArestas = numeroArestas;
    temp->vertices = (vertice*) malloc(numeroVertices * sizeof(vertice));
    for(int i = 0; i < numeroVertices; i++) {
        temp->vertices[i].cabeca = NULL;
    }
    return temp;
}

adjacencia* criaAdjacencia(int vertice) {
    adjacencia *temp = (adjacencia*) malloc(sizeof(adjacencia));
    temp->vertice = vertice;
    temp->prox = NULL;
    return temp;
}

void criaAresta(grafo *labirinto, int verticePartida, int verticeDestino) {
    adjacencia *adj = criaAdjacencia(verticeDestino);
    adj->prox = labirinto->vertices[verticePartida].cabeca;
    labirinto->vertices[verticePartida].cabeca = adj;
}

int main() {
    int numeroCasos;
    scanf("%d", &numeroCasos);
    for(int i = 0; i < numeroCasos; i++) {
        int nodoDesejado, numeroVertices, numeroArestas;
        scanf("%d", &nodoDesejado);
        scanf("%d %d", &numeroVertices, &numeroArestas);
        grafo *labirinto = inicializaGrafo(numeroVertices, numeroArestas);
        for(int j = 0; j < numeroArestas; j++) {
            int verticePartida, verticeDestino;
            scanf("%d %d", &verticePartida, &verticeDestino);
        }
    }
}
