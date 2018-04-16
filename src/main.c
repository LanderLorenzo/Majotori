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
	fprintf(f,"010w\n020t\n");
	fclose(f);
	int tamanyo = contarLineas(ficheroAct);
	f = fopen(ficheroAct, "r");

	char* cod[2]; //array para los codigos
	char* nombresT[10]; //array para los nombres
	char* actT = (char*) malloc(sizeof(char) * tamanyo); // array para comprobar si un tema está activo o no


	int i = 0;
	for(i = 0; i < tamanyo; i++){
		//fgets(cod[i], 2, f);
		actT[i] = fgetc(f);
		//fgets(nombresT[i],10, f);
	}

	fclose(f);



	//MenuPrincipal();


	return 0;
}
