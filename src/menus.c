/*
 * menus.c
 *
 *  Created on: 7 abr. 2018
 *      Author: Lander
 */
#include <stdio.h>
#include "menus.h"

int MenuPrincipal(){
	int eleccion;

	printf("------------------------------------------------------------------- \n");
	printf("MAJOTORI \n");
	printf("1. Jugar \n");
	printf("2. Edici�n \n");
	printf("3. Salir \n");
	printf("�Que opci�n desea?: ");
	scanf( "%d" , "&eleccion");
	printf( "%d" , eleccion);


	return 0;
}
