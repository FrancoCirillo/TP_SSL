#ifndef ERRORES
#define ERRORES

char buffer[100];
void yyerror(const char *s);
const char* cargarOracion (char buffer[],char * tipoError, char* textoError);

#endif // ERRORES

