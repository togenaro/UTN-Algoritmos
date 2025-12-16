#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef char string[80];

main()
{
	string frase = {NULL};
	int longitud = 0;
	
	
	gets(frase);
	longitud = strlen(frase);
	
	printf("MOSTRANDO FRASE 1ra VEZ: ");
	
	printf("%s", frase);
	
	printf("\n\n");
	system("pause");
	
	
	for(int i=0; i<longitud; i++)
	{
		frase[i] = NULL;
	}
	
	printf("MOSTRANDO FRASE 2da vez: ");
	puts(frase);
	
	printf("\n\n");
	system("pause");
}
