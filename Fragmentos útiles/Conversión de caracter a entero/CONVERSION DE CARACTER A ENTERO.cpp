#include <stdlib.h>
#include <stdio.h>

typedef char string[80];

bool isDigit(char c) 
{
	return (c >= '0' && c <= '9');	
}
    
int stringToInteger(const char* str, bool &flag_invalid) 
{
    int result = 0;
    int sign = 1;
    int i = 0;
    flag_invalid = false;

    // Verificar el signo
    if (str[0] == '-') 
	{
        sign = -1;
        i = 1;
    }

    // Convertir los dígitos
    while (str[i] != '\0') 
	{
        if (!isDigit(str[i])) 
        {
        	flag_invalid = true;  // La cadena contiene caracteres no numéricos, retornar 0
        	break;
		}
            

        result = result * 10 + (str[i] - '0');
        i++;
    }

    return result * sign;
}

int main() 
{
    string input;
    bool flag_invalid = false;
    int number = 0;

    while(true) 
	{
        printf("INGRESE UN NUMERO: ");
        _flushall();
        gets(input);

        number = stringToInteger(input, flag_invalid);

        // Verificar si la conversión fue exitosa
        if (!flag_invalid) 
            break;
		
		system("cls");
        printf("Se ingreso un caracter incorrecto. Ingrese nuevamente...");
        printf("\n\n");
        system("pause");
        system("cls");
    }

    printf("\nEl numero ingresado es: %d\n", number);

	printf("\n\n");
	system("pause");
    return 0;
}

