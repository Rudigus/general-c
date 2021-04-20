#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int nota;
    struct fila *proximo;
} fila;

fila* inicializarFila() {
    fila *f = (fila*) malloc(sizeof(fila));
    f->nota = -1;
    f->proximo = NULL;
    return f;
}

void enfila(fila** fim, int notaAluno)
{
    fila *f = inicializarFila();
    f->nota = notaAluno;
    f->proximo = *fim;
    *fim = f;
}

void enfilaOrdenado(fila** fim, int notaAluno)
{
    fila *f = inicializarFila();
    f->nota = notaAluno;
    fila *aux = *fim;
    while(aux->proximo != NULL && notaAluno > aux->proximo->nota)
    {
        aux = aux->proximo;
    }
    f->proximo = aux->proximo;
    aux->proximo = f;
}

//void printarFila(fila* fim)
//{
//    while(fim != NULL)
//    {
//        if(fim->nota != -1)
//        {
//            printf("%d ", fim->nota);
//        }
//        fim = fim->proximo;
//    }
//    printf("\n");
//}

// Exemplo: 50 40 30 20
// filaChegada = 20, 30, 40, 50, -1
// filaNota = -1, 20, 30, 40, 50
int calcularEstudantesMesmoLugar(fila* filaChegada, fila* filaNota) {
    int estudantesMesmoLugar = 0;
    while(filaNota->proximo != NULL)
    {
        //printf("Notas comparadas: %d, %d\n", filaChegada->nota, filaNota->proximo->nota);
        if(filaChegada->nota == filaNota->proximo->nota)
        {
            estudantesMesmoLugar++;
        }
        filaChegada = filaChegada->proximo;
        filaNota = filaNota->proximo;
    }
    return estudantesMesmoLugar;
}

int main()
{
    int numeroCasos;
    scanf("%d", &numeroCasos);
    for(int i = 0; i < numeroCasos; i++)
    {
        fila* filaChegada = inicializarFila();
        fila* filaNota = inicializarFila();
        int numeroAlunos;
        scanf("%d", &numeroAlunos);
        for(int j = 0; j < numeroAlunos; j++)
        {
            int notaAluno;
            scanf(" %d", &notaAluno);
            enfila(&filaChegada, notaAluno);
            enfilaOrdenado(&filaNota, notaAluno);
        }
        //printarFila(filaChegada);
        //printarFila(filaNota);
        printf("%d\n", calcularEstudantesMesmoLugar(filaChegada, filaNota));
    }
}
