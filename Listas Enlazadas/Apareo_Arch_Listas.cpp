// Apareo de 2 Archivos y generar un nuevo arhivo usando una lista y registros auxiliares

#include <iostream>
#include <stdio.h>
using namespace std;

struct Alumno
{
    int legajo;
    int nota;
};

struct Nodo
{
    Alumno info;
    Nodo *sgte;
};

void insertarOrdenado(Nodo *&Lista, Alumno valor);
void mostrar(Nodo *Lista);
void liberar(Nodo *&Lista);

int main(int argc, char const *argv[])
{
    // Listas
    Nodo *lista = NULL; // Lista que contendrá los datos ordenados por nota de los 2 archivos

    // Crear los punteros a los archivos y abrir para lectura
    FILE *Alum1;
    FILE *Alum2;
    FILE *AlumOriginal;

    Alum1 = fopen("Alumnos1.dat", "rb");
    Alum2 = fopen("Alumnos2.dat", "rb");

    // crear registros auxiliares para recorrer los archivos
    Alumno raux1;
    Alumno raux2;
    // Leemos los archivos registro a registro
    fread(&raux1, sizeof(Alumno), 1, Alum1);
    fread(&raux2, sizeof(Alumno), 1, Alum2);

    // Cargamos la lista ordenada con los datos de los archivos
    while (!feof(Alum1))
    {
        insertarOrdenado(lista, raux1);
        fread(&raux1, sizeof(Alumno), 1, Alum1);
    }
    while (!feof(Alum2))
    {
        insertarOrdenado(lista, raux2);
        fread(&raux2, sizeof(Alumno), 1, Alum2);
    }
    // cerramos los archivos
    fclose(Alum1);
    fclose(Alum2);

    // abrimos el archivo que contendra los datos de los otros 2
    AlumOriginal = fopen("AlumnosOriginal.dat", "wb");
    // crear nodo auxiliar y le asignamos lo que apunta lista para no perder la referencia de esta
    Nodo *aux = lista;

    while (aux != NULL)
    {
        fwrite(&aux->info, sizeof(Alumno), 1, AlumOriginal);
        aux = aux->sgte;
    }
    fclose(AlumOriginal);
    // opcional mostrar la lista ordenada de los datos del nuevo archivo
    mostrar(lista);
    // liberar memoria
    liberar(lista);

    return 0;
}

void insertarOrdenado(Nodo *&Lista, Alumno valor)
{
    // crear el nodo
    Nodo *nuevo = new Nodo();
    // cargar el nodo
    nuevo->info.nota = valor.nota;
    nuevo->sgte = NULL; // porque no se donde va
    // Enlazarlo
    Nodo *aux = Lista; // recorro sin modificar la lista!!!
    Nodo *ant = NULL;  // este me va a permitir enlazar
    // BUSCAR!!!!!!!!!!!!!!!!!!!
    while (aux != NULL && aux->info.nota < valor.nota)
    {
        ant = aux;
        aux = aux->sgte; // avanzabamos en la lista
    }
    if (ant == NULL)
    { // No entro al while 1)lista vacia 2)debo insertar al principio
        Lista = nuevo;
    }
    else
    { // Entro al while, 1) en alguna parte de la lista 2)agregar al final
        ant->sgte = nuevo;
    }
    nuevo->sgte = aux;
}

void mostrar(Nodo *Lista)
{
    Nodo *aux = Lista;
    while (aux != NULL)
    {
        cout << "Legajo: " << aux->info.legajo << endl;
        cout << "Nota: " << aux->info.nota << endl;
        aux = aux->sgte;
    }
}

void liberar(Nodo *&Lista)
{
    Nodo *aux;
    while (Lista != NULL)
    {
        aux = Lista;
        Lista = Lista->sgte;
        delete (aux);
    }
}
