#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "pila.h"

int main()
{
    /** DECLARACION DE VARIABLES **/
    Pila origen,destino;
    char continuar = 's';

    inicpila(&origen);
    inicpila(&destino);

    /* --------------------------------------------------------- */


    do{
        system("cls");

        printf("\t\t\t EJERCICIO 2 - PILAS\n\n");

        printf(" CARGANDO PILA ORIGEN... \n\n");

        leer(&origen);

        printf("\n %cQuieres continuar cargando la pila? s=SI / n=NO " , 168 , 164);
        fflush(stdin);
        continuar = getch();

    }while(continuar == 's' || continuar == 'S');

    system("cls");

    printf(" PILA ORIGEN CARGADA... \n");
    mostrar(&origen);

    while(!pilavacia(&origen)){
        apilar(&destino , desapilar(&origen));
    }

    printf(" PILA DESTINO... \n");
    mostrar(&destino);

    return 0;
}
