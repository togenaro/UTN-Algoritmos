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

struct Notas
{
	float primerTrimestre;
	float segundoTrimestre;
	float tercerTrimestre;
	float promedio;
};

struct Fecha
{
	int dia;
	int mes;
	int anio;
};

struct Alumnos
{
	int dni;
	char apeNom[30];
	Fecha nacimiento;
	Notas nota;
};

main()
{
	system("color F0");
	
    Alumnos a[30];
    
    int N = 0;
	int c = 0;
	int sumaNotas = 0;
    
    printf("INGRESE CANTIDAD DE ALUMNOS: ");
    scanf("%d", &N);
    system("cls");
    
    for (int i=0; i<N; i++)
    {
    	printf("--ALUMNO: [%d]--", i+1);
    	printf("\nDNI: ");
    	scanf("%d", &a[i].dni);
    	
    	printf("APELLIDO Y NOMBRE: ");
    	_flushall();
    	gets(a[i].apeNom);
    	
    	printf("\nFECHA DE NACIMIENTO: ");
    	printf("\n\tDia: ");
    	scanf("%d", &a[i].nacimiento.dia);
    	printf("\tMes: ");
    	scanf("%d", &a[i].nacimiento.mes);
    	printf("\tAnio: ");
    	scanf("%d", &a[i].nacimiento.anio);
    	
    	printf("\nNOTAS TRIMESTRALES: ");
    	printf("\n\tNotas del Primer Trimestre: ");
    	scanf("%f", &a[i].nota.primerTrimestre);
    	printf("\tNotas del Segundo Trimestre: ");
    	scanf("%f", &a[i].nota.segundoTrimestre);
    	printf("\tNotas del Tercer Trimestre: ");
    	scanf("%f", &a[i].nota.tercerTrimestre);
    	
    	sumaNotas = (a[i].nota.primerTrimestre + a[i].nota.segundoTrimestre + a[i].nota.tercerTrimestre);
    	
    	a[i].nota.promedio = ((float)sumaNotas/3);
     
	    if(a[i].nota.promedio > 8)
	    {
	 		c++;
	    }   
        printf("\nLa cantidad de Alumnos con un promedio mayor a 8 es: %d", c);  
        printf("\n\n"); 
	}
    
    printf("\n\n");
    system("pause");
}
