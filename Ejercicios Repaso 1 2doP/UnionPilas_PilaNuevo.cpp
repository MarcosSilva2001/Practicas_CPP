/*b- Dadas 2 Pilas de enteros (Pila A y Pila B) genere la UNION de ambas en Pila C.*/
#include <iostream>
using namespace std;

struct Nodo
{
    int info;
    Nodo *sgte;
};

void push(Nodo *&pila, int valor);
int pop(Nodo *&pila);
void Union(Nodo *&Pila1, Nodo *&Pila2, Nodo *&Pila3);

int main(int argc, char const *argv[])
{
    Nodo *pila1;
    Nodo *pila2;
    Nodo *pila3 = NULL;

    Union(pila1, pila2, pila3);

    return 0;
}

void Union(Nodo *&Pila1, Nodo *&Pila2, Nodo *&Pila3)
{

    int valor;

    while (Pila1 != NULL)
    {
        valor = pop(Pila1);
        push(Pila3, valor);
    }

    while (Pila2 != NULL)
    {
        valor = pop(Pila2);
        push(Pila3, valor);
    }
}
