%top{
#include <stdio.h>
#include "tokens.h"
}
%option outfile="scanner.c"
%option header-file="scanner_flex.h"
%option noinput
%option nounput
L  [[:alpha:]]
D  [0-9]
LD [[:alnum:]]
S  [[:space:]]
O  [[:^alnum:]]{-}[[:space:]()+\-*/,.]
%%
programa 	return PRPROG;
variables 	return PRVAR;
codigo 		return PRCOD;
definir 	return PRDEF; 
leer 		return PRLEER;
escribir 	return PRESC;
fin 		return PRFIN;
{L}{LD}* 	return ID;
{D}+ 		return CTE;
"<-" 		return ASIG;
"+" 		return '+';
"-" 		return '-';
"*" 		return '*';
"/" 		return '/';
"(" 		return '(';
")" 		return ')';
"," 		return ',';
"." 		return '.';
{S}+    	/*ignorar*/
"//".* 		/*  ignorar*/
{O}+ printf("Error Léxico: Cadena desconocida: %s\n", yytext);
{D}+{L}+{LD}*	printf("Error Léxico:\t\t\tConstante invalida: %s\n", yytext);
{L}{LD}*{O}+([^[:space:]()+\-*/,.])* printf("Error Léxico:\t\t\tIdentificador invalido: %s\n", yytext);
