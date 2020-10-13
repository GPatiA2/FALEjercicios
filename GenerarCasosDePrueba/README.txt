Instrucciones para usar el generador:

 - Para cambiar el número de casos de prueba que se generan por ejecución cambiar la constante NUMCASOS

 - La semilla se genera a partir de la fecha y hora internas de vuestro ordenador
   Esto provoca que si ejecutais el programa varias veces seguidas, os saldrán casos parecidos.
   Por ello es por lo que pone srand(i*(time(NULL) + i)), así cada vez que ejecuteis el programa os saldrán casos relativamente distintos.

 - Si quereis evitar que os salgan 0 en los datos iniciales, sumadle 1 al numero aleatorio generado
   Ejemplo:  longitud = (rand() % 50) + 1; da números del 1 al 51
	     longitud = (rand() % 50); da números del 0 al 50;

 - Podeis cambiar el nombre del fichero donde se vuelcan los casos generados.

 - Podeis alterar el rango en el que se generan los numeros aleatorios cambiado el número con el que se hace el módulo al generarlos.

 - Tened en cuenta que cuantos más casos generéis en la misma ejecución, más posibilidades teneis de que se repitan números.
