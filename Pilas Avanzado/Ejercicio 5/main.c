#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
/** DECLARACIÓN DE VARIBALES **/

    Pila dada;
    Pila auxDada;
    Pila numAInsertar;

    inicpila(&dada);
    inicpila(&auxDada);
    inicpila(&numAInsertar);

/* ------------------------------------- */
    printf("\t\t\t EJERCICIO 5 - PILAS AVANZADO \n\n");

    apilar(&dada , 5);
    apilar(&dada , 4);
    apilar(&dada , 3);
    apilar(&dada , 2);
    apilar(&dada , 1);

    printf(" PILA CARGADA ORDENADA \n");
    mostrar(&dada);

    printf(" Ingresar n%cmero a insertar: \n" , 163);
    leer(&numAInsertar);

    while((!pilavacia(&dada)) && (tope(&dada) < tope(&numAInsertar))){
        apilar(&auxDada , desapilar(&dada));
    }

    apilar(&dada , desapilar(&numAInsertar));

    while(!pilavacia(&auxDada)){
        apilar(&dada , desapilar(&auxDada));
    }

    printf("\n");
    system("pause");
    system("cls");

    printf("\n PILA ACTUALIZADA \n");
    mostrar(&dada);

    return 0;
}
