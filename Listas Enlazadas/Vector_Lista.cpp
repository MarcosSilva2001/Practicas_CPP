#include <iostream>
using namespace std;

struct Product
{
    int ID;
    int stock;
};

struct Nodo
{
    Product info;
    Nodo *sgte;
};

void liberar(Nodo *&lista);
int buscar(Product vec[], int len, Product valor);

int mainn(int argc, char **argv)
{
    Product vector[20];
    int len;
    Nodo *lista;
    int pos;

    Nodo *aux = lista;

    while (aux != NULL)
    {
        pos = buscar(vector, len, aux->info);

        if (pos != -1)
        {
            vector[pos].stock = vector[pos].stock + aux->info.stock;
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

int buscar(Product vec[], int len, Product valor)
{
    int i = 0;

    while (i < len && vec[i].ID != valor.ID)
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
