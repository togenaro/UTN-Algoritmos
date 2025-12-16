#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fechaUltimaCompra
{
	int dia;
	int mes;
	int anio;
};

struct registro
{
	int codigo;
	char articulo[50];
	int cantMinima;
	fechaUltimaCompra fecha;
	int stock;
	float precio;
};

void cargaProductos(registro *reg, int &f01_N)
{
	do
	{
		printf("INGRESE CANTIDAD DE ARTICULOS: ");
		scanf("%d", & f01_N);
		
		if(f01_N < 10)
		{
			system("cls");
			printf("Error. La cantidad de productos tiene que ser mayor o igual a 10.");
			printf("\n\n");
			system("pause");
			system("cls");	
		}	
	}
	while (f01_N < 10);
	
	system("cls");
	for (int i=0; i<f01_N; i++)
	{
		printf("ARTICULO NUMERO %d\n\n", i+1);
				
		printf("\tCODIGO: ");
		scanf("%d", & reg[i].codigo);
				
		printf("\tDESCRIPCION: ");
		_flushall();
		gets(reg[i].articulo);
				
		printf("\tCANTIDAD MINIMA: ");
		scanf("%d", & reg[i].cantMinima);
				
		printf("\tFECHA DE ULTIMA COMPRA: \n");
		printf("\t\tDIA: ");
		scanf("%d", & reg[i].fecha.dia);
		printf("\t\tMES: ");
		scanf("%d", & reg[i].fecha.mes);
		printf("\t\tANIO: ");
		scanf("%d", & reg[i].fecha.anio);
				
		printf("\tSTOCK: ");
		scanf("%d", & reg[i].stock);
				
		printf("\tPRECIO: ");
		scanf("%f", & reg[i].precio);
		
		printf("\n\n");			
	}
}

void buscarProducto(registro *reg, int f02_N)
{
	int busqueda = 0;
	int bandera = 0;
	
	system("cls");
	printf("--BUSCAR ARTICULO--\n\n");
	printf("INGRESE EL CODIGO DEL ARTICULO: ");
	scanf("%d", & busqueda);
	
	do
	{
		for(int i=0; i<f02_N; i++)
		{
			if (reg[i].codigo == busqueda)
			{
				printf("\n\nARTICULO NUMERO %d", i+1);
				printf("\nDESCRIPCION: ");
				puts(reg[i].articulo);
				printf("STOCK ACTUAL: %d", reg[i].stock);
				printf("\nULTIMA COMPRA: %d-%d-%d", reg[i].fecha.dia, reg[i].fecha.mes, reg[i].fecha.anio);
				printf("\n\n\tACTUALIZAR STOCK: ");
				scanf("%d", & reg[i].stock);
				
				printf("\tACTUALIZAR FECHA: \n");
				printf("\t\tDIA: ");
				scanf("%d", & reg[i].fecha.dia);
				printf("\t\tMES: ");
				scanf("%d", & reg[i].fecha.mes);
				printf("\t\tANIO: ");
				scanf("%d", & reg[i].fecha.anio);
				
				printf("\n\nStock actualizado exitosamente.");
				printf("\n\n");
				system("pause");
				bandera++;
			}	
		}
		
		if (bandera == 0)
		{
			system("cls");
			printf("No se encontro el codigo ingresado. Ingrese nuevamente.");
			printf("\n\n");
			system("pause");
			system("cls");
		}		
	}
	while(bandera == 0);
}

void venta(registro *reg, int f03_N)
{
	int busqueda = 0;
	int cantidad = 0;
	float montoAPagar = 0;
	
	system("cls");
	printf("--VENTA DEL ARTICULO--\n\n");
	printf("INGRESE EL CODIGO DEL ARTICULO: ");
	scanf("%d", & busqueda);
	printf("\n");
	
	for(int i=0; i<f03_N; i++)
	{
		if(reg[i].codigo == busqueda)
		{
			do
			{
				printf("ARTICULO NUMERO: %d\n\n", i+1);
				printf("\tDESCRIPCION: ");
				puts(reg[i].articulo);
				printf("\tPRECIO: $%.2f\n", reg[i].precio);
				printf("\tCANTIDAD EN STOCK: %d", reg[i].stock);
			
			
				printf("\n\nINGRESE CANTIDAD A COMPRAR: ");
				scanf("%d", & cantidad);
				
				if(cantidad > reg[i].stock)	
				{
					system("cls");
					printf("Error. Cantidad ingresada excede al stock actual del producto.");
					printf("\n\n");
					system("pause");
					system("cls");
				}			
			}
			while(cantidad > reg[i].stock);
			
			montoAPagar = (float)cantidad * (float)reg[i].precio;	
		}	
		
	}
	
	printf("\nEl monto a pagar es de: $%.2f", montoAPagar);
	printf("\n\n");
	system("pause");	
}

void mostrarProductos(registro *reg, int f04_N)
{
	int bandera = 0;
	
	system("cls");
	printf("--PRODUCTOS CON STOCK MENOR A CANTIDAD MINIMA--");
	for (int i=0; i<f04_N; i++)
	{
		if(reg[i].cantMinima > reg[i].stock)
		{	
			printf("\n\nPRODUCTO NUMERO: %d\n\n", i+1);
			printf("\tCODIGO: %d\n", reg[i].codigo);
			printf("\tDESCRIPCION: ");
			puts(reg[i].articulo);
			printf("\tPRECIO: %.2f\n", reg[i].precio);
			printf("\tCANTIDAD MINIMA: %d\n", reg[i].cantMinima);
			printf("\tCANTIDAD EN STOCK: %d", reg[i].stock);
			
			bandera++;
			
			printf("\n\n");
			system("pause");
		}
		
	}
	
	if (bandera == 0)
	{
		printf("\n\nNingun producto posee stock menor a la cantidad minima.");
		printf("\n\n");
		system("pause");
	}
}

main()
{
	system("color F0");
	
	int N = 0;

	registro reg[N];
	
	cargaProductos(reg, N);
	buscarProducto(reg, N);
	venta(reg, N);
	mostrarProductos(reg, N);		
}
