#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser_bison.h"
#include "scanner_flex.h"
#include "symbol.h"
#include "semantic.h"
#include "errores.h"

int cantTemporales = 1;

int validarID(char* id){
	if(buscarLexema(id)!=NULL){
		yyerror(cargarOracion(buffer, "Error semantico: no se pude volver a declarar ", id));
		errSeman++;
		return 0;
	}
	return 1;
}

int verificarID(char* id){
	if(buscarLexema(id)!=NULL)	return 1;
	else{
		yyerror(cargarOracion(buffer, "Error semantico: no se encontro declaracion de ", id));
		errSeman++;
		return 0;
	}

}

void generar(char* funcion, char* ident, char* idObjetivo){
			printf("%s %s, %s, Integer\n", funcion, idObjetivo, ident);
}

void declararID(char nombreID[]){
		generar("Declare", nombreID, "");
		insertar(nombreID);
}

void leerID(char nombreID[]){
		generar("Read", nombreID, "");
}

void escribirExp(char * expresion){
	generar("Write", expresion, "");
}

void asignar(char * id, char * idObjetivo){
	generar("Store", id, idObjetivo);
}

struct Dicc * declararTmp(){ 
	char nombreTemporal[16];
	sprintf(nombreTemporal, "Temp#%d", cantTemporales);
	declararID(nombreTemporal);
	cantTemporales++;
	return diccionario;
}

char* aplFuncion(char* operador, char* operando1, char* operando2, char* opGuardado){
	printf("%s %s,%s,%s\n", operador, operando1, operando2, opGuardado);
	return opGuardado;
}
