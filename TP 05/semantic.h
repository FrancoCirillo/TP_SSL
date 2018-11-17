#ifndef RUTINAS_SEM
#define RUTINAS_SEM

void declararID(char nombreID[]);
void asignarValor(char nombreID[], char* valorNuevo);
void leerID(char nombreID[]);
void escribirExp(char* expresion);
void asignar(char * id, char * expresion);
struct Dicc * declararTmp();
extern int cantTemporales;

char* aplFuncion(char* operador, char* operando1, char* operando2, char* opGuardado);

#endif // RUTINAS_SEM
