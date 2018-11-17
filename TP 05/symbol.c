#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"

struct Dicc* diccionario = NULL; 

struct Dicc * insertar(char *lex) {
	
	struct Dicc *link = (struct Dicc*) malloc(sizeof(struct Dicc));
	strncpy(link->lexema, lex, sizeof(link->lexema));
	link->lexema[LARGO_ID-1] = '\0';
	link->sig = diccionario;
	diccionario = link;
	
	return diccionario;
}

struct Dicc * buscarLexema(char lexBuscado[]){
	struct Dicc *ptr = diccionario;
    while (ptr!=NULL && strcmp(ptr->lexema, lexBuscado) != 0){
        ptr = ptr->sig;
    }
    return ptr;
}
