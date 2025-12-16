/*
Universidad Tecnológica Nacional
Facultad Regional Tucumán
Ingeniería en Sistemas de Información

Algoritmos y Estructuras de Datos

Integrantes:
            
            44030752 - Genaro Toledo
*/        

#include<stdio.h>
#include<stdlib.h>

struct Registro 
{
	float dato;
};


struct Nodo
{
	Registro info;
	Nodo *sig;
};


int Menu()
{
	system("color F0");
	
	int opcion = 0;
	
	printf("--MENU--");
	
	printf("\n\n1- INSERTAR NODO");
	printf("\n2- LISTAR NODOS");
	printf("\n3- ORDENAR NODOS");
	printf("\n4- ELIMINAR NODO");
	printf("\n\n0- SALIR");
	printf("\n\nINGRESE UNA OPCION: ");
	scanf("%d", &opcion);
	
	return opcion;  
}



void InicializarLista(Nodo *&frente, Nodo *&fondo)
{
	frente = NULL;
	fondo = NULL;
}


void InsertarNodo(Nodo *&frente, Nodo *&fondo, float x)
{
	Nodo *aux;
	
	aux = new(Nodo);
	
	if (aux != NULL)
	{
		aux->info.dato = x;
		aux->sig = NULL;
		
		if (frente == NULL)
		{
			frente = aux; 
		}
		else
		{
			fondo->sig = aux;
		}
		
		fondo = aux;
		
	}
	else
	{
		printf("No se pudo insertar un nuevo nodo...");
		printf("\n\n");
		system("pause");
    } 
}


void RecorrerLista(Nodo *&frente)
{
	
	printf("Lista de Nodos\n\n");
	
	Nodo *aux;
	
	aux = frente;
	            
	if (aux != NULL)
	{
            
  	  while(aux != NULL)
	  {
	  	  //printf("\n%.2f", aux->info.dato);
	  	  printf("%.2f  ", aux->info.dato);
		  aux = aux->sig;
	  }
            
    }
    else
    {	
    	printf("La pila de nodos esta vacia...");
    }
	

}


void OrdenarLista(Nodo *&frente)
{ 
     Nodo *actual ,*siguiente;
     
     float aux; 
     
     actual = frente; 
     
     if (frente != NULL)
     {
       while(actual->sig != NULL)
        { 
           siguiente= actual->sig; 
         
           while ( siguiente != NULL )
            { 
                 
                if ( actual->info.dato > siguiente->info.dato )
                { 
					aux = siguiente->info.dato; 
					siguiente->info.dato = actual->info.dato;
					actual->info.dato = aux; 
				} 
                 
                 siguiente = siguiente->sig; 
            } 
                      
           actual = actual->sig; 
           siguiente = actual->sig; 
         
         } 
       
    } 
}                      


bool EliminarNodo(Nodo *&frente, float target)
{
	Nodo *actual;
    Nodo *anterior;
    
    actual = frente;
    
 	bool encontrado = false;
 	
 	
 	
    if ( frente != NULL )
    {
        while ( actual != NULL )
        {
            if (actual->info.dato == target)
            {	
                if ( actual == frente )
                {
                    frente = frente->sig;
                }
                else
                {
					anterior->sig = actual->sig;
                }					
                
  			    encontrado = true;
                
                delete(actual);		
                break;				
            }
            
            anterior = actual;
            actual = actual->sig;
            
        } 
        
    }
    else
    {
    	system("cls");
    	printf("La pila de nodos esta vacia...\n");
    }
    
    return encontrado;
} 


void EliminarLista(Nodo *&frente, Nodo *&fondo)
{
	Nodo *aux;
	
	while (frente != NULL)
	{
		aux = frente;	
		frente = frente->sig;		
   	    delete(aux);
	}
	
	fondo = NULL;
}



main()
{
   int opcion = 0;
   float numero = 0.0;   
   bool bandera = false;
      
   Nodo *frente, *fondo;
   InicializarLista(frente, fondo);
         
   do 
   {
      system("cls");
      opcion = Menu();    
      system("cls");
      
      switch ( opcion )
      {
             
        case 1: {
                  printf("--INSERTAR NODO--");
                  printf("\n\nINGRESE EL VALOR: ");
                  scanf("%f", &numero);
                  
                  InsertarNodo(frente, fondo, numero);                  
                  printf("\nSe inserto %.2f a la lista.", numero);                  
                  break;   
                }

        case 2: {
                  RecorrerLista(frente);
                  break;   
                }

        case 3: {
                  printf("Ordenar Lista\n");                  
                  OrdenarLista(frente);                  
                  printf("\nLa lista fue ordenada");             
                  break;   
                }

        case 4: {
             
                  printf("Eliminar Nodo\n");
                  printf("\nValor a eliminar: ");
                  scanf("%f", &numero);
                  
                  bandera = EliminarNodo(frente, numero);
                  
                  if ( bandera )
                  {
                      printf("\nSe elimino %.2f de la lista.", numero); 
                  }
                  else
                  {
                      printf("\n%.2f no se encontraba en la lista.", numero); 
                  }
             
                  break;   
                }
                
        case 0: {
                	system("cls");
                	printf("Finalizando...");
					printf("\n\n");
					system("pause");
					exit(EXIT_SUCCESS);                	
                }
              
        default:
				{
					system("cls");
					printf("Opcion incorrecta. Ingrese nuevamente...");
					printf("\n\n");
					system("pause");
                }              

      };
     
      printf("\n\n");               
      system("pause");
                 
   } while (opcion >= 0 || opcion <= 4);

   EliminarLista(frente, fondo);
}

