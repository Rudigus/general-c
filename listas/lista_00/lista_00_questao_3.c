#include <stdio.h>

int main()
{
	int n;
    scanf("%d", &n);
	for(int i = 0; i < 4; i++)
	{
		printf("%d ", n-2+i+i/2);
	}
}

