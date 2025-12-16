/*
Universidad Tecnológica Nacional
	Facultad Regional Tucumán
	Ingeniería en Sistemas de Información
	
Algoritmos y Estructuras de Datos

Integrantes:

            44030752 - Toledo, Genaro
            44367714 - Saavedra, Mariana	
            44920917 - Sánchez, Aldana			
            44479000 - Tula, Esteban
            44703749 - Sánchez, Lautaro
            44814073 - Soria, Julián
			   
Comisión:
			-- 1K06 --
*/   

// -----------------
#include <stdio.h>
#include <stdlib.h>
// -----------------

int ingresarOrden(int f01_N)
{
	
	// --------------------
	float f01_Nfloat = 0.0;
	// --------------------
	
	// --------------------------------------------------------------
	do
	{
		do
		{
			system("cls");
			printf("INGRESE EL VALOR DE ORDEN DEL VECTOR: ");
			scanf("%f", & f01_Nfloat);
		
			f01_N = f01_Nfloat;	
			f01_Nfloat = f01_Nfloat - f01_N;
							
			if ((f01_Nfloat > 0) or (f01_Nfloat < 0))
			{
				system("cls");
				printf("Valor incorrecto. Ingrese nuevamente.\n\n");
				system("pause");
			}		
		}
		while ((f01_Nfloat > 0) or (f01_Nfloat < 0));
	
		if (f01_N <= 0)
		{
			system("cls");
			printf("Valor incorrecto. Ingrese nuevamente.\n\n");
			system("pause");	
		}
		
	}
	while (f01_N <= 0);
	// --------------------------------------------------------------
	
	return f01_N;
	
} // Cierre función

void ingresarSubIndices(int* f02_vector, int* f02_vectorCopia, int f02_N)
{
	
	// ------------------------
	int subIndice = 0;
	float subIndiceFloat = 0.0;
	// ------------------------
	
	// ----------------------------------------------------------------
	for (int i=0; i<f02_N; i++)
	{
		do
		{
			system("cls");
			printf("INGRESE SUBINDICE [%d]: ", i);
			scanf("%f", & subIndiceFloat);
			
			subIndice = subIndiceFloat;
			subIndiceFloat = subIndiceFloat - subIndice;
			
			if ((subIndiceFloat > 0) or (subIndiceFloat < 0))
			{
				system("cls");
				printf("Valor incorrecto. Ingrese nuevamente.\n\n");
				system("pause");	
			}
			
		}
		while ((subIndiceFloat > 0) or (subIndiceFloat < 0));
		
		f02_vector[i] = subIndice; 
		f02_vectorCopia[i] = subIndice;
				
	} // Cierre for
	// ----------------------------------------------------------------
		
} // Cierre función

void mostrarSubIndices(int* f03_vector, /*int* f03_vectorCopia,*/ int f03_N)
{
	
	system("cls");
	printf("VALORES INGRESADOS: \n");
	
	for (int i=0; i<f03_N; i++)
	{	
		printf("\n");
		printf("SUBINDICE [%d]: %d", i, f03_vector[i]);
	}
	
	printf("\n\n");
	system("pause");
	
	/*printf("\n\n");
	system("pause");
	printf("\n");
	
	printf("VALORES INGRESADOS (VECTOR COPIA) \n");
	
	for (int i=0; i<f03_N; i++)
	{	
		printf("\n");
		printf("SUBINDICE [%d]: %d", i, f03_vectorCopia[i]);
	}
	*/
		
} // Cierre función

void mostrarVectorOriginal(int* f04_vectorCopia, int f04_N)
{
	
	printf("VALORES INGRESADOS: \n");
	
	for (int i=0; i<f04_N; i++)
	{	
		printf("\n");
		printf("SUBINDICE [%d]: %d", i, f04_vectorCopia[i]);
	}
	
	printf("\n\n");
	system("pause");
	
} // Cierre función

// *****************METODOS**************************

void metodoBurbuja(int* f05_vector, int f05_N)
{
	
	// -----------
	int j = 0;
	int aux = 0;
	bool bandera;
	// -----------
	
	for(int i=1; i<f05_N; i++){
		bandera = false;
		for(j=f05_N-1; j>=i; j--){
			if (f05_vector[j-1] > f05_vector[j]){
				aux = f05_vector [j-1];
				f05_vector[j-1] = f05_vector[j];
				f05_vector[j] = aux;
				bandera = true;
			}
		}
		if(bandera==false) break;
	}
	
	printf("ORDEN ASCENDENTE:");
	
    for(int i=0; i<f05_N; i++)
    {
   		printf(" %d", f05_vector[i]);	
	}
	
	printf("\n\n");
	system("pause");
	
	printf("\nORDEN DESCENDENTE:");
	
	for(int i=(f05_N - 1); i>=0; i--)
	{
		printf(" %d", f05_vector[i]);
	}
		
} // Cierre función

