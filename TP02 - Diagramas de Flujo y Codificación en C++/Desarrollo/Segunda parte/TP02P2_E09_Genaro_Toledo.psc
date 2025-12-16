Algoritmo Ejercicio_9
	
	Repetir
		
		Mostrar 'Ingrese la cantidad de empleados' 
		Leer cantidadEmpleados
		Limpiar Pantalla
		
		Si cantidadEmpleados <= 0 Entonces
			
			Mostrar 'Cantidad de empleados incorrecta. (Presione una tecla para continuar)'
			leer pausa
			Limpiar Pantalla
			
		FinSi
		
	Hasta Que cantidadEmpleados > 0
	
	Para x<-1 Hasta cantidadEmpleados Con Paso 1
		
		Mostrar 'EMPLEADO NÚMERO: ',x
		Mostrar 'Ingrese el D.N.I. del empleado'
		Leer dni
		
		Mostrar 'Ingrese el sueldo del empleado'
		Leer sueldo
		Limpiar Pantalla
		
		Si sueldo >= 38500 y sueldo <= 65300 Entonces
			
			sueldoIntermedio = sueldoIntermedio + 1
			
		FinSi
		
		Si sueldo > sueldoMayor Entonces
			
			sueldoMayor = sueldo
			dniMayor = dni
			
		FinSi
		
		sueldoTotal = sueldoTotal + sueldo
		
	FinPara
	
	Limpiar Pantalla
	
	Mostrar 'La cantidad de empleados que tienen el sueldo entre 38.500 y 65.300 es: ', sueldoIntermedio
	Mostrar 'El sueldo mayor es: ', sueldoMayor '|DNI: ', dniMayor
	Mostrar 'El sueldo total de todos los empleados es: ', sueldoTotal
	
FinAlgoritmo
