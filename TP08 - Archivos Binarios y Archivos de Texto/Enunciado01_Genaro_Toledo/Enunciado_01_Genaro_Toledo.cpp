#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char cadena[80];
char vec_Minus[] = "abcdefghijklmnopqrstuvwxyz";
char vec_Mayus[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";


main()
{
	system("color F0");
	
	int centinela = 999;
	char letra[100];
		
	FILE *archivo1;
	FILE *archivo2;
	FILE *archivo3;
	
	cadena frase1;
	cadena frase2;
	cadena frases;
		
	archivo1 = fopen("Archivo1.txt", "wt");
	
	if(archivo1 == NULL)
	{
		printf("No se pudo abrir el archivo");
		printf("\n\n");
		system("pause");		
		exit(EXIT_FAILURE);
	}
	
	archivo2 = fopen("Archivo2.txt", "wt");

	if(archivo2 == NULL)
	{
		printf("No se pudo abrir el archivo");
		printf("\n\n");
		system("pause");		
		exit(EXIT_FAILURE);
	}	
	
	archivo3 = fopen("Frases.txt", "wt");

	if(archivo3 == NULL)
	{
		printf("No se pudo abrir el archivo");
		printf("\n\n");
		system("pause");
		exit(EXIT_FAILURE);
	}
	
	
	do
	{
		printf("INGRESE LA FRASE RECIBIDA POR JOSE LUIS: ");
		_flushall();
		gets(frase1);
		
		if ( strcmp(strlwr(frase1), "fin") != 0 )
		{
			fputs(strcat(frase1, "\n"), archivo1);
		}
		
	} while ( strcmp(strlwr(frase1), "fin") != 0 );
	
	
	printf("\n\n");
	
	do
	{
		printf("INGRESE LA FRASE RECIBIDA POR MARIA EMILIA: ");
		_flushall();
		gets(frase2);
		
		if ( strcmp(strlwr(frase2), "fin") != 0 )
		{
			fputs(strcat(frase2, "\n"), archivo2);
		}
		
	} while ( strcmp(strlwr(frase2), "fin") != 0 );
	
	fclose(archivo1);
	fclose(archivo2);
	
	printf("\n\n");
	system("pause");
	
	archivo1 = fopen("Archivo1.txt", "rt");
	archivo2 = fopen("Archivo2.txt", "rt");
	
	fgets(frase1, sizeof(frase1), archivo1);
	fgets(frase2, sizeof(frase2), archivo2);
	
	while(  (!feof(archivo1)) && (!feof(archivo2))  )
	{
		fputs(frase1, archivo3);
		fputs("\n", archivo3);
		fputs(frase2, archivo3);
		fputs("\n", archivo3);
				
		fgets(frase1, sizeof(frase1), archivo1);
		fgets(frase2, sizeof(frase2), archivo2);
	}
	
	/*while (!feof(archivo1))
	{
		fputs(frase1, archivo3);
		fputs("\n", archivo3);
		fgets(frase1, sizeof(frase1), archivo1);
	}
	
	while (!feof(archivo2))
	{
		fputs(frase2, archivo3);
		fputs("\n", archivo3);
		fgets(frase2, sizeof(frase2), archivo2);
	}*/
	
	fclose(archivo1);
	fclose(archivo2);
	fclose(archivo3);
	
	archivo1 = fopen("Archivo1.txt", "rt");
	archivo2 = fopen("Archivo2.txt", "rt");
	
	fgets(frase1, sizeof(frase1), archivo1);
	fgets(frase2, sizeof(frase2), archivo2);
	
	printf("\n--FRASES RECIBIDAS POR JOSE LUIS--\n\n");
	
	while(!feof(archivo1))
	{
		strupr(frase1);
		puts(frase1);
		
		fgets(frase1, sizeof(frase1), archivo1);
	}
	
	printf("--FRASES RECIBIDAS POR MARIA EMILIA--\n\n");
	while(!feof(archivo2))
	{
		strlwr(frase2);
		puts(frase2);
		
		fgets(frase2, sizeof(frase2), archivo2);
	}
	
	system("pause");
	
	printf("\n--FRASES DEL ARCHIVO COMBINADO--\n\n");
	
	archivo3 = fopen("Frases.txt", "rt");
	
	fgets(frases, sizeof(frases), archivo3);
	
	char primeraLetra;
	int longitud = 0;
	
	while(!feof(archivo3))
	{
		longitud = 0;
		
		strlwr(frases);
		longitud = strlen(frases);
		
		primeraLetra = frases[0];
		
		for(int i=0; i<26; i++)
		{
			if(primeraLetra == vec_Minus[i])
			{
				primeraLetra = vec_Mayus[i];
			}
		}
		
		printf("%c", primeraLetra);
		
		for(int i=1; i<longitud; i++)
		{
			letra[i] = frases[i];

			printf("%c", letra[i]);
		}
			
		fgets(frases, sizeof(frases), archivo3);
	}
	
	system("pause");
	
	fclose(archivo1);
	remove("Archivo1.txt");
	
	fclose(archivo2);
	remove("Archivo2.txt");
}










