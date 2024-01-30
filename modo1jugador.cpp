#include <iostream>
#include "rlutil.h"
#include "funcion_main.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>


//MODO UN JUGADOR
void singlePlayer(int& puntuacion_maxima, char nombre[], int& puntos, int& lanzamientos, int& ronda, int& max_ronda, bool& salir, int& acu_puntos, bool& flag_sexteto_seis, int& d1, int& d2, int& d3, int& d4, int& d5, int& d6){

    pedirNombre(nombre);
    acu_puntos = 0;
    puntos = 0;
    ronda = 0;
    salir = false;

    rlutil::cls();

    while(acu_puntos<500 && salir == false){

        flag_sexteto_seis = false;
        lanzamientos = 0;
        max_ronda = 0;

        //INTERFASE RONDA INCIO RONDA

        rlutil::locate(30,10);
        std::cout<< "--------------------------------------------------------- " << std::endl;

        for(int g = 1; g<=7; g++){
            rlutil::locate(30,10+g);
            std::cout<< "-" << std::endl;
        }

        for(int h = 1; h<=7; h++){
            rlutil::locate(86,10+h);
            std::cout<< "-" << std::endl;
        }

        rlutil::locate(56,12);
        std::cout<< "RONDA " << ronda+1 << std::endl;

        rlutil::locate(52,14);
        std::cout<< "JUGADOR: " << nombre << std::endl;

        rlutil::locate(50,16);
        std::cout<< "PUNTAJE: "  << acu_puntos << " PUNTOS" << std::endl;

        rlutil::locate(30,18);
        std::cout<< "--------------------------------------------------------- " << std::endl;

        rlutil::locate(30,22);
        rlutil::setColor(rlutil::GREEN);
        std::cout<< "PRESIONE CUALQUIER TECLA PARA COMENZAR A LANZAR LOS DADOS " << std::endl;
        rlutil::setColor(rlutil::WHITE);

        rlutil::anykey();
        rlutil::cls();

        //INICION RONDA
        while (lanzamientos < 3){

        dados_x6(d1,d2,d3,d4,d5,d6);

        //EVITAR QUE SE DESPINTEN LOS DADOS Y LA PANTALLA
        rlutil::setBackgroundColor(rlutil::BLACK);
        rlutil::setColor(rlutil::WHITE);

        /////INGRESAR MANUALMENTE EL VALOR DE CADA DADO//////
        //ingresarDadosManualmente(d1,d2,d3,d4,d5,d6);

        if(combinacion_tres(d1,d2,d3,d4,d5,d6)){
            puntos = combinacion_tres(d1,d2,d3,d4,d5,d6);
        }

        else if(sexteto(d1,d2,d3,d4,d5,d6)){
            puntos = sexteto(d1,d2,d3,d4,d5,d6);
        }

        else if(sexteto_seis(d1,d2,d3,d4,d5,d6) == true){
            puntos = 0;
            flag_sexteto_seis = true;
        }

        else if(escalera(d1,d2,d3,d4,d5,d6) == true){
            rlutil::locate(1,14);
            std::cout << "¡ESCALERA!" << std::endl;
            rlutil::locate(1,16);
            std::cout<< "PRESIONE CUALQUIER TECLA PARA CONTINUAR... " << std::endl;
            rlutil::anykey();

            rlutil::cls();
            rlutil::locate(38,10);
            std::cout << "¡FELICIDADES! ¡GANASTE LA PARTIDA!" << std::endl;
            std::cout << "" << std::endl;
            salir = true;
            break;
        }
        else{
            puntos = d1+d2+d3+d4+d5+d6;
        }

        ////////////PUNTAJE MAXIMO DE CADA RONDA///////////

        if(max_ronda == 0 || puntos > max_ronda){
            max_ronda = puntos;
        }

        //////////CONTADOR LANZAMIENTOS//////////
        lanzamientos++;

        //// MOSTRAR DATOS DURANTE LA RONDA, NOMBRE, TURNO, LANZAMIENTO, PUNTAJE, MAX RONDA, PUNTAJE TOTAL ////
        rlutil::locate(1,1);
        std::cout<< "TURNO DE: " << nombre << std::endl;

        rlutil::locate(20,1);
        std::cout<< "RONDA NUMERO: " << ronda+1 << std::endl;

        rlutil::locate(40,1);
        std::cout<< "PUNTAJE ACUMULADO: " << acu_puntos << " PUNTOS" << std::endl;

        std::cout<< "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
        std::cout<< "-" << std::endl;

        rlutil::locate(1,4);
        std::cout<< "PUNTAJE MAXIMO DE LA RONDA: " << max_ronda << std::endl;

        rlutil::locate(1,5);
        std::cout<< "PUNTAJE DE LA TIRADA: " << puntos << std::endl;

        rlutil::locate(1,6);
        std::cout<< "LANZAMIENTO NUMERO: " << lanzamientos << std::endl;

        rlutil::locate(1,16);
        std::cout<< "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

        rlutil::locate(1,17);
        std::cout<< "-" << std::endl;

        rlutil::locate(1,19);
        rlutil::setColor(rlutil::GREEN);
        std::cout<< "PRESIONE CUALQUIER TECLA PARA CONTINUAR CON LOS LANZAMIENTOS... " << std::endl;
        rlutil::setColor(rlutil::WHITE);

        rlutil::anykey();
        rlutil::cls();

        }//FIN WHILE SINGLE PLAYER

    //FIN DE LA RONDA - ACUMULACION Y CALCULO DE PUNTAJE
        if(flag_sexteto_seis == true){
            max_ronda = 0;
        }

        acu_puntos = acu_puntos+max_ronda;

        ronda++;


    }//FIN WHILE

    //PUNTAJE MAXIMO
    if(puntuacion_maxima == -1 || acu_puntos > puntuacion_maxima){
        puntuacion_maxima = acu_puntos;
    }

    //MOSTRAR GANADOR SINGLEPLAYER
    //mostrarGanadorSingleplayer(acu_puntos, nombre);
    rlutil::locate(38,12);
	std::cout<< "PUNTAJE ACUMULADO: " << acu_puntos << std::endl;

	rlutil::locate(38,14);
	std::cout<< "GANADOR: " << nombre << std::endl;

	rlutil::locate(38,16);
	std::cout<< "FIN DEL JUEGO" << std::endl;

	rlutil::locate(38,18);
	std::cout<< "PRESIONE CUALQUIER TECLA PARA VOLVER AL MENU." << std::endl;


    rlutil::anykey();
    rlutil::cls();

}//FIN FUNCION


