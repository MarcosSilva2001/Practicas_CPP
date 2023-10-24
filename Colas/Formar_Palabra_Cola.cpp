/*
Este programa permite al usuario interactuar a trav�s de un men� de opciones. 
Las principales funciones incluyen la capacidad de agregar letras a una cola, 
la cual se utiliza para formar una palabra en el orden en que se ingresan las letras. 
El usuario puede visualizar la palabra formada en cualquier momento. Adem�s,
 el men� permite salir del programa cuando el usuario lo desee.
*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Nodo
{
    char dato;
    Nodo *sgte;
};

void agregar(Nodo *&colafte, Nodo *&colafin, char letra);
char suprimir(Nodo *&colafte, Nodo *&colafin);

int main()
{
    Nodo *colafte = NULL;
    Nodo *colafin = NULL;

    char letra;
    char rdo;
    int opcion;

    cout << "\t\t:MENU:\n" << endl;

    do
    {
        // Opciones del men�
        cout << "[1] Insertar una letra" << endl;
        cout << "[2] Mostrar la palabra formada" << endl;
        cout << "[3] Salir" << endl;

        cout << "\nSeleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "\nEscriba la letra que desea insertar: ";
            cin >> letra;
            agregar(colafte, colafin, letra);

            cout << "\nLa letra ha sido agregada a la cola correctamente." << endl;
            break;

        case 2:
            if (colafte == NULL)
            {
                cout << "\nNo se ingreso ninguna letra..." << endl;
            }
            else
            {
                cout << "\nLa palabra formada es: ";
                while (colafte != NULL)
                {
                    rdo = suprimir(colafte, colafin);
                    cout << rdo;
                }
                cout << endl;
            }
            cout << endl;
            system("pause");
            break;

        case 3:
            break;

        default:
            cout << "\n\tOPCION INVALIDA" << endl;
            cout << endl;
            system("pause");
        }
        system("cls");

    } while (opcion != 3);

    return 0;
}

void agregar(Nodo *&colafte, Nodo *&colafin, char letra)
{
    // Pedimos memoria para el nuevo nodo
    Nodo *nuevo_nodo = new Nodo();

    // Cargamos el nodo con los datos
    nuevo_nodo->dato = letra;
    nuevo_nodo->sgte = NULL; // Inicializamos sgte a NULL

    // Verificamos si estamos en una cola vac�a o no
    if (colafte == NULL)
    {
        colafte = nuevo_nodo; // Si la cola est� vac�a, el nuevo nodo es el frente y el final.
        
    }
    else
    {
        colafin->sgte = nuevo_nodo; // Si no est� vac�a, enlazamos el �ltimo nodo al nuevo nodo.
        
    }
    
    colafin = nuevo_nodo;       // El nuevo nodo se convierte en el nuevo final de la cola.
}

char suprimir(Nodo *&colafte, Nodo *&colafin)
{
    char ret;
    if (colafte == NULL)
    {
        cout << "La cola esta vacia, no se puede eliminar." << endl;
        ret = '/'; // Devuelve '/' para indicar que la cola esta vacia.
    }
    else
    {
        ret = colafte->dato;
        Nodo *aux = colafte;
        colafte = colafte->sgte; // Si la cola tiene elementos, eliminamos el que est� en frente y ahora frente apunta al siguiente

        // Si colafte es NULL despues de eliminar el ultimo elemento, actualiza colafin a NULL tambien.
        if (colafte == NULL)
        {
            colafin = NULL;
        }

        delete aux;
    }

    return ret;
}

