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

int cantTemporales = 1;

void declararID(struct Dicc ** inicio, char nombreID[]){
	if(estaEnElDic(inicio, nombreID)){
		yyerror(cargarOracion(buffer, "Error semantico: no se pude volver a declarar ", nombreID));
		aumentarErrSeman();
	}
	else{
		printf("Decalre %s, Integer\n", nombreID); //Cambiar Integer por %s
		insertar(inicio, nombreID, "0"); //Todas las variables se inicializan en 0
	}
}

void asignarValor(struct Dicc ** inicio, char nombreID[], char* valorNuevo){
	if(estaEnElDic(inicio, nombreID)){
		strncpy(buscarLexema(inicio, nombreID)->valor, valorNuevo, sizeof(buscarLexema(inicio, nombreID)->valor)); //Escribirlo bien
		buscarLexema(inicio, nombreID)->valor[LARGO_VALOR-1] = '\0';
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

void escribirExp(struct Dicc ** inicio, char * expresion){
		printf("Write %s, Integer\n", expresion);
}

void asignar(struct Dicc ** inicio, char * id, char * expresion){
		printf("Store %s,%s\n", expresion,id);
}

struct Dicc * declararTmp(struct Dicc ** inicio, char* valorNuevo){ //declararTmp no es el mejor nombre. quizas InicializarTMP
	char nombreTemporal[16];
	sprintf(nombreTemporal, "Temp#%d", cantTemporales);
	declararID(inicio, nombreTemporal);
	asignarValor(inicio, nombreTemporal, valorNuevo);
	cantTemporales++;
	return * inicio;
}

char* aplFuncion(struct Dicc ** inicio, char* operador, char* operando1, char* operando2, char* opGuardado){
	printf("%s %s,%s,%s\n", operador, operando1, operando2, opGuardado);
	return opGuardado;
}

void parar(){
	puts("Stop");
	}
