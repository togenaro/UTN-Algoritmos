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

struct Datos
{
	char NomApe[30];
	char AnioIn[4];
	char AnioPro[4];
	int Antig;
};

void Antiguedad(Datos v[20], int N);
void BuscarNombre(Datos v[20], int N);

main()
{
	system("color F0");
	
	Datos v[20];
	char x[2];
	char Buscar[30];
	
    int d = 0;
	int i = 0;
	int FechaIngreso = 0;
	int FechaProceso = 0;
	
	do 
	{
		printf("INGRESE NOMBRE COMPLETO: ");
		_flushall();
		gets(v[i].NomApe);
		
		printf("\nINGRESE FECHA DE INGRESO: ");
		_flushall();
		gets(v[i].AnioIn);
		
		FechaIngreso = atoi(v[i].AnioIn);
		printf("\nINGRESE FECHA DE PROCESO: ");
		_flushall();
		gets(v[i].AnioPro);
		
	    FechaProceso = atoi(v[i].AnioPro);
		v[i].Antig = (FechaProceso-FechaIngreso);
		printf("%d", v[i].Antig);
		
		printf("\n\nINGRESAR NUEVO FORMULARIO (S: SI|N: NO): ");
		_flushall();
		gets(x);
		strlwr(x);
		
		if (strcmp(x,"s")==0)
		{
			i++;
		}
		
		if (i==19)
		{
			strcpy(x,"x");
		}
		printf("\n");
		
   }
   while (strcmp(x,"s" )==0 || strcmp(x,"si" )==0);
   
   int N = 0;
   N = i + 1;
   
   Antiguedad (v, N);
   BuscarNombre(v, N);
   
   printf("\n\n");
   printf("\nLista: ");
   printf("\nNOMBRE \t\tFECHA DE INGRESO \tFECHA DE PROCESO \t\tANTIGUEDAD: ");
   
   for ( i=0; i<N; i++)
   {
   		printf("\n%s \t%d Anios \t\t%d Anios \t\t\t%d Anios", v[i].NomApe, FechaIngreso, FechaProceso, v[i].Antig);
		printf("\n");	
   }
   
   printf("\n\n");
   system("pause");
}

void Antiguedad(Datos v[20], int N)
{
	int i;
	float Prom;
	for (i=0; i<N; i++)
	{
		int Total = v[i].Antig+Total;
		Prom=Total/N;
	}
	printf ("\n-----PROMEDIO DE HORAS DE ANTIGUEDAD: %.2f-----\n", Prom);
}

void BuscarNombre(Datos v[20], int N)
{
	char Buscar[20];
	int Comp = 1;
	int Cont = 0;
	
	printf("\nINGRESE NOMBRE A BUSCAR: ");
	gets(Buscar);
	
	for (int i=0; i<N; i++)
	{
		Comp=strcmp(v[i].NomApe,Buscar);
		
		if (Comp==0)
		{
			if (Cont==0)
			{
			printf("\n-----NOMBRE SOLICITADO----- ");
	        printf("\nNombre \t\tAntiguedad: ");
			}
			printf("\n%s", v[i].NomApe);
			printf("\t%d anios", v[i].Antig);
			Cont++;
		}
		Comp=1;	
	}
	
	if (Cont==0)
	{
		printf("\nError. No se encontro el nombre introducido.");
	}
}
