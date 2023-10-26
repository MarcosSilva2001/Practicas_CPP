/*Desarrolle una función que retorne una lista ordenada a partir la INTERSECCION de 2 Listas.*/
#include <iostream>
using namespace std;

struct Nodo
{
   int info;
   Nodo *sgte;
};

Nodo *Lista_Interseccion(Nodo *lista1, Nodo *lista2);
void mostrar(Nodo *lista);
void liberar(Nodo *&lista);
Nodo *buscar(Nodo *lista, int valor);
void insertarOrdenado(Nodo *&Lista, int valor);

int main(int argc, char const *argv[])
{
   Nodo *lista1 = NULL;
   insertarOrdenado(lista1, 3);
   insertarOrdenado(lista1, 5);
   insertarOrdenado(lista1, 1);
   insertarOrdenado(lista1, 8);
   insertarOrdenado(lista1, 9);

   Nodo *lista2 = NULL;
   insertarOrdenado(lista2, 2);
   insertarOrdenado(lista2, 4);
   insertarOrdenado(lista2, 1);
   insertarOrdenado(lista2, 7);
   insertarOrdenado(lista2, 5);
   insertarOrdenado(lista2, 9);

   Nodo *nueva_lista = NULL;

   cout << "--------------LISTA ORDENADA INTERSECCION---------------" << endl;

   nueva_lista = Lista_Interseccion(lista1, lista2);
   mostrar(nueva_lista);
   liberar(nueva_lista);

   return 0;
}

Nodo *buscar(Nodo *lista, int valor)
{
   // recorremos la lista nodo a nodo hasta encontrar el valor
   Nodo *aux = lista;

   while (aux != NULL && aux->info != valor)
   {
      aux = aux->sgte; // auxiliar va avanzando de nodo en nodo
   }

   return aux; // retorna el puntero al nodo que necesitamos o retorna null si no esta
}

void insertarOrdenado(Nodo *&Lista, int valor)
{
   // crear el nodo
   Nodo *nuevo = new Nodo();
   // cargar el nodo
   nuevo->info = valor;
   nuevo->sgte = NULL; // porque no s� d�nde va
   // Enlazarlo
   Nodo *aux = Lista; // recorro sin modificar la lista!!!
   Nodo *ant = NULL;  // este me va a permitir enlazar
   // BUSCAR!!!!!!!!!!!!!!!!!!!
   while (aux != NULL && aux->info < valor)
   {
      ant = aux;
      aux = aux->sgte; // avanzabamos en la lista
   }
   if (ant == NULL)
   { // No entr� al while 1)lista vac�a 2)debo insertar al principio
      Lista = nuevo;
   }
   else
   { // Entr� al while, 1) en alguna parte de la lista 2)agregar al final
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

Nodo *Lista_Interseccion(Nodo *lista1, Nodo *lista2)
{
   Nodo *lista3 = NULL;

   Nodo *aux = lista1;
   Nodo *Encontrado;
   int buscado;

   while (aux != NULL)
   {
      buscado = aux->info;

      Encontrado = buscar(lista2, buscado);

      if (Encontrado != NULL)
      {
         insertarOrdenado(lista3, buscado);
      }

      aux = aux->sgte;
   }

   return lista3;
}