#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "pila.h"

int main()
{
/** DECLARACIÓN DE VARIABLES **/

    Pila modelo;
    Pila dada;
    Pila descarte;
    Pila auxDada;
    char continuar = 's';

    inicpila(&modelo);
    inicpila(&dada);
    inicpila(&descarte);
    inicpila(&auxDada);

/* -------------------------------------------------- */

    apilar(&modelo , 55);
    apilar(&modelo , 6);
    apilar(&modelo , 1);
    apilar(&modelo , 9);
    apilar(&modelo , 23);
    apilar(&modelo , 3);

    do{
        system("cls");

        printf("\t\t\t EJERCICIO 11 - PILAS \n\n");

        printf(" CARGANDO PILA DADA... \n\n");
        leer(&dada);
        printf("\n %cQuieres continuar cargando la pila? s=SI / n=NO " , 168);
        continuar = getch();

    }while(continuar == 's' || continuar == 'S');

    system("cls");

    printf(" PILA MODELO CARGADA \n");
    mostrar(&modelo);
    printf(" PILA DADA CARGADA \n");
    mostrar(&dada);

    while(!pilavacia(&dada)){
        if(tope(&modelo) == tope(&dada)){
            apilar(&descarte , desapilar(&dada));
        }else{
            apilar(&auxDada , desapilar(&dada));
        }
    }

    while(!pilavacia(&auxDada)){
        apilar(&dada , desapilar(&auxDada));
    }

    printf(" PILA DADA ACTUALIZADA \n");
    mostrar(&dada);

    return 0;
}
