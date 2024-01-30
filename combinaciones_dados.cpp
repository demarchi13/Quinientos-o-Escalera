#include<iostream>
#include "rlutil.h"
#include "funcion_main.h"
#include <ctime>
#include <cstdlib>
#include <algorithm>




// //////////////DADOS RANDOM//////////////////////
void dados_x6(int& dado1, int& dado2, int& dado3, int& dado4, int& dado5, int& dado6){

	dado1 = rand() % 6 + 1;
	dibujarDado(dado1,1,10);

	dado2 = rand() % 6 + 1;
	dibujarDado(dado2,10,10);

	dado3 = rand() % 6 + 1;
	dibujarDado(dado3,20,10);

	dado4 = rand() % 6 + 1;
	dibujarDado(dado4,30,10);

	dado5 = rand() % 6 + 1;
	dibujarDado(dado5,40,10);

	dado6 = rand() % 6 + 1;
	dibujarDado(dado6,50,10);
}


/////////////COMBINACION DE 3 O 5 DADOS /////////////////
int combinacion_tres(int d1, int d2, int d3, int d4, int d5, int d6){

	int dadoX = 0;
	int resultado = 0;

	int repeticiones = 0;
	int maxRepeticiones = 0;
	int maxPuntaje= 0;

	for (int x = 1; x <= 6; x++) {

		repeticiones = 0;


		if (d1 == x) repeticiones++;
		if (d2 == x) repeticiones++;
		if (d3 == x) repeticiones++;
		if (d4 == x) repeticiones++;
		if (d5 == x) repeticiones++;
		if (d6 == x) repeticiones++;

		if (repeticiones >= 3 && repeticiones <=5) {
			if(repeticiones > maxRepeticiones || (repeticiones == maxRepeticiones && x > dadoX)){
				dadoX = x;
				maxRepeticiones = repeticiones;
				maxPuntaje = dadoX*10;
			}
		}
	}
	resultado = maxPuntaje;
	return resultado;
}


////////////////////////SEXTETO X/////////////////////////////
int sexteto(int d1, int d2, int d3, int d4,int d5, int d6){

	int resultado_sexteto;

	if(d1==d2 && d2==d3 && d3==d4 && d4==d5 && d5==d6){
		if(d1 != 6){
			resultado_sexteto = d1*50;
		}
	}

	return resultado_sexteto;
}



/////////////////////// SEXTETO DE SEIS ////////////////////////
bool sexteto_seis(int d1, int d2, int d3, int d4,int d5, int d6){

	bool flag_sexteto_seis = false;

	if(d1==6 && d2==6 && d3==6 && d4==6 && d5==6 && d6==6){
		flag_sexteto_seis = true;
	}

	return flag_sexteto_seis;
}



////////////////////////// ESCALERA /////////////////////////////
bool escalera(int d1, int d2, int d3, int d4, int d5, int d6) {

	int dados[6] = {d1, d2, d3, d4, d5, d6};

	std::sort(dados, dados + 6);

	for (int i = 0; i < 5; i++) {
		if (dados[i] + 1 != dados[i + 1])
			return false;
	}

	return true;
}


///// INGRESAR DADOS MANUALMENTE ////////////
void ingresarDadosManualmente(int& d1, int& d2, int& d3, int& d4, int& d5, int& d6){

	rlutil::locate(1,10);
	std::cin >> d1;
	rlutil::locate(20,10);
	std::cin >> d2;
	rlutil::locate(40,10);
	std::cin >> d3;
	rlutil::locate(1,11);
	std::cin >> d4;
	rlutil::locate(20,11);
	std::cin >> d5;
	rlutil::locate(40,11);
	std::cin >> d6;

}
