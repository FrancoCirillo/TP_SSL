//Rutinas que manejan el Diccionario
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"

void mostrarLista(struct Dicc *inicio) {

	struct Dicc *ptr = inicio;

	printf("\n[inicio] =>");
	while(ptr != NULL) {        
	  printf(" %s, %s =>",ptr->lexema, ptr->valor);
	  ptr = ptr->sig;
	}
	printf(" [null]\n");
}

struct Dicc * insertar(struct Dicc ** inicio, char *lex, char* valorNuevo) {
	
	struct Dicc *link = (struct Dicc*) malloc(sizeof(struct Dicc));
	strncpy(link->lexema, lex, sizeof(link->lexema));
	link->lexema[LARGO_ID-1] = '\0';
	strncpy(link->valor, valorNuevo, sizeof(link->valor));
	link->valor[LARGO_VALOR-1] = '\0';
	link->sig = * inicio;
	* inicio = link;
	
	return * inicio;
}

struct Dicc * buscarLexema(struct Dicc **lista, char lexBuscado[]){
	struct Dicc *ptr = * lista;
    while (ptr!=NULL && strcmp(ptr->lexema, lexBuscado) != 0){
        ptr = ptr->sig;
    }
    return ptr; // Si no lo encontro retorna NULL, si no retorna el puntero al lexema
}

int estaEnElDic(struct Dicc ** inicio, char nombreID[]){
	if(buscarLexema(inicio, nombreID)==NULL) return 0;
	else return 1;
}
