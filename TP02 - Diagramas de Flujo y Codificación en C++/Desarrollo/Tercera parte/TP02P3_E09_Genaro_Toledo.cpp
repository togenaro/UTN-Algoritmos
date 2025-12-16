/*
Universidad Tecnológica Nacional
Facultad Regional Tucumán
Ingeniería en Sistemas de Información

Algoritmos y Estructuras de Datos

Integrantes:
            
            44030752 - Genaro Toledo
*/        
/*
Dados N números enteros positivo. Determinar si cada uno de los números ingresado es
primo.

Verificar que los números que se ingresen sean positivos enteros.

En caso de que él número ingresado sea primo mostrar el mensaje, “El numero ingresado ES primo” 
en caso de no ser primo mostrar el mensaje “El numero ingresado NO es primo”
*/

// ----------------------------------------------

#include<stdio.h>
#include<stdlib.h>

// ----------------------------------------------

main()

{ // Apertura main
	
// ----------------------------------------------



// ----------------------------------------------	
	
	// ----------------------------------------------
	
	// ----------------------------------------------
	
	do
	
	{ // Apertura do - while cantidad 
		
		printf("Ingrese la cantidad de numeros analizar: ");
		scanf("%d", & cantidadNumeros);
		
		if (cantidadNumeros <= 0)
		
		{
			
			printf("\nCantidad de numeros incorrecta. Ingrese nuevamente.\n\n");
			system("pause");
			system("cls");
			
		}
		
	} // Cierre do - while cantidad
	
	while (cantidadNumeros < 0);
	
	// ----------------------------------------------
	
	// ----------------------------------------------
	
	for (int x = 1; x <= cantidadNumeros; x++)
	
	{ // APERTURA FOR PRINCIPAL
		
		residuo = 0;
		operacion = 0;
		
	// ----------------------------------------------
		
		// ----------------------------------------------
		
		do
		
		{ // Apertura do - while numero
			
			printf("NUMERO %d", x);
			
			printf("\n\nIngrese el numero a analizar: ");
			scanf("%d", numero);
			
			if (numero <= 0)
			
			{
				
				printf("\nEl numero debe ser positivo y distinto de cero. Ingrese nuevamente.\n\n");
				system("pause");
				system("cls");
				
			}
			
		} // Cierre do - while numero
		
		while (numero <= 0);
		
		// ----------------------------------------------
		
		// ----------------------------------------------
		
	} // CIERRE FOR PRINCIPAL
	
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
} // Cierre main































