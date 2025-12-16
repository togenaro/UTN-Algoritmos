/*
Universidad Tecnológica Nacional
Facultad Regional Tucumán
Ingeniería en Sistemas de Información

Algoritmos y Estructuras de Datos

Integrantes:
            
            44030752 - Genaro Toledo
*/        
/*
En un banco se procesan datos las N cuentas corrientes. Los datos ingresados por teclados de cada uno de los socios serán:

	a. Número de Cuenta.
	b. Numero de documento del socio.
	c. Saldo de la cuenta.
	
De cada una de las cuentas mostrar, el Documento del socio, número de cuenta y
el estado de la cuenta. Siendo

	Estado de la cuenta | Saldo
	Acreedor | Cuando el saldo sea mayor a cero
	Deudor | Cuando el saldo sea menor a cero
	Nulo | Cuando el saldo sea igual a cero
	
Mostrar al final del listado, la suma total de los saldos Acreedores.
*/

// -------------------------------------------------

#include<stdio.h>
#include<stdlib.h>

// -------------------------------------------------

main()

{ // Apertura main
	
// -------------------------------------------------
	
	int x = 0;
	int cantidadCuentas = 0;
	
	int numeroCuenta = 0;
	int dniSocio = 0;
	int saldoCuenta = 0;
	
// -------------------------------------------------	
	
	// -------------------------------------------------
	
	printf("Ingrese la cantidad de cuentas a analizar: ");
	scanf("%d", & cantidadCuentas);
	
	for (x = 1; x <= cantidadCuentas; x++)
	
	{ // APERTURA FOR PRINCIPAL
	
	// -------------------------------------------------
	
		// -------------------------------------------------
		
		system("cls");
		
		printf("CUENTA %d", x);
		printf("\n\nIngrese el numero de cuenta: ");
		scanf("%d", & numeroCuenta);
		
		// -------------------------------------------------
		
		// -------------------------------------------------
		
		printf("Ingrese el numero de documento del socio: ");
		scanf("%d", & dniSocio);
		
		// -------------------------------------------------
		
		// -------------------------------------------------
		
		printf("Ingrese el saldo de la cuenta del socio: ");
		scanf("%d", & saldoCuenta);
		
		// -------------------------------------------------
		
		// -------------------------------------------------
		
		if (saldoCuenta > 0)
		
		{
			
			system("cls");
			printf("El socio %d es ACREEDOR.\n\n", x);
			system("pause");
			
		}
		
		else if (saldoCuenta < 0)
		
		{
			
			system("cls");
			printf("El socio %d es DEUDOR.\n\n", x);
			system("pause");
			
		}
		
		else if (saldoCuenta == 0)
		
		{
			
			system("cls");
			printf("El socio %d es NULO.\n\n", x);
			system("pause");	
			
		}
		
		// -------------------------------------------------
		
		// -------------------------------------------------
	
	
	} // CIERRE FOR PRINCIPAL
	
} // Cierre main






































