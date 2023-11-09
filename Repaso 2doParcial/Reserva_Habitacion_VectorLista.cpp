/*Ejercicio 2: (4 puntos)
Se tiene un vector de Reservas de hotel para el verano 2021, que contiene todas las habitaciones de un hotel con los siguientes campos:
-Número de Habitación,
-Cantidad de Camas y
-Cantidad de días disponibles en la temporada.
Además, se cuenta con una lista ordenada que contiene las últimas reservas realizadas, cada nodo de la lista contiene:
-Número de habitación y
-la cantidad de dias.
se pide, actualizar el vector Reservas con la información que hay en la lista.
Ej: Si en la lista la habitación 23 tiene 2 días reservados, esos 2 días se deben restar en el campo de Cantidad de días del Vector.
Se sabe que cómo Máximo hay 700 habitaciones.*/
#include <iostream>
using namespace std;

// registros
struct Hotel
{
    int num_habitacion;
    int cant_camas;
    int cant_dias_disponibles;
};
struct Reservas
{
    int num_habitacion;
    int cant_dias;
};
struct Nodo
{
    Reservas info;
    Nodo *sgte;
};

// encabezados de los procedimientos y funciones
int buscar(Hotel vec[], int len, int valor);
void liberar(Nodo *&lista);

int main(int argc, char const *argv[])
{
    Hotel resHabitacion[700];
    int len;

    Nodo *listaReservas;
    int pos;
    Nodo *aux = listaReservas;

    while (aux != NULL)
    {
        pos = (resHabitacion, len, aux->info.num_habitacion);

        if (pos = !-1 && resHabitacion[pos].cant_dias_disponibles >= aux->info.cant_dias)
        {
            resHabitacion[pos].cant_dias_disponibles = resHabitacion[pos].cant_dias_disponibles - aux->info.cant_dias;
        }

        aux = aux->sgte;
    }

    liberar(listaReservas);

    return 0;
}
