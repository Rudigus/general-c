#include <stdio.h>

int main()
{
    int a[5];
    int b[5];
    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < 5; i++)
    {
        scanf("%d", &b[i]);
    }
    int c[10];
    for(int i = 0; i < 10; i++)
    {
        if(i < 5)
        {
            c[i] = a[i];
        }
        else
        {
            c[i] = b[i - 5];
        }
        printf("%d ", c[i]);
    }
}

