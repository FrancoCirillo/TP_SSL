%top{
#include <stdio.h>
#include <strings.h>
#include "parser_bison.h"
#include "errores.h"
}
%option outfile="scanner.c"
%option header-file="scanner_flex.h"
%option noinput
%option nounput
%option yylineno

L  [[:alpha:]]
D  [0-9]
LD [[:alnum:]]
S  [[:space:]]
O  [[:^alnum:]]{-}[[:space:]()+\-*/,.]
%%
programa 	{return PROG;}
variables 	{return VAR;}
codigo 		{return COD;}
definir 	{return DEF;}
leer 		{return LEER;}
escribir 	{return ESC;}
fin 		{return FIN;}
{L}{LD}* 	{yylval = strdup(yytext);return ID;}
{D}+ 		{yylval = strdup(yytext);return CTE;}
"<-" 		{return ASIG;}
"+" 		{return '+';}
"-" 		{return '-';}
"*" 		{return '*';}
"/" 		{return '/';}
"(" 		{return '(';}
")" 		{return ')';}
"," 		{return ',';}
"." 		{return '.';}
{S}+    	;/*ignorar*/
"//".* 		;/*ignorar*/
{O}+ 		{yylexerrs++;yyerror(cargarOracion(buffer, "Error Léxico: Cadena desconocida: ", yytext));}
{D}+{L}+{LD}*	{yylexerrs++;yyerror(cargarOracion(buffer,"Error Léxico: Constante invalida: ", yytext));}
{L}{LD}*{O}+([^[:space:]()*+\-/,.])* {yylexerrs++; yyerror(cargarOracion(buffer,"Error Léxico: Identificador invalido: ",yytext));}
%%
