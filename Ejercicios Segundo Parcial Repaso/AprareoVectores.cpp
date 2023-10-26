/*
Ejercicio 1:
Desarrolle los siguientes PROCEDIMIENTOS:
a- Dados 2 vectores de enteros (A[10], B[10]) genere la UNION de ambos en C[20]
*/

#include <iostream>
using namespace std;

void Union_Vectores(int vecA[], int lenA, int vecB[], int lenB, int vecC[], int &lenC);

void mostrar(int vec[], int len);

int main(int argc, char const *argv[])
{
    int vecA[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int lenA = 10;
    int vecB[10] = {11, 13, 14, 16, 17, 18, 20, 21};
    int lenB = 8;
    int vecC[20];
    int lenC = 0;

    // llamamos al procedimiento
    Union_Vectores(vecA, lenA, vecB, lenB, vecC, lenC);
    mostrar(vecC, lenC);

    return 0;
}

void Union_Vectores(int vecA[], int lenA, int vecB[], int lenB, int vecC[], int &lenC)
{
    for (int i = 0; i < lenA; i++)
    {
        vecC[lenC] = vecA[i];
        lenC++;
    }
    for (int i = 0; i < lenB; i++)
    {
        vecC[lenC] = vecB[i];
        lenC++;
    }
}

void mostrar(int vec[], int len)
{
    cout << "\nImprimir el vector..." << endl;
    for (int i = 0; i < len; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}