#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

int main()
{
/** DECLARACIÓN DE VARIABLES **/

    Pila dada;
    Pila auxDada;
    Pila ordenada;
    int menor = 0;
    int i;

    inicpila(&dada);
    inicpila(&auxDada);
    inicpila(&ordenada);

/* ------------------------------------- */
    printf(" EJERCICIO 6 - PILAS AVANZADO \n\n");

    srand(time(NULL));

    for(i=0 ; i<10 ; i++){
        apilar(&dada , rand() %50);
    }

    printf("\t\t\t PILA CARGADA ALEATORIAMENTE \n");
    mostrar(&dada);

    while(!pilavacia(&dada)){
        menor = desapilar(&dada);
        while(!pilavacia(&dada)){
            if(tope(&dada) < menor){
                apilar(&auxDada , menor);
                menor = desapilar(&dada);
            }else{
                apilar(&auxDada , desapilar(&dada));
            }
        }

         while(!pilavacia(&auxDada)){
            apilar(&dada , desapilar(&auxDada));
        }

        apilar(&ordenada , menor);
    }

    printf(" PILA ORDENADA POR SELECCI%cN \n" , 224);
    mostrar(&ordenada);

    return 0;
}
