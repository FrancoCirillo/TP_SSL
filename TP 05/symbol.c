//Rutinas que manejan el Diccionario
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"

struct Dicc *inicio = NULL;

int main(){
	insertar("bueno", 5);
	insertar("tamosBien", 25);
	insertar("algo", 15);
	insertar("anuel", 15);
	struct Dicc * encontrado = buscarLexema(inicio, "algo");
	mostrarLista(encontrado);
	
	return 0;
}

void mostrarLista(struct Dicc *inicio) {

	struct Dicc *ptr = inicio;

	printf("\n[inicio] =>");
	while(ptr != NULL) {        
	  printf(" %s, %d =>",ptr->lexema, ptr->valor);
	  ptr = ptr->sig;
	}

	printf(" [null]\n");
}

void insertar(char *lex, int valor) {
	struct Dicc *link = (struct Dicc*) malloc(sizeof(struct Dicc));

	strncpy(link->lexema, lex, sizeof(link->lexema));
	link->lexema[9] = '\0';
	link->valor = valor;

	link->sig = inicio;
	inicio = link;
}

struct Dicc * buscarLexema(struct Dicc *lista, char word[]){
	struct Dicc *ptr = lista;
    while (ptr!=NULL && strcmp(ptr->lexema, word) != 0){
        ptr = ptr->sig;
    }

    return ptr; // Si no lo encontro retorna NULL, si no retorna el puntero al lexema
}
