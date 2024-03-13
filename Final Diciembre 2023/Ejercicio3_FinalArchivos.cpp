#include <iostream>
#include <stdio.h>

using namepsace std :

    struct Producto
{

    int Cod_Pro;
    int peso;
    char tipo; // "A" , "B"
    int cant_Bultos;
};

struct Nodo
{
    Prodcuto info;
    Nodo *sgte;
};

void insertarOrdenado(Nodo &*Lista, Producto valor);
void liberar(Nodo *&Lista);
void mostrar(Nodo *Lista);

int main()
{
    FILE *Bulto = fopen("STOCK.dat", "rb");
    Producto raux;
    Nodo *LISTAOrd = NULL;
    Nodo *LISTAB = NULL;
    Nodo *LISTAC = NULL;

    fread(&raux, sizeof(struct Producto), 1, Bulto);

    while (aux != NULL)
    {

        insertarOrdenado(LISTAOrd, raux); // ORDENAR POR COD PRODUCTO

        // Los productos que no tinen stock.
        if (raux.cant_Bultos == 0)
        {
            insertarOrdenado(LISTAB, raux);
        }
        // Los productos que pesan mas de 10okg y son tipo Bebidas
        if (raux.peso > 100 and raux.tipo == 'B')
        {
            insertarOrdenado(LISTAC, raux);
        }

        fread(&raux, sizeof(struct Producto), 1, Bulto);
    }
    fclose(Bulto);

    // WHILE PARA RECORRER Y MOSTRAR LAS LISTAS

    Nodo *aux = LISTAOrd;

    Bulto = fopen("STOCK.dat", "wb");

    while (aux != NULL)
    {
        fwrite(&aux->info, sizeof(struct Productos), 1, Bulto);
        aux = aux->sgte;
    }
    fclose(Bulto);

    mostrar(LISTAB);
    mostrar(LISTAC);

    liberar(LISTAB);
    liberar(LISTAC);
    liberar(LISTAOrd);

    return 0;
}
