/*
Se tiene un vector de Reservas de habitaciones del hotel “Vacacionar” para el verano 2021, que
contiene todas las habitaciones de un hotel con los siguientes campos:
- Número de Habitación
- Cantidad de Camas
- Cantidad de días vendidos en la temporada.
Además, se cuenta con una lista ordenada que contiene las últimas reservas realizadas, cada nodo de la
lista contiene:
- Número de habitación
- Cantidad de días.
Se pide, actualizar el vector Reservas con la información que hay en la lista. Ej: Si en la lista la habitación
23 tiene 2 días reservados, esos 2 días se deben sumar en el campo de Cantidad de días vendidos del
Vector. Se sabe que cómo Máximo hay 200 habitaciones.
*/

#include <iostream>
using namespace std;

struct Hotel_Vacacionar
{
    int num_habitacion;
    int cant_camas;
    int cant_diasVendidas;
};
struct Reservas
{
    int num_habitacion;
    int cant_diasVendidas;
};

struct Nodo
{
    Reservas info;
    Nodo *sgte;
};

void liberar(Nodo *&lista);
int buscar(Hotel_Vacacionar vec[], int len, int valor);

int main()
{
    Hotel_Vacacionar vector[200];
    int len;

    Nodo *lista;
    int pos;

    Nodo *aux = lista;

    while (aux != NULL)
    {
        pos = buscar(vector, len, aux->info.num_habitacion);
        if (pos != -1)
        {
            vector[pos].cant_diasVendidas = vector[pos].cant_diasVendidas + aux->info.cant_diasVendidas;
        }
        aux = aux->sgte;
    }
    liberar(lista);

    return 0;
}

void liberar(Nodo *&lista)
{
    Nodo *aux;

    while (lista != NULL)
    {
        aux = lista;
        lista = lista->sgte;
        delete aux;
    }
}

int buscar(Hotel_Vacacionar vec[], int len, int valor)
{
    int i = 0;

    while (i < len && vec[i].num_habitacion != valor)
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
