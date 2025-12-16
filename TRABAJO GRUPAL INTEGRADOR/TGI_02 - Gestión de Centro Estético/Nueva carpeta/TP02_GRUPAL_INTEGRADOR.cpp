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
char vec_alfanumeros[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
char vec_digitos[] = "0123456789";	

struct Fecha
{
	float dd;
	float mm;
	float aaaa;	
};

struct Usuarios
{
	int id;
	int Dni;
	int c_Turnos;
	int c_Operaciones;
		
	cadena usuario;
	cadena clave;
	cadena apellidoYNombre;
	cadena telefono;
};

struct Cliente
{
	float peso;
	
	int dniCliente;
	
	cadena apellidoYNombre;
	cadena domicilio;
	cadena localidad;
	cadena telefono; 
	
	Fecha fechaDeNacimiento;
};

struct Turnos
{
	int idProfesional;
	int dniCliente;
	
	char detalleDeAtencion[380];
	
	Fecha fechaDeTurno;
};

// ----------------------------------------------------------------------------------------------------------------------------------------------------

// --Menús principales--
	void MenuPrincipal(FILE *arch);
	void MenuPyR(bool &bandera_sesion_p, bool &bandera_sesion_r, bool bandera_cliente,FILE *arch, int posicion, int base, int aux_id);

// --Administración--
	void MenuAdministracion(FILE *arch);
	void RegistrarProfesional(FILE *arch);
	void RegistrarRecepcionista(FILE *arch);
	void Atenciones(FILE *arch);
	void Ranking(FILE *arch);

// --Módulo: Espacios--
	void ModuloEspacios(bool &bandera_sesion_p, bool &bandera_sesion_r, bool bandera_cliente, FILE *arch, int aux_id, int posicion, int base);
	bool InicioSesion_P(FILE *arch, int &aux_id);
	bool BuscarCliente(FILE *arch, int &posicion, int &base);
	void InformeTurnos(FILE *arch, bool bandera_cliente);
	void RegistrarTratamiento(FILE *arch, bool bandera_cliente, int aux_id, int posicion, bool bandera_sesion_p, bool bandera_sesion_r, int base);

// --Módulo: Recepcionistas--
	void ModuloRecepcionistas(bool &bandera_sesion_p, bool &bandera_sesion_r, bool bandera_cliente, FILE *arch, int posicion, int base, int aux_id);
	void RegistrarCliente(FILE *arch);
	void RegistrarTurno(FILE *arch, bool &bandera_sesion_p, bool &bandera_sesion_r, bool bandera_cliente, int posicion, int base, int aux_id);
	void ListaTurnos(FILE *arch, bool &bandera_sesion_p, bool &bandera_sesion_r, bool bandera_cliente, int posicion, int base, int aux_id);
	bool InicioSesion_R(FILE *arch);

// ----------------------------------------------------------------------------------------------------------------------------------------------------

main()
{
	FILE *archivo;
					
	MenuPrincipal(archivo);	
}

// ********************************************************* MENÚS PRINCIPALES ****************************************************************

void MenuPrincipal(FILE *arch)
{	
	system("color F0");
	
	bool bandera_sesion_p = false;
	bool bandera_sesion_r = false;
	bool bandera_cliente = false;
	
	int base = 0;
	int posicion = 0;
	int opcion = 0;
	int aux_id = 0;
	
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
			case 1: { MenuPyR(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch, posicion, base, aux_id); }
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

void MenuPyR(bool &bandera_sesion_p, bool &bandera_sesion_r, bool bandera_cliente,FILE *arch, int posicion, int base, int aux_id)
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
			case 1: { ModuloEspacios(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch, aux_id, posicion, base); }
			case 2: { ModuloRecepcionistas(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch, posicion, base, aux_id); }
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

// ********************************************************************************************************************************************



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
						Atenciones(arch);
						break;
					}
			case 4:
					{	
						Ranking(arch);
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
	
	bool centinela = false;
	bool tamanio = false;
	bool bandera = false;
	bool minusculas = false;
	bool mayusculas = false;
	bool digitos = false;
	bool consecutividad = false;
	bool band_simbolo = false;
	
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
	
	sesion.c_Operaciones = 0;
	sesion.c_Turnos = 0;
			
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
		
		if(longitud <= 10)
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
		for (int i=0; i<10; i++)
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
		
		// ----------  SIMBOLOS  --------------
		
			bool bandera1 = false;
			band_simbolo = false;
			bandera = false;
			
			cadena aux = {NULL};
			int l = 0;
			
			   
			for(int i=0; i<62;i++)
			{
				for(int j=0; j<longitud; j++)
				{
					if(sesion.usuario[j] == vec_alfanumeros[i]) //g  //a
					{
						printf("HOLA");
						system("pause");
						
						aux[l] = sesion.usuario[j];
						l++;
						
						printf("\n\nelemento %d del vector auxiliar: %c", l, aux[l-1]);
						system("pause");
						
						for(int k=0; k<8; k++)
						{
							if(sesion.usuario[j] != vec_simbolos[k]) 
							{
								bandera1 = true;
							}
						}
					}
				}
			}
			
			if(bandera1 == true)
				band_simbolo = false;
			else 
				band_simbolo = true;

		// --------------------------------------------
		
		
		// ----------------------------REVALORIZAR BANDERA---------------------------------
		if(digitos == true && mayusculas == true && minusculas == true && tamanio == true && band_simbolo == true)
		{
			bandera = true;
		}
		else
		{
			bandera = false;
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
	
	/*arch = fopen("Profesionales.dat", "rb");
	rewind(arch);
	
	fread(&sesion, sizeof(sesion), 1, arch);
	
	while(!feof(arch))
	{
		printf("%d", sesion.id);
		system("pause");
		
		fread(&sesion, sizeof(sesion), 1, arch);
	}
	
	printf("\n\n");
	system("pause");*/
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

void Atenciones(FILE *arch)
{
	FILE *archC;
	FILE *archP;
	
	arch = fopen("Turnos.dat", "rb");
	archC = fopen("Clientes.dat", "rb");
	archP = fopen("Profesionales.dat", "rb");
	
	if(arch == NULL)
	{
		system("cls");
		printf("Error. El archivo 'Turnos.dat' no existe...");
		printf("\n\n(Tiene que registrar al menos un turno).");
	}
	else if(archC == NULL)
	{
		system("cls");
		printf("Error. El archivo 'Clientes.dat' no existe...");
		printf("\n\n(Tiene que registrar al menos un cliente).");		
	}
	else if(archP == NULL)
	{
		system("cls");
		printf("Error. El archivo 'Profesionales.dat' no existe...");
		printf("\n\n(Tiene que registrar al menos un usuario profesional).");	
	}	
	else
	{
		Turnos turnos;
		Usuarios profesional;
		Cliente cliente;
		
		cadena mes; 
		
		bool bandera = false;
		float aux_mes;
		
		system("cls");
		printf("INGRESE EL MES A ANALIZAR: ");
		_flushall();
		gets(mes);
		strupr(mes);
		
		if(strcmp(mes, "ENERO") == 0)
		{
			aux_mes = 1;
			bandera = true;	
		}	
		else if(strcmp(mes, "FEBRERO") == 0)
		{
			aux_mes = 2;
			bandera = true;
		}	
		else if(strcmp(mes, "MARZO") == 0)
		{
			aux_mes = 3;
			bandera = true;	
		}		
		else if(strcmp(mes, "ABRIL") == 0)
		{
			aux_mes = 4;
			bandera = true;
		}		
		else if(strcmp(mes, "MAYO") == 0)
		{
			aux_mes = 5;
			bandera = true;
		}	
		else if(strcmp(mes, "JUNIO") == 0)
		{
			aux_mes = 6;
			bandera = true;
		}
		else if(strcmp(mes, "JULIO") == 0)
		{
			aux_mes = 7;
			bandera = true;
		}
		else if(strcmp(mes, "AGOSTO") == 0)
		{
			aux_mes = 8;
			bandera = true;
		}
		else if(strcmp(mes, "SEPTIEMBRE") == 0)
		{
			aux_mes = 9;
			bandera = true;
		}
		else if(strcmp(mes, "SEPTIEMBRE") == 0)
		{
			aux_mes = 10;
			bandera = true;
		}
		else if(strcmp(mes, "NOVIEMBRE") == 0)
		{
			aux_mes = 11;
			bandera = true;
		}
		else if(strcmp(mes, "DICIEMBRE") == 0)
		{
			aux_mes = 12;
			bandera = true;
		}
		else if(bandera == false)
		{
			system("cls");
			printf("El mes ingresado es incorrecto.");
			printf("\n\nVolviendo al menu...");
			printf("\n\n");
			system("pause");
			MenuAdministracion(arch);
		}
		
		
		bandera = false;																		
		
		rewind(arch);
		fread(&turnos, sizeof(turnos), 1, arch);
		
		printf("\nPACIENTE\t|\tFECHA DEL TURNO\t\t|\tPROFESIONAL A CARGO\t|\tDESCRIPCION DE ATENCION\n\n");
		
		while(!feof(arch))
		{
			if( (turnos.fechaDeTurno.mm == aux_mes) && (strlen(turnos.detalleDeAtencion) > 0) )
			{
				rewind(archC);	
				fread(&cliente, sizeof(cliente), 1, archC);
				
				while(!feof(archC))
				{
					if(turnos.dniCliente == cliente.dniCliente)
					{
						printf("%s", cliente.apellidoYNombre);	
						break;
					}
					
					fread(&cliente, sizeof(cliente), 1, archC);
				}	
				
				printf("\t\t%.0f/%.0f/%.0f", turnos.fechaDeTurno.dd, turnos.fechaDeTurno.mm, turnos.fechaDeTurno.aaaa);
				
				rewind(archP);	
				fread(&profesional, sizeof(profesional), 1, archP);
				
				while(!feof(archP))
				{
					if(turnos.idProfesional == profesional.id)
					{
						printf("\t\t\t%s", profesional.apellidoYNombre);	
						break;
					}
					
					fread(&profesional, sizeof(profesional), 1, archP);
				}
				
				printf("\t\t\t%s\n", turnos.detalleDeAtencion);
				bandera = true;
			}
			
			fread(&turnos, sizeof(turnos), 1, arch);
			
		}
		
		if(bandera == false)
		{
			system("cls");
			printf("No se realizaron atenciones en el mes ingresado...");
		}
		
	}

	fclose(arch);	
	fclose(archP);
	fclose(archC);
	
	printf("\n\n");
	system("pause");	
}

void Ranking(FILE *arch)
{
	system("cls");
	
	FILE *archT;
	
	arch = fopen("Profesionales.dat", "rb");
	archT = fopen("Turnos.dat", "rb");
	
	if(arch == NULL)
	{
		system("cls");
		printf("Error. El archivo 'Profesionales.dat' no existe...");
		printf("\n\n(Tiene que registrar un usuario profesional).");
	}
	else if(archT == NULL)
	{
		system("cls");
		printf("Error. El archivo 'Turnos.dat' no existe...");
		printf("\n\n(Tiene que registrar al menos un turno).");	
	}
	else
	{
		int i = 0;
		int longitud = 0;
		int aux = 0;
		int pos = 0;
		int mayor = -9999;
		
		bool bandera = false;
		
		Usuarios profesional;
	
		// --------------CALCULAR LONGITUD----------------------
		rewind(arch);
		fread(&profesional, sizeof(profesional), 1, arch);
		
		while(!feof(arch))
		{
			i++;
			
			fread(&profesional, sizeof(profesional), 1, arch);		
		}
		
		longitud = i;
		int vector_operaciones[longitud];
		// ----------------------------------------------------
		
		
		// -------------CARGAR OPERACIONES AL VECTOR----------------
		i = 0;
		rewind(arch);
		fread(&profesional, sizeof(profesional), 1, arch);
		
		while(!feof(arch) && bandera == false)
		{
			i++;
			vector_operaciones[i-1] = profesional.c_Operaciones;
			
			if(i > longitud)
			{
				bandera = true;
				break;	
			}
			else
			{
				fread(&profesional, sizeof(profesional), 1, arch);	
			}				
		}
		// --------------------------------------------------------
		
		/*for(i=0; i<longitud; i++)
		{
			printf("%d", vector_operaciones[i]);
			printf("\n");
		}*/
		
		
		// -------------ORDENAMIENTO DE LAS OPERACIONES EN EL VECTOR--------------
		do
		{
			bandera = false;
			
			for(int i=0; i<longitud-1; i++)
			{
				if (vector_operaciones[i] > vector_operaciones[i+1])
				{
					aux = vector_operaciones[i];
					vector_operaciones[i] = vector_operaciones[i+1];
					vector_operaciones[i+1] = aux;
					
					bandera = true;
				}
			}
		
		} 
		while(bandera == true);
		// -----------------------------------------------------------------------
		
		
		// ------------------------------LISTADO----------------------------------------------
		printf("--LISTADO DE PROFESIONALES Y ATENCIONES--\n\n");
		
		for(i=(longitud - 1); i>=0; i--)
		{		
			rewind(arch);
			fread(&profesional, sizeof(profesional), 1, arch);
			while(!feof(arch))
			{
				if(vector_operaciones[i-1] == vector_operaciones[i] || vector_operaciones[i+1] == vector_operaciones[i])
					break;
	
				else if(vector_operaciones[i] == profesional.c_Operaciones)
					printf("\t%s: %d\n", profesional.apellidoYNombre, vector_operaciones[i]);
					
				fread(&profesional, sizeof(profesional), 1, arch);	
			}	
		}
		// -----------------------------------------------------------------------------------
		
		
		// -------------------------------------------CALCULO DE MAYOR OPERACION-----------------------------------------------------------
		for(i=0; i<longitud; i++)
		{
			if(vector_operaciones[i] > mayor)
				mayor = vector_operaciones[i];
				
			pos = i;	
		}
		
		rewind(arch);
		while(!feof(arch))
		{
			if(profesional.c_Operaciones == vector_operaciones[pos])
			{
				printf("\nPROFESIONAL QUE RECIBE EL BONO: %s. [%d atencion/es]", profesional.apellidoYNombre, vector_operaciones[pos]);
				break;	
			}
				
			fread(&profesional, sizeof(profesional), 1, arch);
		}
		
		fclose(arch);
		fclose(archT);		
	}
	// ------------------------------------------------------------------------------------------------------------------------------------
	
	printf("\n\n");
	system("pause");
}

// **************************************



// ************************************************** ESPACIOS *******************************************************************************

void ModuloEspacios(bool &bandera_sesion_p, bool &bandera_sesion_r, bool bandera_cliente, FILE *arch, int aux_id, int posicion, int base)
{	
	Cliente sesion;
	
	int opcion = 0;
	int auxiliar = 0;
	int edad = 0;
	
	if(bandera_sesion_p == false)
	{
		do 
		{
			bandera_sesion_p = InicioSesion_P(arch, aux_id);
			
			if(bandera_sesion_p == false)
				MenuPyR(bandera_sesion_p, bandera_sesion_r, bandera_cliente,arch, posicion, base, aux_id);	
		}	
		while(bandera_sesion_p == false);		
	}
		
	do
	{		
		system("cls");
		printf("--MODULO ESPACIOS--");
		
		/*printf("\n\nVARIABLE POSICION BASE: %d", base);
		printf("\n\n");			
		system("pause");*/
		
		auxiliar = base;
		posicion = auxiliar - 340;
		
		/*printf("\n\nVARIABLE POSICION: %d: ", posicion);
		printf("\n\n");			
		system("pause");*/
		
		if(bandera_cliente == true && bandera_sesion_p == true)
		{		
			arch = fopen("Clientes.dat", "r+b");
			fseek(arch, posicion, SEEK_CUR);
			fread(&sesion, sizeof(sesion), 1, arch);
			
			/*posicion = ftell(arch);
			printf("La posicion del puntero es: %d", posicion);
			printf("\n\n");
			system("pause");*/
			
			edad = 2021 - sesion.fechaDeNacimiento.aaaa;
			
			printf("\n\n\tDATOS DEL CLIENTE:\n");
			printf("\n\t\tNombre: %s", sesion.apellidoYNombre);
			printf("\n\t\tDomicilio: %s", sesion.domicilio);
			printf("\n\t\tDNI: %d", sesion.dniCliente);
			printf("\n\t\tLocalidad: %s", sesion.localidad);
			//printf("\n\t\tFecha de nacimiento: %.0f/%.0f/%.0f", sesion.fechaDeNacimiento.dd, sesion.fechaDeNacimiento.mm, sesion.fechaDeNacimiento.aaaa);
			printf("\n\t\tEdad: %d", edad);
			printf("\n\t\tPeso: %.2f", sesion.peso);
			printf("\n\t\tTelefono: %s", sesion.telefono);
			printf("\n");
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
			case 1: {	bandera_cliente = BuscarCliente(arch, posicion, base);	break;	}
			
			case 2: {	InformeTurnos(arch, bandera_cliente);	break;	}
								
			case 3: {	RegistrarTratamiento(arch, bandera_cliente, aux_id, posicion, bandera_sesion_p, bandera_sesion_r, base);	break;	}
			
			case 4:
					{
						cadena centinela; 
										
						do
						{
							system("cls");
							printf("Desea cerrar sesion(SI|NO): ");
							_flushall();
							gets(centinela);
							strupr(centinela);
							
							if(strcmp(centinela, "SI") == 0)
							{
								bandera_sesion_p = false;
								bandera_cliente = false;
								MenuPyR(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch, posicion, base, aux_id);
							}
							else if(strcmp(centinela, "NO") == 0)
							{
								ModuloEspacios(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch, aux_id, posicion, base);
							}
							else if( strcmp(centinela, "SI") != 0 && strcmp(centinela, "NO") != 0 )
							{
								system("cls");
								printf("La palabra ingresada es incorrecta. Ingrese nuevamente...");
								printf("\n\n");
								system("pause");	
							}	
						}
						while( strcmp(centinela, "SI") != 0 && strcmp(centinela, "NO") != 0 );	
					}
					
			case 5: { MenuPyR(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch, posicion, base, aux_id); }
					
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

bool InicioSesion_P(FILE *arch, int &aux_id)
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
				aux_id = sesion.id;
				
				/*printf("%d", aux_id);
				printf("\n\n");
				system("pause");*/
				
				
				/*printf("Operaciones del profesional ingresado: %d", sesion.c_Operaciones);
				printf("\n\n");
				system("pause");*/
				
				/*printf("Turnos del profesional ingresado: %d", sesion.c_Turnos);
				printf("\n\n");
				system("pause");*/
					
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

bool BuscarCliente(FILE *arch, int &posicion, int &base)
{
	system("cls");
	
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
				base = posicion;
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

void InformeTurnos(FILE *arch, bool bandera_cliente)
{
	system("cls");
	
	FILE *archC;
	FILE *archP;
	
	arch = fopen("Turnos.dat", "rb");
	archC = fopen("Clientes.dat", "rb");
	archP = fopen("Profesionales.dat", "rb");
	
	if(arch == NULL)
	{
		system("cls");
		printf("Error. El archivo 'Turnos.dat' no existe...");
		printf("\n\n(Tiene que registrar al menos un turno).");
		printf("\n\n");
		system("pause");
	}
	else if(archC == NULL)
	{
		system("cls");
		printf("Error. El archivo 'Clientes.dat' no existe...");
		printf("\n\n(Tiene que registrar al menos un cliente).");
		printf("\n\n");
		system("pause");		
	}
	else if(archP == NULL)
	{
		system("cls");
		printf("Error. El archivo 'Profesionales.dat' no existe...");
		printf("\n\n(Tiene que registrar al menos un usuario profesional).");
		printf("\n\n");
		system("pause");		
	}
	else
	{
		Cliente aux_c;
		Usuarios aux_p;
		Turnos aux_t;
	    
	    printf("PACIENTE\t|\tFECHA DEL TURNO\t\t|\tPROFESIONAL A CARGO\t|\tAVANCE DEL TRATAMIENTO\n\n");
	    
		rewind(arch);
	    fread(&aux_t, sizeof(aux_t), 1, arch);
	    
		while(!feof(arch))
		{
			rewind(archC);	
			fread(&aux_c, sizeof(aux_c), 1, archC);
			
			while(!feof(archC))
			{
				if(aux_t.dniCliente == aux_c.dniCliente)
				{
					printf("%s", aux_c.apellidoYNombre);	
					break;
				}
				
				fread(&aux_c, sizeof(aux_c), 1, archC);
			}	
			
			printf("\t\t%.0f/%.0f/%.0f", aux_t.fechaDeTurno.dd, aux_t.fechaDeTurno.mm, aux_t.fechaDeTurno.aaaa);
			
			rewind(archP);	
			fread(&aux_p, sizeof(aux_p), 1, archP);
			
			while(!feof(archP))
			{
				if(aux_t.idProfesional == aux_p.id)
				{
					printf("\t\t\t%s", aux_p.apellidoYNombre);	
					break;
				}
				
				fread(&aux_p, sizeof(aux_p), 1, archP);
			}
			
			printf("\t\t\t%s\n", aux_t.detalleDeAtencion);
		
			
			fread(&aux_t, sizeof(aux_t), 1, arch);
		}
		fclose(arch);  
	
		
		printf("\n");
		system("pause");	
	}
}

void RegistrarTratamiento(FILE *arch, bool bandera_cliente, int aux_id, int posicion, bool bandera_sesion_p, bool bandera_sesion_r, int base)
{	
	system("cls");
	FILE *archT;
	FILE *archP;
	
	arch = fopen("Clientes.dat", "rb");
	archT = fopen("Turnos.dat", "r+b");
	archP = fopen("Profesionales.dat", "r+b");
	
	if(archT == NULL)
	{
		system("cls");
		printf("Error. El archivo 'Turnos.dat' no existe...");
		printf("\n\n(Tiene que registrar al menos un turno).");
		printf("\n\n");
		system("pause");
		ModuloEspacios(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch, aux_id, posicion, base);
	}	
	else if(arch == NULL)
	{
		system("cls");
		printf("Error. El archivo 'Clientes.dat' no existe...");
		printf("\n\n(Tiene que registrar al menos un cliente).");
		printf("\n\n");
		system("pause");
		ModuloEspacios(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch, aux_id, posicion, base);
	}
	else if(archP == NULL)
	{
		
		system("cls");
		printf("Error. El archivo 'Profesionales.dat' no existe...");
		printf("\n\n(Tiene que registrar al menos un profesional).");
		printf("\n\n");
		system("pause");
		ModuloEspacios(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch, aux_id, posicion, base);
	}	

	Turnos turnos;
	Cliente cliente;
	Usuarios sesion;
	
	bool bandera = false;
	bool bandera_P = false;
	bool pendientes = false;

	int opcion = 0;
	int auxiliar = 0;
	
	float dd = 0.0;
	float mm = 0.0;
	float aaaa = 0.0;
		
	sesion.id = aux_id;
	
	/*printf("Id del profesional: %d", aux_id);
	printf("\n\n");
	system("pause");*/
	
	if(bandera_cliente == false)
	{
		system("cls");
		printf("Error. No se ingreso ningun cliente.\n\n");
		printf("Volviendo al menu...");
		printf("\n\n");
		system("pause");
		ModuloEspacios(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch, aux_id, posicion, base);
	}
	else
	{
		fseek(arch, posicion, SEEK_CUR);
		fread(&cliente, sizeof(cliente), 1, arch);
			
		rewind(archT);
		fread(&turnos, sizeof(turnos), 1, archT);	
		
		pendientes = false;
		while(!feof(archT))
		{
			/*printf("Dni en archivo turnos.dat: %d", turnos.dniCliente);
			printf("\n\n");
			system("pause");
		
			printf("\n\nDni en archivo clientes.dat: %d", cliente.dniCliente);
			printf("\n\n");
			system("pause");
			
			printf("\n\nId del profesional en archivo turnos.dat: %d", turnos.idProfesional);
			printf("\n\n");
			system("pause");
		
			printf("\n\nId del profesional en archivo profesionales.dat: %d", sesion.id);
			printf("\n\n");
			system("pause");*/
			
			/*printf("posicion vale: %d", posicion);
			printf("\n\n");
			system("pause");*/
			
			if(turnos.dniCliente == cliente.dniCliente)
			{
				if(turnos.idProfesional == sesion.id)
				{
					if(strlen(turnos.detalleDeAtencion) == 0)
					{
						/*printf("\t%.0f/%.0f/%.0f", turnos.fechaDeTurno.dd, turnos.fechaDeTurno.mm, turnos.fechaDeTurno.aaaa);
						printf("\n");*/
							
						pendientes = true;									
					}
				}
			}
		
			fread(&turnos, sizeof(turnos), 1, archT);					
		}
		
		if(pendientes == false)
		{
			system("cls");
			printf("No se encontro ningun turno pendiente.\n\n");
			printf("Volviendo al menu...");
			printf("\n\n");
			system("pause");
			ModuloEspacios(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch, aux_id, posicion, base);	
		}
		else
		{
			do
			{
				
				/*printf("Id del profesional: %d", aux_id);
				printf("\n\n");
				system("pause");*/
				
				/*printf("posicion vale: %d", posicion);
				printf("\n\n");
				system("pause");*/
				
				fseek(arch, posicion, SEEK_CUR);
				fread(&cliente, sizeof(cliente), 1, arch);
			
				rewind(archT);
				fread(&turnos, sizeof(turnos), 1, archT);	
				
				pendientes = false;
				while(!feof(archT))
				{
					if(turnos.dniCliente == cliente.dniCliente)
					{
						if(turnos.idProfesional == sesion.id)
						{
							if( strlen(turnos.detalleDeAtencion) == 0 )
							{
								/*printf("\t%.0f/%.0f/%.0f", turnos.fechaDeTurno.dd, turnos.fechaDeTurno.mm, turnos.fechaDeTurno.aaaa);
								printf("\n");*/
									
								pendientes = true;									
							}
						}
					}
				
					fread(&turnos, sizeof(turnos), 1, archT);			
				}
				
				if(pendientes == false)
				{
					system("cls");
					printf("No se encontro ningun turno pendiente.\n\n");
					printf("Volviendo al menu...");
					printf("\n\n");
					system("pause");
					ModuloEspacios(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch, aux_id, posicion, base);	
				}
				
				system("cls");
				printf("--FECHAS DE TURNOS PENDIENTES DEL CLIENTE--\n\n");
				
				fseek(arch, posicion, SEEK_CUR);
				fread(&cliente, sizeof(cliente), 1, arch);
				
				rewind(archT);
				fread(&turnos, sizeof(turnos), 1, archT);
					
				pendientes = false;
				while(!feof(archT))
				{
					/*printf("Dni en archivo turnos.dat: %d", turnos.dniCliente);
					printf("\n\n");
					system("pause");
				
					printf("\n\nDni en archivo clientes.dat: %d", cliente.dniCliente);
					printf("\n\n");
					system("pause");
					
					printf("\n\nId del profesional en archivo turnos.dat: %d", turnos.idProfesional);
					printf("\n\n");
					system("pause");
				
					printf("\n\nId del profesional en archivo profesionales.dat: %d", sesion.id);
					printf("\n\n");
					system("pause");*/
					
					if(turnos.dniCliente == cliente.dniCliente)
					{
						if(turnos.idProfesional == sesion.id)
						{
							if(strlen(turnos.detalleDeAtencion) == 0)
							{
								printf("\t%.0f/%.0f/%.0f", turnos.fechaDeTurno.dd, turnos.fechaDeTurno.mm, turnos.fechaDeTurno.aaaa);
								printf("\n");
									
								pendientes = true;									
							}
						}
					}
					
					fread(&turnos, sizeof(turnos), 1, archT);			
				}
				
				if(pendientes == false)
				{
					system("cls");
					printf("No se encontro ningun turno pendiente. Volviendo al menu...");
					printf("\n\n");
					system("pause");
					ModuloEspacios(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch, aux_id, posicion, base);	
				}	
				
				printf("\n1- REGISTRAR EVOLUCION DEL TRATAMIENTO");
				printf("\n2- VOLVER AL MENU");
				
				printf("\n\nINGRESE UNA OPCION: ");
				scanf("%d", &opcion);
		
				switch( opcion )
				{
					case 1:
							{				
								system("cls");
								printf("--FECHAS DE TURNOS PENDIENTES DEL CLIENTE--\n\n");
								
								fseek(arch, posicion, SEEK_CUR);
								fread(&cliente, sizeof(cliente), 1, arch);
								
								rewind(archT);
								fread(&turnos, sizeof(turnos), 1, archT);	
								
								while(!feof(archT))
								{
									if(turnos.dniCliente == cliente.dniCliente)
									{
										if(turnos.idProfesional == sesion.id)
										{
											if(strlen(turnos.detalleDeAtencion) == 0)
											{
												printf("\t%.0f/%.0f/%.0f", turnos.fechaDeTurno.dd, turnos.fechaDeTurno.mm, turnos.fechaDeTurno.aaaa);
												printf("\n");
													
												pendientes = true;									
											}
										}
									}	
									
									fread(&turnos, sizeof(turnos), 1, archT);	
								}
														
								printf("\nINGRESE LA FECHA DEL TURNO: ");
								printf("\n\tDIA: ");
								scanf("%f", &dd);
								printf("\tMES: ");
								scanf("%f", &mm);
								printf("\tANIO: ");
								scanf("%f", &aaaa);
									
								rewind(archT);
								fread(&turnos, sizeof(turnos), 1, archT);
								
								bandera = false;
								while( !feof(archT) && bandera == false )
								{
									if(turnos.dniCliente == cliente.dniCliente && turnos.idProfesional == sesion.id) //
									{
										if(turnos.fechaDeTurno.dd == dd && turnos.fechaDeTurno.mm == mm && turnos.fechaDeTurno.aaaa == aaaa)
										{
											bandera = true;			
											fseek(archT, (long)-sizeof(turnos), SEEK_CUR);
										}	
									}
									
									if(bandera == false)
									{
										fread(&turnos, sizeof(turnos), 1, archT);	
									}
								}
								
								if(bandera == true)
								{
									printf("\nREDACTE EL AVANCE DEL TRATAMIENTO: ");
									_flushall();
									gets(turnos.detalleDeAtencion);
									
									fwrite(&turnos, sizeof(turnos), 1, archT);
									
									// Incrementar operacion del profesional
									
									/*printf("ID: %d", aux_id);
									printf("\n\n");
									system("pause");*/
									
									rewind(archP);
									
									fread(&sesion, sizeof(sesion), 1, archP);
									
									bandera_P = false;
									while(!feof(archP) && bandera_P == false)
									{
										if(aux_id == sesion.id)
										{
											bandera_P = true;
											fseek(archP, (long)-sizeof(sesion), SEEK_CUR);
											/*printf("%d", sesion.c_Operaciones);
											printf("\n\n");
											system("pause");*/
											
											sesion.c_Operaciones++;
											
										    /*printf("\n\n%d", sesion.c_Operaciones);
											printf("\n\n");
											system("pause");*/	
										}
										else
										{
											fread(&sesion, sizeof(sesion), 1, archP);	
										}
								
									}
									
									if(bandera_P == true)
									{
										fwrite(&sesion, sizeof(sesion), 1, archP);	
									}
									
									fclose(archP);
									
									system("cls");
									printf("El avance del tratamiento fue registrado exitosamente...");
									printf("\n\n");
									system("pause");
									
									// ------------------------------------------								
									
								}
								else
								{
									system("cls");
									printf("No se encontro la fecha ingresda...");
									printf("\n\n");
									system("pause");
								}
								
								break;
							}
					case 2:
							{
								ModuloEspacios(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch, aux_id, posicion, base);	
							}
					default:
							{
								system("cls");
								printf("Opcion incorrecta. Ingrese nuevamente...");
								printf("\n\n");
								system("pause");
								break;
							}											
				}
					
			}
			while(opcion >= 1 || opcion <= 2);

		
		}	

		
		
		
		
		
		
		
		
	
	}
	
	
			
	printf("\n\n");
	system("pause");	

	

	
}

// *******************************************************************************************************************************************



// *************************************** RECEPCIONISTAS *****************************************************************************************

void ModuloRecepcionistas(bool &bandera_sesion_p, bool &bandera_sesion_r, bool bandera_cliente, FILE *arch, int posicion, int base, int aux_id)
{
	if(bandera_sesion_r == false)
	{
		do 
		{
			bandera_sesion_r = InicioSesion_R(arch);
			
			if(bandera_sesion_r == false)
				MenuPyR(bandera_sesion_r, bandera_sesion_r, bandera_cliente,arch, posicion, base, aux_id);	
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
		printf("\n3- LISTADO DE TURNOS POR PROFESIONAL Y FECHA");
		
		printf("\n\n4- CERRAR SESION");
		printf("\n\n5- VOLVER AL MENU PROFESIONALES/RECEPCIONISTAS");
		printf("\n6- CERRAR APLICACION");
		
		printf("\n\nSELECCIONE UNA OPCION: ");
		scanf("%d", &opcion);
		
		switch( opcion )
		{
			case 1:
					{
						RegistrarCliente(arch);
						break;
					}
			case 2:
					{
						RegistrarTurno(arch, bandera_sesion_p, bandera_sesion_r, bandera_cliente, posicion, base, aux_id);
						break;
					}
			case 3:
					{
						ListaTurnos(arch, bandera_sesion_p, bandera_sesion_r, bandera_cliente, posicion, base, aux_id);
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
							MenuPyR(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch, posicion, base, aux_id);
						}
						
						break;							
					}
					
			case 5:
					{
						MenuPyR(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch, posicion, base, aux_id);
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
	system("cls");
	
	Cliente aux_c;
	
	arch = fopen("Clientes.dat","a+b");
	
	printf("--REGISTRO DE UN CLIENTE--");
	
	printf("\n\nAPELLIDO Y NOMBRE: ");
	_flushall();
	gets(aux_c.apellidoYNombre);
	
	printf("DNI: ");
	scanf("%d",&aux_c.dniCliente);
	
	printf("\nFECHA DE NACIMIENTO: ");
	
	int existe=0;
	
	do{
		printf("\n\tDIA: ");
		scanf("%f", &aux_c.fechaDeNacimiento.dd);
		
		if(aux_c.fechaDeNacimiento.dd<=0 || aux_c.fechaDeNacimiento.dd>31){
			printf("\n\n");
			printf("El valor ingreado no pertenece a ningun día posible, Por favor ingresar nuevamente");
			printf("\n\n");
			system("pause");
		}
	}while(aux_c.fechaDeNacimiento.dd<=0 || aux_c.fechaDeNacimiento.dd>31);
	
	do{
		
		printf("\tMES: ");
		scanf("%f",&aux_c.fechaDeNacimiento.mm);
		if(aux_c.fechaDeNacimiento.mm <=0 || aux_c.fechaDeNacimiento.mm > 12){
			    printf("\n\n");
			    printf("El valor ingresado no corresponde a ningun mes del anio. Por favor ingresar nuevamenete");
			    printf("\n\n");
			    system("pause");
				}else{
				existe=1;
				if(aux_c.fechaDeNacimiento.mm == 3){
						if(aux_c.fechaDeNacimiento.dd>29){
							existe=0;
			                printf("\n\n");
			                printf("El día elegido no corresponde a una posible fecha del mes: [%.0f]",aux_c.fechaDeNacimiento.mm);
		                    printf("\nPor favor ingresar mes nuevamente");
			                printf("\n\n");
			                system("pause");
						    }
		
		        }
			  }
				
		
	}while(existe==0);
	
	
	do{
		printf("\tANIO: ");
		scanf("%f",&aux_c.fechaDeNacimiento.aaaa);
		if(aux_c.fechaDeNacimiento.aaaa<=0 || aux_c.fechaDeNacimiento.aaaa>2021){
			printf("\n\n");
			printf("El valor ingresado no es valido. Por favor ingresar nuevamente");
			printf("\n\n");
			system("pause");
		}
	}while(aux_c.fechaDeNacimiento.aaaa<=0 || aux_c.fechaDeNacimiento.aaaa>2021);
	
	printf("\nPESO: ");
	scanf("%f",&aux_c.peso);
	printf("DOMICILIO: ");
	_flushall();
	gets(aux_c.domicilio);
	printf("LOCALIDAD: ");
	_flushall();
	gets(aux_c.localidad);
	
	do{
	printf("NUMERO DE TELEFONO: ");
	_flushall();
	gets(aux_c.telefono);
	if(strlen(aux_c.telefono)>14 || strlen(aux_c.telefono)<14){
		    printf("\n");
			printf("Error. Ingresar numero de telefono valido");
			printf("\n\n\t(Tener en cuenta que debe haber un espacio entre el codigo del pais y el resto del numero)");
	     	printf("\n\n\t(Ej:+54 3811234567)");
			printf("\n\n");
			system("pause");
			printf("\n");
	}
	
    }while(strlen(aux_c.telefono)>14 || strlen(aux_c.telefono)<14);
    
    fwrite(&aux_c, sizeof(aux_c), 1, arch);
    
    system("cls");
   	printf("Cliente registrado exitosamente...");
	printf("\n\n");
	system("pause");
    
    fclose(arch);
}

void RegistrarTurno(FILE *arch, bool &bandera_sesion_p, bool &bandera_sesion_r, bool bandera_cliente, int posicion, int base, int aux_id)
{
	system("cls");
	
	FILE *archT;
	FILE *archP;
	
	arch = fopen("Clientes.dat", "rb");
	archP = fopen("Profesionales.dat", "rb");
		
	if(arch == NULL)
	{
		system("cls");
		printf("Error. El archivo 'Clientes.dat' no existe...");
		printf("\n\n(Tiene que registrar al menos un cliente).");
		printf("\n\n");
		system("pause");
		ModuloRecepcionistas(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch, posicion, base, aux_id);
	}
	else if(archP == NULL)
	{
		
		system("cls");
		printf("Error. El archivo 'Profesionales.dat' no existe...");
		printf("\n\n(Tiene que registrar al menos un profesional).");
		printf("\n\n");
		system("pause");
		ModuloRecepcionistas(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch, posicion, base, aux_id);
	}
	
	fclose(archP);	
		
	Cliente aux_c;
	Turnos aux_t;
	Usuarios aux_p;
	
	bool bandera_P = false;
	
	int id = 0;
    int existe = 0;
    
	// ---- Comprobacion de existencia de Cliente ----
	
	archT = fopen("Turnos.dat","a+b");
	
	rewind(arch);
		
	do
	{
		printf("DNI DEL CLIENTE: ");
	    scanf("%d", &aux_t.dniCliente);	
	
    	fread(&aux_c, sizeof(aux_c), 1, arch);
    
	    while(!feof(arch) && existe == 0)
	    {
	        if (aux_t.dniCliente == aux_c.dniCliente)
	        {
		        existe = 1;	
		        break;
	        }
			else
			{
	        	fread(&aux_c, sizeof(aux_c), 1, arch);
			}
	    }
    
	    if (existe == 0)
		{
	        printf("No existe un Cliente con dicho DNI\n");
	        printf("Vuelva a Ingresar o Intentelo mas tarde");
	        system("pause");
	        printf("\n\n");
		}
    }
	while(existe != 1);
    
    fclose(arch);
    // ----------------------------------------------------
    
    // ---- COMPROBACION DE EXISTENCIA DE PROFESIONAL ----
    
    existe = 0;
    
    arch = fopen("Profesionales.dat","rb");
    rewind(arch);
        
	do
	{
		printf("ID DEL PROFESIONAL A CARGO: ");
	    scanf("%d", &aux_t.idProfesional);	
	    
        fread(&aux_p, sizeof(aux_p), 1, arch);
        
        while(!feof(arch) && existe == 0 )
		{
			if (aux_t.idProfesional == aux_p.id)
	        {
	        	id = aux_p.id;
		        existe = 1;
		        break;
	        }
			else
			{
	        	fread(&aux_p, sizeof(aux_p), 1, arch);
			}
		}
    }
	while(existe != 1);
	
	if (existe == 0)
	{
	    printf("No existe un Profesional con dicho ID\n");
	    printf("\nVuelva a Ingresar");
	    printf("\n\n");
	    system("pause");
	}
    
    fclose(arch);

    // -----------------------------------------------------
    
    // ---- FECHA DE TURNO ----
    
    existe = 0;
    
    printf("\nFECHA DEL TURNO");
    
    do
	{
		printf("\n\tDIA: ");
		scanf("%f", &aux_t.fechaDeTurno.dd);
		
		if(aux_t.fechaDeTurno.dd<=0 || aux_t.fechaDeTurno.dd>31)
		{
			printf("\n\n");
			printf("El valor ingreado no pertenece a ningun día posible, Por favor ingresar nuevamente");
			printf("\n\n");
			system("pause");
		}
		
	}
	while(aux_t.fechaDeTurno.dd<=0 || aux_t.fechaDeTurno.dd > 31);
	
	do
	{
		
		printf("\tMES: ");
		scanf("%f", &aux_t.fechaDeTurno.mm);
		
		if(aux_t.fechaDeTurno.mm <= 0 || aux_t.fechaDeTurno.mm > 12)
		{
			existe = 0;
			printf("\n\n");
			printf("El valor ingresado no corresponde a ningun mes del anio. Por favor ingresar nuevamenete");
			printf("\n\n");
			system("pause");		
		}
		else
		{
			existe = 1;
			if(aux_t.fechaDeTurno.mm == 3)
			{
				if(aux_t.fechaDeTurno.dd > 29)
				{
					existe = 0;
	                printf("\n\n");
	                printf("El día elegido no corresponde a una posible fecha del mes: [%d]", aux_t.fechaDeTurno.mm);
                    printf("\nPor favor ingresar mes nuevamente");
	                printf("\n\n");
	                system("pause");
				}
			}
		}
		  	            
      }
	  while(existe == 0);

	do
	{
		printf("\tANIO: ");
		scanf("%f", &aux_t.fechaDeTurno.aaaa);
		
		if(aux_t.fechaDeTurno.aaaa < 2021)
		{
			printf("\n\n");
			printf("El anio no puede ser menor al actual. Por favor ingresar nuevamente");
			printf("\n\n");
			system("pause");
		}
		
	}
	while(aux_t.fechaDeTurno.aaaa < 2021);
	
	_flushall();
	fwrite(&aux_t, sizeof(aux_t), 1, archT);
	
    fclose(archT);

	// Incrementar contador del profesional
				
	/*printf("ID: %d", aux_p.id);
	printf("\n\n");
	system("pause");*/
	
	archP = fopen("Profesionales.dat", "r+b");
	rewind(archP);
	
	fread(&aux_p, sizeof(aux_p), 1, archP);
	bandera_P = false;
	
	while(!feof(archP) && bandera_P == false)
	{
		if(id == aux_p.id)
		{
			bandera_P = true;
			fseek(archP, (long)-sizeof(aux_p), SEEK_CUR);
			/*printf("%d", sesion.c_Operaciones);
			printf("\n\n");
			system("pause");*/
			
			aux_p.c_Turnos++;
			
		    /*printf("\n\n%d", sesion.c_Operaciones);
			printf("\n\n");
			system("pause");*/	
		}
		else
		{
			fread(&aux_p, sizeof(aux_p), 1, archP);	
		}

	}
	
	if(bandera_P == true)
	{
		fwrite(&aux_p, sizeof(aux_p), 1, archP);	
	}
	
	fclose(archP);
	
	// ------------------------------------------
    
    system("cls");
    printf("Se ha registrado el turno exitosamente...");
    printf("\n\n");
    system("pause");
    
    /*archT = fopen("Turnos.dat","rb");
	rewind(archT);
    fread(&aux_t, sizeof(Turnos), 1, archT);

    while(!feof(archT))
	{
		printf("\n%d     ", aux_t.dniCliente);
		printf("/%d/%d/%d", aux_t.fechaDeTurno.dia, aux_t.fechaDeTurno.mes, aux_t.fechaDeTurno.anio);
		printf("   %d", aux_t.idProfesional);
		
		fread(&aux_t, sizeof(Turnos), 1, archT);
	}
	
	printf("\n\n");
	system("pause");*/		
}

void ListaTurnos(FILE *arch, bool &bandera_sesion_p, bool &bandera_sesion_r, bool bandera_cliente, int posicion, int base, int aux_id)
{
	system("cls");
	
	FILE *archC;
	FILE *archP;
	
	arch = fopen("Turnos.dat", "rb");
	archC = fopen("Clientes.dat", "rb");
	archP = fopen("Profesionales.dat", "rb");

	if(arch == NULL)
	{
		system("cls");
		printf("Error. El archivo 'Turnos.dat' no existe...");
		printf("\n\n(Tiene que registrar al menos un turno).");
		printf("\n\n");
		system("pause");
		ModuloRecepcionistas(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch, posicion, base, aux_id);
	}	
	else if(archC == NULL)
	{
		system("cls");
		printf("Error. El archivo 'Clientes.dat' no existe...");
		printf("\n\n(Tiene que registrar al menos un cliente).");
		printf("\n\n");
		system("pause");
		ModuloRecepcionistas(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch, posicion, base, aux_id);
	}
	else if(archP == NULL)
	{
		
		system("cls");
		printf("Error. El archivo 'Profesionales.dat' no existe...");
		printf("\n\n(Tiene que registrar al menos un profesional).");
		printf("\n\n");
		system("pause");
		ModuloRecepcionistas(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch, posicion, base, aux_id);
	}
	else
	{
		Turnos aux_t;
		Usuarios aux_p;
		Cliente aux_c;
		
	    printf("PACIENTE\t|\tFECHA DEL TURNO\t\t|\tPROFESIONAL A CARGO\t\n\n");
	    
		rewind(arch);
	    fread(&aux_t, sizeof(aux_t), 1, arch);
		
		while(!feof(arch))
		{
			rewind(archC);	
			fread(&aux_c, sizeof(aux_c), 1, archC);
			
			while(!feof(archC))
			{
				if(aux_t.dniCliente == aux_c.dniCliente)
				{
					printf("%s", aux_c.apellidoYNombre);	
					break;
				}
				
				fread(&aux_c, sizeof(aux_c), 1, archC);
			}	
			
			printf("\t\t%.0f/%.0f/%.0f", aux_t.fechaDeTurno.dd, aux_t.fechaDeTurno.mm, aux_t.fechaDeTurno.aaaa);
			
			rewind(archP);	
			fread(&aux_p, sizeof(aux_p), 1, archP);
			
			while(!feof(archP))
			{
				if(aux_t.idProfesional == aux_p.id)
				{
					printf("\t\t\t%s", aux_p.apellidoYNombre);	
					break;
				}
				
				fread(&aux_p, sizeof(aux_p), 1, archP);
			}
			
			printf("\n");
				
			fread(&aux_t, sizeof(aux_t), 1, arch);
		}
		fclose(arch); 
	}
	
	printf("\n");
	system("pause");

}

// ************************************************************************************************************************************************



		
		











