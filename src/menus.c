/*
 * menus.c
 *
 *  Created on: 7 abr. 2018
 *      Author: Lander
 */
#include <stdio.h>
#include "menus.h"
#include "utilidades.h"

void MenuPrincipal(Tema *temas){
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
		MenuJugar(temas);
	}else if(eleccion == 2){
		MenuEdicion(temas);
	}else if(eleccion == 3){
		//cerrar el programa
	}
}

void MenuJugar(Tema *temas){
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
		MenuPrincipal(temas);
	}

}

void MenuEdicion(Tema *temas){
	int eleccion;

	printf("------------------------------------------------------------------- \n");
	printf("EDICIÓN \n");
	printf("1. Creación de tema \n");
	printf("2. Borrado de tema \n");
	printf("3. Listado de tema \n");
	printf("4. Creación de preguntas \n");
	printf("5. Borrado de preguntas \n");
	printf("6. Ajustes de Trivial \n");
	printf("7. Atras \n");
	printf("¿Que opción desea?: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &eleccion);
	if(eleccion == 1){
		CreacionDeTema(temas);
	}else if(eleccion == 2){
		BorradoTema(temas);
	}else if(eleccion == 3){
		ListadoDeTema(temas);
	}else if(eleccion == 4){
		CreacionDePreguntas(temas);
	}else if(eleccion == 5){
		BorradoDePreguntas(temas);
	}else if(eleccion == 6){
		AjustesDeTrivial(temas);
	}else if(eleccion == 7){
		MenuPrincipal(temas);
	}
}

void CreacionDeTema(Tema *temas){
	char* nombre[30];
	char eleccion[10];

	printf("------------------------------------------------------------------- \n");
	printf("CREACION DEL TEMA \n");
	printf("Pulsa q para salir. \n");
	printf("Nombre del tema: ");
	fflush(stdin);
	fflush(stdout);
	scanf( "%s", nombre);
	if(nombre[0] == 'q'){
		MenuEdicion(temas);
	} else {
		printf("Tu tema es: %s para confirmar pulse p ,para salir sin guardar pulse q. \n", nombre);
		fflush(stdin);
		fflush(stdout);
		scanf( "%s", eleccion);

		if(eleccion[0] == 'q'){
				MenuEdicion(temas);
		}else{
		//Guardar

		    crearTema(nombre);
			printf("Tu tema se ha guardado correctamente, reiniciando para guardar los cambios...");
			char* ficheroAct = "tema.txt";
			FILE* f;
			int tamanyo = contarLineas(ficheroAct);
			f = fopen(ficheroAct, "r");

			Tema *nuevosTemas =(Tema*) malloc(sizeof(Tema)*tamanyo);


			iniciarTemas(nuevosTemas, ficheroAct, 2, 10, tamanyo);


			fclose(f);
			//MenuEdicion(nuevosTemas);
		}
	}
}

void BorradoTema(Tema *temas){
	int opcion;
	char eleccion;
	printf("------------------------------------------------------------------- \n");
	printf("BORRAR TEMA \n");
	printf("0. Atras\n");
	//Todos los temas.
	printf("Temas: \n");
	int tamanyo = contarLineas("tema.txt");
		int i = 0;
		while (i < tamanyo){
			printf("%i. %s\n", i+1, temas[i].nombre);
			i++;
		}
	printf("\nElegir tema numero: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%i" , &opcion);
	if(opcion == 0){
		MenuEdicion(temas);
	} else {
		printf("\nHas elegido el tema numero %i \n", opcion);
		printf("Pulsa q para salir, p para confirmar: ");
		fflush(stdin);
		fflush(stdout);
		scanf( "%c", &eleccion);

		switch(eleccion){
		case 'q' :
			MenuEdicion(temas);
			break;
		case 'p' :
			//Borrar tema seleccionado.
			borrarTema(opcion, temas);
			printf("El tema seleccionado se ha borrado correctamente, reiniciando para guardar cambios... \n");
			break;
		}
	}
}

void ListadoDeTema(Tema *temas){
	int eleccion;
	printf("------------------------------------------------------------------- \n");
	printf("LISTADO DE TEMA \n");
	//Todas los temas.
	printf("0. Atras \n");
	printf("Temas: \n");
	int tamanyo = contarLineas("tema.txt");
	int i = 0;
	while (i < tamanyo){
		printf("%i. %s\n", i+1, temas[i].nombre);
		i++;
	}

	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &eleccion);
	if(eleccion == 0){
		MenuEdicion(temas);
	}

}

