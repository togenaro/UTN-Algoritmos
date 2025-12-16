#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

typedef char string[80];

main()
{
	bool band_esc = false;
	bool band_enter = false;
	
	char opcion = NULL;
	char tecla = NULL;
	
	string cadena = {NULL};
	
	int i = 0;
			
	printf("SELECCIONE UNA OPCION: ");	
	
	do
	{
		_flushall();
		tecla = getch();	
				
		switch(tecla)
		{
			case 27:
					{
						band_esc = true;
						break;	
					}	
					
			case 13:
					{
						band_enter = true;
						break;		
					}
			default:
					{
						printf("%c", tecla);
						cadena[i++] = tecla;
						break;
					}
		}
					
		if(band_esc == true || band_enter == true)
			break;
	}
	while(true);
	
	cadena[i] = '\0';
		
	if(band_esc == true)
	{
		opcion = '0';
		
		for(i=0; i<strlen(cadena); i++)
		{
			cadena[i] = NULL;
		}
	}
	else
	{
		if(i > 1)
			opcion = '-';
		else
			opcion = cadena[0];			
	}
	
	
	switch( opcion )
	{
		case '1': 
				{
					printf("OPCION 1");
					printf("\n\n");
					system("pause");					
					break;
				}
		case '2': 
				{
					printf("OPCION 2");
					printf("\n\n");
					system("pause");
					break;					
				}
		case '3': 
				{
					printf("OPCION 3");
					printf("\n\n");
					system("pause");
					break;					
				}
		case '0': 
				{
					system("cls");
					printf("VOLVIENDO ATRAS...");	
					printf("\n\n");
					system("pause");
					break;
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
