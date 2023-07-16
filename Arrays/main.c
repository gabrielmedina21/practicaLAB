#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "pila.h"

int cargarArrayInt(int arrInt[] , int dimension); //FUNCIÓN DEL EJERCICIO 1
void mostrarArrayInt(int arrInt[] , int validos); //FUNCIÓN DEL EJERCICIO 2
int sumaElementosArrayInt(int arrInt[] , int validos); //FUNCIÓN DEL EJERCICIO 3
void pasarArrayToPila(int arrInt[] , int validos , Pila *p); //FUNCIÓN DEL EJERCICIO 4
float cargarArrayFloat(float arrFloat[] , int dimension); //FUNCIÓN AUX DEL EJERCICIO 5
void mostrarArrayFloat(float arrFloat[] , int validos); //FUNCIÓN AUX DEL EJERCICIO 5
float sumaElementosArrayFloat(float arrFloat[] , int validos); //FUNCIÓN DEL EJERCICIO 5
int existeCharArray(char arrChars[] , int validos , char letter); //FUNCIÓN DEL EJERCICIO 6
void mostrarArrayChars(char arrChars[] , int validos); //FUNCIÓN AUX DEL EJERCICIO 6
int insertarCharArray(char arrChars[] , int validos , char letter); //FUNCIÓN DEL EJERCICIO 7
char maxCharArray(char arrChars[] , int validos); //FUNCIÓN DEL EJERCICIO 8
int verificaSiEsCapicua(int arrInt[] , int validos); //FUNCIÓN DEL EJERCICIO 9
void invertirArrayInt(int arrInt[] , int validos); //FUNCIÓN DEL EJERCICIO 10
int buscarPosMenorArrayInt(int arrInt[] , int validos , int pos); // FUNCIÓN AUX EJERCICIO 11a
void ordenarArrayIntSeleccion(int arrInt[] , int validos); //FUNCIÓN DEL EJERCICIO 11a
void insertarDatoInt(int arrInt[] , int validos , int dato); //FUNCIÓN  AUX DEL EJERCICIO 11b
void ordenarArrayIntInsercion(int arrInt[] , int validos); //FUNCIÓN DEL EJERCICIO 11b
int intercarlarArrayChar(char arrChars1[] , int valArrayChars1 , char arrChars2[] , int valArrayChars2 , char arrCharsFinal[] , int dimension); //FUNCIÓN DEL EJERCICIO 12

