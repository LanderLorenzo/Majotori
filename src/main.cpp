/*
 * main.cpp
 *
 *  Created on: 17 may. 2018
 *      Author: Lander
 */



#include <iostream>
#include <stdio.h>
#include <stdlib.h>
extern "C" {
#include "menus.h"
#include "utilidades.h"
#include "edicion.h"
}
#include "sqlite3.h"
#include <string.h>
#include "historia.h"

using namespace std;

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
		char opcion;
		char* historiaAct = new char();
		historiaAct = "Historia1.txt";
		bool* respuestas = new bool[10];
		historiaRecorrida historia1(respuestas, historiaAct,0);
		historia1.mostrarTexto();

		//PREGUNTAS AQUI
		cout << "Es hora del Trivial!\n" << endl;
		Pregunta* preguntas = new Pregunta[100];
		Pregunta* preguntasFiltradas = new Pregunta[100];
		iniciarPreguntas(preguntas, db);
		int tamanyo = contarLineas("tema.txt");
		int puntero = 0;
		for (int j = 0; j < tamanyo; j++){
			char* codigoTema = new char[3];
			codigoTema = compararTemas(temas[j].nombre, temas);
			for (int k = 0; k < 100; k++){
				if (preguntas[k].cod[0] == codigoTema[0] && preguntas[k].cod[1] == codigoTema[1]){
					if (temas[j].actT == '0'){

					}else{
						preguntasFiltradas[puntero] = preguntas[k];
					}
				}
			}
		}
		for (int b = 0; b < 10; b++){
			int r = rand()% puntero;
			char* respuesta;
			cout << "Pregunta: " << endl;
			cout << preguntasFiltradas[r].enunciado << endl;
			cout << "Respuesta A: " << preguntasFiltradas[r].respuestaA << endl;
			cout << "Respuesta B: " << preguntasFiltradas[r].respuestaB << endl;
			cout << "Respuesta C: " << preguntasFiltradas[r].respuestaC << endl;
			cout << "Respuesta D: " << preguntasFiltradas[r].respuestaD << endl;
			cout << "¿Cual es tu respuesta? " << endl;
			scanf("%c", respuesta);
			if (respuesta == preguntasFiltradas[r].correcta){
				cout << "¡Correcto!" << endl;
				respuestas[b] = true;
			}else{
				cout << "¡Que pena! La respuesta correcta era la... " << preguntasFiltradas[r].correcta <<endl;
				respuestas[b] = false;
			}

		}
		//FIN DE LAS PREGUNTAS
		historia1.setRespuestas(respuestas);
		bool tombola = historia1.tombola();
		if(tombola == true){
			cout << "¡Felicidades, has tenido suerte con la tombola! 'q' para continuar o otra tecla alfabetica para guardar y salir:\n" << endl;
			scanf("%c", &opcion);

			if(opcion == 'q'){
			historiaAct = "Historia1Rama1.txt";
			historia1.setTexto(historiaAct);
			historia1.mostrarTexto();
			//PREGUNTAS AQUI

			//FIN DE LAS PREGUNTAS
			historia1.setRespuestas(respuestas);
			tombola = historia1.tombola();
			if(tombola == true){
				historiaAct = "Historia1Rama1Final1.txt";
				historia1.setTexto(historiaAct);
				historia1.mostrarTexto();
			}else if(tombola == false){
				historiaAct = "Historia1Rama1Final2.txt";
				historia1.setTexto(historiaAct);
				historia1.mostrarTexto();
			}
			}else{
			//GUARDAR EN UNA BASE DE DATOS?
			}
		}else if(tombola == false){
			cout << "Mala suerte... 'q' para continuar o otra tecla alfabetica para guardar y salir:\n" << endl;
			scanf("%c", &opcion);

			if(opcion == 'q'){
			historiaAct = "Historia1Rama2.txt";
			historia1.setTexto(historiaAct);
			historia1.mostrarTexto();
			//PREGUNTAS AQUI

			//FIN DE LAS PREGUNTAS
			historia1.setRespuestas(respuestas);
			tombola = historia1.tombola();
			if(tombola == true){
				historiaAct = "Historia1Rama2Final1.txt";
				historia1.setTexto(historiaAct);
				historia1.mostrarTexto();
			}else if(tombola == false){
				historiaAct = "Historia1Rama2Final2.txt";
				historia1.setTexto(historiaAct);
				historia1.mostrarTexto();
			}
			}else{
				//GUARDAR EN UNA BASE DE DATOS?
			}

		}

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
