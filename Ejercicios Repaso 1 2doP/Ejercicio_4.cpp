/*
Se tiene un vector de Resumen de las reservas de Pre-viaje para el verano 2023 en la costa Argentina,
que contiene el código de la ciudad costera, cantidad de reservas hechas en todos los alojamientos y
visitantes:
- Código de la ciudad
- Cantidad de reservas
- Cantidad de visitantes por reserva.
Además, se cuenta con una lista ordenada que contiene las últimas cargas realizadas, cada nodo de la
lista contiene (puede haber varios nodos por cada ciudad, ya que 1 nodo implica 1 reserva):
- Código de la ciudad
- Cantidad de visitantes.
Se pide, actualizar el vector Pre-Viaje con la información que hay en la lista. Importante: Si en la lista hay
una reserva para la ciudad "123", hay que actualizar el campo cantidad de visitantes e incrementar en 1
la reserva.
Se sabe que cómo Máximo hay 20 ciudades
*/

#include <iostream>
using namespace std;

struct viajesVerano
{
    int codigo;
    int cantReserva;
    int cantVisitantes;
};

struct reserva
{
    int codigo;
    int cantVisitantes;
};

struct Nodo
{
    viajesVerano info;
    Nodo *sgte;
};

void liberar(Nodo *&lista);
int buscar(viajesVerano vec[], int len, int valor);

int mainn(int argc, char **argv)
{
    viajesVerano vector[20];
    int len;
    Nodo *lista;
    int pos;

    Nodo *aux = lista;

    while (aux != NULL)
    {
        pos = buscar(vector, len, aux->info.codigo);

        if (pos != -1)
        {
            vector[pos].cantVisitantes = vector[pos].cantVisitantes + aux->info.cantVisitantes;
            vector[pos].cantReserva++;
        }
        aux = aux->sgte;
    }

    liberar(lista);

    return 0;
}

int buscar(viajesVerano vec[], int len, int valor)
{
    int i = 0;

    while (i < len && vec[i].codigo != valor)
    {
        i++;
    }

    if (i == len)
    {
        return -1;
    }
    else
        return i;
}
