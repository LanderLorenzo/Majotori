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
	printf("2. Edici�n \n");
	printf("3. Salir \n");
	printf("�Que opci�n desea?: ");
	fflush(stdout);
	scanf("%d" , &eleccion);
	printf("\n Tu elecci�n es: %d \n" , eleccion);
}
