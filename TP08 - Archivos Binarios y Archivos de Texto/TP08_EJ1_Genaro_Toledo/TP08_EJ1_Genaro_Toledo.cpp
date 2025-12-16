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

// -----------------------------
void Menu(FILE *arch);
void Venta(FILE *arch, float valor);
void MostrarVentas(FILE *arch, float valor);
void MayorVenta(FILE *arch, float valor);
void TotalVentas(FILE *arch, float valor);
void BorrarArchivo(FILE *arch, float valor);
// -----------------------------

main()
{
	system("color 0F");
	FILE *archivo;
	
	archivo = fopen("archivo.dat", "r+b");
	
	if (archivo == NULL)
	{
		archivo = fopen("archivo.dat", "w+b");
		
		if(archivo == NULL)
		{
			printf("Error. No se pudo crear el archivo.");
			exit(1);			
		}
		else
		{
			printf("El archivo fue creado exitosamente.\n\n");
			system("pause");			
		}	
	}
	else
	{
		printf("El archivo fue abierto exitosamente.");
		printf("\n\n");
		system("pause");	
	}
	
	Menu(archivo);
}

void Menu(FILE *arch)
{		
	int opcion = 0;
	float valor = 0;
		
	do
	{
		system("cls");	
		printf("--MENU--\n\n");
		printf("1- VENDER PRODUCTO\n");
		printf("2- MOSTRAR VENTAS\n");
		printf("3- MOSTRAR MAYOR VENTA\n");
		printf("4- MOSTRAR EL TOTAL DE VENTAS\n\n");
		printf("5- SALIR\n\n");
		
		printf("INGRESE UNA OPCION: ");
		scanf("%d", & opcion);
		
		switch(opcion)
		{
			case 1:
					{
						Venta(arch, valor);	
						break;
					}
			case 2:
					{
						MostrarVentas(arch, valor);	
						break;
					}
			case 3:
					{	
						MayorVenta(arch, valor);
						break;
					}
			case 4:	
					{
						TotalVentas(arch, valor);
						break;
					}	

			case 5: 
					{
						system("cls");
						int centinela = 0;
						
						printf("Desea borrar el archivo (1:SI | 2: NO): ");
						scanf("%d", & centinela);
						
						if(centinela == 1)
						{
							fclose(arch);
							
							remove("archivo.dat");
							system("cls");
							printf("El archivo fue borrado exitosamente.");
							printf("\n\n");
							system("pause");
						}
						else
						{
							system("cls");
							printf("No se ha borrado el archivo.");
							printf("\n\n");
							system("pause");
						
						}
						
						system("cls");
						printf("Finalizando...");
						printf("\n\n");
						system("pause");
						exit(0);	
					}
			default:
					{
						system("cls");
						printf("Opcion incorrecta. Ingrese nuevamente.");
						printf("\n\n");
						system("pause");
						break;
					}												
		}		
	}
	while(opcion > 1 || opcion < 6);
}

void Venta(FILE *arch, float valor)
{	
	valor = 0;	
	system("cls");
	
	printf("INGRESE EL VALOR DE VENTA: ");
	scanf("%f", &valor);
	
	fseek(arch, 0, SEEK_END);
	fwrite(&valor, sizeof(valor), 1, arch);
	
	system("cls");
	printf("Venta registrada exitosamente.");
	printf("\n\n");
	system("pause");
}

void MostrarVentas(FILE *arch, float valor)
{
	bool bandera = false;
	int c = 0;
	
	rewind(arch);
	fread(&valor, sizeof(valor), 1, arch);
	
	system("cls");
	printf("--VENTAS REALIZADAS--\n\n");
		
	while(!feof(arch))
	{			
		if(valor >= 10000 && valor < 100000)
			printf("0%.0f", valor);
					
		if(valor >= 1000 && valor < 10000)
			printf("00%.0f", valor);
			
		if(valor >= 100 && valor < 1000)
			printf("000%.0f", valor);
			
		if(valor >= 10 && valor < 100)
			printf("0000%.0f", valor);
			
		if(valor >= 1 && valor < 10)
			printf("00000%.0f", valor);

		c++;
		
		if (c!= 10)
			printf(" - ");
		
		if(c == 10)
		{
			printf("\n");
			c = 0;		
		}
			
		fread(&valor, sizeof(valor), 1, arch);
	}
					
	printf("\n\n");
	system("pause");
}

void MayorVenta(FILE *arch, float valor)
{	
	system("cls");
	printf("--VENTA MAYOR--");
	
	float mayorVenta = -99999.99;
	int c_mayorVenta = 1;
	bool bandera = false;
	
	rewind(arch);
	fread(&valor, sizeof(valor), 1, arch);
	
	while(!feof(arch))
	{
		if (valor == mayorVenta)
		{	
			c_mayorVenta++;	
		}
					
		if(valor > mayorVenta)
		{		
			mayorVenta = valor;
			bandera = true;
		}
		
		fread(&valor, sizeof(valor), 1, arch);	
	}
	
	if (bandera == false)
	{
		system("cls");
		printf("No se registro ninguna venta.");
	}
	else
	{
		printf("\n\nMayor venta realizada: $%.2f", mayorVenta);
		printf("\nCantidad de veces que se registro: %d", c_mayorVenta);
	}
	
	printf("\n\n");
	system("pause");
}

void TotalVentas(FILE *arch, float valor)
{
	system("cls");
	printf("--TOTAL DE VENTAS--\n\n");

	float ac_total = 0.0;
	
	rewind(arch);
	fread(&valor, sizeof(valor), 1, arch);
	
	while(!feof(arch))
	{
		ac_total = ac_total + valor;
		
		fread(&valor, sizeof(valor), 1, arch);		
	}
	
	printf("Total de las ventas realizadas: $%.2f", ac_total);
	printf("\n\n");
	system("pause");
}




