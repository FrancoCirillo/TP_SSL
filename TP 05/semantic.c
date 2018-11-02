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

struct Dicc * declararTmp(struct Dicc ** inicio){
	char nombreTemporal[16];
	sprintf(nombreTemporal, "Temporal#%d", cantTemporales);
	
	printf("Declare %s, Integer\n", nombreTemporal);
	insertar(inicio, nombreTemporal, "0");
	cantTemporales++;
	return * inicio;
}

void aplFuncion(struct Dicc ** inicio, char* operador, char* operando1, char* operando2, char* opGuardado){
	printf("%s %s,%s,%s\n", operador, operando1, operando2, opGuardado);
	
}

void INV(struct Dicc ** inicio, char* operando1, char* opGuardado){
	printf("INV %s, ,%s\n", operando1, opGuardado);
	asignarValor(inicio, opGuardado, operando1);
}
//~ void guardarTemporal(struct Dicc ** inicio, int valorAGuardar){
	//~ char nombreTemporal[100];
	//~ sprintf(nombreTemporal, "Temporal#%d", cantTemporales);
	//~ insertar(inicio, nombreTemporal, valorAGuardar);
	//~ printf("Declare %s, Integer\n", nombreTemporal);
	
//~ }
