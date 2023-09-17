#include <iostream>
#include <stdio.h>

using namespace std;

struct Nodo
{
    int info;
    Nodo *sgte;
};

// los punteros colafte y colafin se pasan por referencia ya que van a modificar su valor en el proceso
void agregar(Nodo *&colafte, Nodo *&colafin, int valor);
int suprimir(Nodo *&colafte, Nodo *&colafin); // el tipo de dato del retorno es el de info

int main()
{
    // definir la cola
    Nodo *colafte = NULL;
    Nodo *colafin = NULL;

    int valor;
    int rdo;

    cout << "           CARGAR LA COLA" << endl;
    cout << "\nIngrese un valor ,finalizar con 0: ";
    cin >> valor;

    while (valor != 0)
    {
        agregar(colafte, colafin, valor);
        cout << "\nIngrese un valor ,finalizar con 0: ";
        cin >> valor;
    }

    cout << "\n           SACAR VALORES DE LA COLA" << endl
         << endl;
    while (colafte != NULL)
    {

        rdo = suprimir(colafte, colafin);
        cout << "El valor es: " << rdo << endl;
    }

    return 0;
}

void agregar(Nodo *&colafte, Nodo *&colafin, int valor)
{
    // crear Nodo ----> pedido de memoria
    Nodo *nuevo_nodo = new Nodo();

    // cargarlo con el valor
    nuevo_nodo->info = valor;
    nuevo_nodo->sgte = NULL;

    // Encolar (agregar los elementos por el final de la cola) se mueve colafin
    if (colafte == NULL)
    {
        colafte = nuevo_nodo;
    }
    else
    {
        colafin->sgte = nuevo_nodo;
    }
    colafin = nuevo_nodo;
}

int suprimir(Nodo *&colafte, Nodo *&colafin)
{
    // guardar el valor de retorno
    int retorno;
    retorno = colafte->info;

    // acomodar la cola
    Nodo *aux = colafte;
    colafte = colafte->sgte;
    if (colafte == NULL)
    {
        colafin = NULL;
    }

    // liberar el nodo delete
    delete aux;

    // retornar el valor
    return retorno;
}
