#include <iostream>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *sgte;
};

// prototipos de funciones y procedimientos

void mostrar(Nodo *lista);
void liberar(Nodo *&lista);
void insertarOrdenado(Nodo *&lista, int valor);

int main()
{
    Nodo *lista = NULL;
    int num;

    cout << "\tCargar la Lista" << endl;
    cout << "\nIngrese un valor o termine con 0: ";
    cin >> num;

    while (num != 0)
    {
        insertarOrdenado(lista, num);
        cout << "\nIngrese un valor o termine con 0: ";
        cin >> num;
    }

    mostrar(lista);

    liberar(lista); // luego de usar la lista lo liberamos

    return 0;
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

void insertarOrdenado(Nodo *&lista, int valor)
{
    // pedir memoria para crear el nodo
    Nodo *nuevo_nodo = new Nodo();

    // cargar el nodo
    nuevo_nodo->dato = valor;
    nuevo_nodo->sgte = NULL; // porque no se donde va

    // enlazarlo
    Nodo *aux = lista;     // nos ayuda para recorrer si modificar la lista
    Nodo *anterior = NULL; // este me va a permitir comparar para despues saber donde enlazar el nodo nuevo

    // Burcar en la lista donde voy a enlazar el nuevo nodo de manera ordenada
    while (aux != NULL && aux->dato < valor)
    {
        anterior = aux;
        aux = aux->sgte; // avanza en la lista
    }

    if (anterior == NULL) // No entro al while : 1) la lista estaba vacia 2) debo insertar al principio
    {
        lista = nuevo_nodo;
    }
    else // Entro al while y sale : 1) encontro el lugar donde insertar 2) llego al final y debo insertar en el final
    {
        anterior->sgte = nuevo_nodo;
    }

    nuevo_nodo->sgte = aux;
}
