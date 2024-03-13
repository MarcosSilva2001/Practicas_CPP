/*
2) Dado un vector (de registros) acerca las estadísticas de los jugadores que participaron en la
Copa América 2021 y marcaron goles; que contiene el código del jugador, Inicial de
Selección a la que pertenecen y la cantidad de goles convertidos. (Se sabe que hay
cómo máximo 276 jugadores), se pide determinar:
a- ¿Cuál es el Jugador que más goles convirtió? (Código del Jugador y cantidad de goles)
b- ¿Cuál es el Jugador que menos goles convirtió? (Código del Jugador y cantidad de goles)
c- Calcular el promedio de goles convertidos.
*/

#include <iostream>
using namespace std;

int jugador
{
    int cod_jugador;
    char Seleccion[30];
    int Cant_goles;
};

void MasGoles(jugador vec[], len);
void MenosGoles(jugador vec[], len);
void PromedioGoles(jugador vec[], len);

int main()
{

    jugador vec[276];
    int len;

    int MaxGoles = MasGoles(vec[], len);
    cout << "el maximo de goles es " << MaxGoles << endl;

    int MinGoles = MenosGoles(vec[], len);
    cout << "menos goles" << MinGoles << endl;

    int promedio = PromedioGoles(vec[], len);

    cout << "el promedio de goles son " << promedio << endl;

    return 0;
};

void MasGoles(jugador vec[], len)
{
    int pos = 0;
    for (int i = 1; i < len; i++)
    {
        if (vec[pos].cod_jugador < vec[i].Cant_Goles)

            pos = i;
    }
    retur pos;
};

void MenosGoles(jugador vec[], len)
{
    int pos = 0;
    for (int i = 1; i > len; i++)
    {
        if (vec[pos].cod_jugador < vec[i].Cant_Goles)

            pos = i;
    }
    retur pos;
}
void PromedioGoles(jugador vec[], len)
{
    int suma = 0;
    for (int i = 0; i < len; i++)
    {

        suma = suma + vec[i].Cant_goles;
    }

    cout << "el promedio de goles son" << suma / len << endl;
}