#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol.h"
#include "semantic.h"
#include "errores.h"

int cantTemporales = 1;

void empezar(){
	printf("load rtlib\n");
	}

void terminar(){
	printf("Stop\n");
	}

void generar(char* funcion, char* ident){
	printf("%s %s, Integer\n", funcion, ident);
}

int validarID(char* nombreID){
	if(buscarLexema(nombreID)!=NULL){
		yyerror(cargarOracion(buffer, "Error semantico: no se pude volver a declarar ", nombreID));
		errSeman++;
		return 0;
	}
	return 1;
}

int verificarID(char* nombreID){
	if(buscarLexema(nombreID)==NULL){
		yyerror(cargarOracion(buffer, "Error semantico: no se encontro declaracion de ", nombreID));
		errSeman++;
		return 0;
		}
	return 1;
}


void declararID(char nombreID[]){
	generar("Declare", nombreID);
		insertar(nombreID);
}

void leerID(char nombreID[]){
	generar("Read", nombreID);
}

void escribirExp(char * expresion){
	generar("Write", expresion);
}

void asignar(char * idObjetivo, char * id){
	printf("Store %s, %s\n", idObjetivo, id); // generear2(char* funcion, char * idObjetivo, char * id)??
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
