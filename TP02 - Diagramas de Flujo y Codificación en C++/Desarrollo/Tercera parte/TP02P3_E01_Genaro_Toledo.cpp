/*
Universidad Tecnológica Nacional
Facultad Regional Tucumán
Ingeniería en Sistemas de Información

Algoritmos y Estructuras de Datos

Integrantes:
            
            44030752 - Genaro Toledo
*/    
/*
La secretaria debe ingresar por teclado los valores obtenidos en la nota de un alumno:

	Nota Promedio de sus parciales.
	Nota Promedio de sus trabajos integradores.
	Nota de su trabajo final.
	
SE PIDE

	cuál será su calificación final en la materia de Algoritmos y estructura de Datos
	donde la calificación final es 10 y se compone de la suma de los siguientes porcentajes
	obtenida de sus notas promedios y trabajo final:
	
		40% corresponde al promedio de sus parciales.
		20% corresponde al promedio de sus trabajos integradores.
		40% corresponde a la calificación de su trabajo final.
*/     

//------------------------------------------------

#include<stdlib.h>
#include<stdio.h>

//------------------------------------------------

main()

{	// Apertura main

//------------------------------------------------

	float promedioParciales = 0;
	float promedioIntegradores = 0;
	float trabajoFinal = 0;
	
	float porcentaje_Integradores = 0;
	float porcentaje_Parciales = 0;
	float porcentaje_TrabajoFinal = 0;
	
	float notaFinal = 0;
	
//------------------------------------------------

	//------------------------------------------------
	
	do
	
	{
		
		printf("Ingrese el promedio de parciales del alumno: ");
		scanf("%f", & promedioParciales);
		
		if ((promedioParciales < 0) or (promedioParciales > 10))
		
		{
			
			printf("Promedio incorrecto. Ingrese nuevamente\n\n");
			system("pause");
			system("cls");
			
		}
	
	}
	
	while ((promedioParciales < 0) or (promedioParciales > 10));
	
	//------------------------------------------------
	
	//------------------------------------------------
	
	do
	
	{
	
		printf("Ingrese el promedio de trabajos integradores del alumno: ");
		scanf("%f", & promedioIntegradores);
		
		if ((promedioIntegradores < 0) or (promedioIntegradores > 10))
			
			{
				
				printf("Promedio incorrecto. Ingrese nuevamente\n\n");
				system("pause");
				system("cls");
				
			}
	
	}
	
	while ((promedioIntegradores < 0) or (promedioIntegradores > 10));
	
	//------------------------------------------------
	
	//------------------------------------------------
	
	do
	
	{
		
		printf("Ingrese la nota del trabajo final del alumno: ");
		scanf("%f", & trabajoFinal);
		
		if ((trabajoFinal < 0) or (trabajoFinal > 10))
			
			{
				
				printf("Promedio incorrecto. Ingrese nuevamente\n\n");
				system("pause");
				system("cls");
				
			}
			
	}
	
	while ((trabajoFinal < 0) or (trabajoFinal > 10));
	
	//------------------------------------------------
	
	//------------------------------------------------
	
	porcentaje_Parciales = promedioParciales * 0.40;
	
	porcentaje_Integradores = promedioIntegradores * 0.20;
	 
	porcentaje_TrabajoFinal = trabajoFinal * 0.40;
	
	notaFinal = porcentaje_Parciales + porcentaje_Integradores + porcentaje_TrabajoFinal;
	
	//------------------------------------------------
	
	//------------------------------------------------
	
	system("cls");
	
	printf("-------------------------------------------------");
	
	printf("\n\nPorcentaje de los parciales: %.2f", porcentaje_Parciales);
	printf("\nPorcentaje de los trabajos integradores: %.2f", porcentaje_Integradores);
	printf("\nPorcentaje del trabajo final: %.2f", porcentaje_TrabajoFinal);
	
	printf("\n\n-------------------------------------------------");
	
	printf("\n\nLa nota final es: %.2f\n\n", notaFinal);
	system("pause");
	
	//------------------------------------------------
	
}	// Cierre main


































