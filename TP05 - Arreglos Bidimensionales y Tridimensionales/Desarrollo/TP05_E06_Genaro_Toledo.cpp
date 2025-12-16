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

void mostrarMatriz(int f0n_matriz[PLANOS][FILAS][COLUMNAS], int f0n_p, int f0n_f, int f0n_c)
{
	printf("\n");
	printf("MATRIZ GENERADA: ");
	printf("\n\n");
	
	for (int k=0; k<f0n_p; k++)
	{
		printf("PLANO [%d]", k);
		printf("\n\n");
		for (int i=0; i<f0n_f; i++)
		{
			for (int j=0; j<f0n_c; j++)
			{
				printf("%d ", f0n_matriz[k][i][j]);
			} // columnas
			printf("\n");
		} // filas
		printf("\n");
	} // planos

}

int calculoMenorValor(int f02_matriz[PLANOS][FILAS][COLUMNAS], int f02_p, int f02_f, int f02_c)
{
	int f02_menor = 99999;
	
	for (int k=0; k<f02_p; k++)
	{
		for (int i=0; i<f02_f; i++)
		{
			for (int j=0; j<f02_c; j++)
			{
				//f02_matriz[k][i][j] = EnteroAleatorio(10, 99);
				
				if (f02_matriz[k][i][j] < f02_menor)
				{
					f02_menor = f02_matriz[k][i][j];
				}
			} // columnas
			
		} // filas
	
	} // planos
	
	return f02_menor;
	
}

int calculoParidad(int f03_menor)
{
	int f03_parOImpar = 0;
	
	f03_parOImpar = f03_menor % 2;
	
}

main()
{
	system("color 0F");
	
	srand(time(NULL));
	
	int p = 0; // planos
	int f = 0; // filas
	int c = 0; // columnas
	
	int menor = 0;
	int parOImpar = 0;
	
	printf("INGRESE CANTIDAD DE PLANOS: ");
	scanf("%d", & p);
	printf("INGRESE CANTIDAD DE FILAS: ");
	scanf("%d", & f);
	printf("INGRESE CANTIDAD DE COLUMNAS: ");
	scanf("%d", & c);	
	
	int matriz[PLANOS][FILAS][COLUMNAS];
	
	cargaMatriz(matriz, p, f, c);
	mostrarMatriz(matriz, p, f, c);
	
	menor = calculoMenorValor(matriz, p, f, c);
	printf("-----------------------\n\n");
	printf("El menor valor es: %d", menor);
	printf("\n\n");
	
	parOImpar = calculoParidad(menor);
	if (parOImpar == 0)
	{
		printf("El menor valor es: PAR.");
	}
	else 
	{
		printf("El menor valor es: IMPAR.");
	}
	printf("\n\n-----------------------");
	
	printf("\n\n");
	system("pause");
}
