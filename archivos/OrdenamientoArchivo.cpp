/*ARCHIVOS: Ordenamiento con vector*/

#include <iostream>
#include <stdio.h>

using namespace std;

struct Alumno
{
    int legajo;
    int dni;
    int nota1;
    int nota2;
};
void inicializar(Alumno vec[], int tam, Alumno valorIni);
void insertar(Alumno vec[], int &len, Alumno valor, int pos);
void insertarOrdenado(Alumno vec[], int &len, Alumno valor);

int main()
{

    // 1) Definir un puntero al archivo y definimos un vector de registros
    Alumno vec[5]; // necesitamos conocer cuantos registros tiene el archivo
    int len = 0;
    FILE *Alum;

    // 2) inicializamos el vector de registros y luego abrimos el archivo para lectura
    Alumno valorInicial;
    valorInicial.legajo = 0;
    valorInicial.dni = 0;
    valorInicial.nota1 = 0;
    valorInicial.nota2 = 0;

    inicializar(vec, 5, valorInicial);

    Alum = fopen("K1115.dat", "rb");

    // 3) Lectura del archivo y cargar del vector
    Alumno raux;
    fread(&raux, sizeof(Alumno), 1, Alum);

    while (!feof(Alum)) // mientrar no sea el final del archivo
    {
        // llamamos a la funcion insertarOrdeanado , sacamos los valores de raux y se lo asignamos a vec para ordenarlos
        insertarOrdenado(vec, len, raux);

        // leemos
        fread(&raux, sizeof(Alumno), 1, Alum);
    }

    fclose(Alum); // cierro el archivo porque termino la lectura

    // vuelvo a abrir pero en modo escritura para poder reescribir mi archivo con los datos ordenados que tengo en el vector de registro
    Alum = fopen("K1115.dat", "wb");

    // sobrescribo mi archivo
    for (int i = 0; i < len; i++)
    {
        fwrite(&vec[i], sizeof(Alumno), 1, Alum);
    }
    // 5) cierro el archivo despues de la escritura
    fclose(Alum);

    return 0;
}

void inicializar(Alumno vec[], int tam, Alumno valorIni)
{
    for (int i = 0; i < tam; i++)
    {
        vec[i].legajo = valorIni.legajo;
        vec[i].dni = valorIni.dni;
        vec[i].nota1 = valorIni.nota1;
        vec[i].nota2 = valorIni.nota2;
    }
}

void insertar(Alumno vec[], int &len, Alumno valor, int pos)
{
    for (int i = len; i > pos; i--)
    {
        vec[i].legajo = vec[i - 1].legajo;
        vec[i].dni = vec[i - 1].dni;
        vec[i].nota1 = vec[i - 1].nota1;
        vec[i].nota2 = vec[i - 1].nota2;
    }

    vec[pos].legajo = valor.legajo;
    vec[pos].dni = valor.dni;
    vec[pos].nota1 = valor.nota1;
    vec[pos].nota2 = valor.nota2;

    len++;
}

void insertarOrdenado(Alumno vec[], int &len, Alumno valor)
{
    int i = 0;

    while (i < len && vec[i].legajo <= valor.legajo) // en este caso quiero ordenar por el numero de legajo
    {
        i++;
    }

    if (i == len)
    {
        vec[len].legajo = valor.legajo;
        vec[len].dni = valor.dni;
        vec[len].nota1 = valor.nota1;
        vec[len].nota2 = valor.nota2;

        len++;
    }
    else
        insertar(vec, len, valor, i);
}