#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float CambioMaluco(int moedaPossuida, float valorMoeda, int moedaDesejada)
{
    float cambio[4] = {1, 3.87, 4.36, 0.09};
    valorMoeda *= (float) cambio[moedaPossuida] / (float) cambio[moedaDesejada];
    return valorMoeda;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    int moedaPossuida, moedaDesejada;
    float valorMoeda;
    printf("Informe o tipo de moeda possuída (0 - Real, 1 - Dólar,\n2 - Euro, 3 - Peso Argentino):");
    scanf("%d", &moedaPossuida);
    printf("\nInforme o valor da moeda: ");
    scanf("%f", &valorMoeda);
    printf("\nInforme o tipo de moeda desejada (0 - Real, 1 - Dólar,\n2 - Euro, 3 - Peso Argentino): ");
    scanf("%d", &moedaDesejada);
    printf("\nO valor após a conversão será de %.2f\n", CambioMaluco(moedaPossuida, valorMoeda, moedaDesejada));
    return 0;
}
