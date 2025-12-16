/*
Universidad Tecnológica Nacional
Facultad Regional Tucumán
Ingeniería en Sistemas de Información

Algoritmos y Estructuras de Datos

Integrantes:
            
            44030752 - Genaro Toledo
*/        
/*
Diseñar un programa que solicite por teclado N números enteros positivos.
Verificar que el número ingresado sea entero positivo, en caso de no ser entero
positivo mostrar un mensaje y volver a solicitar el reingreso del número.
Por cada número ingresado, calcular y mostrar en código binario.
*/

// --------------------------------------------------

#include<stdlib.h>
#include<stdio.h>

// --------------------------------------------------

main()

{ // Apertura main
	
// --------------------------------------------------

	int numeroEntero = 0;
	float numeroFlotante = 0;
	
	int cantidadNumeros = 0;
	int x = 0;
	
	float operacion = 0;
	
// --------------------------------------------------

	// --------------------------------------------------
	
	printf("Ingrese cantidad de numeros a analizar: ");
	scanf("%d", & cantidadNumeros);
	system("cls");
	
	// --------------------------------------------------
	
	// --------------------------------------------------
	
	for (x = 1; x <= cantidadNumeros; x++)
	
	{ // APERTURA FOR PRINCIPAL
	
	// --------------------------------------------------
	
		// --------------------------------------------------
			
			do 
			
			{ // Apertura do - while numero
				system("cls");
				printf("NUMERO %d", x);
				
				printf("\n\nIngrese el numero: ");
				scanf("%f", & numeroFlotante);	
				
				numeroEntero = numeroFlotante; // Sacar parte entera del numero float.
				numeroFlotante = (float)numeroFlotante - numeroEntero; // Sacar parte decimal del numero float.
			
				/*
				printf("\nparte entera: %d", numeroEntero);
				printf("\n\nparte decimal: %f", numeroFlotante);
				*/
				
				if (numeroFlotante > 0)
				
				{
					
					printf("\nEl numero ingresado es decimal. Ingrese nuevamente\n\n");
					system("pause");
					system("cls");
					
				}
				
				else if ((numeroFlotante < 0) or (numeroEntero < 0))
				
				{
					
					printf("\nEl numero tiene que ser positivo. Ingrese nuevamente.\n\n");
					system("pause");
					system("cls");
					
				}
				
			} // Cierre do - while numero
			
			while ((numeroFlotante > 0) or (numeroFlotante < 0) or (numeroEntero < 0));		
			
			// --------------------------------------------------
			
			// --------------------------------------------------
			
			while (numeroEntero < 2)
			
			{
				
				operacion = (int)numeroEntero % 2;
				
			}
			
			
		
		
		
		
	} // CIERRE FOR PRINCIPAL
	
	
		
	

	
} // Cierre main

























