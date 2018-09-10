%code top{
#include <stdio.h>
#include "scanner_flex.h""
}
%code provides{
void yyerror(const char *);
extern int yylexerrs;
}
%defines "scanner_bison.h"
%output "parser.c"
%token PROG FIN VAR COD DEF LEER ESC ASIG ID CTE
%define api.value.type {char *}
%define parse.error verbose

%%
todo	: mini { if (yynerrs || yylexerrs) YYABORT;}
mini : PRPROG programa PRFIN
	| listado lista
	;
lista	: palabras '!'
	| numeros '!'
	| error '!'
	;
palabras: PALABRA
	| palabras ',' PALABRA
	;
numeros	: NRO
	| numeros ',' NRO
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
