#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int n, canos[1010];

int max(int a, int b)
{
    if(a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int maiorValor(int ind, int tamCano, int valor)
{
    if(ind == n)
    {
        return 0;
    }
    int usa = maiorValor(ind + 1, tamCano - canos[ind][0], valor + canos[ind][1]);
    int naoUsa = 0;
    if(canos[ind][0] > tamCano)
    {
        naoUsa = maiorValor(ind + 1, tamCano, valor);
    }
    max(usa, naoUsa);
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    int t, ci, vi, i; // n - número de tamanhos de cano diferentes. t - tamanho inicial do cano a ser cortado (capacidade)
    // Número de tamanhos de cano diferentes - n e Tamanho do cano a ser cortado - t
    scanf("%d %d", &n, &t);
    int canos[n][2];
    for(i = 0; i < n; i++)
    {
        // Tamanho de cano i - [0] e Preço de venda do cano i - [1]
        scanf("%d %d", &canos[i][0], &canos[i][1]);
    }
    printf("%d", maiorValor(0, t, 0));
    return 0;
}
