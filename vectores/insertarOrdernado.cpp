#include <iostream>

using namespace std;

const int valorInicial = 0;

void inicializar(int vec[], int tam);
void insertar(int vec[], int &len, int valor, int pos); // insertar un valor en el vector
void insertarOrdenado(int vec[], int &len, int valor);  // insertar de manera ordenada un valor en el vector
void mostrar(int vec[], int len);

int main()
{
    int n;
    cout << "Digite la cantidad de posiciones para el vector: ";
    cin >> n;
    int numeros[n];
    int len = 0;
    int num;

    inicializar(numeros, n);

    cout << "Cargue el vector: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        // en cada iteracion pedimos un valor al usuario y cargamos el vector ordenado
        insertarOrdenado(numeros, len, num);
    }

    mostrar(numeros, len);

    return 0;
}

// procedimientos
void inicializar(int vec[], int tam)
{
    for (int i = 0; i < tam; i++)
    {
        vec[i] = valorInicial;
    }
}
void insertar(int vec[], int &len, int valor, int pos)
{
    /*El i que empieza desde len va decrementando hasta llegar a la posicion pos que se desea y se inserta, en cada iteracion se desplaza el valor anterior
    al valor actual y asi sucesivamente hasta pos*/

    for (int i = len; i > pos; i--)
    {
        vec[i] = vec[i - 1];
    }
    // sale del bucle y se inserta el valor a la pos
    vec[pos] = valor;
    len++;
}
void insertarOrdenado(int vec[], int &len, int valor)
{
    // busco la posicion donde voy a insertar el valor, para eso comparo el valor a insertar con los numeros de cada posicion
    int i = 0;
    while (i < len && vec[i] <= valor)
    {
        i++; // verifica en cada iteracion que el numero en la posicion i sea menor o igual al valor que quiere ingresar
    }
    // de no ser el caso entonces se sale del bucle por que lo recorrio completo e i==len o porque el valor ingresado es menor al de la posicion i

    // entonces verifica lo siguiente
    if (i == len)
    {
        vec[len] = valor;
        len++;
    }
    else
        insertar(vec, len, valor, i); // si no se sale por i==len entonces se inserta el valor en la posicion i que haya salido el bucle
}
void mostrar(int vec[], int len)
{
    cout << "\n-----------El vector cargado y ordenado es-----------" << endl;
    for (int i = 0; i < len; i++)
    {
        cout << "  " << vec[i];
    }
}