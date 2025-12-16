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
#include <string.h>

typedef char cadena[100];

struct datosCliente
{
	int codCli; //código del cliente
	char ApeNom[40]; //apellido y nombre
	char dire[60]; //domicilio particular
	float monCred; //Monto máximo del crédito que puede realizar en cada compra.
};

void cargaDatos(datosCliente *f01_reg, int &f01_cantidadClientes)
{
	cadena centinela;
	int i = 0;
	
	// ------------------------------------------------------------------------
	do
	{
		system("cls");
		
		printf("CODIGO DEL CLIENTE: ");
		scanf("%d", & f01_reg[i].codCli);
		
		printf("APELLIDO Y NOMBRE: ");
		_flushall();
		gets(f01_reg[i].ApeNom);
		
		printf("DOMICILIO: ");
		_flushall();
		gets(f01_reg[i].dire);
		
		printf("LIMITE DE CREDITO: ");
		scanf("%f", & f01_reg[i].monCred);
		
		f01_cantidadClientes++;
		
		printf("\nDESEA INGRESAR OTRO CLIENTE? (SI|NO): ");
		_flushall();
		gets(centinela);	
		
		i++;	
	}
	while ((strcmp(centinela, "NO") != 0) and (strcmp(centinela, "no") != 0));
	// ------------------------------------------------------------------------
	
	system("cls");	
}

void mostrarClientes(datosCliente *f02_reg, int f02_cantidadClientes)
{	
	// ----------------------------------------------------
	for (int i=0; i<f02_cantidadClientes; i++)
	{
		printf("CLIENTE [%d]\n\n", i+1);
		printf("Codigo del cliente: %d", f02_reg[i].codCli);
		
		printf("\nApelido y nombre: ");
		puts(f02_reg[i].ApeNom);
		
		printf("Domicilio: ");
		puts(f02_reg[i].dire);
		
		printf("Margen: %.2f", f02_reg[i].monCred);
		printf("\n\n");
	}
	// ----------------------------------------------------	
}

void calculoMonto(datosCliente *f03_reg, int f03_cantidadClientes)
{
	int cantidad30000 = 0;
	
	// ----------------------------------------------------
	for (int i=0; i<f03_cantidadClientes; i++)
	{
		if (f03_reg[i].monCred > 30000)
		{
			cantidad30000++;
		}
	}	
	// ----------------------------------------------------
	
	printf("Cliente/s con monto de credito superior a 30000: %d", cantidad30000);
	printf("\n\n");
	system("pause");
}

main()
{	
	system("color F0");
	
	int cantidadClientes = 0;
	datosCliente reg[100];

	// ------------------------------------
	cargaDatos(reg, cantidadClientes);
	mostrarClientes(reg, cantidadClientes);
	calculoMonto(reg, cantidadClientes);
	// ------------------------------------
}
