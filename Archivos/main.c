#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "pila.h"

typedef struct
{
    int legajo;
    char nombreYapellido[30];
    int edad;
    int year; //año que cursa

}stAlumno;

stAlumno cargarDatosAlumno(stAlumno alum); //FUNCIÓN AUX DEL EJERCICIO 1
void guardarAlumno(char nombreArchivo[] , stAlumno alum); //FUNCIÓN AUX DEL EJERCICIO 1
void cargarArchAlumnos(char nombreArchivo[]); //FUNCIÓN DEL EJERCICIO 1
void mostrarUnAlumno(stAlumno alum); //FUNCIÓN AUX DEL EJERCICIO 2
void mostrarArchAlumnos(char nombreArchivo[]); //FUNCIÓN DEL EJERCICIO 2
void agregarNuevoAlumnoFinal(char nombreArchivo[]); //FUNCIÓN DEL EJERCICIO 3
void pasarArchivoToPila(char nombreArchivo[] , Pila *p); //FUNCIÓN DEL EJERCICIO 4
int contarAlumsMayores(char nombreArchivo[] , int edad); //FUNCIÓN DEL EJERCICIO 5
void mostrarAlumsPorEdad(char nombreArchivo[] , int edadMin , int edadMax); //FUNCIÓN DEL EJERCICIO 6
stAlumno buscarMayorAlumno(char nombreArchivo[]); //FUNCIÓN DEL EJERCICIO 7
int contarAlumsIgualYear(char nombreArchivo[] , int year); //FUNCIÓN DEL EJERCICIO 8
int pasarArchivoToArray(char nombreArchivo[] , stAlumno arrAlums[] , int dimension); //FUNCIÓN DEL EJERCICIO 9
void mostrarArrayAlums(stAlumno arrAlums[] , int validos); //FUNCIÓN AUX DEL EJERCICIO 9
int cantRegistrosCargados(char nombreArchivo[] , int bytes); //FUNCIÓN DEL EJERCICIO 10

int main()
{
    char archAlumnos[] = {"alumnos.dat"};
    Pila legajosAlumnosMayores;
    int edadAlum = 0;
    int totalAlums = 0;
    int edadMin = 0;
    int edadMax = 0;
    stAlumno mayor;
    int yearAlumno = 0;
    int cantAlumsXyear = 0;
    int totalRegistrosCargados = 0;
    stAlumno arrayAlums[50];
    int valArrayAlums = 0;

    inicpila(&legajosAlumnosMayores);

//    cargarArchAlumnos(archAlumnos);

//    system("cls");

    printf("\t\t\t\t TP7 - ARCHIVOS \n\n");

    printf(" LISTA DE ALUMNOS: \n\n");
    mostrarArchAlumnos(archAlumnos);

    system("pause");
    system("cls");

//    printf(" CARGANDO NUEVO ALUMNO... \n\n");

//    agregarNuevoAlumnoFinal(archAlumnos);

//    printf("\n\n");
//    system("pause");
//    system("cls");

//    printf(" LISTA DE ALUMNOS ACTUALIZADA: \n\n");
//    mostrarArchAlumnos(archAlumnos);

//    pasarArchivoToPila(archAlumnos , &legajosAlumnosMayores);

//    printf(" LEGAJOS DE ALUMNOS MAYORES \n");
//    mostrar(&legajosAlumnosMayores);

//    printf(" Ingresar edad: ");
//    scanf("%d" , &edadAlum);

//    totalAlums = contarAlumsMayores(archAlumnos , edadAlum);

//    printf("\n La cantidad de alumnos mayores de %d a%cos es de: %d \n\n" , edadAlum , 164 , totalAlums);

//    printf(" Ingresar edad m%cnima: " , 161);
//    scanf("%d" , &edadMin);
//    printf(" Ingresar edad m%cxima: " , 160);
//    scanf("%d" , &edadMax);

//    system("cls");

//    printf(" ALUMNOS DE %d A %d A%cOS: \n\n" , edadMin , edadMax , 165);
//
//    mostrarAlumsPorEdad(archAlumnos , edadMin , edadMax);

//    mayor = buscarMayorAlumno(archAlumnos);

//    printf(" El alumno con mayor edad corresponde a: \n\n");
//    mostrarUnAlumno(mayor);

//    printf(" Ingresar a%co: " , 164);
//    scanf("%d" , &yearAlumno);

//    cantAlumsXyear = contarAlumsIgualYear(archAlumnos , yearAlumno);

//    printf("\n La cantidad de alumnos de %d%c a%co es: %d \n\n" , yearAlumno , 248 , 164 , cantAlumsXyear);

//    totalRegistrosCargados = cantRegistrosCargados(archAlumnos , sizeof(stAlumno));

    valArrayAlums = pasarArchivoToArray(archAlumnos , arrayAlums , 50);

    system("cls");

    printf(" ARREGO DE ALUMNOS CARGADO \n\n");
    mostrarArrayAlums(arrayAlums , valArrayAlums);

//    printf(" La cantidad de registros cargados en el archivo es de: %d \n\n" , totalRegistrosCargados);

    return 0;
}

