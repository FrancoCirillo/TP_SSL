%top{
#include <stdio.h>
#include "tokens_09.h"
}
%{
int identificadores = 0;
int constantes = 0;
int palabrasReservadas = 0;
int operadores = 0;
int caracteresPuntuacion = 0;
%}
%option outfile="09test.c"
L  [[:alpha:]]
D  [0-9]
LD [[:alnum:]]
S  [[:space:]]
O  [[:^alnum:]]{-}[[:space:]]
%%
programa palabrasReservadas++; return PRPROG;
variables palabrasReservadas++; return PRVAR;
codigo palabrasReservadas++; return PRCOD;
leer palabrasReservadas++; return PRLEER;
escribir palabrasReservadas++; return PRESC;
fin palabrasReservadas++; return PRFIN;
{L}{LD}* identificadores++; return ID;
{D}+ constantes++; return CTE;
"+" operadores++; return OPMAS;
"-" operadores++; return OPMENOS;
"*" operadores++; return OPPOR;
"/" operadores++; return OPDIV;
"<-" operadores++; return OPASIG;
"(" operadores++; return PARABRE;
")" operadores++; return PARCIERRA;
"," operadores++; return COMA;
"." operadores++; return PUNTO;
