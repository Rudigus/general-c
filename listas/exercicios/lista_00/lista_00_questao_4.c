#include <stdio.h>

int main()
{
    int a[5][4];
	int b[4][3];
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			scanf("%d", &b[i][j]);
		}
	}
	int c[5][3];
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			c[i][j] = 0;
			for(int k = 0; k < 4; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
			printf("%d ", c[i][j]);
		}
	}
}

