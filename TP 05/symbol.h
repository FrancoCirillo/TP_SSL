#ifndef DiccIONARIO
#define DICCIONARIO
#define LARGO_ID 16
struct Dicc {
	char lexema[LARGO_ID];
	int valor;
	struct Dicc *sig;
};
#endif // DiccIONARIO


void insertar(char*, int);
void mostrarLista();
struct Dicc * buscarLexema(struct Dicc *lista, char word[]);
