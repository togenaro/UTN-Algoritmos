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

void tamanioFrase(char *f01_frase, int &f01_longitudFrase)
{
	int i = 0;
	
	// ---------------------------
	while (f01_frase[i] != '\0')
	{
		f01_longitudFrase++;
		i++;
	}
	// ---------------------------
}

void calculoMayusculas(char *f02_frase, int f02_longitudFrase)
{
	char vec_Mayus[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int N_Mayus = 26;
	int mayusculas = 0;
	
	// -----------------------------------------
	for (int i=0; i<N_Mayus; i++)
	{
		for (int c=0; c<f02_longitudFrase; c++)
		{
			if (f02_frase[c] == vec_Mayus[i])
			{
				mayusculas++;
			}
		}
	}
	// -------------------------------------------------------------
	if (mayusculas != 0)
	{
		printf("\nSe ingreso %d letra/s mayuscula/s", mayusculas);
		printf("\n\n");
		system("pause");
		exit(-1);
	}
	else
	{
		printf("\nNo se ingreso ninguna letra mayuscula.");
		printf("\n\n");
		system("pause");
		exit(-1);

	}
	// -------------------------------------------------------------
}

main()
{
	system("color F0");
	
	char frase[101];
	int longitudFrase = 0;
	
	printf("INGRESE UNA FRASE: ");
	_flushall();
	gets(frase);
	
	tamanioFrase(frase, longitudFrase);
	calculoMayusculas(frase, longitudFrase);
}
