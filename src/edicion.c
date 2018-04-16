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
