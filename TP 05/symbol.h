#ifndef DICCIONARIO
#define LARGO_ID 32
#define LARGO_VALOR 16
#define DICCIONARIO
struct Dicc {
	char lexema[LARGO_ID];
	char valor[LARGO_VALOR];
	struct Dicc *sig;
};

struct Dicc * insertar(struct Dicc **, char*, char*);
void mostrarLista(struct Dicc *);
struct Dicc * buscarLexema(struct Dicc **, char[]);
int estaEnElDic(struct Dicc ** inicio, char nombreID[]);

#endif // DICCIONARIO

