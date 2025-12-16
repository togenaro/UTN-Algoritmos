Algoritmo Ejercicio_8
	
	Mostrar 'Ingrese la cantidad de números a analizar'
	Leer cantidad
	Limpiar Pantalla
	
	Para x<-1 Hasta cantidad Con Paso 1
	
		Repetir 
			
			Mostrar 'NÚMERO: ', x
			Mostrar 'Ingrese un número de tres cifras'
			Leer numero
			Limpiar Pantalla
		
			Si (numero < 100) o (numero > 999)
			
				Mostrar 'El número debe tener tres cifras. (Presione una tecla para continuar)'
				Leer pausa
				Limpiar Pantalla
			
			FinSi
			
			Si (numero >= 100) y (numero <= 999)
			
				digito = numero % 10
				Mostrar 'El último dígito del número ingresado es: ', digito
				Mostrar '-------------------------------------------'
				Mostrar 'Presione una tecla para continuar'
				Leer pausa
				Limpiar Pantalla
			
			FinSi
			
		Hasta Que numero >= 100 y numero <= 999
	
	FinPara

	
	
FinAlgoritmo
