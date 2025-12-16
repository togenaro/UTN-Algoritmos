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

const int FILAS = 100;
const int COLUMNAS = 100;

int EnteroAleatorio(int minimo, int maximo)
{	
	int numero = 0;
	
	numero = minimo + rand() % (maximo + 1 - minimo);
	
	return numero;				
}

void antisimetrica(int f01_matriz[FILAS][COLUMNAS], int f01_M)
{
	
	for (int i=0; i<f01_M; i++)
	{
		for (int j=0; j<f01_M; j++)
		{
			f01_matriz[i][j] = EnteroAleatorio(1, 100);
			f01_matriz[j][i] = f01_matriz[i][j] * -1;	
			
			if (i == j)
			{
				f01_matriz[i][j] = 0;
			}
		}

	}

}

void mostrarMatriz(int f02_matriz[FILAS][COLUMNAS], int f02_M)
{
	printf("\n");
	
	for (int i=0; i<f02_M; i++)
	{
		for (int j=0; j<f02_M; j++)
		{
			printf("\t%d", f02_matriz[i][j]);
		}
		
		printf("\n");
	}
}

int cuadroMatriz(int f03_matriz[FILAS][COLUMNAS], int f03_M, int &f03_sumaj)
{
	
	int f03_sumai = 0;
	f03_sumaj = 0;
	
	for (int i=0; i<f03_M; i++)
	{
		for (int j=0; j<f03_M; j++)
		{
			
			if ((i==0) or (i==f03_M-1))
			{
				f03_sumai = f03_sumai + f03_matriz[i][j];	
			}
			else if ((j==0) or (j==f03_M-1))
			{
				if ( ((i==0)and(j==0)) or ((i==0)and(j==f03_M-1)) or ((i==f03_M-1)and(j==0)) or ((i==f03_M-1)and(j==f03_M-1)) )
				{	
				}
				else
				{
					f03_sumaj = f03_sumaj + f03_matriz[i][j];
				}
			}
				
		}
	}
	
	printf("\nSuma de filas: %d", f03_sumai);
	printf("\nSuma de columnas: %d", f03_sumaj);
	
	return f03_sumai;
	
}

main()
{	
	system("color 0F");
	srand(time(NULL));
	
	int M = 0;
	
	int sumai = 0;
	int sumaj = 0;
	int sumaTotal = 0;
	
	printf("INGRESE ORDEN DE MATRIZ: ");
	scanf("%d", & M);
	
	int matriz[FILAS][COLUMNAS];
	
	antisimetrica(matriz, M);
	mostrarMatriz(matriz, M);
	
	sumai = cuadroMatriz(matriz, M, sumaj);
	sumaTotal = sumai + sumaj;
	
	printf("\n\n");
	printf("SUMA DEL CUADRO DE LA MATRIZ: %d", sumaTotal);
	
	printf("\n\n");
	system("pause");
}
