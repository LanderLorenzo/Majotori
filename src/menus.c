/*
 * menus.c
 *
 *  Created on: 7 abr. 2018
 *      Author: Lander
 */
#include <stdio.h>
#include "menus.h"


void MenuPrincipal(){
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
		MenuJugar();
	}else if(eleccion == 2){
		MenuEdicion();
	}else if(eleccion == 3){
		//cerrar el programa
	}
}

void MenuJugar(){
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
		MenuPrincipal();
	}

}

void MenuEdicion(){
	int eleccion;

	printf("------------------------------------------------------------------- \n");
	printf("EDICIÓN \n");
	printf("1. Creación de tema \n");
	printf("2. Borrado de tema \n");
	printf("3. Listado de tema \n");
	printf("4. Creación de preguntas \n");
	printf("5. Borrado de preguntas \n");
	printf("6. Edición de temas \n");
	printf("7. Ajustes de Trivial \n");
	printf("8. Atras \n");
	printf("¿Que opción desea?: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &eleccion);
	if(eleccion == 1){
		CreacionDeTema();
	}else if(eleccion == 2){
		BorradoTema();
	}else if(eleccion == 3){
		ListadoDeTema();
	}else if(eleccion == 4){
		CreacionDePreguntas();
	}else if(eleccion == 5){
		BorradoDePreguntas();
	}else if(eleccion == 6){
		EdicionDeTemas();
	}else if(eleccion == 7){
		AjustesDeTrivial();
	}else if(eleccion == 8){
		MenuPrincipal();
	}
}

void CreacionDeTema(){
	char nombre[30];
	char eleccion[10];

	printf("------------------------------------------------------------------- \n");
	printf("CREACION DEL TEMA \n");
	printf("Pulsa q para salir. \n");
	printf("Nombre del tema: ");
	fflush(stdin);
	fflush(stdout);
	scanf( "%s", nombre);
	if(nombre[0] == 'q'){
		MenuEdicion();
	} else {
		printf("Tu tema es: %s para confirmar pulse p ,para salir sin guardar pulse q. \n", nombre);
		fflush(stdin);
		fflush(stdout);
		scanf( "%s", eleccion);

		switch(eleccion[0]){
			case 'q' :
				MenuEdicion();
				break;
			case 'p' :
				//Guardar
				printf("Tu tema se ha guardado correctamente");
				MenuEdicion();
				break;
			}
	}
}

void BorradoTema(){
	char opcion[30];
	char eleccion[10];
	printf("------------------------------------------------------------------- \n");
	printf("BORRAR TEMA \n");
	printf("Pulsa q para salir. \n");
	//Todos los temas.
	printf("\n Elegir tema numero: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c" , &opcion[0]);
	if(opcion[0] == 'q'){
		MenuEdicion();
	} else {
		printf("\n Has elegido el tema numero %s \n", opcion);
		printf("Pulsa q para salir, p para confirmar: ");
		fflush(stdin);
		fflush(stdout);
		scanf( "%s", eleccion);

		switch(eleccion[0]){
		case 'q' :
			MenuEdicion();
			break;
		case 'p' :
			//Borrar tema seleccionado.
			printf("El tema seleccionado se ha borrado correctamente. \n");
			MenuEdicion();
			break;
		}
	}
}

void ListadoDeTema(){
	int eleccion;
	printf("------------------------------------------------------------------- \n");
	printf("LISTADO DE TEMA \n");
	//Todas los temas.
	printf("1. Atras \n");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &eleccion);
	if(eleccion == 1){
		MenuEdicion();
	}

}

