/*
 * utilidades.c
 *
 *  Created on: 7 abr. 2018
 *      Author: Lander
 */
#include "utilidades.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int contarLineas(char* nombreF) {

	FILE *f;
	int cuenta = 0;
	char c;

	f = fopen(nombreF, "r");

	while (c != EOF) {
		c = fgetc(f);
		if (c == '\n') {
			cuenta = cuenta + 1;
		}
	}

	fclose(f);

	return cuenta;

}

void iniciarTemas(Tema* array, char* nombreF, int tamanyoCod, int tamanyoNombre, int longitud){
	FILE *f;
	f = fopen(nombreF, "r");

	int j = 0;
	int i = 0;
	while(i < longitud){
		while(j < tamanyoCod){
			array[i].cod[j] = fgetc(f);
			j++;
		}
		j = 0;
		array[i].actT = fgetc(f);
		while(j < tamanyoNombre){
			char a = fgetc(f);
			if (a == '\n'){
				j = tamanyoNombre;
			}else{
			array[i].nombre[j] = a;
			}
			j++;
		}
		array[i].nombre[9] = '\0';
		j = 0;
		i++;
	}

	fclose(f);
}



void partirArray(char cod[], Pregunta *preguntas){

	 int tamanyo = contarLineas("pregunta.txt");
	 Pregunta *preguntas2 = (Pregunta*) malloc(sizeof(Pregunta)*tamanyo);
	 int i = 0;
	 while (i < tamanyo){
		 if(cod[0] == preguntas[i].cod[0] && cod[1] == preguntas[i].cod[1]){
			 preguntas2[i] = preguntas[i];
		 }
	 }
	preguntas = preguntas2;

}
void anyadirPregunta(Pregunta *pregunta, sqlite3 *db){
	sqlite3_stmt *stmt;

		char sql[] = "insert into Preguntas (Cod, Enunciado, RespuestaA, RespuestaB, RespuestaC, RespuestaD, RespuestaCorrecta) values (?, ?, ?, ?, ?, ?, ?)";
		int result = sqlite3_prepare_v2(db, sql, strlen(sql) + 1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
		}

		printf("SQL query prepared (INSERT)\n");
		char cod[3];
		cod[0] = pregunta->cod[0];
		cod[1] = pregunta->cod[1];
		cod[2] = '\0';

		result = sqlite3_bind_text(stmt, 1, cod, strlen(cod), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
		}

		result = sqlite3_bind_text(stmt, 2, pregunta->enunciado, strlen(pregunta->enunciado), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
		}

		result = sqlite3_bind_text(stmt, 3, pregunta->respuestaA, strlen(pregunta->respuestaA), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
		}

		result = sqlite3_bind_text(stmt, 4, pregunta->respuestaB, strlen(pregunta->respuestaB), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
		}

		result = sqlite3_bind_text(stmt, 5, pregunta->respuestaC, strlen(pregunta->respuestaC), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
		}

		result = sqlite3_bind_text(stmt, 6, pregunta->respuestaD, strlen(pregunta->respuestaD), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
		}

		char* correcta = malloc(sizeof(char));
		correcta[0] = pregunta->correcta[0];
		result = sqlite3_bind_text(stmt, 7, correcta, strlen(correcta), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
		}


		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error inserting new data into Preguntas table\n");
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (INSERT)\n");
			printf("%s\n", sqlite3_errmsg(db));
		}

		printf("Prepared statement finalized (INSERT)\n");

		if (result != SQLITE_OK) {
				printf("Error inserting new data\n");
				printf("%s\n", sqlite3_errmsg(db));
			}

}

