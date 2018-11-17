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
mini 	: PROG {puts("load rtlib");} programa FIN {puts("Stop");}
		;
programa: VAR definiciones COD sentencias 
		| VAR COD sentencias
		;
definiciones: definiciones DEF ID '.' {if(!validarID($ID))YYERROR;declararID($ID);}
		| DEF ID '.' {if(!validarID($1)) YYERROR;declararID($ID);}
		| error '.'
		;
sentencias: sentencias sentencia '.'
		| sentencia '.'
		;
sentencia: LEER'(' identificadores ')'
		| ESC '(' expresiones ')'
		| id ASIG expresion  {asignar($id, $expresion); $id= $expresion;}
		| error
		; 
identificadores: identificadores ',' id {leerID($id);}
		| id {leerID($id);}
		;
expresiones: expresiones ',' expresion {escribirExp($1);}
		| expresion  {escribirExp($1);}
		;
expresion: expresion '+' expresion {$$ = aplFuncion("ADD", $1, $3, declararTmp()->lexema);}	
		| expresion '-' expresion {$$ = aplFuncion("SUBS", $1, $3, declararTmp()->lexema);}	
		| expresion '*' expresion {$$ = aplFuncion("MULT", $1, $3, declararTmp()->lexema);}
		| expresion '/' expresion {$$ = aplFuncion("DIV", $1, $3, declararTmp()->lexema);}
		| CTE
		| '(' expresion ')' {$$ = $2;}
		| id
		| '-' expresion %prec NEG  {$$ = aplFuncion("INV", $2, "", declararTmp()->lexema);}	
		;
		
id		: ID {if(!verificarID($1)) YYERROR;}

		
%%

