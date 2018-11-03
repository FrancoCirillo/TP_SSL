#ifndef RUTINAS_SEM
#define RUTINAS_SEM

void declararID(struct Dicc ** inicio, char nombreID[]);
void asignarValor(struct Dicc ** inicio, char nombreID[], char* valorNuevo);
void leerID(struct Dicc ** inicio, char nombreID[]);
void escribirExp(struct Dicc ** inicio, char* expresion);
void asignar(struct Dicc ** inicio, char * id, char * expresion);
struct Dicc * declararTmp(struct Dicc ** inicio, char* valorNuevo);
extern int cantTemporales;
void parar();

char* aplFuncion(struct Dicc ** inicio, char* operador, char* operando1, char* operando2, char* opGuardado);

#endif // RUTINAS_SEM
