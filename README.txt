# Ordenar Evaluaciones Deportivos
(1) Resenja
El programa toma un archivo de texto de entrada. El archivo de texto debe contener una id de ocho
digitos, una evaluacion con tres digitos y la abreviacion de un evento con 6 caracteres incluyendo tres
caracteres seguidos y tres digitos seguidos. Un conjunto de los tres datos debe estar en una linea
del archivo de texto separado por un espacio (no tiene que ser ordenado). Se puede verificar el
archivo de texto "datos_desordenados". Se saltean lineas invalidas.
El programa extrae los datos y los guarda en una estructura de datos "atleta". Todas las entradas
se almacenan en un arreglo.
Despues hay tres algoritmos de sorteo que son capaces de sortear los datos segun el id.
Se genera el archivo con los datos ordenados y despues un archivo de reporte de los diferentes
algoritmos de sorteo compuesto por Bubble Sort, Quick Sort, Radix Sort.
En el archivo de texto del reporte hay una tabla con los tiempos de demora y comparaciones ejecutando
cada algoritmo con los datos especificado en el archivo de entrada.

(2) Condiciones de compilacion y ejecucion:
version de gcc 4.8.5

(3) Compilacion y Ejecucion
(a) Compilacion

gcc -std=c99 -Wall -Wextra -Iinclude -c src/main.c -o build/main.o
gcc -std=c99 -Wall -Wextra -Iinclude -c src/lector.c -o build/lector.o
gcc -std=c99 -Wall -Wextra -Iinclude -c src/utils.c -o build/utils.o
gcc -std=c99 -Wall -Wextra -Iinclude -c src/atleta.c -o build/atleta.o
gcc -std=c99 -Wall -Wextra -Iinclude -c src/ordenamiento.c -o build/ordenamiento.o
gcc  build/main.o  build/lector.o  build/utils.o  build/atleta.o  build/ordenamiento.o -o build/ordenar_eval -lrt -lm

o usar el makefile donde se ejecutan los comandos arriba en un conjunto ingresando 'make' en linea del comando.

(b) Ejecucion
En la carpeta del makefile ejecutar:

./build/ordenar_eval <path/to/.txt/>

Se puede activar salida de texto verbosa con el indicador '-v'

./build/ordenar_eval <path/to/.txt/> -v

(4) Creador del programa
Jan Fenker, RUT-USM: 90.004.813-0
