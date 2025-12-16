#include <stdlib.h>
#include <stdio.h>

/*
	Datos de los autores
*/

main()
{
	int N = 0;
	
	int numeroCuenta = 0;
	int dni = 0;
	float saldo = 0.0;
	
	float totalSaldosAcreedores = 0.0;
	
	
	system("cls");
	
	printf("Ingrese la cantidad de socios: ");
	scanf("%d", &N);
	
	
	for (int i=1; i <= N; i++)
	{
		printf("\n\nNro Cuenta: ");
		scanf("%d", &numeroCuenta);
		
		printf("DNI Socio: ");
		scanf("%d", &dni);
		
		printf("Saldo: ");
		scanf("%f", &saldo);
		
		printf("\n\n");
		printf("Datos de la cuenta");
		printf("\nCuenta Nro %d", numeroCuenta);
		printf("\nDNI N°: %d", dni);
		
		if ( saldo > 0)
		{
			printf("\nSaldo ACREEDOR de: $ %.2f", saldo);
			totalSaldosAcreedores = totalSaldosAcreedores + saldo;
		}
		else
		{
			if ( saldo < 0 )
			{
				printf("\nSaldo DEUDOR por: $ %.2f", saldo);
			}
			else
			{
				printf("\nSaldo NULO: $ 0.00");
			}
		}
		
	} // for
	
	printf("\n\n");
	printf("El total de saldos acreedores es $ %.2f", totalSaldosAcreedores);
	
	
	
	printf("\n\n");
	system("pause");
}
