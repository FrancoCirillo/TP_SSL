#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser_bison.h"
#include "scanner_flex.h"
#include "symbol.h"
#include "semantic.h"
#include "errores.h"

int cantTemporales = 1;

void declararID(char nombreID[]){
	if(buscarLexema(nombreID)!=NULL){
		yyerror(cargarOracion(buffer, "Error semantico: no se pude volver a declarar ", nombreID));
		errSeman++;;
	}
	else{
		printf("Decalre %s, Integer\n", nombreID); //Cambiar Integer por %s
		insertar(nombreID);
	}
}

void leerID(char nombreID[]){
	if(buscarLexema(nombreID)!=NULL){
		printf("Read %s, Integer\n", nombreID);
	}
	else{
		yyerror(cargarOracion(buffer, "Error semantico: no se encontro declaracion de ", nombreID));
		errSeman++;;
	}
}

void escribirExp(char * expresion){
		printf("Write %s, Integer\n", expresion);
}

void asignar(char * id, char * expresion){
		printf("Store %s,%s\n", expresion,id);
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


