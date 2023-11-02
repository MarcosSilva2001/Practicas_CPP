// Desarrolle los siguientes PROCEDIMIENTOS:

#include <iostream>
using namespace std;

struct Nodo
{
    int info;
    Nodo *sgte;
};

// a- Dados 2 vectores de enteros (A[10], B[10]) genere la INTERSECCION de ambos en C[10]
void interseccionVectores(int A[], int B[], int C[], int lenA, int lenB, int &lenC)
{
    int buscador;
    for (int i = 0; i < lenA; i++)
    {
        buscador = A[i];

        for (int j = 0; j < lenB; j++)
        {
            if (buscador == B[j])
            {
                C[lenC] = buscador;
                lenC++;
            }
        }
    }
}

// b- Dadas 1 Cola de enteros (Cola A) y 1 Pila de enteros (Pila A) genere la UNION de ambos en ListaA.
int suprimir(Nodo *&cfte, Nodo *&cfin);
int pop(Nodo *&pila);
void insertar(Nodo *&lista, int valor);

void unionColaPila(Nodo *cfte, Nodo *cfin, Nodo *pila, Nodo *&listaA)
{

    int carga;
    while (cfte != NULL)
    {
        carga = suprimir(cfte, cfin);
        insertar(listaA, carga);
    }
    while (pila != NULL)
    {
        carga = pop(pila);
        insertar(listaA, carga);
    }
}

// c- Dadas 2 Listas de enteros (Lista A y Lista B) genere la UNION de ambas en Lista C

void unionListas(Nodo *listaA, Nodo *listaB, Nodo *&listaC)
{
    listaC = listaA;
    Nodo *aux = listaB;

    while (aux != NULL)
    {
        insertar(listaC, aux->info);
        aux = aux->sgte;
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}
