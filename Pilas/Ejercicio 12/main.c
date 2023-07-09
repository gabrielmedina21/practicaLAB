#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

int main()
{
/** DECLARACIÓN DE VARIABLES **/
    Pila modelo;
    Pila dada;
    Pila descarte;
    Pila auxModelo;
    Pila auxDada;
    int contModelo;
    int contDada;

    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&descarte);
    inicpila(&auxModelo);
    inicpila(&auxDada);

/* --------------------------------------------- */

    srand(time(NULL));

    for(contModelo=0 ; contModelo<5 ; contModelo++){
        apilar(&modelo , rand() % 10 + 1);
    }

    for(contDada=0 ; contDada<5 ; contDada++){
        apilar(&dada , rand() % 10 + 1);
    }

    printf(" PILA MODELO CARGADA \n");
    mostrar(&modelo);
    printf(" PILA DADA CARGADA \n");
    mostrar(&dada);


    while(!pilavacia(&modelo)){
        while(!pilavacia(&dada)){
            if(tope(&dada) == tope(&modelo)){
                apilar(&descarte , desapilar(&dada));
            }else{
                apilar(&auxDada , desapilar(&dada));
            }
        }

        while(!pilavacia(&auxDada)){
            apilar(&dada , desapilar(&auxDada));
        }

        apilar(&auxModelo , desapilar(&modelo));
    }

    printf(" Elementos eliminados de la pila DADA \n");
    mostrar(&descarte);

    printf(" Pila DADA actualizada \n");
    mostrar(&dada);

    return 0;
}
