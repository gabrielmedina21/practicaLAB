#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "pila.h"

int main()
{
    /** DECLARACION DE VARIABLES **/
    Pila dada;
    Pila auxDada1;
    Pila auxDada2;
    char continuar = 's';

    inicpila(&dada);
    inicpila(&auxDada1);
    inicpila(&auxDada2);


    /* ------------------------------------------- */

    do{
        system("cls");

        printf("\t\t\t EJERCICIO 5 - PILAS \n\n");

        printf(" CARGANDO PILA DADA... \n\n");

        leer(&dada);

        printf("\n %cQuieres continuar cargando la pila? s=SI / n=NO " , 168);
        fflush(stdin);
        continuar = getch();

    }while(continuar == 's' || continuar == 'S');

    system("cls");

    printf(" PILA DADA CARGADA \n");
    mostrar(&dada);

    while(!pilavacia(&dada)){
        apilar(&auxDada1 , desapilar(&dada));
    }

    while(!pilavacia(&auxDada1)){
        apilar(&auxDada2 , desapilar(&auxDada1));
    }

    while(!pilavacia(&auxDada2)){
        apilar(&dada , desapilar(&auxDada2));
    }

    printf(" PILA DADA INVERTIDA \n");
    mostrar(&dada);

    return 0;
}
