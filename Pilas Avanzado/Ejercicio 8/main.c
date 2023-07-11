#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

int main()
{
/** DECLARACIÓN DE VARIABLES **/

    Pila dada;
    Pila auxDada;
    Pila descarte;
    int numAEliminar = 0;
    int i;

    inicpila(&dada);
    inicpila(&auxDada);
    inicpila(&descarte);

/* ------------------------------------ */

    printf("\t\t\t EJERCICIO 8 - PILAS AVANZADO \n\n");

    srand(time(NULL));

    for(i=0 ; i<10 ; i++){
        apilar(&dada , rand() %100);
    }

    printf(" PILA CARGADA ALEATORIAMENTE \n");
    mostrar(&dada);

    printf(" Ingresar n%cmero a eliminar: " , 163);
    scanf("%d" , &numAEliminar);

    if(!pilavacia(&dada)){
        while(!pilavacia(&dada)){
            if(tope(&dada) == numAEliminar){
                apilar(&descarte , desapilar(&dada));
            }else{
                apilar(&auxDada , desapilar(&dada));
            }
        }

        while(!pilavacia(&auxDada)){
            apilar(&dada , desapilar(&auxDada));
        }

        printf("\n PILA ACUTALIZADA \n");
        mostrar(&dada);
    }

    return 0;
}
