/*
Universidad Tecnológica Nacional
Facultad Regional Tucumán
Ingeniería en Sistemas de Información

Algoritmos y Estructuras de Datos

Integrantes:
            
            44030752 - Toledo, Genaro
            44367714 - Saavedra, Mariana	
            44920917 - Sánchez, Aldana			
            44479000 - Tula, Esteban
            44703749 - Sánchez, Lautaro
            44814073 - Soria, Julián
*/        

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

const int FILAS = 10;
const int COLUMNAS = 10;

int numeroAleatorio(int minimo, int maximo)
{
	int numero = 0;
	
	numero = minimo + rand() % (maximo + 1 - minimo);
	
	return numero;
	
}

void cargaAleatoriaMatriz(int f01_matriz[FILAS][COLUMNAS], int f01_f, int f01_c)
{
	for (int i=0; i<f01_f; i++)
	{
		for (int j=0; j<f01_c; j++)
		{
			f01_matriz[i][j] = numeroAleatorio(10, 99);
		}
	}
}

void mostrarMatriz(int f02_matriz[FILAS][COLUMNAS], int f02_f, int f02_c)
{
	printf("\n");
	printf("MATRIZ GENERADA:");
	printf("\n\n");
	
	for (int i=0; i<f02_f; i++)
	{
		for (int j=0; j<f02_c; j++)
		{
			printf("%d ", f02_matriz[i][j]);
		}
		printf("\n");
	}
	
	printf("\n");
	system("pause");
	
}

void traspuesta(int f03_matriz[FILAS][COLUMNAS], int f03_traspuesta[FILAS][COLUMNAS], int f03_f, int f03_c)
{
	for (int i=0; i<f03_f; i++)
	{
		for (int j=0; j<f03_c; j++)
		{
			f03_traspuesta[j][i] = f03_matriz[i][j];
		}	
	}
}

void mostrarTraspuesta(int f04_traspuesta[FILAS][COLUMNAS], int f04_f, int f04_c)
{
	printf("\n");
	printf("MATRIZ TRASPUESTA:");
	printf("\n\n");
	
	for (int j=0; j<f04_c; j++)
	{
		for (int i=0; i<f04_f; i++)
		{
			printf("%d ", f04_traspuesta[j][i]);
		}
		printf("\n");	
	}
	
	printf("\n");
	system("pause");
}

main()
{
	system("color 0F");
	
	srand(time(NULL));
	
	int f = 0; // filas
	int c = 0; // columnas
	
	printf("INGRESE CANTIDAD DE FILAS: ");
	scanf("%d", & f);
	printf("INGRESE CANTIDAD DE COLUMNAS: ");
	scanf("%d", & c);
	
	int matriz[FILAS][COLUMNAS];
	int matrizT[FILAS][COLUMNAS];
	
	cargaAleatoriaMatriz(matriz, f, c);
	mostrarMatriz(matriz, f, c);
	
	traspuesta(matriz, matrizT, f, c);
	mostrarTraspuesta(matrizT, f, c);
}
