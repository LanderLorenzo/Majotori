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

typedef struct{

    char cod[3]; //código de tema
    char enunciado[30];
    char respuestaA[30];
    char respuestaB[30];
    char respuestaC[30];
    char respuestaD[30];
    char correcta;

}Pregunta;

int contarLineas(char* nombreF);
void iniciarTemas(Tema* array, char* nombreF, int tamanyoCod,int tamanyoNombre, int longitud);
void iniciarPreguntas(Pregunta* array, char* nombreF, int tamanyoCod, int tamanyoEnunciado, int longPregunta1, int longPregunta2, int longPregunta3, int longPregunta4, int longitud);
#endif /* UTILIDADES_H_ */
