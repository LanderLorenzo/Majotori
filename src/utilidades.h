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
	char cod[3];
	char nombre[10];
	char actT;
}Tema;

int contarLineas(char* nombreF);
void iniciarTemas(Tema* array, char* nombreF, int tamanyoCod,int tamanyoNombre, int longitud);
#endif /* UTILIDADES_H_ */