int main()
{
/** DECLARACIÓN DE VARIABLES **/

//variables del ejercicio 1:
    int dimension = 50;
    int arrayInt[dimension];
    int valArrayInt = 0;

//--------------------------------//

//variables del ejercicio 3:
    int sumaArrayInt = 0;

//--------------------------------//

//variables del ejercicio 4:
    Pila elemArray;

    inicpila(&elemArray);

//--------------------------------//

//variables del ejercicio 4:
    float arrayFloat[100];
    int valArrayFloat = 0;
    float sumaArrayFloat = 0;

//--------------------------------//

//variables del ejercicio 6:
    char arrayChars[] = {'a','b','c','d','e','f'};
    char letter = 0;
    int existeLetter = 0;

//--------------------------------//

//variables del ejercicio 7:
    char charAInsertar = 0;
    int valArrayChars = 0;

//--------------------------------//

//variables del ejercicio 8:
    char charMax = 0;

//--------------------------------//

//variables del ejercicio 9:
    int arrayInt2[dimension];
    int valArrayInt2 = 0;
    int esCapicua = 0;

//--------------------------------//

//variables del ejercicio 12:

    char arrayChars2[] = {'a','e','i','o','u'};
    char arrayCharsOrdenado[30];
    int valArrayCharsOrdenado = 0;

//--------------------------------//

///* EJERCICIO 1 */
//    valArrayInt = cargarArrayInt(arrayInt , dimension);
//
/////-----------------------------------///
//
///* EJERCICIO 2 */
//    system("cls");
//
//    printf("\t\t\t TP4 - ARRAY \n\n");
//
//    printf(" EJERCICIO 2 \n\n");
//    printf(" ARREGLO DE N%cMEROS ENTEROS CARGADO \n\n" , 233);
//    mostrarArrayInt(arrayInt , valArrayInt);
//
/////-----------------------------------///
//
///* EJERCICIO 3 */
//    sumaArrayInt = sumaElementosArrayInt(arrayInt , valArrayInt);
//
//    printf(" EJERCICIO 3 \n\n");
//    printf(" La suma de los elementos del array es: %d \n\n" , sumaArrayInt);
//
/////-----------------------------------///
//
///* EJERCICIO 4 */
//    pasarArrayToPila(arrayInt , valArrayInt , &elemArray);
//
//    printf(" EJERCICIO 4 \n\n");
//    printf(" DATOS ARRAY COPIADOS A LA PILA \n");
//    mostrar(&elemArray);
//
/////-----------------------------------///
//
//    printf("\n\n");
//    system("pause");
//
///* EJERCICIO 5 */
//    valArrayFloat = cargarArrayFloat(arrayFloat , 100);
//
//    system("cls");
//    printf(" EJERCICIO 5 \n\n");
//    printf(" ARREGLO DE N%cMEROS REALES CARGADO \n\n" , 233);
//    mostrarArrayFloat(arrayFloat , valArrayFloat);
//
//    sumaArrayFloat = sumaElementosArrayFloat(arrayFloat , valArrayFloat);
//
//    printf(" La suma de los elementos del array es: %.2f \n\n" , sumaArrayFloat);
//
/////-----------------------------------///
//
//    system("pause");
//    system("cls");
//
///* EJERCICIO 6 */
//    printf(" EJERCICIO 6 \n\n");
//    printf(" Ingresar letra a buscar: ");
//    fflush(stdin);
//    scanf("%c" , &letter);
//
//    existeLetter = existeCharArray(arrayChars , 6 , letter);
//
//    if(existeLetter == 1){
//        printf("\n La letra %c existe en el array. \n\n" , letter);
//        printf(" ARRAY DE CHARS CARGADO \n\n");
//        mostrarArrayChars(arrayChars , 6);
//    }else{
//        printf("\n La letra %c NO existe en el array. \n\n" , letter);
//    }

///-----------------------------------///

/* EJERCICIO 7 */
    printf(" EJERCICIO 7 \n\n");
    printf(" Ingresar char a insertar: ");
    fflush(stdin);
    scanf("%c" , &charAInsertar);

    valArrayChars = insertarCharArray(arrayChars , 6 , charAInsertar);

    printf("\n ARREGLO CON EL NUEVO CHAR \n\n");
    mostrarArrayChars(arrayChars , valArrayChars);

///-----------------------------------///

/* EJERCICIO 8 */
    printf(" EJERCICIO 8 \n\n");

    charMax = maxCharArray(arrayChars , valArrayChars);

    printf(" El caracter m%cximo del array es: %c \n\n" , 160 , charMax);

///-----------------------------------///

    system("pause");

/* EJERCICIO 9 */
    valArrayInt2 = cargarArrayInt(arrayInt2 , dimension);

    system("cls");

    printf(" EJERCICIO 9 \n\n");

    printf(" ARRAY 2 DE N%cMEROS ENTEROS CARGADO  \n\n" , 233);
    mostrarArrayInt(arrayInt2 , valArrayInt2);

    esCapicua = verificaSiEsCapicua(arrayInt2 , valArrayInt2);

    if(esCapicua == 1){
        printf(" El arreglo es capic%ca. \n\n" , 163);
    }else{
        printf(" El arreglo NO es capic%ca. \n\n" , 163);
    }

///-----------------------------------///

/* EJERCICIO 10 */
    invertirArrayInt(arrayInt2 , valArrayInt2);

    printf(" EJERCICIO 10 \n\n");
    printf(" ARREGLO INVERTIDO \n\n");
    mostrarArrayInt(arrayInt2 , valArrayInt2);

///-----------------------------------///

/* EJERCICIO 11a */
    printf(" EJERCICIO 11a \n\n");

    ordenarArrayIntSeleccion(arrayInt2 , valArrayInt2);

    printf(" ARREGLO ORDENADO POR SELECCI%cN \n\n" , 224);
    mostrarArrayInt(arrayInt2 , valArrayInt2);


///-----------------------------------///

/* EJERCICIO 11b */
    printf(" EJERCICIO 11b \n\n");

    ordenarArrayIntInsercion(arrayInt2 , valArrayInt2);

    printf(" ARREGLO ORDENADO POR INSERCI%cN \n\n" , 224);
    mostrarArrayInt(arrayInt2 , valArrayInt2);


///-----------------------------------///

    system("pause");
    system("cls");

/* Ejercicio 12 */

    printf(" ARREGLO DE CHARS 1 ORDENADO \n\n");
    mostrarArrayChars(arrayChars , valArrayChars);
    printf(" ARREGLO DE CHARS 2 ORDENADO \n\n");
    mostrarArrayChars(arrayChars2 , 5);

    valArrayCharsOrdenado = intercarlarArrayChar(arrayChars , valArrayChars , arrayChars2 , 5 , arrayCharsOrdenado , 30);

    printf(" ARREGLO DE CHARS FINAL ORDENADO \n\n");
    mostrarArrayChars(arrayCharsOrdenado , valArrayCharsOrdenado);

///-----------------------------------///

    return 0;
}

