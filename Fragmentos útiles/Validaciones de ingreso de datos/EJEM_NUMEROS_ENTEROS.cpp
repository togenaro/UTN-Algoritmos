#include <stdlib.h>
#include <stdio.h>

main()
{
	int N = 0;
	float Nfloat = 0.0;
	
	do
	{	
		system("cls");
		printf("Ingrese un numero: ");
		scanf("%f", & Nfloat);
			
		N = Nfloat; // Sacar parte entera del numero flotante
		Nfloat = (float)(Nfloat - N); // Sacar parte decimal del numero flotante
					
		if (Nfloat > 0 || Nfloat < 0)
		{
			system("cls");
			printf("El numero ingresado es decimal.\n\n");
			system("pause");
		}
		else if(Nfloat == 0)
		{
			system("cls");
			printf("El numero ingresado es entero.\n\n");
			printf("\nFinalizando...\n\n");
		}
		
	}
	while (Nfloat > 0 || Nfloat < 0);
		
	system("pause");
	
	system("cls");
	printf("N vale: %d\n\n", N);
	system("pause");
	
}

