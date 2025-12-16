/*
Universidad Tecnológica Nacional
Facultad Regional Tucumán
Ingeniería en Sistemas de Información

Algoritmos y Estructuras de Datos

Integrantes:
            
            44030752 - Genaro Toledo
*/        
/* 
Se ingresan los datos de los socios de un club, el ingreso termina cuando se ingrese un
numero de socio igual a cero.

Los datos ingresados son los siguientes:

	a. Nro. de Socio (numero entero)
	b. Edad.
	c. Deporte que realiza (1=Futbol, 2= Natación, 3 = jockey).
	d. Sexo (1 = Masculinos, 2 = Femeninos).
	
SE PIDE
	
	Cuantos socios entre las edad de 30 y 50 años practican futbol.
	Cuantos socios femenino tiene el club y cuantos masculinos.
	Cuantos socios son menores de 16 años.
	
*/ 

#include<stdlib.h>
#include<stdio.h>

main()

{ // Apertura main

//---------------------------------------------------

	int numeroSocio = 0;
	int edadSocio = 0;
	int sexoSocio = 0;
	int deporteSocio = 0;
	
	int mayores = 0;
	int menores = 0;
	
	int masculinos = 0;
	int femeninos = 0;
	
	int mayoresFutbol = 0;
	
	int socios = 0;

//---------------------------------------------------

	//---------------------------------------------------

	printf("Ingrese el numero de socio o (0 para cancelar): ");
	scanf("%d", & numeroSocio);
	
	while (numeroSocio != 0)
	
	{ // Apertura while
	
	//---------------------------------------------------
		
	//---------------------------------------------------
	
		do
		
		{
			
			printf("Ingrese la edad del socio: ");
			scanf("%d", & edadSocio);	
			
			if (edadSocio <= 0)
				
			{
				
				printf("\nLa edad ingresada es incorrecta. \n\n");
				system("pause");
				system("cls");
				
			}
			
		}
		
		while (edadSocio <= 0);
		
		if ((edadSocio >= 30) and (edadSocio <= 50))
		
		{
			
			mayores++;
			
		}
		
		else if (edadSocio < 16)
		
		{
			
			menores++;
			
		}
		
		//---------------------------------------------------
		
		//---------------------------------------------------
		
		do
		
		{
			
			printf("Ingrese el deporte (1: FUTBOL|2: NATACION|3: JOCKEY): ");
			scanf("%d", & deporteSocio);
			
			if ((deporteSocio > 3) or (deporteSocio <= 0))
			
			{
				
				printf("\nEl deporte ingresado es incorrecto.\n\n");
				system("pause");
				system("cls");
				
			}	
			
		}
		
		while ((deporteSocio > 3) or (deporteSocio <= 0));
		
		//---------------------------------------------------
		
		//---------------------------------------------------
		
		do
		
		{
			
			printf("Ingrese el sexo del socio (1: MASCULINO|2: FEMENINO): ");
			scanf("%d", & sexoSocio);
			
			if ((sexoSocio <= 0) or (sexoSocio > 2))
			
			{
				
				printf("\nEl sexo ingresado es incorrecto. \n\n");
				system("pause");
				system("cls");
				
			}
			
		}
		
		while ((sexoSocio <= 0) or (sexoSocio > 2));
		
		if (sexoSocio == 1)
		
		{
			
			masculinos++;
			
		}	
		
		else if (sexoSocio == 2) 
		
		{
			
			femeninos++;
			
		}
		
		//---------------------------------------------------
		
		//---------------------------------------------------
		
		if ((edadSocio >= 30) and (edadSocio <= 50) and (deporteSocio == 1))
		
		{
			
			mayoresFutbol++;
			
		}
		
		socios++;
		
		//---------------------------------------------------	
		
		//---------------------------------------------------
		
		system("cls");
		printf("Ingrese el numero de socio o (0 para cancelar): ");
		scanf("%d", & numeroSocio);
		
		
		//---------------------------------------------------
		
	} // Cierre while
	
	//---------------------------------------------------
	
	if (socios == 0)
	
	{
		
		system("cls");
		printf("No se ingreso ningun socio.\n");
		
	}
	
	else 
	
	{
		
		system("cls");
	
		printf("Socios masculinos: %d\n", masculinos);
		printf("Socios femeninos: %d\n", femeninos);
		printf("Socios entre 30 y 50 años que practican futbol: %d\n", mayoresFutbol);
		printf("Socios menores de 16 años: %d\n", menores);
		
	}
	
	//---------------------------------------------------
	
} // Cierre main





