void CreacionDePreguntas(Tema *temas){
		char etema[10];
		char* enunciado =(char*) malloc(sizeof(char)*30);
		char* respuesta1 =(char*) malloc(sizeof(char)*30);
		char* respuesta2 =(char*) malloc(sizeof(char)*30);
		char* respuesta3 =(char*) malloc(sizeof(char)*30);
		char* respuesta4 =(char*) malloc(sizeof(char)*30);

	printf("------------------------------------------------------------------- \n");
	printf("CREACION DE PREGUNTA \n");
	printf("------------------------------------------------------------------- \n");
	printf("Tema: \n");
	printf("Pulsa q para salir. \n");
	printf("Temas: \n");
		int tamanyo = contarLineas("tema.txt");
		int i = 0;
		while (i < tamanyo){
			printf("%i. %s\n", i+1, temas[i].nombre);
			i++;
		}
	printf("Elige el NOMBRE del tema: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%s" ,etema);

	if(etema[0] == 'q'){
		MenuEdicion(temas);
	} else {

		printf("El tema elegido es: %s \n", etema);
		crearPregunta(etema, temas);
		completarPregunta(etema, 0);
		//GuardaTema
	}
	printf("Siempre que se quiera poner un 'espacio' escribir '_'.\n");
	printf("Enunciado: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%s" , enunciado);

		printf("\nTu enunciado es: %s \n", enunciado);
		completarPregunta(enunciado, 0);
		//Guardar enunciado
		fflush(stdin);
		fflush(stdout);

		printf("------------------------------------------------------------------- \n");
			printf("RESPUESTAS: \n");

			printf("Respuesta A: ");
			fflush(stdin);
			fflush(stdout);
			scanf("%s", respuesta1);

				printf("\nRespuesta A es: %s \n" , respuesta1);
				completarPregunta(respuesta1, 0);
				//Guardar respuesta1
				free(respuesta1);

			printf("Respuesta B: ");
			fflush(stdin);
			fflush(stdout);
			scanf("%s", respuesta2);

				printf("\nRespuesta B es: %s \n" , respuesta2);
				completarPregunta(respuesta2, 0);
				//Guardar respuesta2
				free(respuesta2);

			printf("Respuesta C: ");
			fflush(stdin);
			fflush(stdout);
			scanf("%s", respuesta3);

				printf("\nRespuesta C es: %s \n" , respuesta3);
				completarPregunta(respuesta3, 0);
				//Guardar respuesta3
				free(respuesta3);

			printf("Respuesta D: ");
			fflush(stdin);
			fflush(stdout);
			scanf("%s", respuesta4);

				printf("\nRespuesta D es: %s \n" , respuesta4);
				completarPregunta(respuesta4, 0);
				//Guardar respuesta4
				free(respuesta4);

				char respuestaCorrecta;
			printf("------------------------------------------------------------------- \n");
				printf("RESPUESTA CORRECTA \n");
				printf("Letra: ");
				fflush(stdin);
				fflush(stdout);
				scanf("%c", &respuestaCorrecta);

					printf("\nLa respuesta %c es la correcta. \n" , respuestaCorrecta);
					completarPregunta(&respuestaCorrecta, 1);
					//Guardar respuesta correcta
				fflush(stdin);
				fflush(stdout);
				printf("Reiniciando para guardar los cambios...");


}


