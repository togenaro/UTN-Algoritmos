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
	typedef char cadena[100];
	cadena nombre[5], aux;
	
	for (int i=0; i<5; i++)
	{
		_flushall();
		printf("INGRESE CADENA [%d]: ", i);
		gets(nombre[i]);
	}
	
	// ORDENAMIENTO -------------------------------------
	
	bool bandera;
	
	do
	{
		bandera = false;
		
		for (int i=0; i<5-1; i++)
		{
			if ( strcmp(nombre[i], nombre[i+1]) > 0 )
			{
				strcpy(aux, nombre[i]);
				strcpy(nombre[i], nombre[i+1]);
				strcpy(nombre[i+1], aux);
				bandera = true;
			}
		}
	}
	while (bandera == true);
	
	// -------------------------------------------------
	
	printf("\n");
	printf("VECTOR ORDENADO: ");
	printf("\n\n");
	for (int i=0; i<5; i++)
	{
		puts(nombre[i]);
	}
	
	
	printf("\n");
	system("pause");

}