void metodoInsercion(int* f06_vector, int f06_N)
{ 

	// --------	
	int ia = 0;
	int iv = 0;
	// --------
	
	for(int i=0; i<f06_N; i++)
	{
		ia = i;
		iv = f06_vector[i];
		
		while((ia > 0) && (f06_vector[ia-1] > iv))
		{
			f06_vector[ia] = f06_vector[ia-1];
			ia--;
		}
		f06_vector[ia] = iv;	
	}
	
	printf("ORDEN ASCENDENTE:");
	
    for(int i=0; i<f06_N; i++)
    {
   		printf(" %d", f06_vector[i]);	
	}
	
	printf("\n\n");
	system("pause");
	
	printf("\nORDEN DESCENDENTE:");
	
	for(int i=(f06_N - 1); i>=0; i--)
	{
		printf(" %d", f06_vector[i]);
	}
	
} // Cierre funcion

void metodoSeleccion(int* f07_vector, int f07_N)
{
	
	// ---------
	int i = 0;
	int j = 0;
	int aux = 0;
	int min = 0;
	// ---------
	
	for(i=0; i<f07_N; i++)
	{
		min = i;
		
		for(j=i+1; j<f07_N; j++)
		{
			if (f07_vector[j] < f07_vector[min])
			{
				min = j;
			}
		}
			
		aux = f07_vector[i];
		f07_vector[i]= f07_vector[min];
		f07_vector[min] = aux;
	}
	
	printf("ORDEN ASCENDENTE:");
	
    for(int i=0; i<f07_N; i++)
    {
   		printf(" %d", f07_vector[i]);	
	}
	
	printf("\n\n");
	system("pause");
	
	printf("\nORDEN DESCENDENTE:");
	
	for(int i=(f07_N - 1); i>=0; i--)
	{
		printf(" %d", f07_vector[i]);
	}
	
} // Cierre función

void metodoQuicksort(int* f08_vector, int izq, int der)
{
	
	// ----------
	int i = 0;
	int j = 0;
	int p = 0;
	int tmp = 0;
	// ----------
	
	i = izq;
	j = der;
	p = f08_vector[(izq + der) / 2];
		
	while(i <= j)
	{	
	
		while(f08_vector[i]<p)i++;
		while(f08_vector[j]>p)j--;
		
		if(i <= j)
		{
			tmp = f08_vector[i];
			f08_vector[i] = f08_vector[j];
			f08_vector[j] = tmp;
			i++; j--;	
		}
			
	}
	
	if(izq<j)
		metodoQuicksort(f08_vector,izq,j);
		
		if(i<der)
		{
			metodoQuicksort(f08_vector,i,der);	
		}
		
} // Cierre función

void metodoMergesort(int* f09_vector, int izq, int der)
{
	
	// ----------
    int mid = 0;
    // ----------
    
    if (izq < der)
	{	
	
        mid = (izq + der) / 2;
        metodoMergesort(f09_vector, izq, mid);
        metodoMergesort(f09_vector, mid + 1, der);
        
	    int c[der + 1];
	    int i = 0;
	    int j = 0;
	    int k = 0;
	    
	    // ---------
	    i = izq;
	    k = izq;
	    j = mid + 1;
	    // ----------
	    
	    while (i<=mid && j<=der)
		{
	        if (f09_vector[i] < f09_vector[j])
			{
	            c[k] = f09_vector[i];
	            k++;
	            i++;
	        }
	        else 
			{
	            c[k] = f09_vector[j];
	            k++;
	            j++;
	        }
	    }
	    
	    while (i <= mid)
		{
	        c[k] = f09_vector[i];
	        k++;
	        i++;
	    }
	    
	    while (j <= der)
		{
	        c[k] = f09_vector[j];
	        k++;
	        j++;
	    }
	    
	    for (i=izq; i<k; i++)
		{
	        f09_vector[i] = c[i];
	    } 
		 
	} // Cierre if
	
} // Cierre función

// ******************************************************

