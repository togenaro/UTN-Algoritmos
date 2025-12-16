#include <iostream>
using namespace std;

void metodoBurbuja(int vector[])
{
	int n = 5;
	int i,j,aux;
	bool bandera;
	
	/*
			primera iteración i=1 bandera=false j=4
				45 > 0
				{99,-3,21,0,45}
				bandera = true;
			segunda iteración i=1 bandera=true j=3	
				21 > 45 no	
				{99,-3,21,0,45}
			tercera iteración i=1 bandera=true j=2
				-3 < 21 no	
				{99,-3,21,0,45}
			cuarta iteracion i=1 bandera=true j=1
				99 < -3 i, por tanto se hace el cambio
				{-3,99,21,0,45}
					primera iteracion i=2 bandera=false j=4
					{-3,99,21,0,45}
					45 < 0 si
					{-3,99,21,0,45}
					bandera = true;
					segunda iteracion i=2 bandera=true j=3  
						{-3,99,21,0,45}
						21 > 0 si.
						  {-3,99,0,21,45}
						  bandera=true;
					tercera iteracion i=2 bandera=true j=2
						{-3,99,0,21,45}
						99>0 si
						{-3,99,0,21,45}	
						primera iteracion i=3 bandera=false j=4         
							{-3,99,0,21,45}
							21 > 45 no
							sin cambios
						segunda iteración i=3 bandera=false j=3
							{-3,99,0,21,45}
							99 > 21 si
							bandera = true;
							{-3,0,21,99,45}
							primera iteracion i=4 bandera=false j=4
							{-3,0,21,99,45}
							99 > 45 si
							bandera=true;
							{-3,0,21,45,99}  							
							i=5 fin del for:							
							{-3,0,21,45,99}	
							
								  
	*/
	
	for(i=1; i<n; i++){
		bandera = false;
		for(j=n-1; j>=i; j--){
			if (vector[j-1] > vector[j]){
				aux = vector [j-1];
				vector[j-1] = vector[j];
				vector[j] = aux;
				bandera = true;
			}
		}
		if(bandera==false) break;
	}
	
	for(i=0;i<n;i++){
		cout<<vector[i]<<" ";
	}
	system("pause");
	
}

main()

{
	int vector[] = {99,-3,21,45,0};
	metodoBurbuja(vector);
}
	
