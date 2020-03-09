#include <stdio.h>
#include <string.h>

int main()
{
	/*char ok[5];
	scanf("%s", ok);
	printf("\nTamanho strlen: %ld", strlen(ok));
	printf("\nTamanho sizeof: %ld\n\n", sizeof(ok));
	*/char outro[2] ="ab";
	/*for(int i = 0; i < 5; i++)
	{
		printf("\n%c pascal ", ok[i]);
	}*/
	printf("\nSTRING: %s\n", outro);
	printf("\nTamanho strlen: %ld", strlen(outro));
	printf("\nTamanho sizeof: %ld\n\n", sizeof(outro));
	printf("%p\n", outro);
	for(int i = 0; i < 5; i++)
	{
		printf("\n%d pascal ", i[outro]);
	}
	//printf("%p\n%p\n", ok, outro);
}