void CreacionDePreguntas(){
	int eleccion;
	printf("------------------------------------------------------------------- \n");
	printf("CREACION DE PREGUNTA \n");
	printf("1.Enunciado: \n");
	printf("2.Respuestas: \n");
	printf("3.Respuesta correcta a la pregunta: \n");
	printf("4.Guardar \n");
	printf("5.Atras. \n");
	printf("¿Que opción desea?: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &eleccion);
	if(eleccion == 1){
		Enunciado();
	}else if(eleccion == 2){
		Respuesta();
	}else if(eleccion == 3){
		RespuestaCorrecta();
	}else if(eleccion == 4){
		//Guardar
	}else if(eleccion == 5){
		MenuEdicion();
	}
}


void Enunciado(){
	char nombre[30];
	char eleccion[10];

	printf("------------------------------------------------------------------- \n");
	printf("ENUNCIADO: \n");
	printf("Pulsa q para salir. \n");
	printf("Texto: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%s" , nombre);
	if(nombre[0] == 'q'){
		MenuEdicion();
	} else {
		printf("Tu enunciado es: %s \n", nombre);
		printf("Pulsa q para salir, p para confirmar: ");
		fflush(stdin);
		fflush(stdout);
		scanf( "%s", eleccion);

		switch(eleccion[0]){
		case 'q' :
			MenuEdicion();
			break;
		case 'p' :
			//Guardar
			printf("El enunciado se ha guardado correctamente. \n");
			MenuEdicion();
			break;
		}

	}
}

void Respuesta(){
	char respuesta1[30];
	char respuesta2[30];
	char respuesta3[30];
	char respuesta4[30];
	char eleccion[10];
	printf("------------------------------------------------------------------- \n");
	printf("RESPUESTAS: \n");
	printf("Pulsa q para salir. \n");
	printf("Respuesta A: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%s", respuesta1);
	if(respuesta1[0] == 'q'){
		MenuEdicion();
	} else {
		printf("\n Respuesta A es: %s \n" , respuesta1);
	}

	printf("Respuesta B: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%s", respuesta2);
	if(respuesta2[0] == 'q'){
		MenuEdicion();
	} else {
		printf("\n Respuesta B es: %s \n" , respuesta2);
	}

	printf("Respuesta C: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%s", respuesta3);
	if(respuesta3[0] == 'q'){
		MenuEdicion();
	} else {
		printf("\n Respuesta C es: %s \n" , respuesta3);
	}

	printf("Respuesta D: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%s", respuesta4);
	if(respuesta4[0] == 'q'){
		MenuEdicion();
	} else {
		printf("\n Respuesta D es: %s \n" , respuesta4);
	}

	printf("Pulsa q para salir, p para confirmar: ");
	fflush(stdin);
	fflush(stdout);
	scanf( "%s", eleccion);

	switch(eleccion[0]){
	case 'q' :
		MenuEdicion();
		break;
	case 'p' :
		//Guardar
		printf("Las respuestas se han guardado correctamente. \n");
		MenuEdicion();
		break;
	}



}
void RespuestaCorrecta(){
	char respuestaCorrecta[10];
	char eleccion[10];
	printf("------------------------------------------------------------------- \n");
	printf("RESPUESTA CORRECTA \n");
	printf("Pulsa q para salir. \n");
	printf("Letra: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c", &respuestaCorrecta);
	if(respuestaCorrecta[0] == 'q'){
		MenuEdicion();
	} else {
		printf("\n La respuesta %c es la correcta. \n" , respuestaCorrecta);
	}
	printf("Pulsa q para salir, p para confirmar: ");
	fflush(stdin);
	fflush(stdout);
	scanf( "%s", eleccion);

	switch(eleccion[0]){
	case 'q' :
		MenuEdicion();
		break;
	case 'p' :
		//Guardar
		printf("Las respuesta correcta se ha guardado correctamente. \n");
		MenuEdicion();
		break;
	}

}
void BorradoDePreguntas(){
	char numeroTema[10];
	char numeroPregunta[10];
	char eleccion[10];

	printf("------------------------------------------------------------------- \n");
	printf("BORRAR PREGUNTA \n");
	printf("Pulsa q para salir. \n");
	printf("Elige el tema donde esta la pregunta. \n");
	//Lista de temas.

	printf("Tema numero: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%s" , &numeroTema);
	if(numeroTema[0] == 'q'){
		MenuEdicion();
	} else {
		printf("\n Has elegido el tema numero %c \n" , numeroTema);
	}
	printf("Elige la pregunta que quieras borrar. \n");
	//Listado de preguntas de ese tema.
	printf("Pregunta numero: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%s" , &numeroPregunta);
	if(numeroPregunta[0] == 'q'){
		MenuEdicion();
	} else {
		printf("\n Has elegido la pregunta numero: %c \n" , numeroPregunta);
	}
	printf("Pulsa q para salir, p para confirmar: ");
	fflush(stdin);
	fflush(stdout);
	scanf( "%s", eleccion);

	switch(eleccion[0]){
	case 'q' :
		MenuEdicion();
		break;
	case 'p' :
		//Borrar
		printf("Las pregunta se ha borrado correctamente. \n");
		MenuEdicion();
		break;
	}

}

void EdicionDeTemas(){
	int eleccion;
	printf("------------------------------------------------------------------- \n");
	printf("EDICIÓN DE TEMAS \n");
	printf("1.Añadir preguntas a un tema \n");
	printf("2.Atras \n");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &eleccion);
	if(eleccion == 1){
		AnyadirPreguntasATema();
	}else if(eleccion == 2){
		MenuEdicion();
	}

}

