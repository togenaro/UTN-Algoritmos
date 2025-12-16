/*
Universidad Tecnológica Nacional
Facultad Regional Tucumán
Ingeniería en Sistemas de Información

Algoritmos y Estructuras de Datos

Integrantes:
            
            44030752 - Genaro Toledo
*/        

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct nodo
{
	int edad;
	char apenom[25];
	char telefono[20];
	nodo *sig;
}

*frente = NULL;

void InsertarPila();
int MayorEdad();
void MostrarMayor(int X);

main()
{
	system("color F0");
	int N;
	
	printf("INGRESE CANTIDAD DE PACIENTES: ");
	scanf("%d", &N);
	
	for(int i=0;i<N;i++)
	{
		InsertarPila();
		printf("\n");
	}
	
	MostrarMayor(MayorEdad());
	
	printf("\n");
	system("pause");
}

void InsertarPila()
{
	nodo *nodoNew;
	nodoNew = new(nodo);
	
	system("cls");
	
	printf("--INGRESO DE DATOS--\n\n");
	printf("APELLIDO Y NOMBRE: ");
	_flushall();
	gets(nodoNew->apenom);

	printf("TELEFONO: ");
	_flushall();
	gets(nodoNew->telefono);
	
	printf("EDAD: ");
	scanf("%d", &nodoNew->edad);
	
	nodoNew->sig=frente;
	
	frente=nodoNew;
}

int MayorEdad()
{
	nodo *target; 
	target = frente;
	int r = 0;
	
	while(target != NULL)
	{
		if(target->edad>r)
		{
			r = target->edad;
		}
		target = target->sig;
	}
	return r;
}

void MostrarMayor(int X)
{
	nodo *pila;
	
	pila = frente;
	
	int i = 0;
	
	printf("--PACIENTE CON MAYOR EDAD--\n\n");
	
	while(pila!=NULL)
	{
		if(pila->edad==X)
		{
			i++;
			printf("Apellido y Nombre: %s",pila->apenom);
			printf("\nTelefono: %s", pila->telefono);
			printf("\nEdad: %d\n\n" ,pila->edad);
		}
		
		pila = pila->sig;
	}
}


