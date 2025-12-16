/*
Universidad Tecnológica Nacional
Facultad Regional Tucumán
Ingeniería en Sistemas de Información

Algoritmos y Estructuras de Datos

Integrantes:

			44030752 - Genaro Toledo
*/        

/*

Se ingresa por teclado un conjunto de números, uno a uno.
 
	Contar cuantas veces se ingresa los valores 10, 20, 30; y cuantos números 
	distintos a los mencionados se ingresan. El algoritmo debe terminar cuando 
	se ingrese el valor igual a -1.
	
*/

#include<stdlib.h>
#include<stdio.h>

main()

{
	int numero = 0;
	int numero10 = 0;
	int numero20 = 0;
	int numero30 = 0;
	int distintos = 0;
	int contadores = 0;

	
	do
	
	{
		system("cls");
		printf("Ingrese un numero o (-1 para cancelar):  ");
		scanf("%d", & numero);
		
		if (numero == 10)
		
		{
			
			numero10++;	
			
		}
		
		else if (numero == 20)
		
		{
			
			numero20++;
			
		}
		
		else if (numero == 30)
		
		{
			
			numero30++;
			
		}
		
		else if ((numero != 10) and (numero != 20) and (numero != 30) and (numero != -1)) 
		
		{
			
			distintos++;
			
		}
		
	}
	
	while (numero != -1);
	
	system("cls");
	
	contadores = numero10 + numero20 + numero30 + distintos;
	
	if (contadores == 0)
	
	{
		
		printf("No se ingreso ningun numero.");	
		
	}
	
	else if (contadores != 0)
	
	{
	
		system("cls");
		printf("La cantidad de numeros de valor 10 es: %d", numero10);
		printf("\nLa cantidad de numeros de valor 20 es: %d", numero20);
		printf("\nLa cantidad de numeros de valor 30 es: %d", numero30);
		
		printf("\n\nLa cantidad de numeros de valor distinto de 10, 20 o 30 es: %d", distintos);
	
	}
		
}

