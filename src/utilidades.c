/*
 * utilidades.c
 *
 *  Created on: 7 abr. 2018
 *      Author: Lander
 */
#include "utilidades.h"
#include <stdio.h>
#include <stdlib.h>
int contarLineas(char* nombreF){

FILE *f;
int cuenta = 0;
char c;

f = fopen(nombreF, "r");


   for (c = getc(f); c != EOF; c = getc(f)){
        if (c == '\n'){
            cuenta = cuenta + 1;
        }
   }


fclose(f);
printf("El archivo tiene %d líneas", cuenta);

return cuenta;

}
