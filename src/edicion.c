/*
 * edicion.c
 *
 *  Created on: 16 abr. 2018
 *      Author: Lander
 */
#include "edicion.h"
#include "utilidades.h"
#include <stdio.h>
#include <stdlib.h>

void crearTema(char* temaN){

	char* ficheroAct = "tema.txt";
	FILE* f;

	f = fopen(ficheroAct, "a");
		int tamanyo = contarLineas(ficheroAct);

		if(tamanyo < 10){
			fprintf(f,"0%i0%s\n", tamanyo+1, temaN);
		}else{
			fprintf(f,"%i0%s\n", tamanyo+1, temaN);
		}

	fclose(f);

}

void borrarTema(int eleccion, Tema *temas){


	char* ficheroAct = "tema.txt";
	FILE* f;

	f = fopen(ficheroAct, "w");
		int tamanyo = contarLineas(ficheroAct);
		int i = 0;
		for(i = 0; i < tamanyo; i++){
			if(i != eleccion){
				fprintf(f,"%s%c%s\n",temas[i].cod, temas[i].actT, temas[i].nombre);
				printf("%i", i);
			}else{
				tamanyo--;
				i--;
			}
		}

	fclose(f);

}

// Este m�todo ser�a solo para crear el c�digo �nico de la pregunta
void crearPregunta(){

	char* ficheroAct = "pregunta.txt";
	FILE* f;

	f = fopen(ficheroAct, "a");

	int tamanyo = contarLineas(ficheroAct);

	if(tamanyo < 10){
		fprintf(f,"0%i0%s\n", tamanyo+1);
	}else{
		fprintf(f,"%i0%s\n", tamanyo+1);
	}

	fclose(f);

}

//Este m�todo lo llamas varias veces durante el m�todo Creaci�ndePreguntas() de menus. Coge los datos
//que va dando el usuario y los va escribiendo en orden, separados por el s�mbolo "&" (no se si ser� necesario
//separarlos o no.
void completarPregunta(char* partePreg, int fin){


	char* ficheroAct = "pregunta.txt";
	FILE* f;

	f = fopen(ficheroAct, "a");

	if(fin == 0){
	fprintf(f, "%s &", partePreg);
	}else{
		fprintf(f, "%s \n", partePreg);
	}
	fclose(f);
}