char ListadoDePreguntas(Tema *temas, Pregunta *preguntas){
	char eleccion;
	printf("------------------------------------------------------------------- \n");
	printf("0.Atras\n");
	printf("LISTADO DE PREGUNTAS \n");
	//Todas las preguntas.
	printf("Preguntas: \n");
	int tamanyo = contarLineas("pregunta.txt")/2;
	int i = 0;
	while (i < tamanyo){
		printf("%i. %s\n", i+1, preguntas[i].enunciado);
		i++;
	}

fflush(stdin);
fflush(stdout);
scanf("%c" , &eleccion);
if(eleccion == 0){
	MenuEdicion(temas);
}
return eleccion;
}

void BorradoDePreguntas(Tema *temas){
	char numeroTema;
	char etema[10];
	char eleccionP;
	char eleccion;
	int tamanyoP = contarLineas("pregunta.txt");
	Pregunta *preguntas = (Pregunta*) malloc(sizeof(Pregunta)*(contarLineas("pregunta.txt")/2));
	iniciarPreguntas(preguntas, "pregunta.txt", 2, 30, 30, 30, 30, 30, tamanyoP );
	printf("------------------------------------------------------------------- \n");
	printf("BORRAR PREGUNTA \n");
	printf("Pulsa q para salir. \n");
	printf("Elige el tema donde esta la pregunta. \n");
	//Lista de temas.
	int tamanyo = contarLineas("tema.txt");
		int i = 0;
		while (i < tamanyo){
			printf("%i. %s\n", i+1, temas[i].nombre);
			i++;
		}
	printf("NOMBRE del tema: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%s" ,etema);

	if(etema[0] == 'q'){
		MenuEdicion(temas);
	} else {

		printf("El tema elegido es: %s \n", etema);
		//Saca cual es el codigo que concuerda con ese tema
		FILE* f;
			int tamanyo = contarLineas("tema.txt");
			char cod[3];
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


		//GuardaTema
	}

	printf("Elige la pregunta que quieras borrar. \n");
	//Listado de preguntas de ese tema.
	eleccionP = ListadoDePreguntas(temas, preguntas);

	if(eleccion == 'q'){
		MenuEdicion(temas);
	} else {
		printf("\n Has elegido la pregunta numero: %c \n" , eleccionP);
	}
	printf("Pulsa q para salir, p para confirmar: ");
	fflush(stdin);
	fflush(stdout);
	scanf( "%c", &eleccion);

	switch(eleccion){
	case 'q' :
		MenuEdicion(temas);
		break;
	case 'p' :
		//Borrar
		printf("La pregunta se ha borrado correctamente, reiniciando para guardar... \n");
		break;
	}

}



void AjustesDeTrivial(Tema *temas){
	    int eleccion = 0;
	    FILE* f;

	    printf("------------------------------------------------------------------- \n");
	    printf("AJUSTES DEL TRIVIAL \n");


	    f = fopen("tema.txt", "r");

	    printf("Temas: \n");
	    int tamanyo = contarLineas("tema.txt");
	    int i = 0;
	    while (i < tamanyo){
	        printf("%i. %s\n", i+1, temas[i].nombre);
	        i++;
	    }
	    fclose(f);
	    printf("Selecciona el número del tema cuya disponibilidad deseas cambiar: ");
	    fflush(stdin);
	    fflush(stdout);
	    scanf( "%i", &eleccion);

	    f = fopen("tema.txt", "w");
	        i = 0;
	        for(i = 0; i < tamanyo; i++){
	            if(i != (eleccion-1)){
	                fprintf(f,"%c",temas[i].cod[0]);
	                fprintf(f,"%c",temas[i].cod[1]);
	                fprintf(f,"%c",temas[i].actT);
	                fprintf(f,"%s\n",temas[i].nombre);
	            }else{

	                fprintf(f,"%c",temas[i].cod[0]);
	                fprintf(f,"%c",temas[i].cod[1]);
	                if(temas[i].actT == '0'){
	                fprintf(f,"1");
	                }else{
	                fprintf(f,"0");
	                }

	                fprintf(f,"%s\n",temas[i].nombre);

	            }
	        }

	    fclose(f);
	    printf("Reiniciando para guardar los cambios...");



}




