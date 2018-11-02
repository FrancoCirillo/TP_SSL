#include <stdio.h>
#include <string.h>
#include "scanner_flex.h"
#include "errores.h"

void yyerror(const char *s){
	printf("línea #%d: %s\n", yylineno, s);
	return;
}

const char* cargarOracion (char buffer[],char * tipoError, char* textoError){
		sprintf(buffer, "%s%s", tipoError, textoError);
		return buffer;
}

void aumentarErrSeman(){errSeman++;}
