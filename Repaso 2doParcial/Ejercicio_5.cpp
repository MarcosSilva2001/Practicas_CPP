/*Se tiene un vector de Resumen de las carpas alquiladas en Mar del Plata para verano 2023, que contiene
el código del balneario, cantidad de días de la temporada reservados y cantidad de confirmaciones:
- Código del balneario
- Cantidad de días reservados
- Cantidad de confirmaciones/reservas
Además, se cuenta con una lista ordenada que contiene los últimos pedidos realizados, cada nodo de la
lista contiene:
- Código del balneario
- Cantidad de días reservados
Se pide, actualizar el vector Carpas con la información que hay en la lista. Importante: Si en la lista hay
una reserva para el balneario "123", hay que actualizar el campo cantidad de días reservados e
incrementar en 1 la reserva.
Se sabe que cómo Máximo hay 23 balnearios.
*/
#include <iostream>
using namespace std;

struct CarpaAlquilada
{
    int codigo;
    int cant_dias_reservar;
    int cant_confirmadas;
};

struct PedidosCarpa
{
    int codigo;
    int cant_dias_reservar;
};

struct Nodo
{
    CarpaAlquilada info;
    Nodo *sgte;
};

void liberar(Nodo *&lista);
int buscar(CarpaAlquilada vec[], int len, int valor);

int mainn(int argc, char **argv)
{
    CarpaAlquilada vector[23];
    int len;

    Nodo *lista;
    Nodo *aux = lista;
    int pos;

    while (aux != NULL)
    {
        pos = buscar(vector, len, aux->info.codigo);

        if (pos != -1)
        {
            vector[pos].cant_dias_reservar = vector[pos].cant_dias_reservar + aux->info.cant_dias_reservar;
            vector[pos].cant_confirmadas++;
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

int buscar(CarpaAlquilada vec[], int len, int valor)
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
