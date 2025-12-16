#include <stdlib.h>
#include <stdio.h>

main()
{
	int divisor = 0;
	int divisores = 0;
	int num = 0;
	
	printf("INGRESE UN NUMERO: ");
	scanf("%d", &num);
		

		divisores = 0;
		divisor = 1;
		
		do
		{
			if(num % divisor == 0)
			{
				divisores++;
			}
		
			divisor++;
		}
		while(divisor <= num);
		
		
		
		if(divisores == 2)
		{
			printf("El numero es primo.");
		}		
		else
		{
			printf("El numero no es primo.");
		}
	

	printf("\n\n");
	system("pause");
	
}
