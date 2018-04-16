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

void capturarString(char* String, char* nombreF, int tamanyo){
	FILE *f;
	f = fopen(nombreF, "r");

	int j = 0;
	while(j < tamanyo){
		String[j] = fgetc(f);
		j++;
	}

	fclose(f);
}
