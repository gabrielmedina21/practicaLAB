#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
#include "pila.h"

int main()
{
/** DECLARACIÓN DE VARIABLES **/

    Pila dada;
    Pila menor;
    Pila auxDada;
    int i;

    inicpila(&dada);
    inicpila(&menor);
    inicpila(&auxDada);

/* ------------------------------------- */

    printf("\t\t\t EJERCICIO 4 - PILAS AVANZADO \n\n");

    srand(time(NULL));

    for(i=0 ; i<10 ; i++){
        apilar(&dada , rand() %100);
    }

    printf(" PILA CARGADA ALEATORIAMENTE \n");
    mostrar(&dada);

    apilar(&menor , desapilar(&dada));

    if(!pilavacia(&dada)){
        while(!pilavacia(&dada)){
            if(tope(&dada) < tope(&menor)){
                apilar(&auxDada , desapilar(&menor));
                apilar(&menor , desapilar(&dada));
            }else{
                apilar(&auxDada , desapilar(&dada));
            }
        }
    }

    while(!pilavacia(&auxDada)){
        apilar(&dada , desapilar(&auxDada));
    }

    printf(" El menor de la pila es: %d \n\n" , tope(&menor));

    return 0;
}
