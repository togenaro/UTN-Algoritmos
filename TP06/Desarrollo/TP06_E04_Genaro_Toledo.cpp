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

void calculoTamanioPoema(char *f00_poema, int &f00_tamanioPoema)
{
	int c = 0;
	f00_tamanioPoema = 0;
	
	// --------------------------
	while (f00_poema[c] != '\0')
	{
		f00_tamanioPoema++;
		c++;
	}
	// --------------------------	

}

void calculoVocales(char *f01_poema, int f01_tamanioPoema)
{
	char vec_vocales[] = "AEIOUaeiou";
	
	int vocales = 0;
	int N_vocales = 10;
	
	// ----------------------------------------
	for (int i=0; i<N_vocales; i++)
	{
		for (int c=0; c<f01_tamanioPoema; c++)
		{
			if(f01_poema[c] == vec_vocales[i])
			{
				vocales++;
			}
		}
	}
	// ----------------------------------------
	
	printf("\n");
	printf("VOCALES: %d", vocales);
}

void calculoConsonantes(char *f02_poema, int f02_tamanioPoema)
{
	char vec_consonantes[] = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
	int consonantes = 0;
	int N_consonantes = 42;
	
	// ----------------------------------------
	for (int i=0; i<N_consonantes; i++)
	{
		for (int c=0; c<f02_tamanioPoema; c++)
		{
			if(f02_poema[c] == vec_consonantes[i])
			{
				consonantes++;
			}
		}
	}
	// ----------------------------------------	
	
	printf("\n");
	printf("CONSONANTES: %d", consonantes);
}

void calculoPuntuaciones(char *f03_poema, int f03_tamanioPoema)
{
	char vec_puntuaciones[] = ".,:;!¡?¿";
	
	int puntuaciones = 0;
	int N_puntuaciones = 8;	
		
	// ---------------------------------------------	
	for (int i=0; i<N_puntuaciones; i++)
	{
		for (int c=0; c<f03_tamanioPoema; c++)
		{
			if(f03_poema[c] == vec_puntuaciones[i])
			{
				puntuaciones++;
			}
		}	
	}
	// ---------------------------------------------
	
	printf("\n");
	printf("SIGNOS DE PUNTUACION: %d", puntuaciones);
}

void calculoDigitos(char *f04_poema, int f04_tamanioPoema)
{
	char vec_digitos[] = "0123456789";
	
	int digitos = 0;
	int N_digitos = 10;
	
	// ----------------------------------------
	for (int i=0; i<N_digitos; i++)
	{
		for (int c=0; c<f04_tamanioPoema; c++)
		{
			if(f04_poema[c] == vec_digitos[i])
			{
				digitos++;
			}
		}	
	}
	// ----------------------------------------
	
	printf("\n");
	printf("DIGITOS: %d", digitos);	
}

void calculoMayusMinus(char *f05_poema, int f05_tamanioPoema)
{
	char vec_mayus[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char vec_minus[] = "abcdefghijklmnopqrstuvwxyz";
	
	int mayusculas = 0;
	int minusculas = 0;
	int N_mayus = 26;
	
	// ---------------------------------------------
	for (int i=0; i<N_mayus; i++)
	{
		for (int c=0; c<f05_tamanioPoema; c++)
		{
			if(f05_poema[c] == vec_mayus[i])
			{
				mayusculas++;
			}
			else if (f05_poema[c] == vec_minus[i])
			{
				minusculas++;
			}
		}	
	}
	// ---------------------------------------------
	
	printf("\n");
	printf("MAYUSCULAS: %d", mayusculas);
	printf("\n");
	printf("MINUSCULAS: %d", minusculas);		
}

main()
{
	system("color F0");
	
	int tamanioPoema = 0;
	
	// ---------------------------------------
	
	char poema[201];
	printf("RELATE SU POEMA: ");
	_flushall();
	gets(poema);
	
	// ---------------------------------------
	
	calculoTamanioPoema(poema, tamanioPoema);
	calculoVocales(poema, tamanioPoema);
	calculoConsonantes(poema, tamanioPoema);
	calculoPuntuaciones(poema, tamanioPoema);
	calculoDigitos(poema, tamanioPoema);
	calculoMayusMinus(poema, tamanioPoema);
	
	// ---------------------------------------
	
	printf("\n\n");
	system("pause");
}
