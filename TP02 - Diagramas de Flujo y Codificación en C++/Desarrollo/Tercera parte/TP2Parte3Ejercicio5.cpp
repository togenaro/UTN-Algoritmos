#include <stdlib.h>
#include <stdio.h>

/*
  Datos de los autores
*/


main()
{
	// Seccion de declaracion e inicializacion de variables
	int edad = 0;
	int sexo = 0;
	int patologia = 0;
	
	int mujeres = 0;
	int totalEncuestados = 0;
	
	int varonesGripeA = 0;
	float porcentajeMujeres = 0.0;
	
	system("cls"); // Limpiar la consola
	
	printf("Edad: ");
	scanf("%d", &edad);
	
	while ( edad != 0 )
	{
		printf("Sexo: ");
		scanf("%d", &sexo);
		
		printf("Patologia: ");
		scanf("%d", &patologia);
		
		totalEncuestados = totalEncuestados + 1;
		
		if (sexo == 2)
		{
			mujeres++;
			// igual que escribir mujeres = mujeres + 1;
		}
		
		
		if ( (sexo == 1) && (patologia == 2) )
		{
			varonesGripeA++;
		}
		
		
		printf("\n\n");
		printf("Edad: ");
		scanf("%d", &edad);
		
	} // while
	
	printf("\n\n");
	
	if ( totalEncuestados > 0 )
	{
		//porcentajeMujeres = (mujeres / totalEncuestados) * 100;
		porcentajeMujeres = (float) (mujeres * 100) / totalEncuestados;
		
		printf("Varones con Gripe A: %d", varonesGripeA);
		printf("\nPorcentaje Mujeres: %.2f", porcentajeMujeres);
	}
	else
	{
		printf("No se encuesto ningun paciente.");
	}
	
	
	
	
	printf("\n\n");	
	system("pause");
}
