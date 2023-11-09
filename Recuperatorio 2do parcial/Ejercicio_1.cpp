/*Desarrolle los siguientes Subprogramas:
a- Una función que retorne una lista ordenada a partir de la Unión de 2 colas.
b- Un procedimiento que genere una lista sin orden a partir de la INTERSECCION de 2 listas.
Defina usted las estructuras de los nodos de la manera que considere más conveniente y detallar. */

#include <iostream>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *sgte;
};

int suprimir(Nodo *&cfte, Nodo *&cfin);
void insertarOrdenado(Nood *&lista, int valor);
void insertar(Nodo *&lista, int valor);
Nodo *buscar(Nodo *lista, int valorBuscado);

// a- Una función que retorne una lista ordenada a partir de la Unión de 2 colas.
Nodo *lista_UnionColas(Nodo *cfte1, Nodo *cfin1, Nodo *cfte2, Nodo *cfin2)
{
    Nodo *lista = NULL;
    int carga;

    while (cfte1 != NULL)
    {
        carga = suprimir(cfte1, cfin1);
        insertarOrdenado(lista, carga);
    }
    while (cfte2 != NULL)
    {
        carga = suprimir(cfte2, cfin2);
        insertarOrdenado(lista, carga);
    }

    return lista;
}

// b- Un procedimiento que genere una lista sin orden a partir de la INTERSECCION de 2 listas.

void interseccion_Listas(Nodo *lista1, Nodo *lista2, Nodo *&lista3)
{
    Nodo *aux1 = lista1;

    Nodo *buscado;

    while (aux1 != NULL)
    {
        buscado = buscar(lista2, aux1->dato);

        if (buscado != NULL)
        {
            insertar(lista3, aux1->dato);
        }
        aux1 = aux1->sgte;
    };
}