void menu(int* f10_vector, int* f10_vectorCopia, int f10_N)
{
	
	// -------------------
	int opcion = 0;
	float opcionFloat = 0;
	// -------------------
	
	while (opcion != 6)
	{
		
		do
		{
			system("cls");
			printf("MENU DE OPCIONES: \n\n");
		
			printf("OPCION 1: Intercambio o burbuja mejorada.");
			printf("\nOPCION 2: Insercion o metodo de la baraja.");
			printf("\nOPCION 3: Seleccion o metodo sencillo.");
			printf("\nOPCION 4: Rapido o QuickSort.");
			printf("\nOPCION 5: Por mezcla o MergeSort.");
			printf("\nOPCION 6: Salir.");
		
			printf("\n\nSELECCIONE UNA OPCION: ");
			scanf("%f", & opcionFloat);
		
			opcion = opcionFloat;
			opcionFloat = opcionFloat - opcion;
			
			if (opcionFloat > 0)
			{
				system("cls");
				printf("Opcion incorrecta. Ingrese nuevamente.\n\n");
				system("pause");	
			}
			
		}
		while (opcionFloat > 0);
	
		switch(opcion)
		{ 
			case 1:
					{
						system("cls");
						printf("OPCION 1: INTERCAMBIO O BURBUJA MEJORADA.");
						printf("\n\n");
						mostrarVectorOriginal(f10_vectorCopia, f10_N);
						printf("\n");
						metodoBurbuja(f10_vector, f10_N);
						printf("\n\n");
						system("pause");
						break;
					}
			case 2:
					{
						system("cls");
						printf("OPCION 2: INSERCION O METODO DE LA BARAJA.");
						printf("\n\n");
						mostrarVectorOriginal(f10_vectorCopia, f10_N);
						printf("\n");
						metodoInsercion(f10_vector, f10_N);
						printf("\n\n");
						system("pause");
						break;
					}
			case 3:
					{
						system("cls");
						printf("OPCION 3: SELECCION O METODO SENCILLO.");
						printf("\n\n");
						mostrarVectorOriginal(f10_vectorCopia, f10_N);
						printf("\n");
						metodoSeleccion(f10_vector, f10_N);
						printf("\n\n");
						system("pause");
						break;
					}
			case 4:
					{
						int izquierda = 0;
						int derecha = 0;
	
						derecha = (f10_N - 1);
						
						system("cls");
						printf("OPCION 4: RAPIDO O QUICKSORT.");
						printf("\n\n");
						mostrarVectorOriginal(f10_vectorCopia, f10_N);
						metodoQuicksort(f10_vector, izquierda, derecha);
						
						// Mostrar ordenamiento en forma ascendente
							printf("\nORDEN ASCENDENTE:");
						    for(int i=0; i<f10_N; i++)
						    {
						   		printf(" %d", f10_vector[i]);	
							}
							
							printf("\n\n");
							system("pause");
							
						// Mostrar ordenamiento en forma descendente
							printf("\nORDEN DESCENDENTE:");
							for(int i=(f10_N - 1); i>=0; i--)
							{
								printf(" %d", f10_vector[i]);
							}
						
						printf("\n\n");
						system("pause");
						break;
					}
			case 5:
					{
						int izquierda = 0;
						int derecha = 0;
						
						derecha = (f10_N - 1);
						
						system("cls");
						printf("OPCION 5: POR MEZCLA O MERGESORT.");
						printf("\n\n");
						mostrarVectorOriginal(f10_vectorCopia, f10_N);
						metodoMergesort(f10_vector, izquierda, derecha);
						
						// Mostrar ordenamiento en forma descendente
						printf("\nORDEN ASCENDENTE:");
						for(int i=0; i<f10_N; i++)
						{
						  	printf(" %d", f10_vector[i]);	
						}
							
						printf("\n\n");
						system("pause");
							
						// Mostrar ordenamiento en formaascendente	
						printf("\nORDEN DESCENDENTE:");							
						for(int i=(f10_N - 1); i>=0; i--)
						{
							printf(" %d", f10_vector[i]);
						}
						
						printf("\n\n");
						system("pause");
						break;
					}
			case 6:
					{
						system("cls");
						printf("Finalizando...");
						printf("\n\n");
						system("pause");
						break;
					}
			default:
					{
						system("cls");
						printf("Opcion incorrecta. Ingrese nuevamente");
						printf("\n\n");
						system("pause");
						break;
					}
					
		} // Cierre switch
		
	} // Cierre while (opcion)
	
} // Cierre función

main()
{
	system("color 0F");
	
	// --------------------------
	int N = 0;
	N = ingresarOrden(N); 
	
	int vector[N] = {0}; // Declaración e inicializacion del vector original
	int vectorCopia[N] = {0}; // Declaración e inicializacion de la copia del vector original
	// --------------------------
	
	// ----------------------------------------
	ingresarSubIndices(vector, vectorCopia, N);
	mostrarSubIndices(vector, /*vectorCopia,*/ N);
	// ----------------------------------------
	
	// --------------------------
	menu(vector, vectorCopia, N);
	// --------------------------
				
} // CIERRE MAIN
