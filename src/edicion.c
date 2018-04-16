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

	int tamanyo = contarLineas(ficheroAct);
	f = fopen(ficheroAct, "w");
		int i = 0;
		for(i = 0; i < tamanyo; i++){
			if(i != eleccion){
				fprintf(f,"%c",temas[i].cod[0]);
				fprintf(f,"%c",temas[i].cod[1]);
				fprintf(f,"%c",temas[i].actT);
				fprintf(f,"%s\n",temas[i].nombre);
			}else{
			}
		}

	fclose(f);

}

// Este método sería solo para crear el código único de la pregunta
void crearPregunta(char* etema, Tema *temas){

	FILE* f;
	int tamanyo = contarLineas("tema.txt");

	char cod[3];
	int i = 0;
	int j = 0;
	int coinciden = 0;
	while(i < tamanyo){
		while(j < temas[i].tamanyo){
			if(etema[j] == temas[i].nombre[j]){
				coinciden = 1;
			}else{
				coinciden = 0;
				j = temas[i].tamanyo;
			}
			j++;
		}
		if(coinciden == 1){
			i = tamanyo;
			cod[0] = temas[i].cod[0];
			cod[1] = temas[i].cod[1];
		}
		i++;
	}



	char* ficheroAct = "pregunta.txt";

	f = fopen(ficheroAct, "a");


	fprintf(f,"%c%c%s\n", cod[0],cod[1], etema);

	fclose(f);

}

//Este método lo llamas varias veces durante el método CreacióndePreguntas() de menus. Coge los datos
//que va dando el usuario y los va escribiendo en orden, separados por el símbolo "&" (no se si será necesario
//separarlos o no.
void completarPregunta(char* partePreg, int fin){


	char* ficheroAct = "pregunta.txt";
	FILE* f;

	f = fopen(ficheroAct, "a");

	if(fin == 0){
		fprintf(f, "%s &", partePreg);
	}else{
		fprintf(f, "%c\n", partePreg[0]);
	}
	fclose(f);
}
