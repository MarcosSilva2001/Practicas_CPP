/*Ejercicio 1 (1 puntos)
Desarrolle los siguientes Subprograma
a- Un procedimiento que genere una lista ordenada a partir de la Unión de dos colas.
b- Una función que retorne una lista ordenada a partir de la Intersección de 2 listas.
Defina usted las estructuras que considere más conveniente y detallar.
*/
#include <iostream>
using namespace std;

struct Nodo
{
    int info;
    Nodo *sgte;
};

int suprimir(Nodo *&cfte, Nodo *&cfin);
void insertarOrdenado(Nodo *&lista, int valor);
Nodo *buscar(Nodo *lista, int valor);

// a- Un procedimiento que genere una lista ordenada a partir de la Unión de dos colas.
void UnionCola_Listaordenada(Nodo *&lista, Nodo *cfteA, Nodo *cfinA, Nodo *cfteB, Nodo *cfinB)
{
    int carga;
    while (cfteA != NULL)
    {
        carga = suprimir(cfteA, cfinA);
        insertarOrdenado(lista, carga);
    }
    while (cfteB != NULL)
    {
        carga = suprimir(cfteB, cfinB);
        insertarOrdenado(lista, carga);
    }
}

// b- Una función que retorne una lista ordenada a partir de la Intersección de 2 listas.
Nodo *InterseccionListas(Nodo *lista1, Nodo *lista2)
{
    Nodo *lista_nuevo = NULL;

    Nodo *aux = lista1;
    Nodo *Buscado;
    int num;

    while (aux != NULL)
    {
        num = aux->info;
        Buscado = buscar(lista2, num);

        if (Buscado != NULL)
        {
            insertarOrdenado(lista_nuevo, num);
        }

        aux = aux->sgte;
    }

    return lista_nuevo;
}