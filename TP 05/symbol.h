#ifndef DICCIONARIO
#define LARGO_ID 32
#define LARGO_VALOR 16
#define DICCIONARIO
struct Dicc {
	char lexema[LARGO_ID];
	struct Dicc *sig;
};

extern struct Dicc* diccionario; 
struct Dicc * insertar(char*);
struct Dicc * buscarLexema(char[]);

#endif // DICCIONARIO

