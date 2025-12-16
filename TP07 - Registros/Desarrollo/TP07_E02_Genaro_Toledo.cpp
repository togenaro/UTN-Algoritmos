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
#include <math.h>

struct registro
{
	float PX1;
	float PX2;
	float PY1;
	float PY2;
	
};

void cargaCoordenadas(registro &f01_reg)
{
	printf("--PUNTO 1--\n");
	printf("INGRESE VALOR DE X: ");
	scanf("%f", &f01_reg.PX1);
	printf("INGRESE VALOR DE Y: ");
	scanf("%f", &f01_reg.PY1);
	printf("\n--PUNTO 2--");
	printf("\nINGRESE VALOR DE X: ");
	scanf("%f", &f01_reg.PX2);
	printf("INGRESE VALOR DE Y: ");
	scanf("%f", &f01_reg.PY2);
}

void mostrarCoordenadas(registro f02_reg)
{
	printf("\nCoordenadas del punto 1: (%.2f , %.2f)", f02_reg.PX1, f02_reg.PY1);
	printf("\nCoordenadas del punto 2: (%.2f , %.2f)", f02_reg.PX2, f02_reg.PY2);	
}

void calcularDistanciaOrigen(registro f03_reg)
{
	float X = 0;
	float Y = 0;
	float distancia = 0;
	
	X = pow(f03_reg.PX1, 2);
	Y = pow(f03_reg.PY1, 2);
	
	distancia = sqrt(X+Y);
	
	printf("\nDistancia del eje de coordenadas al origen: %.2f", distancia);
}

void calcularLongitudSegmento(registro f04_reg)
{	
	float S1 = 0;
	float S2 = 0;
	float segmento = 0;
	
	S1 = pow(((f04_reg.PX2)-(f04_reg.PX1)), 2);
	S2 = pow(((f04_reg.PY2)-(f04_reg.PY1)), 2);
	
	segmento = sqrt(S1+S2);
	
	printf("\nLongitud del segmento de recta: %.2f", segmento);	
}

main()
{
	system("color F0");
	
	registro reg;
	
	cargaCoordenadas(reg);
	mostrarCoordenadas(reg);
	calcularDistanciaOrigen(reg);
	calcularLongitudSegmento(reg);
	
	printf("\n\n");
	system("pause");
}


