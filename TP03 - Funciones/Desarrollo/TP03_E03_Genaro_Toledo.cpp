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

void calMayMen(int &May, int &Men)
{
	May = -9999;
	Men = 9999;
	
	int numero1 = 0;
	int numero2 = 0;
	
	printf("INGRESE NUMERO 1: ");
	scanf("%d", & numero1);
	
	do
	{
		printf("\nINGRESE NUMERO 2: ");
		scanf("%d", & numero2);	
		if (numero1 == numero2)
		{
			system("cls");
			printf("Los valores ingresados deben ser distintos. Ingrese nuevamente.");
			printf("\n\n");
			system("pause");
			system("cls");
		}
	}
	while(numero1 == numero2);
	
	if(numero1 > numero2)
	{
		May = numero1;
		Men = numero2;
		printf("Mayor es: %d", May);
		printf("\nMenor es: %d", Men);
	}
	else if(numero2 > numero1)
	{
		May = numero2;
		Men = numero1;
		
		printf("\nMayor es: %d", May);
		printf("\nMenor es: %d", Men);
	}	
}

void areaCuad(int May, float &SupCua)
{
	SupCua = May * May;		
}

void areaCilin(int Men, float &SupCil)
{
	SupCil = 3.14 * (Men * Men);
}

main()
{
	system("color F0");
	int mayor = 0;
	int menor = 0;
	
	float supCuadrado = 0;
	float supCirculo = 0;
	
	calMayMen(mayor, menor);
	areaCuad(mayor, supCuadrado);
	
	printf("\n\nArea del cuadrado: %.2f", supCuadrado);
	
	areaCilin(menor, supCirculo);
	printf("\nArea del circulo: %.2f", supCirculo);
	
	printf("\n\n");
	system("PAUSE");
}
