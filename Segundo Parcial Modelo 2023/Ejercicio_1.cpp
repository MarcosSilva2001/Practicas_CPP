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

void suprimir(Nodo *&cfte, Nodo *&cfin);
void insertarOrdenado(Nodo *&lista, int valor);

// a- Un procedimiento que genere una lista ordenada a partir de la Unión de dos colas.
void UnionCola_Listaordenada(Nodo *&lista, Nodo *cfteA, Nodo *cfinA, Nodo *cfteB, Nodo *cfinB)
{
    int carga;
    while (cfteA != NULL)
    {
        carga = suprimir(cfteA, cfinA);
        insertarOrdenado(lista, carga);
    }
    while (cfteA != NULL)
    {
        carga = suprimir(cfteA, cfinA);
        insertarOrdenado(lista, carga);
    }
}