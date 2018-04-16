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
				array[i].tamanyo = j+1;
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
