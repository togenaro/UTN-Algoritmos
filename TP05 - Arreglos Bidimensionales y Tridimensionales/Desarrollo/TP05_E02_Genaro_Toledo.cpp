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

#include <stdio.h>
#include <stdlib.h>

const int FILAS = 10;
const int COLUMNAS = 10;

void cargarMatriz(int f01_matriz[FILAS][COLUMNAS], int f01_M, int f01_N)
{
	
	int valor = 0;
	
	for(int i=0; i<f01_M; i++)
	{
		for(int j=0; j<f01_N; j++)
		{
			do
			{
				system("cls");
				printf("INGRESE SUBINDICE [%d][%d]: ", i, j);
				scanf("%d", & valor);
			
				f01_matriz[i][j] = valor;
				if (valor <= 0)
				{
					system("cls");
					printf("El valor es incorrecto. Ingrese nuevamente.");
					printf("\n\n");
					system("pause");
				}
			}
			while(valor <= 0);
		}
	}
	
}

void mostrarMatriz(int f02_matriz[FILAS][COLUMNAS], int f02_M, int f02_N)
{
	system("cls");
	printf("---VALORES INGRESADOS---");
	printf("\n\n");
	
	for(int i=0; i<f02_M; i++)
	{
		for(int j=0; j<f02_N; j++)
		{
			printf("  %d", f02_matriz[i][j]);
		}
		
		printf("\n\n");
	}
	
	system("pause");
}

void cambiarElemento(int f03_matriz[FILAS][COLUMNAS])
{
	int i = 0;
	int j = 0;
	
	printf("\n\n");
	printf("---CAMBIAR SUBINDICE---");
	printf("\n\n");
	
	printf("INGRESE LA FILA DEL SUBINDICE: ");
	scanf("%d", & i);
	printf("INGRESE LA COLUMNA DEL SUBINDICE: ");
	scanf("%d", & j);
	
	
	f03_matriz[i][j] = 0;
}

void mostrarMatriz2(int f0n_matriz[FILAS][COLUMNAS], int f0n_M, int f0n_N)
{
	system("cls");
	printf("---CAMBIO DEL ELEMENTO---");
	printf("\n\n");
	
	for(int i=0; i<f0n_M; i++)
	{
		for(int j=0; j<f0n_N; j++)
		{
			printf("  %d", f0n_matriz[i][j]);
		}
		
		printf("\n\n");
	}
	
	system("pause");
}

void mostrarFila(int f04_matriz[FILAS][COLUMNAS], int f04_N, int f04_M)
{
	int buscarFila = 0;
	printf("\n\n");
	printf("---ELEMENTOS DE UNA FILA---");
	printf("\n\n");
	printf("INGRESE LA FILA A ANALIZAR: ");
	scanf("%d", & buscarFila);
	printf("\n");
	printf("Los elementos de la fila[%d] son: ", buscarFila);
	
	for(int j=0; j<f04_N; j++)
	{
		printf("%d ", f04_matriz[buscarFila][j]);
	}
	
	printf("\n\n\n");
}

void mostrarColumna(int f05_matriz[FILAS][COLUMNAS], int f05_M, int f05_N)
{
	
	int buscarColumna = 0;
	
	printf("---ELEMENTOS DE UNA COLUMNA---");
	printf("\n\n");
	printf("INGRESE LA COLUMNA A ANALIZAR: ");
	scanf("%d", & buscarColumna);
	printf("\n");
	printf("Los elementos de la columna[%d] son: ", buscarColumna);
	
	for(int i=0; i<f05_M; i++)
	{
		printf("%d ", f05_matriz[i][buscarColumna]);
	}
	
	printf("\n\n");
	system("pause");
	
}

main()
{
	system("color 0F");
	
	int matriz[FILAS][COLUMNAS];
	int M = 0;
	int N = 0;
	
	printf("INGRESE LA CANTIDAD DE FILAS: ");
	scanf("%d", & M);
	printf("INGRESE LA CANTIDAD DE COLUMNAS: ");
	scanf("%d", & N);
	
	cargarMatriz(matriz, M, N);
	mostrarMatriz(matriz, M, N);
	
	cambiarElemento(matriz);
	mostrarMatriz2(matriz, M, N);

	mostrarFila(matriz, N, M);	
	mostrarColumna(matriz, M, N);	
}
