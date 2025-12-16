#include<iostream>
using namespace std;

const int ORDEN = 15;

void quicksort(int* arr,int izq,int der)

{
	
	
	int i=izq,j=der,tmp;
	int p=arr[(izq+der)/2];
	
	while(i<=j){
		
		while(arr[i]<p)i++;
		while(arr[j]>p)j--;
		if(i<=j)
		{
			tmp=arr[i];
			arr[i]=arr[j];
			arr[j]=tmp;
			i++;j--;
			
		}
	}
	if(izq<j)
		quicksort(arr,izq,j);
		if(i<der){
			quicksort(arr,i,der);
		
	}
		
	
		
}
main()
{
	cout<<"este es el codigo quicksort\n\n";
	cout<<"esta es la lista a ordenar\n";
	cout<<"88,6,69,-33,98,7,23,5,0,100\n";
	cout<<"la lista de abajo ya se ha ordenado\n\n";
	
	int N = 10;
	int derecha = 0;
	int arreglo[N]={88,6,69,-33,98,7,23,5,0,100};
	
	derecha = (N - 1);
	
	quicksort(arreglo, 0, derecha);
	
	for(int i=0; i<N; i++)
	cout<<arreglo[i]<<" ";
	 
	system("pause");
	return 0;
	
}
