#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "pila.h"

void cargaPila(Pila *p); /* FUNCIÓN EJERCICIO 1 */
void pasarPilaToPila(Pila *origen , Pila *destino); /* FUNCIÓN EJERCICIO 2 */
void pasarPilaToPilaConservandoOrden(Pila *origen , Pila *destino); /* FUNCIÓN EJERCICIO 3 */
int buscarMenorPila(Pila *p); /* FUNCIÓN EJERCICIO 4 */
void ordenarPilaSeleccion(Pila *origen , Pila *destino); /* FUNCIÓN EJERCICIO 5 */
void insertarElementoPila(Pila *p , int nuevoElemento); /* FUNCIÓN EJERCICIO 6 */
void ordenarPilaPorInsercion(Pila *origen , Pila *destino); /* FUNCIÓN EJERCICIO 7 */
int sumaDosPrimerosElementos(Pila *p); /* FUNCIÓN EJERCICIO 8 */
int sumaElementosPila(Pila p); /* FUNCIÓN AUX EJERCICIO 9 */
int contarElementosPila(Pila p); /* FUNCIÓN AUX EJERCICIO 9 */
float promedioPila(Pila p); /* FUNCIÓN EJERCICIO 9 */
int pasarANumDecimal(Pila p); /* FUNCIÓN EJERCICIO 10 */

int main()
{

/** DECLARACIÓN DE VARIABLES **/

    /* Variables del ejercicio 1: */
    Pila dada;

    inicpila(&dada);

/* --------------------------------- */

    /* Variables del ejercicio 2: */
    Pila dest;

    inicpila(&dest);

/* --------------------------------- */

    /* Variables del ejercicio 4: */
    int menorElementoPila;

/* --------------------------------- */

    /* Variables del ejericio 5 */
    Pila ordenadaPorSeleccion;

    inicpila(&ordenadaPorSeleccion);

/* --------------------------------- */

/* Variables del ejericio 6 */
    int nuevoElem = 0;

/* --------------------------------- */

/* Variables del ejericio 7 */
    Pila ordenadaPorInsercion;

    inicpila(&ordenadaPorInsercion);

/* --------------------------------- */

/* Variables del ejericio 8 */
    int sumaElementosPila = 0;

/* --------------------------------- */

/* Variables del ejericio 9 */

    float promPila = 0;

/* --------------------------------- */

/* Variables del ejericio 9 */

    Pila dada2;
    int numDecimal = 0;

    inicpila(&dada2);

/* --------------------------------- */

/// Ejercicio 1
    cargaPila(&dada);

    system("cls");

    printf("\t\t\t TP3 - MODULARIZACI%cN \n\n" , 224);

    printf(" PILA CARGADA \n");
    mostrar(&dada);

/* ------------------------------------------------------- */

/// Ejercicio 2

    pasarPilaToPila(&dada , &dest);

    printf(" PILA DESTINO \n");
    mostrar(&dest);

/* ------------------------------------------------------- */

/// Ejercicio 3

    pasarPilaToPilaConservandoOrden(&dest , &dada);

    printf(" PASAR PILA TO PILA CONSERVANDO ORDEN \n");
    mostrar(&dada);

/* ------------------------------------------------------- */

/// Ejercicio 4

    menorElementoPila = buscarMenorPila(&dada);

    printf(" El menor elemento de la pila es: %d \n\n" , menorElementoPila);

/* ------------------------------------------------------- */

/// Ejercicio 5

    apilar(&ordenadaPorSeleccion , menorElementoPila);
    ordenarPilaSeleccion(&dada , &ordenadaPorSeleccion);

    printf(" PILA ORDENADA POR SELECCI%cN \n" , 224);
    mostrar(&ordenadaPorSeleccion);

/* ------------------------------------------------------- */

/// Ejercicio 6

    printf(" Ingresar nuevo n%cmero: " , 163);
    scanf("%d" , &nuevoElem);

    insertarElementoPila(&ordenadaPorSeleccion , nuevoElem);

    printf("\n PILA CON EL NUEVO ELEMENTO INSERTARDO \n");
    mostrar(&ordenadaPorSeleccion);

/* ------------------------------------------------------- */

/// Ejercicio 7

    ordenarPilaPorInsercion(&ordenadaPorSeleccion , &ordenadaPorInsercion);

    printf(" PILA ORDENADA POR INSERCI%cN \n" , 224);
    mostrar(&ordenadaPorInsercion);

/* ------------------------------------------------------- */

/// Ejercicio 8

    sumaElementosPila = sumaDosPrimerosElementos(&ordenadaPorInsercion);

    printf(" La suma de los dos primeros elementos de la pila es: %d \n\n" , sumaElementosPila);


/* ------------------------------------------------------- */

/// Ejercicio 9

    promPila = promedioPila(ordenadaPorInsercion);

    printf(" El promedio de la pila es: %.2f \n\n" , promPila);

/* ------------------------------------------------------- */

    system("pause");

/// Ejercicio 10

    cargaPila(&dada2);

    system("cls");

    printf(" PILA CARGADA... \n");
    mostrar(&dada2);

    numDecimal = pasarANumDecimal(dada2);

    printf(" Convertido en n%cmero decimal es: %d \n" , 163 , numDecimal);

/* ------------------------------------------------------- */

    return 0;
}

