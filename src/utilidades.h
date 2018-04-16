/*
 * utilidades.h
 *
 *  Created on: 7 abr. 2018
 *      Author: Lander
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef UTILIDADES_H_
#define UTILIDADES_H_

typedef struct{
	char cod[2];
	char nombre[10];
	char actT;
}Tema;

int contarLineas(char* nombreF);
void capturarString(char* String, char* nombreF, int tamanyo);
#endif /* UTILIDADES_H_ */
