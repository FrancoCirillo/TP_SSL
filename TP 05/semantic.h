#ifndef RUTINAS_SEM
#define RUTINAS_SEM

void declararID(struct Dicc ** inicio, char nombreID[]);
void asignarValor(struct Dicc ** inicio, char nombreID[], int valorNuevo);
void leerID(struct Dicc ** inicio, char nombreID[]);
void declararTmp(struct Dicc ** inicio);
extern int cantTemporales;

#endif // RUTINAS_SEM
