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
    char continuar = 's';
    float promedioPila = 0;
    int cantElementosPila = 0;
    int sumaElementosPila = 0;

    inicpila(&dada);
    inicpila(&auxDada);

/* ------------------------------------ */

    do{
        system("cls");

        printf("\t\t\t EJERCICIO 3 - PILAS AVANZADO \n\n");

        printf(" CARGANDO PILA... \n\n");
        leer(&dada);

        printf("\n %cQuieres continuar cargando la pila? s=SI / n=NO " , 168);
        fflush(stdin);
        continuar = getch();

    }while(continuar == 's' || continuar == 'S');

    system("cls");

    printf(" PILA CARGADA \n\n");
    mostrar(&dada);

    while(!pilavacia(&dada)){
         sumaElementosPila += tope(&dada);
         apilar(&auxDada , desapilar(&dada));
         cantElementosPila++;
    }

    while(!pilavacia(&auxDada)){
        apilar(&dada , desapilar(&auxDada));
    }

    promedioPila = (float)sumaElementosPila / cantElementosPila;

    printf(" El promedio es: %.2f \n\n" , promedioPila);

    return 0;
}
