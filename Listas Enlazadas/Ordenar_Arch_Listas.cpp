// Ordenamiento de un Archivo usando una lista

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
   // crear el puntero al archivo y abrir el archivo para lectura
   FILE *Alum;
   Alum = fopen("K115.dat", "rb");

   // crear el puntero a la lista que usaremos para ordenar el archivo
   Nodo *lista = NULL;
   Alumno raux; // registro auxiliar para recorrer el archivo y guarda cada registro del archivo en el

   fread(&raux, sizeof(Alumno), 1, Alum);
   // ordenamos los datos del archivo en la lista
   while (!feof(Alum))
   {
      insertarOrdenado(lista, raux);
      fread(&raux, sizeof(Alumno), 1, Alum);
   }
   fclose(Alum);

   // abrir el archivo para escritura
   Alum = fopen("K115.dat", "wb");

   // creamos un puntero a nodo  auxiliar y le asignamos la lista asi usamos el auxiliar para no perder la referencia de la lista
   Nodo *aux = lista;

   while (aux != NULL)
   {
      fwrite(&aux->info, sizeof(aux->info), 1, Alum);
      aux = aux->sgte;
   }
   fclose(Alum);
   // opcional mostrar la lista ordenada
   mostrar(lista);
   // liberamos la memoria que ocuoa la lista
   liberar(lista);

   return 0;
}

void insertarOrdenado(Nodo *&Lista, Alumno valor)
{
   // crear el nodo
   Nodo *nuevo = new Nodo();
   // cargar el nodo
   nuevo->info = valor.nota;
   nuevo->sgte = NULL; // porque no se donde va
   // Enlazarlo
   Nodo *aux = Lista; // recorro sin modificar la lista!!!
   Nodo *ant = NULL;  // este me va a permitir enlazar
   // BUSCAR!!!!!!!!!!!!!!!!!!!
   while (aux != NULL && aux->info < valor.nota)
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
      cout << "  " << aux->info;
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