/* Ejercicio 3) Se tiene un vector y su len, con las notas de los estudiantes. Se pide que muestre:
a. La menor nota
b. La mejor nota
c. El promedio
d. La cantidad de notas cargadas */

#include <iostream>

using namespace std;

void cargaNotas(int vec[], int &len1, int tam);
int notaMenor(int vec[], int len1);
int notaMejor(int vec[], int len1);
int notaPromedio(int vec[], int len1);

int main()
{
    int n;
    cout << "Digite la cantidad de notas que desea ingresar: ";
    cin >> n;
    int notas[n] = {0};
    int len = 0;

    cargaNotas(notas, len, n);

    cout << "\n_______________IMPRIMIR RESULTADOS_______________" << endl;

    int Menor = notaMenor(notas, len);
    cout << "\nLa menor nota es: " << notas[Menor] << endl;

    int Mejor = notaMejor(notas, len);
    cout << "\nLa mejor nota es: " << notas[Mejor] << endl;

    int promNotas = notaPromedio(notas, len);
    cout << "\nEl promedio de las notas ingresadas es: " << promNotas << endl;

    return 0;
}

void cargaNotas(int vec[], int &len1, int tam)
{
    cout << "\n----------A continuación debe cargar las notas de los estudiantes----------" << endl;
    for (int i = 0; i < tam; i++)
    {
        cout << "\nIngrese la nota [" << i + 1 << "]: ";
        cin >> vec[i];
        len1++;
    }
}

int notaMenor(int vec[], int len1)
{
    int men = 99999999; // un valor lo suficientemente grande para que cualquier valor ingresado sea menor a men
    int pos = 0;
    for (int i = 0; i < len1; i++)
    {
        if (vec[i] < men)
        {
            men = vec[i];
            pos = i;
        }
    }
    return pos;
}

int notaMejor(int vec[], int len1)
{
    int may = -99999999; // esto para que cualquier valor ingresado sea mayor que may
    int pos = 0;
    for (int i = 0; i < len1; i++)
    {
        if (vec[i] > may)
        {
            may = vec[i];
            pos = i;
        }
    }
    return pos;
}

int notaPromedio(int vec[], int len1)
{
    int promedio = 0;
    for (int i = 0; i < len1; i++)
    {
        promedio = promedio + vec[i];
    }
    promedio = promedio / len1;
    return promedio;
}

