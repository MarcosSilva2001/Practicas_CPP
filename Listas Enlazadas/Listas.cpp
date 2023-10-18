/*Name: Listas Enlazadas*/

#include <iostream>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *sgte;
};

// prototipos de funciones y procedimientos
void agregarPrimero(Nodo *&lista, int valor);
int eliminarPrimero(Nodo *&lista);
void mostrar(Nodo *lista);
void liberar(Nodo *&lista);           // eliminar todos los nodos de la lista ,libera memoria sin mostrar los elementos
Nodo *buscar(Nodo *lista, int valor); // retorna el puntero al nodo donde se encuentra el valor que buscamos en caso contrario retorna NULL
void buscarMostrar(Nodo *lista, int valor);

int main()
{
    Nodo *lista = NULL;
    int rdo;
    int num;

    // cargar y mostrar la lsita
    cout << "\tCargar la Lista" << endl;
    cout << "\nIngrese un valor o termine con 0: ";
    cin >> num;

    while (num != 0)
    {
        agregarPrimero(lista, num);
        cout << "\nIngrese un valor o termine con 0: ";
        cin >> num;
    }

    mostrar(lista);

    liberar(lista); // luego de usar la lista lo liberamos

    return 0;
}

void agregarPrimero(Nodo *&lista, int valor)
{
    // pedido de memoria para crear el nodo
    Nodo *nuevo_nodo = new Nodo();

    // cargar el nodo
    nuevo_nodo->dato = valor;
    nuevo_nodo->sgte = lista; // sgte ahora tiene la direccion al cual apunta lista
    // enlazar
    lista = nuevo_nodo; // lista ahora apunta al nuevo nodo
}

int eliminarPrimero(Nodo *&lista)
{
    // guardar el valor del retorno
    int ret;
    ret = lista->dato;

    // eliminar nodo
    Nodo *aux = lista;
    lista = lista->sgte;
    delete aux;

    // reotrnar el valor
    return ret;
}

void mostrar(Nodo *lista)
{
    Nodo *aux = lista;
    while (aux != NULL)
    {
        cout << "El valor es: " << aux->dato << endl;
        aux = aux->sgte;
    }
}

void liberar(Nodo *&lista)
{
    Nodo *aux;
    while (lista != NULL)
    {
        aux = lista;
        lista = lista->sgte;
        delete (aux);
    }
}

Nodo *buscar(Nodo *lista, int valor)
{
    // recorremos la lista nodo a nodo hasta encontrar el valor
    Nodo *aux = lista;

    while (aux != NULL && aux->dato != valor)
    {
        aux = aux->sgte; // auxiliar va avanzando de nodo en nodo
    }

    return aux; // retorna el puntero al nodo que necesitamos o retorna null si no esta
}
void buscarMostrar(Nodo *lista, int valor)
{
    Nodo *aux;

    aux = buscar(lista, valor);

    if (aux == NULL)
    {
        cout << "No se encontro el valor buscado... " << endl;
    }
    else
    {
        cout << "El valor encontrado es " << aux->dato << endl;
    }
}