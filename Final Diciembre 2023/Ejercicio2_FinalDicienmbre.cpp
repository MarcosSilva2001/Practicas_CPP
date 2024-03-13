#include <iostream>

using namespace std;

struct HotelPinamar
{
    int codigo_hotel;
    int cant_dias_reservadas;
    int cant_dias_disponibles;
};

struct Reservas
{
    int codigo_hotel;
    int cant_dias_reservadas;
};

struct Nodo
{
    Reservas dato;
    Nodo *sgte;
};

int buscar(HotelPinamar vec[], int len, int valor);
void liberar(Nodo *&lista);

int main(int argc, char const *argv[])
{

    HotelPinamar vec[50];
    int len;
    Nodo *Lista;
    Nodo *aux = Lista;

    int pos;
    while (aux != NULL)
    {
        pos = buscar(vec[], len, aux->dato.codigo_hotel);
        if (pos != -1)
        {
            vec[pos].cant_dias_reservadas = vec[pos].cant_dias_reservadas + aux->dato.cant_dias_reservadas;

            if (vec[pos].cant_dias_disponibles >= aux->dato.cant_dias_reservadas)
            {

                vec[pos].cant_dias_disponibles = vec[pos].cant_dias_disponibles - aux->dato.cant_dias_reservadas;
            }
            else
            {
                cout << "Lo siento, los dias de reservas superan los dias disponibles" << endl;
            }
        }
        aux = aux->sgte;
    }

    liberar(Lista);

    return 0;
}
