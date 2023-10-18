#include <iostream>
using namespace std;

struct Nodo
{
    int info;
    Nodo *next;
};

int pop(Nodo *&pila);
int suprimir(Nodo *&cfte, Nodo *&cfin);
void mostrar(Nodo *lista);
void insertar_ordenado(Nodo *&lista, int valor);
void liberar(Nodo *&lista);

int main(int argc, char **argv)
{
    Nodo *pila;
    Nodo *cfte;
    Nodo *cfin;
    Nodo *lista = NULL;

    int carga;

    // para la pila
    while (pila != NULL)
    {
        carga = pop(pila);
        insertar_ordenado(lista, carga);
    }
    // para la cola
    while (cfte != NULL)
    {
        carga = suprimir(cfte, cfin);
        insertar_ordenado(lista, carga);
    }

    // Mostramos la nueva lista cargada con la union de la pila y la cola de manera ordeanda
    mostrar(lista);
    liberar(lista);

    return 0;
}

int pop(Nodo *&pila)
{
    int ret = pila->info;

    Nodo *aux = pila;
    pila = pila->next;
    delete aux;

    return ret;
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
    { // Entr� al while, 1) en alguna parte de la lista 2)agregar al final
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