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
#include <conio.h>
#include <ctype.h>

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
	
	bool borrado;
};

void Menu(FILE *arch);
void Venta(FILE *arch);
void ListarMes(FILE *arch);
void ListarFormaPago(FILE *arch);
void ImporteTotalVendedor(FILE *arch);
void ListarDatos(FILE *arch);
void ModificarFormaVenta(FILE *arch);
void BajaLogica(FILE *arch);
void BajaFisica(FILE *arch, cadena clave);
void Ordenamiento(FILE *arch);
void RegistrarClave(cadena clave);

main()
{
	system("color F0");
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
	cadena clave;
		
	do
	{
		system("cls");	
		printf("--MENU--\n\n");
		printf("1- REGISTRAR VENTA\n");
		printf("2- LISTAR VENTAS DE UN MES\n");
		printf("3- LISTAR FORMAS DE PAGO EN EL MES\n");
		printf("4- LISTAR IMPORTE TOTAL DE UN VENDEDOR\n");
		printf("5- LISTAR DATOS DEL ARCHIVO\n");
		printf("6- MODIFICAR FORMA DE VENTA DE UNA FACTURA\n");
		printf("7- REALIZAR ORDENAMIENTO POR ORDEN DE FACTURA.");
		
		printf("\n\n8- BAJA LOGICA DEL REGISTRO.");
		printf("\n9- BAJA FISICA DEL REGISTRO.");
		printf("\n10- REGISTRAR NUEVA CLAVE.");
		
		printf("\n\n0- SALIR\n\n");
		
		printf("INGRESE UNA OPCION: ");
		scanf("%d", & opcion);
		
		switch(opcion)
		{
			
			case 0:	 
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
						ModificarFormaVenta(arch);
						break;
					}
			case 7:	
					{
						Ordenamiento(arch);
						break;
					}					
			case 8:	
					{
						BajaLogica(arch);
						break;
					}
			case 9:	
					{
						BajaFisica(arch, clave);
						break;
					}						
			case 10:	
					{
						RegistrarClave(clave);
						break;
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
	while(opcion > 0 || opcion < 10);
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
	printf("--LISTADO DE DATOS DEL ARCHIVO--");
	
	while(!feof(arch))
	{
		if(reg.borrado == true)
		{
			printf("\n\n\nESTADO: BORRADO.\n");
		}
		else if(reg.borrado == false)
		{
			printf("\n\n\nESTADO: ACTIVO.\n");
		}
		
		printf("NUMERO DE VENDEDOR: %d", reg.numeroVendedor);
		printf("\nAPELLIDO Y NOMBRE DEL VENDEDOR: %s", reg.apellidoYNombre);
		printf("\nNUMERO DE FACTURA: %d", reg.numeroFactura);
		printf("\nIMPORTE FACTURADO DE LA VENTA: %d", reg.importeVenta);
		
		printf("\nFORMA DE VENTA: ");
		if(reg.formaVenta == 1)
			printf("CONTADO.");
		if(reg.formaVenta == 2)
			printf("CREDITO.");
				
		printf("\nFECHA DE VENTA: %d/%d/%d", reg.Fecha.dd, reg.Fecha.mm, reg.Fecha.aaaa);
			
		fread(&reg, sizeof(reg), 1, arch);
	}
	
	printf("\n\n");
	system("pause");
}

void ModificarFormaVenta(FILE *arch)
{
	int factura = 0;
	
	RegistroVenta reg;
	
	system("cls");
	printf("--MODIFICACION DE FACTURA--\n\n");
	printf("INGRESE FACTURA A MODIFICAR: ");
	scanf("%d", &factura);
	
	rewind(arch);
	fread(&reg, sizeof(reg), 1, arch);
		
	while(!feof(arch))
	{
		if(factura == reg.numeroFactura)
		{
			printf("LA FORMA DE VENTA ACUTAL DE LA FACTURA ES: ");
			if(reg.formaVenta == 1)
				printf("DE CONTADO.");
			if(reg.formaVenta == 2)
				printf("POR CREDITO.");	
				
			printf("\n\nINGRESE LA FORMA DE VENTA A MODIFICAR: ");
			scanf("%d", &reg.formaVenta);	
			
			fwrite(&reg, sizeof(reg), 1, arch);	
		}
					
		fread(&reg, sizeof(reg), 1, arch);
	}
	
}

void BajaLogica(FILE *arch)
{
	int target = 0;
	bool bandera = false;
	
	cadena centinela;
	
	RegistroVenta reg;
	
	system("cls");
	printf("--BAJA LOGICA--\n\n");
	
	printf("INGRESE FACTURA A ELIMINAR: ");
	scanf("%d", &target);
	
	rewind(arch);
	fread(&reg, sizeof(reg), 1, arch);
		
	while(!feof(arch) && bandera == false)
	{
		if(target == reg.numeroFactura)
		{
			printf("DESEA BORRAR LA FACTURA INGRESADA (SI|NO): ");
			_flushall();
			gets(centinela);
			strupr(centinela);
			
			if(strcmp(centinela, "SI") == 0)
			{
				reg.borrado = true;
				fseek(arch, (long) -sizeof(reg), SEEK_CUR);
				fwrite(&reg, sizeof(reg), 1, arch);
				
				printf("\nSe ha realizado la baja logica del registro exitosamente.");
				printf("\n\n");
				system("pause");
				bandera = true;
			}
			else if(strcmp(centinela, "NO") == 0)
			{
				system("cls");
				printf("No se ha realizado la baja logica de la factura seleccionada.");
				printf("\n\n");
				system("pause");
				system("cls");
			}
			
			if(target != reg.numeroFactura)
			{
				fread(&reg, sizeof(reg), 1, arch);
			}
			
		}
				
	}	
	
	if(bandera == false)
	{
		system("cls");
		printf("No se ha encontrado la factura ingresada.");
		printf("\n\n");
		system("pause");
		system("cls");
	}
}

void BajaFisica(FILE *arch, cadena clave)
{
	cadena ingreso;
	FILE *aux;
	RegistroVenta reg;
	
	system("cls");
	printf("INGRESE LA CLAVE: ");
	_flushall();
	gets(ingreso);
	
	if(strcmp(ingreso, clave) == 0)
	{
	
		bool bandera = false;
		
		aux = fopen("auxiliar.dat", "w+b");
		
		rewind(arch);
		fread(&reg, sizeof(reg), 1, arch);
		
		while (!feof(arch))
		{
			if (reg.borrado == false)
			{
				fwrite(&reg, sizeof(reg), 1, aux);
				
				bandera = true;
			}
			
			fread(&reg, sizeof(reg), 1, arch);
		}
		
		if (bandera = true)
		{
			system("cls");
			printf("El registro fue borrado exitosamente.");
			printf("\n\n");
			system("pause");
		}
		else
		{
			system("cls");
			printf("No se pudo borrar el registro.");
			printf("\n\n");
			system("pause");
		}
		
		fclose(arch);
		fclose(aux);
		
		remove("archivo.dat");
		rename("auxiliar.dat", "archivo.dat");
		
		arch = fopen("archivo.dat", "r+b");	
	} 
	else
	{
		system("cls");
		printf("La clave es incorrecta.");
		printf("\n\n");
		system("pause");
		system("cls");
	}
}

void Ordenamiento(FILE *arch)
{
	RegistroVenta reg;
	RegistroVenta vec[80];
	RegistroVenta aux;

	bool bandera = false;
	
	int L = 0;
	int N = 0;
	int i = 0; 
	
	rewind(arch);
	fread(&reg, sizeof(reg), 1, arch);
	
	while (!feof(arch))
	{
		vec[i] = reg;
		i++;
		
		fread(&reg, sizeof(reg), 1, arch);
	}
	
	N = i;	
	L = N - 1;
	
	do
	{
		bandera = false;
		
		for(int i=0; i<L; i++)
		{
			if (vec[i].numeroFactura > vec[i+1].numeroFactura)
			{
				aux = vec[i];
				vec[i] = vec[i+1];
				vec[i+1] = aux;
				
				bandera = true;
			}
		}
		
		L = L - 1;
	} 
	while (bandera == true);
	
	
	system("cls");
	printf("--ORDENAMIENTO Y LISTADO--");
	
	for (int i=0; i<=N-1; i++)
	{
		reg = vec[i];
			
		printf("\n\n\nNUMERO DE VENDEDOR: %d", reg.numeroVendedor);
		printf("\nAPELLIDO Y NOMBRE: %s", reg.apellidoYNombre);
		printf("\nNUMERO DE FACTURA: %d", reg.numeroFactura);
		printf("\nMONTO DE FACTURA: %d", reg.importeVenta);
		//printf("\nForma de Venta: %d", regi.formaVenta);
		printf("\nFORMA DE VENTA: ");
		switch ( reg.formaVenta )
		{
			case 1: {printf("CONTADO");	break;}	
			case 2: {printf("CREDITO"); break;}
		};
		
		printf("\nFECHA DE VENTA: %d/%d/%d", reg.Fecha.dd, reg.Fecha.mm, reg.Fecha.aaaa);
		
		if (reg.borrado == false)
		{
			printf("\nEstado: ACTIVO");
		}
		else
		{
			printf("\nEstado: BORRADO");
		}
	}
	
	printf("\n\n");
	system("pause");	
}

void RegistrarClave(cadena clave)
{
	cadena centinela;
	char tecla = ' ';
	int i = 0;
	
	system("cls");
	
	printf("DESEA REGISTRAR NUEVA CLAVE(SI|NO): ");
	_flushall();
	gets(centinela);
	strupr(centinela);
	if( strcmp(centinela, "SI") == 0) 
	{	
		system("cls");	
		printf("Ingrese clave: ");
		
		do
		{
			tecla = getch(); // tecla original
			//tecla = toupper(getch()); // mayusculas
			//tecla = tolower(getch()); // minusculas
			
			if (tecla == 13) break; // 13 es [ENTER]
			
			printf("*");
			
			clave[i++] = tecla;
	
		} while (true);
		
		clave[i] = '\0';
		printf("\nSu clave es: %s", clave);		
	}
	
	printf("\n\n");
	system("pause");
}



