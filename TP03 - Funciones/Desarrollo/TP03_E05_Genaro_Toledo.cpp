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

void ingresoMaquina(int &f01_maquina)
{
	do
	{
		printf("INGRESE LA MAQUINA (1|2|3 o 0 para finalizar): ");
		scanf("%d", & f01_maquina);	
		
		if (f01_maquina > 3 || f01_maquina < 0)
		{
			system("cls");
			printf("Valor incorrecto. Ingrese nuevamente.");
			printf("\n\n");
			system("pause");
			system("cls");	
		}
		else if(f01_maquina == 0)
		{
			system("cls");
			printf("Finalizando...");
			printf("\n\n");
			system("pause");
			exit(1);
		}	
	}
	while (f01_maquina > 3 || f01_maquina < 0);	
}

void calculoTotalEnvases(int &f01_cantEnvases, int &f01_desechados, int &f01_totalEnvases)
{
	int semana = 5; // 5 dias habiles (lunes a viernes)
	
	for (int i=0; i<semana; i++)
	{
		printf("\nDIA %d\n\n", i+1);
		printf("ENVASES PRODUCIDOS: ");
		scanf("%d", & f01_cantEnvases);
			
		printf("ENVASES DESECHADOS: ");
		scanf("%d", & f01_desechados);
			
		f01_totalEnvases = f01_totalEnvases + f01_cantEnvases;
	}	
}

int calculoDesechados(int f02_desechados, int f02_totalEnvases)
{
	int f02_porcentajeDesechados = 0.0;
	
	f02_porcentajeDesechados = ((float)f02_desechados / (float)f02_totalEnvases) * 100;
	
	return f02_porcentajeDesechados;
}

void mostrarResultados(int f03_codigo, int f03_totalEnvases, float f03_porcentajeDesechados)
{
	printf("\n\nEl codigo de identificacion de la maquina es: %d", f03_codigo);
	printf("\nLa cantidad de envases producidos en la semana es: %d", f03_totalEnvases);
	printf("\nEl porcentaje de envases desechados sobre el total es: %.2f", f03_porcentajeDesechados);	
		
	printf("\n\n");
	system("pause");	
}

main()
{
	system("color F0");
	
	int maquina = 0;
	int codigo = 0;
	int desechados = 0;
	int cantEnvases = 0;
	int totalEnvases = 0;
	
	float porcentajeDesechados = 0.0;
	
	ingresoMaquina(maquina);

	while (maquina != 0)
	{	
		porcentajeDesechados = 0.0;
		cantEnvases = 0.0;
		codigo = 0;
		
		printf("CODIGO DE IDENTIFICACION: ");
		scanf("%d", & codigo);	
		
		calculoTotalEnvases(cantEnvases, desechados, totalEnvases);
		porcentajeDesechados = calculoDesechados(desechados, totalEnvases);
		mostrarResultados(codigo, totalEnvases, porcentajeDesechados);
		ingresoMaquina(maquina);
	}
	
	printf("\n\n");
	system("cls");
}
