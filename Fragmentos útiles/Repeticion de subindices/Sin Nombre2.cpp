#include <stdio.h>
#include <stdlib.h>


main()
{
	system("color F0");
	
	int vector[] = {1, 2, 3, 4, 5, 6, 9, 8, 9, 10, 10};
	int L = 0;
	int repeticiones = 0;
	int valor = 0;
	int N = 0;
	
	N = 12;
	L = N-1;
	
	for(int i=0; i<N; i++)
	{
		
		for(int n=i+1; n<L; n++)
		{
			if(vector[i] == vector[n] && vector[i] != NULL)
			{
				repeticiones++;
				valor = vector[i];
				break;					
			}	
		}
		
		for(int c=0; c<N; c++)
		{
			if(valor == vector[c])
			{
				vector[c] = NULL;
			}
		}
		
	}
	
	printf("%d", repeticiones);
	
	printf("\n\n");
	system("pause");
			
}
	

