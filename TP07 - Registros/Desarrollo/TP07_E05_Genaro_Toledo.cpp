/*
Universidad Tecnológica Nacional
Facultad Regional Tucumán
Ingeniería en Sistemas de Información

Algoritmos y Estructuras de Datos

Integrantes:
            
            44030752 - Genaro Toledo
*/        

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct Fecha
{
	int dia;
	int mes;
	int anio;	
};

struct Datos
{
	char apeNom[60];
	int dni;
	Fecha ingreso;
	int ventaSemanal[5];	
};

void cargaEmpleados(Datos *reg, int N);
void cargaVentas(Datos *reg, int N, int *totalVentas);
void listarVentas(Datos *reg, int N, int *totalVentas);
void modificarDato(Datos *reg, int N, int *totalVentas);

main()
{
	system("color F0");
	
	int N = 0;
	printf("INGRESE CANTIDAD DE EMPLEADOS: ");
	scanf("%d", &N);	
	Datos reg[N];
	int totalVentas[N];
	
	cargaEmpleados(reg, N);
	cargaVentas(reg, N, totalVentas);
	listarVentas(reg, N, totalVentas);
	modificarDato(reg, N, totalVentas);
	listarVentas(reg, N, totalVentas);
}

void cargaEmpleados(Datos *reg, int N)
{
	system("cls");
	
	for(int i=0; i<N; i++)
	{
		printf("EMPLEADO: [%d]", i+1);
		printf("\nAPELLIDO Y NOMBRE: ");
		_flushall();
		gets(reg[i].apeNom);
		
		printf("DNI: ");
		scanf("%d", &reg[i].dni);
		
		printf("FECHA DE CONTRATO: ");
		printf("\n\tDIA: ");
		scanf("%d", &reg[i].ingreso.dia);
		printf("\tMES: ");
		scanf("%d", &reg[i].ingreso.mes);
		printf("\tANIO: ");
		scanf("%d", &reg[i].ingreso.anio);
		printf("\n\n");
	}
	
}
	
void cargaVentas(Datos *reg, int N, int *totalVentas)
{
	char busqueda[60];
	int centinela = 0;
	int suma = 0;

	for (int i=0; i<N; i++)
	{
		
		do
		{
			system("cls");
			printf("--REGISTRAR VENTA DEL EMPLEADO--\n\n");
			printf("APELLIDO Y NOMBRE DEL EMPLEADO: ");
			_flushall();
			gets(busqueda);
			centinela = strcmp(busqueda, reg[i].apeNom);
			if (centinela != 0)
			{
				system("cls");
				printf("El empleado no fue encontrado. Ingrese nuevamente.");	
				printf("\n\n");
				system("pause");
			}			
		}
		while(centinela != 0);
		
		if (centinela == 0)
		{
			printf("\nCANTIDAD DE VENTAS LUNES: ");
			scanf("%d", &reg[i].ventaSemanal[0]);
			printf("CANTIDAD DE VENTAS MARTES: ");	
			scanf("%d", &reg[i].ventaSemanal[1]);
			printf("CANTIDAD DE VENTAS MIERCOLES: ");	
			scanf("%d", &reg[i].ventaSemanal[2]);
			printf("CANTIDAD DE VENTAS JUEVES: ");	
			scanf("%d", &reg[i].ventaSemanal[3]);
			printf("CANTIDAD DE VENTAS VIERNES: ");	
			scanf("%d", &reg[i].ventaSemanal[4]);
		
			suma = reg[i].ventaSemanal[4] + reg[i].ventaSemanal[3] + reg[i].ventaSemanal[2] +reg[i].ventaSemanal[1] +reg[i].ventaSemanal[0];
			
			totalVentas[i] = suma;
		}
	
	}	
}

void listarVentas(Datos *reg, int N, int *totalVentas)
{
	system("cls");
	
	printf("---VENTAS DE LA SEMANA---\n\n");
	
	for (int i=0; i<N; i++)
	{
		printf("EMPLEADO: [%d]\n", i+1);
		printf("DOCUMENTO: %d\n", reg[i].dni);
		printf("APELLIDO Y NOMBRE: ");	
		puts(reg[i].apeNom);
		
		printf("\nCANTIDAD DE VENTAS LUNES: %d", reg[i].ventaSemanal[0]);
		printf("\nCANTIDAD DE VENTAS MARTES: %d", reg[i].ventaSemanal[1]);	
		printf("\nCANTIDAD DE VENTAS MIERCOLES: %d", reg[i].ventaSemanal[2]);	
		printf("\nCANTIDAD DE VENTAS JUEVES: %d", reg[i].ventaSemanal[3]);	
		printf("\nCANTIDAD DE VENTAS VIERNES: %d", reg[i].ventaSemanal[4]);	
		
		printf("\n\nTOTAL DE VENTAS: %d", totalVentas[i]);
	}
	
	printf("\n\n");
	system("pause");
}

void modificarDato(Datos *reg, int N, int *totalVentas)
{
	int suma = 0;
	int busqueda = 0;
	int monto = 0;
	char dia[60];
	
	printf("\n---MODIFICACION DE DATOS DE VENTAS---\n\n");
	
	for (int i=0; i<N; i++)
	{
		printf("INGRESE DNI DEL EMPLEADO: ");
		scanf("%d", &busqueda);
		
		if(busqueda == reg[i].dni)
		{
			printf("INGRESE EL DIA A MODIFICAR (con minusculas): ");
			_flushall();
			gets(dia);
			
			if( (strcmp(dia, "lunes")) == 0)
			{
				printf("INGRESE EL MONTO A CAMBIAR: ");
				scanf("%d", &monto);
				reg[i].ventaSemanal[0] = monto;	
			}
			else if( (strcmp(dia, "martes")) == 0)
			{
				printf("INGRESE EL MONTO A CAMBIAR: ");
				scanf("%d", &monto);
				reg[i].ventaSemanal[1] = monto;
			}
			else if( (strcmp(dia, "miercoles")) == 0)
			{
				printf("INGRESE EL MONTO A CAMBIAR: ");
				scanf("%d", &monto);
				reg[i].ventaSemanal[2] = monto;
			}
			else if( (strcmp(dia, "jueves")) == 0)
			{
				printf("INGRESE EL MONTO A CAMBIAR: ");
				scanf("%d", &monto);
				reg[i].ventaSemanal[3] = monto;
			}
			else if( (strcmp(dia, "viernes")) == 0)
			{
				printf("INGRESE EL MONTO A CAMBIAR: ");
				scanf("%d", &monto);
				reg[i].ventaSemanal[4] = monto;
			}	
			else 
			{
				system("cls");
				printf("Error de sintaxis.");
				printf("\n\n");
				system("pause");
				exit(-1);
			}
			
		}
		/*else
		{
			system("cls");
			printf("No se encontro el dni ingresado.");
			printf("\n\n");
			system("pause");			
			exit(-1);
		}*/
		
		suma = reg[i].ventaSemanal[4] + reg[i].ventaSemanal[3] + reg[i].ventaSemanal[2] +reg[i].ventaSemanal[1] +reg[i].ventaSemanal[0];	
		totalVentas[i] = suma;
	}
	
	
}