/* ejercicio 1: Hacer una función que permita ingresar varios elementos a una Pila, tantos como quiera el usuario. */
void cargaPila(Pila *p)
{
    char continuar = 's';

    do{
        system("cls");

        printf(" CARGANDO PILA... \n\n");
        leer(p);

        printf("\n %cQuieres continuar cargando la pila? s=SI / n=NO " , 168);
        fflush(stdin);
        continuar = getch();

    }while(continuar == 's' || continuar == 'S');
}

/* ejercicio 2: Hacer una función que pase todos los elementos de una pila a otra.  */
void pasarPilaToPila(Pila *origen , Pila *destino)
{
    while(!pilavacia(origen)){
        apilar(destino , desapilar(origen));
    }
}

/* ejercicio 3: Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden.  */

void pasarPilaToPilaConservandoOrden(Pila *origen , Pila *destino)
{
    Pila aux;
    inicpila(&aux);

    pasarPilaToPila(origen , &aux);
    pasarPilaToPila(&aux , destino);
}

// ejercicio 4: Hacer una función que encuentre el menor elemento de una pila y lo retorne. La misma debe eliminar ese dato de
//              la pila.

int buscarMenorPila(Pila *p)
{
    Pila aux;
    int menor;

    inicpila(&aux);

    if(!pilavacia(p)){
        menor = desapilar(p);

        while(!pilavacia(p)){
            if(tope(p) < menor){
                apilar(&aux , menor);
                menor = desapilar(p);
            }else{
                apilar(&aux , desapilar(p));
            }
        }

        pasarPilaToPila(&aux , p);

    }else{
        printf(" La pila esta vacia. \n\n");
    }

    return menor;
}

// ejercicio 5: Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada.
//              Usar la función del ejercicio 4. (Ordenamiento por selección)

void ordenarPilaSeleccion(Pila *origen , Pila *destino)
{
    int menor = 0;

    while(!pilavacia(origen)){
        menor = buscarMenorPila(origen);
        apilar(destino , menor);
    }
}

/* ejercicio 6: Hacer una función que inserte en una pila ordenada un nuevo elemento, conservando el orden de ésta. */

void insertarElementoPila(Pila *p , int nuevoElemento)
{
    Pila aux;

    inicpila(&aux);

    while(!pilavacia(p) && tope(p) > nuevoElemento){
        apilar(&aux , desapilar(p));
    }

    apilar(&aux , nuevoElemento);

    pasarPilaToPila(&aux , p);
}

// ejercicio 7: . Hacer una función que pase los elementos de una pila a otra, de manera que se genere una nueva pila ordenada.
//                Usar la función del ejercicio 6.  (Ordenamiento por inserción)

void ordenarPilaPorInsercion(Pila *origen , Pila *destino)
{
    Pila auxRecep;
    int recep = 0;

    inicpila(&auxRecep);

    while(!pilavacia(origen)){
        recep = desapilar(origen);
        insertarElementoPila(&auxRecep , recep);
    }

    pasarPilaToPila(&auxRecep , destino);
}

// ejercicio 8: Hacer una función que sume y retorne los dos primeros elementos de una pila (tope y anterior), sin alterar
//              su contenido.

int sumaDosPrimerosElementos(Pila *p)
{
    Pila aux;
    int sumaElementos = 0;

    inicpila(&aux);

    if(!pilavacia(p)){
        sumaElementos += tope(p);
        apilar(&aux , desapilar(p));

        if(!pilavacia(p)){
            sumaElementos += tope(p);
            apilar(&aux , desapilar(p));
        }

        while(!pilavacia(&aux)){
            apilar(p , desapilar(&aux));
        }
    }

    return sumaElementos;
}

// ejercicio 9: Hacer una función que calcule el promedio de los elementos de una pila, para ello hacer también una función que
//              calcule la suma, otra para la cuenta y otra que divida. En total son cuatro funciones, y la función que calcula
//              el promedio invoca a las otras 3.

int sumaElementosPila(Pila p)
{
    Pila aux;
    int resultadoSuma = 0;

    inicpila(&aux);

    while(!pilavacia(&p)){
        resultadoSuma += tope(&p);
        apilar(&aux , desapilar(&p));
    }

    return resultadoSuma;
}

int contarElementosPila(Pila p)
{
    Pila aux;
    int contElementos = 0;

    inicpila(&aux);

    while(!pilavacia(&p)){
        apilar(&aux , desapilar(&p));
        contElementos++;
    }

    return contElementos;
}

float promedioPila(Pila p)
{
    float promPila = 0;
    int sumaElementos = sumaElementosPila(p);
    int cantElementos = contarElementosPila(p);

    promPila = (float)sumaElementos / cantElementos;

    return promPila;
}

// ejercicio 10: . Hacer una función que reciba una pila con números de un solo dígito (es responsabilidad de quien usa el programa)
//                 y que transforme esos dígitos en un número decimal.

int pasarANumDecimal(Pila p)
{
    Pila aux;
    int numDecimal = 0;

    inicpila(&aux);

    pasarPilaToPila(&p , &aux);

    while(!pilavacia(&aux)){
        numDecimal *= 10;
        numDecimal += desapilar(&aux);
    }

    return numDecimal;
}
