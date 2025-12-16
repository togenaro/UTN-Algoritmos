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

void calculoHoras(int f01_cantDias)
{
	int horas = 24;
	
	horas = horas * f01_cantDias;
	
	printf("\nHoras: %d", horas);
}

void calculoMinutos(int f02_cantDias)
{
	int minutos = 1440;
	
	minutos = minutos * f02_cantDias;
	
	printf("\nMinutos: %d", minutos);	
}

void calculoSegundos(int f03_cantDias)
{
	int segundos = 86400;
	
	segundos = segundos * f03_cantDias;
	
	printf("\nSegundos: %d", segundos);
	printf("\n\n");
	system("pause");	
}

main()
{
	int cantDias = 0;
	
	do
	{
		printf("INGRESE CANTIDAD DE DIAS: ");
		scanf("%d", & cantDias);
		
		if(cantDias < 100)
		{	
			system("cls");
			printf("El valor ingresado debe ser mayor a 100. Ingrese nuevamente.");
			printf("\n\n");
			system("pause");
			system("cls");
		}
		else
		{
			calculoHoras(cantDias);
			calculoMinutos(cantDias);
			calculoSegundos(cantDias);		
		}
	}
	while(cantDias < 100);
	
}
