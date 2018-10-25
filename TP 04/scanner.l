%top{
#include <stdio.h>
#include <strings.h>
#include "parser_bison.h"
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
programa 	{yylval = strdup(yytext);return PROG;}
variables 	{yylval = strdup(yytext);return VAR;}
codigo 		{yylval = strdup(yytext);return COD;}
definir 	{yylval = strdup(yytext);return DEF;}
leer 		{yylval = strdup(yytext);return LEER;}
escribir 	{yylval = strdup(yytext);return ESC;}
fin 		{yylval = strdup(yytext);return FIN;}
{L}{LD}* 	{yylval = strdup(yytext);return ID;}
{D}+ 		{yylval = strdup(yytext);return CTE;}
"<-" 		{yylval = strdup(yytext);return ASIG;}
"+" 		{yylval = strdup(yytext);return '+';}
"-" 		{yylval = strdup(yytext);return '-';}
"*" 		{yylval = strdup(yytext);return '*';}
"/" 		{yylval = strdup(yytext);return '/';}
"(" 		{yylval = strdup(yytext);return '(';}
")" 		{yylval = strdup(yytext);return ')';}
"," 		{yylval = strdup(yytext);return ',';}
"." 		{return '.';}
{S}+    	;/*ignorar*/
"//".* 		;/*  ignorar*/
{O}+ 		{yylexerrs++;yyerror("Error Léxico: Cadena desconocida: ");printf("%s\n",yytext);}
{D}+{L}+{LD}*	{yylexerrs++;yyerror("Error Léxico: Constante invalida: ");printf("%s\n",yytext);}
{L}{LD}*{O}+([^[:space:]()*+\-/,.])* {yylexerrs++; yyerror("Error Léxico: Identificador invalido: ");printf("%s\n",yytext);}
%%
