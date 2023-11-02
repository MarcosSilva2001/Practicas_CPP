/*Desarrolle una función que retorne una lista ordenada a partir la INTERSECCION de una Lista y
una Pila.*/
#include <iostream>
using namespace std;

struct Nodo
{
   int info;
   Nodo *sgte;
};

Nodo *Union_Pila_Lista(Nodo *pila, Nodo *lista1);
void mostrar(Nodo *lista);
void liberar(Nodo *&lista);
Nodo *buscar(Nodo *lista, int valor);
void insertarOrdenado(Nodo *&Lista, int valor);
void push(Nodo *&pila, int valor);
int pop(Nodo *&pila);

int main(int argc, char const *argv[])
{
   Nodo *lista1 = NULL;
   insertarOrdenado(lista1, 2);
   insertarOrdenado(lista1, 6);
   insertarOrdenado(lista1, 5);
   insertarOrdenado(lista1, 8);

   Nodo *pila=NULL;
   push(pila, 1);
   push(pila, 2);
   push(pila, 3);
   push(pila, 4);
   push(pila, 5);
   push(pila, 6);

   cout << "--------------LISTA ORDENADA INTERSECCION PILA Y LISTA ---------------" << endl;
   Nodo *listaOrdenada = NULL;

   listaOrdenada = Union_Pila_Lista(pila, lista1);
   mostrar(listaOrdenada);
   liberar(listaOrdenada);

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

void push(Nodo *&pila, int valor)
{
   Nodo *nuevo_nodo = new Nodo();
   nuevo_nodo->info = valor;
   nuevo_nodo->sgte = NULL;
   pila = nuevo_nodo;
}

int pop(Nodo *&pila)
{
   int ret;
   ret = pila->info;

   Nodo *aux = pila;
   pila = aux->sgte;

   delete aux;
   return ret;
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

Nodo *Union_Pila_Lista(Nodo *pila, Nodo *lista1)
{
   Nodo *lista2 = NULL;

   Nodo *aux = lista1;
   Nodo *auxBuscador;
   int buscado;

   while (aux != NULL)
   {
      buscado = pop(pila);

      auxBuscador = buscar(lista2, buscado);

      if (auxBuscador != NULL)
      {
         insertarOrdenado(lista2, buscado);
      }

      aux = aux->sgte;
   }

   return lista2;
}