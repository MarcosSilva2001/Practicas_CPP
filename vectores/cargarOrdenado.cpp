#include <iostream>

using namespace std;

void cargarOrdenado(int vec[], int &len, int tam);
void mostrar(int vec[], int len);

int main()
{

    int tam;
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> tam;

    int array[tam] = {0}; // Inicializa todas las posiciones en cero
    int len = 0;

    cout << "\nEl arreglo inicializado en cero es: " << endl;
    mostrar(array, tam);

    cargarOrdenado(array, len, tam);

    cout << "\nEl arreglo ordenado es: " << endl;
    mostrar(array, len);

    return 0;
}

void cargarOrdenado(int vec[], int &len, int tam)
{
    int valor;
    cout << "\n\nA continuacion cargue el arreglo\n"
         << endl;

    for (int i = 0; i < tam; i++)
    {
        cout << "Ingrese un valor: ";
        cin >> valor;

        int j = len - 1;

        while (j >= 0 && vec[j] > valor)
        {
            vec[j + 1] = vec[j];
            j--;
        }

        vec[j + 1] = valor;
        len++;
    }
}

void mostrar(int vec[], int len)
{

    for (int i = 0; i < len; i++)
    {
        cout << "  " << vec[i];
    }
}