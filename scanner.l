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
O  [[:^alnum:]]{-}[[:space:]]
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
"+" operadores++; return OPMAS;
"-" operadores++; return OPMEN;
"*" operadores++; return OPPOR;
"/" operadores++; return OPDIV;
"<-" operadores++; return OPASIG;
"(" caracteresPuntuacion++; return PARABRE;
")" caracteresPuntuacion++; return PARCIERRA;
"," caracteresPuntuacion++; return COMA;
"." caracteresPuntuacion++; return PUNTO;
{O}+ errores++; printf("Error Léxico:\t\tValor: %s\n", yytext);
{S}+    	/*ignorar*/
"//".* printf("Encontro un comentario\n", yytext);
%%

char *token_names[] = {"", "Identificador", "Constante Entera", "Programa", "Fin", "Variable", "Codigo","Definir", "Leer", "Escribir", "Mas", "Menos", "Por", "Dividir", "Asignacion", "Parentesis que abre", "Parentecis que cierra", "Coma", "Punto"};
int main() {
	enum token t;
	while ((t = yylex()))
		printf("Token: %s\t\t\tLexema: %s\n", token_names[t], yytext);
	puts("-------totales-------");
	printf("Identificadores: %d\nConstantes: %d\nPalabras Reservadas: %d\nOperadores: %d\nCaracteres de puntuacion: %d\nErrores: %d\n", identificadores, constantes, palabrasReservadas, operadores, caracteresPuntuacion,errores);
	return 0;
}