void AnyadirPreguntasATema(){
	char numeroTema[10];
	char eleccion[10];

	printf("------------------------------------------------------------------- \n");
	printf("AÑADIR PREGUNTAS \n");
	printf("Pulsa q para salir. \n");
	//Lista de temas.

	printf("Tema numero: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%s" , &numeroTema);
	if(numeroTema[0] == 'q'){
		MenuEdicion();
	} else {
		printf("\n Es el tema numero %c \n" , numeroTema);
	}

	ElegirPregunta();

	printf("Pulsa q para salir, p para confirmar: ");
	fflush(stdin);
	fflush(stdout);
	scanf( "%s", eleccion);

	switch(eleccion[0]){
	case 'q' :
		MenuEdicion();
		break;
	case 'p' :
		//Borrar
		printf("La pregunta se ha añadido correctamente. \n");
		MenuEdicion();
		break;
	}
}

void ElegirPregunta(){
	char opcion[10];
	char eleccion[10];

	printf("------------------------------------------------------------------- \n");
	printf("ELEGIR PREGUNTA \n");
	printf("Pulsa q para salir. \n");
	//Lista de enunciados de las preguntas.

	printf("Elegir pregunta que quieras añadir: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%s" , &opcion);
	if(opcion[0] == 'q'){
		MenuEdicion();
	} else {
		printf("\n Has elegido la pregunta numero %c \n", opcion);
	}

	printf("Pulsa q para salir, p para confirmar: ");
	fflush(stdin);
	fflush(stdout);
	scanf( "%s", eleccion);

	switch(eleccion[0]){
	case 'q' :
		MenuEdicion();
		break;
	case 'p' :
		//Borrar
		printf("La pregunta ha sido seleccionada correctamente. \n");
		MenuEdicion();
		break;
	}

}

void AjustesDeTrivial(){
	char opcion[10];
	char eleccion[10];
	printf("------------------------------------------------------------------- \n");
	printf("AJUSTES DEL TRIVIAL \n");
	printf("Pulsa q para salir. \n");
	//Listado de Temas (Marcando si estan activos o no)

	printf("Elegir tema para activar/desactivar: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%s" , &opcion);
	if(opcion[0] == 'q'){
		MenuEdicion();
	} else {
		printf("\n Has elegido el tema numero %c \n", opcion);
	}

	printf("Pulsa q para salir, p para confirmar: ");
	fflush(stdin);
	fflush(stdout);
	scanf( "%c", eleccion);

	switch(eleccion[0]){
	case 'q' :
		MenuEdicion();
		break;
	case 'p' :
		//Borrar
		printf("La pregunta ha sido seleccionada correctamente. \n");
		MenuEdicion();
		break;
	}

}



