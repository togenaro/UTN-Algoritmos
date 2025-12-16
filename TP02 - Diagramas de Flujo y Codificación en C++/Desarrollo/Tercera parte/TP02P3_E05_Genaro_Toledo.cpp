/*
Universidad Tecnológica Nacional
Facultad Regional Tucumán
Ingeniería en Sistemas de Información

Algoritmos y Estructuras de Datos

Integrantes:
            
            44030752 - Genaro Toledo
*/        
/*
En un Hospital se realiza una estadística para determinar las patologías respiratorias en
época invernal de un grupo no determinado de pacientes. A tal efecto se cargan los siguientes
datos:

	a. EDAD
	
	b. SEXO se ingresa 
		1: si es Masculino
		2: si es Femenino.
		
	c. PATOLOGÍA se ingresa 1: Gripe Estacional,
		2: Gripe A,
		3: Neumonía,
		4: Bronquitis.
		
	La cantidad de personas de sexo masculino que padecen Gripe A.
	Qué porcentaje del total de encuestado es de sexo femenino.
	El ingreso de datos deberá finalizar cuando la edad de la persona encuestada sea
	cero.
*/
	
// -----------------------------------------------------------

#include<stdio.h>
#include<stdlib.h>

// -----------------------------------------------------------
	
// -----------------------------------------------------------

main()

{ // Apertura main
	
// -----------------------------------------------------------	
	
	int numeroSocio = 0;
	int edadSocio = 0;
	int sexoSocio = 0;
	
	int masculinos = 0;
	int femeninos = 0;
	
	int patologia = 0;
	int gripeEstacional = 0;
	int gripeA = 0;
	int neumonia = 0;
	int bronquitis = 0;
	
	int masculinosGripeA = 0;
	int encuestados = 0;
	
	float porcentajeFemeninos = 0;
	
// -----------------------------------------------------------	
		
		// -----------------------------------------------------------
			
			system("cls");		
			printf("Ingrese el numero de socio: ");
			scanf("%d", & numeroSocio);
			
			// -----------------------------------------------------------
			
			// -----------------------------------------------------------
			
			do
			
			{ // Apertura do - while edad
				
				printf("Ingrese la edad del socio (0 PARA CANCELAR): ");
				scanf("%d", & edadSocio);
				
				if (edadSocio < 0)
				
				{
					
					printf("\nEdad incorrecta. Ingrese nuevamente\n\n");
					system("pause");
					system("cls");
					
				}
				
			} // Cierre do - while sexo
			
			while (edadSocio < 0);
			
			// -----------------------------------------------------------
			
		// -----------------------------------------------------------
	
		while (edadSocio != 0)
		
		{ // APERTURA WHILE PRINCIPAL
		
		// -----------------------------------------------------------
			
			
			// -----------------------------------------------------------
	
			do
			
			{ // Apertura do - while sexo
				
				printf("Ingrese el sexo del socio (1: MASCULINO|2: FEMENINO): ");
				scanf("%d", & sexoSocio);
				
				if (sexoSocio == 1)
				
				{
					
					masculinos++;
					
				}
				
				else if (sexoSocio == 2)
				
				{
					
					femeninos++;
					
				}
				
				else if ((sexoSocio != 1) and (sexoSocio != 2))
				
				{
					
					printf("\nEl sexo ingresado es incorrecto. Ingrese nuevamente\n");
					system("pause");
					system("cls");
					
				}
				
			} // Cierre do - while sexo
		
			while ((sexoSocio != 1) and (sexoSocio != 2));
			
			// -----------------------------------------------------------
		
			// -----------------------------------------------------------
		
			do
			
			{  // Apertura do- while patologia
				
				printf("\nPATOLOGIAS: ");
				
				printf("\n\n1: Gripe estacional");
				printf("\n2: Gripe A");
				printf("\n3: Neumonia");
				printf("\n4: Bronquitis");
				
				printf("\n\nIngrese la patologia que posee el socio: ");
				scanf("%d", & patologia);
				
				if (patologia == 1)
				
				{
					
					gripeEstacional++;
					
				}
				
				else if (patologia == 2)
				
				{
					
					gripeA++;
					
				}
				
				else if (patologia == 3)
				
				{
					
					neumonia++;
					
				}
				
				else if (patologia == 4)
				
				{
					
					bronquitis++;
					
				}
				
				else if ((patologia < 1) or (patologia > 4))
				
				{
					
					printf("\nPatologia incorrecta. Ingrese nuevamente\n");
					system("pause");
					system("cls");
					
				}
									
			} //  Cierre do - while patologia
			
			while ((patologia < 1) or (patologia > 4));
			
			// -----------------------------------------------------------
			
			
			system("cls");		
			printf("Ingrese el numero de socio: ");
			scanf("%d", & numeroSocio);
			
			// -----------------------------------------------------------
			
			// -----------------------------------------------------------
			
			do
			
			{ // Apertura do - while edad
				
				printf("Ingrese la edad del socio (0 PARA CANCELAR): ");
				scanf("%d", & edadSocio);
				
				if (edadSocio < 0)
				
				{
					
					printf("\nEdad incorrecta. Ingrese nuevamente\n\n");
					system("pause");
					system("cls");
					
				}
				
			} // Cierre do - while sexo
			
			while (edadSocio < 0);
			
			// -----------------------------------------------------------
			
			if (sexoSocio == 1 and patologia == 2)
			
			{
				
				masculinosGripeA++;
				
			}
			
			// -----------------------------------------------------------
			
			// -----------------------------------------------------------
			
			encuestados++;
			
			porcentajeFemeninos = (femeninos / encuestados) * 100;
			
			// -----------------------------------------------------------	
				
		} // CIERRE WHILE PRINCIPAL
		
		// -----------------------------------------------------------
		
		system("cls");
		
		printf("La cantidad de personas de sexo masculino que padecen gripe A es: %d", masculinosGripeA);
		printf("\nLa cantidad de encuestados de sexo femenino es: %d\n\n", femeninos);
		system("pause");
		
			
} // Cierre main




































