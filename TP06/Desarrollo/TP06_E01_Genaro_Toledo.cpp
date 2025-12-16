/*
Universidad Tecnológica Nacional
Facultad Regional Tucumán
Ingeniería en Sistemas de Información

Algoritmos y Estructuras de Datos

Integrantes:
            
            44030752 - Genaro Toledo
*/        

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

main()
{
	system("color F0");
	
	typedef char cadena[50];
	cadena palabra[50], palabraMayor[1];
	
	int i = 0;
	int c = 0;
	int mayor = -9999;
	int tamanio = 0;
	bool bandera;
	
	do
	{	
		printf("INGRESE PALABRA [%d]: ", i+1);
		gets(palabra[i]);	
	
		if (strcmp(palabra[i], "final") == 0) 
		{
			bandera = true; // fin do/while
		}
		else if (strcmp(palabra[i], "final") != 0)
		{
			
			tamanio = strlen(palabra[i]);
			if (tamanio > mayor)
			{
				mayor = tamanio;
				strcpy(palabraMayor[c], palabra[i]);
			}
			
			i++;
		}	
	}
	while (bandera != true); 	
	
	printf("\nLa palabra mas larga ingresada es: ");
	puts(palabraMayor[c]);
	
	printf("Se ingreso %d palabra/s", i);
	
	printf("\n\n");
	system("pause");
}
