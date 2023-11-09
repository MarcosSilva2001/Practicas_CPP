
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
}