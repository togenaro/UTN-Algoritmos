// ordenamiento por elecccion

#include<iostream>
#include<conio.h>

using namespace std;

void metodoSeleccion(int f08_vector[], int f08_N)
{
	int i,j,aux,min;
	
	for(int i=0; i<f08_N; i++)
	{
		min = i;
		for(j=i+1; j<f08_N; j++)
			{
			if(f08_vector[j]< f08_vector[min]){
				min = j;
			}
	}
		
	aux = f08_vector[i];
	f08_vector[i]= f08_vector[min];
	f08_vector[min] = aux;
	
	}
	
	printf("Orden Ascendente: \n");
	for(i=0; i<f08_N; i++)
	{
		printf("\n");
		printf("SUBINDICE [%d]: %d", i, f08_vector[i]);
	}
	
	printf("\n\nOrden Descendente: \n");
	for(i=f08_N; i>=0; i--)
	
	{
		printf("\n");
		printf("SUBINDICE [%d]: %d", i, f08_vector[i]);
	}
	printf("\n\n");

}

main()
{
	int vector[] = {5, 8, 2, 9, 1};
	int N = 5;
	metodoSeleccion(vector, N);
	system("pause");
}
















