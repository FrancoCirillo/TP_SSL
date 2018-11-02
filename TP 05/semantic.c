/*
 * Rutinas semanticas 
 * Cuando haya errores semanticos usar YYERROR para dejar de analizar sintácticamente la sentencia o rutina donde ocurrió el error
 * No usar yyerrorok


*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser_bison.h"
#include "scanner_flex.h"
#include "symbol.h"
#include "semantic.h"


struct Dicc *inicio = NULL;

int main(){
	declararID(&inicio, "bueno", 5);
	declararID(&inicio, "tamosBien", 25);
	declararID(&inicio, "algo", 15);
	declararID(&inicio, "anuel", 44);
	declararID(&inicio, "anuel", 11);
	declararID(&inicio, "SKEREE", 666);
	mostrarLista(inicio);
	
	return 0;
}


void declararID(struct Dicc ** inicio, char nombreID[], int valor){
	struct Dicc * lugarDelLexema = buscarLexema(inicio, nombreID);
	if(lugarDelLexema == NULL){
		insertar(inicio, nombreID, valor);
	}
	else{
		printf("%s ya estaba declarado\n",nombreID);
	}
}
