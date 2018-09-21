%top{
#include <stdio.h>
#include "tokens.h"
}
%{
int identificadores = 0;
int constantes = 0;
int palabrasReservadas = 0;
int operadores = 0;
int caracteresPuntuacion = 0;
int errores =0;
%}
%option outfile="scanner.c"
L  [[:alpha:]]
D  [0-9]
LD [[:alnum:]]
S  [[:space:]]
O  [[:^alnum:]]{-}[[:space:]()+\-*/,.]|<-
%%
programa palabrasReservadas++; return PRPROG;
variables palabrasReservadas++; return PRVAR;
codigo palabrasReservadas++; return PRCOD;
definir palabrasReservadas++; return PRDEF; 
leer palabrasReservadas++; return PRLEER;
escribir palabrasReservadas++; return PRESC;
fin palabrasReservadas++; return PRFIN;
{L}{LD}* identificadores++; return ID;
{D}+ constantes++; return CTE;
"+" operadores++; return '+';
"-" operadores++; return '-';
"*" operadores++; return '*';
"/" operadores++; return '/';
"<-" operadores++; return ASIG;
"(" caracteresPuntuacion++; return '(';
")" caracteresPuntuacion++; return ')';
"," caracteresPuntuacion++; return ',';
"." caracteresPuntuacion++; return '.';
{O}+ errores++; printf("Error Léxico:\t\t\t\tValor: %s\n", yytext);
{S}+    	/*ignorar*/
"//".* /*ignorar*/
%%

char *token_names[] = {"Fin de archivo", "Programa", "Fin", "Variable", "Codigo","Definir", "Leer", "Escribir","Asignacion", "Identific", "Constante"};
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
