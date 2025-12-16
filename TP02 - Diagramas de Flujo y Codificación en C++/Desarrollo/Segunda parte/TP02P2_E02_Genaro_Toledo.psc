// Se lee la base y la altura de un conjunto de rectángulos. Se pide mostrar el valor del
// área, la base y la altura, solo de aquellos rectángulos cuyo perímetro sea menor a un valor
// dado (o sea ingresado como dato). Continuar ingresando valores (base y altura) hasta que la
// base ingresada sea igual a cero.
Algoritmo sin_titulo
	
	Repetir
		
		Limpiar Pantalla
		Escribir 'Ingrese la base del rectángulo: '
		Leer base
		
		si base = 0 Entonces
			
			Limpiar Pantalla
			Mostrar 'La base debe ser distinta de cero. Ingrese nuevamente'
			leer asd //pausa del sistema
			
		FinSi
		
	Hasta Que base <> 0
	
	Mientras base <> 0 Hacer
		
		Repetir
			
			Limpiar Pantalla
			Escribir 'Ingrese la altura del rectangulo: '
			Leer altura
			
			si altura = 0 Entonces
				
				Limpiar Pantalla
				Mostrar 'La altura debe ser distinta de cero. Ingrese nuevamente'
				leer asd //pausa del sistema
				
			FinSi
			
		Hasta Que altura <> 0
		
		area <- (base*altura)
		perimetro <- (base*2)+(altura*2)
		
		Limpiar Pantalla
		Escribir 'Ingrese un valor mínimo para el perímetro'
		Leer valor
		Limpiar Pantalla
		
		Si perimetro<=valor Entonces
			
			Escribir 'La base ingresada del rectangulo es: ',base
			Escribir ' '
			Escribir 'La altura ingresada del rectangulo es: ',altura
			Escribir ' '
			Escribir 'El area del rectángulo es: ',area
			leer asd //pausa del sistema
			Limpiar Pantalla
			
		SiNo
			
			Escribir 'El area no se puede calcular porque el perímetro supera al valor dado.'
			leer asd //pausa del sistema
			Limpiar Pantalla
			
		FinSi
		Escribir 'Ingrese la base del rectángulo (0 para cancelar)'
		Leer base
		Limpiar Pantalla
		

		
	FinMientras
	
FinAlgoritmo
