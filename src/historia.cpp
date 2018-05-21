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


	ifstream f;
	char paquete[100];
	strcpy(paquete, "Historias/");
	strcat(paquete, fichero);
	f.open(paquete);
	char text[1000];
	int i = 0;
	int tamanyo = 0;

	while(!f.eof()){
		f >> text[i];
		if(text[i] == '_'){
			text[i] = ' ';
		}
		if(text[i] == '/'){
			text[i] = '\0';
		}
		if(text[i] == '.'){
			i++;
			tamanyo++;
			text[i] = '\n';
		}		i++;
		tamanyo++;
	}

		this->texto = new char[tamanyo];
		strcpy(this->texto, text);


	f.close();
}

historia::historia(const historia& h){
	this->texto = new char[strlen(h.texto) + 1];
	strcpy(this->texto, h.texto);

}

void historia::setTexto(char* fichero){
	delete[] this->texto;
		ifstream f;
		char paquete[100];
		strcpy(paquete, "Historias/");
		strcat(paquete, fichero);
		f.open(paquete);
		char text[1000];
		int i = 0;
		int tamanyo = 0;

		while(!f.eof()){
			f >> text[i];
			if(text[i] == '_'){
				text[i] = ' ';
			}
			if(text[i] == '/'){
				text[i] = '\0';
			}
			if(text[i] == '.'){
				i++;
				tamanyo++;
				text[i] = '\n';
			}		i++;
			tamanyo++;
		}

			this->texto = new char[tamanyo];
			strcpy(this->texto, text);


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


historiaRecorrida::~historiaRecorrida(){
	delete[] this->respuestas;
}

historiaRecorrida::historiaRecorrida(bool* respuestas, char* fichero):historia(fichero),respuestas(respuestas){}

historiaRecorrida::historiaRecorrida(historiaRecorrida& h){
	this->texto = h.texto;
	this->respuestas = h.respuestas;
}

bool historiaRecorrida::tombola(){
	int r = rand()% 10;

	return respuestas[r];
}

void historiaRecorrida::setRespuestas(bool respuestas[10]){
	for(int i = 0; i < 10; i++){
		this->respuestas[i] = respuestas[i];
	}

}
bool* historiaRecorrida::getRespuestas(){
	return this->respuestas;
}

