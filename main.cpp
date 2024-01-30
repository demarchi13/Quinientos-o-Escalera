#include<iostream>
#include "rlutil.h"
#include "funcion_main.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cstring>

int main() {

    srand(time(nullptr));

    int puntuacion_maxima_final = -1;
    char nombre_final[100];
    int op;

    //MODO UN JUGADOR
    char nombre[100];
    int puntuacion_maxima = -1;
	int puntos;
	int lanzamientos;
	int ronda;
	int max_ronda;
    int acu_puntos;
	bool salir;
	bool flag_sexteto_seis;

	//MODO 2 JUGADORES
	char nombre_player1[100];
	char nombre_player2[100];
	int puntuacion_maxima_multiplayer = -1;
	int puntos_player1;
	int puntos_player2;
	int lanzamientosPlayer1;
	int lanzamientosPlayer2;
	int max_rondap1;
	int max_rondap2;
	int ronda_player1;
	int ronda_player2;
	int acu_puntos_player1;
	int acu_puntos_player2;
	bool flag_sexteto_seis_p1;
	bool flag_sexteto_seis_p2;
	bool flag_ganador_player1;
	bool flag_ganador_player2;
	bool salir_player1;
	bool salir_player2;

    do {

    int d1=0, d2=0, d3=0, d4=0, d5=0, d6=0;

    menu(op);

    switch(op){
    case 1:
        singlePlayer(puntuacion_maxima, nombre, puntos, lanzamientos, ronda, max_ronda, salir, acu_puntos, flag_sexteto_seis, d1,d2,d3,d4,d5,d6);
        break;

    case 2:
        modoMultiplayer(puntuacion_maxima_multiplayer, nombre_player1, nombre_player2, puntos_player1, puntos_player2, lanzamientosPlayer1, lanzamientosPlayer2, max_rondap1, max_rondap2, ronda_player1, ronda_player2, acu_puntos_player1, acu_puntos_player2, flag_sexteto_seis_p1, flag_sexteto_seis_p2, salir_player1, salir_player2, flag_ganador_player1, flag_ganador_player2, d1, d2, d3, d4, d5, d6);
        break;

    case 3:
        puntuacionMaximaFinal_3(puntuacion_maxima_final,puntuacion_maxima,puntuacion_maxima_multiplayer,acu_puntos_player1,acu_puntos_player2,nombre,nombre_player1,nombre_player2,nombre_final);
        mostrarPuntuacionFinal(puntuacion_maxima_final, nombre_final);
        break;

    case 4:
        reglas();
        break;

    default:
        break;
    }// FIN SWITCH

}while(op != 5);

    return 0;
}
