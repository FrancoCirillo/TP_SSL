/*

TP04- 2018


Grupo 04:

Cirillo, Franco         1636182
Díaz Pereyra, Mariano   1635037
García, Victoria        1644105
Seijo, Federico         1642121

*/

#include <stdio.h>
#include "parser_bison.h"
#include "scanner_flex.h"

int yylexerrs = 0;

int main() {
	switch( yyparse() ){
	case 0:
		puts("Compilacion terminada con exito"); break;
	case 1:
		puts("Errores de compilacion"); break;
	case 2:
		puts("Memoria insuficiente"); break;
	}
	printf("Errores sintacticos: %d - Errores lexicos: %d \n", yynerrs, yylexerrs);
	return 0;
}

void yyerror(const char *s){
	printf("línea #%d: %s\n", yylineno, s);
	return;
}
