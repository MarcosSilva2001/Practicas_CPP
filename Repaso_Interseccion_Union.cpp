struct Nodo
{
    int info;
    Nodo *sgte;
};

int suprimir(Nodo *&cfte, Nodo *&cfin);
void insertarOrdenado(Nood *&lista, int valor);

Nodo *interseccion_Pila_Lista(Nodo *pila, Nodo *lista1)
{
    Nodo *lista2 = NULL;
    Nodo *Buscado = NULL;

    int valor;

    while (pila != NULL)
    {
        valor = pop(pila);
        Buscado = buscar(lista1, valor);

        if (Buscado != NULL)
        {
            insertarOrdenado(lista2, valor);
        }
        aux = aux->sgte;
    }

    return lista2;
}

// procedimiento union pila y cola en una lista ordenada
void Union_Pila_Cola(Nodo *pila, Nodo *cfte, Nodo *cfin, Nodo *&lista)
{
    int valor;
    while (pila != NULL)
    {
        valor = pop(pila);
        insertarOrdenado(lista, valor);
    }
    while (cfte != NULL)
    {
        valor = suprimir(cfte, cfin);
        insertarOrdenado(lista, valor);
    }
}