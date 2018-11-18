#ifndef RUTINAS_SEM
#define RUTINAS_SEM

void declararID(char nombreID[]);
void asignarValor(char nombreID[], char* valorNuevo);
void leerID(char nombreID[]);
void escribirExp(char* expresion);
void asignar(char * id, char * expresion);
void empezar();
void terminar();
struct Dicc * declararTmp();
extern int cantTemporales;
int validarID(char* id);
int verificarID(char* id);
char* aplFuncion(char* operador, char* operando1, char* operando2, char* opGuardado);

void generar(char* funcion, char* ident);
#endif // RUTINAS_SEM

