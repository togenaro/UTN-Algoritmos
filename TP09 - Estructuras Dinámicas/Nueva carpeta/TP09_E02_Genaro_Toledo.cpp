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

struct nodo
{
	int legajo;
	int edad;
	char apenom[30];
	nodo *sig;
}

*lista = NULL;

void IngresoDatos();
void MostrarLista();
void BorrarNodo(int N);

main()
{
	int N;
	printf("INGRESE CANTIDAD DE EMPLEADOS A REGISTRAR: ");
	scanf("%d", &N);
	printf("\n\n");
	
	for(int i=0; i<N; i++)
	{
		printf("EMPLEADO %d", i+1);
		IngresoDatos();
		printf("\n");
	}
	
	system("cls");
	printf("--DATOS CARGADOS--\n\n");
	MostrarLista();
	printf("\nINGRESE LEGAJO PARA ELIMINAR INFORMACION: ");
	scanf("%d", &N);
	
	BorrarNodo(N);
	
	system("cls");
	
	printf("--LISTA ACTUALIZADA--\n\n");
	
	MostrarLista();
	
	system("pause");
}

void IngresoDatos()
{
	nodo *nodoNew,*nod,*no2;
	nodoNew = new(nodo);
	
	nod = lista;
	
	printf("\nLegajo: ");
	scanf("%d", &nodoNew->legajo);

	printf("APELLIDO Y NOMBRE: ");
	_flushall();
	gets(nodoNew->apenom);
	
	printf("EDAD: ");
	scanf("%d",&nodoNew->edad);
	
	nodoNew->sig=lista;
	lista = nodoNew;

}

void MostrarLista()
{
	nodo *nod = lista;
	
	while(nod!=NULL)
	{
		printf("Legajo: %d", nod->legajo);	
		printf("Apellido y Nombre: %s",nod->apenom);
		printf("Edad: %d\n",nod->edad);
		
		nod = nod->sig;
		
		printf("\n");
	}
}

void BorrarNodo(int N)
{
	nodo *nod,*nodA,*nodD;
	
	nod = lista;
	
	while(nod!=NULL && nod->legajo != N)
	{
		nodA = nod;
		nod = nod->sig;
		nodD = nod;
	}
	
	if(nodD != NULL)
	{
		nodA->sig = nodD->sig;
		delete(nodD);	
	}	
}


