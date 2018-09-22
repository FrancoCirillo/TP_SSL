#include "scanner_flex.h"
char *token_names[] = {"Fin de archivo", "Programa", "Fin", "Variables", "Codigo", "Definir", "Leer", "Escribir", "Asignacion", "Identificador", "Constante"};

int main() {
	enum token t;
	while ((t = yylex())){
		if (t<=CTE){
			if (t >= ID) printf("Token: %s\t\tLexema: %s\n", token_names[t], yytext);
			else printf("Token: %s\n", token_names[t]);
		}
		else printf("Token: %c\n", t);
	}
    printf("Token: %s\n", token_names[t]);
return 0;
}
