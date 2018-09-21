%top{
#include <stdio.h>
#include "tokens.h"
}
%option outfile="scanner.c"
L  [[:alpha:]]
D  [0-9]
LD [[:alnum:]]
S  [[:space:]]
O  [[:^alnum:]]{-}[[:space:]()+\-*/,.<]
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
"//".* 		/*ignorar*/
{O}+[^[:space:]()+\-*/,.]*	printf("Error Léxico:\t\t\t\t Cadena invalida: %s\n", yytext);
{D}+{LD}*{O}+([^[:space:]()+\-*/,.])*	printf("Error Léxico:\t\t\t Constante invalida: %s\n", yytext);
{L}{LD}*+{O}+([^[:space:]()+\-*/,.])* printf("Error Léxico:\t\t\t Identificador invalido: %s\n", yytext);
%%

char *token_names[] = {"Fin de archivo", "Programa", "Fin", "Variables", "Codigo", "Definir", "Leer", "Escribir", "Asignacion", "Identific", "Constante"};
int main() {
	enum token t;
	while ((t = yylex())){
		if (t<=CTE){
			if (t >= ID) printf("Token: %s\t\t\tLexema: %s\n", token_names[t], yytext);
			else printf("Token: %s\n", token_names[t]);
		}
		else printf("Token: %c\n", t);
	}
return 0;
}
