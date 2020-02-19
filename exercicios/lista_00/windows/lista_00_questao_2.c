#include <stdio.h>

int main()
{
    int a[5][3];
    int b[5][3];
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            scanf("%d", &b[i][j]);
        }
    }
    int c[2][15];
    for(int i = 0; i < 15; i++)
    {
        c[0][i] = a[i/3][i%3];
        c[1][i] = b[i/3][i%3];
    }
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 15; j++)
        {
            printf("%d ", c[i][j]);
        }
    }
}

