#include<iostream>
#include "rlutil.h"
#include "funcion_main.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cstring>


//FUNCION MENU
void menu(int& op){

        rlutil::locate(43,10);
        std::cout<< "1. PARTIDA INDIVIDUAL" << std::endl;
        rlutil::locate(43,11);
        std::cout<< "2. PARTIDA 2 JUGADORES" << std::endl;
        rlutil::locate(43,12);
        std::cout<< "3. PUNTUACION MAXIMA" << std::endl;
        rlutil::locate(43,13);
        std::cout<< "4. REGLAS" << std::endl;
        rlutil::locate(43,15);
        std::cout<< "5. SALIR" << std::endl;

        //LEER OPCION
        rlutil::locate(43,16);
        std::cin>> op;

        //VALIDACION DE OPCIONES DE MENU
        rlutil::cls();
        if(op <=0 || op >5){
            rlutil::locate(30,8);
            rlutil::setColor(rlutil::RED);
            std::cout<< "UTILIZE LAS TECLAS DEL 1 AL 5 PARA DESPLAZARSE POR EL MENU" << std::endl;
            rlutil::setColor(rlutil::WHITE);
        }
}



//PEDIR NOMBRE UN JUGADOR
void pedirNombre(char nombre[]){
	rlutil::locate(45,14);
	std::cout<< "INGRESE SU NOMBRE" << std::endl;
	rlutil::locate(45,15);
	std::cin>>std::ws;
	std::cin.getline(nombre,100,'\n');
	rlutil::cls();
}



//PEDIR NOMBRE MULTIPLAYER
void pedirNombres(char nombre1[], char nombre2[]){
	rlutil::locate(43,14);
	std::cout<< "INGRESE NOMBRE PLAYER 1" << std::endl;
	rlutil::locate(43,15);
	std::cin>>std::ws;
	std::cin.getline(nombre1,100,'\n');


	rlutil::locate(43,16);
	std::cout<< "INGRESE NOMBRE PLAYER 2" << std::endl;
	rlutil::locate(43,17);
	std::cin>>std::ws;
	std::cin.getline(nombre2,100,'\n');
}


//MOSTRAR PUNTUACION MAXIMA 3
void puntuacionMaximaFinal_3(int& puntuacion_maxima_final, int& puntuacion_maxima, int& puntuacion_maxima_multiplayer, int acu_puntos_player1, int acu_puntos_player2, char nombre[], char nombre_player1[], char nombre_player2[], char nombre_final[]){

    if(puntuacion_maxima != -1 || puntuacion_maxima_multiplayer != -1){

        if(puntuacion_maxima > puntuacion_maxima_multiplayer && puntuacion_maxima > puntuacion_maxima_final){

            puntuacion_maxima_final = puntuacion_maxima;

            strcpy(nombre_final, nombre);
        }

        else if(puntuacion_maxima_multiplayer > puntuacion_maxima && puntuacion_maxima_multiplayer > puntuacion_maxima_final){

            puntuacion_maxima_final = puntuacion_maxima_multiplayer;

            if(puntuacion_maxima_multiplayer == acu_puntos_player1){
                strcpy(nombre_final, nombre_player1);
            }
            else if(puntuacion_maxima_multiplayer == acu_puntos_player2){
                 strcpy(nombre_final, nombre_player2);
            }
        }
    }
    else{
        rlutil::locate(28,13);
        std::cout << "AUN NO SE INICIO NINGUNA PARTIDA PARA DETERMINAR EL PUNTAJE MAXIMO" << std::endl;

        rlutil::locate(37,17);
        std::cout<< "PRESIONE CUALQUIER TECLA PARA VOLVER AL MENU." << std::endl;

        rlutil::anykey();
        rlutil::cls();
    }

}//FIN FUNCION



void mostrarPuntuacionFinal(int puntuacion_maxima_final, char nombre_final[]){
    if(puntuacion_maxima_final != -1){

        rlutil::cls();

        rlutil::locate(43,15);
        std::cout <<  "PUNTUACION MAXIMA: " << puntuacion_maxima_final << std::endl;

        rlutil::locate(43,16);
        std::cout <<  "NOMBRE: " << nombre_final << std::endl;

        rlutil::anykey();
        rlutil::cls();
    }
}



