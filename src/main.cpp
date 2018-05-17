/*
 * main.cpp
 *
 *  Created on: 17 may. 2018
 *      Author: Lander
 */




#include <stdio.h>
#include <stdlib.h>
extern "C" {
#include "menus.h"
#include "utilidades.h"
}
#include "sqlite3.h"
#include <string.h>

void MenuJugar(Tema *temas, sqlite3 *db);

/* Se inicia la aplicación con el menu principal, donde recibe un listado de temas y la base de datos donde se va a almacenar.
 * Da a elegir entre 3 diferentes opciones, con unos 'if' abrimos el menu que ha sido seleccionado.
 *
 */
void MenuPrincipal(Tema *temas, sqlite3 *db){
	int eleccion;

	printf("------------------------------------------------------------------- \n");
	printf("MAJOTORI \n");
	printf("1. Jugar \n");
	printf("2. Edición \n");
	printf("3. Salir \n");
	printf("¿Que opción desea?: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &eleccion);
	if( eleccion == 1){
		MenuJugar(temas, db);
	}else if(eleccion == 2){
		MenuEdicion(temas, db);
	}else if(eleccion == 3){
		//cerrar el programa
	}
}

/*	Al activarse 'Menu Jugar' la cual recibe tambien el listado de temas y la base de datos, se abre un menu con las
 * 	diferentes historias con las que se pueden jugar, también esta la opción de dar marcha atras al 'Menu Principal'
 *
 */
void MenuJugar(Tema *temas, sqlite3 *db){
	int eleccion;

	printf("------------------------------------------------------------------- \n");
	printf("JUGAR \n");
	printf("1. Historia 1 \n");
	printf("2. Historia 2 \n");
	printf("3. Historia 3 \n");
	printf("4. Historia 4 \n");
	printf("5. Atras \n");
	printf("¿Que opción desea?: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &eleccion);
	if( eleccion == 1){
		//Historia1
	}else if(eleccion == 2){
		//Historia2
	}else if(eleccion == 3){
		//Historia3
	}else if(eleccion == 4){
		//Historia4
	}else if(eleccion == 5){
		MenuPrincipal(temas, db);
	}

}
int main(int argc, char* argv[]) {


	char* ficheroAct = "tema.txt";
	FILE* f;


	int tamanyo = contarLineas(ficheroAct);
	f = fopen(ficheroAct, "r");

	Tema *temas = new Tema[tamanyo];


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
