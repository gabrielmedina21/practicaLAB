#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "pila.h"

int main()
{
    /** DECLARACIÓN DE VARIABLES **/
    Pila dada,aux1,aux2;
    int i;

    inicpila(&dada);
    inicpila(&aux1);
    inicpila(&aux2);

    /* ---------------------------------------------- */

    printf("\t\t\t EJERCICIO 1 - PILAS \n\n");

    for(i=0 ; i<5 ; i++){
        system("cls");
        printf(" Cargando la pila DADA.... \n\n");
        leer(&dada);
    }

    system("cls");

    printf(" PILA DADA CARGADA.... \n");
    mostrar(&dada);

    i = 0; /* reseteamos el contador a 0 */

    while(!pilavacia(&dada) && i <= 5){

        if(i < 3 && !pilavacia(&dada)){
            apilar(&aux1 , desapilar(&dada)); /* apilamos los primeros 3 elementos a aux1 */
        }else{
            apilar(&aux2 , desapilar(&dada)); /* apilamos los otros 2 elementos a aux2 */
        }

        i++;
    }

    printf(" PILA AUX 1... \n");
    mostrar(&aux1);
    printf(" PILA AUX 2... \n");
    mostrar(&aux2);
    printf(" PILA DADA... \n");
    mostrar(&dada);

    return 0;
}
