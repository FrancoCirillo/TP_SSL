#ifndef ERRORES
#define ERRORES


extern int errSeman;
char buffer[100];
void yyerror(const char *s);
const char* cargarOracion (char buffer[],char * tipoError, char* textoError);
void aumentarErrSeman();
#endif // ERRORES

