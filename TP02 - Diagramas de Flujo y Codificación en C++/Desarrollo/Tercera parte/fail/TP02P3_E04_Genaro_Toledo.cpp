/*
Universidad Tecnológica Nacional
Facultad Regional Tucumán
Ingeniería en Sistemas de Información

Algoritmos y Estructuras de Datos

Integrantes:
            
            44030752 - Genaro Toledo
*/     

/*
Ingrese una cantidad no definida de valores enteros y determine la suma de los valores
pares y la suma de los valores impares ingresados. Utilizar una bandera para terminar el ciclo
el ciclo cuando el valor ingresado sea cero
*/

#include<stdio.h>
#include<stdlib.h>

main()

{ // Apertura main
	
// ------------------------------------
	
	int numero = 0;
	
	int residuo = 0;

	int sumaPares = 0;
	int sumaImpares = 0;
	
	const int bandera = 0;
	
// ------------------------------------

	// ------------------------------------

	do

	{ // Apertura do-while principal
		
		system("cls");
		printf("Ingrese un numero o (0 para cancelar): ");
		scanf("%d", & numero);
		
		residuo = 0;
		residuo = (numero % 2);
		
		if (residuo == 0)
		
		{
			
			sumaPares = sumaPares + numero;
			
		}
		
		else
		
		{
			sumaImpares = sumaImpares + numero;
			
		}
		
		
	} // Cierre do-while principal
	
	while (numero != bandera);
	
	// ------------------------------------
	
	// ------------------------------------
	
	system("cls");
	
	printf("La suma de los valores pares es: %d\n", sumaPares);
	printf("La suma de los valores impares es: %d\n", sumaImpares);
	
	
	// ------------------------------------	
	
} //Cierre main
