#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "pila.h"

int main()
{
/** DECLARACIÓN DE VARIABLES **/

    Pila origen;
    Pila auxOrigen;
    Pila auxRecep;
    char continua = 's';

    inicpila(&origen);
    inicpila(&auxOrigen);
    inicpila(&auxRecep);

/* ------------------------------------------ */

    do{
        system("cls");

        printf("\t\t\t EJERCICIO 12 - PILAS AVANZADO \n\n");

        printf(" CARGANDO PILA... \n\n");
        leer(&origen);

        printf("\n %cQuieres continuar cargando la pila? s=SI / n=NO " , 168);
        fflush(stdin);
        continua = getch();

    }while(continua == 's');

    system("cls");

    printf(" PILA CARGADA \n");
    mostrar(&origen);

    while(!pilavacia(&origen)){
        while(!pilavacia(&auxRecep) && tope(&origen) < tope(&auxRecep)){
            apilar(&auxOrigen , desapilar(&auxRecep));
        }

        apilar(&auxRecep , desapilar(&origen));

        while(!pilavacia(&auxOrigen)){
            apilar(&auxRecep , desapilar(&auxOrigen));
        }
    }

    while(!pilavacia(&auxRecep)){
        apilar(&origen , desapilar(&auxRecep));
    }

    printf(" PILA ORDENADA POR INSERCI%cN \n" , 224);
    mostrar(&origen);

    return 0;
}
