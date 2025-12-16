Algoritmo Ejercicio_06
	
	Definir factorial Como Real
	factorial = 1
	
	Repetir
		
		Mostrar 'Ingrese la cantidad de números a analizar'
		Leer cantidad
		Limpiar Pantalla
		
		Si cantidad = 0 Entonces
			
			Mostrar 'La cantidad debe ser distinta de cero. (Presione una tecla para continuar)'
			leer pausa
			Limpiar Pantalla
			
		FinSi
		
	Hasta Que cantidad <> 0
	
	Para i<- 1 Hasta cantidad Con Paso 1
		
		factorial = 1
		
		Mostrar 'NÚMERO: ', i
		Mostrar 'Introduzca un número: '
		Leer n
		Limpiar Pantalla
		
		Para x <- 1 Hasta n Con Paso 1
	
			factorial = factorial * x
		
		FinPara
	
		Mostrar 'El factorial del número ', n ' es: ', factorial 
		Mostrar '(Presione una tecla para continuar)'
		Leer pausa
		Limpiar Pantalla
		
	
	FinPara
	
FinAlgoritmo
