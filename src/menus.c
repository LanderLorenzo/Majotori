/*
 * menus.c
 *
 *  Created on: 7 abr. 2018
 *      Author: Lander
 */
#include <stdio.h>
#include "menus.h"

void Invocar(int eleccion){
	if( eleccion == 1){
		MenuPrincipal();
	}else if(eleccion == 2){
		MenuJugar();
	}else if(eleccion == 3){
		MenuEdicion();
	}else if(eleccion == 4){
		CreacionDeTema();
	}else if(eleccion == 5){
		ListadoDeTema();
	}else if(eleccion == 6){
		CreacionDePreguntas();
	}
}

void MenuPrincipal(){
	int eleccion;

	printf("------------------------------------------------------------------- \n");
	printf("MAJOTORI \n");
	printf("1. Jugar \n");
	printf("2. Edici�n \n");
	printf("3. Salir \n");
	printf("�Que opci�n desea?: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &eleccion);
	printf("\n Tu elecci�n es: %d \n" , eleccion);
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
	printf("�Que opci�n desea?: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &eleccion);
	printf("\n Tu elecci�n es: %d \n" , eleccion);

}

void MenuEdicion(){
int eleccion;

	printf("------------------------------------------------------------------- \n");
	printf("EDICI�N \n");
	printf("1. Creaci�n de tema \n");
	printf("2. Borrado de tema \n");
	printf("3. Listado de tema \n");
	printf("4. Creaci�n de preguntas \n");
	printf("5. Borrado de preguntas \n");
	printf("6. Edici�n de temas \n");
	printf("7. Ajustes de Trivial \n");
	printf("8. Atras \n");
	printf("�Que opci�n desea?: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &eleccion);
	printf("\n Tu elecci�n es: %d \n" , eleccion);
}

void CreacionDeTema(){
	char nombre[30];
	printf("------------------------------------------------------------------- \n");
	printf("CREACION DEL TEMA \n");
	printf("Pulsa q para salir. \n");
	printf("Nombre del tema: ");
	fflush(stdin);
	fflush(stdout);
	fgets(nombre, 30, stdin);

	printf("\n Tu tema es: %c \n" , nombre);

}

void ListadoDeTema(){
	int eleccion;
	printf("------------------------------------------------------------------- \n");
	printf("LISTADO DE TEMA \n");
	printf("1. Atras \n");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &eleccion);

}

void CreacionDePreguntas(){
	int eleccion;
	printf("------------------------------------------------------------------- \n");
	printf("CREACION DE PREGUNTA \n");
	printf("1.Enunciado: \n");
	printf("2.Respuesta: \n");
	printf("3.Respuesta correcta a la pregunta: \n");
	printf("4.Guardar \n");
	printf("5.Cancelar: \n");
	printf("�Que opci�n desea?: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &eleccion);
	printf("\n Tu elecci�n es: %d \n" , eleccion);
}

void Enunciado(){
	char nombre[30];
	printf("------------------------------------------------------------------- \n");
	printf("ENUNCIADO: \n");
	printf("Pulsa q para salir. \n");
	printf("Texto: ");
	fflush(stdin);
	fflush(stdout);
	fgets(nombre, 30, stdin);
	printf("\n Tu enunciado es: %c \n" , nombre);
}

void Respuesta(){
	char respuesta1[30];
	char respuesta2[30];
	char respuesta3[30];
	char respuesta4[30];
	printf("------------------------------------------------------------------- \n");
	printf("RESPUESTA: \n");
	printf("Pulsa q para salir. \n");
	printf("Respuesta A: ");
	fflush(stdin);
	fflush(stdout);
	fgets(respuesta1, 30, stdin);
	printf("\n Respuesta A es: %c \n" , respuesta1);

	printf("Respuesta B: ");
		fflush(stdin);
		fflush(stdout);
		fgets(respuesta2, 30, stdin);
		printf("\n Respuesta B es: %c \n" , respuesta2);

	printf("Respuesta C: ");
		fflush(stdin);
		fflush(stdout);
		fgets(respuesta3, 30, stdin);
		printf("\n Respuesta C es: %c \n" , respuesta3);

	printf("Respuesta D: ");
		fflush(stdin);
		fflush(stdout);
		fgets(respuesta4, 30, stdin);
		printf("\n Respuesta D es: %c \n" , respuesta4);
}

void A�adirPreguntasATema(){

}

void ElegirPregunta(){

}


