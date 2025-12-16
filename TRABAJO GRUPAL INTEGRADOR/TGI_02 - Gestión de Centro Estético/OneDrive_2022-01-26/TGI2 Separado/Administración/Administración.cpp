#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char cadena[80];

char vec_simbolos[] = "+-/*?¿!¡";
char vec_mayus[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char vec_minus[] = "abcdefghijklmnopqrstuvwxyz";
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

// --Administración--
	void MenuAdministracion(FILE *arch);
	void RegistrarProfesional(FILE *arch);
	void RegistrarRecepcionista(FILE *arch);
	void Atenciones(FILE *arch);
	void Ranking(FILE *arch);

// ----------------------------------------------------------------------------------------------------------------------------------------------------

main()
{
	FILE *archivo;
					
	MenuAdministracion(archivo);	
}
	
// ********* ADMINISTRACION *************

void MenuAdministracion(FILE *arch)
{
	system("color F0");
	
	int opcion = 0;
	
	do
	{
		system("cls");
		printf("--MODULO DE ADMINISTRACION--");
		printf("\n\n1- REGISTRAR USUARIO PROFESIONAL");
		printf("\n2- REGISTRAR USUARIO RECEPCIONISTA");
		printf("\n3- ATENCIONES POR PROFESIONAL");
		printf("\n4- RANKING DE PROFESIONALES POR ATENCIONES");
		
		printf("\n\n5- CERRAR APLICACION");
		
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
	while (opcion > 0 || opcion < 5);
		
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
	bool simbolos = false;
	
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
		simbolos = false;
		
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
		
		// ----CONDICION DE CARACTERES ALFANUMERICOS----
		for (int a=0; a<longitud; a++)
		{
			for(int b=0; b<8; b++)
			{
				if(sesion.clave[a] == vec_simbolos[b])
				{
					simbolos = true;
				}
				
			}
		}
		// ---------------------------------------------
		
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
			if(consecutividad == true || digitos == true || simbolos == true)
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
	bool simbolos = false;
	
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
		simbolos = false;
		
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
		
		// ----CONDICION DE CARACTERES ALFANUMERICOS----
		for (int a=0; a<longitud; a++)
		{
			for(int b=0; b<8; b++)
			{
				if(sesion.clave[a] == vec_simbolos[b])
				{
					simbolos = true;
				}
				
			}
		}
		// ---------------------------------------------
		
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


