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


		f = fopen(ficheroAct, "w");
		fprintf(f, "%c \n", temaN);
		fclose(f);


		int tamanyo = contarLineas(ficheroAct);
		f = fopen(ficheroAct, "r");

		Tema *temas =(Tema*) malloc(sizeof(Tema)*tamanyo);


		iniciarTemas(temas, ficheroAct, 2, 10, tamanyo);


		fclose(f);

}
