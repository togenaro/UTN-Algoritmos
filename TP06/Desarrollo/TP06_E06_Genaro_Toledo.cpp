#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cadenaInvertida(int f01_longitud, char *cad)
{
	printf("\n");
	for(int i=(f01_longitud - 1); i>=0; i--)
	{
		printf("%c", cad[i]);
	}
	
	printf("\n\n");
	system("pause");
}

main()
{
	system("color F0");
	
	int longitud = 0;
	char cad[121];
	
	printf("INGRESE CADENA: ");
	gets(cad);
	
	longitud = strlen(cad);
	cadenaInvertida(longitud, cad);
}
