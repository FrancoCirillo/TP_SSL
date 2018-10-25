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
%token PROG FIN VAR COD DEF LEER ESC ID CTE
%right ASIG
%left '+' '-'
%left '/' '*'
%precedence NEG 
%precedence '(' ')'
%define api.value.type {char *}
%define parse.error verbose

%%
todo	: mini { if (yynerrs || yylexerrs) YYABORT;}
mini 	: PROG programa FIN
		;
programa: VAR definiciones COD sentencias 
		| VAR COD sentencias
		;
definiciones: definiciones DEF ID '.' {printf("definir %s\n", $ID);}
		| DEF ID '.' {printf("definir %s\n", $ID);}
		| error '.'
		;
sentencias: sentencia '.' sentencias
		| sentencia '.'
		;
sentencia: LEER'(' identificadores ')' {printf("leer\n");}
		| ESC '(' expresiones ')' {printf("escribir\n");}
		| ID ASIG expresion {printf("asignacion\n");}
		| error
		; 
identificadores: ID  ',' identificadores
		| ID
		;
expresiones: expresion ',' expresiones 
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

