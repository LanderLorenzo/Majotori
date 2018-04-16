/*
 * main.c
 *
 *  Created on: 4 abr. 2018
 *      Author: Lander
 */


#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "utilidades.h"

int main(int argc, char* argv[]) {


	char* ficheroAct = "tema.txt";
	FILE* f;

	f = fopen(ficheroAct, "w");
	fprintf(f,"acaw\nabat\n");
	fclose(f);
	int tamanyo = contarLineas(ficheroAct);
	f = fopen(ficheroAct, "r");

	Tema *temas =(Tema*) malloc(sizeof(Tema)*tamanyo);

	int i = 0;
	for(i = 0; i < tamanyo; i++){
		capturarString(temas[i].cod, ficheroAct, 2);
		temas[i].actT = fgetc(f);
		capturarString(temas[i].nombre, ficheroAct, 10);
	}

	fclose(f);

	printf("%c",temas[0].cod[1]);
	printf("%c",temas[1].cod[1]);

	//MenuPrincipal();


	return 0;
}
