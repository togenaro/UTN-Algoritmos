Funcion cargaDatos(asignatura, cantidadAlumnos, N)
	
	para i<-1 Hasta N Con Paso 1 Hacer
		
		Limpiar Pantalla
		
		Mostrar 'Ingrese la asignatura'
		leer asignatura[i]
		
		Mostrar 'Ingrese la cantidad de alumnos'
		leer cantidadAlumnos[i]
		
	FinPara
	
FinFuncion

Funcion posicion = asignaturaMayor(asignatura, cantidadAlumnos, N)
	
	Definir mayorr Como Entero
	Definir auxiliar Como Entero
	
	mayorr = -9999
	
	Para i<-1 Hasta N Con Paso 1 Hacer
		
		Si cantidadAlumnos[i] > mayorr Entonces
			
			mayorr = cantidadAlumnos[i]
			posicion = i
			
		FinSi
		
	FinPara
	
FinFuncion

Funcion cantidad = analizarAsignatura(asignatura, cantidadAlumnos, N)
	
	Definir centinela Como Caracter
	Mostrar 'Ingrese asignatura a analizar: '
	Leer centinela
	
	Para i<-1 Hasta N Con Paso 1 Hacer
		
		Si asignatura[i] == centinela Entonces
			
			cantidad = cantidadAlumnos[i]
			
		FinSi
		
	FinPara
	
FinFuncion

Algoritmo tp6_ejercicio_03
	
	Definir posicion Como Entero
	definir N Como Entero
	Mostrar 'Ingrese el valor de N: '
	leer N
	
	Dimension asignatura[N]
	Dimension cantidadAlumnos[N]
	
	cargaDatos(asignatura, cantidadAlumnos, N)
	
	posicion = asignaturaMayor(asignatura, cantidadAlumnos, N)
	Limpiar Pantalla
	Mostrar 'La asignatura con mayor cantidad de alumnos es: ' asignatura[posicion], ' con ' cantidadAlumnos[posicion]
	
	cantidad = analizarAsignatura(asignatura, cantidadAlumnos, N)
	Mostrar 'La cantidad de alumnos de la asignatura ingresada es: ' cantidad
	
FinAlgoritmo

