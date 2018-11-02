/*
 * Rutinas semanticas 
 * Cuando haya errores semanticos usar YYERROR para dejar de analizar sintácticamente la sentencia o rutina donde ocurrió el error
 * No usar yyerrorok


*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"

void declararID(char* nombreID, int valor);

struct Dicc *inicio = NULL;

int main(){
	insertar(inicio, "bueno", 5);
	insertar(inicio, "tamosBien", 25);
	insertar(inicio, "algo", 15);
	insertar(inicio, "anuel", 15);
//	struct Dicc * encontrado = buscarLexema(inicio, "algo");
	mostrarLista(inicio);
	puts("A VERRRRR");
	return 0;
}
