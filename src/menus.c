/*
 * menus.c
 *
 *  Created on: 7 abr. 2018
 *      Author: Lander
 */
#include <stdio.h>
#include "menus.h"
#include "utilidades.h"
#include "sqlite3.h"

void MenuPrincipal(Tema *temas, sqlite3 *db){
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
		MenuJugar(temas, db);
	}else if(eleccion == 2){
		MenuEdicion(temas, db);
	}else if(eleccion == 3){
		//cerrar el programa
	}
}

void MenuJugar(Tema *temas, sqlite3 *db){
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
		MenuPrincipal(temas, db);
	}

}

void MenuEdicion(Tema *temas, sqlite3 *db){
	int eleccion;

	printf("------------------------------------------------------------------- \n");
	printf("EDICIÓN \n");
	printf("1. Creación de tema \n");
	printf("2. Borrado de tema \n");
	printf("3. Listado de tema \n");
	printf("4. Creación de preguntas \n");
	printf("5. Borrado de preguntas \n");
	printf("6. Listado de Preguntas \n");
	printf("7. Ajustes de Trivial \n");
	printf("8. Atras \n");
	printf("¿Que opción desea?: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &eleccion);
	if(eleccion == 1){
		CreacionDeTema(temas, db);
	}else if(eleccion == 2){
		BorradoTema(temas, db);
	}else if(eleccion == 3){
		ListadoDeTema(temas, db);
	}else if(eleccion == 4){
		CreacionDePreguntas(temas, db);
	}else if(eleccion == 5){
		BorradoDePreguntas(temas, db);
	}else if(eleccion == 6){
		char eleccionC;
		Pregunta *preguntas = (Pregunta*) malloc(sizeof(Pregunta)*100);
		iniciarPreguntas(preguntas, db );
		printf("------------------------------------------------------------------- \n");
		printf("LISTADO DE PREGUNTAS \n");
		mostrarPreguntas(preguntas, db);
		printf("Pulse cualquier tecla (del alfabeto) para volver al menu de edición. \n");
		fflush(stdin);
		fflush(stdout);
		scanf("%c" , &eleccionC);
		MenuEdicion(temas, db);
		freePreguntas(preguntas);
	}else if(eleccion == 7){
		AjustesDeTrivial(temas, db);
	}else if(eleccion == 8){
		MenuPrincipal(temas, db);
	}
}

void CreacionDeTema(Tema *temas, sqlite3 *db){
	char* nombre = malloc(sizeof(char)*30);
	char eleccion[10];

	printf("------------------------------------------------------------------- \n");
	printf("CREACION DEL TEMA \n");
	printf("Pulsa q para salir. \n");
	printf("Nombre del tema: ");
	fflush(stdin);
	fflush(stdout);
	scanf( "%s", nombre);
	if(nombre[0] == 'q'){
		MenuEdicion(temas, db);
	} else {
		printf("Tu tema es: %s para confirmar pulse p ,para salir sin guardar pulse q. \n", nombre);
		fflush(stdin);
		fflush(stdout);
		scanf( "%s", eleccion);

		if(eleccion[0] == 'q'){
				MenuEdicion(temas, db);
		}else{
		//Guardar

		    crearTema(nombre);
			printf("Tu tema se ha guardado correctamente, reiniciando para guardar los cambios...");
			free(nombre);
			/*
			char* ficheroAct = "tema.txt";
			FILE* f;
			int tamanyo = contarLineas(ficheroAct);
			f = fopen(ficheroAct, "r");

			Tema *nuevosTemas =(Tema*) malloc(sizeof(Tema)*tamanyo);


			iniciarTemas(nuevosTemas, ficheroAct, 2, 10, tamanyo);


			fclose(f);
			//MenuEdicion(nuevosTemas);
			*/
		}
	}
}

void BorradoTema(Tema *temas, sqlite3 *db){
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
		MenuEdicion(temas, db);
	} else {
		printf("\nHas elegido el tema numero %i \n", opcion);
		printf("Pulsa q para salir, p para confirmar: ");
		fflush(stdin);
		fflush(stdout);
		scanf( "%c", &eleccion);

		switch(eleccion){
		case 'q' :
			MenuEdicion(temas, db);
			break;
		case 'p' :
			//Borrar tema seleccionado.
			borrarTema(opcion, temas);
			printf("El tema seleccionado se ha borrado correctamente, reiniciando para guardar cambios... \n");
			break;
		}
	}
}

void ListadoDeTema(Tema *temas, sqlite3 *db){
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
		MenuEdicion(temas, db);
	}

}

