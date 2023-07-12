#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include "pila.h"

int main()
{
/** DECLARACIOÓN DE VARIABLES **/

    Pila mazo;
    Pila jugador1;
    Pila jugador2;
    Pila puntosJug1;
    Pila puntosJug2;
    Pila aux;
    int i;
    int i2;
    int sumaPuntosJug1 = 0;
    int sumaPuntosJug2 = 0;

    inicpila(&mazo);
    inicpila(&jugador1);
    inicpila(&jugador2);
    inicpila(&puntosJug1);
    inicpila(&puntosJug2);
    inicpila(&aux);

/* ----------------------------------- */

    printf("\t\t\t EJERCICIO 13 - PILAS AVANZADO \n\n");

    srand(time(NULL));

    for(i=0 ; i<12 ; i++){
        apilar(&mazo , rand() %12 + 1);
    }

    printf(" MAZO \n");
    mostrar(&mazo);

    system("pause");
    printf("\n");

    for(i2=0 ; i2<4 ; i2++){
        printf(" Repartiendo... \n");
        Sleep(950);
    }

    while(!pilavacia(&mazo)){
        apilar(&jugador1 , desapilar(&mazo));
        apilar(&jugador1 , desapilar(&mazo));

        if(!pilavacia(&mazo)){
            apilar(&jugador2 , desapilar(&mazo));
            apilar(&jugador2 , desapilar(&mazo));
        }
    }

    system("cls");

    printf(" MANO DEL JUGADOR 1: \n");
    mostrar(&jugador1);

    printf(" MANO DEL JUGADOR 2: \n");
    mostrar(&jugador2);

    while(!pilavacia(&jugador1)){
        sumaPuntosJug1 += tope(&jugador1);
        apilar(&aux , desapilar(&jugador1));
    }

    while(!pilavacia(&jugador2)){
        sumaPuntosJug2 += tope(&jugador2);
        apilar(&aux , desapilar(&jugador2));
    }

    printf(" El puntaje total del jugador 1 es: %d \n" , sumaPuntosJug1);
    printf(" El puntaje total del jugador 2 es: %d \n" , sumaPuntosJug2);

    if(sumaPuntosJug1 > sumaPuntosJug2){
        printf("\n El ganador es el jugador 1. \n\n");

        while(!pilavacia(&aux)){
            apilar(&puntosJug1 , desapilar(&aux));
        }

        printf("\n PILA PUNTOS DEL JUGADOR 1: \n");
        mostrar(&puntosJug1);

    }else if(sumaPuntosJug2 > sumaPuntosJug1){
        printf("\n El ganador es el jugador 2 \n");

        while(!pilavacia(&aux)){
            apilar(&puntosJug2 , desapilar(&aux));
        }

        printf("\n PILA PUNTOS DEL JUGADOR 2: \n");
        mostrar(&puntosJug2);
    }else{
        printf("\n Ambos jungadores empataron, quien sea mano es el ganador. \n");

        while(!pilavacia(&aux)){
            apilar(&puntosJug1 , desapilar(&aux));
        }

        printf(" PILA PUNTOS DEL JUGADOR 1: \n");
        mostrar(&puntosJug1);
    }

    return 0;
}
