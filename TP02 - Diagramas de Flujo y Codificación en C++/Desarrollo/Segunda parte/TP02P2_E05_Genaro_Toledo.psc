// Desarrolle el algoritmo donde un comerciante ingresa por teclado el código
// de un artículo (el cual solo puede ser 1, 2, 3) y el total de venta realizadas para 
// ese artículo en el mes.
// Cuál es el código y el monto del artículo que más vendió en el mes.
// Indicar el importe total vendido de los tres artículos.
// Mostrar el porcentaje venta que representa el artículo de mayor venta sobre el
// total de las ventas del mes.

Algoritmo Ejercicio_05
	
	Repetir
		
		Escribir 'Ingrese el código del artículo (1, 2 o 3)'
		Leer codigo
		
		Mientras codigo<=0 O codigo>3 Hacer
			
			Limpiar Pantalla
			Escribir 'Código incorrecto. Ingrese nuevamente (1, 2 o 3)'
			Leer codigo
			Limpiar Pantalla
			
		FinMientras
		
		Limpiar Pantalla
		Escribir 'Ingrese el total de ventas del artículo en éste més'
		Leer totalVenta
		
		Si codigo=1 Entonces
			
			ventasArticulo1 <- ventasArticulo1+totalVenta
			
		SiNo
			
			Si codigo=2 Entonces
				
				ventasArticulo2 <- ventasArticulo2+totalVenta
				
			SiNo
				
				Si codigo=3 Entonces
					
					ventasArticulo3 <- ventasArticulo3+totalVenta
					
				FinSi
				
			FinSi
			
		FinSi
		
		Escribir '¿Desea ingresar otro artículo? (SI: 1|NO: CUALQUIER NÚMERO)'
		Leer siono
		Limpiar Pantalla
		
	Hasta Que siono<>1
	
	importeTotal <- ventasArticulo1+ventasArticulo2+ventasArticulo3
	Escribir 'El importe total de ventas de los tres artículos es de: ',importeTotal
	Escribir '  '
	
	Si ventasArticulo1>ventasArticulo2 Y ventasArticulo1>ventasArticulo3 Entonces
		
		porcentajeVentas <- (ventasArticulo1/importeTotal)*100
		Escribir 'El código del artículo más vendido es: 1'
		Escribir '  '
		Escribir 'La cantidad que se vendió de éste artículo es: ',ventasArticulo1
		Escribir '  '
		Escribir 'El porcentaje de ventas sobre el total del artículo 1 es: ',porcentajeVentas
		
	SiNo
		
		Si ventasArticulo2>ventasArticulo1 Y ventasArticulo2>ventasArticulo3 Entonces
			porcentajeVentas <- (ventasArticulo2/importeTotal)*100
			Escribir 'El código del artículo más vendido es: 2'
			Escribir '  '
			Escribir 'La cantidad que se vendió de éste artículo es: ',ventasArticulo2
			Escribir '  '
			Escribir 'El porcentaje de ventas sobre el total del artículo 2 es: ',porcentajeVentas
			
		SiNo
			
			Si ventasArticulo3>ventasArticulo1 Y ventasArticulo3>ventasArticulo2 Entonces
				porcentajeVentas <- (ventasArticulo3/importeTotal)*100
				Escribir 'El código del artículo más vendido es: 3'
				Escribir '  '
				Escribir 'La cantidad que se vendió de éste artículo es: ',ventasArticulo3
				Escribir '  '
				Escribir 'El porcentaje de ventas sobre el total del artículo 3 es: ',porcentajeVentas
				
			FinSi
			
		FinSi
		
	FinSi
	
	Si ventasArticulo1=ventasArticulo2 Y ventasArticulo1<>0 Y ventasArticulo2<>0 Entonces
		
		porcentajeVentas <- ((ventasArticulo1+ventasArticulo2)/importeTotal)*100
		Escribir 'La cantidad de los artículos 1 y 2 es la mísma'
		Escribir '  '
		Escribir 'El porcentaje de ventas de los artículos 1 y 2 es de: ',porcentajeVentas
		
	SiNo
		
		Si ventasArticulo1=ventasArticulo3 Y ventasArticulo1<>0 Y ventasArticulo3<>0 Entonces
			
			porcentajeVentas <- ((ventasArticulo1+ventasArticulo3)/importeTotal)*100
			Escribir 'La cantidad de los artículos 1 y 3 es la mísma'
			Escribir '  '
			Escribir 'El porcentaje de ventas de los artículos 1 y 3 es de: ',porcentajeVentas
			
		SiNo
			
			Si ventasArticulo2=ventasArticulo3 Y ventasArticulo2<>0 Y ventasArticulo3<>0 Entonces
				
				porcentajeVentas <- ((ventasArticulo2+ventasArticulo3)/importeTotal)*100
				Escribir 'La cantidad de los artículos 2 y 3 es la mísma'
				Escribir '  '
				Escribir 'El porcentaje de ventas de los artículos 2 y 3 es de: ',porcentajeVentas
				
			FinSi
			
		FinSi
		
	FinSi
	
FinAlgoritmo
