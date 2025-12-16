/*
Universidad Tecnológica Nacional
	Facultad Regional Tucumán
	Ingeniería en Sistemas de Información
	
Algoritmos y Estructuras de Datos

Integrantes:

            44030752 - Toledo, Genaro
            44367714 - Saavedra, Mariana				
            44479000 - Tula, Esteban
            44814073 - Soria, Julián
			   
Comisión:
			-- 1K06 --
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char cadena[80];
char vec_simbolos[] = "+, -, /, *, ?, ¿, !, ¡";
char vec_mayus[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char vec_minus[] = "abcdefghijklmnopqrstuvwxyz";
char vec_digitos[] = "0123456789";	

struct Fecha
{
	int dia;
	int mes;
	int anio;	
};

struct Usuarios
{
	cadena usuario;
	cadena clave;
	cadena apellidoYNombre;
	int id;
	int Dni;
	cadena telefono;
};

struct Cliente
{
	cadena apellidoYNombre;
	cadena domicilio;
	int dniCliente;
	cadena localidad;
	Fecha fechaDeNacimiento;
	float peso;
	cadena telefono; 	
};

struct Turnos
{
	int idProfesional;
	Fecha fechaDeTurno;
	int dniCliente;
	char detalleDeAtencion[380];
};

// -----------------------------------------------------------------------------------------------------------

// --Menús principales--
void MenuPrincipal(FILE *arch);
void MenuPyR(bool &bandera_sesion_p, bool &bandera_sesion_r, bool bandera_cliente,FILE *arch);

// --Administración--
void MenuAdministracion(FILE *arch);
void RegistrarProfesional(FILE *arch);
void RegistrarRecepcionista(FILE *arch);

// --Módulo: Espacios--
void ModuloEspacios(bool &bandera_sesion_p, bool &bandera_sesion_r, bool bandera_cliente,FILE *arch);
bool InicioSesion_P(FILE *arch);
bool BuscarCliente(FILE *arch, int &posicion);

// --Módulo: Recepcionistas--
void ModuloRecepcionistas(bool &bandera_sesion_p, bool &bandera_sesion_r, bool bandera_cliente, FILE *arch);
void RegistrarCliente(FILE *arch);
bool InicioSesion_R(FILE *arch);

// -----------------------------------------------------------------------------------------------------------

main()
{
	FILE *archivo;
					
	MenuPrincipal(archivo);	
}

// ************************************* MENÚS PRINCIPALES ************************************************

void MenuPrincipal(FILE *arch)
{	
	system("color F0");
	
	bool bandera_sesion_p = false;
	bool bandera_sesion_r = false;
	bool bandera_cliente = false;
	
	int opcion = 0;
	
	do
	{
		system("cls");
		printf("--MENU PRINCIPAL--");
		printf("\n\n1- PROFESIONALES/RECEPCIONISTAS");
		printf("\n2- MODULO DE ADMINISTRACION");
		
		printf("\n\n3- CERRAR APLICACION");
		
		printf("\n\nSELECCIONE UNA OPCION: ");
		scanf("%d", &opcion);
		
		switch(opcion)
		{
			case 1: { MenuPyR(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch); }
			case 2: { MenuAdministracion(arch); }
			case 3:
					{
						system("cls");
						printf("Finalizando...");
						printf("\n\n");
						system("pause");
						exit(EXIT_SUCCESS);
					}
			default:
					{
						system("cls");
						printf("Opcion incorrecta. Ingrese nuevamente.");
						printf("\n\n");
						system("pause");
						system("cls");
						break;
					}
		}
		
	}
	while (opcion > 0 || opcion < 4);	
	
}

void MenuPyR(bool &bandera_sesion_p, bool &bandera_sesion_r, bool bandera_cliente,FILE *arch)
{	
	int opcion = 0;
		
	do
	{
		system("cls");
		printf("--ESPACIOS/RECEPCIONISTAS--");
		
		printf("\n\n1- MODULO ESPACIOS");
		printf("\n2- MODULO RECEPCION");
		
		printf("\n\n3- VOLVER AL MENU PRINCIPAL");
		printf("\n4- CERRAR APLICACION");
		
		printf("\n\nSELECCIONE UNA OPCION: ");
		scanf("%d", &opcion);
		
		switch( opcion )
		{
			case 1: { ModuloEspacios(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch); }
			case 2: { ModuloRecepcionistas(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch); }
			case 3: { MenuPrincipal(arch); }
			case 4:
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
						printf("Opcion incorrecta. Ingrese nuevamente.");
						printf("\n\n");
						system("pause");
						system("cls");
						break;
					}
		}
		
	}
	while (opcion > 0 || opcion < 4);
}

// ********************************************************************************************************



// ********* ADMINISTRACION *************

void MenuAdministracion(FILE *arch)
{
	int opcion = 0;
	
	do
	{
		system("cls");
		printf("--MODULO DE ADMINISTRACION--");
		printf("\n\n1- REGISTRAR USUARIO PROFESIONAL");
		printf("\n2- REGISTRAR USUARIO RECEPCIONISTA");
		printf("\n3- ATENCIONES POR PROFESIONAL");
		printf("\n4- RANKING DE PROFESIONALES POR ATENCIONES");
		
		printf("\n\n5- VOLVER AL MENU PRINCIPAL");
		printf("\n6- CERRAR APLICACION");
		
		printf("\n\nSELECCIONE UNA OPCION: ");
		scanf("%d", &opcion);
		
		switch(opcion)
		{
			case 1:
					{
						RegistrarProfesional(arch);
						break;
					}
			case 2:
					{	
						RegistrarRecepcionista(arch);
						break;
					}
			case 3:
					{	
						break;
					}
			case 4:
					{	
						break;
					}										
			case 5:
					{
						MenuPrincipal(arch);
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
						printf("Opcion incorrecta. Ingrese nuevamente.");
						printf("\n\n");
						system("pause");
						system("cls");
						break;
					}
		}
		
	}
	while (opcion > 0 || opcion < 4);
		
}		

void RegistrarProfesional(FILE *arch)
{	
	system("cls");
	
	arch = fopen("Profesionales.dat", "a+b");
	
	Usuarios sesion;
	char primerCaracter;
	
	int c_mayus = 0;
	int c_digitos = 0;
	int longitud = 0;
	int pos = 0;
	
	bool tamanio = false;
	bool bandera = false;
	bool minusculas = false;
	bool mayusculas = false;
	bool digitos = false;
	bool consecutividad = false;
	
	printf("--REGISTRO DE PROFESIONAL--");	
		
	printf("\n\nAPELLIDO Y NOMBRE: ");
	_flushall();
	gets(sesion.apellidoYNombre);
	
	printf("ID: ");
	scanf("%d", &sesion.id);
	
	printf("DNI: ");
	scanf("%d", &sesion.Dni);
	
	printf("TELEFONO: ");
	_flushall();
	gets(sesion.telefono);
			
	// Snippets de usuario.		
	do
	{

		bandera = false;
		
		c_mayus = 0;
		c_digitos = 0;
		longitud = 0;
		
		system("cls");
		printf("--REGISTRO DE PROFESIONAL--\n\n");
		printf("NOMBRE DE USUARIO: ");
		_flushall();
		gets(sesion.usuario);
		
		// -----CALCULAR LONGITUD CADENA------	
		longitud = strlen(sesion.usuario);	
		
		if(longitud < 10)
		{
			tamanio = true;
		}
		// -----------------------------------	
		
		// -----PRIMER CARACTER EN MINUSCULAS------	
		primerCaracter = sesion.usuario[0];	
		for (int i=0; i<27; i++)
		{
			if(primerCaracter == vec_minus[i])
			{
				minusculas = true;	
			}	
		}
		// -----------------------------------------	
		
		// -------CONDICION DE 2 LETRAS MAYUSCULAS------	
		for (int i=0; i<27; i++)
		{
			for(int c=0; c<longitud; c++)
			{
				if(sesion.usuario[c] == vec_mayus[i])
				{
					c_mayus++;
				}				
			}
		}
			
		if(c_mayus >= 2)
		{
			mayusculas = true;
		}
		
		//printf("Letras mayusculas: %d", c_mayus);
		// --------------------------------------------	
		
		// -----CONDICION DE 3 DIGITOS COMO MAXIMO-------
		for (int i=0; i<11; i++)
		{
			for(int c=0; c<longitud; c++)
			{
				if(sesion.usuario[c] == vec_digitos[i])
				{
					c_digitos++;
				}				
			}
			
		}
		
		//printf("\ncantidad de digitos: %d", c_digitos);
		
		if(c_digitos <= 3)
		{
			digitos = true;
		}
		// --------------------------------------------
		
		// ----------------------------REVALORIZAR BANDERA---------------------------------
		if(digitos == true && mayusculas == true && minusculas == true && tamanio == true)
		{
			bandera = true;
		}
		// --------------------------------------------------------------------------------
		
		/*
		if(bandera == true)
		{
			printf("\n\nSe cumplen las 3 condiciones");
		}
		else
		{
			printf("\n\nNo se cumplen las 3 condiciones.");
		}
		*/	
		if(bandera == false)
		{
			system("cls");
			printf("Nombre de usuario incorrecto.");
			printf("\n\nSINTAXIS:");
			printf("\n\tDebe comenzar con una letra minuscula.");
			printf("\n\tDebe tener al menos 2 letras mayusculas.");
			printf("\n\tDebe tener como maximo 3 digitos.");
			printf("\n\nIngrese nuevamente...");
			printf("\n\n");
			system("pause");
			system("cls");	
		}		
	}
	while(bandera == false);
	
	// Snippets de clave.
	do
	{	
		bandera = false;
		digitos = false;
		tamanio = false;
		consecutividad = false;
		
		longitud = 0;
		pos = 0;
		system("cls");
		printf("--REGISTRO DE PROFESIONAL--\n\n");
		printf("CLAVE: ");
		_flushall();
		gets(sesion.clave);
		
		// ------CALCULAR LONGITUD CADENA--------
		longitud = strlen(sesion.clave);
		if(longitud >= 6 && longitud <= 32)
		{
			tamanio = true;
		}
		// --------------------------------------
		
		// -------------------------------DIGITOS CONSECUTIVOS----------------------------	
		for (int a=0; a<longitud; a++)
		{
			for(int b=0; b<10; b++)
			{
				if(sesion.clave[a] == vec_digitos[b])
				{
					for(int c=0; c<10; c++)
					{
						if(sesion.clave[a+1] == vec_digitos[c])
						{
							for(int d=0; d<10; d++)
							{
								if(sesion.clave[a+2] == vec_digitos[d])
								{
									for(int e=0; e<10; e++)
									{
										if(sesion.clave[a+3] == vec_digitos[e])
										{
											digitos = true;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		// ---------------------------------------------------------------------------
		
		// ---------------------------CONSECUTIVIDAD DE ALFABETO------------------------------------------
		for (int a=0; a<longitud; a++)
		{
			for(int b=0; b<26; b++)
			{
				if(sesion.clave[a] == vec_mayus[b] || sesion.clave[a] == vec_minus[b])
				{
					pos = b;
					for(int c=0; c<26; c++)
					{
						if(sesion.clave[a+1] == vec_mayus[pos+1] || sesion.clave[a+1] == vec_minus[pos+1])
						{
							consecutividad = true;
						}
					}
				}
			}
		}
		// ----------------------------------------------------------------------------------------------
		
		// ------------REVALORIZAR BANDERA---------------
		if (tamanio == true)
		{
			if(consecutividad == true || digitos == true)
			{
				bandera = false;
			}
			else
			{
				bandera = true;
			}
		}
		else
		{
			bandera = false;
		}
		// ----------------------------------------------
		
		if(bandera == false)
		{
			system("cls");
			printf("Clave incorrecta.");
			printf("\n\nSINTAXIS:");
			printf("\n\tTener entre 6 y 32 caracteres.");
			printf("\n\tTener letra mayuscula.");
			printf("\n\tSolo caracteres alfanumericos.");
			printf("\n\tNo tener 4 numeros consecutivos.");
			printf("\n\tNo tener 2 letras de orden alfabetico consecutivas.");
			printf("\n\nIngrese nuevamente...");
			printf("\n\n");
			system("pause");
			system("cls");	
		}
			
	}
	while(bandera == false);
	
	fwrite(&sesion, sizeof(sesion), 1, arch);
	
	system("cls");
	printf("Usuario registrado exitosamente.");
	printf("\n\n");
	system("pause");
	fclose(arch);
}

void RegistrarRecepcionista(FILE *arch)
{
	system("cls");
	
	arch = fopen("Recepcionistas.dat", "a+b");
	
	Usuarios sesion;
	char primerCaracter;
	
	int c_mayus = 0;
	int c_digitos = 0;
	int longitud = 0;
	int pos = 0;
	
	bool tamanio = false;
	bool bandera = false;
	bool minusculas = false;
	bool mayusculas = false;
	bool digitos = false;
	bool consecutividad = false;
	
	system("cls");
	printf("--REGISTRO DE RECEPCIONISTA--\n\n");
	printf("APELLIDO Y NOMBRE: ");
	_flushall();
	gets(sesion.usuario);
	
	printf("ID: ");
	scanf("%d", &sesion.id);
	
	printf("DNI: ");
	scanf("%d", &sesion.Dni);
	
	printf("TELEFONO: ");
	_flushall();
	gets(sesion.telefono);
		
	// Snippets de usuario.		
	do
	{
		bandera = false;
		
		c_mayus = 0;
		c_digitos = 0;
		longitud = 0;
		
		system("cls");
		printf("--REGISTRO DE RECEPCIONISTA--\n\n");
		printf("NOMBRE DE USUARIO: ");
		_flushall();
		gets(sesion.usuario);
		

		// -----CALCULAR LONGITUD CADENA------	
		longitud = strlen(sesion.usuario);	
		
		if(longitud < 10)
		{
			tamanio = true;
		}
		// -----------------------------------	
		
		// -----PRIMER CARACTER EN MINUSCULAS------	
		primerCaracter = sesion.usuario[0];	
		for (int i=0; i<27; i++)
		{
			if(primerCaracter == vec_minus[i])
			{
				minusculas = true;	
			}	
		}
		// -----------------------------------------	
		
		// -------CONDICION DE 2 LETRAS MAYUSCULAS------	
		for (int i=0; i<27; i++)
		{
			for(int c=0; c<longitud; c++)
			{
				if(sesion.usuario[c] == vec_mayus[i])
				{
					c_mayus++;
				}				
			}
		}
			
		if(c_mayus >= 2)
		{
			mayusculas = true;
		}
		
		//printf("Letras mayusculas: %d", c_mayus);
		// --------------------------------------------	
		
		// -----CONDICION DE 3 DIGITOS COMO MAXIMO-------
		for (int i=0; i<11; i++)
		{
			for(int c=0; c<longitud; c++)
			{
				if(sesion.usuario[c] == vec_digitos[i])
				{
					c_digitos++;
				}				
			}
			
		}
		
		//printf("\ncantidad de digitos: %d", c_digitos);
		
		if(c_digitos <= 3)
		{
			digitos = true;
		}
		// --------------------------------------------
		
		// ------------------------------REVALORIZAR BANDERA-------------------------------
		if(digitos == true && mayusculas == true && minusculas == true && tamanio == true)
		{
			bandera = true;
		}
		// --------------------------------------------------------------------------------
		
		/*
		if(bandera == true)
		{
			printf("\n\nSe cumplen las 3 condiciones");
		}
		else
		{
			printf("\n\nNo se cumplen las 3 condiciones.");
		}
		*/	
		if(bandera == false)
		{
			system("cls");
			printf("Nombre de usuario incorrecto.");
			printf("\n\nSINTAXIS:");
			printf("\n\tDebe comenzar con una letra minuscula.");
			printf("\n\tDebe tener al menos 2 letras mayusculas.");
			printf("\n\tDebe tener como maximo 3 digitos.");
			printf("\n\nIngrese nuevamente...");
			printf("\n\n");
			system("pause");
			system("cls");	
		}		
	}
	while(bandera == false);
	
	// Snippets de clave.
	do
	{	
		bandera = false;
		digitos = false;
		tamanio = false;
		consecutividad = false;
		
		longitud = 0;
		pos = 0;
		
		system("cls");
		printf("--REGISTRO DE RECEPCIONISTA--\n\n");
		printf("CLAVE: ");
		_flushall();
		gets(sesion.clave);
		
		// ------CALCULAR LONGITUD CADENA--------
		longitud = strlen(sesion.clave);
		if(longitud >= 6 && longitud <= 32)
		{
			tamanio = true;
		}
		// --------------------------------------
		
		// -------------------------------DIGITOS CONSECUTIVOS----------------------------	
		for (int a=0; a<longitud; a++)
		{
			for(int b=0; b<10; b++)
			{
				if(sesion.clave[a] == vec_digitos[b])
				{
					for(int c=0; c<10; c++)
					{
						if(sesion.clave[a+1] == vec_digitos[c])
						{
							for(int d=0; d<10; d++)
							{
								if(sesion.clave[a+2] == vec_digitos[d])
								{
									for(int e=0; e<10; e++)
									{
										if(sesion.clave[a+3] == vec_digitos[e])
										{
											digitos = true;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		// ---------------------------------------------------------------------------
		
		// ---------------------------CONSECUTIVIDAD DE ALFABETO------------------------------------------
		for (int a=0; a<longitud; a++)
		{
			for(int b=0; b<26; b++)
			{
				if(sesion.clave[a] == vec_mayus[b] || sesion.clave[a] == vec_minus[b])
				{
					pos = b;
					for(int c=0; c<26; c++)
					{
						if(sesion.clave[a+1] == vec_mayus[pos+1] || sesion.clave[a+1] == vec_minus[pos+1])
						{
							consecutividad = true;
						}
					}
				}
			}
		}
		// ----------------------------------------------------------------------------------------------
		
		// ------------REVALORIZAR BANDERA---------------
		if (tamanio == true)
		{
			if(consecutividad == true || digitos == true)
			{
				bandera = false;
			}
			else
			{
				bandera = true;
			}
		}
		else
		{
			bandera = false;
		}
		// ----------------------------------------------
		
		if(bandera == false)
		{
			system("cls");
			printf("Clave incorrecta.");
			printf("\n\nSINTAXIS:");
			printf("\n\tTener entre 6 y 32 caracteres.");
			printf("\n\tTener letra mayuscula.");
			printf("\n\tSolo caracteres alfanumericos.");
			printf("\n\tNo tener 4 numeros consecutivos.");
			printf("\n\tNo tener 2 letras de orden alfabetico consecutivas.");
			printf("\n\nIngrese nuevamente...");
			printf("\n\n");
			system("pause");
			system("cls");	
		}
			
	}
	while(bandera == false);
	
	fwrite(&sesion, sizeof(sesion), 1, arch);
	
	system("cls");
	printf("Usuario registrado exitosamente.");
	printf("\n\n");
	system("pause");
	
	fclose(arch);
}

// **************************************



// *************************************** ESPACIOS *******************************************************

void ModuloEspacios(bool &bandera_sesion_p, bool &bandera_sesion_r, bool bandera_cliente, FILE *arch)
{	
	Cliente sesion;
	
	int opcion = 0;
	int posicion = 0;
	
	if(bandera_sesion_p == false)
	{
		do 
		{
			bandera_sesion_p = InicioSesion_P(arch);
			
			if(bandera_sesion_p == false)
				MenuPyR(bandera_sesion_p, bandera_sesion_r, bandera_cliente,arch);	
		}	
		while(bandera_sesion_p == false);		
	}
		
	do
	{		
		system("cls");
		printf("--MODULO ESPACIOS--");
		
		/*printf("\n\nVARIABLE POSICION: %d: ", posicion);
		printf("\n\n");			
		system("pause");*/
		
		posicion = posicion - 340;
		
		if(bandera_cliente == true && bandera_sesion_p == true)
		{		
			arch = fopen("Clientes.dat", "r+b");
			fseek(arch, posicion, SEEK_CUR);
			fread(&sesion, sizeof(sesion), 1, arch);
			
			posicion = ftell(arch);
			/*printf("La posicion del puntero es: %d", posicion);
			printf("\n\n");
			system("pause");*/
		
			printf("\n\n\tDATOS DEL CLIENTE:\n");
			printf("\n\t\tNombre: %s", sesion.apellidoYNombre);
			printf("\n\t\tDomicilio: %s", sesion.domicilio);
			printf("\n\t\tDNI: %d", sesion.dniCliente);
			printf("\n\t\tLocalidad: %s", sesion.localidad);
			printf("\n\t\tFecha de nacimiento: %d/%d/%d", sesion.fechaDeNacimiento.dia, sesion.fechaDeNacimiento.mes, sesion.fechaDeNacimiento.anio);
			printf("\n\t\tPeso: %.2f", sesion.peso);
			printf("\n\t\tTelefono: %s", sesion.telefono);
		}
		
		printf("\n\n1- BUSCAR CLIENTE");
		printf("\n2- VISUALIZAR INFORME DE TURNOS");
		printf("\n3- REGISTRAR EVOLUCION DEL TRATAMIENTO");
		
		printf("\n\n4- CERRAR SESION");	
		printf("\n\n5- VOLVER AL MENU PROFESIONALES/RECEPCIONISTAS");
		printf("\n6- CERRAR APLICACION");
		
		printf("\n\nSELECCIONE UNA OPCION: ");
		scanf("%d", &opcion);
		
		switch( opcion )
		{
			case 1:
					{
						bandera_cliente = BuscarCliente(arch, posicion);
						break;
					}
			case 2:
					{
						break;
					}					
			case 3:
					{
						break;
					}
			case 4:
					{
						cadena centinela; 
						
						system("cls");
						printf("Desea cerrar sesion(SI|NO): ");
						_flushall();
						gets(centinela);
						strupr(centinela);
						
						if(strcmp(centinela, "SI") == 0)
						{
							bandera_sesion_p = false;
							bandera_cliente = false;
							MenuPyR(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch);
						}
					}
			case 5: { MenuPyR(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch); }
					
			case 6:
					{
						system("cls");
						printf("Finalizando...");
						printf("\n\n");
						system("pause");
						exit(EXIT_SUCCESS);
					}
			default:
					{
						system("cls");
						printf("Opcion incorrecta. Ingrese nuevamente.");
						printf("\n\n");
						system("pause");
						system("cls");
						break;
					}
		}
		
	}
	while (opcion > 1 || opcion < 6);		
}

bool InicioSesion_P(FILE *arch)
{
	Usuarios sesion;
	
	cadena usuario;
	cadena clave; 
	
	bool bandera = false;

	arch = fopen("Profesionales.dat", "rb");
	
	if(arch == NULL)
	{
		system("cls");
		printf("Error. El archivo 'Profesionales.dat' no existe...");
		printf("\n\n(Tiene que registrar un usuario profesional).");
		printf("\n\n");
		system("pause");
	}
	else
	{
		system("cls");
		printf("NOMBRE DE USUARIO: ");
		_flushall();
		gets(usuario);
		
		printf("CLAVE: ");
		_flushall();
		gets(clave);
		
		rewind(arch);
		fread(&sesion, sizeof(sesion), 1, arch);
				
		while(!feof(arch) && bandera == false)
		{
			if(strcmp(usuario, sesion.usuario) == 0 && strcmp(clave, sesion.clave) == 0)
			{
				system("cls");
				printf("Se ha iniciado sesion exitosamente...");
				printf("\n\n");
				system("pause");
				system("cls");
				bandera = true;
				break;
			}
			else
			{
				fread(&sesion, sizeof(sesion), 1, arch);	
			}
		}
		
		if(bandera == false)
		{
			system("cls");
			printf("Usuario y/o contraseña incorrecto/s...");
			printf("\n\n");
			system("pause");
			system("cls");	
		}					
		
		return bandera;		
	}

	fclose(arch);
}

bool BuscarCliente(FILE *arch, int &posicion)
{
	Cliente sesion;
	cadena busqueda;
	
	bool bandera = false;
	
	arch = fopen("Clientes.dat", "r+b");
	if(arch == NULL)
	{
		system("cls");
		printf("Error. El archivo 'Clientes.dat' no existe...");
		printf("\n\n(Tiene que registrar al menos un cliente).");
		printf("\n\n");
		system("pause");
	}
	else
	{
		system("cls");
		printf("INGRESE EL CLIENTE A BUSCAR: ");
		_flushall();
		gets(busqueda);
		
		fread(&sesion, sizeof(sesion), 1, arch);
		rewind(arch);
		
		while(!feof(arch) && bandera == false)
		{
			if( strcmp(busqueda, sesion.apellidoYNombre) == 0 )
			{
				system("cls");
				printf("Se encontro el cliente exitosamente...");
				printf("\n\n");
				system("pause");
				
				/*printf("\n\n\tDATOS DEL CLIENTE:\n");
				printf("\n\t\tNombre: %s", sesion.apellidoYNombre);
				printf("\n\t\tDomicilio: %s", sesion.domicilio);
				printf("\n\t\tDNI: %d", sesion.dniCliente);
				printf("\n\t\tLocalidad: %s", sesion.localidad);
				printf("\n\t\tFecha de nacimiento: %d/%d/%d", sesion.fechaDeNacimiento.dia, sesion.fechaDeNacimiento.mes, sesion.fechaDeNacimiento.anio);
				printf("\n\t\tPeso: %.2f", sesion.peso);
				printf("\n\t\tTelefono: %s", sesion.telefono);
				printf("\n\n");
				system("pause");*/
				
				posicion = ftell(arch);
				/*printf("\n\nLa posicion del puntero es: %d", posicion);
				printf("\n\n");
				system("pause");*/
				
				system("cls");
				bandera = true;	
				break;	
			}
			else
			{
				fread(&sesion, sizeof(sesion), 1, arch);			
			}
		}
		
		if(bandera == false)
		{
			system("cls");
			printf("No se encontro el cliente ingresado...");
			printf("\n\n");
			system("pause");
			system("cls");
		}		
	}
	
	return bandera;
	fclose(arch);
}

// *********************************************************************************************************



// *************************************** RECEPCIONISTAS **************************************************

void ModuloRecepcionistas(bool &bandera_sesion_p, bool &bandera_sesion_r, bool bandera_cliente, FILE *arch)
{
	if(bandera_sesion_r == false)
	{
		do 
		{
			bandera_sesion_r = InicioSesion_R(arch);
			
			if(bandera_sesion_r == false)
				MenuPyR(bandera_sesion_r, bandera_sesion_r, bandera_cliente,arch);	
		}	
		while(bandera_sesion_r == false);		
	}
		
	int opcion = 0;
	
	do
	{
		system("cls");
		printf("--MODULO RECEPCION--");
		printf("\n\n1- REGISTRAR CLIENTE");
		printf("\n2- REGISTRAR TURNO");
		printf("\n3- LISTADO DE ATENCIONES POR PROFESIONAL Y FECHA");
		
		printf("\n\n4- CERRAR SESION");
		printf("\n\n5- VOLVER AL MENU PROFESIONALES/RECEPCIONISTAS");
		printf("\n6- CERRAR APLICACION");
		
		printf("\n\nSELECCIONE UNA OPCION: ");
		scanf("%d", &opcion);
		
		switch( opcion )
		{
			case 1:
					{
						system("cls");
						RegistrarCliente(arch);
						printf("\n\nLOS DATOS SE HAN REGISTRADO EXITOSAMENTE");
						printf("\n\n");
						system("pause");
						break;
					}
			case 2:
					{
						break;
					}
			case 3:
					{
						break;
					}
			case 4:
					{
						cadena centinela; 
						
						system("cls");
						printf("Desea cerrar sesion(SI|NO): ");
						_flushall();
						gets(centinela);
						strupr(centinela);
						
						if(strcmp(centinela, "SI") == 0)
						{
							bandera_sesion_r = false;
							MenuPyR(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch);
						}
						
						break;							
					}
					
			case 5:
					{
						MenuPyR(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch);
					}
			case 6:
					{
						system("cls");
						printf("Finalizando...");
						printf("\n\n");
						system("pause");
						exit(EXIT_SUCCESS);
					}
			default:
					{
						system("cls");
						printf("Opcion incorrecta. Ingrese nuevamente.");
						printf("\n\n");
						system("pause");
						system("cls");
						break;
					}
		}
		
	}
	while (opcion > 1 || opcion < 6);	
}

bool InicioSesion_R(FILE *arch)
{	
	Usuarios sesion;

	cadena usuario;
	cadena clave; 
	bool bandera = false;

	arch = fopen("Recepcionistas.dat", "rb");
	
	if(arch == NULL)
	{
		system("cls");
		printf("Error. El archivo 'Recepcionistas.dat' no existe...");
		printf("\n\n(Tiene que registrar un usuario recepcionista).");
		printf("\n\n");
		system("pause");
	}
	else
	{
		system("cls");
		printf("NOMBRE DE USUARIO: ");
		_flushall();
		gets(usuario);
		
		printf("CLAVE: ");
		_flushall();
		gets(clave);
		
		rewind(arch);
		fread(&sesion, sizeof(sesion), 1, arch);
				
		while(!feof(arch) && bandera == false)
		{
			if(strcmp(usuario, sesion.usuario) == 0 && strcmp(clave, sesion.clave) == 0)
			{
				system("cls");
				printf("Se ha iniciado sesion exitosamente...");
				printf("\n\n");
				system("pause");
				system("cls");
				bandera = true;
				break;
			}
			else
			{
				fread(&sesion, sizeof(sesion), 1, arch);	
			}
		}
		
		if(bandera == false)
		{
			system("cls");
			printf("Usuario y/o contraseña incorrecto/s.");
			printf("\n\n");
			system("pause");
			system("cls");	
		}					
	
		return bandera;		
	}

		
	fclose(arch);
}

void RegistrarCliente(FILE *arch)
{	
	Cliente aux_c;
	
	arch = fopen("Clientes.dat","a+b");
	
	printf("--INGRESE DATOS DEL CLIENTE--");
	
	printf("\n\nApellido y Nombre: ");
	_flushall();
	gets(aux_c.apellidoYNombre);
	
	printf("DNI: ");
	scanf("%d",&aux_c.dniCliente);
	
	printf("\nFecha de nacimiento: ");
	
	int existe=0;
	
	do{
		printf("\nDia: ");
		scanf("%d", &aux_c.fechaDeNacimiento.dia);
		
		if(aux_c.fechaDeNacimiento.dia<=0 || aux_c.fechaDeNacimiento.dia>31){
			printf("\n\n");
			printf("El valor ingreado no pertenece a ningun día posible, Por favor ingresar nuevamente");
			printf("\n\n");
			system("pause");
		}
	}while(aux_c.fechaDeNacimiento.dia<=0 || aux_c.fechaDeNacimiento.dia>31);
	
	do{
		
		printf("\nMes: ");
		scanf("%d",&aux_c.fechaDeNacimiento.mes);
		if(aux_c.fechaDeNacimiento.mes <=0 || aux_c.fechaDeNacimiento.mes > 12){
			    printf("\n\n");
			    printf("El valor ingresado no corresponde a ningun mes del anio. Por favor ingresar nuevamenete");
			    printf("\n\n");
			    system("pause");
				}else{
				existe=1;
				if(aux_c.fechaDeNacimiento.mes == 3){
						if(aux_c.fechaDeNacimiento.dia>29){
							existe=0;
			                printf("\n\n");
			                printf("El día elegido no corresponde a una posible fecha del mes: [%d]",aux_c.fechaDeNacimiento.mes);
		                    printf("\nPor favor ingresar mes nuevamente");
			                printf("\n\n");
			                system("pause");
						    }
		
		        }
			  }
				
		
	}while(existe==0);
	
	
	do{
		printf("\nAnio: ");
		scanf("%d",&aux_c.fechaDeNacimiento.anio);
		if(aux_c.fechaDeNacimiento.anio<=0 || aux_c.fechaDeNacimiento.anio>2021){
			printf("\n\n");
			printf("El valor ingresado no es valido. Por favor ingresar nuevamente");
			printf("\n\n");
			system("pause");
		}
	}while(aux_c.fechaDeNacimiento.anio<=0 || aux_c.fechaDeNacimiento.anio>2021);
	
	printf("\npeso: ");
	scanf("%f",&aux_c.peso);
	printf("Domicilio: ");
	_flushall();
	gets(aux_c.domicilio);
	printf("Localidad: ");
	_flushall();
	gets(aux_c.localidad);
	
	do{
	printf("Telefono: ");
	_flushall();
	gets(aux_c.telefono);
	if(strlen(aux_c.telefono)>14 || strlen(aux_c.telefono)<14){
		    printf("\n\n");
			printf("Ingresar número de telefono valido");
			printf("tener en cuenta que debe haber un espacio entre el codigo del pais y el resto del número");
	     	printf("(Ej:+54 3811234567 )");
			printf("\n\n");
			system("pause");
	}
	
    }while(strlen(aux_c.telefono)>14 || strlen(aux_c.telefono)<14);
    
    fwrite(&aux_c, sizeof(aux_c), 1, arch);
    
    fclose(arch);
}

// ********************************************************************************************************
















