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

const int FILAS = 4;
const int COLUMNAS = 3;

void cargarMatriz(float f01_matriz[FILAS][COLUMNAS])
{
	float valor = 0;
	
	for (int i=0; i<FILAS; i++)
	{
		for (int j=0; j<COLUMNAS; j++)
		{
			printf("INGRESE EL SUBINDICE [%d][%d]: ", i, j);
			scanf("%f", & valor);
			
			f01_matriz[i][j] = valor;
		}
	}
}

float mayorYMenor(float f02_matriz[FILAS][COLUMNAS], float &f02_maximo)
{
	printf("\n\n");
	
	float minimo = 999999;
	f02_maximo = -99999;
	
	for(int i=0; i<FILAS; i++)
	{
		for(int j=0; j<COLUMNAS; j++)
		{
			if (f02_matriz[i][j] < minimo)
			{
				minimo = f02_matriz[i][j];
			}
			
			if (f02_matriz[i][j] > f02_maximo)
			{
				f02_maximo = f02_matriz[i][j];
			}
		}
	}
	
	return minimo;
}

void mostrarMatriz(float f03_matriz[FILAS][COLUMNAS])
{
	printf("\n\n");
	
	for (int i=0; i<FILAS; i++)
	{
		for (int j=0; j<COLUMNAS; j++)
		{
			printf(" - %.2f", f03_matriz[i][j]);
		}
		
		printf(" -");
		printf("\n\n");
	}
	
	printf("\n");
	system("pause");
}

main()
{
	system("color 0F");
	
	float matriz[FILAS][COLUMNAS];
	float maximo = 0; 
	float minimo = 0; 

	cargarMatriz(matriz);
	minimo = mayorYMenor(matriz, maximo); 
	
	system("cls");
	printf("El maximo elemento es: %.2f", maximo); // Por referencia
	printf("\n\n");
	system("pause");
	
	printf("\n");
	printf("El minimo elemento es: %.2f", minimo); // Por retorno de dato de la función
	printf("\n\n");
	system("pause");
	
	mostrarMatriz(matriz);		
}
