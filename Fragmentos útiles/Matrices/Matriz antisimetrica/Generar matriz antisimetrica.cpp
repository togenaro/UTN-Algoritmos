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
			printf("%d   ", f02_matriz[i][j]);
		}
		
		printf("\n");
	}
}


main()
{	
	int M = 0;
	
	printf("INGRESE ORDEN DE MATRIZ: ");
	scanf("%d", & M);
	
	int matriz[FILAS][COLUMNAS];
	
	antisimetrica(matriz, M);
	mostrarMatriz(matriz, M);
	
	printf("\n\n");
	system("pause");
}
