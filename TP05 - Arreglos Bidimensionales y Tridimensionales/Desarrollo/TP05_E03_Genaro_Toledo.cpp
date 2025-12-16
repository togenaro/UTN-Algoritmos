/*
Universidad Tecnológica Nacional
Facultad Regional Tucumán
Ingeniería en Sistemas de Información

Algoritmos y Estructuras de Datos

Integrantes:
            
            44030752 - Toledo, Genaro	
        	44479000 - Tula, Esteban
        	44703749 - Sánchez, Lautaro Valentín
        	44920917 - Sánchez, Aldana
        	44637714 - Saavedra, Mariana
        	44814073 - Soria, Julián
*/        

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int FILAS = 10;
const int COLUMNAS = 10;
const int N = 3;

int EnteroAleatorio(int minimo, int maximo) 
{	
	int numero = 0;
	
	numero = minimo + rand() % (maximo + 1 - minimo);
	
	return numero;
}

void cargaMatriz(int f01_matriz[FILAS][COLUMNAS], int f01_M, int f01_N)
{
	for (int i=0; i<f01_M; i++)
	{
		for (int j=0; j<f01_N; j++)
		{
			f01_matriz[i][j] = EnteroAleatorio(1, 99);
		}
	}
	
}

void mostrarMatriz(int f02_matriz[FILAS][COLUMNAS], int f02_M, int f02_N)
{
	system("cls");
	printf("MATRIZ GENERADA: ");
	printf("\n\n");
	
	for (int i=0; i<f02_M; i++)
	{
		printf("  |");
		for (int j=0; j<f02_N; j++)
		{
			printf("   %.2d", f02_matriz[i][j]);
		}
		printf("  |");
		printf("\n\n");
	}
	
	system("pause");
}

void mayorProduccion(int f03_matriz[FILAS][COLUMNAS], int f03_M, int f03_N)
{
	
	int maximo = -99999;
	int taller = 0;
	
	for (int j=0; j<f03_N; j++)
	{	
		int sumaColumna = 0;
		
		for (int i=0; i<f03_M; i++)
		{
			sumaColumna = sumaColumna + f03_matriz[i][j]; // Sumar columnas y acumular en sumaColumna
			
			if (sumaColumna > maximo)
			{
				maximo = sumaColumna;
				taller = j; // Taller con mayor producción	
			}
		}
		
	}
	
	printf("\n\n");
	printf("El taller con mayor produccion es el taller: [%d]", taller);
	printf("\n\nLa cantidad de prendas que producio es de: %d", maximo);
	
	printf("\n\n\n");
	system("pause");
}

main()
{
	system("color 0F");
	srand(time(NULL));
	
	int matriz[FILAS][COLUMNAS];
	int M = 0;

	printf("INGRESE LA CANTIDAD DE TALLERES: ");
	scanf("%d", & M);

	cargaMatriz(matriz, M, N);
	mostrarMatriz(matriz, M, N);
	mayorProduccion(matriz, M, N);	
}
