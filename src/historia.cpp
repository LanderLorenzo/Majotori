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



historial::~historial(){
	delete[] this->rama;
}

historial::historial(int ramas[2], char* fichero):historia(fichero){
	for(int i = 0; i < 2; i++){
		this->rama[i] = ramas[i];
	}

}
historial::historial(historial& h){
	for(int i = 0; i < 2; i++){
		this->rama[i] = h.rama[i];
	}
}

void historial::setRama(int set[2]){

	this->rama[0] = set[0];
	this->rama[1] = set[1];

}

int* historial::getRama(){

	return this->rama;
}

void historial::getRecorrido(char numeroHistoria){
	char* textoHistorial;
	int i = 0;
	int xrama = 0;
	ifstream f;
	int lenght = 0;
	textoHistorial = this->texto;

	while (i < sizeof(textoHistorial)){

		if (textoHistorial[i] == "|"){

			xrama++;

		}

	}

	textoHistorial = textoHistorial + "|";

	if (xrama = 0){

		//función que coja el texto de la historiax y la escriba en textoHistorial

		f.open("Historias/Historia" + numeroHistoria);
		i=0;

		while(!f.eof()){
			f >> textoHistorial[i];
			if(textoHistorial[i] == '_'){
				textoHistorial[i] = ' ';
			}
			if(textoHistorial[i] == '/'){
				textoHistorial[i] = '\0';
			}
			if(textoHistorial[i] == '.'){
				i++;
				lenght++;
				textoHistorial[i] = '\n';
			}		i++;
			lenght++;
		}

		this->textoHistorial = new char[lenght];
		this->texto = {};
		strcat(this->textoHistorial, textoHistorial);

		//guardar este textHistorial al fondo del fichero que vayamos a usar como historial?

		f.close();

	}else if (xrama = 1){

		//función que coja el texto de la historiaxramax y la escriba en el final de textoHistorial

		f.open("Historias/Historia" + numeroHistoria + "Rama" + this->rama[0]);

		i=0;

		while(!f.eof()){
			f >> textoHistorial[i];
			if(textoHistorial[i] == '_'){
				textoHistorial[i] = ' ';
			}
			if(textoHistorial[i] == '/'){
				textoHistorial[i] = '\0';
			}
			if(textoHistorial[i] == '.'){
				i++;
				lenght++;
				textoHistorial[i] = '\n';
			}		i++;
			lenght++;
		}

		this->textoHistorial = new char[lenght];
		strcat(this->textoHistorial, textoHistorial);

		//guardar este textoHistorial al fondo del fichero que vayamos a usar como historial?

		f.close();

	}else if (xrama = 2){

		//función que coja el texto de la historiaxramaxfinalx y la escriba en el final de textoHistorial

		f.open("Historias/Historia" + numeroHistoria + "Rama" + this->rama[0] + "Final" + this->rama[1]);

		i=0;

		while(!f.eof()){
			f >> textoHistorial[i];
			if(textoHistorial[i] == '_'){
				textoHistorial[i] = ' ';
			}
			if(textoHistorial[i] == '/'){
				textoHistorial[i] = '\0';
			}
			if(textoHistorial[i] == '.'){
				i++;
				lenght++;
				textoHistorial[i] = '\n';
			}		i++;
			lenght++;
		}

		this->textoHistorial = new char[lenght];
		strcat(this->textoHistorial, textoHistorial);

		//guardar este texto al fondo del fichero que vayamos a usar para el historial?

		f.close();


	}else{

		//con 3 ramas ya habría acabado la historia, así que borramos el fichero y escribimos en blanco
		//igual que con xrama = 0

		f.open("Historias/Historia" + numeroHistoria);

		i=0;

		while(!f.eof()){
			f >> textoHistorial[i];
			if(textoHistorial[i] == '_'){
				textoHistorial[i] = ' ';
			}
			if(textoHistorial[i] == '/'){
				textoHistorial[i] = '\0';
			}
			if(textoHistorial[i] == '.'){
				i++;
				lenght++;
				textoHistorial[i] = '\n';
			}		i++;
			lenght++;
		}

		this->textoHistorial = new char[lenght];
		//this.textoHistorial = {}; ¿vacia el array?
		this->textoHistorial = {};
		strcat(this->textoHistorial, textoHistorial);

		f.close();

		//guardar este texto al principio del fichero que acabamos de vaciar

	}

}


