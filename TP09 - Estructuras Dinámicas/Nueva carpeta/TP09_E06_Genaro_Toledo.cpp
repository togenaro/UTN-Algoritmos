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
	int numA;
	char tel[20], rec;
	nodo *sig;
}

*frente = NULL, *fondo = NULL;

void showyd(int &C)
{
	system("cls");
	
	nodo *nodos=frente;
	
	int i=0;
	
	while(nodos!=NULL)
	{
		i++;
		if(nodos->rec=='T')C++;
		
		if(i==1)
		{
			printf("Proxima atencion: \n\n");
		}
		
		printf("Cliente N%d:\t%-9d\t%-20s\t%c\n",i,nodos->numA,nodos->tel,nodos->rec);
			
		nodos=nodos->sig;
	}
	
	printf("\n\n");
	system("pause");
	system("cls");
	
	frente=frente->sig;
	
	delete(nodos);
}

void insertRec()
{
	char o;
	int B=1;
	nodo *nodoNew;
	nodoNew = new(nodo);
	nodoNew->sig=NULL;
	printf("NUMERO DE ATENCION: ");
	scanf("%d", &nodoNew->numA);
	_flushall();
	printf("TELEFONO: ");
	gets(nodoNew->tel);
	
	if(nodoNew != NULL)
	{
		do
		{
			printf("TIPO DE RECLAMO(Tecnico, Compra o Facturacion | T, C o F): ");
			scanf("%c", &o);
			
			if(o == 't' || o == 'T')
			{
				nodoNew->rec='T';
				B=1;
			}
			
			else if(o == 'c' || o == 'C')
			{
				nodoNew->rec='C';
				B=1;
			}
			
			else if(o == 'f' || o == 'F')
			{
				nodoNew->rec='F';
				B=1;
			}
			else
			{
				B=0;
				printf("Ingrese correctamente el tipo de atencion!\n");
			}
			
		_flushall();
		
		}
		while(B==0);
		
		if(frente==NULL)
		{
			frente=nodoNew;
		}
		else
		{
			fondo->sig=nodoNew;
		}
		
		fondo=nodoNew;
	}
	
	printf("\n");
}

main()
{
	system("color F0");
	int C = 0;
	int N = 0;
	
	printf("INGRESE CANTIDAD DE RECLAMOS: ");
	scanf("%d", &N);
	system("cls");
	
	for(int i=0; i<N; i++)
	{
		printf("RECLAMO %d\n", i+1);
		insertRec();
	}
	
	for(int i=0;i<N;i++)
	{
		showyd(C);
	}
	
	float p;
	
	p = ( (float)C / (float)N )* 100;
	
	printf("El porcentaje de atenciones por problemas tecnico fue de %.2f .\n\n",p);
	
	system("pause");
}
