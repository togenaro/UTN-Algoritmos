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

int cargaDatos(float *f01_vector)
{
	float Nfloat = 0;
	int i = 0;
	int c = 0;

		do
		{
			printf("INGRESE UN VALOR: ");
			scanf("%f", & Nfloat);
			
			if(Nfloat != 0)
			{
				f01_vector[i] = Nfloat;
				c++;
				i++;	
			}
						
		}
		while(Nfloat != 0);
	
	return c;
}

float buscarValor(float *f02_vector, int c, int &encontrado)
{
	float busqueda = 0;
	int i = 0;
	
	printf("\n\nINGRESE EL VALOR A BUSCAR: ");
	scanf("%f", & busqueda);
	
	for (i=0; i<c; i++)
	{
		if(busqueda == f02_vector[i])
		{
			encontrado++;
		}
	}	
}

main()
{
	system("color F0");
	
	int cantidadFloat = 0;
	int valorEncontrado = 0;
	float vector[100];
	
	cantidadFloat = cargaDatos(vector);
	printf("\nCantidad de numeros reales ingresados: %d", cantidadFloat);
	
	buscarValor(vector, cantidadFloat, valorEncontrado);
	
	if(valorEncontrado > 0)
	{
		printf("El valor fue encontrado. Se repite %d veces.", valorEncontrado);
		printf("\n\n");
		system("pause");	
	}
	else if(valorEncontrado == 0)
	{
		printf("\nValor ingresado no se encuentra en la lista de valores.");
		printf("\n\n");
		system("pause");
	}	
	
}
