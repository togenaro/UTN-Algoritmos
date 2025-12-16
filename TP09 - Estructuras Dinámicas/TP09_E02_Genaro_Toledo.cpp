#include <stdio.h>
#include <stdlib.h>

struct Registro 
{
	float valor;	
};

struct Nodo
{
	Registro info;
	Nodo *sig;	
};

void menu();
void NuevoNodo(Registro Reg, Nodo *&frente, Nodo *&fondo);
void ListarEstructura(Nodo *&frente);


main()
{
	menu();
}

void menu()
{
	Registro Reg;
	Nodo *frente;
	Nodo *fondo;
	
	frente = NULL;
	fondo = NULL;
	
	int opcion = 0;
	do
	{
		system("cls");
		printf("--MENU--");
		printf("\n\n1- NUEVO NODO.");
		printf("\n2- LISTAR NODOS.");
		printf("\n3- ORDENAR NODOS.");
		
		printf("\n4- BORRAR UN NODO.");		
		printf("\n\n4- SALIR.");
		
		printf("\n\nINGRESE UNA OPCION: ");
		scanf("%d", &opcion);
		
		switch( opcion )
		{
			case 1: { NuevoNodo(Reg, frente, fondo); break; }
			case 2: { ListarEstructura(frente); break; }
			case 3: { ; break; }
			case 4:
					{
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

void NuevoNodo(Registro Reg, Nodo *&frente, Nodo *&fondo)
{
	Nodo *pointer;
	
	system("cls");
	printf("--NUEVO NODO--");
	
	printf("\n\nINGRESE VALOR: ");
	scanf("%f", &Reg.valor);
	
	pointer = new(Nodo);
	
	if(pointer != NULL)
	{
		pointer->info = Reg; 
		pointer->sig = NULL;
		
		if(frente == NULL)
		{
			frente = pointer;
		}
		else
		{
			fondo->sig = pointer;
		}
		
		fondo = pointer;
		
		system("cls");
   		printf("El nodo fue cargado exitosamente...");
		printf("\n\n");
		system("pause");
	}
	else
	{
		printf("No se pudo insertar un nuevo nodo...");
		printf("\n\n");
		system("pause");
    } 
}

void ListarEstructura(Nodo *&frente)
{	
	Nodo *pointer;
	pointer = frente;
	  
	system("cls");
	printf("--LISTA DE NODOS--\n\n"); 
	            
	if (pointer != NULL)
	{
            
  	  while(pointer != NULL)
	  {
	  	  printf("%.2f  ", pointer->info.valor);
		  pointer = pointer->sig;
	  }
            
    }
    else
    {	
    	system("cls");
    	printf("La pila de nodos esta vacia...");
    }
    
    printf("\n\n");
    system("pause");
}

void EliminarNodoX(Nodo *frente)
{
	Nodo *pointer;
	pointer = frente;
	
	float X = 0.0;
	
	printf("INGRESE EL VALOR DEL NODO A ELIMINAR: ");
	scanf("%f", &X);
	
	if (pointer != NULL)
	{    
		while(pointer != NULL)
		{
			if(X == pointer->info)
			{
				printf("Se encontro el nodo");
				printf("\n\n");
				system("pause");
			}
		}        
    }
    else
    {	
    	system("cls");
    	printf("La pila de nodos esta vacia...");
    }
	
	
}











