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
	int tamanyo;
}Tema;

typedef struct{

    char codp[3]; //código de la pregunta (único)
    char cod[3]; //código de tema
    char enunciado[30];
    char respuestaA[30];
    char respuesta[30];
    char respuestaC[30];
    char respuestaD[30];
    char correcta[1];

}Pregunta;

int contarLineas(char* nombreF);
void iniciarTemas(Tema* array, char* nombreF, int tamanyoCod,int tamanyoNombre, int longitud);
#endif /* UTILIDADES_H_ */
