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
	fprintf(f,"010Cuack\n021whale\n");
	fclose(f);
	int tamanyo = contarLineas(ficheroAct);
	f = fopen(ficheroAct, "r");

	Tema *temas =(Tema*) malloc(sizeof(Tema)*tamanyo);


	iniciarTemas(temas, ficheroAct, 2, 10, tamanyo);


	fclose(f);


	MenuPrincipal();


	return 0;
}
