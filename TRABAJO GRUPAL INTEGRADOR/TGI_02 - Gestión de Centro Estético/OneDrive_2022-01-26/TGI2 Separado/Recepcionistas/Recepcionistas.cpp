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

// --Módulo: Recepcionistas--
	void ModuloRecepcionistas(bool &bandera_sesion_p, bool &bandera_sesion_r, bool bandera_cliente, FILE *arch, int posicion, int base, int aux_id);
	void RegistrarCliente(FILE *arch);
	void RegistrarTurno(FILE *arch, bool &bandera_sesion_p, bool &bandera_sesion_r, bool bandera_cliente, int posicion, int base, int aux_id);
	void ListaTurnos(FILE *arch, bool &bandera_sesion_p, bool &bandera_sesion_r, bool bandera_cliente, int posicion, int base, int aux_id);
	bool InicioSesion_R(FILE *arch);
	
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
					
	ModuloRecepcionistas(bandera_sesion_p, bandera_sesion_r, bandera_cliente, archivo, posicion, base, aux_id);	
}

// *************************************** RECEPCIONISTAS *****************************************************************************************

void ModuloRecepcionistas(bool &bandera_sesion_p, bool &bandera_sesion_r, bool bandera_cliente, FILE *arch, int posicion, int base, int aux_id)
{
	if(bandera_sesion_r == false)
	{
		do 
		{
			bandera_sesion_r = InicioSesion_R(arch);
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
		printf("\n5- CERRAR APLICACION");
		
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
							ModuloRecepcionistas(bandera_sesion_p, bandera_sesion_r, bandera_cliente, arch, posicion, base, aux_id);
						}
						
						break;							
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