/// Ejercicio 1: Hacer una función que reciba como parámetro un arreglo de números enteros y permita que el usuario ingrese valores
///              al mismo por teclado. La función debe retornar la cantidad de elementos cargados en el arreglo.

int cargarArrayInt(int arrInt[] , int dimension)
{
    char continuar = 's';
    int num = 0;
    int i = 0;

    while((i<dimension) && (continuar == 's' || continuar == 'S')){
        system("cls");

        printf(" CARGANDO ARREGLO INT... \n\n");

        printf(" Ingresar n%cmero: " , 163);
        scanf("%d" , &num);

        arrInt[i] = num;

        i++;

        printf("\n %cQuieres continuar cargando el arreglo? s=SI / n=NO " , 168);
        fflush(stdin);
        continuar = getch();
    }

    return i;
}

/// Ejercicio 2: Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y
///              los muestre por pantalla.
void mostrarArrayInt(int arrInt[] , int validos)
{
    int i;

    for(i=0 ; i<validos ; i++){
        printf("| %d |" , arrInt[i]);
    }
    printf("\n\n");
}

/// Ejercicio 3: Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos) cargados en él y calcule
///              la suma de sus elementos.

int sumaElementosArrayInt(int arrInt[] , int validos)
{
    int resSuma = 0;
    int i = 0;

    while(i < validos){
        resSuma += arrInt[i];
        i++;
    }

    return resSuma;
}

/// Ejercicio 4: Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos) cargados en él y una
///              Pila. La función debe copiar los elementos del arreglo en la pila.

void pasarArrayToPila(int arrInt[] , int validos , Pila *p)
{
    int i = 0;

    while(i < validos){
        apilar(p , arrInt[i]);
        i++;
    }
}

/// Ejercicio 5: Realizar una función que sume los elementos reales de un arreglo de dimensión 100.

float sumaElementosArrayFloat(float arrFloat[] , int validos)
{
    float sumaArarayFloat = 0;
    int i = 0;

    while(i<validos){
        sumaArarayFloat += arrFloat[i];
        i++;
    }

    return sumaArarayFloat;
}

float cargarArrayFloat(float arrFloat[] , int dimension)
{
    char continuar = 's';
    float num = 0;
    int i = 0;

    while((i<dimension) && (continuar == 's' || continuar == 'S')){
        system("cls");

        printf(" CARGANDO ARREGLO FLOAT... \n\n");

        printf(" Ingresar n%cmero: " , 163);
        scanf("%f" , &num);

        arrFloat[i] = num;

        i++;

        printf("\n %cQuieres continuar cargando el arreglo? s=SI / n=NO " , 168);
        fflush(stdin);
        continuar = getch();
    }

    return i;
}

void mostrarArrayFloat(float arrFloat[] , int validos)
{
    int i;

    for(i=0 ; i<validos ; i++){
        printf("| %.2f |" , arrFloat[i]);
    }
    printf("\n\n");
}

/// Ejercicio 6: Realizar una función que indique si un elemento dado se encuentra en un arreglo de caracteres.

int existeCharArray(char arrChars[] , int validos , char letter)
{
    int flag = 0;
    int i = 0;

    while(i<validos && flag == 0){
        if(arrChars[i] == letter){
            flag = 1;
        }else{
            i++;
        }
    }

    return flag;
}

