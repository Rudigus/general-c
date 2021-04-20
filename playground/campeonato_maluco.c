#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <windows.h>

// i, j - Contadores.
// nomeTime[][] - Nome dos oito times que participarão do campeonato.
// pontos[] - Pontos de cada time na primeira rodada.
// sem[][0] - Pontos dos times que irão pras semifinais.
// sem[][1] - Índice dos times que irão pras semifinais.
// fin[] - Finalistas.
// campeao - Campeão.
// tempoPausa - Tempo entre certos comandos.
int i, j, pontos[8] = {0, 0, 0, 0, 0, 0, 0, 0}, sem[4][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}}, fin[2], campeao;
int tempoPausa = 1000;
char nomeTime[8][49];

// Função que gere o funcionamento de uma partida e retorna o nome do time que venceu.
int partida(int time1, int time2)
{
    int golsTime1 = rand() % 6;
    int golsTime2 = rand() % 6;
    printf("Resultado do jogo entre %s e %s: %d x %d\n", nomeTime[time1], nomeTime[time2], golsTime1, golsTime2);
    Sleep(tempoPausa);
    if(golsTime1 >= golsTime2)
    {
        return time1;
    }
    else
    {
        return time2;
    }
}

// Função que gere o funcionamento de uma partida e atribui pontos aos times de acordo com os resultados dela.
void jogo(int time1, int time2)
{
    int golsTime1 = rand() % 6;
    int golsTime2 = rand() % 6;
    printf("Resultado do jogo entre %s e %s: %d x %d\n", nomeTime[time1], nomeTime[time2], golsTime1, golsTime2);
    Sleep(tempoPausa);
    if(golsTime1 > golsTime2)
    {
        pontos[time1] += 3;
    }
    else if(golsTime1 < golsTime2)
    {
        pontos[time2] += 3;
    }
    else
    {
        pontos[time1] += 1;
        pontos[time2] += 1;
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    srand(time(NULL));

    // Fornecimento dos nomes dos times que competirão.
    printf("Bloco 1:\n\n");
    for(i = 0; i < 8; i++)
    {
        if(i == 4)
        {
            printf("\nBloco 2:\n\n");
        }
        printf("Informe o nome do %dº time: ", i + 1);
        scanf("%s", nomeTime[i]);
    }

    // Jogos de ida e de volta do Grupo 1
    printf("\nBloco 1:\n\n");
    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 4; j++)
        {
            if(i != j)
            {
                jogo(i, j);
            }
        }
    }

    // Jogos de ida e de volta do Grupo 2
    printf("\nBloco 2:\n\n");
    for(i = 4; i < 8; i++)
    {
        for(j = 4; j < 8; j++)
        {
            if(i != j)
            {
                jogo(i, j);
            }
        }
    }

    // Quadro de pontuação
    printf("\nPontuação dos times do Bloco 1:\n\n");
    for(i = 0; i < 8; i++)
    {
        if(i == 4)
        {
            printf("\nPontuação dos times do Bloco 2:\n\n");
        }
        printf("Time %s - %d pontos\n", nomeTime[i], pontos[i]);
        Sleep(tempoPausa);
    }

    // Checagem de semifinalistas do Grupo 1
    for(i = 0; i < 4; i++)
    {
        if(pontos[i] > sem[0][0])
        {
            sem[1][0] = sem[0][0];
            sem[1][1] = sem[0][1];
            sem[0][0] = pontos[i];
            sem[0][1] = i;
        }
        else if(pontos[i] > sem[1][0])
        {
            sem[1][0] = pontos[i];
            sem[1][1] = i;
        }
    }

    // Checagem de semifinalistas do Grupo 2
    for(i = 4; i < 8; i++)
    {
        if(pontos[i] > sem[2][0])
        {
            sem[3][0] = sem[2][0];
            sem[3][1] = sem[2][1];
            sem[2][0] = pontos[i];
            sem[2][1] = i;
        }
        else if(pontos[i] > sem[3][0])
        {
            sem[3][0] = pontos[i];
            sem[3][1] = i;
        }
    }

    //Listagem dos semifinalistas
    printf("\nSemifinalistas do bloco 1:\n1º Lugar - %s\n2º Lugar - %s", nomeTime[sem[0][1]], nomeTime[sem[1][1]]);
    Sleep(tempoPausa);
    printf("\n\nSemifinalistas do bloco 2:\n1º Lugar - %s\n2º Lugar - %s\n", nomeTime[sem[2][1]], nomeTime[sem[3][1]]);
    Sleep(tempoPausa);

    // Semifinais
    printf("\nSemifinais:\n\n");
    fin[0] = partida(sem[0][1], sem[1][1]);
    fin[1] = partida(sem[2][1], sem[3][1]);

    // Finais
    printf("\nFinais:\n\n");
    campeao = partida(fin[0], fin[1]);
    printf("\nE o grande campeão é... %s!!!!!!!!\n\n", nomeTime[campeao]);
    Sleep(tempoPausa);
    system("pause");

    return 0;
}
