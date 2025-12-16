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

void mostrarCadena(char* cadena)
{	
	int i = 0;
	int tamanio = 0;
	
	while (cadena[i] != '\0')
	{
		i++;
		tamanio++;
	}
	
	printf("\n");
	printf("Palabras ingresadas: \n\n");
	printf(" ");
	
	for (int i=0; i<tamanio; i++)
	{
		if (cadena[i] == ',')
		{
			printf("\n");
		}
		else
		{
			printf("%c", cadena[i]);
		}
	}
		
}

int longitudCadena(char* cadena)
{
	int tamanio = 0;
	int i = 0;
	
	while (cadena[i] != '\0')
	{
		i++;
		tamanio++;
	}
	
	return tamanio;
}

main()
{
	system("color F0");
	
	char cadena[100];
	int longitud = 0;
	
	printf("INGRESE LA CADENA: ");
	gets(cadena);
	
	mostrarCadena(cadena);
	longitud = longitudCadena(cadena);
	
	printf("\n\nLa cadena tiene %d caracter/es");
	
	printf("\n\n");
	system("pause");
}















