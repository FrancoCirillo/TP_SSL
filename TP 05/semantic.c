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


/*
int main(){
	declararID(&inicio, "bueno");
	declararID(&inicio, "tamosBien");
	declararID(&inicio, "algo");
	declararID(&inicio, "anuel");
	declararID(&inicio, "anuel");
	declararID(&inicio, "SKEREE");
	asignarValor(&inicio, "SKEREE", 666);
	asignarValor(&inicio, "algo", 77);
	mostrarLista(inicio);
	
	return 0;
}
*/


void declararID(struct Dicc ** inicio, char nombreID[]){
	if(estaEnElDic(inicio, nombreID)){
		printf("No se pudo declarar '%s', ya estaba declarado\n",nombreID);
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
