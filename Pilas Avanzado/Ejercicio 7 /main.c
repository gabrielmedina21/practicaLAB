#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pila.h"

int main()
{
/** DECLARACIÓN DE VARIABLES **/

    Pila dada;
    Pila auxDada;
    int flag = 0;
    int numABuscar = 0;
    int i;

    inicpila(&dada);
    inicpila(&auxDada);

/* --------------------------------------- */

    srand(time(NULL));

    for(i=0 ; i<10 ; i++){
        apilar(&dada , rand() %50);
    }

    printf("\t\t\t EJERCICIO 7 - PILAS AVANZADO \n\n");

    printf(" Ingresar n%cmero a buscar: " , 163);
    scanf("%d" , &numABuscar);

    while(!pilavacia(&dada) && flag == 0){
        if(tope(&dada) == numABuscar){
            flag = 1;
        }else{
            apilar(&auxDada , desapilar(&dada));
        }
    }

    while(!pilavacia(&auxDada)){
        apilar(&dada , desapilar(&auxDada));
    }

    if(flag == 1){
        printf("\n El n%cmero %d se encuentra en la pila. \n" , 163 , numABuscar);
        mostrar(&dada);
    }else{
        printf("\n El n%cmero %d no se encuentra en la pila. \n" , 163 , numABuscar);
    }

    return 0;
}
