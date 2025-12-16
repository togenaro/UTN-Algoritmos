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
#include <iostream>

typedef char string[80];

struct Registro
{
	string programa;
	int lineas;
};

struct Nodo
{
	Registro info;
	Nodo *sig;	
};

void menu();
void NuevoNodo(Nodo *&tope);
void ListarPila(Nodo *&tope);
void BorrarNodo(Nodo *&tope);
void VaciarPila(Nodo *&tope);

main()
{
	system("color F0");

	menu();	
}

void menu()
{
	Nodo *pila;
	pila = NULL; // el tope es null
	
	int opcion = 0;
	do
	{
		system("cls");
		printf("--MENU--");
		printf("\n\n1- INSERTAR NODO EN PILA.");
		printf("\n2- LISTAR PILA DE NODOS.");
		printf("\n3- BORRAR ULTIMO NODO.");
		printf("\n\n4- SALIR.");
		
		printf("\n\nINGRESE UNA OPCION: ");
		scanf("%d", &opcion);
		
		switch( opcion )
		{
			case 1: { NuevoNodo(pila); break; }
			case 2: { ListarPila(pila); break; }
			case 3: { BorrarNodo(pila); break; }
			case 4:
					{
						VaciarPila(pila);
						system("cls");
						printf("Finalizando...");
						printf("\n\n");
						system("pause");
						exit(EXIT_SUCCESS);
						break;
					}
			default: 
					{
						system("cls");
						printf("Opcion incorrecta. Ingrese nuevamente...");
						printf("\n\n");
						system("pause");
						system("cls");
						break;
					}			
		}
	}
	while (opcion > 1 || opcion < 4);
}

void NuevoNodo(Nodo *&tope)
{
	Registro Reg;

	system("cls");
	printf("--NUEVO NODO--");
	
	printf("\n\nINGRESE NOMBRE DEL PROGRAMA: ");
	_flushall();
	gets(Reg.programa);	
	
	printf("INGRESE CANTIDAD DE LINEAS: ");
	scanf("%d", &Reg.lineas);
		
	Nodo *pointer; // declarar puntero para trabajar con el/los nodo/s
	pointer = new Nodo; // puntero apunta a un nuevo nodo creado
	
	if (pointer != NULL) 
	{
		pointer->info = Reg; // p apunta a "info" del nodo y le asigna la informacion del registro
		pointer->sig = tope; // p apunta a "sig" del nodo y le asigna el valor del tope
		
		tope = pointer; // el tope toma el valor del nuevo nodo creado
	}
	else
	{
		system("cls");
		printf("Error. No hay suficiente memoria para crear un nuevo nodo...");
		printf("\n\n");
		system("pause");
	}
	
	printf("\n\nEl nodo fue ingresado exitosamente...");
	printf("\n\n");
	system("pause");
}

void ListarPila(Nodo *&tope)
{
	system("cls");
	printf("--PILA DE NODOS--");
	
	Nodo *pointer;
	
	pointer = tope; // el puntero toma el valor del tope
	while (pointer != NULL) // se repite hasta que el tope sea NULL, o sea, no hay mas nodos
	{
		// procesar el nodo actual
		printf("\n\n%s", pointer->info.programa);
		printf("\n%d", pointer->info.lineas);
		pointer = pointer->sig; // el puntero toma el valor del siguiente nodo, o sea, la siguiente direccion de mem
	}
	
	printf("\n\n");
	system("pause");	
}

void BorrarNodo(Nodo *&tope)
{
	Registro Reg;
	
	Nodo *pointer;
	
	if (tope != NULL)
	{
		pointer = tope; // asignar al puntero direccion del tope de la pila
		
		Reg = pointer->info; // asignar al registro la informacion del siguiente nodo 
		
		tope = tope->sig; // asignar al tope la direccion del siguiente nodo
		
		delete pointer; // borrar direccion actual del puntero
		
		system("cls");
		printf("Nodo superior borrado exitosamente.");
		printf("\n\n");
		system("pause");
	}
	else
	{
		system("cls");
		printf("No se ha borrado ningun nodo. La pila esta vacia...");
		printf("\n\n");
		system("pause");
	}	
}

void VaciarPila(Nodo *&tope)
{
	system("cls");
	printf("--VACIAR PILA--\n");
	Nodo *pointer;
	
	while (tope != NULL)
	{
		pointer = tope;
		
		printf("\nEliminando elemento... (%s - %d)", pointer->info.programa, pointer->info.lineas);
		tope = tope->sig;
		
		delete pointer;
	}
	
	tope = NULL;
	
	printf("\n\n");
	system("pause");	
}


