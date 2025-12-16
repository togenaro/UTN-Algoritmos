/*
Universidad Tecnológica Nacional
Facultad Regional Tucumán
Ingeniería en Sistemas de Información

Algoritmos y Estructuras de Datos

Integrantes:
            
            44030752 - Toledo, Genaro
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

const int M = 10;
const int N = 10;

int EnteroAleatorio(int minimo, int maximo) 
{	
	int numero = 0;
	
	numero = minimo + rand() % (maximo + 1 - minimo);
	
	return numero;
}	

void cargaMatriz(int f01_matriz[M][N], int f01_f, int f01_c)
{
	for (int i=0; i<f01_f; i++)
	{
		for (int j=0; j<f01_c; j++)
		{
			f01_matriz[i][j] = EnteroAleatorio(10, 99);
		}
	}

}

void mostrarMatriz(int f0n_matriz[M][N], int f0n_f, int f0n_c)
{
	printf("\n\n");
	printf("MATRIZ GENERADA DEL NEGOCIO: ");
	printf("\n\n");
	
	for (int i=0; i<f0n_f; i++)
	{
		for (int j=0; j<f0n_c; j++)
		{
			printf("%d ", f0n_matriz[i][j]);
		}
		printf("\n");
	}
}

void mayorVentaSucursal(int f02_matriz[M][N], int f02_f, int f02_c)
{
	
	int suma = 0;
	int mayorVenta = -999999;
	int sucursalMayor = 0;
	
	for (int i=0; i<f02_f; i++)
	{
		suma = 0;
		
		for (int j=0; j<f02_c; j++)
		{
			suma = suma + f02_matriz[i][j];
		} // columnas 
		
		if (suma > mayorVenta)
		{
			mayorVenta = suma;
			sucursalMayor = i;		
		}
		
	} // filas
	
	printf("\n");
	printf("El SUBINDICE de la sucursal con mayor venta es: [%d]", sucursalMayor);
}

void mayorVentaDeporte(int f03_matriz[M][N], int f03_f, int f03_c)
{
	
	int suma = 0;
	int mayorVenta = -999999;
	int deporteMayor = 0;
	
	for (int j=0; j<f03_c; j++)
	{
		suma = 0;
		
		for (int i=0; i<f03_f; i++)
		{
			suma = suma + f03_matriz[j][i];
		} // columnas 
		
		if (suma > mayorVenta)
		{
			mayorVenta = suma;
			deporteMayor = j;	
		}
		
	}
	
	printf("\n");
	printf("El SUBINDICE del deporte con mayor venta es: [%d]", deporteMayor);
	
	printf("\n\n");	
}

int sumaSucursales(int f04_matriz[M][N], int f04_f, int f04_c)
{
	int suma = 0;
	
	for (int i=0; i<f04_f; i++)
	{
		
		for (int j=0; j<f04_c; j++)
		{
			suma = suma + f04_matriz[i][j];
		} // columnas 
		
	} // filas
	
	return suma;
}

main()
{
	system("color 0F");
	
	int f = 0; // filas(sucursales)
	int c = 0; // columnas(deporte)
	
	int totalVentas = 0; // total de ventas de todas las sucursales.
	
	printf("INGRESE CANTIDAD DE SUCURSALES: ");
	scanf("%d", & f);
	printf("INGRESE LA CANTIDAD DE DEPORTES: ");
	scanf("%d", & c);
	
	int negocio[M][N];
	
	cargaMatriz(negocio, f, c);
	mostrarMatriz(negocio, f, c);
	
	mayorVentaSucursal(negocio, f, c);
	mayorVentaDeporte(negocio, f, c);
	
	totalVentas = sumaSucursales(negocio, f, c);
	
	printf("La venta total de todas las sucursales es de: %d", totalVentas);
	
	printf("\n\n");
	system("pause");
}
