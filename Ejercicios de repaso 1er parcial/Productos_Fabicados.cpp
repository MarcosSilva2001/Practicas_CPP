/* 1) Dado un vector acerca de la producción de una fábrica, que contiene el código del producto
    fabricado y la cantidad de unidades disponibles para la venta (Se sabe que máximo hay 150
    productos en proceso de fabricación), determinar:

a- ¿Cuál es el producto que más unidades tiene fabricados?
b- ¿Cuál es el producto que menos unidades tiene?
c- Indicar la cantidad total de productos fabricados según el vector.
*/

#include <iostream>

using namespace std;

const int Max_Fabricados = 150;

struct Producto
{
    int codigo;
    int cantidad;
};

void inicializar(Producto vec[], int tam, Producto valorIni);
int Max_Unidades_Fabricados(Producto vec[], int len);
int Min_Unidades_Fabricados(Producto vec[], int len);
int Total(Producto vec[], int len);

int main()
{
    Producto productos[Max_Fabricados]; // definimos un vector de registros que en cada posicion tiene el codigo del producto y la cantidad disponible
    int len = 0;
    int numFabricados;

    cout << "Ingrese el numero de productos fabricados: " << endl;
    cin >> numFabricados;

    // inicializamos el vector de registros
    Producto valorInicial;
    valorInicial.codigo = 0;
    valorInicial.cantidad = 0;

    inicializar(productos, numFabricados, valorInicial);

    // cargamos los datos de cada producto fabricado
    for (int i = 0; i < numFabricados; i++)
    {
        cout << "Ingrese el cogido del producto [" << i << "] : " << endl;
        cin >> productos[i].codigo;
        cout << "Ingrese la cantidad de unidades disponibles para la venta : " << endl;
        cin >> productos[i].cantidad;
        cout << "----------------------------" << endl;

        len++;
    }

    // a) llamamos la funcion para calcular el producto con mas unidades fabricados
    int maxUnidades = Max_Unidades_Fabricados(productos, len);
    cout << "\nProducto con mas unidades fabricadas: Código " << productos[maxUnidades].codigo << endl;

    // b) llamamos la funcion para calcular el producto con menos unidades fabricados
    int minUnidades = Min_Unidades_Fabricados(productos, len);
    cout << "\nProducto con menos unidades fabricadas: Código " << productos[minUnidades].codigo << endl;

    // c)  total de las unidades de productos fabricados disponibles
    int total = Total(productos, len);
    cout << "\nCantidad total de productos fabricados: " << total << endl;

    return 0;
}

void inicializar(Producto vec[], int tam, Producto valorIni)
{
    for (int i = 0; i < tam; i++)
    {
        vec[i] = valorIni;
    }
}

// calculamos a- ¿Cuál es el producto que más unidades tiene fabricados?
int Max_Unidades_Fabricados(Producto vec[], int len)
{
    int maxPos = 0;

    for (int i = 1; i < len; i++)
    {
        if (vec[maxPos].cantidad < vec[i].cantidad)
        {
            maxPos = i;
        }
    }

    return maxPos;
}

// calculamos b- ¿Cuál es el producto que menos unidades tiene?
int Min_Unidades_Fabricados(Producto vec[], int len)
{
    int minPos = 0;

    for (int i = 1; i < len; i++)
    {
        if (vec[minPos].cantidad > vec[i].cantidad)
        {
            minPos = i;
        }
    }

    return minPos;
}

// calculamos c- Indicar la cantidad total de productos fabricados según el vector.
int Total(Producto vec[], int len)
{
    int suma = 0;
    // sumo en cada posicion  la cantidad de productos disponibles
    for (int i = 0; i < len; i++)
    {
        suma = suma + vec[i].cantidad;
    }

    return suma;
}
