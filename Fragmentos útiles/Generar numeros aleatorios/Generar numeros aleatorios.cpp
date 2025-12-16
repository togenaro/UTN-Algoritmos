#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
La librería time.h sirve para generar números aleatorios.
*/

// s: seed (semilla)
/* time(NULL):	función interna dentro de la librería <time.h> que devuelve la cantidad de milisegundos
				que transcurrieron desde las 00:00 del 01/01/1970 hasta el momento actual en el que se
				ejecuta la función.			
*/ 
// rand(): función interna dentro de la librería <time.h> para generar números aleatorios.

 // Inicializar la semilla en cero.

int EnteroAleatorio(int minimo, int maximo) 
{	
	int numero = 0;		//10       //20
	
	//variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior) ;
	numero = minimo + rand() % (maximo + 1 - minimo);
	
	return numero;
}					

main()
{
	srand(time(NULL));
	
	int numeroGenerado = 0;
	const int minimo = 1;
	const int maximo = 100;
	
	do
	{
		system("cls");
		numeroGenerado = EnteroAleatorio(minimo, maximo);
		printf("El numero generado es: %d", numeroGenerado);
	}
	while (numeroGenerado != 10);	

	printf("\n\n");
	system("pause");		
}
