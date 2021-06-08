/*1º Exercício-Programa de Grafos*/

/* Grupo abaixo:                        */
/* Francisco Davi Camilo Ribeiro  */
/* Rodrigo Matos Aguiar           */
/* Leandro Alves Machado          */
/* Victor Bruno Rodrigues Parente */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 150
#define INFINITO 10000

//Função do Algoritmo de Dijkstra conforme solicitado
void algoritmoDijkstra(int vertices, int pontoOrigem, int pontoDestino, int *custo){
    int i = 0;             // Variavel de contador
    int v = 0;        // Variavel de auxilio
  double min;       // Variavel de auxilio
    int ant[MAX];     // Array dos predecessores
    int z[MAX];       // Vertices com o caminho mínimo conhecido
    double dist[MAX]; // Array acumulador de custo dos caminhos
    
  // Inicializar
    for(i = 0; i < vertices; i++){
        if(custo[i] != -1){
            ant[i] = pontoOrigem-1;
            dist[i] = custo[i];
        }
        else{
            ant[i] = -1;
            dist[i] = INFINITO;
        }
        z[i] = 0;
    }
    z[pontoOrigem-1] = 1;
    dist[pontoOrigem-1] = 0;

  // Inserir vertice que já conhecemos o caminho minimo no conjunto z
    while(v != pontoDestino-1 && min != INFINITO){
        min = INFINITO;
        
        for(i = 0; i < vertices; i++){
            if(z[i] == 0){
                if(dist[i] >= 0 && dist[i] < min){
                    min = dist[i];
                    v = i;
                }
            }
        }

    // Distancias dos vizinhos de z
        if(min != INFINITO && v != pontoDestino-1){
            z[v] = 1;
            for(i = 0; i < vertices; i++)
                if(z[i] == 0){
                    if(custo[v*vertices+i] != -1 && dist[v]+custo[v*vertices+i] < dist[i]){
                        dist[i] = dist[v]+custo[v*vertices+i];
                        ant[i] = v;
                    }
                }
        }
  }

  // Imprimindo resultados: Caminho minimo e custo
  if(min == INFINITO)
        printf("\nNão há caminho entre os vértices %d e %d.\n", pontoOrigem, pontoDestino);
    else{
        
        i = pontoDestino;
        i = ant[i-1];
        
    int arr[MAX];
    arr[0] = pontoDestino;
    int j = 1;
    int count = 0;
        while(i !=-1) {
      arr[j] = i+1;
      count++;
      j++;
            i = ant[i];
        }
        printf("\nCaminho mínimo do vértice %d para o vértice %d: ",
           pontoOrigem, pontoDestino);
    
    for(count = count; count > 0; count--){
      printf("(%d, %d) ", arr[count],arr[count-1]);
    }

        printf("\n\nCusto: %d\n", (int)dist[pontoDestino-1]);

        // i = pontoDestino;
        // printf("(%d)", i);
        // i = ant[i-1];
        
        // while(i !=-1) {
        //     printf(" <- (%d)", i+1);
        //     i = ant[i];
        // }
        // printf("\n\nCusto: %d\n", (int)dist[pontoDestino-1]);
    }
}

int main(int argc, char **argv){

  int vertices = 0;       // Quantidade de vertices do grafo
    int arcos    = 0;         // Quantidade de arcos do grafo
    int origem   = 0;     // Vertice de Origem
    int destino  = 0;        // Vertice de Destino
    int u  = 0;              // Vertice de origem de cada arco no grafo
    int v = 0;               // Vertice de detino de cada arco no grafo
    int *custos  = NULL;     // Array de adjacências
    int i = 0;                    // Variavel de auxilio
    int j = 0;                    // Variavel de auxilio

  FILE *arquivo = fopen(argv[1], "r");
    if (arquivo == NULL) {
    printf("Não foi possível ler o arquivo\n");
    printf("Encerrando...\n");
    return 1;
  }
    char caminhoArquivo[100];

  // Faz a leitura do arquivo e armazena os valores nas variaveis
    fscanf(arquivo, "%d %d %d %d", &vertices, &arcos, &origem, &destino);
    
    free(custos);
    
  custos = (int*)malloc(sizeof(int)*vertices*vertices);
    for(i = 0; i <= vertices*vertices; i++)
        custos[i] = -1;

  // Faz a leitura do arquivo da segunda linha em diante e armazena as variaveis
    for(j = 0; j < arcos; j++){
        fscanf(arquivo, "%d %d", &u, &v);
        // Faz o armazenamento dos custos na lista de adjacências
        fscanf(arquivo, "%d", &custos[(u-1)*vertices+v-1]);
    }
    fclose(arquivo);

  algoritmoDijkstra(vertices, origem, destino, custos);

  return 0;
}