void mostrarPreguntas(Pregunta *preguntas,sqlite3 *db){
	sqlite3_stmt *stmt;

	char sql[] = "select Enunciado from Preguntas";

	int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
	if (result != SQLITE_OK) {
		printf("Error preparing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("SQL query prepared (SELECT)\n");

	char name[30];
	int i = 1;
	printf("\n");
	printf("\n");
	printf("Preguntas:\n");
	do {
		result = sqlite3_step(stmt) ;
		if (result == SQLITE_ROW) {
			strcpy(name, (char *) sqlite3_column_text(stmt, 0));
			printf("%d - Enunciado: %s\n",i, name);
			i++;
		}
	} while (result == SQLITE_ROW);

	printf("\n");
	printf("\n");

	result = sqlite3_finalize(stmt);
	if (result != SQLITE_OK) {
		printf("Error finalizing statement (SELECT)\n");
		printf("%s\n", sqlite3_errmsg(db));
	}

	printf("Prepared statement finalized (SELECT)\n");

	if (result != SQLITE_OK) {
		printf("Error al mostrar las preguntas\n");
		printf("%s\n", sqlite3_errmsg(db));
	}
}
void borrarPregunta(char* enunciado, sqlite3 *db){

	sqlite3_stmt *stmt;

		char sql[] = "delete from Preguntas where Enunciado = ?";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (DELETE)\n");
			printf("%s\n", sqlite3_errmsg(db));
		}

		printf("SQL query prepared (DELETE)\n");

		result = sqlite3_bind_text(stmt, 1, enunciado, strlen(enunciado), SQLITE_STATIC);
		if (result != SQLITE_OK) {
			printf("Error binding parameters\n");
			printf("%s\n", sqlite3_errmsg(db));
		}

		result = sqlite3_step(stmt);
		if (result != SQLITE_DONE) {
			printf("Error deleting data\n");
			printf("%s\n", sqlite3_errmsg(db));
		}

		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (DELETE)\n");
			printf("%s\n", sqlite3_errmsg(db));
		}

		printf("Prepared statement finalized (DELETE)\n");

		if (result != SQLITE_OK) {
			printf("Error borrando la pregunta\n");
			printf("%s\n", sqlite3_errmsg(db));
		}
}

void iniciarPreguntas(Pregunta* preguntas, sqlite3 *db){
	sqlite3_stmt *stmt;

		char sql[] = "select Cod, Enunciado, RespuestaA, RespuestaB, RespuestaC, RespuestaD, RespuestaCorrecta from Preguntas";

		int result = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) ;
		if (result != SQLITE_OK) {
			printf("Error preparing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
		}

		printf("SQL query prepared (SELECT)\n");

		int i = 0;
		do {
			result = sqlite3_step(stmt) ;
			if (result == SQLITE_ROW) {
				char* Cod = (char*) malloc(sizeof(char) * 3);
				char* Enunciado = (char*) malloc(sizeof(char) * 30);
				char* RespuestaA = (char*) malloc(sizeof(char) * 30);
				char* RespuestaB = (char*) malloc(sizeof(char) * 30);
				char* RespuestaC = (char*) malloc(sizeof(char) * 30);
				char* RespuestaD = (char*) malloc(sizeof(char) * 30);
				char* RespuestaCorrecta = (char*) malloc(sizeof(char));
				preguntas[i].cod = malloc(sizeof(char)*3);
				preguntas[i].enunciado = malloc(sizeof(char)*3);
				preguntas[i].respuestaA = malloc(sizeof(char)*3);
				preguntas[i].respuestaB = malloc(sizeof(char)*3);
				preguntas[i].respuestaC = malloc(sizeof(char)*3);
				preguntas[i].respuestaD = malloc(sizeof(char)*3);
				preguntas[i].correcta = malloc(sizeof(char)*3);
				strcpy(Cod, (char *) sqlite3_column_text(stmt, 0));
				preguntas[i].cod = Cod;
				strcpy(Enunciado, (char *) sqlite3_column_text(stmt, 1));
				preguntas[i].enunciado = Enunciado;
				printf("%s", preguntas[i].enunciado);
				strcpy(RespuestaA, (char *) sqlite3_column_text(stmt, 2));
				preguntas[i].respuestaA = RespuestaA;
				printf("%s", preguntas[i].respuestaA);
				strcpy(RespuestaB, (char *) sqlite3_column_text(stmt, 3));
				preguntas[i].respuestaB = RespuestaB;
				printf("%s", preguntas[i].respuestaB);
				strcpy(RespuestaC, (char *) sqlite3_column_text(stmt, 4));
				preguntas[i].respuestaC = RespuestaC;
				printf("%s", preguntas[i].respuestaC);
				strcpy(RespuestaD, (char *) sqlite3_column_text(stmt, 5));
				preguntas[i].respuestaD = RespuestaD;
				printf("%s", preguntas[i].respuestaD);
				strcpy(RespuestaCorrecta, (char *) sqlite3_column_text(stmt, 6));
				preguntas[i].correcta = RespuestaCorrecta;
				i++;

			}
		} while (result == SQLITE_ROW);


		result = sqlite3_finalize(stmt);
		if (result != SQLITE_OK) {
			printf("Error finalizing statement (SELECT)\n");
			printf("%s\n", sqlite3_errmsg(db));
		}

		printf("Prepared statement finalized (SELECT)\n");

		if (result != SQLITE_OK) {
			printf("Error al inicializar las preguntas\n");
			printf("%s\n", sqlite3_errmsg(db));
		}
}
