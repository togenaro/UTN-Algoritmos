/*
Universidad Tecnológica Nacional
Facultad Regional Tucumán
Ingeniería en Sistemas de Información

Algoritmos y Estructuras de Datos

Integrantes:
            
            44030752 - Genaro Toledo
*/        

/*
Se lee la base y la altura de un conjunto de rectángulos.

	Se pide mostrar el valor delárea, la base y la altura, solo de aquellos rectángulos cuyo
	perímetro sea menor a un valor dado (o sea ingresado como dato).
	
	Continuar ingresando valores (base y altura) hasta que la
	base ingresada sea igual a cero.
*/

#include<stdio.h>
#include<stdlib.h>

main()
{
	int base = 0;
	int altura = 0;
	int area = 0;
	int valor = 0;
	int perimetro = 0;
	
	printf("Ingrese un valor minimo para el perimetro: ");
	scanf("%d", & valor);
	
	
	do 
		
		{
			
			system("cls");
			printf("Ingrese el valor de la base del rectangulo o (0 para cancelar): ");
			scanf("%d", & base);
			
			if (base < 0)
			
			{
				
				printf("\nLa base ingresada debe ser positiva. ");
				system("pause");	
				system("cls");
				
			}
				
		}
		
		while (base < 0);
		
	while (base != 0)
	
	{
			
		do
		
		{
		
			printf("Ingrese el valor de la altura del rectangulo: ");
			scanf("%d", & altura);
			
			if (altura <= 0)
			
			{
				
				printf("\nLa altura ingresada debe ser positiva y distinta de cero. ");
				system("pause");
				system("cls");
				
			}
			
		}
		
		while (altura <= 0);
		
		perimetro = (base * 2) + (altura * 2);
		area = base * altura;
		
		if (perimetro > valor)
		
		{
			
			printf("\nNo se puede calcular el area porque el perimetro supera al valor ingresado.\n\n");
			system("pause");
			
		}
		
		else 
		
		{
			
			printf("\nEl area del rectangulo es: %d\n\n", area);
			system("pause");	
			
		}
		
		do 
		
		{
			
			system("cls");
			printf("Ingrese el valor de la base del rectangulo o (0 para cancelar): ");
			scanf("%d", & base);
			
			if (base < 0)
			
			{	
			
				printf("\nLa base ingresada debe ser positiva. ");
				system("pause");
						
			}
			
				
		}
		
		while (base < 0);
	
	} //while cancelar algoritmo
	
} //main


























