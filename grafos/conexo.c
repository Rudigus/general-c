#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
    int vertice;
    struct NO *proximo;
} NO;

typedef struct {
    int vetor[], tamanho, topo;
} PILHA;

typedef NO** GRAFO;

int criaPilha(PILHA p, int n) {
    /* Se houver memória disponível, cria uma pilha de vértices com n posições e devolve 0; caso contrário, devolve -1 */
    p.vetor = malloc(sizeof(int) * n);
    if (p.vetor == NULL) { /* falta de memória */
        return -1;
    }
    p.topo = -1;
    p.tamanho = n;
    return 0;
}

int empilha(PILHA p, int e) {
    /* Se houver espaço disponível, empilha o elemento e na pilha p e devolve 0; caso contrário, devolve -1 */
    if (p.topo < p.tamanho - 1) {
        p.topo++;
        p.vetor[p.topo] = e
        return 0;
    } else { /* overflow */
        return -1;
    }
}

int desempilha(PILHA p) {
    /* Se a pilha p não estiver vazia, remove e devolve o elemento no topo da pilha; caso contrário, devolve -1 */
    if (p.topo > -1) {
        p.topo--;
        return p.vetor[p.topo];
    } else { /* underflow */
        return -1;
    }
}

int pilhaVazia(PILHA p) {
    /* Se a pilha p estiver vazia, devolve 1; caso contrário, devolve 0 */
    return p.topo < 0;
}

int conexo(GRAFO G, int n) {
    /* Recebe um grafo G com n vértices, representado através de um LA. Se o grafo for conexo, devolve 1; se for desconexo, devolve 0; se faltar memória, devolve 2 */
    int i = 1, u, *visitado;
    PILHA p;
    NO *aux;
    
    if (G == NULL) { /* grafo vazio */
        return 1;
    }
    visitado = calloc(n, sizeof(int));
    criaPilha(&p, n);
    if (visitado == NULL || criaPilha(p, n) == -1) { /* falta de memória */
        return 2;
    }
    visitado[0] = 1;
    empilha(p, 0);
    while (pilhaVazia(p) == 0) {
        u = desempilha(p);
        aux = G[u];
        while (aux != NULL) {
            if (visitado[aux->vertice] == 0) {
                visitado[aux->vertice] = 1;
                empilha(p, aux->vertice);
                i++;
            }
            aux = aux->proximo;
        }
    }
    return i == n;
}

int main() {
    int n, m, i;
    GRAFO G;
    
    printf("Quantidade de vértices: ");
    scanf("%d", &n);
    printf("Quantidade de arestas: ");
    scanf("%d", &m);
    G = criaGrafo(n, m);
    if (G == NULL) { /* falta de memória */
        return 1;
    }
    printf("Grafo %s\n", conexo(G) ? "conexo" : "desconexo");
    return 0;
} /* fim main*/
