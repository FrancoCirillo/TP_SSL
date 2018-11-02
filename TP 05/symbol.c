//Rutinas que manejan el Diccionario
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"

void mostrarLista(struct Dicc *inicio) {

	struct Dicc *ptr = inicio;

	printf("\n[inicio] =>");
	while(ptr != NULL) {        
	  printf(" %s, %d =>",ptr->lexema, ptr->valor);
	  ptr = ptr->sig;
	}
	printf(" [null]\n");
}

struct Dicc * insertar(struct Dicc ** inicio, char *lex, int valor) {
	struct Dicc *link = (struct Dicc*) malloc(sizeof(struct Dicc));

	strncpy(link->lexema, lex, sizeof(link->lexema));
	link->lexema[15] = '\0';
	link->valor = valor;
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
