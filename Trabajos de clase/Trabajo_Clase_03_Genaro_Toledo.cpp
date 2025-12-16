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
#include <time.h>

const int PLANOS = 10;
const int FILAS = 99;
const int COLUMNAS = 99;

int EnteroAleatorio(int minimo, int maximo) 
{	
	int numero = 0;
	
	numero = minimo + rand() % (maximo + 1 - minimo);
	
	return numero;
}

void cargaMatriz(int f01_matriz[PLANOS][FILAS][COLUMNAS], int f01_p, int f01_f, int f01_c)
{
	for (int k=0; k<f01_p; k++)
	{
		for (int i=0; i<f01_f; i++)
		{
			for (int j=0; j<f01_c; j++)
			{
				f01_matriz[k][i][j]	= EnteroAleatorio(1, 9);
			}	
		}	
	}	
}

void mostrarMatriz(int f02_matriz[PLANOS][FILAS][COLUMNAS], int f02_p, int f02_f, int f02_c)
{
	printf("\n\n");
	for (int k=0; k<f02_p; k++)
	{
		printf("HOTEL [%d]\n\n", k);
		for (int i=0; i<f02_f; i++)
		{
			for (int j=0; j<f02_c; j++)
			{
				printf("%d ", f02_matriz[k][i][j]);
			}
			
			printf("\n");	
		}
		
		printf("\n");	
	}
}	

int calculoPersonasAlojadas(int f03_matriz[PLANOS][FILAS][COLUMNAS], int f03_p, int f03_f, int f03_c)
{
	printf("\n");
	
	int suma = 0;
	int total = 0;
		
	for (int k=0; k<f03_p; k++)
	{	 	
		suma = 0;
		for (int i=0; i<f03_f; i++)
		{
			for (int j=0; j<f03_c; j++)
			{
				suma = suma + f03_matriz[k][i][j];	
			}	
		}
		
		
		printf("Cantidad de personas del hotel [%d]: %d", k, suma);
		printf("\n");	
		
		total = total + suma;
	}
	
	return total;
}

main()
{
	system("color 0F");
	srand(time(NULL));
	
	int p = 0; // planos
	int f = 0; // filas
	int c = 0; // columnas
	int cantidadPersonas = 0;
	
	printf("INGRESE CANTIDAD DE HOTELES: ");
	scanf("%d", & p);
	printf("INGRESE CANTIDAD DE PISOS: ");
	scanf("%d", & f);
	printf("INGRESE CANTIDAD DE HABITACIONES: ");
	scanf("%d", & c);
	
	int matriz[PLANOS][FILAS][COLUMNAS];
	
	cargaMatriz(matriz, p, f, c);
	mostrarMatriz(matriz, p, f, c);

	cantidadPersonas = calculoPersonasAlojadas(matriz, p, f, c);
	printf("Cantidad total de personas alojadas: %d", cantidadPersonas);	
	
	printf("\n\n");
	system("pause");
}
