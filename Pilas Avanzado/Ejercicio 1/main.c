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
    int sumaElementosPila = 0;
    char continuar = 's';

    inicpila(&dada);
    inicpila(&auxDada);

/* -------------------------------------- */

    do{
        system("cls");

        printf("\t\t\t EJERCICIO 1 - PILAS AVANZADO \n\n");

        printf(" CARGANDO PILA... \n\n");
        leer(&dada);

        printf("\n %cQuieres continuar cargando la pila? s=SI / n=NO " , 168);
        fflush(stdin);
        continuar = getch();

    }while(continuar == 's' || continuar == 'S');

    system("cls");

    printf(" PILA CARGADA... \n");
    mostrar(&dada);

    while(!pilavacia(&dada)){
        sumaElementosPila += tope(&dada);
        apilar(&auxDada , desapilar(&dada));
    }

    while(!pilavacia(&auxDada)){
        apilar(&dada , desapilar(&auxDada));
    }
    
    printf(" La suma de los elementos de la pila es: %d \n\n" , sumaElementosPila);

    return 0;
}
