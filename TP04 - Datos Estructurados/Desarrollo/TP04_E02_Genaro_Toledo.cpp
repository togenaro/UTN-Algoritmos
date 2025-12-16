/*
Universidad Tecnológica Nacional
Facultad Regional Tucumán
Ingeniería en Sistemas de Información

Algoritmos y Estructuras de Datos

Integrantes:
            
            44030752 - Genaro Toledo
*/        

#include <stdlib.h>
#include <stdio.h>

void cargaNotas(int* f01_vector, int f01_N)
{
	system("cls");
	int nota = 0;
	
	for (int i=0; i<f01_N; i++)
	{
		do
		{
			system("cls");
			printf("INGRESE NOTA [%d]: ", i);
			scanf("%d", & nota);
			if((nota > 10) or (nota < 1))
			{
				system("cls");
				printf("La nota ingresada es incorrecta. Ingrese nuevamente.");
				printf("\n\n");
				system("pause");
			}
			
				
		}
		while((nota > 10) or (nota < 1));
		
		f01_vector[i] = nota;
	}
}

void mayorYMenor(int* f02_vector, int f02_N)
{
	system("cls");
	
	int mayor = -9999999;
	int menor = 99999999;
	
	for (int i=0; i<f02_N; i++)
	{
		if (f02_vector[i] < menor)
		{
			menor = f02_vector[i];
		}
		else if (f02_vector[i] > mayor)
		{
			mayor = f02_vector[i];
		}
	}
	
	printf("LA MAYOR NOTA INGRESADA ES: %d", mayor);
	printf("\nLA MENOR NOTA INGRESADA ES: %d", menor);
	
	printf("\n\n");
	system("pause");
	
}

float promedioNotas(int* f03_vector, int f03_N)
{
	system("cls");
	
	int sumaNotas = 0;
	int cantidadNotas = 0;
	float promedio = 0;
	
	for (int i=0; i<f03_N; i++)
	{
		sumaNotas = sumaNotas + f03_vector[i];
		cantidadNotas++;
	}
	
	promedio = (sumaNotas / cantidadNotas); 
	
	return promedio;
}

main()
{
	int N = 0;
	int mayorNota = 0;
	int menorNota = 0;
	int promedio = 0;
	
	printf("INGRESE LA CANTIDED DE NOTAS DEL CURSO: ");
	scanf("%d", & N);
	int vector[N] = {0};
	
	cargaNotas(vector, N);
	
	mayorYMenor(vector, N);
	
	promedio = promedioNotas(vector, N);
	printf("EL VALOR PROMEDIO DE LAS NOTAS ES: %d", promedio);
	printf("\n\n");
	system("pause");
	
}
