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
			   
Comisión:
			-- 1K06 --
*/   

#include <stdlib.h>
#include <stdio.h>
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

void mostrarmatriz(int f0n_matriz[PLANOS][FILAS][COLUMNAS], int f0n_p, int f0n_f, int f0n_c)
{
	system("cls");
	printf("ARREGLO GENERADO:");
	printf("\n\n");
	for (int k=0; k<f0n_p; k++)
	{
		printf("PLANO [%d]: ", k);
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

void llenarVector(int f02_matriz[PLANOS][FILAS][COLUMNAS], int f02_p, int f02_f, int f02_c, int* f02_sumaPlanos)
{
	int suma = 0;
	
	for (int k=0; k<f02_p; k++)
	{
		suma = 0;
		
		for (int i=0; i<f02_f; i++)
		{
			for (int j=0; j<f02_c; j++)
			{
				suma = suma + f02_matriz[k][i][j]; 
			}
		}
		
		f02_sumaPlanos[k] = suma;
	}
	
}

void mostrarVector(int* f03_sumaPlanos, int f03_p)
{
	printf("SUMA DE LOS PLANOS:");
	printf("\n\n");
	for (int k=0; k<f03_p; k++)
	{
		printf("PLANO [%d]: %d ", k, f03_sumaPlanos[k]);
		printf("\n");
	}
	

}

float calculoPromedio(int* f04_sumaPlanos, int f04_p)
{
	int sumaVector = 0;
	float f04_promedio = 0.0;
	int cantidad = 0;
	
	for (int k=0; k<f04_p; k++)
	{
		sumaVector = sumaVector + f04_sumaPlanos[k];
		cantidad++;
	}
		
	f04_promedio = ((float)sumaVector/(float)cantidad);
	return f04_promedio;
}

main()
{
	system("color 0F");
	
	srand(time(NULL));
	
	int f = 0; // filas
	int c = 0; // columnas
	int p = 0; // planos
	float promedio = 0.0; // promedio del vector
	
	printf("INGRESE CANTIDAD DE PLANOS: ");
	scanf("%d", & p);
	printf("INGRESE CANTIDAD DE FILAS: ");
	scanf("%d", & f);
	printf("INGRESE CANTIDAD DE COLUMNAS: ");
	scanf("%d", & c);
	
	int matriz[PLANOS][FILAS][COLUMNAS]; // arreglo multidimensional
	int sumaPlanos[p]; // vector suma
	
	cargaMatriz(matriz, p, f, c);
	mostrarmatriz(matriz, p, f, c);
	
	llenarVector(matriz, p, f, c, sumaPlanos);
	mostrarVector(sumaPlanos, p); 	
	
	promedio = calculoPromedio(sumaPlanos, p);
	
	printf("\n");
	printf("El promedio del vector es: %.2f", promedio);
	printf("\n\n");
	system("pause");
}

