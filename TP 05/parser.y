%code top{
#include <stdio.h>
#include "scanner_flex.h"
#include "symbol.h"
#include "semantic.h"
#include "errores.h"
}
%code provides{
void yyerror(const char *);
extern int yylexerrs;
int yynerrs;
struct Dicc * diccionario;
}
%defines "parser_bison.h"
%output "parser.c"
%token PROG FIN VAR COD DEF LEER ESC ID CTE ASIG
%left '+' '-'
%left '/' '*'
%precedence NEG 
%define api.value.type {char *}
%define parse.error verbose

%%
todo	: mini { if (yynerrs || yylexerrs || errSeman) YYABORT; else YYACCEPT;}
mini 	: PROG programa FIN
		;
programa: VAR definiciones COD sentencias 
		| VAR COD sentencias
		;
definiciones: definiciones DEF ID '.' {declararID(&diccionario, $ID);}
		| DEF ID '.' {declararID(&diccionario, $ID);}
		| error '.'
		;
sentencias: sentencias sentencia '.'
		| sentencia '.'
		;
sentencia: LEER'(' identificadores ')'
		| ESC '(' expresiones ')' {printf("escribir\n");}
		| ID ASIG expresion {printf("asignacion\n");}
		| error
		; 
identificadores: identificadores ',' ID {leerID(&diccionario, $ID);}
		| ID {leerID(&diccionario, $ID);}
		;
expresiones: expresiones ',' expresion
		| expresion 
		;
expresion: expresion '+' expresion {printf("suma\n");}
		| expresion '-' expresion {printf("resta\n");}
		| expresion '*' expresion {printf("multiplicacion\n");}
		| expresion '/' expresion {printf("division\n");}
		| CTE 
		| '(' expresion ')' {printf("parentesis\n");}
		| ID
		| '-' expresion %prec NEG {printf("inversion\n");}		
		;

%%

