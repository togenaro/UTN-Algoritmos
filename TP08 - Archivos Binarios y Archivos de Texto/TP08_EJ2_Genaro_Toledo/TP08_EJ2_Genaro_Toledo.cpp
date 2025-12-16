/*
Universidad Tecnológica Nacional
Facultad Regional Tucumán
Ingeniería en Sistemas de Información

Algoritmos y Estructuras de Datos

Integrantes:
            
            44030752 - Genaro Toledo
*/        

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void Menu(FILE *arch);
int EnteroAleatorio(int minimo, int maximo); 
void CargaDatos(FILE *arch);
void ParesImpares(FILE *arch);
void ListarArchivo(FILE *arch);
void AgregarDatos(FILE *arch);
void BuscarValor(FILE *arch);
void RangoValores(FILE *arch);

main()
{
	system("color F0");
	srand(time(NULL));
	
	FILE *archivo;
	
	archivo = fopen("numeros.dat", "r+b");
	
	if(archivo == NULL)
	{
		archivo = fopen("numeros.dat", "w+b");
		
		if(archivo == NULL)
		{
			printf("No se pudo abrir el archivo.");
		}
	}
	
	fclose(archivo);	
	
	CargaDatos(archivo);
	Menu(archivo);
	
	fclose(archivo);
}

