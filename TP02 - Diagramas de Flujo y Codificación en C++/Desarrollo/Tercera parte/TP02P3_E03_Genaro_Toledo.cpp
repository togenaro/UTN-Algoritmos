/*
Universidad Tecnológica Nacional
Facultad Regional Tucumán
Ingeniería en Sistemas de Información

Algoritmos y Estructuras de Datos

Integrantes:
            
            44030752 - Genaro Toledo
*/        
/* 
Se Tiene los puntos A(x1,y1) y B(x2 , y2) de coordenadas. en el cuadrante positivo del plano
cartesiano, elabore un programa que permita obtener la distancia entre los puntos A y B ingresados
por teclado atreves del teorema de Pitágoras.
*/

// --------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

// --------------------------------------------------------

main()

{ // Apertura main
	
// --------------------------------------------------------	
	
	int c1 = 0;
	int c2 = 0;
	
	float cateto1Cuadrado = 0;
	float cateto2Cuadrado = 0;
	
	float hipotenusaCuadrada = 0;
	float hipotenusa = 0;
	
	
// --------------------------------------------------------	
	
	// --------------------------------------------------------	
	
	do
	
	{
		
		printf("Ingrese el valor del cateto 1: ");
		scanf("%d", & c1);
		
		if (c1 <= 0)
		
		{
			
			printf("El valor ingresado es incorrecto.\n\n");
			system("pause");
			system("cls");
			
		}
	
	
	}
	
	while (c1 <= 0);
	
	// --------------------------------------------------------	
	
	// --------------------------------------------------------	
	
	do
	
	{
		
		printf("Ingrese el valor del cateto 2: ");
		scanf("%d", & c2);
		
		if (c2 <= 0)
		
		{
			
			printf("El valor ingresado es incorrecto.\n\n");
			system("pause");
			system("cls");
			
		}
		
	
	
	}
	
	while (c2 <= 0);
	
	// --------------------------------------------------------	
	
	// --------------------------------------------------------	
	
	cateto1Cuadrado = pow(c1, 2);
	
	cateto2Cuadrado = pow(c2, 2);
	
	hipotenusaCuadrada = cateto1Cuadrado + cateto2Cuadrado;
	
	hipotenusa = sqrt(hipotenusaCuadrada);
	
	// --------------------------------------------------------	
	
	// --------------------------------------------------------	
	
	printf("\n\nEl valor de la hipotenusa es: %.2f", hipotenusa);
	
	// --------------------------------------------------------	
	
	
} // Cierre main

