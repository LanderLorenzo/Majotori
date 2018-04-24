/*
 * main.c
 *
 *  Created on: 4 abr. 2018
 *      Author: Lander
 */


#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "utilidades.h"
#include "sqlite3.h"
#include <string.h>
int main(int argc, char* argv[]) {


	char* ficheroAct = "tema.txt";
	FILE* f;


	int tamanyo = contarLineas(ficheroAct);
	f = fopen(ficheroAct, "r");

	Tema *temas =(Tema*) malloc(sizeof(Tema)*tamanyo);


	iniciarTemas(temas, ficheroAct, 2, 10, tamanyo);


	fclose(f);

	sqlite3 *db;

		int result = sqlite3_open("PreguntasMajotori.sqlite", &db);
		if (result != SQLITE_OK) {
			printf("Error opening database\n");
			return result;
		}
		/*
	sqlite3_stmt *stmt;

		char sql[] = "CREATE TABLE [Preguntas] ([Cod] NVARCHAR(3)  NOT NULL,[Enunciado] TEXT  UNIQUE NOT NULL PRIMARY KEY,[RespuestaA] TEXT  NOT NULL,[RespuestaB] TEXT  NOT NULL,[RespuestaC] TEXT  NOT NULL,[RespuestaD] TEXT  NOT NULL,[RespuestaCorrecta] VARCHAR(1)  NOT NULL)";
		sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
		sqlite3_step(stmt);
		sqlite3_finalize(stmt);
*/
	MenuPrincipal(temas, db);

	result = sqlite3_close(db);
		if (result != SQLITE_OK) {
			printf("Error opening database\n");
			printf("%s\n", sqlite3_errmsg(db));
			return result;
		}
	free(temas);
	return 0;
}
