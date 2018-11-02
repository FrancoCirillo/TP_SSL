#ifndef RUTINAS_SEM
#define RUTINAS_SEM

void declararID(struct Dicc ** inicio, char nombreID[]);
void asignarValor(struct Dicc ** inicio, char nombreID[], char* valorNuevo);
void leerID(struct Dicc ** inicio, char nombreID[]);
void declararTmp(struct Dicc ** inicio);
extern int cantTemporales;

void SUM(char* operando1, char* operando2, char* opGuardado);
#endif // RUTINAS_SEM
