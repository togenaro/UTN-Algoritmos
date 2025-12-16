#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char cadena[100];

void cargaDatos(cadena *nombre, int f01_N)
{
	system("cls");
	for(int i=0; i<f01_N; i++)
	{
		printf("APELLIDO Y NOMBRE(socio %d): ", i+1);
		_flushall();
		gets(nombre[i]);	
	}
	
	printf("\n");
	system("pause");
}

void ordenamientoDescreciente(cadena *nombre, int f02_N)
{
	bool bandera;
	cadena aux;
	
	do
	{
		bandera = false;
		
		for (int i=0; i<f02_N-1; i++)
		{
			if ( strcmp(nombre[i], nombre[i+1]) < 0 )
			{
				strcpy(aux, nombre[i]);
				strcpy(nombre[i], nombre[i+1]);
				strcpy(nombre[i+1], aux);
				bandera = true;
			}
		}
	}
	while (bandera == true);
}

void listarPersonas(cadena *nombre, int f03_N)
{
	printf("\n");
	printf("VECTOR ORDENADO (DECRECIENTE): ");
	printf("\n\n");
	for (int i=0; i<f03_N; i++)
	{
		puts(nombre[i]);
	}
	
	printf("\n\n");
	system("pause");
}

void ordenamientoCreciente(cadena *nombre, int f04_N)
{
	bool bandera;
	cadena aux;
	
	do
	{
		bandera = false;
		
		for (int i=0; i<f04_N-1; i++)
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
	
	printf("\n");
	printf("VECTOR ORDENADO (CRECIENTE): ");
	printf("\n\n");
	for (int i=0; i<f04_N; i++)
	{
		puts(nombre[i]);
	}
	
	printf("\n\n");
	system("pause");
	
}

void buscarCadena(cadena *nombre, int f05_N)
{
	cadena busqueda;
	int contadorApellido = 0;
	int bandera = 0;
	
	system("cls");
	printf("INGRESE EL APELLIDO: ");
	_flushall();
	gets(busqueda);
	
	for(int i=0; i<f05_N; i++)
	{	
		bandera = strstr(nombre[i], busqueda) - nombre[i];
		
		if(bandera >= 0)
		{
			contadorApellido++;
		}
	}
	
	if(bandera < 0)
	{
		printf("No se encontro el apellido ingresado.");
	}
	else if (bandera >= 0);
	{
		printf("\nSe encontro el apellido: ");
		puts(busqueda);
		printf("Cantidad de veces que aparece: %d", contadorApellido);
	}
	
	printf("\n\n");
	system("pause");
}

main()
{
	system("color F0");
	
	int N = 0;
	printf("INGRESE CANTIDAD DE SOCIOS: ");
	scanf("%d", & N);
	cadena nombre[N];
	
	cargaDatos(nombre, N);
	ordenamientoDescreciente(nombre, N);
	listarPersonas(nombre, N);
	ordenamientoCreciente(nombre, N);
	buscarCadena(nombre, N);
}

