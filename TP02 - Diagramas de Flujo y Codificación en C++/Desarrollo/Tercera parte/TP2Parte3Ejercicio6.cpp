#include <stdlib.h>
#include <stdio.h>

/*
	Datos de los autores
*/

main()
{
	int numeroSocio = 0; 
	int edad = 0;
	int deporte = 0;
	int sexo = 0;
	
	int totalSocios = 0;
	int sumaEdades = 0;
	
	int futbol = 0;
	int varones = 0;
	int mujeres = 0;
	int menores = 0;
	float edadPromedio = 0.0;
	
	system("cls");
	
	printf("Numero Socio: ");
	scanf("%d", &numeroSocio);
	
	while ( numeroSocio != 0 )
	{
		printf("Edad: ");
		scanf("%d", &edad);
		
		printf("Deporte: ");
		scanf("%d", &deporte);
		
		printf("Sexo: ");
		scanf("%d", &sexo);
		
		// Contabilizar el nuevo socio ingresado
		totalSocios++;
		
		// Socios entre 30 y 50 años que practican futbol
		if ( ( (edad >= 30) && (edad <= 50) ) && (deporte == 1) )
		{
			futbol++;
		}
		
		
		if ( sexo == 1 )
		{
			varones++;
		}
		
		
		if ( sexo == 2 )
		{
			mujeres++;
		}
		
		
		if ( edad < 16 )
		{
			menores++;
		}
		
		sumaEdades = sumaEdades + edad;
		
		printf("\n\nNumero Socio: ");
		scanf("%d", &numeroSocio);
		
	} // while
	
	if ( totalSocios > 0 )
	{
		edadPromedio = (float) sumaEdades / totalSocios;
		
		printf("\n");
		printf("\nFutbol (30 a 50): %d", futbol);
		printf("\nVarones: %d", varones);
		printf("\nMujeres: %d", mujeres);
		printf("\nMenores: %d", menores);
		printf("\nEdad Promedio: %.2f", edadPromedio);
		
		printf("\n");
		printf("\nSuma de las edades: %d", sumaEdades);
		printf("\nCantidad de socios: %d", totalSocios);
	}
	else
	{
		printf("\n\nNo se registraron socios");
	}
	
	
	
	
	printf("\n\n");
	system("pause");
}
