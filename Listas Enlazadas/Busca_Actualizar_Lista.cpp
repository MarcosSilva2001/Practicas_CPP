#include <iostream>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *sgte;
};

// prototipos de funciones y procedimientos
void agregarPrimero(Nodo *&lista, int valor);
void liberar(Nodo *&lista);
int buscar(Nodo *lista, int valor);

int main()
{
    Nodo *lista = NULL;
    int Buscado;
    int num;

    // cargar la lsita
    cout << "------------------------------------------------" << endl;
    cout << "\tCargar la Lista" << endl;
    cout << "\nIngrese un valor o termine con 0: ";
    cin >> num;

    while (num != 0)
    {
        agregarPrimero(lista, num);
        cout << "\nIngrese un valor o termine con 0: ";
        cin >> num;
    }

    // busco y muestro el valor buscado
    int buscado;
    int verificacion;
    char agregarlista;
    cout << "------------------------------------------------" << endl;
    cout << "\tBuscar en la Lista" << endl;
    cout << "\nIngrese el valor que desee buscar en la lista: ";
    cin >> buscado;

    verificacion = buscar(lista, buscado);

    if (verificacion == 0)
    {
        cout << "\nEl valor " << buscado << " fue encontrado en la lista..." << endl;
    }
    else if (verificacion == -1)
    {
        cout << "\nEl valor " << buscado << " no se encuentra en la lista..." << endl
             << endl;
        cout << "\n --> Desea agregar el valor a la lista? [s/n] :  ";
        cin >> agregarlista;

        if (agregarlista == 's')
        {
            agregarPrimero(lista, buscado);
        }
        else if (agregarlista == 'n')
        {
            exit;
        }
    }

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

int buscar(Nodo *lista, int valor)
{
    Nodo *aux = lista;

    while (aux != NULL && aux->dato != valor)
    {
        aux = aux->sgte;
    }
    if (aux == NULL)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}
