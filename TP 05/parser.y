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
todo	: mini { if (yynerrs || yylexerrs || errSeman) YYABORT; else YYACCEPT; parar();}
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
		| ESC '(' expresiones ')'
		| ID ASIG expresion  {asignar(&diccionario, $ID, $expresion); $ID = $expresion;}
		| error
		; 
identificadores: identificadores ',' ID {leerID(&diccionario, $ID);}
		| ID {leerID(&diccionario, $ID);}
		;
expresiones: expresiones ',' expresion {escribirExp(&diccionario, $1);}
		| expresion  {escribirExp(&diccionario, $1);}
		;
expresion: expresion '+' expresion {$$ = aplFuncion(&diccionario, "ADD", $1, $3, declararTmp(&diccionario, $$)->lexema);}	
		| expresion '-' expresion {$$ = aplFuncion(&diccionario, "SUBS", $1, $3, declararTmp(&diccionario, $$)->lexema);}	
		| expresion '*' expresion {$$ = aplFuncion(&diccionario, "MULT", $1, $3, declararTmp(&diccionario, $$)->lexema);}
		| expresion '/' expresion {$$ = aplFuncion(&diccionario, "DIV", $1, $3, declararTmp(&diccionario, $$)->lexema);}
		| CTE
		| '(' expresion ')' 
		| ID
		| '-' expresion %prec NEG  {$$ = aplFuncion(&diccionario, "INV", $2, "", declararTmp(&diccionario, $$)->lexema);}	
		;

%%

