#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
	typedef char cadena[100];
	cadena palabra, palabraMayor[50];
	
	int mayor = -99999;
	int centinela = 0;
	int contadorDePalabras = 0;
	
	int i = 0;
	int aux = 0;
	
	do
	{
		printf("PALABRA: ");
		gets(palabra);
		
		strcpy(palabraMayor[i], palabra);
		
		centinela = strcmp(palabra, "final");
		
		
		if (strlen(palabra) > mayor)
		{
			mayor = strlen(palabra);
			aux = i;
		}
		
		if (centinela != 0);
		{
			contadorDePalabras++;
		}
		
		i++;
		
	}
	while (centinela != 0);
	
	printf("\n\n");
	printf("La palabra mayor ingresada es: ");
	puts(palabraMayor[aux]);
	
	printf("La cantidad de palabras ingresadas es: %d", contadorDePalabras);
	
	printf("\n\n");
	system("pause");	
	
}
