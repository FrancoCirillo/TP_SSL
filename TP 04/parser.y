%code top{
#include <stdio.h>
#include "scanner_flex.h"
}
%code provides{
void yyerror(const char *);
extern int yylexerrs;
}
%defines "parser_bison.h"
%output "parser.c"
%token PROG FIN VAR COD DEF LEER ESC ASIG ID CTE
%define api.value.type {char *}
%define parse.error verbose

%%
todo	: mini { if (yynerrs || yylexerrs) YYABORT;}
mini 	: PROG programa FIN
		;
programa: VAR definiciones COD sentencias
		| VAR COD sentencias
		;
definiciones: DEF ID "." definiciones
		| DEF ID "."
		;
sentencias: sentencia "." sentencias
		| sentencia "."
		;
sentencia: LEER"(" identificadores ")"
		| ESC "(" expresiones ")"
		| ID "<-" expresion
		;
identificadores:| ID  "," identificadores
		| ID
		;
expresiones: expresion "," expresiones
		| expresion
		;
expresion: expresion "+" termino
		| expresion "-" termino
		| termino		
		;
termino	: termino "*" factor
		| termino "/" factor
		| factor
		;
factor:	CTE 
		| "(" expresion ")"
		| ID
		| "-" factor
		;
%%

int yylexerrs = 0;
int main() {
	switch( yyparse() ){
	case 0:
		puts("Pertenece al LIC"); return 0;
	case 1:
		puts("No pertenece al LIC"); return 1;
	case 2:
		puts("Memoria insuficiente"); return 2;
	}
	return 0;
}
/* Informa la ocurrencia de un error. */
void yyerror(const char *s){
	printf("línea #%d: %s\n", yylineno, s);
	return;
}
