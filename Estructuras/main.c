#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>

typedef struct
{
    int matricula;
    char nombre[30];
    char genero; //m o f
}stAlumno;

int cargarArrayAlumns(stAlumno arrAlums[] , int dimension); //FUNCIÓN DEL EJERCICIO 1
void mostrarUnAlumno(stAlumno alum); // FUNCIÓN AUX DEL EJERCICIO 2
void mostrarArrayAlumns(stAlumno arrAlums[] , int validos); //FUNCIÓN DEL EJERCICIO 2
stAlumno buscarAlumXmatricula(stAlumno arrAlums[] , int validos , int matricula); // FUNCION DEL EJERCICIO 3
int buscarPosMenor(stAlumno arrAlums[] , int validos , int pos); // FUNCIÓN AUX DEL EJERCICIO 4
void ordenarArrayAlumsSeleccion(stAlumno arrAlums[] , int validos); // FUNCIÓN DEL EJERCICIO 4
void mostrarArrayAlumsXgenero(stAlumno arrAlums[] , int validos , char generoAlum); // FUNCIÓN DEL EJERCICIO 5
int insertarNuevoAlumno(stAlumno arrAlums[] , int validos , stAlumno nuevo); // FUNCIÓN DEL EJERCICIO 6
void insertarAlum(stAlumno arrAlums[] , int validos , stAlumno alum); // FUNCIÓN AUX DEL EJERCICIO 7
void ordenarArrayAlumInsercion(stAlumno arrAlums[] , int validos); // FUNCIÓN DEL EJERCICIO 7
int contarAlumsPorGenero(stAlumno arrAlums[] , int validos , char generoAlum); // FUNCIÓN DEL EJERCICIO 8
void menuPrint(); // FUNCIÓN AUX DEL EJERCICIO 9
void menuPrincipal(); // FUNCIÓN DEL EJERCICIO 9
 
int main()
{
    menuPrincipal();

    return 0;
}

// 1. Hacer una función que cargue un arreglo de alumnos, hasta que el usuario lo decida.
int cargarArrayAlumns(stAlumno arrAlums[] , int dimension)
{
    char continuar = 's';
    int i = 0;

    while((continuar == 's' || continuar == 'S') && (i < dimension)){
        system("cls");

        printf(" CARGANDO ALUMNO... \n\n");

        printf(" Ingresar matr%cula: " , 161);
        scanf("%d" , &arrAlums[i].matricula);

        printf(" Ingresar nombre: ");
        fflush(stdin);
        gets(arrAlums[i].nombre);

        printf(" Ingresar g%cnero (m o f): " , 130);
        fflush(stdin);
        scanf("%c" , &arrAlums[i].genero);

        i++;

        printf("\n %cQuieres cargar otro alumno? s=SI / n=NO " , 168);
        fflush(stdin);
        continuar = getch();
    }

    return i;
}

// 2. Hacer una función que muestre un arreglo de alumnos por pantalla. Modularizar.
void mostrarUnAlumno(stAlumno alum)
{
    printf(" ------------------------ \n");
    printf(" Matr%cula: %d \n" , 161 , alum.matricula);
    printf(" Nombre: %s \n" , alum.nombre);
    if(alum.genero == 'm'){
        printf(" G%cnero: Masculino \n" , 130);
    }else{
        printf(" G%cnero: Femenino \n" , 130);
    }
    printf(" ------------------------ \n\n");
}

void mostrarArrayAlumns(stAlumno arrAlums[] , int validos)
{
    int i;
    int numAlum = 0;

    for(i=0 ; i<validos ; i++){
        numAlum++;
        printf(" Alumno N%c %d \n" , 167 , numAlum);
        mostrarUnAlumno(arrAlums[i]);
    }

    printf("\n\n");
}

// 3. Hacer una función que muestre por pantalla los datos de un alumno, conociendo su matrícula. Modularizar.
stAlumno buscarAlumXmatricula(stAlumno arrAlums[] , int validos , int matricula)
{
    int i = 0;
    int flag = 0;
    stAlumno aux;

    while((i < validos) && (flag == 0)){
        if(arrAlums[i].matricula == matricula){
            flag = 1;
            aux = arrAlums[i];
        }else{
            i++;
        }
    }

    return aux;
}