void reglas(){

	rlutil::cls();

	std::cout<< "--------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "" << std::endl;
	rlutil::setColor(rlutil::YELLOW);
	std::cout << "OBJETIVO: LLEGAR A LOS 500 PUNTOS O SACAR UNA ESCALERA" << std::endl;
	rlutil::setColor(rlutil::WHITE);

	std::cout << "" << std::endl;

	std::cout<< "--------------------------------------------------------------------------------------------" << std::endl;

	std::cout << "" << std::endl;

	rlutil::setColor(rlutil::YELLOW);
	std::cout << "COMBINACIONES DE DADOS PARA OBTENER PUNTAJE" << std::endl;
	rlutil::setColor(rlutil::WHITE);
	std::cout << "" << std::endl;

	std::cout<< "--------------------------------------------------------------------------------------------" << std::endl;

	std::cout << "" << std::endl;
	rlutil::setColor(rlutil::GREEN);
	std::cout << "SUMA DE DADOS" << std::endl;
	rlutil::setColor(rlutil::WHITE);
	std::cout << "MENOS DE 3 DADOS CON VALORES IGUALES (CUALQUIER COMBINACION)" << std::endl;
	std::cout << "PUNTAJE OTORGADO: SUMA DE LOS VALORES DE TODOS LOS DADOS" << std::endl;
	std::cout << "EJEMPLO: 6,5,5,2,2,1 = 21" << std::endl;

	std::cout << "" << std::endl;

	rlutil::setColor(rlutil::GREEN);
	std::cout << "TRIO X++ (X CORRESPONDE AL NUMERO DEL DADO)" << std::endl;
	rlutil::setColor(rlutil::WHITE);
	std::cout << "TRES DADOS O MAS CON EL MISMO VALOR (HASTA 5 DADOS)" << std::endl;
	std::cout << "PUNTAJE OTORGADO: X*10 PUNTOS" << std::endl;
	std::cout << "EJEMPLO: 5,5,5,1,2,3 = 50 PUNTOS" << std::endl;

	std::cout << "" << std::endl;

	rlutil::setColor(rlutil::GREEN);
	std::cout << "SEXTETO X (X CORRESPONDE AL NUMERO DEL DADO)" << std::endl;
	rlutil::setColor(rlutil::WHITE);
	std::cout << "6 DADOS IGUAL (EXCEPTO EL DADO NUMERO SEIS)" << std::endl;
	std::cout << "PUNTAJE OTORGADO: X*50 PUNTOS" << std::endl;
	std::cout << "EJEMPLO: 3,3,3,3,3,3 = 150 PUNTOS" << std::endl;

	std::cout << "" << std::endl;

	rlutil::setColor(rlutil::GREEN);
	std::cout << "SEXTETO DE SEIS" << std::endl;
	rlutil::setColor(rlutil::WHITE);
	std::cout << "SEIS DADOS IGUALES DE NUMERO SEIS" << std::endl;
	std::cout << "PUNTAJE OTORGADO: PIERDE TODOS LOS PUNTOS DE ESA RONDA" << std::endl;
	std::cout << "EJEMPLO: 6,6,6,6,6,6 = 0 PUNTOS" << std::endl;

	std::cout << "" << std::endl;

	rlutil::setColor(rlutil::GREEN);
	std::cout << "ESCALERA" << std::endl;
	rlutil::setColor(rlutil::WHITE);
	std::cout << "SEIS DADOS CONSECUTIVOS EN ORDEN CRECIENTE" << std::endl;
	std::cout << "PUNTAJE OTORGADO: GANA LA PARTIDA EN ESA RONDA" << std::endl;
	std::cout << "EJEMPLO: 1,2,3,4,5,6" << std::endl;

	std::cout<< "" << std::endl;

	rlutil::setColor(rlutil::GREEN);
	std::cout<< "PRESIONE CUALQUIER TECLA PARA VOLVER AL MENU." << std::endl;
	rlutil::setColor(rlutil::WHITE);

	rlutil::anykey();
	rlutil::cls();
}

