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
	int codigo;
	char descripcion[20];
	int stock;
	float precio;
};

main()
{
	system("color F0");
	
	Datos v[30];
	
	int Buscar = 0;
	int Comp = 1;
	int Cont = 0;
	int b = 0;
	int N = 0;
	int i = 0;
	int M = 0;
	int j = 0;
	int aux2 = 0;
	int aux3 = 0;
	float aux4 = 0.0;
	char aux1[20];
	
	printf("INGRESE CANTIDAD DE PRODUCTOS: ");
	scanf("%d", &N);
	for(i=0; i<N; i++)
	{
		printf("\nCODIGO: ");
		scanf("%d", &v[i].codigo);
		printf("DESCRIPCION: ");
		_flushall();
		gets(v[i].descripcion);
		printf("STOCK: ");
		scanf("%d", &v[i].stock);
		printf("PRECIO UNITARIO: ");
		scanf("%f", &v[i].precio);
	}
	
	printf("\n---BUSQUEDA DEL PRODUCTO---");
	printf("\n\nINGRESE CODIGO A BUSCAR: ");
	scanf("%d", &Buscar);
	
    for(i=0; i<	N; i++)
    {
    	if (Buscar==v[i].codigo)
    	{
    		printf("\nELIMINAR PRODUCTO (1:SI|2:NO): ");
    		scanf("%d", &M);
    		
    		if (M==1)
    		{
    		
    			for (j=i ; j<N; j++)
    			{		
    				v[j].codigo=v[j+1].codigo;
    				strcpy(v[i].descripcion,v[i+1].descripcion);
    				v[j].stock=	v[j+1].stock;
    				v[j].precio=v[j+1].precio;
    					
    				if(Cont==0)
    				{
    					N=N-1;
    				}
    					
    				Cont++;
    			}
    		}
    	}
    		
    }
    	
   	do
	{
		b=0;
		
    	for(i=0; i<N-1; i++)
		{	
			if((strcmp(v[i+1].descripcion, v[i].descripcion))>0)
			{
				strcpy(aux1,v[i].descripcion);
				strcpy(v[i].descripcion,v[i+1].descripcion);
				strcpy(v[i+1].descripcion, aux1);
				aux2=v[i].codigo;
				v[i].codigo=v[i+1].codigo;
				v[i+1].codigo=aux2;
				aux3=v[i].stock;
				v[i].stock=v[i+1].stock;
				v[i+1].stock=aux3;
				aux4=v[i].precio;
				v[i].precio=v[i+1].precio;
				v[i+1].precio=aux4;
				b=1;
			}
		}
		
	}
	while(b==1);
		
	printf("\n\n---ORDENAMIENTO ALFABETICO DECRECIENTE---\n");
		
	for(i=0; i<N; i++)
	{
		printf("\nCODIGO: %d", v[i].codigo);
		printf("\nDESCRIPCION: %s", v[i].descripcion);
		printf("\nSTOCK: %d", v[i].stock);
		printf("\nPRECIO %.2f", v[i].precio);
	}
	
	do
	{
		b=0;
		
		for(i=0; i<N-1; i++)
		{
			if(v[i].stock > v[i+1].stock)
			{
				strcpy(aux1, v[i].descripcion);
				strcpy(v[i].descripcion, v[i+1].descripcion);
				strcpy(v[i+1].descripcion, aux1);
				aux2=v[i].codigo;
				v[i].codigo=v[i+1].codigo;
				v[i+1].codigo=aux2;
				aux3=v[i].stock;
				v[i].stock=v[i+1].stock;
				v[i+1].stock=aux3;
				aux4=v[i].precio;
				v[i].precio=v[i+1].precio;
				v[i+1].precio=aux4;
				b=1;
			}
		}
	}
	while(b==1);
		
	printf("\n\n---ORDENAMIENTO CRECIENTE DE STOCK---\n");
	for(i=0; i<N; i++)
	{
		printf("\nCODIGO: %d", v[i].codigo);
		printf("\nDESCRIPCION: %s", v[i].descripcion);
		printf("\nSTOCK: %d", v[i].stock);
		printf("\nPRECIO %.2f", v[i].precio);
	}	
		
	printf("\n\n");
    system("pause"); 
}
    

