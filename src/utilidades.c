/*
 * utilidades.c
 *
 *  Created on: 7 abr. 2018
 *      Author: Lander
 */
#include "utilidades.h"
#include <stdio.h>
#include <stdlib.h>
int contarLineas(char* nombreF) {

	FILE *f;
	int cuenta = 0;
	char c;

	f = fopen(nombreF, "r");

	while (c != EOF) {
		c = fgetc(f);
		if (c == '\n') {
			cuenta = cuenta + 1;
		}
	}

	fclose(f);

	return cuenta;

}

void iniciarTemas(Tema* array, char* nombreF, int tamanyoCod, int tamanyoNombre, int longitud){
	FILE *f;
	f = fopen(nombreF, "r");

	int j = 0;
	int i = 0;
	while(i < longitud){
		while(j < tamanyoCod){
			array[i].cod[j] = fgetc(f);
			j++;
		}
		j = 0;
		array[i].actT = fgetc(f);
		while(j < tamanyoNombre){
			char a = fgetc(f);
			if (a == '\n'){
				j = tamanyoNombre;
			}else{
			array[i].nombre[j] = a;
			}
			j++;
		}
		j = 0;
		i++;
	}

	fclose(f);
}

void iniciarPreguntas(Pregunta* array, char* nombreF, int tamanyoCod, int tamanyoEnunciado, int longPregunta1, int longPregunta2, int longPregunta3, int longPregunta4, int longitud){
	FILE *f;
	f = fopen(nombreF, "r");

	int j = 0;
	int i = 0;
	//i = longitud del array
	while(i < longitud){
		//j = longitud del codigo
		while(j < tamanyoCod){
			array[i].cod[j] = fgetc(f);
			j++;
		}
		j = 0;
		//j = longitud del enunciado
		while(j < tamanyoEnunciado){
			char a = fgetc(f);
			if (a == '\n'|| a == '&'){
				j = tamanyoEnunciado;
			}else{
			array[i].enunciado[j] = a;
			}
			j++;
		}
		j = 0;

		//j = longitud de la pregunta1
		while(j < longPregunta1){
			char a = fgetc(f);
			if (a == '\n'|| a == '&'){
				j = longPregunta1;
			}else{
			array[i].respuestaA[j] = a;
			}
			j++;
		}
		j = 0;
		//j = longitud de la pregunta2
		while(j < longPregunta2){
			char a = fgetc(f);
			if (a == '\n'|| a == '&'){
				j = longPregunta2;
			}else{
			array[i].respuestaB[j] = a;
			}
			j++;
		}
		j = 0;
		//j = longitud de la pregunta3
		while(j < longPregunta3){
			char a = fgetc(f);
			if (a == '\n'|| a == '&'){
				j = longPregunta3;
			}else{
			array[i].respuestaC[j] = a;
			}
			j++;
		}
		j = 0;
		//j = longitud de la pregunta4
		while(j < longPregunta4){
			char a = fgetc(f);
			if (a == '\n'|| a == '&'){
				j = longPregunta4;
			}else{
			array[i].respuestaD[j] = a;
			}
			j++;
		}

		array[i].correcta = fgetc(f);

		i++;
	}

	fclose(f);
}
