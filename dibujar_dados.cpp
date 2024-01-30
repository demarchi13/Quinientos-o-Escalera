#include<iostream>
#include <string>
#include "rlutil.h"
#include "funcion_main.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>


void dibujarCuadrado(int posx, int posy) {
	rlutil::setColor(rlutil::WHITE);
	for(int x=0; x<7; x++){
		for(int y=0; y<3; y++){
			rlutil::locate(x+posx,y+posy);
			std::cout << (char)219 << std::endl;
		}
	}
}

void dibujarDado(int numero, int posx, int posy){
	dibujarCuadrado(posx, posy);
	dibujarPuntos(numero, posx, posy);
}

void dibujarPuntos(int numero, int posx, int posy){

	rlutil::setColor(rlutil::BLACK);
	rlutil::setBackgroundColor(rlutil::WHITE);

	switch(numero){
	case 1:
		rlutil::locate(posx+3, posy+1);
		std::cout << (char)254;
		break;
	case 2:
		rlutil::locate(posx+5, posy);
		std::cout << (char)220;

		rlutil::locate(posx+1, posy+2);
		std::cout << (char)223;
		break;
	case 3:
		rlutil::locate(posx+5, posy);
		std::cout << (char)220;

		rlutil::locate(posx+1, posy+2);
		std::cout << (char)223;

		rlutil::locate(posx+3, posy+1);
		std::cout << (char)254;
		break;
	case 4:
		rlutil::locate(posx+1, posy);
		std::cout << (char)220;

		rlutil::locate(posx+5, posy);
		std::cout << (char)220;

		rlutil::locate(posx+1, posy+2);
		std::cout << (char)223;

		rlutil::locate(posx+5, posy+2);
		std::cout << (char)223;
		break;
	case 5:
		rlutil::locate(posx+1, posy);
		std::cout << (char)220;

		rlutil::locate(posx+5, posy);
		std::cout << (char)220;

		rlutil::locate(posx+1, posy+2);
		std::cout << (char)223;

		rlutil::locate(posx+5, posy+2);
		std::cout << (char)223;

		rlutil::locate(posx+3, posy+1);
		std::cout << (char)254;
		break;
	case 6:
		rlutil::locate(posx+1, posy);
		std::cout << (char)220;

		rlutil::locate(posx+5, posy);
		std::cout << (char)220;

		rlutil::locate(posx+3, posy);
		std::cout << (char)220;

		rlutil::locate(posx+1, posy+2);
		std::cout << (char)223;

		rlutil::locate(posx+5, posy+2);
		std::cout << (char)223;

		rlutil::locate(posx+3, posy+2);
		std::cout << (char)223;
		break;
	}//FIN SWITCH
}
