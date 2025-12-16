#include <stdlib.h>
#include <stdio.h>

const int FILAS = 3;
const int COLUMNAS = 3;

cargaMatriz(int matriz[FILAS][COLUMNAS])
{
	for(int f=0; f<FILAS; f++)
	{
		int valor = 0;
		
		for(int c=0; c<COLUMNAS; c++)
		{
			printf("INGRESE EL SUBINDICE[%d][%d]: ", f, c);
			scanf("%d", & valor);
			
			matriz[f][c] = valor;
		}
	}
}

mostrarMatriz(int matriz[FILAS][COLUMNAS])
{
	system("cls");
	
	for(int f=0; f<FILAS; f++)
	{
		for(int c=0; c<COLUMNAS; c++)
		{
			printf("  %d", matriz[f][c]);
		}
		
		printf("\n\n");
	}
	
	printf("\n\n");
	system("pause");
}



main()
{
	int matriz[FILAS][COLUMNAS] = {0};
	
	cargaMatriz(matriz);
	mostrarMatriz(matriz);	
}
