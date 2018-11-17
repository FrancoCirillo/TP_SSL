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
todo	: mini { if (yynerrs || yylexerrs || errSeman) {YYABORT;} else {YYACCEPT;}}
mini 	: PROG programa FIN
		;
programa: VAR definiciones COD sentencias 
		| VAR COD sentencias
		;
definiciones: definiciones DEF ID '.' {declararID($ID);}
		| DEF ID '.' {declararID($ID);}
		| error '.'
		;
sentencias: sentencias sentencia '.'
		| sentencia '.'
		;
sentencia: LEER'(' identificadores ')'
		| ESC '(' expresiones ')'
		| ID ASIG expresion  {asignar($ID, $expresion); $ID = $expresion;}
		| error
		; 
identificadores: identificadores ',' ID {leerID($ID);}
		| ID {leerID($ID);}
		;
expresiones: expresiones ',' expresion {escribirExp($1);}
		| expresion  {escribirExp($1);}
		;
expresion: expresion '+' expresion {$$ = aplFuncion("ADD", $1, $3, declararTmp()->lexema);}	
		| expresion '-' expresion {$$ = aplFuncion("SUBS", $1, $3, declararTmp()->lexema);}	
		| expresion '*' expresion {$$ = aplFuncion("MULT", $1, $3, declararTmp()->lexema);}
		| expresion '/' expresion {$$ = aplFuncion("DIV", $1, $3, declararTmp()->lexema);}
		| CTE
		| '(' expresion ')' 
		| ID
		| '-' expresion %prec NEG  {$$ = aplFuncion("INV", $2, "", declararTmp()->lexema);}	
		;

%%

