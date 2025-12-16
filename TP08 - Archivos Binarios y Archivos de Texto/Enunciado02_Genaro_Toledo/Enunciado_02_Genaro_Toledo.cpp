#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

typedef char cadena[80];

struct RegistroEstudiantes
{
	cadena nombre;
	cadena apellido;
	cadena carrera;
	cadena nota;	
};

void Menu(FILE *arch);
void CargaDatos(FILE *arch);
void Listado(FILE *arch);
void ApellidosIguales(FILE *arch);


main()
{
	system("color F0");
	FILE *archivo;
	
	archivo = fopen("estudiantes.txt", "rt");
	
	if (archivo == NULL)
	{
		archivo = fopen("estudiantes.txt", "wt");
		
		if(archivo == NULL)
		{
			printf("Error. No se pudo crear el archivo.");
			exit(EXIT_FAILURE);			
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

	fclose(arch);
		
	int opcion = 0;		
	do
	{
		system("cls");	
		printf("--MENU--\n\n");
		printf("1- REGISTRAR ESTUDIANTE\n");
		printf("2- LISTAR ESTUDIANTES\n");
		printf("3- LISTAR CANTIDAD DE APELLIDOS IGUALES\n");
		printf("4- LISTAR ESTUDIANTES QUE CURSAN LA MISMA CARRERA\n");
		printf("5- BUSCAR ESTUDIANTE");
		
		printf("\n\n6- SALIR\n\n");
		
		printf("INGRESE UNA OPCION: ");
		scanf("%d", & opcion);
		
		switch(opcion)
		{
					
			case 1:
					{
						CargaDatos(arch);
						break;
					}
			case 2:
					{
						Listado(arch);
						break;
					}
			case 3:
					{
						ApellidosIguales(arch);	
						break;
					}
			case 4:	
					{
						break;
					}
			case 5:	
					{
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
							
							remove("estudiantes.txt");
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

void CargaDatos(FILE *arch)
{
	RegistroEstudiantes reg;
	
	arch = fopen("estudiantes.txt", "at");
	
	system("cls");
	printf("--REGISTRO DE ESTUDIANTES--\n\n");
	
	printf("NOMBRE: ");
	_flushall();
	gets(reg.nombre);
	fputs("NOMBRE: ", arch);
	fputs(strcat(reg.nombre, ";"), arch);
	fputs("\n", arch);
	
	printf("APELLIDO: ");
	_flushall();
	gets(reg.apellido);
	fputs("APELLIDO: ", arch);
	fputs(strcat(reg.apellido, ";"), arch);
	fputs("\n", arch);
	
	printf("CARRERA QUE ESTUDIA: ");
	_flushall();	
	gets(reg.carrera);
	fputs("CARRERA: ", arch);
	fputs(strcat(reg.carrera, ";"), arch);
	fputs("\n", arch);
	
	printf("NOTA PROMEDIO: ");
	_flushall();	
	gets(reg.nota);
	fputs("PROMEDIO: ", arch);
	fputs(strcat(reg.nota, ";"), arch);
	fputs("\n\n", arch);
	
	fclose(arch);
}

void Listado(FILE *arch)
{
	RegistroEstudiantes reg;
	
	system("cls");
	printf("--LISTADO DE ESTUDIANTES--\n\n");
	
	arch = fopen("estudiantes.txt", "rt");

	fgets(reg.nombre, sizeof(reg), arch);
	fgets(reg.apellido, sizeof(reg), arch);	
	fgets(reg.carrera, sizeof(reg), arch);	
	fgets(reg.nota, sizeof(reg), arch);	
	
	while(!feof(arch))
	{
		printf("%s", reg.nombre);
		printf("%s", reg.apellido);
		printf("%s", reg.carrera);
		printf("%s", reg.nota);
		
		fgets(reg.nombre, sizeof(reg), arch);
		fgets(reg.apellido, sizeof(reg), arch);	
		fgets(reg.carrera, sizeof(reg), arch);	
		fgets(reg.nota, sizeof(reg), arch);			
	}
	
	printf("\n\n");
	system("pause");
	
	fclose(arch);
}

void ApellidosIguales(FILE *arch)
{
	RegistroEstudiantes reg;
	cadena vector[80];
	cadena auxiliar;
	int i = 0;
	int L = 0;
	int N = 0;
	int repeticiones = 0;
	
	system("cls");
	printf("--APELLIDOS IGUALES--\n\n");
	
	arch = fopen("estudiantes.txt", "rt");

	fgets(reg.apellido, sizeof(reg), arch);	
	
	while(!feof(arch))
	{
		strcat(reg.apellido, vector[i]);
		printf("%s", reg.apellido);
		fgets(reg.apellido, sizeof(reg.apellido), arch);	
		i++;
		N++;	
		printf("%d\n\n", N);
		system("pause");
	}
	
	
	printf("N: %d", N);
	L = N - 1;
	printf("\nL: %d", L);
	
	for (i=0; i<N; i++)
	{
		printf("\n\nHOLA\n\n");
		system("pause");
		for(int n=i+1; n<L; n++)
		{
			if(strcmp(vector[i], vector[n]) == 0 && vector[i] != NULL)
			{
				repeticiones++;
				strcpy(vector[i], auxiliar);
				break;					
			}
		}
		
		for(int c=0; c<N; c++)
		{
			if( strcmp(auxiliar, vector[c]) == 0 ) 
			{
				strcat(vector[i], NULL); 
					
			}
		}
		
	}
	
	printf("Cantidad de veces que se repiten apellidos: %d", repeticiones);
	printf("\n\n");
	system("pause");
	
	fclose(arch);	
}

void MismaCarrera()
{
	
}

void BuscarEstudiante()
{
	
}


















