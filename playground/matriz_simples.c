#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "portuguese");
    int i, j, numeroLinha, numeroColuna, contDigitos, ultimoValor;
    printf("Informe o número de linhas da matriz: ");
    scanf("%d", &numeroLinha);
    printf("Informe o número de colunas da matriz: ");
    scanf("%d", &numeroColuna);
    ultimoValor = numeroLinha * numeroColuna - 1;
    int matriz[numeroLinha][numeroColuna];
    printf("\nMatriz Normal\n\n");
    for(i = 0; i < numeroLinha; i++){
        for(j = 0; j < numeroColuna; j++){
            matriz[i][j] = j + (i * numeroColuna);
            printf("%d", matriz[i][j]);
            for(contDigitos = 0; contDigitos < NumeroDigitos(ultimoValor) - NumeroDigitos(matriz[i][j]) + 1; contDigitos++)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    printf("\nMatriz Transposta\n\n");
    for(i = 0; i < numeroLinha; i++){
        for(j = 0; j < numeroColuna; j++){
            matriz[i][j] = i + (j * numeroColuna);
            printf("%d", matriz[i][j]);
            for(contDigitos = 0; contDigitos < NumeroDigitos(ultimoValor) - NumeroDigitos(matriz[i][j]) + 1; contDigitos++)
            {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

int NumeroDigitos(int numero)
{
    int numeroDigitos = 0;
    float numeroDado = numero;
    do{
        numeroDado /= 10;
        numeroDigitos++;
    }
    while(numeroDado >= 1);
    return numeroDigitos;
}
