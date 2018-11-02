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
		aumentarErrSeman();
	}
	else{
		printf("Decalre %s, Integer\n", nombreID); //Cambiar Integer por %s
		insertar(inicio, nombreID, 0); //Todas las variables se inicializan en 0
	}
}

void asignarValor(struct Dicc ** inicio, char nombreID[], int valorNuevo){
	if(estaEnElDic(inicio, nombreID)){
		buscarLexema(inicio, nombreID)->valor = valorNuevo;
	}
	else{
		yyerror(cargarOracion(buffer, "Error semantico: no se encontro declaracion de ", nombreID));
		aumentarErrSeman();
	}
}


void leerID(struct Dicc ** inicio, char nombreID[]){
	if(estaEnElDic(inicio, nombreID)){
		printf("Read %s, Integer\n", nombreID);
	}
	else{
		yyerror(cargarOracion(buffer, "Error semantico: no se encontro declaracion de ", nombreID));
		aumentarErrSeman();
	}
}