// 4. Hacer una función que ordene el arreglo de alumnos por medio del método de selección. El criterio de ordenación es el
//    número de matrícula.
int buscarPosMenor(stAlumno arrAlums[] , int validos , int pos)
{
    int posMenor = pos;
    stAlumno menor = arrAlums[pos];
    int i;

    for(i=pos+1 ; i<validos ; i++){
        if(arrAlums[i].matricula < menor.matricula){
            posMenor = i;
            menor = arrAlums[i];
        }
    }

    return posMenor;
}

void ordenarArrayAlumsSeleccion(stAlumno arrAlums[] , int validos)
{
    int posMenor = 0;
    stAlumno aux;
    int i;

    for(i=0 ; i<validos ; i++){
        posMenor = buscarPosMenor(arrAlums , validos , i);
        aux = arrAlums[posMenor];
        arrAlums[posMenor] = arrAlums[i];
        arrAlums[i] = aux;
    }
}

// 5.	Hacer una función que muestre por pantalla los datos de los estudiantes de un género determinado (se envía por parámetro).
//      Modularizar.
void mostrarArrayAlumsXgenero(stAlumno arrAlums[] , int validos , char generoAlum)
{
    int i;

    for(i=0 ; i<validos ; i++){
        if(arrAlums[i].genero == generoAlum){
            mostrarUnAlumno(arrAlums[i]);
        }
    }

    printf("\n\n");
}

// 6. Hacer una función que inserte en un arreglo ordenado por matrícula un nuevo dato, conservando el orden.
int insertarNuevoAlumno(stAlumno arrAlums[] , int validos , stAlumno nuevo)
{
    int i = validos-1;

    while((i >= 0) && (arrAlums[i].matricula > nuevo.matricula)){
        arrAlums[i+1] = arrAlums[i];
        i--;
    }

    arrAlums[i+1] = nuevo;

    return validos+1;
}

// 7. Hacer una función que ordene el arreglo de alumnos por medio del método de inserción. El criterio de ordenación es el nombre.
void insertarAlum(stAlumno arrAlums[] , int validos , stAlumno alum)
{
    int i = validos;

    while((i >= 0) && (strcmp(arrAlums[i].nombre , alum.nombre) > 0)){
        arrAlums[i+1] = arrAlums[i];
        i--;
    }

    arrAlums[i+1] = alum;
}

void ordenarArrayAlumInsercion(stAlumno arrAlums[] , int validos)
{
    int i;

    for(i=0 ; i<validos-1 ; i++){
        insertarAlum(arrAlums , i , arrAlums[i+1]);
    }
}

// 8. Hacer una función que cuente y retorne la cantidad de estudiantes de un género determinado (se envía por parámetro)
//    que tiene un arreglo de alumnos.
int contarAlumsPorGenero(stAlumno arrAlums[] , int validos , char generoAlum)
{
    int contAlums = 0;
    int i;

    for(i=0 ; i<validos ; i++){
        if(arrAlums[i].genero == generoAlum){
            contAlums++;
        }
    }

    return contAlums;
}

// 9. Hacer una función principal que pruebe el funcionamiento de todos los incisos anteriores, con un menú de opciones para poder
//   ejecutar todas las funciones requeridas. Tengan presente la correcta declaración y el ámbito de variables.
void menuPrint()
{
    printf("\t\t\t\t\t TP6 - Estructuras \n\n");

    printf("\t ============================================================================= \n");

    printf("\t\t\t  1. Mostrar lista de alumnos. \n");
    printf("\t\t\t  2. Buscar alumno por matr%ccula. \n" , 161);
    printf("\t\t\t  3. Ordenar alumnos por el m%ctodo de SELECCI%cN. \n" , 130 , 224);
    printf("\t\t\t  4. Mostrar alumnos de un g%cnero determinado. \n" , 130);
    printf("\t\t\t  5. Ingresar nuevo alumno. \n");
    printf("\t\t\t  6. Ordenar alumnos por el m%ctodo de INSERCI%cN. \n" , 130 , 224);
    printf("\t\t\t  7. Cantidad de alumnos de un g%cnero determinado. \n" , 130);

    printf("\t ============================================================================= \n\n");
}

