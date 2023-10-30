/*
Se tiene un archivo de disponibilidad para las habitaciones de un hotel en la costa Verano2021.dat (sin
Orden):
- Número de Habitación: 999999
- Tipo: ‘s’, ‘d’, ‘t’ o ‘c’ (Single, Doble, Triple o Cuádruple)
- Días disponibles de la temporada: 999
- Precio por día de la habitación: 999 (entero)
Se pide:
a) Ordenar el archivo Verano2021.DAT por precio de habitación

b) Armar una lista, ordenada por Número de habitación, y mostrarla por pantalla si el número de
días disponibles es menor a 50 y son habitaciones singles o dobles.
Nota: Sólo puede leer 1 vez el archivo.
*/
#include <iostream>
#include <stdio.h>
using namespace std;

struct Hotel
{
    int num_habitacion;
    char tipo; // ‘s’, ‘d’, ‘t’ o ‘c’ (Single, Doble, Triple o Cuádruple)
    int dias_disponibles;
    int precio_dia;
};

struct Nodo
{
    Hotel dato;
    Nodo *sgte;
};

void insertarOrdenado(Nodo *&lista, Hotel valor);
void mostrar(Nodo *lista);
void liberar(Nodo *&lista);

int main(int argc, char const *argv[])
{
    FILE *hotel;
    hotel = fopen("Verano2021.dat", "rb");

    Nodo *listaOrdArch = NULL;
    Nodo *listaHabitacion = NULL;

    Hotel raux;

    fread(&raux, sizeof(raux), 1, hotel);

    while (!feof(hotel))
    {
        // ordenamos el archivo por precio de habitacion con la listaOrdArch
        insertarOrdenado(listaOrdArch, raux);

        // Armar una lista, ordenada por Número de habitación
        insertarOrdenado(listaHabitacion, raux);

        fread(&raux, sizeof(raux), 1, hotel);
    }
    fclose(hotel);

    Nodo *aux = listaHabitacion;
    while (aux != NULL)
    {
        // mostrar por pantalla si el número de días disponibles es menor a 50 y son habitaciones singles o dobles.
        if (raux.dias_disponibles < 50 && (raux.tipo == 's' || raux.dias_disponibles < 50 && raux.tipo == 'd'))
        {
            mostrar(listaHabitacion);
        }
    }
    liberar(listaHabitacion);

    // escribir el archivo ordenado por precio de habitaciones
    hotel = fopen("Verano2021.dat", "wb");
    aux = listaOrdArch;

    while (aux != NULL)
    {
        fwrite(&aux->dato, sizeof(aux->dato), 1, hotel);
        aux = aux->sgte;
    }
    fclose(hotel);
    liberar(listaOrdArch);

    return 0;
}
