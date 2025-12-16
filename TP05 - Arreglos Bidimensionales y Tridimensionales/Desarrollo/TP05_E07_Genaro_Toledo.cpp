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

const int PLANOS = 3;
const int FILAS = 2;
const int COLUMNAS = 4;

int EnteroAleatorio(int minimo, int maximo) 
{	
	int numero = 0;
	
	numero = minimo + rand() % (maximo + 1 - minimo);
	
	return numero;
}	

void cargarMatriz(int f01_matriz[PLANOS][FILAS][COLUMNAS])
{
	
	for (int k=0; k<PLANOS; k++)
	{
		for (int i=0; i<FILAS; i++)
		{
			for (int j=0; j<COLUMNAS; j++)
			{
				f01_matriz[k][i][j] = EnteroAleatorio(10, 99);
			} // columnas
		} // filas
	} // planos
	
}

void mostrarMatriz(int f02_matriz[PLANOS][FILAS][COLUMNAS])
{
	for (int k=0; k<PLANOS; k++)
	{
		printf("PAIS [%d]: ", k);
		printf("\n\n");
		
		for (int i=0; i<FILAS; i++)
		{
			for (int j=0; j<COLUMNAS; j++)
			{
				printf("%d ", f02_matriz[k][i][j]);
			} // columnas
			printf("\n");
		} // filas
		printf("\n");
	} // planos
	
}

int ventaPais(int f03_matriz[PLANOS][FILAS][COLUMNAS])
{
	int f03_mayor = -99999;
	int f03_paisMayor = 0;
	int f03_suma = 0;	
	
	for (int k=0; k<PLANOS; k++)
	{
		f03_suma = 0;
		
		for (int i=0; i<FILAS; i++)
		{
			for (int j=0; j<COLUMNAS; j++)
			{
				f03_suma = f03_suma + f03_matriz[k][j][i];
			} // columnas
			
		} // filas
		
		if (f03_suma > f03_mayor)
		{
			f03_mayor = f03_suma;
			f03_paisMayor = k;
		}	
		
	} // planos
	
	return f03_paisMayor;
}

void sumaPaises(int f04_matriz[PLANOS][FILAS][COLUMNAS])
{
	int suma = 0;
	
	for (int k=0; k<PLANOS; k++)
	{
		for (int i=0; i<FILAS; i++)
		{
			for (int j=0; j<COLUMNAS; j++)
			{
				suma = suma + f04_matriz[k][i][j];
			} // columnas
		} // filas
	} // planos	
	
	printf("\n\n");
	printf("La suma total de las ventas de los paises es de: %d", suma);
	
	printf("\n\n");
	system("pause");
	
}

main()
{
	system("color 0F");
	
	srand(time(NULL));
	
	int paisMayor = 0;
	
	int matriz[PLANOS][FILAS][COLUMNAS];
	
	cargarMatriz(matriz);
	mostrarMatriz(matriz);
	
	paisMayor = ventaPais(matriz);
	printf("El pais que mas vendio fue el pais: [%d]", paisMayor);
	
	sumaPaises(matriz);
}
