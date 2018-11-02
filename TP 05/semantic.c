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

void declararID(struct Dicc ** inicio, char nombreID[], int valor){
	if(estaEnElDic(inicio, nombreID)){
		printf("%s ya estaba declarado\n",nombreID);
	}
	else{
		insertar(inicio, nombreID, valor);
	}
}
