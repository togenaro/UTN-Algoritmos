/*
Universidad Tecnológica Nacional
Facultad Regional Tucumán
Ingeniería en Sistemas de Información

Algoritmos y Estructuras de Datos

Integrantes:
            
            44030752 - Genaro Toledo
*/        
/*
Un Comerciante tributa semestralmente un impuesto provincial a las retenciones de los
ingresos brutos; que es el 5% del total de las Ventas realizada en cada mes. Se conoce el Total
de las Ventas de cada uno de los meses y el Total de Gastos que tuvo en cada mes. Determinar si tuvo o no
ganancia en un Semestre. Mostrando el monto de la ganancia como el monto
de la perdida si hubo. En caso de no haber ganancia o pérdida indicar por medio de un mensaje.
*/

// -----------------------------------------------------------------------------

#include<stdlib.h>
#include<stdio.h>

// -----------------------------------------------------------------------------

// -----------------------------------------------------------------------------

main()

{ // Apertura main
	
// -----------------------------------------------------------------------------
	
	int x = 0;
	int totalVentas = 0;
	int totalGastos = 0;
	int gastosMes = 0;
	int contador_Gastos = 0;
	
	float retencion = 0;
	float ingreso = 0;
	float ingresoNeto = 0;
	float ganancias = 0;
	
// -----------------------------------------------------------------------------	
	
	while (x < 6)
	
	{ // Apertura while principal
		
		x = x + 1;
		totalVentas = 0;
		
		// -----------------------------------------------------------------------------	
		
		do
		
		{
			
			system("cls");
			printf("Ingrese el total de ventas del mes %d: ", x);
			scanf("%d", & totalVentas);	
			
			if (totalVentas < 0)
			
			{
				
				printf("\n\nValor incorrecto.\n");
				system("pause");
				system("cls");
				
			}
			
		}
		
		while (totalVentas < 0 );
			
		// -----------------------------------------------------------------------------	
		
		// -----------------------------------------------------------------------------	
		
		do
		
		{
			
				printf("Ingrese el total de gastos del mes %d: ", x);
				scanf("%d", & gastosMes);
				system("pause");	
			
			if (gastosMes < 0)
			
			{
				
				printf("\n\nValor incorrecto.\n");
				system("pause");
				system("cls");
				
			}
			
		}
		
		while (gastosMes < 0 );
		
		// -----------------------------------------------------------------------------
		
		// -----------------------------------------------------------------------------
		
		retencion = totalVentas * 0.05; // Cálculo del impuesto al ingreso bruto
		
		/*
		system("cls");
		printf("la retencion es: %.2f\n", retencion);
		system("pause");
		*/
		
		ingreso = totalVentas - retencion;
		
		/*
		system("cls");
		printf("El ingreso es: %.2f\n", ingreso);
		system("pause");
		*/
		
		ingresoNeto = ingresoNeto + ingreso; // Cálculo del ingreso total del mes
		
		/*
		system("cls");
		printf("el ingreso total es: %.2f\n", ingresoNeto);
		system("pause");
		*/
		
		totalGastos = totalGastos + gastosMes;
		
		/*
		printf("el total de gastos es: %d\n", totalGastos);
		system("pause");
		*/
		
		
		
		// -----------------------------------------------------------------------------	
	
		// -----------------------------------------------------------------------------	
	
		
	} // Cierre while principal
	
	// -----------------------------------------------------------------------------
	
	// -----------------------------------------------------------------------------
	
	system("cls");
	printf("El total de ventas del semestre es: %.2f", ingresoNeto);
	printf("\nEl total de gastos del semestre es: %d\n", totalGastos);
	system("pause");
	
	// -----------------------------------------------------------------------------
	
	// -----------------------------------------------------------------------------
		
	ganancias = ingresoNeto - totalGastos;
	
	if (ganancias > 0)
	
	{
		
		system("cls");
		printf("HUBO GANANCIAS (%.2f)", ganancias);
		
	}
	
	else 
	
	{
		system("cls");
		printf("NO HUBO GANANCIAS (%.2f)", ganancias);
		
	}
	
	// -----------------------------------------------------------------------------
	
	
} // Cierre main
