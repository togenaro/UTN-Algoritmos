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

typedef char cadena[80];

struct Fecha
{
	int dia;
	int mes;
	int anio;
};

struct datosCliente
{
	char apeNom[40];
	char dire[60];
	float monVehi;
	Fecha fecVenta;	
};

void cargaVentas(datosCliente *reg, int N);
void mostrarDatos(datosCliente *reg, int i);
void menorVenta(datosCliente *reg, int i);

main()
{
	system("color F0");
	int N = 0;
	
	printf("INGRESE CANTIDAD DE VENTAS DE LA SEMANA: ");
	scanf("%d", &N);

	datosCliente reg[N];
	cargaVentas(reg, N);
}

void cargaVentas(datosCliente *reg, int N)
{	
	int n = 0;
		
	for (int i=0; i<N; i++)
	{
		system("cls");
		printf("--VENTA NUMERO %d--\n\n", i+1);	
		printf("NOMBRE Y APELLIDO: ");
		_flushall();
		gets(reg[i].apeNom);
		
		printf("DOMICILIO: ");
		_flushall();
		gets(reg[i].dire);
		
		printf("MONTO DEL VEHICULO: ");
		scanf("%f", &reg[i].monVehi);
		
		printf("\nFECHA DE COMPRA: ");
		printf("\n\tDIA: ");
		scanf("%d", &reg[i].fecVenta.dia);
		printf("\tMES: ");
		scanf("%d", &reg[i].fecVenta.mes);
		printf("\tANIO: ");
		scanf("%d", &reg[i].fecVenta.anio);
		
		n++;
		
		mostrarDatos(reg, i);
		menorVenta(reg, i);
	}

}

void mostrarDatos(datosCliente *reg, int i)
{
	system("cls");
	int menor = 0;
	
	printf("--DATOS INGRESADOS--");
	
	for (int n=0; n<=i; n++)
	{
		printf("\n\nNOMBRE Y APELLIDO: ");
		_flushall();
		puts(reg[n].apeNom);
		
		printf("DOMICILIO: ");
		_flushall();
		puts(reg[n].dire);
		
		printf("MONTO DEL VEHICULO: %.2f", reg[n].monVehi);
		
		printf("\nFECHA DE COMPRA: ");
		printf("\n\tDIA: %d", reg[n].fecVenta.dia);
		printf("\n\tMES: %d", reg[n].fecVenta.mes);
		printf("\n\tANIO: %d\n", reg[n].fecVenta.anio);
					
	}
	
}

void menorVenta(datosCliente *reg, int n)
{
	int menor = 999999;
	
	for (int i=0; i<=n; i++)
	{
		if(reg[i].monVehi < menor)
		{
			menor = reg[i].monVehi;
		}	
	}

	printf("\n\nLa menor venta registrada es de: %d", menor);	
	printf("\n\n");
	system("pause");	
}