void CreacionDePreguntas(Tema *temas, sqlite3 *db){
	    Pregunta *pregunta = malloc(sizeof(Pregunta));
	    pregunta->cod = malloc(sizeof(char)*3);
	    pregunta->correcta = malloc(sizeof(char));
	    pregunta->enunciado = malloc(sizeof(char)*30);
	    pregunta->respuestaA = malloc(sizeof(char)*30);
	    pregunta->respuestaB = malloc(sizeof(char)*30);
	    pregunta->respuestaC = malloc(sizeof(char)*30);
	    pregunta->respuestaD = malloc(sizeof(char)*30);
		char etema[10];
		char* enunciado = malloc(sizeof(char)*30);
		char* respuesta1 = malloc(sizeof(char)*30);
		char* respuesta2 = malloc(sizeof(char)*30);
		char* respuesta3 = malloc(sizeof(char)*30);
		char* respuesta4 = malloc(sizeof(char)*30);

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
		MenuEdicion(temas, db);
	} else {

		printf("El tema elegido es: %s \n", etema);
		pregunta->cod = compararTemas(etema, temas);
		//GuardaTema

	printf("Siempre que se quiera poner un 'espacio' escribir '_'.\n");
	printf("Enunciado: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%s" , enunciado);

		printf("\nTu enunciado es: %s \n", enunciado);
		pregunta->enunciado = enunciado;
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
				pregunta->respuestaA = respuesta1;
				//Guardar respuesta1

			printf("Respuesta B: ");
			fflush(stdin);
			fflush(stdout);
			scanf("%s", respuesta2);

				printf("\nRespuesta B es: %s \n" , respuesta2);
				pregunta->respuestaB = respuesta2;
				//Guardar respuesta2

			printf("Respuesta C: ");
			fflush(stdin);
			fflush(stdout);
			scanf("%s", respuesta3);

				printf("\nRespuesta C es: %s \n" , respuesta3);
				pregunta->respuestaC = respuesta3;
				//Guardar respuesta3

			printf("Respuesta D: ");
			fflush(stdin);
			fflush(stdout);
			scanf("%s", respuesta4);

				printf("\nRespuesta D es: %s \n" , respuesta4);
				pregunta->respuestaD = respuesta4;
				//Guardar respuesta4

				char* respuestaCorrecta = malloc(sizeof(char));
			printf("------------------------------------------------------------------- \n");
				printf("RESPUESTA CORRECTA \n");
				printf("Letra: ");
				fflush(stdin);
				fflush(stdout);
				scanf("%c", respuestaCorrecta);

					printf("\nLa respuesta %c es la correcta. \n" , *respuestaCorrecta);
					pregunta->correcta = respuestaCorrecta;
					anyadirPregunta(pregunta, db);
					//Guardar respuesta correcta
				fflush(stdin);
				fflush(stdout);
				printf("Reiniciando para guardar los cambios...");
				free(pregunta->cod);
				free(pregunta->correcta);
				free(pregunta->enunciado);
				free(pregunta->respuestaA);
				free(pregunta->respuestaB);
				free(pregunta->respuestaC);
				free(pregunta->respuestaD);
	}
}


int ListadoDePreguntas(Tema *temas, Pregunta *preguntas, sqlite3 *db){
	int eleccion;
	printf("------------------------------------------------------------------- \n");
	printf("LISTADO DE PREGUNTAS \n");
	mostrarPreguntas(preguntas, db);

printf("Elección:\n");
fflush(stdin);
fflush(stdout);
scanf("%i" , &eleccion);
fflush(stdin);
fflush(stdout);
return eleccion;
}

void BorradoDePreguntas(Tema *temas, sqlite3 *db){
	int eleccionP;
	char eleccion;
	Pregunta *preguntas = (Pregunta*) malloc(sizeof(Pregunta)*100);
	iniciarPreguntas(preguntas, db );
	printf("------------------------------------------------------------------- \n");
	printf("BORRAR PREGUNTA \n");

	//modificar array de preguntas para que solo aparezcan las que tengan relacion con el tema
	//Listado de preguntas de ese tema.
	eleccionP = ListadoDePreguntas(temas, preguntas, db);

	if(eleccionP == 0){
		MenuEdicion(temas, db);
	} else {
		printf("\n Has elegido la pregunta numero: %i \n" , eleccionP);
	}
	printf("Pulsa q para salir, p para confirmar: ");
	fflush(stdin);
	fflush(stdout);
	scanf( "%c", &eleccion);

	switch(eleccion){
	case 'q' :
		MenuEdicion(temas, db);
		break;
	case 'p' :
		//Borrar
		borrarPregunta(preguntas[eleccionP-1].enunciado, db);
		printf("La pregunta se ha borrado correctamente, reiniciando para guardar... \n");
		freePreguntas(preguntas);
		break;
	}


}



void AjustesDeTrivial(Tema *temas, sqlite3 *db){
	    int eleccion = 0;
	    FILE* f;

	    printf("------------------------------------------------------------------- \n");
	    printf("AJUSTES DEL TRIVIAL \n");


	    f = fopen("tema.txt", "r");

	    printf("0. Atras.\n");
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
	    if(eleccion == 0){
	    	MenuEdicion(temas, db);
	    }else{
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

}




