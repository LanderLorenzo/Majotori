/*
 * menus.h
 *
 *  Created on: 7 abr. 2018
 *      Author: Lander
 */
#include "utilidades.h"

#ifndef MENUS_H_
#define MENUS_H_

void MenuPrincipal(Tema *temas);
void MenuJugar(Tema *temas);
void MenuEdicion(Tema *temas);
void CracionDeTema(Tema *temas);
void BorradoTema(Tema *temas);
void ListadoDeTema(Tema *temas);
void CreacionDePreguntas(Tema *temas);
void BorradoDePreguntas(Tema *temas);
void Enunciado(Tema *temas);
void Respuesta(Tema *temas);
void RespuestaCorrecta(Tema *temas);
void AnyadirPreguntasATema(Tema *temas);
void ElegirPregunta(Tema *temas);
void EdicionDeTemas(Tema *temas);
void AjustesDeTrivial(Tema *temas);

#endif /* MENUS_H_ */
