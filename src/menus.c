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
	if( eleccion == 1){
			CreacionDeTema();
		}else if(eleccion == 2){
			//BorradoTema();
		}else if(eleccion == 3){
			ListadoDeTema();
		}else if(eleccion == 4){
			CreacionDePreguntas();
		}else if(eleccion == 5){
			//BorradoDePreguntas()
		}else if(eleccion == 6){
			EdicionDeTemas();
		}else if(eleccion == 7){
			//AjustesDeTrivial();
		}else if(eleccion == 8){
			MenuPrincipal();
		}
}

void CreacionDeTema(){
	char nombre[30];
	printf("------------------------------------------------------------------- \n");
	printf("CREACION DEL TEMA \n");
	printf("Pulsa q para salir. \n");
	printf("Nombre del tema: ");
	fflush(stdin);
	fflush(stdout);
	scanf( "%s", nombre);

	switch(nombre){
	case "q" :
		MenuEdicion();
		break;
	default:
		//Guardar Nombre en el fichero;
	}

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
	printf("2.Respuestas: \n");
	printf("3.Respuesta correcta a la pregunta: \n");
	printf("4.Guardar \n");
	printf("5.Cancelar: \n");
	printf("¿Que opción desea?: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &eleccion);
	if(eleccion == 1){
				Enunciado();
			}else if(eleccion == 2){
				Respuestas();
			}else if(eleccion == 3){
				//respuestacorrecta
			}else if(eleccion == 4){
				//Guardar
			}else if(eleccion == 5){
				MenuEdicion();
			}
}

void Enunciado(){
	char nombre[30];
	printf("------------------------------------------------------------------- \n");
	printf("ENUNCIADO: \n");
	printf("Pulsa q para salir. \n");
	printf("Texto: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%s" , nombre);

	switch(nombre){
	case "q" :
		MenuEdicion();
		break;
	default:
		//Guardar enunciado en el fichero;
	}
}

void Respuesta(){
	char respuesta1[30];
	char respuesta2[30];
	char respuesta3[30];
	char respuesta4[30];
	printf("------------------------------------------------------------------- \n");
	printf("RESPUESTAS: \n");
	printf("Respuesta A: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%s", respuesta1);
	printf("\n Respuesta A es: %s \n" , respuesta1);

	printf("Respuesta B: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%s", respuesta2);
		printf("\n Respuesta B es: %s \n" , respuesta2);

	printf("Respuesta C: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%s", respuesta3);
		printf("\n Respuesta C es: %s \n" , respuesta3);

	printf("Respuesta D: ");
		fflush(stdin);
		fflush(stdout);
		scanf("%s", respuesta4);
		printf("\n Respuesta D es: %s \n" , respuesta4);

	char nombre[30];
	//do{
	printf("Pulsa q para salir, p para confirmar: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%s", respuesta4);
	//}while( //comparacion para que sea o q o p);
	switch(nombre){
	case "q" :
		MenuEdicion();
		break;
	case "p" :
			//Guardar
			MenuEdicion();
			break;
	default:

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

}

void AñadirPreguntasATema(){

}

void ElegirPregunta(){

}


