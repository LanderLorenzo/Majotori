/*
 * edicion.c
 *
 *  Created on: 16 abr. 2018
 *      Author: Lander
 */
#include "edicion.h"
#include "utilidades.h"
#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

/*
 * La función 'crearTema' leera el fichero 'tema.txt'.
 */
void crearTema(char* temaN){

	char* ficheroAct = "tema.txt";
	FILE* f;

	f = fopen(ficheroAct, "a");
		int tamanyo = contarLineas(ficheroAct);

		if(tamanyo < 10){
			fprintf(f,"0%i0%s\n", tamanyo+1, temaN);
		}else{
			fprintf(f,"%i0%s\n", tamanyo+1, temaN);
		}

	fclose(f);

}
/*
 * La función 'borrarTema' borrara el tema del fichero 'tema.txt' que ha elegido el usuario en el atributo 'eleccion' recibido
 */

void borrarTema(int eleccion, Tema *temas){


	char* ficheroAct = "tema.txt";
	FILE* f;

	int tamanyo = contarLineas(ficheroAct);
	f = fopen(ficheroAct, "w");
		int i = 0;
		for(i = 0; i < tamanyo; i++){
			if(i != (eleccion-1)){
				fprintf(f,"%c",temas[i].cod[0]);
				fprintf(f,"%c",temas[i].cod[1]);
				fprintf(f,"%c",temas[i].actT);
				fprintf(f,"%s\n",temas[i].nombre);
			}else{
			}
		}

	fclose(f);

}

/*
 * La función 'compararTemas' comparara que si los códigos de dos temas son iguales
 */
char* compararTemas(char* etema, Tema *temas){
	int tamanyo = contarLineas("tema.txt");



	char* cod = malloc(sizeof(char)*3);
	int a = 0;
	int i = 0;
	int j = 0;
	int coinciden = 0;

	char** nombres = (char**) malloc(sizeof(char*)*tamanyo);
	for(i = 0; i < tamanyo; i++){
		nombres[i] = temas[i].nombre;
	}
		while(j < tamanyo){
			if(*etema == *nombres[j]){
				coinciden = 1;
				a = j;
				j = tamanyo;

			}else{
				coinciden = 0;
			}
			j++;
		}
		if(coinciden == 1){
			cod[0] = temas[a].cod[0];
			cod[1] = temas[a].cod[1];
		}
		return cod;
}



