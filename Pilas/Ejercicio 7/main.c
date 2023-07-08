#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "pila.h"

int main()
{
    /** DECLARACIÓN DE VARIABLES **/
    Pila dada;
    Pila baseDada;
    Pila auxDada;

    inicpila(&dada);
    inicpila(&baseDada);
    inicpila(&auxDada);

    /* ---------------------------------------------- */

    printf("\t\t\t EJERCICIO 6 - PILAS \n\n");

    apilar(&dada , 3);
    apilar(&dada , 2);
    apilar(&dada , 9);
    apilar(&dada , 6);
    apilar(&dada , 1);

    printf(" PILA DADA CARGADA \n");
    mostrar(&dada);

    while(!pilavacia(&dada)){
        apilar(&auxDada , desapilar(&dada));
    }

    apilar(&baseDada , desapilar(&auxDada));

    while(!pilavacia(&auxDada)){
        apilar(&dada , desapilar(&auxDada));
    }

    apilar(&dada , desapilar(&baseDada));

    printf(" PILA DADA \n");
    mostrar(&dada);

    return 0;
}
