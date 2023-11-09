/*
Ejercicio 3: (4 puntos)
Se tiene un archivo de disponibilidad para las habitaciones de un hotel en la costa Verano2021.dat (sin
Orden):
- Número de Habitación: 999999
- Tipo: 's', 'd', 't' o 'c' (Single, Doble, Triple o Cuádruple)
-Dias disponibles de la temporada: 999
-Precio por dia de la habitación: 999 (entero)
Se pide:
a) Ordenar el archivo Verano2021.DAT por número de habitación
b) Armar una lista, ordenada por Número de habitación, y mostrarla por pantalla si el número de días disponibles es mayor a 90 y son 'c''t.
Nota: Sólo puede leer 1 vez el archivo.
*/
#include <iostream>
#include <stdio.h>

using namespace std;

struct HotelCosta
{
    int num_habitacion;
    char tipo; //'s', 'd', 't' o 'c' (Single, Doble, Triple o Cuádruple)
    int dias_disponibles;
    int precio;
};
struct Nodo
{
    HotelCosta info;
    Nodo *sgte;
};

void insertarOrdenado(Nodo *&lista, HotelCosta valor);
void liberar(Nodo *&lista);

int main(int argc, char const *argv[])
{
    FILE *Summer;
    Summer = fopen("Verano2021.dat", "rb");

    Nodo *listaOrd = NULL; // lista que nos ayudara a ordenar el archivo

    HotelCosta raux; // registro auxiliar para recorrer el archivo

    fread(&raux, sizeof(HotelCosta), 1, Summer);

    while (!feof(Summer))
    {
        // a) Ordenar el archivo Verano2021.DAT por número de habitación
        insertarOrdenado(listaOrd, raux);
        fread(&raux, sizeof(Summer), 1, Summer);
    }
    fclose(Summer);

    Nodo *aux = listaOrd;

    // b) Armar una lista, ordenada por Número de habitación, y mostrarla por pantalla si el número de días disponibles es mayor a 90 y son 'c''t'.
    while (aux != NULL)
    {
        if (aux->info.dias_disponibles > 90 && (aux->info.tipo == 'c' || aux->info.tipo == 't'))
        {
            cout << "\t\tDatos de la Reserva" << endl;

            cout << "Numero Habitacion: " << aux->info.num_habitacion << endl;
            cout << "Tipo: " << aux->info.tipo << endl;
            cout << "Dias disponibles: " << aux->info.dias_disponibles << endl;
            cout << "Precio: " << aux->info.precio << endl;
        }
        aux = aux->sgte;
    }

    aux = listaOrd;
    // abrimos el archivo para escritura
    Summer = fopen("Verano2021.dat", "wr");

    while (aux != NULL)
    {
        fwrite(&aux->info, sizeof(HotelCosta), 1, Summer);
        aux = aux->sgte;
    }
    fclose(Summer);
    liberar(listaOrd);

    return 0;
}
