#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char cadena[80];
char vec_mayus[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char vec_minus[] = "abcdefghijklmnopqrstuvwxyz";
char vec_digitos[] = "0123456789";
char vec_simbolos[] = "áéíóú´+-/*?¿!¡();:#$%&\{}";


struct Usuarios
{
	cadena usuario;
	cadena clave;
	cadena apellidoYNombre;
};

void registrarProfesional();

main()
{
	system("color 0F");
	registrarProfesional();	
}

void registrarProfesional()
{
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
			
	do
	{
		bandera = false;
		
		c_mayus = 0;
		c_digitos = 0;
		longitud = 0;
		
		printf("NOMBRE DE USUARIO: ");
		_flushall();
		gets(sesion.usuario);
		
		// --------------------------------------------	
		longitud = strlen(sesion.usuario);	
		
		if(longitud < 10)
		{
			tamanio = true;
		}
		// --------------------------------------------	
		
		// --------------------------------------------	
		primerCaracter = sesion.usuario[0];	
		for (int i=0; i<27; i++)
		{
			if(primerCaracter == vec_minus[i])
			{
				minusculas = true;	
			}	
		}
		// --------------------------------------------	
		
		// --------------------------------------------	
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
		
		// --------------------------------------------
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
		
		if(digitos == true && mayusculas == true && minusculas == true && tamanio == true)
		{
			bandera = true;
		}
		
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
	
	do
	{	
		bandera = false;
		digitos = false;
		tamanio = false;
		consecutividad = false;
		
		longitud = 0;
		pos = 0;
		
		printf("CLAVE: ");
		_flushall();
		gets(sesion.clave);
		
		longitud = strlen(sesion.clave);
		if(longitud >= 6 && longitud <= 32)
		{
			tamanio = true;
		}
			
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
	
	printf("\n\n");
	system("pause");
}

