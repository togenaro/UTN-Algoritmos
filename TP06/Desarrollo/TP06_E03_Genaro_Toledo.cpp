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

void cargaDatos(cadena *f01_asignatura, int *f01_nroInscriptos, int f01_N)
{
	for (int i=0; i<f01_N; i++)
	{
		printf("INGRESE EL NOMBRE DE LA ASIGNATURA: ");
		_flushall();
		gets(f01_asignatura[i]);
		
		printf("INGRESE CANTIDAD DE ALUMNOS DE LA ASIGNATURA: ");
		scanf("%d", & f01_nroInscriptos[i]);
		printf("\n");
	}
}

int calculoMayorInscriptos(cadena *f02_asignatura, int *f02_nroInscriptos, int f02_N)
{
	int f02_aux = 0;
	int mayor = -999;
	
	for (int i=0; i<f02_N; i++)
	{
		if (f02_nroInscriptos[i] > mayor)
		{
			mayor = f02_nroInscriptos[i];			
			f02_aux = i;
		}
	}
	
	return f02_aux;
}

int busquedaAsignatura(cadena *f03_asignatura, int *f03_nroInscriptos, int f03_N)
{
	cadena busqueda;
	int f03_posicion = 0;
	int centinela = 0;
	
	printf("\n\n");
	system("pause");
	printf("\n\nINGRESE LA ASIGNATURA A ANALIZAR: ");
	_flushall();
	gets(busqueda);
	
	for (int i=0; i<f03_N; i++)
	{
		centinela = strcmp(f03_asignatura[i], busqueda);
		
		if (centinela == 0)
		{
			f03_posicion = i;
		}
	}
	
	return f03_posicion;
}

main()
{
	system("color F0");
	
	int N = 0;
	int posicion = 0;
	int aux = 0;
		
	printf("INGRESE LA CANTIDAD DE ASIGNATURAS: ");
	scanf("%d", & N);
	system("cls");
	
	cadena asignatura[N];
	cadena palabraMayor[1];
	int nroInscriptos[N];
	
	// -------------------------------------------------------
	
	cargaDatos(asignatura, nroInscriptos, N);
	
	// ----------------------------------------------------------
	
	aux = calculoMayorInscriptos(asignatura, nroInscriptos, N);
	
	printf("\nLa materia con mayor cantidad de alumnos inscriptos es: ");
	puts(asignatura[aux]);
	
	// ----------------------------------------------------------
	
	posicion = busquedaAsignatura(asignatura, nroInscriptos, N);
	printf("\nLa cantidad de alumnos inscriptos de la asignatura ingresada es: %d", nroInscriptos[posicion]);
	
	// ----------------------------------------------------------
	
	printf("\n\n");
	system("pause");
}
