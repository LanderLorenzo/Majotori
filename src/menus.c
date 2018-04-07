/*
 * menus.c
 *
 *  Created on: 7 abr. 2018
 *      Author: Lander
 */
#include <stdio.h>
#include "menus.h"

void Invocar(int eleccion){

}

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
	printf("\n Tu elección es: %d \n" , eleccion);
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
	printf("\n Tu elección es: %d \n" , eleccion);

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
	printf("\n Tu elección es: %d \n" , eleccion);
}

void CracionDeTema(){
	char nombre[30];
	printf("------------------------------------------------------------------- \n");
	printf("CREACION DEL TEMA \n");
	printf("Pulsa q para salir.");
	printf("Nombre del tema:");
	fflush(stdin);
	fflush(stdout);
	fgets(nombre, 30, stdin);

	printf("\n Tu tema es: %c \n" , nombre);

}

void ListadoDeTema(){
	int eleccion;
	printf("------------------------------------------------------------------- \n");
	printf("LISTADO DE TEMA \n");
	printf("1. Atras");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &eleccion);

}

void CreacionDePreguntas(){
	printf("------------------------------------------------------------------- \n");
	printf("CREACION DE PREGUNTA \n");
}
