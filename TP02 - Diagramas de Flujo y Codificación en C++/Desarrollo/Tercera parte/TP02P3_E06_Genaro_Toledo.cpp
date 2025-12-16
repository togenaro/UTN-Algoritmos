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
	c. Deporte que realiza, se ingresa 1: Futbol,
		2: Natación,
		3: jockey.
		
	d. Sexo, se ingresa
		1: Masculinos,
		2: Femeninos.
	
	SE DESEA SABER: 
	
		Cuantos socios entre las edad de 30 y 50 años practican futbol.
		Cuantos socios femenino tiene el club y cuantos masculinos.
		Cuantos socios son menores de 16 años.
		Qué promedio de edad tienen los socios del club.	
*/   

// ---------------------------------------------------------

#include<stdlib.h>
#include<stdio.h>

// ---------------------------------------------------------

// ---------------------------------------------------------

main()

{ // Apertura main
	
// ---------------------------------------------------------
	
	int numeroSocio = 0;
	int edadSocio = 0;
	int deporteSocio = 0;
	int sexoSocio = 0;
	
	int masculinos = 0;
	int femeninos = 0;
	
	int socios_EdadPromedio_Futbol = 0;
	
	int menores16 = 0;
	
	int sumaEdades = 0;
	int contadorEdades = 0;
	float promedioEdad = 0;
	
// ---------------------------------------------------------	

		// ---------------------------------------------------------
		
		system("cls");
		printf("Ingrese el numero de socio (0 PARA CANCELAR): ");
		scanf("%d", & numeroSocio);
		
		// ---------------------------------------------------------
		
	// ---------------------------------------------------------
		
	while (numeroSocio != 0)
	
	{ // APERTURA WHILE PRINCIPAL
	
	// ---------------------------------------------------------
	
		// ---------------------------------------------------------
		
		do
		
		{ // Apertura do- while edad
			
			printf("Ingrese la edad del socio: ");
			scanf("%d", & edadSocio);
			
			if (edadSocio <= 0)
			
			{
				
				printf("\nEdad incorrecta. Ingrese nuevamente.\n\n");
				system("pause");
				system("cls");
				
			}
			
		} // Cierre do - while edad
		
		while (edadSocio <= 0);
			
		// ---------------------------------------------------------
		
		// ---------------------------------------------------------
		
		do 
		
		{ // Apertura do - while deporte
			
			printf("Ingrese el deporte (1: FUTBOL|2: NATACION|3: JOCKEY): ");
			scanf("%d", & deporteSocio);
			
			if ((deporteSocio < 1) or (deporteSocio > 3))
			
			{
				
				printf("\nEl deporte ingresado es incorrecto. Ingrese nuevamente.\n\n");
				system("pause");
				system("cls");
					
			}
			
		} // Cierre do - while deporte
		
		while ((deporteSocio < 1) or (deporteSocio > 3));
		
		// ---------------------------------------------------------
		
		// ---------------------------------------------------------
		
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
				
				femeninos ++;
				
			}
			
			else if ((sexoSocio < 1) or (sexoSocio > 2))
			
			{
				
				printf("\nEl sexo ingresado es incorrecto. Ingrese nuevamente.\n\n");
				system("pause");
				system("cls");
				
			}
			
		} // Cierre do - while sexo
		
		while ((sexoSocio < 1) or (sexoSocio > 2));
		
		// ---------------------------------------------------------
		
		// ---------------------------------------------------------
		
		if ((edadSocio >= 30) and (edadSocio <= 50)) // Socios entre 30 y 50 años que practican futbol.
		
		{
			
			if (deporteSocio == 1)
			
			{
				
				socios_EdadPromedio_Futbol++;
				
			}
			
		}
		
		// ---------------------------------------------------------
		
			if (edadSocio < 16)
		
		{
			
			menores16++;
			
		}
		
		sumaEdades = sumaEdades + edadSocio; // Para calcular el promedio de edades
		contadorEdades++;
		
		system("cls");
		printf("Ingrese el numero de socio (0 PARA CANCELAR): ");
		scanf("%d", & numeroSocio);
		
		// ---------------------------------------------------------
		
		// ---------------------------------------------------------
					
	} // CIERRE WHILE PRINCIPAL
	
	// ---------------------------------------------------------
	
	if (contadorEdades <= 0)
	
	{
		
		system("cls");
		printf("No se ingreso ningun socio.\n\n");
		system("pause");
			
		
	}
	
	else 
	
	{
		
		promedioEdad = (int)(sumaEdades / contadorEdades);
		
		system("cls");
	
		printf("Socios entre 30 y 50 anios que practican futbol: %d", socios_EdadPromedio_Futbol);
		printf("\nSocios femeninos: %d", femeninos);
		printf("\nSocios masculinos: %d", masculinos);
		printf("\nSocios menores de 16 anios: %d", menores16);
		printf("\nPromedio de edad de los socios: %.0f\n\n", promedioEdad);
	
		system("pause");
		
	}
	
	// ---------------------------------------------------------
	
} // Cierre main












































