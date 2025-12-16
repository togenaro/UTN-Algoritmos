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
#include <math.h>

struct Fecha
{
	int dia;
	int mes; 
	int anio;	
};

struct fabrica
{
    char expediente[30];
	char propietario[30];
	int metrocuadrados;
	int tipodeobra;
	Fecha fechaMonto;
	float monto;
	
};

void Montorecibido (fabrica v[30], int N);

main()
{
	system("color F0");
	fabrica v[30];
	int i=0, N;
	
	printf("INGRESE CANTIDAD DE EXPEDIENTES: ");
	scanf("%d", &N);
	system("cls");
	
	for(i=0; i<N; i++)
	{
		printf("INGRESE EXPEDIENTE: ");
		_flushall();
		gets(v[i].expediente);
		_flushall();
		printf("INGRESE NOMBRE DE PROPIETARIO: ");
		_flushall;
		gets(v[i].propietario);
		printf("INGRESE METROS CUADRADOS: ");
		scanf("%d", &v[i].metrocuadrados);
		while (v[i].tipodeobra!=0 && v[i].tipodeobra!=1 && v[i].tipodeobra!=2 && v[i].tipodeobra!=3)
		{
		printf("\n\n-----TIPOS DE OBRAS-----");
		printf("\n\n0: Viviendo Basica");
		printf("\n1: Viviendo de Lujo");
		printf("\n2: Edificio");
		printf("\n3: Predio Especial");
		printf("\n\nINGRESE TIPO DE OBRA: ");
		scanf("%d", &v[i].tipodeobra);
		if (v[i].tipodeobra!=0 && v[i].tipodeobra!=1 && v[i].tipodeobra!=2 && v[i].tipodeobra!=3)
		{
		printf("\n\nError. Valor incorrecto.\n\n");
		}
        }
        printf("\nINGRESE FECHA DE MONTO: ");
        printf("\n\tDIA: ");
        scanf("%d", &v[i].fechaMonto.dia);
        printf("\tMES: ");
        scanf("%d", &v[i].fechaMonto.mes);
        printf("\tANIO: ");
        scanf("%d", &v[i].fechaMonto.anio);
        printf("\nINGRESAR MONTO: ");
        scanf("%f", &v[i].monto);
        
        Montorecibido(v, N);
        system("cls");
        
	}
	    for(int i=0; i<N; i++)
	    {
	    printf("\nExpediente: %s", v[i].expediente);
        printf("\nPropietario: %s", v[i].propietario);
        printf("\nTipo de Obra: ");
        if (v[i].tipodeobra==0)
        {
        	printf("Vivienda Basica");
        }
        if (v[i].tipodeobra==1)
        {
        	printf("Vivienda de Lujo");
        }
        if (v[i].tipodeobra==2)
        {
        	printf("Edificio");
        }
        if (v[i].tipodeobra==3)
        {
        	printf("Predio Especial");
        }
        printf("Fecha de monto: ");
        printf("\n\tFecha de Monto: %d", v[i].fechaMonto.dia);
        printf("\n\tFecha de Monto: %d", v[i].fechaMonto.mes);
        printf("\n\tFecha de Monto: %d", v[i].fechaMonto.anio);
        printf("\n\tMonto: %.4f", v[i].monto );
        printf("\n\n");
        }
}

void Montorecibido(fabrica v[30], int N)
{
	system("cls");
	
	int i;
	for (i=0; i<N; i++)
	{
		printf("\n\nExpediente: %s", v[i].expediente);
		printf("\nFecha del monto: ");
		printf("\n\tDia: %d", v[i].fechaMonto.dia);
		printf("\n\tMes: %d", v[i].fechaMonto.mes);
		printf("\n\tAnio: %d", v[i].fechaMonto.anio);
		printf("\nMonto: %.4f\n\n", v[i].monto);
		printf("\n\n");
		system("pause");
	}
}
