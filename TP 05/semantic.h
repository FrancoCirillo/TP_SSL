#ifndef RUTINAS_SEM
#define RUTINAS_SEM

void declararID(struct Dicc ** inicio, char nombreID[]);
void asignarValor(struct Dicc ** inicio, char nombreID[], char* valorNuevo);
void leerID(struct Dicc ** inicio, char nombreID[]);
struct Dicc * declararTmp(struct Dicc ** inicio);
extern int cantTemporales;

void aplFuncion(struct Dicc ** inicio, char* operador, char* operando1, char* operando2, char* opGuardado);

void INV(struct Dicc ** inicio, char* operando1, char* opGuardado);
#endif // RUTINAS_SEM
