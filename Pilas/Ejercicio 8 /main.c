#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "pila.h"

int main()
{
    /** DECLARACIÓN DE VARIABLES **/
    Pila mazo;
    Pila jugador1;
    Pila jugador2;
    int i;
    int cantCartas = 0;
    int cont = 0;

    inicpila(&mazo);
    inicpila(&jugador1);
    inicpila(&jugador2);

    /* ----------------------------------------- */

    srand(time(NULL)); /* cada vez que se ejecuta, se resetea el punto de partida al momento de generar números aleatorios */

    printf("\t\t\t EJERCICIO 8 - PILAS \n\n");

    printf(" Ingresar cantidad de cartas del mazo: ");
    scanf("%d" , &cantCartas);

    for(i=0 ; i<cantCartas ; i++){
        apilar(&mazo , rand() %12 + 1); /* apila numeros del 1 al 12 de forma aleatoria en la pila MAZO */
    }

    system("cls");

    printf("\n Mazo de %d cartas: \n" , cantCartas);
    mostrar(&mazo);

    while(!pilavacia(&mazo)){
        apilar(&jugador1 , desapilar(&mazo));

        if(!pilavacia(&mazo)){
            apilar(&jugador2 , desapilar(&mazo));
        }
    }

    for(cont = 0; cont<4 ; cont++){
        Sleep(820);
        printf(" Repartiendo....... \n");

    }

    system("cls");

    printf(" Cartas del JUGADOR 1: \n");
    mostrar(&jugador1);
    printf(" Cartas del JUGADOR 2: \n");
    mostrar(&jugador2);

    return 0;
}
