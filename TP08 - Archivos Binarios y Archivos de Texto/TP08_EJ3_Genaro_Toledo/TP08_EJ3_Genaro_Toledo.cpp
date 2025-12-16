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

typedef char cadena[80];

struct RegistroFecha
{
	int dd;
	int mm;
	int aaaa;
};

struct RegistroVenta
{
	int numeroVendedor;
	cadena apellidoYNombre;
	int importeVenta;
	int numeroFactura;
	int formaVenta;
	RegistroFecha Fecha;
};

void Menu(FILE *arch);
void Venta(FILE *arch);
void ListarMes(FILE *arch);
void ListarFormaPago(FILE *arch);
void ImporteTotalVendedor(FILE *arch);
void ListarDatos(FILE *arch);

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
		printf("1- REGISTRAR VENTA\n");
		printf("2- LISTAR VENTAS DE UN MES\n");
		printf("3- LISTAR FORMAS DE PAGO EN EL MES\n");
		printf("4- LISTAR IMPORTE TOTAL DE UN VENDEDOR\n");
		printf("5- LISTAR DATOS DEL ARCHIVO\n\n");
		
		printf("6- SALIR\n\n");
		
		printf("INGRESE UNA OPCION: ");
		scanf("%d", & opcion);
		
		switch(opcion)
		{
			case 1:
					{
					 	Venta(arch);
						break;
					}
			case 2:
					{
						ListarMes(arch);
						break;
					}
			case 3:
					{	
						ListarFormaPago(arch);
						break;
					}
			case 4:	
					{
						ImporteTotalVendedor(arch);
						break;
					}
			case 5:	
					{
						ListarDatos(arch);
						break;
					}
												
			case 6: 
					{
						system("cls");
						int centinela = 0;
						
						printf("Desea borrar el archivo (1:SI | 2: NO): ");
						scanf("%d", &centinela);
						
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
						fclose(arch);
						exit(EXIT_SUCCESS);	
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

void Venta(FILE *arch)
{		
	RegistroVenta reg;
	
	system("cls");
	
	do
	{
		printf("NUMERO DE VENDEDOR: ");
		scanf("%d", &reg.numeroVendedor);
		
		if(reg.numeroVendedor < 1 || reg.numeroVendedor > 3)
		{
			system("cls");
			printf("El valor ingresado es incorrecto. Ingrese nuevamente.");
			printf("\n\n");
			system("pause");
			system("cls");				
		}		
	}
	while(reg.numeroVendedor < 1 || reg.numeroVendedor > 3);
	
	printf("APELLIDO Y NOMBRE: ");
	_flushall();
	gets(reg.apellidoYNombre);
	
	printf("NUMERO DE FACTURA: ");
	scanf("%d", &reg.numeroFactura);
	
	printf("IMPORTE DE VENTA: ");
	scanf("%d", &reg.importeVenta);
	
	do
	{
		printf("FORMA DE VENTA: ");
		scanf("%d", &reg.formaVenta);		
	
		if(reg.formaVenta < 1 || reg.formaVenta > 2)
		{
			system("cls");
			printf("El valor ingresado es incorrecto. Ingrese nuevamente.");
			printf("\n\n");
			system("pause");
			system("cls");		
		}	
	}
	while(reg.formaVenta < 1 || reg.formaVenta > 2);
	

	printf("FECHA DE VENTA: \n");
	printf("\tDIA: ");
	scanf("%d", &reg.Fecha.dd);
	printf("\tMES: ");
	scanf("%d", &reg.Fecha.mm);
	printf("\tANIO: ");
	scanf("%d", &reg.Fecha.aaaa);
	
	fseek(arch, 0, SEEK_END);
	fwrite(&reg, sizeof(reg), 1, arch);
		
	system("cls");
	printf("Venta registrada exitosamente.");
	printf("\n\n");
	system("pause");
}

void ListarMes(FILE *arch)
{
	RegistroVenta reg;
	
	int mes = 0;
	int c_cantidadTotalVentas = 0;
	
	system("cls");
	
	printf("INGRESE EL MES A BUSCAR: ");
	scanf("%d", &mes);
	
	rewind(arch);
	fread(&reg, sizeof(reg), 1, arch);
	
	while(!feof(arch))
	{
		if(mes == reg.Fecha.mm)
		{
			c_cantidadTotalVentas++;	
		}
		
		fread(&reg, sizeof(reg), 1, arch);
	}
	
	printf("\n");
		
	if(mes == 1)
	printf("MES DE: ENERO");
	if(mes == 2)
	printf("MES DE: FEBRERO");	
	if(mes == 3)
	printf("MES DE: MARZO");
	if(mes == 4)
	printf("MES DE: ABRIL");	
	if(mes == 5)
	printf("MES DE: MAYO");
	if(mes == 6)
	printf("MES DE: JUNIO");
	if(mes == 7)
	printf("MES DE: JULIO");
	if(mes == 8)
	printf("MES DE: AGOSTO");
	if(mes == 9)
	printf("MES DE: SEPTIEMBRE");
	if(mes == 10)
	printf("MES DE: OCTUBRE");
	if(mes == 11)
	printf("MES DE: NOVIEMBRE");
	if(mes == 12)
	printf("MES DE: DICIEMBRE");
	
	printf("\n");
	
	printf("\tCANTIDAD DE VENTAS: %d", c_cantidadTotalVentas);
	
	printf("\n\n");
	system("pause");
}

void ListarFormaPago(FILE *arch)
{
	RegistroVenta reg;
	
	int mes = 0;
	int c_contado = 0;
	int c_credito = 0;
	
	system("cls");
	
	printf("INGRESE EL MES A BUSCAR: ");
	scanf("%d", &mes);
	
	rewind(arch);
	fread(&reg, sizeof(reg), 1, arch);
	
	while(!feof(arch))
	{
		if(mes == reg.Fecha.mm)
		{
			if(reg.formaVenta == 1)
				c_contado++;
			if(reg.formaVenta == 2)
				c_credito++;				
		}
		
		fread(&reg, sizeof(reg), 1, arch);
	}
	
	
	printf("\n--CANTIDAD DE VENTAS--\n\n");
	printf("\tDE CONTADO: %d", c_contado);
	printf("\n\tPOR CREDITO: %d", c_credito);
	printf("\n\n");
	system("pause");	
}

void ImporteTotalVendedor(FILE *arch)
{
	RegistroVenta reg;
	
	int mes = 0;
	cadena nombre;
	int c_importeTotal = 0;
	
	system("cls");
	
	printf("INGRESE EL MES A BUSCAR: ");
	scanf("%d", &mes);
	
	printf("INGRESE EL NOMBRE DEL VENDEDOR: ");
	_flushall();
	gets(nombre);
	
	rewind(arch);
	fread(&reg, sizeof(reg), 1, arch);
	
	while(!feof(arch))
	{
		if(mes == reg.Fecha.mm)
		{
			if( strcmp(nombre, reg.apellidoYNombre) == 0 )
			{
				c_importeTotal = c_importeTotal + reg.importeVenta;			
			}		
		}
		
		fread(&reg, sizeof(reg), 1, arch);
	}
	
	printf("\n\nIMPORTE TOTAL REALIZADO POR %s: $%d", nombre, c_importeTotal);
	printf("\n\n");
	system("pause");	
}

void ListarDatos(FILE *arch)
{
	RegistroVenta reg;
	
	rewind(arch);
	fread(&reg, sizeof(reg), 1, arch);
	
	system("cls");
	printf("--LISTADO DE DATOS DEL ARCHIVO--\n\n");
	
	while(!feof(arch))
	{
		printf("NUMERO DE VENDEDOR: %d", reg.numeroVendedor);
		printf("\nAPELLIDO Y NOMBRE DEL VENDEDOR: %s", reg.apellidoYNombre);
		printf("\nIMPORTE FACTURADO DE LA VENTA: %d", reg.importeVenta);
		
		printf("\nFORMA DE VENTA: ");
		if(reg.formaVenta == 1)
			printf("CONTADO.");
		if(reg.formaVenta == 2)
			printf("CREDITO.");
				
		printf("\nFECHA DE VENTA:");
		printf("\n\tDIA: %d", reg.Fecha.dd);		
		printf("\n\tMES: %d", reg.Fecha.mm);	
		printf("\n\tANIO: %d\n\n\n", reg.Fecha.aaaa);	
				
		fread(&reg, sizeof(reg), 1, arch);
	}
	
	system("pause");
}










