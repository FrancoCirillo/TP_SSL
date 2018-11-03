#ifndef RUTINAS_SEM
#define RUTINAS_SEM

void declararID(struct Dicc ** inicio, char nombreID[]);
void asignarValor(struct Dicc ** inicio, char nombreID[], char* valorNuevo);
void leerID(struct Dicc ** inicio, char nombreID[]);
struct Dicc * declararTmp(struct Dicc ** inicio, char* valorNuevo);
extern int cantTemporales;

char* aplFuncion(struct Dicc ** inicio, char* operador, char* operando1, char* operando2, char* opGuardado);

#endif // RUTINAS_SEM
