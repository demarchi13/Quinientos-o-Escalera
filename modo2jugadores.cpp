#include <iostream>
#include "rlutil.h"
#include "funcion_main.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>


//MODO 2 JUGADORES
void modoMultiplayer(int& puntuacion_maxima_multiplayer, char nombre_player1[], char nombre_player2[], int& puntos_player1, int& puntos_player2, int& lanzamientosPlayer1, int& lanzamientosPlayer2, int& max_rondap1, int& max_rondap2, int& ronda_player1, int& ronda_player2, int& acu_puntos_player1, int& acu_puntos_player2, bool& flag_sexteto_seis_p1, bool& flag_sexteto_seis_p2, bool& salir_player1, bool& salir_player2, bool& flag_ganador_player1, bool& flag_ganador_player2, int& d1, int& d2, int& d3, int& d4, int& d5, int& d6){

    acu_puntos_player1 = 0;
    puntos_player1 = 0;
    acu_puntos_player2 = 0;
    puntos_player2 = 0;
    ronda_player1 = 0;
    ronda_player2 = 0;
    flag_ganador_player1 = false;
    flag_ganador_player2 = false;
    salir_player1 = false;
    salir_player2 = false;
    pedirNombres(nombre_player1, nombre_player2);

    rlutil::cls();

    while((acu_puntos_player1<500 && salir_player1 == false) && (acu_puntos_player2 <500 && salir_player2 == false)){

        flag_sexteto_seis_p1 = false;
        flag_sexteto_seis_p2 = false;
        lanzamientosPlayer1 = 0;
        lanzamientosPlayer2 = 0;
        max_rondap1 = 0;
        max_rondap2 = 0;

        //SI TODO ESCALERA
        if(salir_player2 == true){
            break;
        }

        //INTERFACE INICIO RONDA PLAYER 1 - RONDA, PROXIMO TURNO, NOMBREP1, NOMBRE P2
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

        rlutil::locate(55,12);
        std::cout<< "RONDA " << ronda_player1+1 << std::endl;

        rlutil::locate(47,13);
        std::cout<< "PROXIMO TURNO: " << nombre_player1 << std::endl;

        rlutil::locate(44,15);
        std::cout<< "PUNTAJE " << nombre_player1 << ": "<< acu_puntos_player1 << " PUNTOS" << std::endl;

        rlutil::locate(44,16);
        std::cout<< "PUNTAJE " << nombre_player2 << ": "<< acu_puntos_player2 << " PUNTOS" << std::endl;

        rlutil::locate(30,18);
        std::cout<< "--------------------------------------------------------- " << std::endl;

        rlutil::setColor(rlutil::GREEN);
        rlutil::locate(30,22);
        std::cout<< "PRESIONE CUALQUIER TECLA PARA COMENZAR A LANZAR LOS DADOS " << std::endl;
        rlutil::setColor(rlutil::WHITE);

        rlutil::anykey();
        rlutil::cls();

        /** INICIO RONDA PLAYER 1 */
        while(lanzamientosPlayer1<3){

            dados_x6(d1,d2,d3,d4,d5,d6);

            //EVITAR QUE SE DESPINTEN LOS DADOS Y LA PANTALLA
            rlutil::setBackgroundColor(rlutil::BLACK);
            rlutil::setColor(rlutil::WHITE);

            //INGRESAR MANUALMENTE EL VALOR DE CADA DADO
            //ingresarDadosManualmente(d1,d2,d3,d4,d5,d6);

            if(combinacion_tres(d1,d2,d3,d4,d5,d6)){
                puntos_player1 = combinacion_tres(d1,d2,d3,d4,d5,d6);
            }
            else if(sexteto(d1,d2,d3,d4,d5,d6)){
                puntos_player1 = sexteto(d1,d2,d3,d4,d5,d6);
            }
            else if(sexteto_seis(d1,d2,d3,d4,d5,d6) == true){
                puntos_player1 = 0;
                flag_sexteto_seis_p1 = true;
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
                salir_player1 = true;
                flag_ganador_player1 = true;
                break;
            }
            else{
                puntos_player1 = d1+d2+d3+d4+d5+d6;
            }

            //PUNTAJE MAXIMO DE LA RONDA PLAYER 1
            if(max_rondap1 == 0 || puntos_player1 > max_rondap1){
                max_rondap1 = puntos_player1;
            }

            //CONTADOR LANZAMIENTOS
            lanzamientosPlayer1++;

            //MOSTRAR DATOS DURANTE LA RONDA PLAYER 1 - NOMBRE TURNO, NºRONDA, PUNTAJE TOTAL, MAX RONDA, PUNTAJE TIRADA, LANZAMIENTO
            rlutil::locate(1,1);
            std::cout<< "TURNO DE: " << nombre_player1 << std::endl;

            rlutil::locate(20,1);
            std::cout<< "RONDA NUMERO: " << ronda_player1+1 << std::endl;

            rlutil::locate(40,1);
            std::cout<< "PUNTAJE ACUMULADO: " << acu_puntos_player1 << " PUNTOS" << std::endl;

            std::cout<< "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout<< "-" << std::endl;

            rlutil::locate(1,4);
            std::cout<< "PUNTAJE MAXIMO DE LA RONDA: " << max_rondap1 << std::endl;

            rlutil::locate(1,5);
            std::cout<< "PUNTAJE DE LA TIRADA: " << puntos_player1 << std::endl;

            rlutil::locate(1,6);
            std::cout<< "LANZAMIENTO NUMERO: " << lanzamientosPlayer1 << std::endl;

            rlutil::locate(1,16);
            std::cout<< "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

            rlutil::locate(1,17);
            std::cout<< "-" << std::endl;

            rlutil::locate(1,19);
            rlutil::setColor(rlutil::GREEN);
            std::cout<< "PRESIONE CUALQUIER TECLA PARA CONTINUAR CON LOS LANZAMIENTOS: " << std::endl;
            rlutil::setColor(rlutil::WHITE);


            rlutil::anykey();
            rlutil::cls();

            }//FIN WHILE RONDA PLAYER 1

        //ACUMULACION Y CALCULO DE PUNTAJE PLAYER 1
        if(flag_sexteto_seis_p1 == true){
            max_rondap1 = 0;
        }

        acu_puntos_player1 = acu_puntos_player1+max_rondap1;

        ronda_player1++;

        //SI TOCO ESCALERA
        if(salir_player1 == true){
            break;
        }

        //INTERFACE INICIO RONDA PLAYER 1 - RONDA, PROXIMO TURNO, NOMBREP1, NOMBRE P2
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

        rlutil::locate(55,12);
        std::cout<< "RONDA " << ronda_player2+1 << std::endl;

        rlutil::locate(47,13);
        std::cout<< "PROXIMO TURNO: " << nombre_player2 << std::endl;

        rlutil::locate(44,15);
        std::cout<< "PUNTAJE " << nombre_player1 << ": "<< acu_puntos_player1 << " PUNTOS" << std::endl;

        rlutil::locate(44,16);
        std::cout<< "PUNTAJE " << nombre_player2 << ": "<< acu_puntos_player2 << " PUNTOS" << std::endl;

        rlutil::locate(30,18);
        std::cout<< "--------------------------------------------------------- " << std::endl;

        rlutil::setColor(rlutil::GREEN);
        rlutil::locate(30,22);
        std::cout<< "PRESIONE CUALQUIER TECLA PARA COMENZAR A LANZAR LOS DADOS " << std::endl;
        rlutil::setColor(rlutil::WHITE);

        rlutil::anykey();
        rlutil::cls();

        /** INICIO RONDA PLAYER 2*/
        while(lanzamientosPlayer2<3){

            dados_x6(d1,d2,d3,d4,d5,d6);

            //EVITAR QUE SE DESPINTEN LOS DADOS Y LA PANTALLA
            rlutil::setBackgroundColor(rlutil::BLACK);
            rlutil::setColor(rlutil::WHITE);

            //INGRESAR MANUALMENTE EL VALOR DE CADA DADO
            //ingresarDadosManualmente(d1,d2,d3,d4,d5,d6);

            if(combinacion_tres(d1,d2,d3,d4,d5,d6)){
                puntos_player2 = combinacion_tres(d1,d2,d3,d4,d5,d6);
            }
            else if(sexteto(d1,d2,d3,d4,d5,d6)){
                puntos_player2 = sexteto(d1,d2,d3,d4,d5,d6);
            }
            else if(sexteto_seis(d1,d2,d3,d4,d5,d6) == true){
                puntos_player2 = 0;
                flag_sexteto_seis_p2 = true;
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
                salir_player2 = true;
                flag_ganador_player2 = true;
                break;
            }
            else{
                puntos_player2 = d1+d2+d3+d4+d5+d6;
            }

            ////////////PUNTAJE MAXIMO DE LA RONDA PLAYER 2///////////
            if(max_rondap2 == 0 || puntos_player2 > max_rondap2){
                max_rondap2 = puntos_player2;
            }

            //////////CONTADOR LANZAMIENTOS//////////
            lanzamientosPlayer2++;

            //MOSTRAR DATOS DURANTE LA RONDA PLAYER 2 - NOMBRE TURNO, NºRONDA, PUNTAJE TOTAL, MAX RONDA, PUNTAJE TIRADA, LANZAMIENTO//
            rlutil::locate(1,1);
            std::cout<< "TURNO DE: " << nombre_player2 << std::endl;

            rlutil::locate(20,1);
            std::cout<< "RONDA NUMERO: " << ronda_player2+1 << std::endl;

            rlutil::locate(40,1);
            std::cout<< "PUNTAJE ACUMULADO: " << acu_puntos_player2 << " PUNTOS" << std::endl;

            std::cout<< "-----------------------------------------------------------------------------------------------------------------------" << std::endl;
            std::cout<< "-" << std::endl;

            rlutil::locate(1,4);
            std::cout<< "PUNTAJE MAXIMO DE LA RONDA: " << max_rondap2 << std::endl;

            rlutil::locate(1,5);
            std::cout<< "PUNTAJE DE LA TIRADA: " << puntos_player2 << std::endl;

            rlutil::locate(1,6);
            std::cout<< "LANZAMIENTO NUMERO: " << lanzamientosPlayer2 << std::endl;

            rlutil::locate(1,16);
            std::cout<< "-----------------------------------------------------------------------------------------------------------------------" << std::endl;

            rlutil::locate(1,17);
            std::cout<< "-" << std::endl;

            rlutil::locate(1,19);
            rlutil::setColor(rlutil::GREEN);
            std::cout<< "PRESIONE CUALQUIER TECLA PARA CONTINUAR CON LOS LANZAMIENTOS: " << std::endl;
            rlutil::setColor(rlutil::WHITE);

            rlutil::anykey();
            rlutil::cls();

        }//FIN WHILE RONDA PLAYER 2

        //FIN DE LA RONDA PLAYER 2 - ACUMULACION Y CALCULO DE PUNTAJE
        if(flag_sexteto_seis_p2 == true){
            max_rondap2 = 0;
        }

        acu_puntos_player2 = acu_puntos_player2+max_rondap2;

        ronda_player2++;

    }//FIN JUEGO 2 JUGADORES


    /** CALCULO DE EMPATE O GANADOR DE LA PARTIDA */
	if(acu_puntos_player1 == acu_puntos_player2 && (salir_player1 == false && salir_player2 == false)){
		rlutil::locate(38,14);
		std::cout<< "¡EMPATE!" << std::endl;
	}
	else if(acu_puntos_player1 > acu_puntos_player2 && salir_player1 == false && salir_player2 == false){
	flag_ganador_player1 = true;
	}
	else if(acu_puntos_player2 > acu_puntos_player1 && salir_player1 == false && salir_player2 == false){
		flag_ganador_player2 = true;
	}


    /** CALCULAR PUNTAJE MAXIMO PARTIDA 2 JUGADORES */
    if(acu_puntos_player1 > acu_puntos_player2){
		puntuacion_maxima_multiplayer = acu_puntos_player1;
	}
	else{
		puntuacion_maxima_multiplayer = acu_puntos_player2;
	}

    //MOSTRAR NOMBRE DEL GANADOR
    if(flag_ganador_player1 == true){
		rlutil::locate(38,14);
		std::cout<< "PUNTAJE ACUMULADO: " << acu_puntos_player1 << std::endl;

		rlutil::locate(38,12);
		std::cout<< "GANADOR: " << nombre_player1 << std::endl;
	}
	else if(flag_ganador_player2 == true){
		rlutil::locate(38,14);
		std::cout<< "PUNTAJE ACUMULADO: " << acu_puntos_player2 <<std::endl;

		rlutil::locate(38,12);
		std::cout<< "GANADOR: " << nombre_player2 << std::endl;
	}

	rlutil::locate(38,16);
	std::cout<< "FIN DEL JUEGO" << std::endl;

	rlutil::locate(38,18);
	std::cout<< "PRESIONE CUALQUIER TECLA PARA VOLVER AL MENU." << std::endl;

	rlutil::anykey();
	rlutil::cls();

}//FIN FUNCION


