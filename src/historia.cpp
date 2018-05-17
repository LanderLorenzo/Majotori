/*
 * historia.cpp
 *
 *  Created on: 17 may. 2018
 *      Author: Lander
 */

#include "historia.h"
#include <string.h>
#include <fstream>
#include <cstdlib>

#include <iostream>
using namespace std;

historia::historia(){
	this->texto = new char[1];
	this->texto[0] = '\0';
}

historia::~historia(){
	delete[] this->texto;
}

historia::historia(char* texto){
	this->texto = new char[strlen(texto) + 1];
	strcpy(this->texto, texto);
}

historia::historia(const historia& h){
	this->texto = new char[strlen(h.texto) + 1];
	strcpy(this->texto, h.texto);

}

void historia::setTexto(char* fichero){
	delete[] this->texto;
	ifstream f;
	f.open(fichero);

	string linea;
	int max;
	int contador = 0;

	while(getline(f, linea)){

		if(max == contador){
			this->texto = linea;
		}

		contador++;
	}


	f.close();
}

char* historia::getTexto(){
	return this->texto;
}

void historia::mostrarTexto(){
	cout << "TEXTO: " << endl;
	cout << endl;
	cout << this->texto << endl;
}

historiaRamificada::historiaRamificada(){
	for(int i = 0; i < 10; i++){
		this->respuestas[i] = false;
	}
}

historiaRamificada::~historiaRamificada(){
	delete[] this->respuestas;


}

historiaRamificada::historiaRamificada(bool respuestas[], char* texto):historia(texto){
	for(int i = 0; i < 10; i++){
		this->respuestas[i] = respuestas;
	}


}

historiaRamificada::historiaRamificada(historiaRamificada& h){
	for(int i = 0; i < 10; i++){
		this->respuestas[i] = h.respuestas;
	}

}

bool historiaRamificada::tombola(){
	int r = rand()% 10 + 1;
	bool resultado;
	if(this->respuestas[r] == true){
		resultado = true;
	} else{
		resultado = false;
	}

	return resultado;
}

void historiaRamificada::setRespuestas(bool respuestas[]){
	for(int i = 0; i < 10; i++){
		this->respuestas[i] = respuestas;
	}

}
bool* historiaRamificada::getRespuestas(){
	return this->respuestas;
}
