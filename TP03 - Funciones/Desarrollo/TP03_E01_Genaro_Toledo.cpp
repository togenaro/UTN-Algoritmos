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

void calculoIntervalo(int f01_N, int f01_A, int f01_B, int &f01_dentro, int &f01_fuera)
{	
	if (f01_N >= f01_A && f01_N < f01_B)
	{
		f01_dentro++;
	}
	else 
	{
		f01_fuera++;
	}
	
}

main()
{
	system("color F0");
	
	int N = 0;
	int A = 0;
	int B = 0;
	
	int dentro = 0;
	int fuera = 0;

	printf("INGRESE VALOR MINIMO DEL INTERVALO A: ");
	scanf("%d", & A);
	
	printf("INGRESE VALOR MAXIMO DEL INTERVALO B: ");
	scanf("%d", & B);
	
	system("cls");
	printf("INGRESE UN NUMERO (0 para finalizar): ");
	scanf("%d", & N);
	
	while(N != 0)
	{
		calculoIntervalo(N, A, B, dentro, fuera);
		
		printf("INGRESE UN NUMERO (0 para finalizar): ");
		scanf("%d", & N);		
	}
	
	printf("\n\nValores dentro del intervalo: %d", dentro);
	printf("\nValores fuera del intervalo: %d", fuera);
	
	printf("\n\n");
	system("pause");
}
