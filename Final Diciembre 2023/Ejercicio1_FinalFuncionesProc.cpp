
// Subprogramas

struct Nodo
{
    int info;
    Nodo *sgte;
};

void suprimir(Nodo *&cfte, Nod0 *&cfin);
void pop(Nodo *&pila);
void insertarOrdenada(Nodo *&lista, int valor);
void insertar(Nodo *&lista, int valor);

// Una funcion que retorne  una lista ordenada a partir de LA UNION DE una pila y  una cola

Nodo *ListaOrdenada(Nodo *Pila, Nodo *cfte, Nodo *cfin)
{

    Nodo *lista = NULL;
    int carga;

    While(cfte != NULL)
    {
        carga = suprimir(cfte, cfin);
        insertarOrdenado(lista, carga);
    }

    While(pila != NULL)
    {
        carga = pop(pila);
        insertarOrdenado(lista, carga);
    }

    return lista;
}

// un procedimiento que genere una lista sin orden a partir de la interseccion de la 2 listas

void InterseccionLista(Nodo *ListaA, Nodo *ListaB, Nodo *&Lista_Nueva)
{
    Nodo *aux = ListaA;
    Nodo *Encontrado;

    while (aux != NULL)
    {
        Encontrado = buscar(ListaB, aux->info);

        if (Encontrado != NULL)
        {
            insertar(Lista_Nueva, aux->info);
        }
        aux = aux->sgte;
    }
}

// Union de listas en una lista nueva
Nodo *UnionListas(Nodo *lista1, Nodo *lista2)
{
    Nodo *lista_nueva = NULL;

    lista_nueva = lista1;

    Nodo *aux = lista2;
    while (aux != NULL)
    {
        insertar(lista_nueva, aux->info);
        aux = aux->sgte;
    }

    return lista_nueva;
}