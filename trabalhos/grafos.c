#include <stdio.h>
#include <stdlib.h>

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

int main() {
    int numeroCasos;
    scanf("%d", &numeroCasos);
    for(int i = 0; i < numeroCasos; i++) {
        int nodoDesejado, numeroVertices, numeroArestas;
        scanf("%d", &nodoDesejado);
        scanf("%d %d", &numeroVertices, &numeroArestas);
        grafo *labirinto = inicializaGrafo(numeroVertices, numeroArestas);
        for(int j = 0; j < numeroArestas; j++) {
            
        }
    }
}
