/*
 * edicion.h
 *
 *  Created on: 16 abr. 2018
 *      Author: Lander
 */

#include <stdio.h>
#include <stdlib.h>
#include "utilidades.h"

#ifndef EDICION_H_
#define EDICION_H_

void crearTema(char* temaN);
void crearPregunta(char* etema);
void completarPregunta(char* partePreg, int fin);
void borrarTema(int eleccion, Tema *temas);

#endif /* EDICION_H_ */
