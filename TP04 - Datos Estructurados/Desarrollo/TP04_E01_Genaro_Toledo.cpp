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

void carga(int* f01_vector, int f01_N)
{
	system("cls");
	int valor = 0;
	
	for (int i=0; i<f01_N; i++)
	{
		printf("INGRESE SUBINDICE [%d]: ", i);
		scanf("%d", & valor);
		
		f01_vector[i] = valor;
	}
}

int menorValor(int* f02_vector, int f02_N)
{
	int minimo = 99999999;
	
	for (int i=0; i<f02_N; i++)
	{
		if (f02_vector[i] < minimo)
		{
			minimo = f02_vector[i];
		}
	}
	
	return minimo;
}

void mostrarVector(int* f03_vector, int f03_N)
{
	system("cls");
	printf("VALORES INGRESADOS: ");
	printf("\n");
	
	for (int i=0; i<f03_N; i++)
	{
		printf("\n");
		printf("SUBINDICE [%d]: %d", i, f03_vector[i]);
	}
	printf("\n\n");
	system("pause");
	
}

main()
{
	int N = 0;
	int menor = 0;
	
	printf("INGRESE EL ORDEN DEL VECTOR: ");
	scanf("%d", & N);
	int vector[N] = {0};
	
	carga(vector, N);
	
	menor = menorValor(vector, N);
	system("cls");
	printf("EL MENOR VALOR INGRESADO ES: %d", menor);
	printf("\n\n");
	system("pause");
	
	mostrarVector(vector, N);			
}
