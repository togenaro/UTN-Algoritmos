/*
Universidad Tecnológica Nacional
Facultad Regional Tucumán
Ingeniería en Sistemas de Información

Algoritmos y Estructuras de Datos

Integrantes:
            
            44030752 - Genaro Toledo
*/        
/*
Se necesita saber cuántos CD son necesarios para hacer la copia de seguridad, de la
información almacenada en un disco rígido, cuya capacidad se conoce.

	Considerar también que un disco duro está lleno de información, además expresado
	en gigabyte. Un CD virgen tiene 700 Megabytes de capacidad y un Gigabyte es igual a
	1.024 megabyte.
*/

// -----------------------------------------------------

#include<stdio.h>
#include<stdlib.h>

// -----------------------------------------------------

main ()

{ // Apertura main
	
// -----------------------------------------------------

	float informacionDisco = 0;
	float informacionDiscoMB = 0;
	
	const int CD = 700;
	const int GB = 1024;
	
	float cantidadCD = 0;
	
	int cantidadCDENTERO = 0;
	
// -----------------------------------------------------
	
	// -----------------------------------------------------
	
	do
	
	{
	
		printf("Ingrese la cantidad de informacion almacenada en disco (expresada en GB): ");
		scanf("%f", & informacionDisco);
		
		if (informacionDisco <= 0)
		
		{
			
			printf("\n\nLa informacion almacenada no puede ser negativa ni cero. Ingrese nuevamente.\n\n");
			system("pause");
			system("cls");
			
		}
	
	}
	
	while (informacionDisco <= 0);	
	
	// -----------------------------------------------------
	
	// -----------------------------------------------------
	
	informacionDiscoMB = informacionDisco * GB; // Datos del disco en MegaBytes
	
	cantidadCD = informacionDiscoMB / CD; // Cantidad de CD que se requieren (forma decimal)
	
	cantidadCDENTERO = (int)informacionDiscoMB / (int)CD; // Cantidad de CD que se requieren (forma entera)
	
	if (cantidadCDENTERO != cantidadCD) 
	
	{
		
		cantidadCDENTERO++; // Si la cantidad de CD entero es distinta a la decimal, entonces se suma uno más.
		
	}
	
	// -----------------------------------------------------
	
	// -----------------------------------------------------
		
	printf("\n\nLa cantidad de CD que se necesitan es: %d\n\n", cantidadCDENTERO);
	system("pause");

	// -----------------------------------------------------
	
} // Cierre main
































