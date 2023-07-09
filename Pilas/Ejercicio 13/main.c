#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

int main()
{
/** DECLARACIÓN DE VARIABLES **/

    Pila limite;
    Pila dada;
    Pila menores;
    Pila mayores;
    int i;

    inicpila(&limite);
    inicpila(&dada);
    inicpila(&menores);
    inicpila(&mayores);

/* ----------------------------------------------------- */
    printf("\t\t\t EJERCICIO 13 - PILAS \n\n");

    srand(time(NULL));

    apilar(&limite , rand() % 50);

    for(i=0 ; i<10 ; i++){
        apilar(&dada , rand() % 50);
    }

    printf(" PILA LIMITE CARGADA \n");
    mostrar(&limite);
    printf(" PILA DADA CARGADA \n");
    mostrar(&dada);

    while(!pilavacia(&dada)){
        if((tope(&dada) > tope(&limite)) || tope(&dada) == tope(&limite)){
            apilar(&mayores , desapilar(&dada));
        }else{
            apilar(&menores , desapilar(&dada));
        }
    }

    printf(" PILA MAYORES \n");
    mostrar(&mayores);
    printf(" PILA MENORES \n");
    mostrar(&menores);

    return 0;
}
