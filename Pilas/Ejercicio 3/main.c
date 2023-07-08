#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "pila.h"

int main()
{
    /** DECLARACION DE VARIABLES **/
    Pila dada;
    Pila distintos;
    Pila auxDada;
    char continuar = 's';

    inicpila(&dada);
    inicpila(&distintos);
    inicpila(&auxDada);

    do{
        system("cls");

        printf("\t\t\t EJERCICIO 3 - PILAS \n\n");

        printf(" CARGANDO PILA DADA... \n\n");

        leer(&dada);

        printf("\n %cQuieres continuar cargando la pila? s=SI / n=NO " , 168);
        fflush(stdin);
        continuar = getch();

    }while(continuar == 's' || continuar == 'S');

    system("cls");

    printf(" PILA DADA CARGADA... \n");
    mostrar(&dada);

    while(!pilavacia(&dada)){
        if(tope(&dada) != 8){
            apilar(&distintos , desapilar(&dada));
        }else{
            apilar(&auxDada , desapilar(&dada));
        }
    }

    printf(" PILA DISTINTOS... \n");
    mostrar(&distintos);

    return 0;
}
