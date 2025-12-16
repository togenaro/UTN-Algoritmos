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

void calculoCuadrado(int f01_N)
{
	int cuadrado = 0;
	int numeroImpar = 1;
	
	for (int i=0; i<f01_N; i++)
	{
		cuadrado = cuadrado + numeroImpar;
		
		numeroImpar = numeroImpar + 2;
	}
	
	printf("\nEl cuadrado del numero ingresado es: %d", cuadrado);
	printf("\n\n");
	system("pause");
}

main()
{
	system("color F0");
	
	int N = 0;
	
	do
	{
		system("cls");
		printf("INGRESE EL NUMERO (0 para finalizar): ");
		scanf("%d", & N);	
		
		if(N == 0)
		{
			system("cls");
			printf("Finalizando...");
			printf("\n\n");
			system("pause");
			exit(1);
		}
		calculoCuadrado(N);
	}
	while(N != 0);
}
