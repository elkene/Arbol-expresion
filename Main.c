#include <stdio.h>
#include <stdlib.h>
#include "nodo/nodo.h"
#include "funciones/funciones.h"
#include "cola/cola.h"


int main(int argc, char *argv[]) {
    NodoBinario *raiz = NULL;

    int valores[] = {100, 50, 25, 75, 150};
    for (int i = 0; i < sizeof(valores) / sizeof(valores[0]); i++) {
        ingresarElementoArbol(&raiz, &valores[i], comparar);
    }

    printf("Recorrido en preorden: ");
    imprimirPreOrden(raiz, imprimir_entero);
    printf("\n");

    printf("Recorrido en inorden: ");
    imprimirInOrden(raiz, imprimir_entero);
    printf("\n");

    printf("Recorrido en postorden: ");
    imprimirPostOrden(raiz, imprimir_entero);
    printf("\n");
    
    printf("Recorrido en nivel orden: ");
    imprimirNivelOrden(raiz, imprimir_entero);
    printf("\n");
    printf("Eliminar Nodo: ");

    int datoAEliminar = 25;
    if (eliminarNodo(&raiz, &datoAEliminar, comparar)) {
        printf("Nodo eliminado\n");
        imprimirPreOrden(raiz, imprimir_entero);
        printf("\n");
        imprimirInOrden(raiz, imprimir_entero);
        printf("\n");
        imprimirPostOrden(raiz, imprimir_entero);
        printf("\n");
        imprimirNivelOrden(raiz, imprimir_entero);

    } else {
        printf("Nodo no encontrado\n");
    }

  

    liberarArbol(raiz);
    
    return 0; 
}