// 1. Crear una función que cargue un archivo de alumnos. Abrirlo de manera tal de verificar si el archivo ya está creado previamente.
//    Cargar el archivo con 5 datos. Cerrarlo dentro de la función.

stAlumno cargarDatosAlumno(stAlumno alum)
{
    printf(" Ingresar legajo: ");
    scanf("%d" , &alum.legajo);

    printf(" Ingresar nombre y apellido: ");
    fflush(stdin);
    gets(alum.nombreYapellido);

    printf(" Ingresar edad: ");
    scanf("%d" , &alum.edad);

    printf(" Ingresar a%co: " , 164);
    scanf("%d" , &alum.year);

    return alum;
}

void guardarAlumno(char nombreArchivo[] , stAlumno alum)
{
    FILE *pArchivo = fopen(nombreArchivo , "ab");

    if(pArchivo != NULL){
        fwrite(&alum , sizeof(stAlumno) , 1 , pArchivo);
        fclose(pArchivo);
    }else{
        printf(" ERROR en la lectura del archivo. \n\n");
    }
}

void cargarArchAlumnos(char nombreArchivo[])
{
    char continuar = 's';
    stAlumno alum;

    while(continuar == 's' || continuar == 'S'){
        system("cls");

        printf(" CARGANDO ALUMNO... \n\n");

        alum = cargarDatosAlumno(alum);

        guardarAlumno(nombreArchivo , alum);

        printf("\n %cQuieres cargar otro alumno? s=SI / n=NO " , 168);
        fflush(stdin);
        continuar = getch();
    }
}

//2. Crear una función que muestre por pantalla los registros de un archivo de alumnos. Modularizar.
void mostrarUnAlumno(stAlumno alum)
{
    printf(" -------------------------- \n");
    printf(" Legajo: %d \n" , alum.legajo);
    printf(" Nombre y apellido: %s \n" , alum.nombreYapellido);
    printf(" Edad: %d \n" , alum.edad);
    printf(" A%co: %d \n" , 164 , alum.year);
    printf(" -------------------------- \n\n");
}

void mostrarArchAlumnos(char nombreArchivo[])
{
    stAlumno aux;
    int numAlumno = 0;
    FILE *pArchivo = fopen(nombreArchivo , "rb");

    if(pArchivo != NULL){
        while(fread(&aux , sizeof(stAlumno) , 1 , pArchivo) > 0){
            numAlumno++;
            printf(" Alumno N%c %d \n" , 248 , numAlumno);
            mostrarUnAlumno(aux);
        }
        fclose(pArchivo);

    }else{
        printf(" ERROR en la lectura del archivo. \n\n");
    }
}

// 3. Crear una función que permita agregar de a un elemento al final del archivo. O sea, se debe abrir el archivo, se piden los
//    datos (se llena una variable de tipo struct alumno), se escribe en el archivo y se cierra.
void agregarNuevoAlumnoFinal(char nombreArchivo[])
{
    stAlumno nuevo;
    FILE *pArchivo = fopen(nombreArchivo , "ab");

    if(pArchivo != NULL){
        nuevo = cargarDatosAlumno(nuevo);

        fwrite(&nuevo , sizeof(stAlumno) , 1 , pArchivo);

        fclose(pArchivo);
    }else{
        printf(" ERROR en la escritura del archivo. \n\n");
    }
}

//4. Crear una función que pase a una pila los números de legajo de los alumnos mayores de edad.
void pasarArchivoToPila(char nombreArchivo[] , Pila *p)
{
    stAlumno aux;
    FILE *pArchivo = fopen(nombreArchivo , "rb");

    if(pArchivo != NULL){
        while(fread(&aux , sizeof(stAlumno) , 1 , pArchivo) > 0){
            if(aux.edad > 21){
                apilar(p , aux.legajo);
            }
        }
        fclose(pArchivo);
    }else{
        printf(" ERROR en la lectura del archivo. \n\n");
    }
}

