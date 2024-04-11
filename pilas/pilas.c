#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "pilas.h"
#include "../funciones/funciones.h"
#include "../cola/lista.h"
#include "../nodo/nodo.h"

void push(Pilas *pila, void *dato) {
    AddTail(pila, dato);
}

void *pop(Pilas *pila) {
    void *copia = pila->tail->data;

    BorrarNodo(pila, pila->tail->data);
    return copia;
}


void ImprimirPila(Pilas *pila) {
    Pilas aux;
    IniciarListaDoble(&aux);

    void *dato = NULL;

    while (!estaVacia(pila)) {
        dato = pop(pila);
        printf("%s ", (char *)dato);
        push(&aux, dato);
    }

    printf("\n");

    while (!estaVacia(&aux)) {
        dato = pop(&aux);
        push(pila, dato);
    }
    LiberarLista(&aux);
}

int estaVacia(Pilas *pila)
{
    return pila->head == NULL;
   
       
}

int esNumeroTelefonoValido(ListaDoble *pila, char *numero_telefono) {
    int contador_espacios = 0;

    for (int i = 0; i < strlen(numero_telefono); i++) {
        if (numero_telefono[i] == ' ') {
            contador_espacios++;
            if (contador_espacios >= 2) {
                return 0;
            }
        }


    }
    return 1;
}



void LeerArchivo(Pilas *pila) {
    char num[100];
    FILE *file = fopen("numeros_telefono.txt", "r");
    if (file == NULL) {
        fputs("Error, no se puede abrir el archivo", stderr);
        exit(1);
    }
    while (fgets(num, sizeof(num), file)) {
        num[strcspn(num, "\n")] = 0;
        Pilas *nueva_pila = (Pilas *)malloc(sizeof(Pilas));
        if (nueva_pila == NULL) {
            printf("Error: No se pudo asignar memoria para la nueva pila\n");
            fclose(file);
            return;
        }
        IniciarListaDoble(nueva_pila);

        if (esNumeroTelefonoValido(nueva_pila, num)) {
            printf("%s: Es valido\n", num);
            AddHead(pila, nueva_pila);
        } else {
            printf("%s: No es valido\n", num);
            LiberarLista(nueva_pila);
            free(nueva_pila);
        }
    }
    fclose(file);
}



