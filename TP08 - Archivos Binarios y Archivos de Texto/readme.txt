// ----------------------------------------------------------
Los archivos de texto son de tipo secuencial. No hay posibilidad de manipular la posición de un puntero.

fputs(strcat(cadena. "\n"), archivo);
luego de poner la cadena en el archivo de texto, se cocatena un salto de linea para que la siguiente cadena que se implemente sea abajo de la anterior.
sino
fputs(cadena, archivo);
fputs("\n", archivo);
// ----------------------------------------------------------


// ----------------------------------------------------------
fgets(cadena, sizeof, archivo); gets en archivo.

while(!feof(archivo)
{
	fgets(cadena, sizeof(cadena), archivo); gets en archivo.
}
// ----------------------------------------------------------



