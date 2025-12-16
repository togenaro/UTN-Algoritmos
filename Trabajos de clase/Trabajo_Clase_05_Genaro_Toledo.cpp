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
#include <string.h>

struct fechaDeNacimiento
{
	int dia;
	int mes;
	int anio;
};

struct registro
{
	int codigo;
	char apellido[100];
	char nombre[100];
	fechaDeNacimiento nacimiento;
	char test;
};

void cargaDatos(registro* f01_vector, int f01_N)
{
	printf("\n");
	for (int i=0; i<f01_N; i++)
	{
		printf("PACIENTE [%d]\n", i);
		printf("CODIGO DE PACIENTE: ");
		scanf("%d", & f01_vector[i].codigo);
		
		printf("APELLIDO: ");
		_flushall();
		scanf("%s", f01_vector[i].apellido);
		
		printf("NOMBRE: ");
		_flushall();
		scanf("%s", f01_vector[i].nombre);
	
		printf("FECHA DE NACIMIENTO\n");
		printf("\tDIA: ");
		scanf("%d", & f01_vector[i].nacimiento.dia);
		printf("\tMES: ");
		scanf("%d", & f01_vector[i].nacimiento.mes);
		printf("\tANIO: ");
		scanf("%d", & f01_vector[i].nacimiento.anio);
		
		printf("RESULTADO DEL TEST: (P: POSITIVO|N: NEGATIVO): ");
		_flushall();
		scanf("%c", & f01_vector[i].test);
		printf("\n");
	}
}

int calculoMayores(registro* f02_vector, int f02_N)
{
	int cantidadMayores = 0;
	int edad = 0;
	
	for (int i=0; i<f02_N; i++)
	{
		edad =  (2021 - f02_vector[i].nacimiento.anio);
		
		if (edad >= 60)
		{
			cantidadMayores = cantidadMayores + 1;
		}
	}
	
	return cantidadMayores;
}

int calculoPorcentajePositivos(registro* f03_vector, int f03_N)
{
	float porcentaje = 0.0;
	float cantidad = 0.0;
	int positivos = 0;

	for (int i=0; i<f03_N; i++)
	{
		if (f03_vector[i].test == 'P')
		{
			positivos++;	
		}
	}
	
	cantidad = f03_N;
	porcentaje = (positivos / cantidad) * 100;
	
	return porcentaje;
}

main()
{
	
	
	int N = 0;
	int cantidadMayores = 0;
	float porcentajePositivos = 0.0;
		
	printf("INGRESE CANTIDAD DE PACIENTES: ");
	scanf("%d", & N);
	
	registro vector[N];
	
	cargaDatos(vector, N);
	cantidadMayores = calculoMayores(vector, N);
	printf("La cantidad de pacientes mayores de 60 anios es: %d", cantidadMayores);
	
	porcentajePositivos = calculoPorcentajePositivos(vector, N);
	printf("\nEl porcentaje de pacientes positivos es de: %.2f", porcentajePositivos);
	
	printf("\n\n");
	system("pause");
	
}
