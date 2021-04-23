#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define EPSILON 0.0000001

/*Se houver memÛria suficiente, aloca uma matriz de double com l linhas e c colunas e devolve
um ponteiro para essa matriz ; caso contr·rio devolve um ponteiro nulo*/
double** alocaMatriz(int l, int c)
{
    double** m;
    int i, j;

    m = malloc(sizeof(double*) * l);

    /*MemÛria insuficiente*/
    if (m == NULL)
    {
        return NULL;
    }
    for (i = 0; i < l; i++) {
        m[i] = malloc(sizeof(double) * c);

        if (m[i] == NULL)
        {
            for (j = 0; j < i; j++)
            {
                free(m[j]);
            }

            free(m);
            return NULL;
        }
    }

    return m;
}

void leMatriz(double **m, int l, int c)
{
    /* LÍ valores para uma matriz de double com l linhas e m colunas alocadas dinamicamente */
    int i, j;
    
    for (i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            printf("M[%d][%d] ", i + 1, j + 1);
            scanf("%lf", &m[i][j]);
        }
    }
}

void imprimeMatriz(double **m, int l, int c)
{
    /* imprime valores para uma matriz de double com l linhas e c colunas alocadas dinamicamente */
    int i, j;
    
    for (i = 0; i < l; i++){
        for(j = 0; j < c; j++){
            printf("%10.3lf  ", m[i][j]);
        }
        printf("\n");
    }
}

/* Recebe m, a matriz aumentada de um SL TS com n vari·veis; se o SL for determinado
armazena em x a soluÁ„o do sistema linear e devolve 0; se for indeterminado, armazena em x
uma soluÁ„o do SL e devolve 1; se for imcompatÌvel, devolve 2; */
int sretro(double **m, int n, double x[])
{
    int i, j, tipo = 0;
    double soma;
    
    for(i = n - 1; i >= 0; i--)
    {
        soma = 0;
        for(j = i + 1; j < n; j++)
        {
            soma = soma + m[i][j] * x[j];
        }
        
        if(m[i][i] == 0)
        {
            if (fabs(m[i][n] - soma) < EPSILON) // x[i] È a vari·vel livre
            {
                x[i] = 0;
                tipo = 1;
            }
            else
            { //Sistema linear imcompatÌvel
                return 2;
            }
        }
        
        else
        {
            x[i] = (m[i][n] - soma) / m[i][i];
        }
    }
    
    return tipo;
}

int main() {
    int i, n, tipo;
    double **m, *x;
    
    printf("Numero de variaveis: ");
    scanf("%d", &n);
    
    m = alocaMatriz(n, n + 1);
    x = malloc(sizeof(double) * n);
    
    if(m == NULL || x == NULL)
    {
        printf("Deu pau!\n Falta de memoria\n");
        return 1;
    }

    leMatriz(m, n, n + 1);
    imprimeMatriz(m, n, n + 1);
    tipo = sretro(m, n, x);

    if(tipo == 2)
        printf("SL incompativel\n");
    else
    {
        printf("SL %sdeterminado\n", tipo? "in" : "");
        for(i = 0; i < n; i++)
        {
            printf("x[%d] = %10.3lf\n", i + 1, x[i]);
        }
    }

    return 0;
}

