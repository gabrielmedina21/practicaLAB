#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include "pila.h"

int main()
{
/** DECLARACIÓN DE VARIABLES **/

    Pila dada;
    Pila aux;
    Pila par;
    Pila impar;
    char continuar = 's';
    int cont = 0;

    inicpila(&dada);
    inicpila(&aux);
    inicpila(&par);
    inicpila(&impar);

/* ----------------------------------------------- */

    do{
        system("cls");

        printf(" CARGANDO PILA DADA... \n\n");
        leer(&dada);
        printf("\n %cQuieres continuar cargando la pila? s=SI / n=NO " , 168);
        fflush(stdin);
        continuar = getch();

    }while(continuar == 's' || continuar == 'S');

    system("cls");

    printf(" PILA DADA CARGADA \n");
    mostrar(&dada);

    system("pause");
    system("cls");

    while(!pilavacia(&dada)){
        apilar(&aux , desapilar(&dada));
        cont++;
    }

    printf(" PILA AUX \n");
    mostrar(&aux);

    if(cont %2 == 0){
        printf(" La cantidad de elementos de la pila es par. \n\n");

        apilar(&par , desapilar(&aux));

        printf(" PILA PAR \n");
        mostrar(&par);
    }else{
        printf(" La cantidad de elementos de la pila es impar. \n\n");

        apilar(&impar , desapilar(&aux));

        printf(" PILA IMPAR \n");
        mostrar(&impar);
    }

    return 0;
}
