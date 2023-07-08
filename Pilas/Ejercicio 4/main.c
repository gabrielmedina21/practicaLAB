#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "pila.h"

int main()
{
    /** DECLARACION DE VARIABLES **/
    Pila origen;
    Pila destino;
    Pila auxDestino;
    char continuar = 's';

    inicpila(&origen);
    inicpila(&destino);
    inicpila(&auxDestino);

    /* ---------------------------------------------------- */

    do{
       system("cls");

       printf("\t\t\t EJERCICIO 4 - PILAS \n\n");

       printf(" CARGANDO PILA ORIGEN.... \n\n");

       leer(&origen);

       printf("\n %cQuieres continuar cargando la pila? s=SI / n=NO " , 168);
       fflush(stdin);
       continuar = getch();

    }while(continuar == 's' || continuar == 'S');

    system("cls");

    printf(" PILA ORIGEN CARGADA \n");
    mostrar(&origen);

    while(!pilavacia(&origen)){
        apilar(&auxDestino , desapilar(&origen));
    }

    while(!pilavacia(&auxDestino)){
        apilar(&destino , desapilar(&auxDestino));
    }

    printf(" PILA DESTINO \n");
    mostrar(&destino);

    return 0;
}
