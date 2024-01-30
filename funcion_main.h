#ifndef FUNCION_MAIN_H_INCLUDED
#define FUNCION_MAIN_H_INCLUDED


void menu(int&);

void reglas();



/**
1.Lo que hace la funcion es verificar el puntaje maximo y el nombre del jugador con mayor puntaje de todos los juegos que se inicicien.
2.como funciona? Se pregunta si puntuacion o puntuacion maxima multiplayer es distinto de -1. Esto sirve para verificar que se ha ingresado
al menos una puntuacion dentro del juego.
3. Despues se vuelve a preguntar y en el primer caso se pregunta si puntuacion la puntuacion maxima de la partida individual es mayor a la puntuacion
maxima de la partida multijugador y  tambien si la puntuacion maxima del modo individual es mayor a la puntuacion maxima final.
    3.1 si da verdadero le asigno la puntuacion maxima del modo individual a la puntuacion maxima final y despues utilizo la funcion "STRING COPY"
    que previamente para poder utilizarla he tenido que incluir la libreria "CSTRING". Lo que hace la funcion STRING COPY es permitirme copiar cadena
    de caracteres tomando dos argumentos que son "el destino y el origen". El DESTINO seria "NOMBRE_FINAL" y el origen seria "NOMBRE".
    3.2 Si se cumple esta condicion ya se que el nombre corresponde al jugador actual del modo individual.

4.Despues si no se cumple esta condicion pasaria a preguntar si la puntuacion maxima del modo multijugador es mayor al puntuacion maxima del modo individual
y mayor a la puntuacion maxima final.
5. Si la condicion se cumple le asigno la puntuacion maxima del modo multijugador a la puntuacion maxima final.
6. En este punto ya se que la puntuacion maxima corresponde a algun jugador del modo multijugador y para poder asignarle el nombre vuelvo a preguntar si
la puntuacion maxima del modo multijugador es igual a "acu_puntos_player 1" que vendria a ser el puntaje acumulado del jugador numero 1.
    6.1 si es puntaje es igual le asigno el nombre del primer jugador a la variable nombre_final.
    6.2 si el puntaje no es igual pregunto si el puntaje es igual al puntaje acumulado del jugador numero 2. Y si es igual le asigno a nombre_final
    el nombre del jugador numero dos.
*/
void puntuacionMaximaFinal_3(int& puntuacion_maxima_final, int& puntuacion_maxima, int& puntuacion_maxima_multiplayer, int acu_puntos_player1, int acu_puntos_player2, char nombre[], char nombre_player1[], char nombre_player2[], char nombre_final[]);



void mostrarPuntuacionFinal(int puntuacion_maxima_final, char nombre_final[]);



///// MODO UN JUGADOR /////

void singlePlayer(int& puntuacion_maxima, char nombre[], int& puntos, int& lanzamientos, int& ronda, int& max_ronda, bool& salir, int& acu_puntos, bool& flag_sexteto_seis, int& d1, int& d2, int& d3, int& d4, int& d5, int& d6);



/**
1. Toma como parametro un vector de tipo char
2. Se utiliza la funcion cin>>::ws; para descartar los espacios en blanco y saltos de linea
3. Se utiliza la funcion cin.getline para leer una linea de texto y guardarla en el vector.
El delimitador \n indica que la entrada tiene que terminar al encontrar un salto de linea.

--BUFER DE ENTRADA es un area de memoria temporal que se usa para almacenar datos. El uso que tiene la funcion cin>>std::ws;
es descartar los espacios en blanco y saltos de linea que puedan haber en quedado en el bufer de entrada despues de leer otros datos.
*/
void pedirNombre(char []);




///// MODO 2 JUGADORES /////

void pedirNombres(char [], char []);

void modoMultiplayer(int& puntuacion_maxima_multiplayer, char nombre_player1[], char nombre_player2[], int& puntos_player1, int& puntos_player2, int& lanzamientosPlayer1, int& lanzamientosPlayer2, int& max_rondap1, int& max_rondap2, int& ronda_player1, int& ronda_player2, int& acu_puntos_player1, int& acu_puntos_player2, bool& flag_sexteto_seis_p1, bool& flag_sexteto_seis_p2, bool& salir_player1, bool& salir_player2, bool& flag_ganador_player1, bool& flag_ganador_player2, int& d1, int& d2, int& d3, int& d4, int& d5, int& d6);



//// COMBINACIONES DE DADOS ////

/**
1.La funcion dados_x6 lo que hace es generar numeros aleatorios del 1 al 6 tomando como parametros los dados del 1 al 6 por referencia.
2.Funciona de la siguiente manera: la funcion "rand()" genera un numero aleatorio.
3.Despues lo que hace es calcular el resto de dividir el numero aleatorio entre 6. Esto lo que hace es asegurar de que el resto de la operacion de entre
0 y 5. Despues se le suma 1 para generar un numero aleatorio del 1 al 6
4. Por ejemplo si se genera el numero 17. El resto de dividir 17 entre 6 es 5 y al 5 se le suma 1 y eso da un resultado de 6 que es el valor del dado.
*/
void dados_x6(int& dado1, int& dado2, int& dado3, int& dado4, int& dado5, int& dado6);



