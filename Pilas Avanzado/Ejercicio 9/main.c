#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "pila.h"

int main()
{
/** DECLARACIÓN DE VARIABLES **/

    Pila dada;
    Pila auxDada;
    Pila dadaInvertida;
    char continuar = 's';
    int copiaTopePila = 0;

    inicpila(&dada);
    inicpila(&auxDada);
    inicpila(&dadaInvertida);

/* ---------------------------------- */

    do{
        system("cls");

        printf("\t\t\t EJERCICIO 9 - PILAS AVANZADO \n\n");

        printf(" CARGANDO PILA...  \n\n");
        leer(&dada);

        printf("\n %cQuieres continuar cargando la pila? s=SI / n=NO " , 168);
        fflush(stdin);
        continuar = getch();

    }while(continuar == 's' || continuar == 'S');

    system("cls");

    printf(" PILA CARGADA \n");
    mostrar(&dada);

    while(!pilavacia(&dada)){
        copiaTopePila = tope(&dada);
        apilar(&dadaInvertida , copiaTopePila);
        apilar(&auxDada , desapilar(&dada));
    }

    while(!pilavacia(&auxDada)){
        apilar(&dada , desapilar(&auxDada));
    }

    while(!pilavacia(&dada) && !pilavacia(&dadaInvertida) && tope(&dada) == tope(&dadaInvertida)){
        apilar(&auxDada , desapilar(&dada));
        apilar(&auxDada , desapilar(&dadaInvertida));
    }

    if(pilavacia(&dada) && pilavacia(&dadaInvertida)){
        printf(" La pila es capic%ca. \n\n" , 163);
    }else{
        printf(" La pila no es capic%ca. \n\n" , 163);
    }

    return 0;
}
