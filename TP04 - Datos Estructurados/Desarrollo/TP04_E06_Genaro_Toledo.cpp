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
#include <time.h>

int EnteroAleatorio(int minimo, int maximo) 
{	
	int numero = 0;		//10       //20
	
	//variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
	numero = minimo + rand() % (maximo + 1 - minimo);
	
	return numero;
}

void cargaVector(int *f01_vector, int f01_N)
{
	
	for (int i=0; i<f01_N; i++)
	{
		f01_vector[i] = EnteroAleatorio(10, 99);
	}

}

void mostrarVector(int *f02_vector, int f02_N)
{
	for (int i=0; i<f02_N; i++)
	{
		printf("%d ", f02_vector[i]);
	}
	printf("\n\n");
 	system("pause");
}

void menorAMayor(int *f03_vector, int f03_N) 
{
	int i,j,aux;
	bool bandera;
	
	for(i=1; i<f03_N; i++)
	{
		bandera = false;
		
		for(j=f03_N-1; j>=i; j--)
		{
			if (f03_vector[j-1] > f03_vector[j])
			{
				aux = f03_vector[j-1];
				f03_vector[j-1] = f03_vector[j];
				f03_vector[j] = aux;
				bandera = true;
			}
		}
		
		if(bandera==false) break;
	}

}

void mayorAMenor(int *f04_vector, int f04_N) 
{
	int i,j,aux;
	bool bandera;
	
	for(i=0; i<f04_N; i++)
	{
		bandera = false;
						
		for(j=f04_N-1; j>i; j--) 
		{
			if (f04_vector[j-1] < f04_vector[j])
			{
				aux = f04_vector [j-1];
				f04_vector[j-1] = f04_vector[j];
				f04_vector[j] = aux;
				bandera = true;
			}
		}
		
		if(bandera==false) break;
	}
}


main()
{
	system("color F0");
	
	srand(time(NULL));
	
	int N = 0;
	printf("INGRESE ORDEN DEL VECTOR: ");
	scanf("%d", &N);
	system("cls");
	
	int vector[N];
	cargaVector(vector, N);
	printf("VECTOR GENERADO: ");
	mostrarVector(vector, N);
	
	printf("\nMENOR A MAYOR: ");
 	menorAMayor(vector, N);
 	mostrarVector(vector, N);
 	
 	printf("\nMAYOR A MENOR: ");
 	mayorAMenor(vector, N);
 	mostrarVector(vector, N);
}
