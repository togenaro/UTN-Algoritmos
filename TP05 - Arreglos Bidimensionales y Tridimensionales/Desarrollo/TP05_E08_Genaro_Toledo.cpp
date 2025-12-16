/*
Universidad Tecnológica Nacional
Facultad Regional Tucumán
Ingeniería en Sistemas de Información

Algoritmos y Estructuras de Datos

Integrantes:
            
            44030752 - Toledo, Genaro
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int PLANOS = 10;
const int FILAS = 10;
const int COLUMNAS = 10;

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
				f01_matriz[k][i][j] = EnteroAleatorio(10, 99);
			} // columnas
		} // filas
	} // planos
	
}

void mostrarMatriz(int f02_matriz[PLANOS][FILAS][COLUMNAS], int f02_p, int f02_f, int f02_c)
{
	
	for (int k=0; k<f02_p; k++)
	{
		printf("\n");
		printf("PLANO [%d]: ", k);
		printf("\n\n");
		
		for (int i=0; i<f02_f; i++)
		{
			for (int j=0; j<f02_c; j++)
			{
				printf("%d ", f02_matriz[k][i][j]);
			} // columnas
			
			printf("\n");
			
		} // filas		
	} // planos	
	
}

void cargaVector(int* f03_vector, int f03_matriz[PLANOS][FILAS][COLUMNAS],int f03_p, int f03_f, int f03_c)
{
	
	int suma = 0;
	
	for (int k=0; k<f03_p; k++)
	{
		suma = 0;
		
		for (int i=0; i<f03_f; i++)
		{
			for (int j=0; j<f03_c; j++)
			{
				suma = suma + f03_matriz[k][i][j];
			
			} // columnas
		} // filas	
		
		f03_vector[k] = suma; 
	
	} // planos	
	
}

void mostrarVector(int* f04_vector, int f04_p)
{
	printf("\n\n");
	printf("VECTOR: ");
	printf("\n\n");
	
	for (int k=0; k<f04_p; k++)
	{
		printf("SUBINDICE[%d]: %d", k, f04_vector[k]);
		printf("\n");
	}
	
	printf("\n\n");
	system("pause");
	
}

main()
{
	system("color 0F");
	
	srand(time(NULL));
	
	int p = 0; // planos
	int f = 0; // filas
	int c = 0; // columnas
	
	printf("INGRESE CANTIDAD DE PLANOS: ");
	scanf("%d", & p);
	printf("INGRESE CANTIDAD DE FILAS: ");
	scanf("%d", & f);
	printf("INGRESE CANTIDAD DE COLUMNAS: ");
	scanf("%d", & c);
	
	int vector[p]; // el orden del vector será igual a la cantidad de planos ingresados por el usuario.
	int matriz[PLANOS][FILAS][COLUMNAS];
	
	cargaMatriz(matriz, p, f, c);
	mostrarMatriz(matriz, p, f, c);
	
	cargaVector(vector, matriz, p, f, c);
	mostrarVector(vector, p);
			
}