//5. Dado un archivo de alumnos, hacer una función que cuente la cantidad de alumnos mayores a edad específica que se envía
//   por parámetro.
int contarAlumsMayores(char nombreArchivo[] , int edad)
{
    stAlumno aux;
    int contAlums = 0;
    FILE *pArchivo = fopen(nombreArchivo , "rb");

    if(pArchivo != NULL){
        while(fread(&aux , sizeof(stAlumno) , 1 , pArchivo) > 0){
            if(aux.edad > edad){
                contAlums++;
            }
        }

        fclose(pArchivo);
    }else{
        printf(" ERROR en la lectura del archivo. \n\n");
    }

    return contAlums;
}

// 6. Dado un archivo de alumnos, mostrar por pantalla el nombre de todos los alumnos entre un rango de edades específico
//   (por ejemplo, entre 17 y 25 años). Dicho rango debe recibirse por parámetro. Modularizar

void mostrarAlumsPorEdad(char nombreArchivo[] , int edadMin , int edadMax)
{
    stAlumno aux;
    FILE *pArchivo = fopen(nombreArchivo , "rb");

    if(pArchivo != NULL){
        while(fread(&aux , sizeof(stAlumno) , 1 , pArchivo) > 0){
            if(aux.edad >= edadMin && aux.edad <= edadMax){
                mostrarUnAlumno(aux);
            }
        }
        fclose(pArchivo);

    }else{
       printf(" ERROR en la lectura del archivo. \n\n");
    }
}

// 7. Dado un archivo de alumnos, mostrar los datos del alumno de mayor edad. Modularizar.
stAlumno buscarMayorAlumno(char nombreArchivo[])
{
    stAlumno aux;
    stAlumno mayor;
    FILE *pArchivo = fopen(nombreArchivo , "rb");

    if(pArchivo != NULL){
        fread(&mayor , sizeof(stAlumno) , 1 , pArchivo);

        while(fread(&aux , sizeof(stAlumno) , 1 , pArchivo) > 0){
            if(aux.edad > mayor.edad){
                mayor = aux;
            }
        }

        fclose(pArchivo);

    }else{
        printf(" ERROR en la lectura del archivo. \n\n");
    }

    return mayor;
}

// 8. Crear una función que retorne la cantidad de alumnos que cursan un determinado año. El año buscado se pasa por parámetro.
int contarAlumsIgualYear(char nombreArchivo[] , int year)
{
    stAlumno aux;
    int contAlums = 0;
    FILE *pArchivo = fopen(nombreArchivo , "rb");

    if(pArchivo != NULL){
        while(fread(&aux , sizeof(stAlumno) , 1 , pArchivo) > 0){
            if(aux.year == year){
                contAlums ++;
            }
        }

        fclose(pArchivo);

    }else{
        printf(" ERROR en la lectura del archivo. \n\n");
    }

    return contAlums;
}

// 9. Crear una función que reciba como parámetro un arreglo de tipo alumno y lo copie en el archivo.
int pasarArchivoToArray(char nombreArchivo[] , stAlumno arrAlums[] , int dimension)
{
    stAlumno aux;
    int i = 0;
    FILE *pArchivo = fopen(nombreArchivo , "rb");

    if(pArchivo != NULL){
        while((fread(&aux , sizeof(stAlumno) , 1 , pArchivo) > 0) && (i < dimension)){
            arrAlums[i] = aux;
            i++;
        }

        fclose(pArchivo);
    }else{
        printf(" ERROR en la lectura del archivo. \n\n");
    }

    return i;
}

void mostrarArrayAlums(stAlumno arrAlums[] , int validos)
{
    int i;
    int numAlumno = 0;

    for(i=0 ; i<validos ; i++){
        numAlumno++;
        printf(" Alumno N%c %d \n" , 248 , numAlumno);
        mostrarUnAlumno(arrAlums[i]);
    }
}

// 10. Crear una función que retorne la cantidad de registros que tiene el archivo. Usar fseek y ftell. Puede pensar la función
//    para uso genérico, que sirva para averiguar la cantidad de registros de cualquier archivo.

int cantRegistrosCargados(char nombreArchivo[] , int bytes)
{
    int totalRegistros = 0;
    FILE *pArchivo = fopen(nombreArchivo , "rb");

    if(pArchivo != NULL){
        fseek(pArchivo , bytes - 1 , SEEK_END);
        totalRegistros = ftell(pArchivo) / bytes;

        fclose(pArchivo);
    }else{
        printf(" ERROR en la lectura del archivo. \n\n");
    }

    return totalRegistros;
}
