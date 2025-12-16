#include <stdio.h>
#include <stdlib.h>

struct Registro
{
	int dato;
	bool borrado;	
};

void CargarDato(FILE *arch);
void MostrarDatos(FILE *arch);
void BajaLogica(FILE *arch);
void BajaFisica(FILE *arch);

main()
{
	system("color 0F");
	
	FILE *archivo;

	archivo = fopen("archivo.dat", "w+b");
	
	if (archivo == NULL)
	{
		printf("No se pudo crear el archivo.");
		exit(1);
	}
	
	CargarDato(archivo);
	MostrarDatos(archivo);
	BajaLogica(archivo);
	BajaFisica(archivo);
	MostrarDatos(archivo);
}

void CargarDato(FILE *arch)
{
	Registro reg;
	
	int N = 0;
	printf("INGRESE CANTIDAD DE DATOS A INGRESAR: ");
	scanf("%d", &N);
	
	system("cls");
	
	rewind(arch);
	
	for(int i=0; i<N; i++)
	{
		printf("DATO NUMERO: %d\n", i+1);
		printf("INGRESE EL DATO: ");
		scanf("%d", &reg.dato);
	
		fwrite(&reg, sizeof(reg), 1, arch);	
		printf("\n");
	}

}

void MostrarDatos(FILE *arch)
{
	Registro reg;
	
	rewind(arch);
	fread(&reg, sizeof(reg), 1, arch);
	
	system("cls");
	printf("--DATOS EN EL ARCHIVO--\n");
	
	while(!feof(arch))
	{
		if(reg.borrado == true)
		{
			printf("\nCONTENIDO: %d", reg.dato);
			printf("\nESTADO: BORRADO");
		}
		else if (reg.borrado == false)
		{
			printf("\nCONTENIDO: %d", reg.dato);
			printf("\nESTADO: ACTIVO");
		}
			
		fread(&reg, sizeof(reg), 1, arch);	
		printf("\n");			
	}

	
	printf("\n");
	system("pause");
}


void BajaLogica(FILE *arch)
{
	Registro reg;
	int target = 0;
	bool bandera = false;
	
	printf("\n\nINGRESE EL DATO A BORRAR: ");
	scanf("%d", &target);
	
	rewind(arch);
	fread(&reg, sizeof(reg), 1, arch);
	
	while( !feof(arch) && bandera == false)
	{
		if(reg.dato == target)
		{
			reg.borrado = true;
			fseek(arch, (long) -sizeof(reg), SEEK_CUR);
			
			fwrite(&reg, sizeof(reg), 1, arch);
			
			bandera = true;
		}
		else
		{
			fread(&reg, sizeof(reg), 1, arch);		
		}	
	}
	
}

void BajaFisica(FILE *arch)
{
	FILE *aux;
	Registro reg;
	
	bool bandera;
	
	rewind(arch);
	
	fread(&reg, sizeof(reg), 1, arch);
	aux = fopen("auxiliar.dat", "w+b");
	
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
