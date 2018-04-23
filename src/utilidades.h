/*
 * utilidades.h
 *
 *  Created on: 7 abr. 2018
 *      Author: Lander
 */

#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

#ifndef UTILIDADES_H_
#define UTILIDADES_H_

typedef struct{
	char cod[3];
	char nombre[10];
	char actT;
}Tema;

typedef struct{

    char* cod; //código de tema
    char* enunciado;
    char* respuestaA;
    char* respuestaB;
    char* respuestaC;
    char* respuestaD;
    char* correcta;

}Pregunta;

int contarLineas(char* nombreF);
void iniciarTemas(Tema* array, char* nombreF, int tamanyoCod,int tamanyoNombre, int longitud);
void partirArray(char cod[], Pregunta *preguntas);
void anyadirPregunta(Pregunta *pregunta, sqlite3 *db);
void mostrarPreguntas(Pregunta *preguntas, sqlite3 *db);
void borrarPregunta(char* enunciado, sqlite3 *db);
void iniciarPreguntas(Pregunta *preguntas, sqlite3 *db);
#endif /* UTILIDADES_H_ */
