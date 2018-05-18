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

historia::historia(char* fichero){


	this->texto = new char[1000]; //Se puede calcular tamaño arriba
	ifstream f;
	char paquete[100];
	strcpy(paquete, "Historias/");
	strcat(paquete, fichero);
	f.open(paquete);
	char text[1000];
	//while(!f.eof()){
		f >> text;
		strcpy(this->texto, text);
	//}

	strcat(this->texto, "\0");
	f.close();
}

historia::historia(const historia& h){
	this->texto = new char[strlen(h.texto) + 1];
	strcpy(this->texto, h.texto);

}

void historia::setTexto(char* fichero){
	delete[] this->texto;
	ifstream f;
	f.open(fichero);

	char text[1000];

	while(!f.eof()){
		f >> text;
		strcat(this->texto, text);
	}
	strcat(this->texto, "\0");
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


}

historiaRamificada::historiaRamificada(bool respuestas[], char* fichero):historia(fichero){
	for(int i = 0; i < 10; i++){
		this->respuestas[i] = respuestas[i];
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
