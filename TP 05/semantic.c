/*
 * Rutinas semanticas 
 * Cuando haya errores semanticos usar YYERROR para dejar de analizar sintácticamente la sentencia o rutina donde ocurrió el error
 * No usar yyerrorok


*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"
#include "semantic.h"

struct Dicc *inicio = NULL;

int main(){
	insertar(&inicio, "bueno", 5);
	insertar(&inicio, "tamosBien", 25);
	insertar(&inicio, "algo", 15);
	insertar(&inicio, "anuel", 15);
	declararID(&inicio, "SKEREEE", 666);
	mostrarLista(inicio);
	
	return 0;
}


void declararID(struct Dicc ** inicio, char nombreID[], int valor){
	struct Dicc * lugarDelLexema = buscarLexema(inicio, nombreID);
	if(lugarDelLexema == NULL){
		insertar(inicio, nombreID, valor);
	}
}
