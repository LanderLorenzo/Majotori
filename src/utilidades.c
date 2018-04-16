/*
 * utilidades.c
 *
 *  Created on: 7 abr. 2018
 *      Author: Lander
 */
#include "utilidades.h"
#include <stdio.h>
#include <stdlib.h>
int contarLineas(FILE* f){

FILE *fp;
int cuenta = 0;
char c;

fp = fopen(f, "r");


   for (c = getc(fp); c != EOF; c = getc(fp)){
        if (c == '\n'){
            cuenta = cuenta + 1;
        }
   }


fclose(f);
printf("El archivo tiene %d líneas", cuenta);

return cuenta;

}
