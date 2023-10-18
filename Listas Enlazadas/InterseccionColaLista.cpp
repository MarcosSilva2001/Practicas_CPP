#include <iostream>
using namespace std;

struct Nodo
{
    int info;
    Nodo *next;
};

int suprimir(Nodo *&cfte, Nodo *&cfin);
void mostrar(Nodo *lista);
void insertar_ordenado(Nodo *&lista, int valor);
void liberar(Nodo *&lista);
Nodo *buscar(Nodo *lista, int valor);

int main(int argc, char **argv)
{
    Nodo *cfte;
    Nodo *cfin;
    Nodo *lista1;
    Nodo *lista2 = NULL;

    int carga;
    Nodo *aux;

    // buscamos el la cola
    while (cfte != NULL)
    {
        carga = suprimir(cfte, cfin);
        aux = buscar(lista1, carga);

        if (aux != NULL)
        {
            insertar_ordenado(lista2, carga);
        }
    }

    // Mostramos la nueva lista cargada con la interseccion de la cola y la lista de manera ordeanda
    mostrar(lista2);
    liberar(lista2);

    return 0;
}

int suprimir(Nodo *&cfte, Nodo *&cfin)
{
    int ret = cfte->info;

    Nodo *aux = cfte;
    cfte = cfte->next;
    if (cfte == NULL)
    {
        cfin = NULL;
    }
    delete aux;
    return ret;
}
void mostrar(Nodo *lista)
{
    Nodo *aux = lista;
    while (aux != NULL)
    {
        cout << "el valor es: " << aux->info << endl;
        aux = aux->next;
    }
}
void insertar_ordenado(Nodo *&lista, int valor)
{
    // crear el nodo
    Nodo *nuevo = new Nodo();
    // cargar el nodo
    nuevo->info = valor;
    nuevo->next = NULL; // porque no s� d�nde va
    // Enlazarlo
    Nodo *aux = lista; // recorro sin modificar la lista!!!
    Nodo *ant = NULL;  // este me va a permitir enlazar
    // BUSCAR!!!!!!!!!!!!!!!!!!!
    while (aux != NULL && aux->info < valor)
    {
        ant = aux;
        aux = aux->next; // avanzabamos en la lista
    }
    if (ant == NULL)
    { // No entr� al while 1)lista vac�a 2)debo insertar al principio
        lista = nuevo;
    }
    else
    { // Entra al while, 1) en alguna parte de la lista 2)agregar al final
        ant->next = nuevo;
    }
    nuevo->next = aux;
}
void liberar(Nodo *&lista)
{
    Nodo *aux;
    while (lista != NULL)
    {
        aux = lista;
        lista = lista->next;
        delete (aux);
    }
}

Nodo *buscar(Nodo *lista, int valor)
{
    // recorremos la lista nodo a nodo hasta encontrar el valor
    Nodo *aux = lista;

    while (aux != NULL && aux->info != valor)
    {
        aux = aux->next; // auxiliar va avanzando de nodo en nodo
    }

    return aux; // retorna el puntero al nodo que necesitamos o retorna null si no esta
}