#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "pila.h"

int main()
{
/** DECLARACIÓN DE VARIABLES **/

    Pila a;
    Pila b;
    Pila aux;
    char continuar = 's';

    inicpila(&a);
    inicpila(&b);
    inicpila(&aux);

/* ------------------------------------------- */

    do{
        system("cls");

        printf("\t\t\t EJERCICIO 10 - PILAS \n\n");

        printf(" CARGANDO PILA A... \n\n");
        leer(&a);
        printf("\n %cQuieres continuar cargando la pila? s=SI / n=NO " , 168);
        fflush(stdin);
        continuar = getch();

    }while(continuar == 's' || continuar == 'S');

    do{
        system("cls");

        printf("\t\t\t EJERCICIO 10 - PILAS \n\n");

        printf(" CARGANDO PILA B... \n\n");
        leer(&b);
        printf("\n %cQuieres continuar cargando la pila? s=SI / n=NO " , 168);
        fflush(stdin);
        continuar = getch();

    }while(continuar == 's' || continuar == 'S');

    system("cls");

    printf(" PILA A CARGADA \n");
    mostrar(&a);
    printf(" PILA B CARGADA \n");
    mostrar(&b);

    while((!pilavacia(&a) && !pilavacia(&b)) && (tope(&a) == tope(&b))){
        apilar(&aux , desapilar(&a));
        apilar(&aux , desapilar(&b));
    }

    if(pilavacia(&a) && pilavacia(&b)){
        printf(" Las dos pilas son iguales. \n\n");
    }else{
        printf(" Las dos pilas son distintas. \n\n");
    }

    return 0;
}
