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

const int ORDEN = 100;

int EnteroAleatorio(int minimo, int maximo) 
{	
	int numero = 0;	
	
	//variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
	numero = minimo + rand() % (maximo + 1 - minimo);
	
	return numero;
}

int cargaVector (int *f00_vector)
{
	printf("Cargando vector...");
	printf("\n\n");
	system("pause");
	
	for (int i=0; i<ORDEN; i++)
	{
		f00_vector[i] = EnteroAleatorio(10, 50);
	}
	
	printf("\n\nHecho.");
	printf("\n\n");
	system("pause");
}

void mostrarVector(int *f02_vector)
{
	system("cls");
	printf("VECTOR GENERADO: \n\n");

	for (int i=0; i<ORDEN; i++)
	{
		printf("%d ", f02_vector[i]);
	}
	
	printf("\n\n");
	system("pause");	
}

float promedioPares(int *f03_vector)
{

	float promedioPares = 0.0;
	int pares = 0;
	int sumaPares = 0;
	
	float promedioImpares = 0.0;
	int impares = 0;
	int sumaImpares = 0;	

	int modulo = 0;
	int numero = 0;
	
	for (int i=0; i<ORDEN; i++)
	{
		numero = f03_vector[i];
		modulo = numero % 2;
		
		if (modulo == 0)
		{
			pares++;
			sumaPares = sumaPares + f03_vector[i];
		}
		else 
		{
			impares++;
			sumaImpares = sumaImpares + f03_vector[i];
		}
	}
	
	printf("\nCantidad de pares: %d", pares);
	printf("\nCantidad de impares: %d", impares);
	printf("\n\n");
	system("pause");
	
	promedioPares = ((float)pares/(float)ORDEN);
	promedioImpares = ((float)impares / (float)ORDEN);
	
	printf("\nPromedio de numeros pares: %.4f", promedioPares);
	printf("\nPromedio de numeros impares: %.4f", promedioImpares);
	
	printf("\n\nSuma de elementos pares: %d", sumaPares);
	printf("\nSuma de elementos impares: %d", sumaImpares);
}					

main()
{
	system("color F0");
	srand(time(NULL));
	
	int sumaTotal = 0;
	int vector[ORDEN];
	
	cargaVector (vector);
	mostrarVector(vector);	
	promedioPares(vector);
	
	printf("\n\n");
	system("pause");
}
