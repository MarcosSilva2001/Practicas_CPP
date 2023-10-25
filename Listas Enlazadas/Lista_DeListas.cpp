

#include <iostream>
using namespace std;
// Tinfo2 esta dentro de Nodo2
struct Tinfo2
{
    int ID;
    int nota;
};
// Nodo2 de Tinfo
struct Nodo2
{
    Tinfo2 info;
    Nodo2 *sgte;
};
// Tinfo esta dentro de Nodo
struct Tinfo
{
    int leg;
    Nodo2 *notas;
};
// Nodo padre
struct Nodo
{
    Tinfo info;
    Nodo *sgte;
};

int main(int argc, char const *argv[])
{
    // por ejemplo quiero calcular el promedio de notas de cada nodo que tiene la lista y a su ves cada nodo de la lista tiene otra lista

    Nodo *lista = NULL; // puntero lista padre que apunta al nodo padre padre
    int suma, cont = 0;
    Nodo *aux = lista;    // para recorrer la lista sim perder referecia
    Nodo2 *lista2 = NULL; // puntero de la lista 2 que esta dentro de cada nodo de la lista padre

    while (aux != NULL)
    {
        lista2 = aux->info.notas;

        while (lista2 != NULL)
        {
            suma = suma + lista2->info.nota;
            cont++;
            lista2 = lista2->sgte;
        }

        // mostramos por pantalla el promedio de notas del legajo tal
        cout << "El promedio de las notas de " << aux->info.leg << " es: " << suma / cont << endl;

        // recetemos el contador y la variable suma y avanzamos el puntero aux
        suma = 0;
        cont = 0;
        aux = aux->sgte;
    }

    return 0;
}
