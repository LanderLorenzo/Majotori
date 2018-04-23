/*
 * menus.h
 *
 *  Created on: 7 abr. 2018
 *      Author: Lander
 */
#include "utilidades.h"
#include "sqlite3.h"
#ifndef MENUS_H_
#define MENUS_H_

void MenuPrincipal(Tema *temas, sqlite3 *db);
void MenuJugar(Tema *temas, sqlite3 *db);
void MenuEdicion(Tema *temas, sqlite3 *db);
void CreacionDeTema(Tema *temas, sqlite3 *db);
void BorradoTema(Tema *temas, sqlite3 *db);
void ListadoDeTema(Tema *temas, sqlite3 *db);
void CreacionDePreguntas(Tema *temas, sqlite3 *db);
void BorradoDePreguntas(Tema *temas, sqlite3 *db);
void AjustesDeTrivial(Tema *temas);
int ListadoDePreguntas(Tema *temas, Pregunta *preguntas, sqlite3 *db);

#endif /* MENUS_H_ */