void menuPrincipal()
{
    int opcion = 0;

/** DECLARACIÓN DE VARIABLES **/

    /* Variables del ejercicio 1: */
    int dimension = 30;
    stAlumno arrayAlumnos[dimension];
    int valArrayAlums = 0;

/****************************************/

    /* Variables del ejercicio 3: */
    stAlumno existeAlum;
    int matriculaAlum = 0;

/****************************************/

    /* Variables del ejercicio 5: */
    char generoAlum = 0;

/****************************************/

    /* Variables del ejercicio 6: */
    stAlumno nuevo;

/****************************************/

    /* Variables del ejercicio 8: */
    int cantAlums = 0;

/****************************************/


    valArrayAlums = cargarArrayAlumns(arrayAlumnos , dimension);

    system("cls");

    menuPrint();

    printf(" Ingresar opci%cn: " , 162);
    scanf("%d" , &opcion);

    switch(opcion)
    {
    case 1:
        system("cls");

        printf("\t\t ------ EJERCICIO 2 ------ \n\n");
        printf(" ALUMNOS CARGADOS \n\n");
        mostrarArrayAlumns(arrayAlumnos , valArrayAlums);

        system("pause");

        break;

    case 2:
        system("cls");

        printf("\t\t ------ EJERCICIO 3 ------ \n\n");

        printf(" Ingresar matr%ccula del alumno a buscar: " , 161);
        scanf("%d" , &matriculaAlum);

        existeAlum = buscarAlumXmatricula(arrayAlumnos , valArrayAlums , matriculaAlum);

        if(existeAlum.matricula == matriculaAlum){
            printf("\n La matr%cula %d corresponde al alumno: \n\n" , 161 , matriculaAlum);
            mostrarUnAlumno(existeAlum);
        }else{
            printf("\n La matr%cula %d no corrresponde a ningun alumno. \n\n" , 161 , matriculaAlum);
        }

        system("pause");

        break;

    case 3:
        system("cls");

        printf("\t\t ------ EJERCICIO 4 ------ \n\n");

        ordenarArrayAlumsSeleccion(arrayAlumnos , valArrayAlums);

        printf(" ALUMNOS ORDENADOS POR MATR%cCULA \n\n" , 214);
        mostrarArrayAlumns(arrayAlumnos , valArrayAlums);

        system("pause");

        break;

    case 4:
        system("cls");

        printf("\t\t ------ EJERCICIO 5 ------ \n\n");

        printf(" Ingresar g%cnero a mostrar: " , 130);
        fflush(stdin);
        scanf("%c" , &generoAlum);

        printf("\n");
        mostrarArrayAlumsXgenero(arrayAlumnos , valArrayAlums , generoAlum);

        system("pause");

        break;

    case 5:
        system("cls");

        printf("\t\t ------ EJERCICIO 6 ------ \n\n");

        printf(" Ingresar datos del nuevo alumno: \n\n");

        printf(" Ingresar matr%cula: " , 161);
        scanf("%d" , &nuevo.matricula);
        printf(" Ingresar nombre: ");
        fflush(stdin);
        gets(nuevo.nombre);
        printf(" Ingresar g%cnero (m o f): " , 130);
        scanf("%c" , &nuevo.genero);

        valArrayAlums = insertarNuevoAlumno(arrayAlumnos , valArrayAlums , nuevo);

        printf("\n LISTA DE ALUNMNOS ACTUALIZADA \n\n");
        mostrarArrayAlumns(arrayAlumnos , valArrayAlums);

        system("pause");

        break;

    case 6:
        system("cls");

        ordenarArrayAlumInsercion(arrayAlumnos , valArrayAlums);

        printf("\t\t ------ EJERCICIO 7 ------ \n\n");

        printf(" ALUMNOS ORDENADOS POR NOMBRE POR EL M%cTODO DE INSERCI%cN \n\n" , 144 , 224);
        mostrarArrayAlumns(arrayAlumnos , valArrayAlums);

        system("pause");

        break;

    case 7:
        system("cls");

        printf("\t\t ------ EJERCICIO 8 ------ \n\n");

        printf(" Ingresar g%cnero del alumno: " , 130);
        fflush(stdin);
        scanf("%c" , &generoAlum);

        if(generoAlum == 'm'){
            cantAlums = contarAlumsPorGenero(arrayAlumnos , valArrayAlums , generoAlum);
            printf("\n La cantidad de alumnos del g%cnero masculino es de: %d \n\n" , 130 , cantAlums);
        }else{
            cantAlums = contarAlumsPorGenero(arrayAlumnos , valArrayAlums , generoAlum);
            printf("\n La cantidad de alumnos del g%cnero femenino es de: %d \n\n" , 130 , cantAlums);
        }

        system("pause");

        break;

    default:
        printf("\n Opci%cn NO v%clida. \n\n" , 162 , 160);
    }

}