/**
1. Primero se asignan las variables auxiliares que me van a ayudar a calcular el resultado final de la combinacion.
2. Despues se declara un ciclo for de 6 vueltas que va del 1 al 6 que son los numeros que representan el valor de los dados
3. Despues se inicializa en 0 la variable "repeticiones" que sirve para saber cuantas veces se repite el mismo numero.
4. Despues se comparan todos los dados con el valor de "x", y si son iguales incrementa el valor de repeticiones en 1.
5. Despues de contar las repeticiones con el numero de valor "x" actual se verifica si estan dentro del rango de 3 a 5 repeticiones.
6. Si se cumple la condicion se asigna el valor de "X" a la variable dadoX que sirve para calcular el puntaje de la tirada.
7. Si hay mas de un numero que se repite 3 veces se pregunta si la varaible repeticiones es igual a max_repeticiones y
si el valor de "x" es mayor que el valor de dadoX actual.
8. Si es mayor se remplaza sino queda igual.
9. Al finalizar el ciclo se le asigna el puntaje a la variable Resultado y se retorna esa misma variable.
*/
int combinacion_tres(int d1, int d2, int d3, int d4, int d5, int d6);




/**
	1. Creo una funcion tipo int que toma como parametros el valor de los dados
	2. Creo la variable resultado para utilizarla como valor de retorno al final de la funcion
	3. Despues pregunto si todos los dados son iguales entre si
	4. Si son iguales pregunto si son diferentes de 6
	5. Si son diferentes de 6 calculo el valor del dado por 50
	5. Por ultimo a la variable resultado le asigno el calculo de la combinacion y luego me retorna ese valor.
*/
int sexteto(int d1, int d2, int d3, int d4,int d5, int d6);



/**
	1. Creo una funcion tipo bool que toma como parametros el valor de los dados
	2. Creo una variable tipo bool para utilizarla como bandera que se inicializa en false
	3. Despues pregunto si todos los dados son iguales 6
	4. Si se cumple la condicion la bandera cambia a true
	5. La funcion retorna el valor de la bandera
	6. Mas adelante esa bandera sirve para determinar el puntaje maximo al finalizar la ronda del jugador
*/
bool sexteto_seis(int d1, int d2, int d3, int d4,int d5, int d6);



/**
1. Se crea un vector de dados que contiene los valores de los dados.
2. Lo valores se copian en el mismo orden que se pasaron a la funcion.
3. Se utiliza la funcion sort para ordenar el vector de forma ascendente.
4. Se compara mediante un ciclo for y un if si vector dados en el indice [i] +1 es igual al siguiente numero en el arregalo.
5. Si la suma no es igual, la secuencia no es consectutiva y retorna false.
6. Si ciclo se ejecuta sin ningun problema retorna true.

--dados[i] + 1 significa que se suma 1 al número en el indice "i" del arreglo.
--dados[i + 1] se refiere al número en la siguiente posición consecutiva en el vector dados.
.

--La función std::sort() toma dos parámetros: el primero es un iterador al inicio del rango a ordenar, y el segundo es un iterador al final
del rango a ordenar. Dados actúa como un iterador al inicio del rango, y dados + 6 actúa como un iterador al final del rango

--La razón por la que se utiliza std::sort(dados, dados + 6) en lugar de simplemente std::sort(dados) es que la función std::sort() requiere
especificar el rango completo a ordenar. En este caso, el rango es desde el primer elemento del arreglo hasta el elemento siguiente al último elemento.
*/
bool escalera(int d1, int d2, int d3, int d4, int d5, int d6);




void ingresarDadosManualmente(int& d1, int& d2, int& d3, int& d4, int& d5, int& d6);



//// DIBUJAR DADOS /////

/**
1. La funcion se encargar de dibujar un cuadrado
2. Toma dos parametros de entrada: posX y posY que representan las coordenadas
3. Se utilizan matrices para iterar sobre las coordenadas X e Y del cuadrado
4. El ciclo externo "X" determina el ancho del cuadrado y el ciclo interno "Y" determina la altura del cuadrado.
5. Dentro del ciclo se utiliza la funcion locate de rlutil para determinar la posicion de impresion en pantalla, que
se calcula sumando la coordenada actual X o Y con las coordenadas de desplazamiento propocionadas por posX y posY.
6. Por ultimo se "castea" un "COUT" para imprimir el caracter correspondiente al codigo ASCII 219.
*/
void dibujarCuadrado(int, int);


/**
1. Combina dos funciones, dibujar cuadrado y dibujar puntos.
2. Toma 3 parametros, el numero del dado, posX y posY que son las coordenadas.
3. Primero llama a la funcion dibujar cuadrado con los parametros posX y posY en la posicion indicada
4. Despues llama a la funcion dibujar puntos con los parametros numero, posX y posY para dibujar los puntos
correspondientes segun el valor del dado en la posicion indicada.
*/
void dibujarDado(int, int, int);


/**
Lo que hace esta funcion es dibujar patrones de puntos en la pantalla mediante codigo ascii dependiento del valor del
parametro numero (valor del dado).
*/
void dibujarPuntos(int numero, int posx, int posy);


#endif // FUNCION_MAIN_H_INCLUDED
