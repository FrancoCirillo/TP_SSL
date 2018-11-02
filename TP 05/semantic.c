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
#include "errores.h"

void declararID(struct Dicc ** inicio, char nombreID[]){
	if(estaEnElDic(inicio, nombreID)){
		yyerror(cargarOracion(buffer, "Error semantico: no se pude volver a declarar ", nombreID));
//		printf("No se pudo declarar '%s', ya estaba declarado\n",nombreID);
	}
	else{
		printf("Decalre %s, Integer\n", nombreID);
		insertar(inicio, nombreID, 0); //Todas las variables se inicializan en 0
	}
}

void asignarValor(struct Dicc ** inicio, char nombreID[], int valorNuevo){
	if(estaEnElDic(inicio, nombreID)){
		buscarLexema(inicio, nombreID)->valor = valorNuevo;
	}
	else{
		printf("La variable %s no esta declarada",nombreID);
	}
}
