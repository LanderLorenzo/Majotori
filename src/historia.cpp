/*
 * historia.cpp
 *
 *  Created on: 17 may. 2018
 *      Author: Lander
 */

#include "historia.h"
#include "string.h"

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

void historia::setTexto(char* texto){
	delete[] this->texto;
	this->texto = new char[strlen(texto) + 1];
	strcpy(this->texto, texto);

}

char* historia::getTexto(){
	return this->texto;
}

void historia::mostrarTexto(char*){
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

historiaRamificada::historiaRamificada(bool respuestas[]){
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

}

void historiaRamificada::setRespuestas(bool respuestas[]){
	for(int i = 0; i < 10; i++){
		this->respuestas[i] = respuestas;
	}

}
bool* historiaRamificada::getRespuestas(){
	return this->respuestas;
}
