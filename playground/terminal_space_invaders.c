#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <windows.h>
#include <time.h>

// Local das Variáveis Globais 1
int vertical = 20, horizontal = 1, i, j, verticalTiro = 0, horizontalTiro, verticalNave = 0;
int verticalAtualInimigo = 0, horizontalAtualInimigo, pontuacao = 0, quantInimigos = 4;
char input, novaLinha[] = "                                                                                                                        ";
bool tiro = false, desenho = true, abate = false, sentidoDireita = true;
clock_t tempoInicial[3] = {0, 0, 0}, tempoFinal[3];
double tempoRedesenhar = 0.1, velocidadeTiro = 0.1, velocidadeInimigo = 0.5, tempoPercorrido[3];

// O inimigo do jogo
struct Inimigo
{
    char forma[20];
    int vertical, horizontal;
    bool abatido;
};

// Local das Variáveis Globais 2
struct Inimigo inimigo[] = {
    {"\\-|-/", 1, 0, false}, {"\\-|-/", 1, 5, false}, {"\\-|-/", 1, 10, false}, {"\\-|-/", 1, 15, false}
};

// Recebe o input do usuário
void pegarInput()
{
    if(kbhit())
    {
        input = getch();
    }
    else
    {
        input = '\0';
    }
    if(input == 'w')
    {
        if(!tiro)
        {
            tiro = true;
            verticalTiro = vertical - 1;
            horizontalTiro = horizontal;
        }
    }
    if(input == 'a')
    {
        if(horizontal > 1)
        {
            horizontal--;
        }
    }
    else if(input == 'd')
    {
        if(horizontal < 57)
        {
            horizontal++;
        }
    }
}

void limparTela()
{
    //system("cls");
    COORD coord;
    coord.X = 0;
    coord.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    for(i = 0; i < 23; i++)
    {
        printf("%s", novaLinha);
    }
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Renderização
void desenhar()
{
    if(desenho)
    {
        limparTela();
        for(i = 0; i < quantInimigos; i++)
        {
            for(j = 0; j < inimigo[i].vertical - verticalAtualInimigo; j++)
            {
                printf("\n");
            }
            for(j = 0; j < inimigo[i].horizontal - horizontalAtualInimigo; j++)
            {
                printf(" ");
            }
            if(!inimigo[i].abatido)
            {
                printf("%s", inimigo[i].forma);
            }
            else
            {
                printf("     ");
            }
            verticalAtualInimigo = inimigo[i].vertical;
            horizontalAtualInimigo = inimigo[i].horizontal;
        }
        verticalAtualInimigo = 0;
        horizontalAtualInimigo = 0;
        if(tiro == true)
        {
            verticalNave = vertical - verticalTiro;
            for(i = 0; i < verticalTiro; i++)
            {
                printf("\n");
            }
            printf("  ");
            for(i = 0; i < horizontalTiro; i++)
            {
                printf("  ");
            }
            printf("|");
        }
        else
        {
            verticalNave = vertical;
        }
        for(i = 0; i < verticalNave; i++)
        {
            printf("\n");
        }
        for(i = 0; i < horizontal; i++)
        {
            printf("  ");
        }
        printf("__|__");
        printf("\n\n Pontuacao: %d", pontuacao);
        printf("\n\n Tamanho da janela e tamanho do buffer de tela recomendados: 120 x 30\n"
               " Horizontal: %d, Vertical: %d, HorizontalTiro: %d, VerticalTiro: %d ", horizontal, vertical, horizontalTiro, verticalTiro);
        desenho = false;
    }
    else
    {
        tempoFinal[0] = clock();
        tempoPercorrido[0] = (double) (tempoFinal[0] - tempoInicial[0]) / CLOCKS_PER_SEC;
        if(tempoPercorrido[0] > tempoRedesenhar)
        {
            desenho = true;
            tempoInicial[0] = tempoFinal[0];
        }
    }
}

// Mecanismo de tiro
void atirar()
{
    tempoFinal[1] = clock();
    tempoPercorrido[1] = (double) (tempoFinal[1] - tempoInicial[1]) / CLOCKS_PER_SEC;
    if(tempoPercorrido[1] > velocidadeTiro)
    {
        verticalTiro--;
        tempoInicial[1] = tempoFinal[1];
    }
    if(verticalTiro < 0 || verticalTiro < inimigo[1].vertical)
    {
        verticalTiro = 0;
        horizontalTiro = 0;
        tiro = false;
    }
}

void abateInimigo()
{
    for(i = 0; i < quantInimigos; i++)
    {
        if(!inimigo[i].abatido && inimigo[i].vertical == verticalTiro &&
           (inimigo[i].horizontal <= horizontalTiro + 1 && inimigo[i].horizontal >= horizontalTiro - 1))
        {
            inimigo[i].abatido = true;
            abate = true;
        }
    }
    if(abate)
    {
        verticalTiro = 0;
        horizontalTiro = 0;
        tiro = false;
        pontuacao += 10;
    }
    abate = false;
}

void movimentoInimigo()
{
    tempoFinal[2] = clock();
    tempoPercorrido[2] = (double) (tempoFinal[2] - tempoInicial[2]) / CLOCKS_PER_SEC;
    if(tempoPercorrido[2] > velocidadeTiro)
    {
        tempoInicial[2] = tempoFinal[2];
        for(i = 0; i < quantInimigos; i++)
        {
            if(inimigo[quantInimigos - 1].horizontal >= 57 && sentidoDireita)
            {
                sentidoDireita = false;
                inimigo[i].vertical++;
            }
            else if(inimigo[0].horizontal <= 0 && !sentidoDireita)
            {
                sentidoDireita = true;
                inimigo[i].vertical++;
            }
            if(sentidoDireita)
            {
                inimigo[i].horizontal++;
            }
            else
            {
                inimigo[i].horizontal--;
            }
        }
    }
}

int main()
{
    // Início
    for(i = 0; i < vertical; i++)
    {
        printf("\n");
    }
    printf(" __|__");

    // Loop principal
    while(true)
    {
        // Recebe o input do usuário
        pegarInput();
        // Mecanismo de tiro
        if(tiro == true)
        {
            atirar();
        }
        // Trata dos acertos nos inimigos
        abateInimigo();
        movimentoInimigo();
        // Renderização
        desenhar();
    }

    return 0;
}
