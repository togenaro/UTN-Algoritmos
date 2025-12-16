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

// --Módulo: Espacios--
	void ModuloEspacios(bool &bandera_sesion_p, bool &bandera_sesion_r, bool bandera_cliente, FILE *arch, int aux_id, int posicion, int base);
	bool InicioSesion_P(FILE *arch, int &aux_id);
	bool BuscarCliente(FILE *arch, int &posicion, int &base);
	void InformeTurnos(FILE *arch, bool bandera_cliente);
	void RegistrarTratamiento(FILE *arch, bool bandera_cliente, int aux_id, int posicion, bool bandera_sesion_p, bool bandera_sesion_r, int base);

// ----------------------------------------------------------------------------------------------------------------------------------------------------

main()
{
	bool bandera_sesion_p = false;
	bool bandera_sesion_r = false;
	bool bandera_cliente = false;
	
	int base = 0;
	int posicion = 0;
	int opcion = 0;
	int aux_id = 0;
	
	FILE *archivo;
					
	ModuloEspacios(bandera_sesion_p, bandera_sesion_r, bandera_cliente, archivo, aux_id, posicion, base);	
}

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
		printf("\n5- CERRAR APLICACION");
		
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
								ModuloEspacios(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch, aux_id, posicion, base);
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
	
			case 5:
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
	while (opcion > 1 || opcion < 5);		
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
		exit(EXIT_SUCCESS);
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












