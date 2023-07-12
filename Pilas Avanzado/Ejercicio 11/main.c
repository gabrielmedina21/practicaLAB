#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

int main()
{
/** DECLARACIÓN DE VARIABLES **/

    Pila ordenada1;
    Pila ordenada2;
    Pila ordenadaFinal;

    inicpila(&ordenada1);
    inicpila(&ordenada2);
    inicpila(&ordenadaFinal);
  
/* -------------------------------------- */

    printf("\t\t\t EJERCICIO 11 - PILAS AVANZADO \n\n");

    apilar(&ordenada1 , 1);
    apilar(&ordenada1 , 3);
    apilar(&ordenada1 , 5);
    apilar(&ordenada1 , 7);
    apilar(&ordenada1 , 9);

    apilar(&ordenada2 , 2);
    apilar(&ordenada2 , 4);
    apilar(&ordenada2 , 6);
    apilar(&ordenada2 , 8);

    printf(" PILA ORDENADA 1 CARGADA \n");
    mostrar(&ordenada1);
    printf(" PILA ORDENADA 2 CARGADA \n");
    mostrar(&ordenada2);

    while(!pilavacia(&ordenada1) && !pilavacia(&ordenada2)){
        if(tope(&ordenada1) > tope(&ordenada2)){
            apilar(&ordenadaFinal , desapilar(&ordenada1));
        }else{
            apilar(&ordenadaFinal , desapilar(&ordenada2));
        }
    }

    if(!pilavacia(&ordenada1)){
        while(!pilavacia(&ordenada1)){
            apilar(&ordenadaFinal , desapilar(&ordenada1));
        }
    }else{
        while(!pilavacia(&ordenada2)){
            apilar(&ordenadaFinal , desapilar(&ordenada2));
        }
    }

    printf(" PILA ORDENADA FINAL \n");
    mostrar(&ordenadaFinal);

    return 0;
}
