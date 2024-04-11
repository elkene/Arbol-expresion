#include "../cola/lista.h"


typedef ListaDoble Pilas;

void push(Pilas *pila, void *dato);
void *pop(Pilas *pila);
int estaVacia(Pilas *pila);
void ImprimirPila(Pilas *pila);
