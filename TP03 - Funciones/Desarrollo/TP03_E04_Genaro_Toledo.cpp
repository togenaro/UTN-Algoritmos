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

void calculo(int f01_X, int &f01_acumulador)
{
	int division = 0;

	int primerDigito = 0;
	int operacion = 0;
	int mod = 0;
	int primerValor = 0;
		
		for (int i=0; i<5; i++)
		{
					
			if(i < 1)
			{
				primerValor = f01_X; 
				division = primerValor; // 15677
				mod = division % 10; // 7
				operacion = (mod * 10000); // 70000 
				f01_acumulador = f01_acumulador + operacion; // 70000
			}
			
			division = division / 10; // 1567 - 156 - 15 - 1
			mod = division % 10; // 7 - 6 - 5 - 1					
					
		 	if (division >= 1000 && division < 10000)
			{	//50
				operacion = (mod * 1000); // 7000
				f01_acumulador = f01_acumulador + operacion;
			}
			if (division >= 100 && division < 1000)
			{
				operacion = (mod * 100); // 600
				f01_acumulador = f01_acumulador + operacion;
			}
			if (division >= 10 && division < 100)
			{
				operacion = (mod * 10); // 50
				f01_acumulador = f01_acumulador + operacion;	
			}
			if (division < 10 && division > 0)
			{
				operacion = (mod * 1); // 1
				f01_acumulador = f01_acumulador + operacion;
			}
		}
}

main()
{
	system("color F0");
		
	int X = 0;
	int acumulador = 0;
	
	do
	{
		printf("INGRESE UN NUMERO (5 digitos): ");
		scanf("%d", & X);
		if(X < 10000 || X > 99999)
		{
			system("cls");
			printf("ERROR. Debe ingresar un numero de 5 digitos.");
			printf("\n\n");
			system("pause");
			system("cls");	
		}	
	}
	while(X < 10000 || X > 99999);


	calculo(X, acumulador);
	
	if (acumulador == X)
	{
		printf("\nEl numero ingresado SI ES palindromo.");
		printf("\n\n");
		system("pause");
	}
	else
	{
		printf("\nEl numero ingresado NO ES palindromo.");
		printf("\n\n");
		system("pause");
	}
}
