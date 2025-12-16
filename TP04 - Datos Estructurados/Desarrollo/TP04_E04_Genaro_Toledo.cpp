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
	int numero = 0;		//10       //20
	
	//variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
	numero = minimo + rand() % (maximo + 1 - minimo);
	
	return numero;
}					


void cargaVector(int *f01_vector)
{
	printf("Generando vector...");
	printf("\n\n");
	system("pause");
	for(int i=0; i<ORDEN; i++)
	{
		f01_vector[i] = EnteroAleatorio(1, 432);	
	}

	printf("\n\nHecho.");
	printf("\n\n");
	system("pause");
	system("cls");
}

int calculoMultiplos(int *f02_vector)
{
	int K = 0;
	int multiplos = 0;
	int modulo = 0;
	
	printf("INGRESE ESCALAR: ");
	scanf("%d", & K);
	
	for (int i=0; i<ORDEN; i++)
	{
		modulo = f02_vector[i] % K;
		if(modulo == 0)
		{
			multiplos++;	
		}
	}
	
	return multiplos;
}

void mostrarVector(int *f03_vector)
{
	printf("\nVECTOR GENERADO: \n\n");
	
	for (int i=0; i<ORDEN; i++)
	{
		printf("%d ", f03_vector[i]);
	}
}

main()
{
	system("color F0");
	
	srand(time(NULL));
	
	int multiplos = 0;
	int vector[ORDEN];
	
	cargaVector(vector);
	multiplos = calculoMultiplos(vector);
	
	printf("\nCantidad de multiplos del valor ingresado: %d", multiplos);
	
	printf("\n\n");
	system("pause");
	
	mostrarVector(vector);
		
	printf("\n\n");
	system("pause");
}