void Menu(FILE *arch)
{	
	int opcion = 0;
	
	do
	{
		system("cls");
		printf("--MENU--\n\n");
		
		printf("1- DETERMINAR VALORES PARES E IMPARES.");
		printf("\n2- LISTAR ARCHIVO.");
		printf("\n3- AGREGAR DATOS.");
		printf("\n4- BUSCAR UN DATO.");
		printf("\n5- DETERMINAR VALORES EN RANGO [125, 500] y [500, 789].");
		
		printf("\n\n6- SALIR");
		
		printf("\n\nINGRESE UNA OPCION: ");
		scanf("%d", &opcion);
		
		switch(opcion)
		{
			case 1:
					{
						system("cls");
						printf("PARES E IMPARES");
						ParesImpares(arch);
						break;
					}
			case 2:
					{
						system("cls");
						printf("LISTAR ARCHIVO\n\n");
						ListarArchivo(arch);
						break;
					}
			case 3:
					{
						system("cls");
						printf("AGREGAR DATOS\n\n");
						AgregarDatos(arch);
						break;
					}
			case 4:
					{
						system("cls");
						printf("BUSCAR UN DATO");
						BuscarValor(arch);
						break;
					}
			case 5:
					{
						system("cls");
						printf("VALORES EN RANGO [125, 500] y [500, 789]\n\n");
						RangoValores(arch);
						break;
					}
			case 6:
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
	while(opcion > 1 || opcion < 6);
	
	fclose(arch);	
}

int EnteroAleatorio(int minimo, int maximo) 
{	
	int numero = 0;		
	
	numero = minimo + rand() % (maximo + 1 - minimo);
	
	return numero;
}

void CargaDatos(FILE *arch)
{
	arch = fopen("numeros.dat", "r+b");
	
	printf("Generando numeros en el archivo...");
	printf("\n\n");
	system("pause");
	
	int numero = 0;
	
	rewind(arch);
	
	for(int i=0; i<276; i++)
	{
		numero = EnteroAleatorio(125, 789);
		
		fwrite(&numero, sizeof(numero), 1, arch);
	}	
	
	system("cls");
	printf("Hecho.");
	printf("\n\n");
	system("pause");
	system("cls");
	
	fclose(arch);
}

void ParesImpares(FILE *arch)
{	
	arch = fopen("numeros.dat", "r+b");
	
	int numero = 0;
	int pares = 0;
	int impares = 0;
	
	rewind(arch);
	
	fread(&numero, sizeof(numero), 1, arch);
	
	while(!feof(arch))
	{
		if( (numero % 2) == 0)
		{
			pares++;
		}
		
		if( (numero % 3) == 0)
		{
			impares++;
		}
		
		fread(&numero, sizeof(numero), 1, arch);
	}
	
	printf("\n\nValores pares guardados en el archivo: %d", pares);
	printf("\nValores impares guardados en el archivo: %d", impares);
	
	printf("\n\n");
	system("pause");

	fclose(arch);
}

void ListarArchivo(FILE *arch)
{
	arch = fopen("numeros.dat", "r+b");
	
	int numero = 0;
	
	rewind(arch);
	fread(&numero, sizeof(numero), 1, arch);
	
	while(!feof(arch))
	{
		printf("%d ", numero);
		
		fread(&numero, sizeof(numero), 1, arch);
	}
	
	printf("\n\n");
	system("pause");
	
	fclose(arch);
}

void AgregarDatos(FILE *arch)
{
	arch = fopen("numeros.dat", "r+b");
	
	int N = 0;
	float Nfloat = 0.0;
	
	fseek(arch, 0, SEEK_END);
	
	do
	{
		do
		{	
			printf("INGRESE UN NUMERO (0 para finalizar): ");
			scanf("%f", & Nfloat);
				
			N = Nfloat; // Sacar parte entera del numero flotante
			Nfloat = (float)(Nfloat - N); // Sacar parte decimal del numero flotante
						
			if (Nfloat > 0 || Nfloat < 0)
			{
				system("cls");
				printf("El numero debe ser entero. Ingrese nuevamente...");
				printf("\n\n");
				system("pause");
				system("cls");
				printf("AGREGAR DATOS\n\n");
			}
		}
		while (Nfloat > 0 || Nfloat < 0);
		
		if(N != 0)
		{
			fwrite(&N, sizeof(N), 1, arch);			
		}

	}
	while(N != 0);
	
	printf("\n\nDatos agregados correctamente.");
	printf("\n\n");
	system("pause");
	
	fclose(arch);
}

void BuscarValor(FILE *arch)
{
	arch = fopen("numeros.dat", "r+b");
	
	int busqueda = 0;
	float Nfloat = 0.0;
	int numero = 0;
	int c_busqueda = 0;
	
	do
	{	
		printf("\n\nINGRESE EL VALOR A BUSCAR: ");
		scanf("%f", & Nfloat);
			
		busqueda = Nfloat; // Sacar parte entera del numero flotante
		Nfloat = (float)(Nfloat - busqueda); // Sacar parte decimal del numero flotante
					
		if (Nfloat > 0 || Nfloat < 0)
		{
			system("cls");
			printf("El numero debe ser entero. Ingrese nuevamente...");
			printf("\n\n");
			system("pause");
			system("cls");
			printf("BUSCAR UN DATO");
		}
	}
	while (Nfloat > 0 || Nfloat < 0);
	
	rewind(arch);
	
	fread(&numero, sizeof(numero), 1, arch);
	
	while(!feof(arch))
	{
		if(busqueda == numero)
		{
			c_busqueda++;
		}
		
		fread(&numero, sizeof(numero), 1, arch);
	}
	
	if(c_busqueda == 0)
	{
		printf("\nEl valor ingresado no esta registrado en el archivo.");
		printf("\n\n");
		system("pause");
	}
	else 
	{
		printf("\nSe encontro el valor ingresado.\n");
		printf("Cantidad de veces que aparece: %d", c_busqueda);
		printf("\n\n");
		system("pause");			
	}
	
	fclose(arch);
}

void RangoValores(FILE *arch)
{
	arch = fopen("numeros.dat", "r+b");
	
	int numero = 0;
	int primerRango = 0;
	int segundoRango = 0;
	
	rewind(arch);
	fread(&numero, sizeof(numero), 1, arch);
	
	while(!feof(arch))
	{
		if(numero >= 125 && numero <=500)
		{
			primerRango++;	
		}
		
		if(numero >= 500 && numero <= 789)
		{
			segundoRango++;
		}
		
		fread(&numero, sizeof(numero), 1, arch);
	}
	
	if(primerRango > 0)
	{
		printf("Numeros entre rango [125...500]: %d", primerRango);
	}
	else
	{
		printf("No existe ningun numero entre rango [125...500].");
		printf("\n\n");
		system("pause");
		system("cls");
	}
	
	if(segundoRango > 0)
	{
		printf("\nNumeros entre rango [500...789]: %d", segundoRango);
	}
	else
	{
		printf("\nNo existe ningun numero entre rango [500...789].");
		printf("\n\n");
		system("pause");
		system("cls");	
	}
	
	if(primerRango == 0 && segundoRango == 0)
	{
		printf("\n\nNo existen numeros entre los rangos estipulados.");
		printf("\n\n");
		system("pause");
		system("cls");
	}
	
	
	printf("\n\n");
	system("pause");
	
	fclose(arch);	
}