void mostrarArrayChars(char arrChars[] , int validos)
{
    int i;

    for(i=0 ; i<validos ; i++){
        printf("| %c |" , arrChars[i]);
    }

    printf("\n\n");
}

/// Ejercicio 7: Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente, conservando el orden.

int insertarCharArray(char arrChars[] , int validos , char letter)
{
    int i = validos-1;

    while(i>=0 && arrChars[i] > letter){
        arrChars[i+1] = arrChars[i];
        i--;
    }

    arrChars[i+1] = letter;

    return validos+1;
}

/// Ejercicio 8: Realizar una función que obtenga el máximo carácter de un arreglo dado.

char maxCharArray(char arrChars[] , int validos)
{
    int i = 0;
    char max = arrChars[i];

    while(i<validos){
        if(arrChars[i] > max){
            max = arrChars[i];
        }else{
            i++;
        }
    }

    return max;
}

/// Ejercicio 9: Realizar una función que determine si un arreglo es capicúa.

int verificaSiEsCapicua(int arrInt[] , int validos)
{
    int esCapicua = 1;
    int i = 0;
    int j = validos-1;

    while(i<validos && esCapicua == 1){
        if(arrInt[i] == arrInt[j]){
            j--;
        }else{
            esCapicua = 0;
        }

        i++;
    }

    return esCapicua;
}

/// Ejercicio 10: Realizar una función que invierta los elementos de un arreglo.

void invertirArrayInt(int arrInt[] , int validos)
{
    int temporal = 0;
    int i;
    int j = validos-1;

    for(i=0 ; i<j ; i++){
        temporal = arrInt[i];
        arrInt[i] = arrInt[j];
        arrInt[j] = temporal;

        j--;
    }
}

/// Ejercicio 11: Ordenar un arreglo según los siguientes métodos:
///                a.Selección
///                b.Inserción

int buscarPosMenorArrayInt(int arrInt[] , int validos , int pos)
{
    int menor = arrInt[pos];
    int posMenor = pos;
    int i = pos+1;

    while(i<validos){
        if(arrInt[i] < menor){
            menor = arrInt[i];
            posMenor = i;
        }else{
            i++;
        }
    }

    return posMenor;
}

void ordenarArrayIntSeleccion(int arrInt[] , int validos)
{
    int posMenor = 0;
    int aux = 0;
    int i;

    for(i=0 ; i<validos ; i++){
        posMenor = buscarPosMenorArrayInt(arrInt , validos , i);
        aux = arrInt[posMenor];
        arrInt[posMenor] = arrInt[i];
        arrInt[i] = aux;
    }
}

void insertarDatoInt(int arrInt[] , int validos , int dato)
{
    int i = validos;

    while(i>=0 && arrInt[i] > dato){
        arrInt[i+1] = arrInt[i];
        i--;
    }

    arrInt[i+1] = dato;
}

void ordenarArrayIntInsercion(int arrInt[] , int validos)
{
    int i;

    for(i=0 ; i<validos-1 ; i++){
        insertarDatoInt(arrInt , i , arrInt[i+1]);
    }
}

/// Ejercicio 12: Dados dos arreglos ordenados alfabéticamente, crear un tercer arreglo con los elementos de los dos primeros
///               intercalados, de manera que quede un arreglo también ordenado alfabéticamente.

int intercarlarArrayChar(char arrChars1[] , int valArrayChars1 , char arrChars2[] , int valArrayChars2 , char arrCharsFinal[] , int dimension)
{
    int iA = 0;
    int iB = 0;
    int iC = 0;

    while((iA < valArrayChars1) && (iB < valArrayChars2) && (iC < dimension)){
        if(arrChars1[iA] < arrChars2[iB]){
            arrCharsFinal[iC] = arrChars1[iA];
             iA++;
        }else{
            arrCharsFinal[iC] = arrChars2[iB];
            iB++;
        }

        iC++;
    }

    while((iA < valArrayChars1) && (iC < dimension)){
        arrCharsFinal[iC] = arrChars1[iA];
        iA++;
        iC++;
    }

    while((iB < valArrayChars2) && (iC < dimension)){
        arrCharsFinal[iC] = arrChars2[iB];
        iB++;
        iC++;
    }

    return iC;
}
