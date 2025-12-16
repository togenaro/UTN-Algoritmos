Algoritmo Ejercicio_10
	
	Repetir
		
		Mostrar 'Ingrese la cantidad de números a analizar'
		Leer cantidad
		Limpiar Pantalla
		
		Si cantidad <= 0 Entonces
			
			Mostrar 'Cantidad incorrecta. (Pulse una tecla para continuar)'
			Leer pausa
			Limpiar Pantalla
			
		FinSi
		
		
	Hasta Que cantidad > 0
	
	Para x <- 1 Hasta cantidad Con Paso 1 
		
		residuo = 0
		operacion = 0
		
		Repetir
			
			Mostrar 'NÚMERO: ', x
			Mostrar 'Ingrese el número a analizar'
			Leer numero
			Limpiar Pantalla
			
			Si numero <= 0 Entonces
				
				Mostrar 'El número debe ser positivo y distinto de cero. (Pulse una tecla para continuar)'
				Leer pausa
				Limpiar Pantalla
				
			FinSi
			
		Hasta Que numero > 0
	
		Para divisor <- 1 Hasta 10 Con Paso 1 
			
			operacion = numero % divisor
		
			si operacion = 0 Entonces
				
				residuo = residuo + 1
			
			FinSi
		
		FinPara
		
		Si residuo = 2 Entonces
		
			Mostrar 'El número ',numero ' ES PRIMO'
			Leer pausa
			Limpiar Pantalla
		
		SiNo
		
			Mostrar 'El número ',numero ' NO ES PRIMO'
			leer pausa
			Limpiar Pantalla
		
		FinSi
	
	FinPara

		
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
FinAlgoritmo
