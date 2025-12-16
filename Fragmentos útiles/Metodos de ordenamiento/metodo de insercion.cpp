// Metodo de ordenamiento por inserción

#include <stdio.h>
#include <stdlib.h>

void metodoInsercion(int numeros[])
{
	int i=0, ia, iv;
	
	for(i=0;i<5;i++)
	{
	
		ia = i;/////
		iv = numeros[i];//9//8
		
		while((ia > 0) && (numeros[ia-1] > iv))
		
		{
			numeros[ia]=numeros[ia-1];
			ia--;
		}
		
		numeros[ia]= iv;
		
	}
	printf("forma ascendente:");
	
    for(i=0;i<5;i++)
    {
   		printf(" %d", numeros[i]);	
	}


	printf("\n\n");
	system ("pause");
}


main()
{
	int numeros[]={9,8,5,7,6};
	
	metodoInsercion(numeros);
}
