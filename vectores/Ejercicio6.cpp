/* 6) Dado un lote valores provistos por el usuario, que finalizan con 0, definir y cargar un
vector de 15 posiciones (de manera ordenada) y calcular:
a. La sumatoria de todos los valores luego de ingresarlos al vector
b. El valor máximo
c. El valor mínimo
d. Generar un segundo vector que contenga sólo la mitad de cada valor cargado
en el vector original
e. Genere un tercer vector con el doble de cada valor cargado en el vector
original */
#include <iostream>
using namespace std;

void cargarOrdenado(int vec[], int &len, int valor);
void mostrar(int vec[], int len);
int sumatoria(int vec[], int len);
int valorMax(int vec[], int len);
int valorMin(int vec[], int len);
void generarMitad(int vec[], int len, int mitadVec[]);
void generarDoble(int vec[], int len, int dobleVec[]);

int main()
{
    int vector[15] = {0}; // Definir un vector de 15 posiciones
    int len = 0, num = 0;
    int vectorMitad[15];
    int vectorDoble[15];

    cout << "--------A CONTINUACION DEBERA INGRESAR VALORES PARA CARGAR EL VECTOR-------" << endl;
    cout << endl;

    cargarOrdenado(vector, len, num); // Llamamos la funcion para carga el vector ordenadamente
    cout << "\nEl vector ordenado es: " << endl;
    mostrar(vector, len); // Mostramos el vector ordenado

    cout << "\n_____________________________________________________________________" << endl; // linea para separar resultados

    int sumar = sumatoria(vector, len);
    cout << "La sumatoria de los valores ingresados es: " << sumar << endl;

    int posMax = valorMax(vector, len);
    cout << "\nEl maximo valor ingresado es : " << vector[posMax] << endl;

    int posMin = valorMin(vector, len);
    cout << "\nEl minimo valor ingresado es : " << vector[posMin] << endl;

    // llamamos la funcion para mostrar el vector mitad
    generarMitad(vector, len, vectorMitad);
    // mostramos el vector mitad
    cout << "\nEl vector midad del original es: " << endl;
    mostrar(vectorMitad, len);

    // llamamos la funcion para mostrar el vector doble
    generarDoble(vector, len, vectorDoble);
    // mostramos el vector mitad
    cout << "\nEl vector doble del original es: " << endl;
    mostrar(vectorDoble, len);

    return 0;
}

void cargarOrdenado(int vec[], int &len, int valor)
{
    int i = 0;
    cout << "Ingrese un valor para el vector (0 para finalizar): " << endl;
    cin >> valor;

    while (i < 15 && valor != 0)
    {
        int j = len - 1; // inicializar la variable j con el ultimo indice valido del vector vec o sea j=14
        while (j >= 0 && vec[j] > valor)
        {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = valor;
        len++;
        i++;

        cout << "Ingrese un valor para el vector (0 para finalizar): " << endl;
        cin >> valor;
    }
}

void mostrar(int vec[], int len)
{

    for (int i = 0; i < len; i++)
    {
        cout << "  " << vec[i];
    }
}
// a. La sumatoria de todos los valores luego de ingresarlos al vector
int sumatoria(int vec[], int len)
{
    int suma = 0;

    for (int i = 0; i < len; i++)
    {
        suma = suma + vec[i];
    }
    return suma;
}
// b. El valor máximo
int valorMax(int vec[], int len)
{
    int pos = 0;
    int max;
    max = vec[pos];

    for (int i = 1; i < len; i++)
    {
        if (vec[i] > max)
        {
            max = vec[i];
            pos = i;
        }
    }

    return pos;
}
// c. El valor mínimo
int valorMin(int vec[], int len)
{
    int pos = 0;
    int min;
    min = vec[pos];

    for (int i = 1; i < len; i++)
    {
        if (vec[i] < min)
        {
            min = vec[i];
            pos = i;
        }
    }

    return pos;
}
// d. Generar un segundo vector que contenga sólo la mitad de cada valor cargado
void generarMitad(int vec[], int len, int mitadVec[])
{
    for (int i = 0; i < len; i++)
    {
        mitadVec[i] = vec[i] / 2;
    }
}
// e. Genere un tercer vector con el doble de cada valor cargado en el vector original
void generarDoble(int vec[], int len, int dobleVec[])
{
    for (int i = 0; i < len; i++)
    {
        dobleVec[i] = vec[i] * 2;
    }
}
