/*
Universidad Tecnológica Nacional
Facultad Regional Tucumán
Ingeniería en Sistemas de Información

Algoritmos y Estructuras de Datos

Integrantes:
            
            44030752 - Genaro Toledo
*/     

/* 
Desarrolle el algoritmo donde un comerciante ingresa por teclado el código
de un artículo (el cual solo puede ser 1, 2, 3) y el total de venta realizadas para ese artículo en
el mes.

SE NECESITA SABER

	Cuál es el código y el monto del artículo que más vendió en el mes.
	Indicar el importe total vendido de los tres artículos.
	Mostrar el porcentaje venta que representa el artículo de mayor venta sobre el total de las ventas del mes.
	
*/ 

// -----------------------------------------------

#include<stdio.h>
#include<stdlib.h>

// -----------------------------------------------

main()

{ // Apertura main

// -----------------------------------------------
	const int cierre = 1;
	int siono = 0;

	int codigo = 0;
	int totalVenta = 0;
	
	int ventasArticulo1 = 0;
	int ventasArticulo2 = 0;
	int ventasArticulo3 = 0;
	
	float importeTotal = 0;
	float porcentajeVentas = 0;
	
	
// -----------------------------------------------
	// -----------------------------------------------
	
	do
	
	{ // Apertura do-while principal
		
		// -----------------------------------------------	
		
		do
		
		{
			
			system("cls");
			printf("Ingrese el codigo del articulo (1, 2 o 3): ");
			scanf("%d", & codigo);
			
			if ((codigo > 3) or (codigo <= 0))
			
			{
				
				printf("Codigo incorrecto.\n\n");
				system("pause");	
				
			}	
			
		}		
		
		while ((codigo > 3) or (codigo <= 0));
		
		// -----------------------------------------------
		
		// -----------------------------------------------
		
		do
		
		{
			
			printf("Ingrese el total de ventas del articulo en este mes: ");
			scanf("%d", & totalVenta);
			
			if (totalVenta < 0)
			
			{
			
				printf("El total de ventas debe ser un valor positivo.\n\n");
				system("pause");
				system("cls");
				
			}
		
		}
		
		while (totalVenta < 0);
		
		// -----------------------------------------------
		
		// -----------------------------------------------
		
		if (codigo == 1)
		
		{
			
			ventasArticulo1 = ventasArticulo1 + totalVenta;
			
		}
		
		else if (codigo == 2)
		
		{
			
			ventasArticulo2 = ventasArticulo2 + totalVenta;
			
		}
		
		else if (codigo == 3)
		
		{
			
			ventasArticulo3 = ventasArticulo3 + totalVenta;
			
		}
		
		// -----------------------------------------------
	
	system("cls");	
	printf("Desea ingresar otro articulo? (SI: 1||NO: CUALQUIER NUMERO): ");
	scanf("%d", & siono);	
			
	} // Cierre do-while principal
	
	while (siono == cierre);
	
	// -----------------------------------------------
	
	// -----------------------------------------------	
	
	importeTotal = ventasArticulo1 + ventasArticulo2 + ventasArticulo3;
	
	system("cls");
	printf("El importe total de ventas de los tres articulos es de: %.2f\n", importeTotal);
	
	// -----------------------------------------------	
	
	// -----------------------------------------------
	
		
	if ((ventasArticulo1 > ventasArticulo2) and (ventasArticulo1 > ventasArticulo3))
	
	{
		
		porcentajeVentas = (ventasArticulo1 / importeTotal) * 100;
		printf("\nEl codigo del articulo mas vendido es: 1");
		printf("\nla cantidad que se vendio de este articulo es: %d", ventasArticulo1);
		printf("\nEl porcentaje de ventas del articulo 1 sobre el total de ventas es: %.2f\n\n", porcentajeVentas);
		system("pause");
		
	}
	
	else if ((ventasArticulo2 > ventasArticulo1) and (ventasArticulo2 > ventasArticulo3))
	
	{
		
		porcentajeVentas = (ventasArticulo2 / importeTotal) * 100;
		printf("\nEl codigo del articulo mas vendido es: 2");
		printf("\nla cantidad que se vendio de este articulo es: %d", ventasArticulo2);
		printf("\nEl porcentaje de ventas del articulo 2 sobre el total de ventas es: %.2f\n\n", porcentajeVentas);
		system("pause");
		
	}
	
	else if ((ventasArticulo3 > ventasArticulo1) and (ventasArticulo3 > ventasArticulo2))
	
	{
		
		porcentajeVentas = (ventasArticulo3 / importeTotal) * 100;
		printf("\nEl codigo del articulo mas vendido es: 3");
		printf("\nla cantidad que se vendio de este articulo es: %d", ventasArticulo3);
		printf("\nEl porcentaje de ventas del articulo 3 sobre el total de ventas es: %.2f\n\n", porcentajeVentas);
		system("pause");
		
	}
	
	// -----------------------------------------------
	
	// -----------------------------------------------
	
	if ((ventasArticulo1 == ventasArticulo2) and (ventasArticulo1 == ventasArticulo3) and (ventasArticulo2 == ventasArticulo3))
	
	{
		
		printf("La cantidad vendida de los articulos 1, 2 y 3 es la misma.\n\n");
		system("pause");
		
	}
	
	else if ((ventasArticulo1 == ventasArticulo2) and (ventasArticulo1 != 0) and (ventasArticulo2 != 0))
	
	{
		
		porcentajeVentas = ((ventasArticulo1 + ventasArticulo2) / importeTotal) * 100;
		printf("\nLa cantidad vendida de los articulos 1 y 2 es la misma (%d)", ventasArticulo1);
		printf("\nEl porcentaje de ventas de los articulos 1 y 2 sobre el total de ventas es de: %.2f\n\n", porcentajeVentas);
		system("pause");
		
	}
	
	else if ((ventasArticulo1 == ventasArticulo3) and (ventasArticulo1 != 0) and (ventasArticulo3 != 0))
	
	{
		
		porcentajeVentas = ((ventasArticulo1 + ventasArticulo3) / importeTotal) * 100;
		printf("\nLa cantidad vendida de los articulos 1 y 3 es la misma (%d)", ventasArticulo3);
		printf("\nEl porcentaje de ventas de los articulos 1 y 3 sobre el total de ventas es de: %.2f\n\n", porcentajeVentas);
		system("pause");
		
	}
	
	else if ((ventasArticulo2 == ventasArticulo3) and (ventasArticulo2 != 0) and (ventasArticulo3 != 0))
	
	{
		
		porcentajeVentas = ((ventasArticulo2 + ventasArticulo3) / importeTotal) * 100;
		printf("\nLa cantidad vendida de los articulos 2 y 3 es la misma (%d)", ventasArticulo2);
		printf("\nEl porcentaje de ventas de los articulos 2 y 3 sobre el total de ventas es de: %.2f\n\n", porcentajeVentas);
		system("pause");
		
	}
	
	// -----------------------------------------------

} // Cierre main









































