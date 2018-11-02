#ifndef DICCIONARIO
#define DICCIONARIO

struct Dicc {
	char lexema[16];
	int valor;
	struct Dicc *sig;
};

void insertar(struct Dicc *, char*, int);
void mostrarLista(struct Dicc *);
struct Dicc * buscarLexema(struct Dicc *lista, char word[]);

#endif // DICCIONARIO

