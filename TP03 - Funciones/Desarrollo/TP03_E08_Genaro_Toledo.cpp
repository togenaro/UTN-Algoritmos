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

float calculo(int f01_pares, int f01_sumaPares, int f01_impares, int f01_total, float &f01_porcentajeImpares)
{
	float f01_promedioPares = 0;
	
	f01_promedioPares = (float)f01_sumaPares / (float)f01_total;
	f01_porcentajeImpares = ((float)f01_impares / (float)f01_total) * 100;
	
	return f01_promedioPares;
}

main()
{
	system("color F0");
	
	int N = 0;
	int pares = 0;
	int sumaPares = 0;
	int impares = 0;
	int calculoPar = 0;
	int total = 0;
		
	float promedioPares = 0.0;
	float porcentajeImpares = 0.0;
	
	printf("INGRESE UN NUMERO (0 para finalizar): ");
	scanf("%d", & N);
	
	while(N != 0)
	{
		calculoPar = N % 2;
		
		if (calculoPar == 0)
		{
			pares++;
			sumaPares = sumaPares + N;
		}
		else
		{
			impares++;
		}
		
		total++;
		
		printf("INGRESE UN NUMERO (0 para finalizar): ");
		scanf("%d", & N);
	}
	
	promedioPares = calculo(pares, sumaPares, impares, total, porcentajeImpares);
	
	printf("\n\nEl promedio de numeros pares es: %.2f", promedioPares);
	printf("\nEl porcentaje de numeros impares sobre el total es: %.2f", porcentajeImpares);
	printf("\n\n");
	system("pause");
}
