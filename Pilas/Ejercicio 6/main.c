#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "pila.h"

int main()
{
    /** DECLARACIÓN DE VARIABLES **/
    Pila dada;
    Pila topeDada;
    Pila auxDada;

    inicpila(&dada);
    inicpila(&topeDada);
    inicpila(&auxDada);

    /* ---------------------------------------------- */

    printf("\t\t\t EJERCICIO 6 - PILAS \n\n");

    apilar(&dada , 7);
    apilar(&dada , 5);
    apilar(&dada , 3);
    apilar(&dada , 2);
    apilar(&dada , 8);

    printf(" PILA DADA CARGADA \n");
    mostrar(&dada);

    apilar(&topeDada , desapilar(&dada));

    while(!pilavacia(&dada)){
        apilar(&auxDada , desapilar(&dada));
    }

    apilar(&dada , desapilar(&topeDada));

    while(!pilavacia(&auxDada)){
        apilar(&dada , desapilar(&auxDada));
    }

    printf(" PILA DADA \n");
    mostrar(&dada);

    return 0;
}
