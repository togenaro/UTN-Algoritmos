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

void cargarMatriz(int f01_matriz[FILAS][COLUMNAS], int f01_M)
{
	
	for (int i=0; i<f01_M; i++)
	{
		for (int j=0; j<f01_M; j++)
		{
			f01_matriz[i][j] = EnteroAleatorio(10, 99);
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
			printf("%d ", f02_matriz[i][j]);
		}
		
		printf("\n");
	}
	
}

void cuadroMatriz(int f03_matriz[FILAS][COLUMNAS], int f03_M)
{
	
	int sumai = 0;
	int sumaj = 0;
	int sumaTotal = 0;
	
	for (int i=0; i<f03_M; i++)
	{
		for (int j=0; j<f03_M; j++)
		{
			
			if ((i==0) or (i==f03_M-1))
			{
				sumai = sumai + f03_matriz[i][j];	
			}
			
			if ((j==0) or (j==f03_M-1))
			{
				if ( ((i==0)and(j==0)) or ((i==0)and(j==f03_M-1)) or ((i==f03_M-1)and(j==0)) or ((i==f03_M-1)and(j==f03_M-1)) )
				{
					
				}
				else
				{
					sumaj = sumaj + f03_matriz[i][j];
				}
			}
				
		}
		
	}
	
	
	sumaTotal = sumai + sumaj;
	
	printf("\nSuma de filas: %d", sumai);
	printf("\nSuma de columnas: %d", sumaj);
	printf("\n\nSuma del cuadro de la matriz: %d", sumaTotal);	

}

main()
{
	srand(time(NULL));
	
	int M = 0;
	
	printf("INGRESE ORDEN DE MATRIZ: ");
	scanf("%d", & M);
	
	int matriz[FILAS][COLUMNAS];
	
	cargarMatriz(matriz, M);
	mostrarMatriz(matriz, M);
	
	cuadroMatriz(matriz, M);
	
	printf("\n\n");
	system("pause");
}
