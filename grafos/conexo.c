#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
    int vertice;
    struct NO *proximo;
} NO;

typedef struct {
    int *vetor, tamanho, topo;
} PILHA;

typedef struct {
    NO **vertice;
    int numVertices;
} GRAFO;
/* representando o grafo através de uma lista de adjacências */

int criaPilha(PILHA *p, int n) {
    /* Se houver memória disponível, cria uma pilha de vértices com n posições e devolve 0; caso contrário, devolve -1 */
    p->vetor = malloc(sizeof(int) * n);
    if (p->vetor == NULL) { /* falta de memória */
        return -1;
    }
    p->topo = -1;
    p->tamanho = n;
    return 0;
} /* fim criaPilha */

int empilha(PILHA *p, int e) {
    /* Se houver espaço disponível, empilha o elemento e na pilha p e devolve 0; caso contrário, devolve -1 */
    if (p->topo < p->tamanho - 1) {
        p->topo++;
        p->vetor[p->topo] = e;
        return 0;
    } else { /* overflow */
        return -1;
    }
} /* fim empilha */

int desempilha(PILHA *p) {
    /* Se a pilha p não estiver vazia, remove e devolve o elemento no topo da pilha; caso contrário, devolve -1 */
    if (p->topo > -1) {
        p->topo--;
        return p->vetor[p->topo];
    } else { /* underflow */
        return -1;
    }
} /* fim desempilha */

int pilhaVazia(PILHA p) {
    /* Se a pilha p estiver vazia, devolve 1; caso contrário, devolve 0 */
    return p.topo < 0;
} /* fim pilhaVazia */

int conexo(GRAFO G) {
    /* Recebe um grafo G com n vértices, representado através de um LA. Se o grafo for conexo, devolve 1; se for desconexo, devolve 0; se faltar memória, devolve 2 */
    int i = 1, u, *visitado;
    PILHA p;
    NO *aux;
    
    if (G.vertice == NULL) { /* grafo vazio */
        return 1;
    }
    visitado = calloc(G.numVertices, sizeof(int));
    if (visitado == NULL || criaPilha(&p, G.numVertices) == -1) { /* falta de memória */
        return 2;
    }
    visitado[0] = 1;
    empilha(&p, 0);
    while (pilhaVazia(p) == 0) {
        u = desempilha(&p);
        aux = G.vertice[u];
        while (aux != NULL) {
            if (visitado[aux->vertice] == 0) {
                visitado[aux->vertice] = 1;
                empilha(&p, aux->vertice);
                i++;
            }
            aux = aux->proximo;
        }
    }
    return i == G.numVertices;
} /* fim conexo */

void destroiGrafo(GRAFO *G) {
    
}

int criaGrafo(GRAFO *G, int n, int m) {
    /* Se houver memória disponível, cria um grafo com n vértices e m arestas e devolve 0; caso contrário, devolve -1. As arestas são informadas pelo usuário através do dispositivo padrão de entrada. O grafo é representado através de uma lista de adjacências */
    int i, u, v;
    NO *aux1, *aux2;
    
    G->numVertices = n;
    if (n == 0) { /* grafo vazio */
        G->vertice = NULL;
        return 0;
    }
    G->vertice = calloc(n, sizeof(NO *));
    if (G->vertice == NULL) { /* falta de memória */
        return -1;
    }
    printf("Criando um grafo com %d vértices e %d arestas\n", n, m);
    printf("Para cada aresta, digite os vértices conectados por essa aresta separados por espaço em branco\n");
    for (i = 1; i <= m; i++) { /* lendo as arestas do grafo */
        printf("Aresta %d: ", i);
        scanf("%d %d", &u, &v);
        aux1 = malloc(sizeof(NO));
        if (aux1 == NULL) { /* falta de memória */
            destroiGrafo(G);
            return -1;
        }
        aux2 = malloc(sizeof(NO));
        if (aux2 == NULL) { /* falta de memória */
            free(aux1);
            destroiGrafo(G);
            return -1;
        }
        aux1->vertice = v - 1;
        aux1->proximo = G->vertice[u - 1];
        G->vertice[u - 1] = aux1;
        aux2->vertice = u - 1;
        aux2->proximo = G->vertice[v - 1];
        G->vertice[v - 1] = aux2;
    }
    return 0;
} /* fim criaGrafo */

int main() {
    int n, m, i;
    GRAFO G;
    
    printf("Quantidade de vértices: ");
    scanf("%d", &n);
    printf("Quantidade de arestas: ");
    scanf("%d", &m);
    if (criaGrafo(&G, n, m) == -1) { /* falta de memória */
        return 1;
    }
    printf("Grafo %s\n", conexo(G) ? "conexo" : "desconexo");
    return 0;
} /* fim main */
