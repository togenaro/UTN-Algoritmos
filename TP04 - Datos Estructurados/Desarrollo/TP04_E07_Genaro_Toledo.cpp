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
#include <math.h>

const int ORDEN = 10;

int EnteroAleatorio(int minimo, int maximo) 
{	
	int numero = 0;		//10       //20
	
	//variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
	numero = minimo + rand() % (maximo + 1 - minimo);
	
	return numero;
}

void arregloA(int *f01_vector_A)
{
	printf("ARREGLO A: \n\n");
	
	for (int i=0; i<ORDEN; i++)
	{
		f01_vector_A[i] = EnteroAleatorio(10, 99);
	}
	
	for (int i=0; i<ORDEN; i++)
	{
		printf("%d ", f01_vector_A[i]);
	}
	printf("\n\n");

}

void arregloB(int *f02_vector_A, int *f02_vector_B)
{
	int numero = 0;
	int potencia = 0;
	
	for (int i=0; i<ORDEN; i++)
	{
		numero = f02_vector_A[i];
		potencia = pow(numero, 2);
		
		f02_vector_B[i] = potencia;
	}
	
	printf("ARREGLO B: \n\n");
	for (int i=0; i<ORDEN; i++)
	{
		printf("%d ", f02_vector_B[i]);
	}
	printf("\n\n");
	 	
}

void arregloC(int *f03_vector_A, int *f03_vector_B, int *f03_vector_C)
{
	
	for (int i=0; i<ORDEN; i++)
	{
		
		f03_vector_C[i] = f03_vector_B[i] + f03_vector_A[i];
	}
	
	printf("ARREGLO C: \n\n");
	for (int i=0; i<ORDEN; i++)
	{
		printf("%d ", f03_vector_C[i]);
	}
	printf("\n\n");
	system("pause");
	 	
}

main()
{
	system("color F0");
	
	srand(time(NULL));
	
	int vector_A[ORDEN];
	int vector_B[ORDEN];
	int vector_C[ORDEN];
	
	arregloA(vector_A);	
	arregloB(vector_A, vector_B);
	arregloC(vector_A, vector_B, vector_C);	
}
