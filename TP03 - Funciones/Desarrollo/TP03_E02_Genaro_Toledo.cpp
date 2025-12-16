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

void calcularMultiplos(int f01_X)
{
	int multiplo = 0;
	int n = 1;
	
	printf("\nLos multiplos del numero ingresado son: ");
	do
	{
		multiplo = f01_X * n;
		n++;
			
		printf(" %d", multiplo);
	}
	while (n != 11);		

	printf("\n\n");
	system("pause");
}

void calcularSubMultiplos(int f02_X)
{
	int submultiplo = 0;
	int modulo = 0;
	
	printf("\nLos submultiplos del numero ingresado son: ");

	for (int n=1; n<=f02_X; n++)
	{
		submultiplo = f02_X / n;
		
		if ( (f02_X % n) == 0)
		{
			printf(" %d", submultiplo);	
		}
		
	}
	
	printf("\n\n");
	system("pause");
}

main()
{
	system("color F0");
	
	int N = 0;
	int X = 0;
	
	printf("INGRESE CANTIDAD DE NUMEROS: ");
	scanf("%d", & N);
	
	for (int i=0; i<N; i++)
	{
		system("cls");
		
		printf("INGRESE EL NUMERO [%d]: ", i);
		scanf("%d", & X);	
		
		if (X > 0 && X < 150)
		{
			calcularMultiplos(X);
		}
		else if (X >= 150 && X < 301)
		{
			calcularSubMultiplos(X);
		}
		else if (X <= 0 || X >= 301)
		{
			system("cls");
			printf("Valor incorrecto.");
			printf("\n\n");
			system("pause");
		}
	}
	
	
}
