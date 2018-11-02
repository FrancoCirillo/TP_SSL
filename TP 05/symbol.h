#ifndef DICCIONARIO
#define LARGO_ID 32
#define DICCIONARIO
struct Dicc {
	char lexema[LARGO_ID];
	int valor;
	struct Dicc *sig;
};

struct Dicc * insertar(struct Dicc **, char*, int);
void mostrarLista(struct Dicc *);
struct Dicc * buscarLexema(struct Dicc **, char[]);
int estaEnElDic(struct Dicc ** inicio, char nombreID[]);

#endif // DICCIONARIO

