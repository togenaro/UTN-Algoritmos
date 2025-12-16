Algoritmo Ejercicio_6 
	
	Definir egresadosElectrica Como Entero
	Definir egresadosMecanica Como Entero
	Definir egresadosISI Como Entero
	Definir legajo Como Entero
	Definir carrera Como Entero
	Definir porcentajeElectrica Como Real
	Definir porcentajeISI Como Real
	Definir porcentajeMecanica Como Real
	definir cantidadEgresados Como Entero
	
	// Condiciones vinculantes
	
	Repetir
	
	Escribir 'Ingrese la cantidad de alúmnos egresados'
	leer cantidadEgresados
	Limpiar Pantalla
	
	Hasta Que cantidadEgresados <> 0 
	
	Para x <- 1 Hasta cantidadEgresados Con Paso 1 Hacer
	
	Escribir 'Ingrese el legajo del alúmno ',x ':'
	Leer legajo
			
			Escribir 'Ingrese una carrera (1: ISI|2: Electronica|3: Mecanica)'
			Leer carrera
			Limpiar Pantalla
			
			Mientras carrera<=0 O carrera>3 Hacer
				
				Limpiar Pantalla
				Escribir 'Carrera incorrecta, ingrese nuevamente (1: ISI|2: Electronica|3: Mecanica)'
				Leer carrera
				
			FinMientras
			
			Si (carrera=1) Entonces
				
				egresadosISI <- egresadosISI+1
				
			SiNo
				
				Si (carrera=2) Entonces
					
					egresadosMecanica <- egresadosMecanica+1
					
				SiNo
					
					Si (carrera=3) Entonces
						
						egresadosElectrica <- egresadosElectrica+1
						
					FinSi
					
				FinSi
				
			FinSi
			
		FinPara
	
	
	Limpiar Pantalla
	
	//Resultados
	
	totalEgresados <- egresadosISI+egresadosMecanica+egresadosElectrica
	Escribir 'Total de egresados: ',totalEgresados
	
	Mostrar "                     "
	porcentajeISI <- (egresadosISI/totalEgresados)*100
	Escribir 'Cantidad de egresados de ISI: ',egresadosISI
	Escribir 'Porcentaje de egresados de ISI: ',porcentajeISI
	
	Mostrar "                     "
	porcentajeMecanica <- (egresadosMecanica/totalEgresados)*100
	Escribir 'Cantidad de egresados de Mecanica: ',egresadosMecanica
	Escribir 'Porcentaje de egresados de Mecanica: ',porcentajeMecanica
	
	Mostrar "                     "
	porcentajeElectrica <- (egresadosElectrica/totalEgresados)*100
	Escribir 'Cantidad de egresados de Electrica: ',egresadosElectrica
	Escribir 'Porcentaje de egresados de Electrica: ',porcentajeElectrica
	
	
FinAlgoritmo
