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
    Pila c;
    Pila descarte;
    Pila aux;
    char continuar = 's';

    inicpila(&a);
    inicpila(&b);
    inicpila(&c);
    inicpila(&descarte);
    inicpila(&aux);

/* --------------------------------------- */

    do{
        system("cls");

        printf("\t\t\t EJERCICIO 10 - PILAS AVANZADO \n\n");

        printf(" CARGANDO PILA A... \n\n");
        leer(&a);

        printf("\n %cQuieres continuar cargando la pila? s=SI / n=NO " , 168);
        fflush(stdin);
        continuar = getch();

    }while(continuar == 's' || continuar == 'S');

    do{
        system("cls");

        printf("\t\t\t EJERCICIO 10 - PILAS AVANZADO \n\n");

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

    system("pause");

    while(!pilavacia(&a)){
        while(!pilavacia(&b)){
            if(tope(&b) == tope(&a)){
                apilar(&descarte , desapilar(&b));
            }else{
                apilar(&aux ,desapilar(&b));
            }
        }
        apilar(&c , desapilar(&a));

        while(!pilavacia(&aux)){
            apilar(&b , desapilar(&aux));
        }
    }

    while(!pilavacia(&b)){
        apilar(&c , desapilar(&b));
    }

    system("cls");

    printf(" PILA C \n");
    mostrar(&c);

    return 0;
}
